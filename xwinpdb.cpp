/* Copyright (c) 2022 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "xwinpdb.h"

XWinPDB::XWinPDB(QIODevice *pDevice) : XBinary(pDevice)
{
#ifdef Q_OS_WIN
    g_pDiaDataSource=nullptr;
    g_pDiaSession=nullptr;
    g_pGlobal=nullptr;
#endif
}

XWinPDB::~XWinPDB()
{
#ifdef Q_OS_WIN
    if(g_pGlobal)
    {
        g_pGlobal->Release();
        g_pGlobal=nullptr;
    }

    if(g_pDiaSession)
    {
        g_pDiaSession->Release();
        g_pDiaSession=nullptr;
    }

    if(g_pDiaDataSource)
    {
        g_pDiaDataSource->Release();
        g_pDiaDataSource=nullptr;
    }
#endif
}

bool XWinPDB::loadMSDIALibrary(QString sFileName)
{
    bool bResult=false;
#ifdef Q_OS_WIN
    if(g_pDiaDataSource)
    {
        g_pDiaDataSource->Release();
        g_pDiaDataSource=nullptr;
    }

    wchar_t wszFilePath[512]={};

    if(sFileName.toWCharArray(wszFilePath))
    {
        HRESULT hr=NoRegCoCreate(wszFilePath, _uuidof(DiaSource),_uuidof(IDiaDataSource),(void **)(&g_pDiaDataSource));

        if(SUCCEEDED(hr))
        {
            bResult=true;
        }
    }
#endif
    return bResult;
}

bool XWinPDB::loadFile(QString sFileName)
{
    bool bResult=false;
#ifdef Q_OS_WIN
    if(g_pDiaDataSource)
    {
        wchar_t wszFilePath[512]={};

        if(sFileName.toWCharArray(wszFilePath))
        {
            HRESULT hr=g_pDiaDataSource->loadDataFromPdb(wszFilePath);

            if(SUCCEEDED(hr))
            {
                if(g_pGlobal)
                {
                    g_pGlobal->Release();
                    g_pGlobal=nullptr;
                }

                if(g_pDiaSession)
                {
                    g_pDiaSession->Release();
                    g_pDiaSession=nullptr;
                }

                hr=g_pDiaDataSource->openSession(&g_pDiaSession);

                if(SUCCEEDED(hr))
                {
                    hr=g_pDiaSession->get_globalScope(&g_pGlobal);

                    if(SUCCEEDED(hr))
                    {
                        bResult=true;
                    }
                }
            }
        }
    }
#endif
    return bResult;
}

QString XWinPDB::getName()
{
    QString sResult;
#ifdef Q_OS_WIN
    if(g_pGlobal)
    {
        sResult=_get_name(g_pGlobal);
    }
#endif
    return sResult;
}

QString XWinPDB::getArch()
{
#ifdef Q_OS_WIN
    return XPE::getImageFileHeaderMachinesS().value(_get_machineType(g_pGlobal));
#else
    return XBinary::getArch();
#endif
}

XWinPDB::PDB_INFO XWinPDB::getPdbInfo(PDSTRUCT *pPdStruct)
{
    PDB_INFO result={};
#ifdef Q_OS_WIN
    result.sName=_get_name(g_pGlobal);
    result.sGUID=_get_guid(g_pGlobal);
    result.sFileName=_get_symbolsFileName(g_pGlobal);
    result.sArch=getArch();
    result.nAge=_get_age(g_pGlobal);
    result.nSignature=_get_signature(g_pGlobal);
    result.bIsCTypes=_get_isCTypes(g_pGlobal);
    result.bIsStripped=_get_isStripped(g_pGlobal);

    IDiaEnumSymbols *pEnumSymbols=nullptr;

    qint32 nCurrent=0;

    if(g_pGlobal->findChildren(SymTagNull,nullptr,nsNone,&pEnumSymbols)==S_OK)
    {
        quint32 nCount=_get_Count(pEnumSymbols);

        setPdStructTotal(pPdStruct,nCount);

        if(nCount)
        {
            IDiaSymbol *pSymbol;
            ULONG celt=0;

            while(SUCCEEDED(pEnumSymbols->Next(1,&pSymbol,&celt))&&(celt==1)&&(!pPdStruct->bIsStop)) // TODO Stop
            {
                quint32 nSymTag=_get_symTag(pSymbol);

                qDebug("SymTag: %d %d %d",nCurrent,nCount,nSymTag);

                if(nSymTag==SymTagUDT)
                {

                }

                pSymbol->Release();

                nCurrent++;
                setPdStructCurrent(pPdStruct,nCurrent);
            }
        }
    }

    setPdStructFinished(pPdStruct);

    pEnumSymbols->Release();

//                    SYMBOL_RECORD record={};
//                    BSTR bstring=nullptr;
//                    DWORD dwSymTag=0;
//                    pSymbol->get_symTag(&dwSymTag);

//                    if(dwSymTag==SymTagUDT)
//                    {
//                        DWORD dwParentClass=0;

//                        pSymbol->get_classParentId(&dwParentClass);

//                        if(dwParentClass==0)
//                        {
//                            ULONGLONG nLen=0;
//                            pSymbol->get_length(&nLen);
//                            pSymbol->get_symIndexId(&record.dwID);

//                            record.sName=getName(pSymbol);

//                            if(mapUDT.value(record.sName,-1)!=nLen)
//                            {
//                                DWORD _dwKind=0;
//                                pSymbol->get_udtKind(&_dwKind);

//                                if(_dwKind==0)
//                                {
//                                    record.type=SYMBOL_TYPE_STRUCT;
//                                }
//                                else if(_dwKind==1)
//                                {
//                                    record.type=SYMBOL_TYPE_CLASS;
//                                }
//                                else if(_dwKind==2)
//                                {
//                                    record.type=SYMBOL_TYPE_UNION;
//                                }
//                                else if(_dwKind==3)
//                                {
//                                    record.type=SYMBOL_TYPE_INTERFACE;
//                                }

//                                pStats->listSymbols.append(record);
//                            }
//                        }
//                    }
//                    else if(dwSymTag==SymTagEnum)
//                    {
//                        DWORD dwParentClass=0;

//                        pSymbol->get_classParentId(&dwParentClass);

//                        if(dwParentClass==0)
//                        {
//                            record.sName=getName(pSymbol);

//                            pSymbol->get_symIndexId(&record.dwID);
//                            record.type=SYMBOL_TYPE_ENUM;

//                            pStats->listSymbols.append(record);
//                        }
//                    }

//                    pSymbol->Release();

//                    pStats->nCurrent++;
//                }
//            }
//        }

//        pEnumSymbols->Release();
//    }
#endif
    return result;
}

void XWinPDB::test()
{
#ifdef Q_OS_WIN

//    QString v_compilerName=_get_compilerName(g_pGlobal);
//    quint32 v_symIndexId=_get_symIndexId(g_pGlobal);
//    quint32 v_symTag=_get_symTag(g_pGlobal);

    PDSTRUCT pdStruct={};

    getPdbInfo(&pdStruct);
    QString v_name=_get_name(g_pGlobal);
    QString v_guid=_get_guid(g_pGlobal);
    QString v_symbolsFileName=_get_symbolsFileName(g_pGlobal);
    quint32 v_age=_get_age(g_pGlobal);
    quint32 v_signature=_get_signature(g_pGlobal);
    quint32 v_machineType=_get_machineType(g_pGlobal);
    bool v_isCTypes=_get_isCTypes(g_pGlobal);
    bool v_isStripped=_get_isStripped(g_pGlobal);

    _testSymbol(g_pGlobal);
#endif
}
#ifdef Q_OS_WIN
void XWinPDB::_testSymbol(IDiaSymbol *pSymbol)
{
    DWORD dwTest=0;
    ULONGLONG ullTest=0;
    LONG lTest=0;
    BSTR strTest;
    BOOL bTest=0;
    IDiaSymbol *pSymbolTest=0;
    VARIANT varTest;
    GUID guidTest;
    BYTE bData[256];
    DWORD dwData[256];
    WORD wData[256];
    IDiaInputAssemblyFile *iafTest;

    if(pSymbol->get_symIndexId(&dwTest)==S_OK) qDebug("get_symIndexId");
    if(pSymbol->get_symTag(&dwTest)==S_OK) qDebug("get_symTag");
    if(pSymbol->get_name(&strTest)==S_OK) qDebug("get_name");
    if(pSymbol->get_lexicalParent(&pSymbolTest)==S_OK) qDebug("get_lexicalParent");
    if(pSymbol->get_classParent(&pSymbolTest)==S_OK) qDebug("get_classParent");
    if(pSymbol->get_type(&pSymbolTest)==S_OK) qDebug("get_type");
    if(pSymbol->get_dataKind(&dwTest)==S_OK) qDebug("get_dataKind");
    if(pSymbol->get_locationType(&dwTest)==S_OK) qDebug("get_locationType");
    if(pSymbol->get_addressSection(&dwTest)==S_OK) qDebug("get_addressSection");
    if(pSymbol->get_addressOffset(&dwTest)==S_OK) qDebug("get_addressOffset");
    if(pSymbol->get_relativeVirtualAddress(&dwTest)==S_OK) qDebug("get_relativeVirtualAddress");
    if(pSymbol->get_virtualAddress(&ullTest)==S_OK) qDebug("get_virtualAddress");
    if(pSymbol->get_registerId(&dwTest)==S_OK) qDebug("get_registerId");
    if(pSymbol->get_offset(&lTest)==S_OK) qDebug("get_offset");
    if(pSymbol->get_length(&ullTest)==S_OK) qDebug("get_length");
    if(pSymbol->get_slot(&dwTest)==S_OK) qDebug("get_slot");
    if(pSymbol->get_volatileType(&bTest)==S_OK) qDebug("get_volatileType");
    if(pSymbol->get_constType(&bTest)==S_OK) qDebug("get_constType");
    if(pSymbol->get_unalignedType(&bTest)==S_OK) qDebug("get_unalignedType");
    if(pSymbol->get_access(&dwTest)==S_OK) qDebug("get_access");
    if(pSymbol->get_libraryName(&strTest)==S_OK) qDebug("get_libraryName");
    if(pSymbol->get_platform(&dwTest)==S_OK) qDebug("get_platform");
    if(pSymbol->get_language(&dwTest)==S_OK) qDebug("get_language");
    if(pSymbol->get_editAndContinueEnabled(&bTest)==S_OK) qDebug("get_editAndContinueEnabled");
    if(pSymbol->get_frontEndMajor(&dwTest)==S_OK) qDebug("get_frontEndMajor");
    if(pSymbol->get_frontEndMinor(&dwTest)==S_OK) qDebug("get_frontEndMinor");
    if(pSymbol->get_frontEndBuild(&dwTest)==S_OK) qDebug("get_frontEndBuild");
    if(pSymbol->get_backEndMajor(&dwTest)==S_OK) qDebug("get_backEndMajor");
    if(pSymbol->get_backEndMinor(&dwTest)==S_OK) qDebug("get_backEndMinor");
    if(pSymbol->get_backEndBuild(&dwTest)==S_OK) qDebug("get_backEndBuild");
    if(pSymbol->get_sourceFileName(&strTest)==S_OK) qDebug("get_sourceFileName");
    if(pSymbol->get_unused(&strTest)==S_OK) qDebug("get_unused");
    if(pSymbol->get_thunkOrdinal(&dwTest)==S_OK) qDebug("get_thunkOrdinal");
    if(pSymbol->get_thisAdjust(&lTest)==S_OK) qDebug("get_thisAdjust");
    if(pSymbol->get_virtualBaseOffset(&dwTest)==S_OK) qDebug("get_virtualBaseOffset");
    if(pSymbol->get_virtual(&bTest)==S_OK) qDebug("get_virtual");
    if(pSymbol->get_intro(&bTest)==S_OK) qDebug("get_intro");
    if(pSymbol->get_pure(&bTest)==S_OK) qDebug("get_pure");
    if(pSymbol->get_callingConvention(&dwTest)==S_OK) qDebug("get_callingConvention");
    if(pSymbol->get_value(&varTest)==S_OK) qDebug("get_value");
    if(pSymbol->get_baseType(&dwTest)==S_OK) qDebug("get_baseType");
    if(pSymbol->get_token(&dwTest)==S_OK) qDebug("get_token");
    if(pSymbol->get_timeStamp(&dwTest)==S_OK) qDebug("get_timeStamp");
    if(pSymbol->get_guid(&guidTest)==S_OK) qDebug("get_guid");
    if(pSymbol->get_symbolsFileName(&strTest)==S_OK) qDebug("get_symbolsFileName");
    if(pSymbol->get_reference(&bTest)==S_OK) qDebug("get_reference");
    if(pSymbol->get_count(&dwTest)==S_OK) qDebug("get_count");
    if(pSymbol->get_bitPosition(&dwTest)==S_OK) qDebug("get_bitPosition");
    if(pSymbol->get_arrayIndexType(&pSymbolTest)==S_OK) qDebug("get_arrayIndexType");
    if(pSymbol->get_packed(&bTest)==S_OK) qDebug("get_packed");
    if(pSymbol->get_constructor(&bTest)==S_OK) qDebug("get_constructor");
    if(pSymbol->get_overloadedOperator(&bTest)==S_OK) qDebug("get_overloadedOperator");
    if(pSymbol->get_nested(&bTest)==S_OK) qDebug("get_nested");
    if(pSymbol->get_hasNestedTypes(&bTest)==S_OK) qDebug("get_hasNestedTypes");
    if(pSymbol->get_hasAssignmentOperator(&bTest)==S_OK) qDebug("get_hasAssignmentOperator");
    if(pSymbol->get_hasCastOperator(&bTest)==S_OK) qDebug("get_hasCastOperator");
    if(pSymbol->get_scoped(&bTest)==S_OK) qDebug("get_scoped");
    if(pSymbol->get_virtualBaseClass(&bTest)==S_OK) qDebug("get_virtualBaseClass");
    if(pSymbol->get_indirectVirtualBaseClass(&bTest)==S_OK) qDebug("get_indirectVirtualBaseClass");
    if(pSymbol->get_virtualBasePointerOffset(&lTest)==S_OK) qDebug("get_virtualBasePointerOffset");
    if(pSymbol->get_virtualTableShape(&pSymbolTest)==S_OK) qDebug("get_virtualTableShape");
    if(pSymbol->get_lexicalParentId(&dwTest)==S_OK) qDebug("get_lexicalParentId");
    if(pSymbol->get_classParentId(&dwTest)==S_OK) qDebug("get_classParentId");
    if(pSymbol->get_typeId(&dwTest)==S_OK) qDebug("get_typeId");
    if(pSymbol->get_arrayIndexTypeId(&dwTest)==S_OK) qDebug("get_arrayIndexTypeId");
    if(pSymbol->get_virtualTableShapeId(&dwTest)==S_OK) qDebug("get_virtualTableShapeId");
    if(pSymbol->get_code(&bTest)==S_OK) qDebug("get_code");
    if(pSymbol->get_function(&bTest)==S_OK) qDebug("get_function");
    if(pSymbol->get_managed(&bTest)==S_OK) qDebug("get_managed");
    if(pSymbol->get_msil(&bTest)==S_OK) qDebug("get_msil");
    if(pSymbol->get_virtualBaseDispIndex(&dwTest)==S_OK) qDebug("get_virtualBaseDispIndex");
    if(pSymbol->get_undecoratedName(&strTest)==S_OK) qDebug("get_undecoratedName");
    if(pSymbol->get_age(&dwTest)==S_OK) qDebug("get_age");
    if(pSymbol->get_signature(&dwTest)==S_OK) qDebug("get_signature");
    if(pSymbol->get_compilerGenerated(&bTest)==S_OK) qDebug("get_compilerGenerated");
    if(pSymbol->get_addressTaken(&bTest)==S_OK) qDebug("get_addressTaken");
    if(pSymbol->get_rank(&dwTest)==S_OK) qDebug("get_rank");
    if(pSymbol->get_lowerBound(&pSymbolTest)==S_OK) qDebug("get_lowerBound");
    if(pSymbol->get_upperBound(&pSymbolTest)==S_OK) qDebug("get_upperBound");
    if(pSymbol->get_lowerBoundId(&dwTest)==S_OK) qDebug("get_lowerBoundId");
    if(pSymbol->get_upperBoundId(&dwTest)==S_OK) qDebug("get_upperBoundId");
    if(pSymbol->get_dataBytes(256,&dwTest,bData)==S_OK) qDebug("get_dataBytes");
//    if(pSymbol->findChildren(&bTest)==S_OK) qDebug("findChildren");
//    if(pSymbol->findChildrenEx(&bTest)==S_OK) qDebug("findChildrenEx");
//    if(pSymbol->findChildrenExByAddr(&bTest)==S_OK) qDebug("findChildrenExByAddr");
//    if(pSymbol->findChildrenExByVA(&bTest)==S_OK) qDebug("findChildrenExByVA");
//    if(pSymbol->findChildrenExByRVA(&bTest)==S_OK) qDebug("findChildrenExByRVA");
    if(pSymbol->get_targetSection(&dwTest)==S_OK) qDebug("get_targetSection");
    if(pSymbol->get_targetOffset(&dwTest)==S_OK) qDebug("get_targetOffset");
    if(pSymbol->get_targetRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_targetRelativeVirtualAddress");
    if(pSymbol->get_targetVirtualAddress(&ullTest)==S_OK) qDebug("get_targetVirtualAddress");
    if(pSymbol->get_machineType(&dwTest)==S_OK) qDebug("get_machineType");
    if(pSymbol->get_oemId(&dwTest)==S_OK) qDebug("get_oemId");
    if(pSymbol->get_oemSymbolId(&dwTest)==S_OK) qDebug("get_oemSymbolId");
    if(pSymbol->get_types(0,&dwTest,&pSymbolTest)==S_OK) qDebug("get_types");
    if(pSymbol->get_typeIds(0,&dwTest,dwData)==S_OK) qDebug("get_typeIds");
    if(pSymbol->get_objectPointerType(&pSymbolTest)==S_OK) qDebug("get_objectPointerType");
    if(pSymbol->get_udtKind(&dwTest)==S_OK) qDebug("get_udtKind");
    if(pSymbol->get_undecoratedNameEx(0,&strTest)==S_OK) qDebug("get_undecoratedNameEx");
    if(pSymbol->get_noReturn(&bTest)==S_OK) qDebug("get_noReturn");
    if(pSymbol->get_customCallingConvention(&bTest)==S_OK) qDebug("get_customCallingConvention");
    if(pSymbol->get_noInline(&bTest)==S_OK) qDebug("get_noInline");
    if(pSymbol->get_optimizedCodeDebugInfo(&bTest)==S_OK) qDebug("get_optimizedCodeDebugInfo");
    if(pSymbol->get_notReached(&bTest)==S_OK) qDebug("get_notReached");
    if(pSymbol->get_interruptReturn(&bTest)==S_OK) qDebug("get_interruptReturn");
    if(pSymbol->get_farReturn(&bTest)==S_OK) qDebug("get_farReturn");
    if(pSymbol->get_isStatic(&bTest)==S_OK) qDebug("get_isStatic");
    if(pSymbol->get_hasDebugInfo(&bTest)==S_OK) qDebug("get_hasDebugInfo");
    if(pSymbol->get_isLTCG(&bTest)==S_OK) qDebug("get_isLTCG");
    if(pSymbol->get_isDataAligned(&bTest)==S_OK) qDebug("get_isDataAligned");
    if(pSymbol->get_hasSecurityChecks(&bTest)==S_OK) qDebug("get_hasSecurityChecks");
    if(pSymbol->get_compilerName(&strTest)==S_OK) qDebug("get_compilerName");
    if(pSymbol->get_hasAlloca(&bTest)==S_OK) qDebug("get_hasAlloca");
    if(pSymbol->get_hasSetJump(&bTest)==S_OK) qDebug("get_hasSetJump");
    if(pSymbol->get_hasLongJump(&bTest)==S_OK) qDebug("get_hasLongJump");
    if(pSymbol->get_hasInlAsm(&bTest)==S_OK) qDebug("get_hasInlAsm");
    if(pSymbol->get_hasEH(&bTest)==S_OK) qDebug("get_hasEH");
    if(pSymbol->get_hasSEH(&bTest)==S_OK) qDebug("get_hasSEH");
    if(pSymbol->get_hasEHa(&bTest)==S_OK) qDebug("get_hasEHa");
    if(pSymbol->get_isNaked(&bTest)==S_OK) qDebug("get_isNaked");
    if(pSymbol->get_isAggregated(&bTest)==S_OK) qDebug("get_isAggregated");
    if(pSymbol->get_isSplitted(&bTest)==S_OK) qDebug("get_isSplitted");
    if(pSymbol->get_container(&pSymbolTest)==S_OK) qDebug("get_container");
    if(pSymbol->get_inlSpec(&bTest)==S_OK) qDebug("get_inlSpec");
    if(pSymbol->get_noStackOrdering(&bTest)==S_OK) qDebug("get_noStackOrdering");
    if(pSymbol->get_virtualBaseTableType(&pSymbolTest)==S_OK) qDebug("get_virtualBaseTableType");
    if(pSymbol->get_hasManagedCode(&bTest)==S_OK) qDebug("get_hasManagedCode");
    if(pSymbol->get_isHotpatchable(&bTest)==S_OK) qDebug("get_isHotpatchable");
    if(pSymbol->get_isCVTCIL(&bTest)==S_OK) qDebug("get_isCVTCIL");
    if(pSymbol->get_isMSILNetmodule(&bTest)==S_OK) qDebug("get_isMSILNetmodule");
    if(pSymbol->get_isCTypes(&bTest)==S_OK) qDebug("get_isCTypes");
    if(pSymbol->get_isStripped(&bTest)==S_OK) qDebug("get_isStripped");
    if(pSymbol->get_frontEndQFE(&dwTest)==S_OK) qDebug("get_frontEndQFE");
    if(pSymbol->get_backEndQFE(&dwTest)==S_OK) qDebug("get_backEndQFE");
    if(pSymbol->get_wasInlined(&bTest)==S_OK) qDebug("get_wasInlined");
    if(pSymbol->get_strictGSCheck(&bTest)==S_OK) qDebug("get_strictGSCheck");
    if(pSymbol->get_isCxxReturnUdt(&bTest)==S_OK) qDebug("get_isCxxReturnUdt");
    if(pSymbol->get_isConstructorVirtualBase(&bTest)==S_OK) qDebug("get_isConstructorVirtualBase");
    if(pSymbol->get_RValueReference(&bTest)==S_OK) qDebug("get_RValueReference");
    if(pSymbol->get_unmodifiedType(&pSymbolTest)==S_OK) qDebug("get_unmodifiedType");
    if(pSymbol->get_framePointerPresent(&bTest)==S_OK) qDebug("get_framePointerPresent");
    if(pSymbol->get_isSafeBuffers(&bTest)==S_OK) qDebug("get_isSafeBuffers");
    if(pSymbol->get_intrinsic(&bTest)==S_OK) qDebug("get_intrinsic");
    if(pSymbol->get_sealed(&bTest)==S_OK) qDebug("get_sealed");
    if(pSymbol->get_hfaFloat(&bTest)==S_OK) qDebug("get_hfaFloat");
    if(pSymbol->get_hfaDouble(&bTest)==S_OK) qDebug("get_hfaDouble");
    if(pSymbol->get_liveRangeStartAddressSection(&dwTest)==S_OK) qDebug("get_liveRangeStartAddressSection");
    if(pSymbol->get_liveRangeStartAddressOffset(&dwTest)==S_OK) qDebug("get_liveRangeStartAddressOffset");
    if(pSymbol->get_liveRangeStartRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_liveRangeStartRelativeVirtualAddress");
    if(pSymbol->get_countLiveRanges(&dwTest)==S_OK) qDebug("get_countLiveRanges");
    if(pSymbol->get_liveRangeLength(&ullTest)==S_OK) qDebug("get_liveRangeLength");
    if(pSymbol->get_offsetInUdt(&dwTest)==S_OK) qDebug("get_offsetInUdt");
    if(pSymbol->get_paramBasePointerRegisterId(&dwTest)==S_OK) qDebug("get_paramBasePointerRegisterId");
    if(pSymbol->get_localBasePointerRegisterId(&dwTest)==S_OK) qDebug("get_localBasePointerRegisterId");
    if(pSymbol->get_isLocationControlFlowDependent(&bTest)==S_OK) qDebug("get_isLocationControlFlowDependent");
    if(pSymbol->get_stride(&dwTest)==S_OK) qDebug("get_stride");
    if(pSymbol->get_numberOfRows(&dwTest)==S_OK) qDebug("get_numberOfRows");
    if(pSymbol->get_numberOfColumns(&dwTest)==S_OK) qDebug("get_numberOfColumns");
    if(pSymbol->get_isMatrixRowMajor(&bTest)==S_OK) qDebug("get_isMatrixRowMajor");
    if(pSymbol->get_numericProperties(0,&dwTest,dwData)==S_OK) qDebug("get_numericProperties");
    if(pSymbol->get_modifierValues(0,&dwTest,wData)==S_OK) qDebug("get_modifierValues");
    if(pSymbol->get_isReturnValue(&bTest)==S_OK) qDebug("get_isReturnValue");
    if(pSymbol->get_isOptimizedAway(&bTest)==S_OK) qDebug("get_isOptimizedAway");
    if(pSymbol->get_builtInKind(&dwTest)==S_OK) qDebug("get_builtInKind");
    if(pSymbol->get_registerType(&dwTest)==S_OK) qDebug("get_registerType");
    if(pSymbol->get_baseDataSlot(&dwTest)==S_OK) qDebug("get_baseDataSlot");
    if(pSymbol->get_baseDataOffset(&dwTest)==S_OK) qDebug("get_baseDataOffset");
    if(pSymbol->get_textureSlot(&dwTest)==S_OK) qDebug("get_textureSlot");
    if(pSymbol->get_samplerSlot(&dwTest)==S_OK) qDebug("get_samplerSlot");
    if(pSymbol->get_uavSlot(&dwTest)==S_OK) qDebug("get_uavSlot");
    if(pSymbol->get_sizeInUdt(&dwTest)==S_OK) qDebug("get_sizeInUdt");
    if(pSymbol->get_memorySpaceKind(&dwTest)==S_OK) qDebug("get_memorySpaceKind");
    if(pSymbol->get_unmodifiedTypeId(&dwTest)==S_OK) qDebug("get_unmodifiedTypeId");
    if(pSymbol->get_subTypeId(&dwTest)==S_OK) qDebug("get_subTypeId");
    if(pSymbol->get_subType(&pSymbolTest)==S_OK) qDebug("get_subType");
    if(pSymbol->get_numberOfModifiers(&dwTest)==S_OK) qDebug("get_numberOfModifiers");
    if(pSymbol->get_numberOfRegisterIndices(&dwTest)==S_OK) qDebug("get_numberOfRegisterIndices");
    if(pSymbol->get_isHLSLData(&bTest)==S_OK) qDebug("get_isHLSLData");
    if(pSymbol->get_isPointerToDataMember(&bTest)==S_OK) qDebug("get_isPointerToDataMember");
    if(pSymbol->get_isPointerToMemberFunction(&bTest)==S_OK) qDebug("get_isPointerToMemberFunction");
    if(pSymbol->get_isSingleInheritance(&bTest)==S_OK) qDebug("get_isSingleInheritance");
    if(pSymbol->get_isMultipleInheritance(&bTest)==S_OK) qDebug("get_isMultipleInheritance");
    if(pSymbol->get_isVirtualInheritance(&bTest)==S_OK) qDebug("get_isVirtualInheritance");
    if(pSymbol->get_restrictedType(&bTest)==S_OK) qDebug("get_restrictedType");
    if(pSymbol->get_isPointerBasedOnSymbolValue(&bTest)==S_OK) qDebug("get_isPointerBasedOnSymbolValue");
    if(pSymbol->get_baseSymbol(&pSymbolTest)==S_OK) qDebug("get_baseSymbol");
    if(pSymbol->get_baseSymbolId(&dwTest)==S_OK) qDebug("get_baseSymbolId");
    if(pSymbol->get_objectFileName(&strTest)==S_OK) qDebug("get_objectFileName");
    if(pSymbol->get_isAcceleratorGroupSharedLocal(&bTest)==S_OK) qDebug("get_isAcceleratorGroupSharedLocal");
    if(pSymbol->get_isAcceleratorPointerTagLiveRange(&bTest)==S_OK) qDebug("get_isAcceleratorPointerTagLiveRange");
    if(pSymbol->get_isAcceleratorStubFunction(&bTest)==S_OK) qDebug("get_isAcceleratorStubFunction");
    if(pSymbol->get_numberOfAcceleratorPointerTags(&dwTest)==S_OK) qDebug("get_numberOfAcceleratorPointerTags");
    if(pSymbol->get_isSdl(&bTest)==S_OK) qDebug("get_isSdl");
    if(pSymbol->get_isWinRTPointer(&bTest)==S_OK) qDebug("get_isWinRTPointer");
    if(pSymbol->get_isRefUdt(&bTest)==S_OK) qDebug("get_isRefUdt");
    if(pSymbol->get_isValueUdt(&bTest)==S_OK) qDebug("get_isValueUdt");
    if(pSymbol->get_isInterfaceUdt(&bTest)==S_OK) qDebug("get_isInterfaceUdt");
//    if(pSymbol->findInlineFramesByAddr(&bTest)==S_OK) qDebug("findInlineFramesByAddr");
//    if(pSymbol->findInlineFramesByRVA(&bTest)==S_OK) qDebug("findInlineFramesByRVA");
//    if(pSymbol->findInlineFramesByVA(&bTest)==S_OK) qDebug("findInlineFramesByVA");
//    if(pSymbol->findInlineeLines(&bTest)==S_OK) qDebug("findInlineeLines");
//    if(pSymbol->findInlineeLinesByAddr(&bTest)==S_OK) qDebug("findInlineeLinesByAddr");
//    if(pSymbol->findInlineeLinesByRVA(&bTest)==S_OK) qDebug("findInlineeLinesByRVA");
//    if(pSymbol->findInlineeLinesByVA(&bTest)==S_OK) qDebug("findInlineeLinesByVA");
//    if(pSymbol->findSymbolsForAcceleratorPointerTag(&bTest)==S_OK) qDebug("findSymbolsForAcceleratorPointerTag");
//    if(pSymbol->findSymbolsByRVAForAcceleratorPointerTag(&bTest)==S_OK) qDebug("findSymbolsByRVAForAcceleratorPointerTag");
//    if(pSymbol->get_acceleratorPointerTags(&bTest)==S_OK) qDebug("get_acceleratorPointerTags");
//    if(pSymbol->getSrcLineOnTypeDefn(&bTest)==S_OK) qDebug("getSrcLineOnTypeDefn");
    if(pSymbol->get_isPGO(&bTest)==S_OK) qDebug("get_isPGO");
    if(pSymbol->get_hasValidPGOCounts(&bTest)==S_OK) qDebug("get_hasValidPGOCounts");
    if(pSymbol->get_isOptimizedForSpeed(&bTest)==S_OK) qDebug("get_isOptimizedForSpeed");
    if(pSymbol->get_PGOEntryCount(&dwTest)==S_OK) qDebug("get_PGOEntryCount");
    if(pSymbol->get_PGOEdgeCount(&dwTest)==S_OK) qDebug("get_PGOEdgeCount");
    if(pSymbol->get_PGODynamicInstructionCount(&ullTest)==S_OK) qDebug("get_PGODynamicInstructionCount");
    if(pSymbol->get_staticSize(&dwTest)==S_OK) qDebug("get_staticSize");
    if(pSymbol->get_finalLiveStaticSize(&dwTest)==S_OK) qDebug("get_finalLiveStaticSize");
    if(pSymbol->get_phaseName(&strTest)==S_OK) qDebug("get_phaseName");
    if(pSymbol->get_hasControlFlowCheck(&bTest)==S_OK) qDebug("get_hasControlFlowCheck");
    if(pSymbol->get_constantExport(&bTest)==S_OK) qDebug("get_constantExport");
    if(pSymbol->get_dataExport(&bTest)==S_OK) qDebug("get_dataExport");
    if(pSymbol->get_privateExport(&bTest)==S_OK) qDebug("get_privateExport");
    if(pSymbol->get_noNameExport(&bTest)==S_OK) qDebug("get_noNameExport");
    if(pSymbol->get_exportHasExplicitlyAssignedOrdinal(&bTest)==S_OK) qDebug("get_exportHasExplicitlyAssignedOrdinal");
    if(pSymbol->get_exportIsForwarder(&bTest)==S_OK) qDebug("get_exportIsForwarder");
    if(pSymbol->get_ordinal(&dwTest)==S_OK) qDebug("get_ordinal");
    if(pSymbol->get_frameSize(&dwTest)==S_OK) qDebug("get_frameSize");
    if(pSymbol->get_exceptionHandlerAddressSection(&dwTest)==S_OK) qDebug("get_exceptionHandlerAddressSection");
    if(pSymbol->get_exceptionHandlerAddressOffset(&dwTest)==S_OK) qDebug("get_exceptionHandlerAddressOffset");
    if(pSymbol->get_exceptionHandlerRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_exceptionHandlerRelativeVirtualAddress");
    if(pSymbol->get_exceptionHandlerVirtualAddress(&ullTest)==S_OK) qDebug("get_exceptionHandlerVirtualAddress");
    if(pSymbol->findInputAssemblyFile(&iafTest)==S_OK) qDebug("findInputAssemblyFile");
    if(pSymbol->get_characteristics(&dwTest)==S_OK) qDebug("get_characteristics");
    if(pSymbol->get_coffGroup(&pSymbolTest)==S_OK) qDebug("get_coffGroup");
    if(pSymbol->get_bindID(&dwTest)==S_OK) qDebug("get_bindID");
    if(pSymbol->get_bindSpace(&dwTest)==S_OK) qDebug("get_bindSpace");
    if(pSymbol->get_bindSlot(&dwTest)==S_OK) qDebug("get_bindSlot");
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::_get_symIndexId(IDiaSymbol *pSymbol)
{
    quint32 nResult=0;
    DWORD dwTemp=0;

    if(pSymbol->get_symIndexId(&dwTemp)==S_OK)
    {
        nResult=dwTemp;
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::_get_symTag(IDiaSymbol *pSymbol)
{
    quint32 nResult=0;
    DWORD dwTemp=0;

    if(pSymbol->get_symTag(&dwTemp)==S_OK)
    {
        nResult=dwTemp;
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::_get_compilerName(IDiaSymbol *pSymbol)
{
    QString sResult;

    BSTR bstring=nullptr;

    if(pSymbol->get_compilerName(&bstring)==S_OK)
    {
        sResult=QString::fromWCharArray(bstring);
        SysFreeString(bstring);
    }

    return sResult;
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::_get_Count(IDiaEnumSymbols *pEnumSymbols)
{
    quint32 nResult=0;
    LONG lTemp=0;

    if(pEnumSymbols->get_Count(&lTemp)==S_OK)
    {
        nResult=lTemp;
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::_get_name(IDiaSymbol *pSymbol)
{
    QString sResult;

    BSTR bstring=nullptr;

    if(pSymbol->get_name(&bstring)==S_OK)
    {
        sResult=QString::fromWCharArray(bstring);
        SysFreeString(bstring);
    }

    return sResult;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::_get_guid(IDiaSymbol *pSymbol)
{
    QString sResult;

    GUID guid;

    if(pSymbol->get_guid(&guid)==S_OK)
    {
        QUuid uuid(guid.Data1,guid.Data2,guid.Data3,
                                        guid.Data4[0],
                                        guid.Data4[1],
                                        guid.Data4[2],
                                        guid.Data4[3],
                                        guid.Data4[4],
                                        guid.Data4[5],
                                        guid.Data4[6],
                                        guid.Data4[7]);
        sResult=uuid.toString().remove("{").remove("}");
    }

    return sResult;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::_get_symbolsFileName(IDiaSymbol *pSymbol)
{
    QString sResult;

    BSTR bstring=nullptr;

    if(pSymbol->get_symbolsFileName(&bstring)==S_OK)
    {
        sResult=QString::fromWCharArray(bstring);
        SysFreeString(bstring);
    }

    return sResult;
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::_get_age(IDiaSymbol *pSymbol)
{
    quint32 nResult=0;
    DWORD dwTemp=0;

    if(pSymbol->get_age(&dwTemp)==S_OK)
    {
        nResult=dwTemp;
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::_get_signature(IDiaSymbol *pSymbol)
{
    quint32 nResult=0;
    DWORD dwTemp=0;

    if(pSymbol->get_signature(&dwTemp)==S_OK)
    {
        nResult=dwTemp;
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::_get_machineType(IDiaSymbol *pSymbol)
{
    quint32 nResult=0;
    DWORD dwTemp=0;

    if(pSymbol->get_machineType(&dwTemp)==S_OK)
    {
        nResult=dwTemp;
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
bool XWinPDB::_get_isCTypes(IDiaSymbol *pSymbol)
{
    bool bResult=false;
    BOOL bTemp=0;

    if(pSymbol->get_isCTypes(&bTemp)==S_OK)
    {
        bResult=bTemp;
    }

    return bResult;
}
#endif
#ifdef Q_OS_WIN
bool XWinPDB::_get_isStripped(IDiaSymbol *pSymbol)
{
    bool bResult=false;
    BOOL bTemp=0;

    if(pSymbol->get_isStripped(&bTemp)==S_OK)
    {
        bResult=bTemp;
    }

    return bResult;
}
#endif
