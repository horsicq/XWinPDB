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

#ifdef Q_OS_WIN32
#define X_PDB_FUNCTION_DWORD(func_name,pdb_name) \
quint32 func_name(IDiaSymbol *pSymbol)      \
{                                           \
    quint32 nResult=0;                      \
    DWORD dwTemp=0;                         \
    if(pSymbol->pdb_name(&dwTemp)==S_OK)    \
    {                                       \
        nResult=dwTemp;                     \
    }                                       \
    return nResult;                         \
}                                           \

X_PDB_FUNCTION_DWORD(_get_symIndexId,get_symIndexId)
X_PDB_FUNCTION_DWORD(_get_symTag,get_symTag)
X_PDB_FUNCTION_DWORD(_get_age,get_age)
X_PDB_FUNCTION_DWORD(_get_signature,get_signature)
X_PDB_FUNCTION_DWORD(_get_machineType,get_machineType)
X_PDB_FUNCTION_DWORD(_get_lexicalParentId,get_lexicalParentId)
X_PDB_FUNCTION_DWORD(_get_PGOEdgeCount,get_PGOEdgeCount)
X_PDB_FUNCTION_DWORD(_get_PGOEntryCount,get_PGOEntryCount)
X_PDB_FUNCTION_DWORD(_get_access,get_access)
X_PDB_FUNCTION_DWORD(_get_addressOffset,get_addressOffset)
X_PDB_FUNCTION_DWORD(_get_addressSection,get_addressSection)
X_PDB_FUNCTION_DWORD(_get_arrayIndexTypeId,get_arrayIndexTypeId)
X_PDB_FUNCTION_DWORD(_get_backEndBuild,get_backEndBuild)
X_PDB_FUNCTION_DWORD(_get_backEndMajor,get_backEndMajor)
X_PDB_FUNCTION_DWORD(_get_backEndMinor,get_backEndMinor)
X_PDB_FUNCTION_DWORD(_get_backEndQFE,get_backEndQFE)
X_PDB_FUNCTION_DWORD(_get_baseDataOffset,get_baseDataOffset)
X_PDB_FUNCTION_DWORD(_get_baseDataSlot,get_baseDataSlot)
X_PDB_FUNCTION_DWORD(_get_baseSymbolId,get_baseSymbolId)
X_PDB_FUNCTION_DWORD(_get_baseType,get_baseType)
X_PDB_FUNCTION_DWORD(_get_bindID,get_bindID)
X_PDB_FUNCTION_DWORD(_get_bindSlot,get_bindSlot)
X_PDB_FUNCTION_DWORD(_get_bindSpace,get_bindSpace)
X_PDB_FUNCTION_DWORD(_get_bitPosition,get_bitPosition)
X_PDB_FUNCTION_DWORD(_get_builtInKind,get_builtInKind)
X_PDB_FUNCTION_DWORD(_get_callingConvention,get_callingConvention)
X_PDB_FUNCTION_DWORD(_get_characteristics,get_characteristics)
X_PDB_FUNCTION_DWORD(_get_classParentId,get_classParentId)
X_PDB_FUNCTION_DWORD(_get_count,get_count)
X_PDB_FUNCTION_DWORD(_get_countLiveRanges,get_countLiveRanges)
X_PDB_FUNCTION_DWORD(_get_dataKind,get_dataKind)
X_PDB_FUNCTION_DWORD(_get_exceptionHandlerAddressOffset,get_exceptionHandlerAddressOffset)
X_PDB_FUNCTION_DWORD(_get_exceptionHandlerAddressSection,get_exceptionHandlerAddressSection)
X_PDB_FUNCTION_DWORD(_get_exceptionHandlerRelativeVirtualAddress,get_exceptionHandlerRelativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_get_finalLiveStaticSize,get_finalLiveStaticSize)
X_PDB_FUNCTION_DWORD(_get_frameSize,get_frameSize)
X_PDB_FUNCTION_DWORD(_get_frontEndBuild,get_frontEndBuild)
X_PDB_FUNCTION_DWORD(_get_frontEndMajor,get_frontEndMajor)
X_PDB_FUNCTION_DWORD(_get_frontEndMinor,get_frontEndMinor)
X_PDB_FUNCTION_DWORD(_get_frontEndQFE,get_frontEndQFE)
X_PDB_FUNCTION_DWORD(_get_language,get_language)
X_PDB_FUNCTION_DWORD(_get_liveRangeStartAddressOffset,get_liveRangeStartAddressOffset)
X_PDB_FUNCTION_DWORD(_get_liveRangeStartAddressSection,get_liveRangeStartAddressSection)
X_PDB_FUNCTION_DWORD(_get_liveRangeStartRelativeVirtualAddress,get_liveRangeStartRelativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_get_localBasePointerRegisterId,get_localBasePointerRegisterId)
X_PDB_FUNCTION_DWORD(_get_locationType,get_locationType)
X_PDB_FUNCTION_DWORD(_get_lowerBoundId,get_lowerBoundId)
X_PDB_FUNCTION_DWORD(_get_memorySpaceKind,get_memorySpaceKind)
X_PDB_FUNCTION_DWORD(_get_numberOfAcceleratorPointerTags,get_numberOfAcceleratorPointerTags)
X_PDB_FUNCTION_DWORD(_get_numberOfColumns,get_numberOfColumns)
X_PDB_FUNCTION_DWORD(_get_numberOfModifiers,get_numberOfModifiers)
X_PDB_FUNCTION_DWORD(_get_numberOfRegisterIndices,get_numberOfRegisterIndices)
X_PDB_FUNCTION_DWORD(_get_numberOfRows,get_numberOfRows)
X_PDB_FUNCTION_DWORD(_get_oemId,get_oemId)
X_PDB_FUNCTION_DWORD(_get_oemSymbolId,get_oemSymbolId)
X_PDB_FUNCTION_DWORD(_get_offsetInUdt,get_offsetInUdt)
X_PDB_FUNCTION_DWORD(_get_ordinal,get_ordinal)
X_PDB_FUNCTION_DWORD(_get_paramBasePointerRegisterId,get_paramBasePointerRegisterId)
X_PDB_FUNCTION_DWORD(_get_platform,get_platform)
X_PDB_FUNCTION_DWORD(_get_rank,get_rank)
X_PDB_FUNCTION_DWORD(_get_registerId,get_registerId)
X_PDB_FUNCTION_DWORD(_get_registerType,get_registerType)
X_PDB_FUNCTION_DWORD(_get_relativeVirtualAddress,get_relativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_get_samplerSlot,get_samplerSlot)
X_PDB_FUNCTION_DWORD(_get_sizeInUdt,get_sizeInUdt)
X_PDB_FUNCTION_DWORD(_get_slot,get_slot)
X_PDB_FUNCTION_DWORD(_get_staticSize,get_staticSize)
X_PDB_FUNCTION_DWORD(_get_stride,get_stride)
X_PDB_FUNCTION_DWORD(_get_subTypeId,get_subTypeId)
X_PDB_FUNCTION_DWORD(_get_targetOffset,get_targetOffset)
X_PDB_FUNCTION_DWORD(_get_targetRelativeVirtualAddress,get_targetRelativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_get_targetSection,get_targetSection)
X_PDB_FUNCTION_DWORD(_get_textureSlot,get_textureSlot)
X_PDB_FUNCTION_DWORD(_get_thunkOrdinal,get_thunkOrdinal)
X_PDB_FUNCTION_DWORD(_get_timeStamp,get_timeStamp)
X_PDB_FUNCTION_DWORD(_get_token,get_token)
X_PDB_FUNCTION_DWORD(_get_typeId,get_typeId)
X_PDB_FUNCTION_DWORD(_get_uavSlot,get_uavSlot)
X_PDB_FUNCTION_DWORD(_get_udtKind,get_udtKind)
X_PDB_FUNCTION_DWORD(_get_unmodifiedTypeId,get_unmodifiedTypeId)
X_PDB_FUNCTION_DWORD(_get_upperBoundId,get_upperBoundId)
X_PDB_FUNCTION_DWORD(_get_virtualBaseDispIndex,get_virtualBaseDispIndex)
X_PDB_FUNCTION_DWORD(_get_virtualBaseOffset,get_virtualBaseOffset)
X_PDB_FUNCTION_DWORD(_get_virtualTableShapeId,get_virtualTableShapeId)

#define X_PDB_FUNCTION_BOOL(func_name,pdb_name) \
bool func_name(IDiaSymbol *pSymbol)             \
{                                               \
    bool bResult=false;                         \
    BOOL bTemp=0;                               \
    if(pSymbol->pdb_name(&bTemp)==S_OK)         \
    {                                           \
        bResult=bTemp;                          \
    }                                           \
    return bResult;                             \
}                                               \

X_PDB_FUNCTION_BOOL(_get_isCTypes,get_isCTypes)
X_PDB_FUNCTION_BOOL(_get_isStripped,get_isStripped)
X_PDB_FUNCTION_BOOL(_get_RValueReference,get_RValueReference)
X_PDB_FUNCTION_BOOL(_get_addressTaken,get_addressTaken)
X_PDB_FUNCTION_BOOL(_get_code,get_code)
X_PDB_FUNCTION_BOOL(_get_compilerGenerated,get_compilerGenerated)
X_PDB_FUNCTION_BOOL(_get_constType,get_constType)
X_PDB_FUNCTION_BOOL(_get_constantExport,get_constantExport)
X_PDB_FUNCTION_BOOL(_get_constructor,get_constructor)
X_PDB_FUNCTION_BOOL(_get_customCallingConvention,get_customCallingConvention)
X_PDB_FUNCTION_BOOL(_get_dataExport,get_dataExport)
X_PDB_FUNCTION_BOOL(_get_editAndContinueEnabled,get_editAndContinueEnabled)
X_PDB_FUNCTION_BOOL(_get_exportIsForwarder,get_exportIsForwarder)
X_PDB_FUNCTION_BOOL(_get_farReturn,get_farReturn)
X_PDB_FUNCTION_BOOL(_get_framePointerPresent,get_framePointerPresent)
X_PDB_FUNCTION_BOOL(_get_function,get_function)
X_PDB_FUNCTION_BOOL(_get_hasAlloca,get_hasAlloca)
X_PDB_FUNCTION_BOOL(_get_hasAssignmentOperator,get_hasAssignmentOperator)
X_PDB_FUNCTION_BOOL(_get_hasCastOperator,get_hasCastOperator)
X_PDB_FUNCTION_BOOL(_get_hasControlFlowCheck,get_hasControlFlowCheck)
X_PDB_FUNCTION_BOOL(_get_hasDebugInfo,get_hasDebugInfo)
X_PDB_FUNCTION_BOOL(_get_hasEH,get_hasEH)
X_PDB_FUNCTION_BOOL(_get_hasEHa,get_hasEHa)
X_PDB_FUNCTION_BOOL(_get_hasInlAsm,get_hasInlAsm)
X_PDB_FUNCTION_BOOL(_get_hasLongJump,get_hasLongJump)
X_PDB_FUNCTION_BOOL(_get_hasManagedCode,get_hasManagedCode)
X_PDB_FUNCTION_BOOL(_get_hasNestedTypes,get_hasNestedTypes)
X_PDB_FUNCTION_BOOL(_get_hasSEH,get_hasSEH)
X_PDB_FUNCTION_BOOL(_get_hasSecurityChecks,get_hasSecurityChecks)
X_PDB_FUNCTION_BOOL(_get_hasSetJump,get_hasSetJump)
X_PDB_FUNCTION_BOOL(_get_hasValidPGOCounts,get_hasValidPGOCounts)
X_PDB_FUNCTION_BOOL(_get_hfaDouble,get_hfaDouble)
X_PDB_FUNCTION_BOOL(_get_hfaFloat,get_hfaFloat)
X_PDB_FUNCTION_BOOL(_get_indirectVirtualBaseClass,get_indirectVirtualBaseClass)
X_PDB_FUNCTION_BOOL(_get_inlSpec,get_inlSpec)
X_PDB_FUNCTION_BOOL(_get_interruptReturn,get_interruptReturn)
X_PDB_FUNCTION_BOOL(_get_intrinsic,get_intrinsic)
X_PDB_FUNCTION_BOOL(_get_intro,get_intro)
X_PDB_FUNCTION_BOOL(_get_isAcceleratorGroupSharedLocal,get_isAcceleratorGroupSharedLocal)
X_PDB_FUNCTION_BOOL(_get_isAcceleratorPointerTagLiveRange,get_isAcceleratorPointerTagLiveRange)
X_PDB_FUNCTION_BOOL(_get_isAcceleratorStubFunction,get_isAcceleratorStubFunction)
X_PDB_FUNCTION_BOOL(_get_isAggregated,get_isAggregated)
X_PDB_FUNCTION_BOOL(_get_isCVTCIL,get_isCVTCIL)
X_PDB_FUNCTION_BOOL(_get_isConstructorVirtualBase,get_isConstructorVirtualBase)
X_PDB_FUNCTION_BOOL(_get_isCxxReturnUdt,get_isCxxReturnUdt)
X_PDB_FUNCTION_BOOL(_get_isDataAligned,get_isDataAligned)
X_PDB_FUNCTION_BOOL(_get_isHLSLData,get_isHLSLData)
X_PDB_FUNCTION_BOOL(_get_isHotpatchable,get_isHotpatchable)
X_PDB_FUNCTION_BOOL(_get_isInterfaceUdt,get_isInterfaceUdt)
X_PDB_FUNCTION_BOOL(_get_exportHasExplicitlyAssignedOrdinal,get_exportHasExplicitlyAssignedOrdinal)
X_PDB_FUNCTION_BOOL(_get_isLocationControlFlowDependent,get_isLocationControlFlowDependent)
X_PDB_FUNCTION_BOOL(_get_isMSILNetmodule,get_isMSILNetmodule)
X_PDB_FUNCTION_BOOL(_get_isMatrixRowMajor,get_isMatrixRowMajor)
X_PDB_FUNCTION_BOOL(_get_isMultipleInheritance,get_isMultipleInheritance)
X_PDB_FUNCTION_BOOL(_get_isNaked,get_isNaked)
X_PDB_FUNCTION_BOOL(_get_isOptimizedAway,get_isOptimizedAway)
X_PDB_FUNCTION_BOOL(_get_isOptimizedForSpeed,get_isOptimizedForSpeed)
X_PDB_FUNCTION_BOOL(_get_isPGO,get_isPGO)
X_PDB_FUNCTION_BOOL(_get_isPointerBasedOnSymbolValue,get_isPointerBasedOnSymbolValue)
X_PDB_FUNCTION_BOOL(_get_isPointerToDataMember,get_isPointerToDataMember)
X_PDB_FUNCTION_BOOL(_get_isPointerToMemberFunction,get_isPointerToMemberFunction)
X_PDB_FUNCTION_BOOL(_get_isRefUdt,get_isRefUdt)
X_PDB_FUNCTION_BOOL(_get_isReturnValue,get_isReturnValue)
X_PDB_FUNCTION_BOOL(_get_isSafeBuffers,get_isSafeBuffers)
X_PDB_FUNCTION_BOOL(_get_isSdl,get_isSdl)
X_PDB_FUNCTION_BOOL(_get_isSingleInheritance,get_isSingleInheritance)
X_PDB_FUNCTION_BOOL(_get_isSplitted,get_isSplitted)
X_PDB_FUNCTION_BOOL(_get_isStatic,get_isStatic)
X_PDB_FUNCTION_BOOL(_get_isValueUdt,get_isValueUdt)
X_PDB_FUNCTION_BOOL(_get_isVirtualInheritance,get_isVirtualInheritance)
X_PDB_FUNCTION_BOOL(_get_isWinRTPointer,get_isWinRTPointer)
X_PDB_FUNCTION_BOOL(_get_managed,get_managed)
X_PDB_FUNCTION_BOOL(_get_msil,get_msil)
X_PDB_FUNCTION_BOOL(_get_nested,get_nested)
X_PDB_FUNCTION_BOOL(_get_noInline,get_noInline)
X_PDB_FUNCTION_BOOL(_get_noNameExport,get_noNameExport)
X_PDB_FUNCTION_BOOL(_get_noReturn,get_noReturn)
X_PDB_FUNCTION_BOOL(_get_noStackOrdering,get_noStackOrdering)
X_PDB_FUNCTION_BOOL(_get_notReached,get_notReached)
X_PDB_FUNCTION_BOOL(_get_optimizedCodeDebugInfo,get_optimizedCodeDebugInfo)
X_PDB_FUNCTION_BOOL(_get_overloadedOperator,get_overloadedOperator)
X_PDB_FUNCTION_BOOL(_get_packed,get_packed)
X_PDB_FUNCTION_BOOL(_get_privateExport,get_privateExport)
X_PDB_FUNCTION_BOOL(_get_pure,get_pure)
X_PDB_FUNCTION_BOOL(_get_reference,get_reference)
X_PDB_FUNCTION_BOOL(_get_restrictedType,get_restrictedType)
X_PDB_FUNCTION_BOOL(_get_scoped,get_scoped)
X_PDB_FUNCTION_BOOL(_get_sealed,get_sealed)
X_PDB_FUNCTION_BOOL(_get_strictGSCheck,get_strictGSCheck)
X_PDB_FUNCTION_BOOL(_get_unalignedType,get_unalignedType)
X_PDB_FUNCTION_BOOL(_get_virtual,get_virtual)
X_PDB_FUNCTION_BOOL(_get_virtualBaseClass,get_virtualBaseClass)
X_PDB_FUNCTION_BOOL(_get_volatileType,get_volatileType)
X_PDB_FUNCTION_BOOL(_get_wasInlined,get_wasInlined)
X_PDB_FUNCTION_BOOL(_get_isLTCG,get_isLTCG)

#define X_PDB_FUNCTION_BSTRING(func_name,pdb_name)  \
QString func_name(IDiaSymbol *pSymbol)              \
{                                                   \
    QString sResult;                                \
    BSTR bstring=nullptr;                           \
    if(pSymbol->pdb_name(&bstring)==S_OK)           \
    {                                               \
        sResult=QString::fromWCharArray(bstring);   \
        SysFreeString(bstring);                     \
    }                                               \
    return sResult;                                 \
}                                                   \

X_PDB_FUNCTION_BSTRING(_get_compilerName,get_compilerName)
X_PDB_FUNCTION_BSTRING(_get_libraryName,get_libraryName)
X_PDB_FUNCTION_BSTRING(_get_name,get_name)
X_PDB_FUNCTION_BSTRING(_get_objectFileName,get_objectFileName)
X_PDB_FUNCTION_BSTRING(_get_phaseName,get_phaseName)
X_PDB_FUNCTION_BSTRING(_get_sourceFileName,get_sourceFileName)
X_PDB_FUNCTION_BSTRING(_get_symbolsFileName,get_symbolsFileName)
X_PDB_FUNCTION_BSTRING(_get_undecoratedName,get_undecoratedName)
X_PDB_FUNCTION_BSTRING(_get_unused,get_unused)

QString _get_undecoratedNameEx(IDiaSymbol *pSymbol)
{
    QString sResult;
    BSTR bstring=nullptr;

    if(pSymbol->get_undecoratedNameEx(0,&bstring)==S_OK)
    {
        sResult=QString::fromWCharArray(bstring);
        SysFreeString(bstring);
    }

    return sResult;
}

quint32 _get_Count(IDiaEnumSymbols *pEnumSymbols)
{
    quint32 nResult=0;
    LONG lTemp=0;

    if(pEnumSymbols->get_Count(&lTemp)==S_OK)
    {
        nResult=lTemp;
    }

    return nResult;
}

QString _get_guid(IDiaSymbol *pSymbol)
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

        QSet<quint32> stTypes;

        if(nCount)
        {
            IDiaSymbol *pSymbol;
            ULONG celt=0;

            while(SUCCEEDED(pEnumSymbols->Next(1,&pSymbol,&celt))&&(celt==1)&&(!pPdStruct->bIsStop)) // TODO Stop
            {
                quint32 nSymTag=_get_symTag(pSymbol);

//                qDebug("SymTag: %d %d %d",nCurrent,nCount,nSymTag);

                if(!stTypes.contains(nSymTag))
                {
//                    qDebug("SymTag: %d %d %d",nCurrent,nCount,nSymTag);
                    _testSymbol(pSymbol);

                    stTypes.insert(nSymTag);
                }

//                if(nSymTag==SymTagCompiland)
//                {
//                    _testSymbol(pSymbol);
//                }
//                else
//                {
//                    qDebug("%d",nSymTag);
//                }

                pSymbol->Release();

                nCurrent++;
                setPdStructCurrent(pPdStruct,nCurrent);
            }
        }

        pEnumSymbols->Release();
    }

    setPdStructFinished(pPdStruct);

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
//    QString v_name=_get_name(g_pGlobal);
//    QString v_guid=_get_guid(g_pGlobal);
//    QString v_symbolsFileName=_get_symbolsFileName(g_pGlobal);
//    quint32 v_age=_get_age(g_pGlobal);
//    quint32 v_signature=_get_signature(g_pGlobal);
//    quint32 v_machineType=_get_machineType(g_pGlobal);
//    bool v_isCTypes=_get_isCTypes(g_pGlobal);
//    bool v_isStripped=_get_isStripped(g_pGlobal);

//    _testSymbol(g_pGlobal);
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

    if(pSymbol->findInputAssemblyFile(&iafTest)==S_OK) qDebug("findInputAssemblyFile");
    if(pSymbol->get_PGODynamicInstructionCount(&ullTest)==S_OK) qDebug("get_PGODynamicInstructionCount");
    if(pSymbol->get_PGOEdgeCount(&dwTest)==S_OK) qDebug("get_PGOEdgeCount: %d",_get_PGOEdgeCount(pSymbol));
    if(pSymbol->get_PGOEntryCount(&dwTest)==S_OK) qDebug("get_PGOEntryCount: %d",_get_PGOEntryCount(pSymbol));
    if(pSymbol->get_RValueReference(&bTest)==S_OK) qDebug("get_RValueReference: %d",_get_RValueReference(pSymbol));
    if(pSymbol->get_access(&dwTest)==S_OK) qDebug("get_access: %d",_get_access(pSymbol));
    if(pSymbol->get_addressOffset(&dwTest)==S_OK) qDebug("get_addressOffset: %d",_get_addressOffset(pSymbol));
    if(pSymbol->get_addressSection(&dwTest)==S_OK) qDebug("get_addressSection: %d",_get_addressSection(pSymbol));
    if(pSymbol->get_addressTaken(&bTest)==S_OK) qDebug("get_addressTaken: %d",_get_addressTaken(pSymbol));
    if(pSymbol->get_age(&dwTest)==S_OK) qDebug("get_age: %d",_get_age(pSymbol));
    if(pSymbol->get_arrayIndexType(&pSymbolTest)==S_OK) qDebug("get_arrayIndexType");
    if(pSymbol->get_arrayIndexTypeId(&dwTest)==S_OK) qDebug("get_arrayIndexTypeId: %d",_get_arrayIndexTypeId(pSymbol));
    if(pSymbol->get_backEndBuild(&dwTest)==S_OK) qDebug("get_backEndBuild: %d",_get_backEndBuild(pSymbol));
    if(pSymbol->get_backEndMajor(&dwTest)==S_OK) qDebug("get_backEndMajor: %d",_get_backEndMajor(pSymbol));
    if(pSymbol->get_backEndMinor(&dwTest)==S_OK) qDebug("get_backEndMinor: %d",_get_backEndMinor(pSymbol));
    if(pSymbol->get_backEndQFE(&dwTest)==S_OK) qDebug("get_backEndQFE: %d",_get_backEndQFE(pSymbol));
    if(pSymbol->get_baseDataOffset(&dwTest)==S_OK) qDebug("get_baseDataOffset: %d",_get_baseDataOffset(pSymbol));
    if(pSymbol->get_baseDataSlot(&dwTest)==S_OK) qDebug("get_baseDataSlot: %d",_get_baseDataSlot(pSymbol));
    if(pSymbol->get_baseSymbol(&pSymbolTest)==S_OK) qDebug("get_baseSymbol");
    if(pSymbol->get_baseSymbolId(&dwTest)==S_OK) qDebug("get_baseSymbolId: %d",_get_baseSymbolId(pSymbol));
    if(pSymbol->get_baseType(&dwTest)==S_OK) qDebug("get_baseType: %d",_get_baseType(pSymbol));
    if(pSymbol->get_bindID(&dwTest)==S_OK) qDebug("get_bindID: %d",_get_bindID(pSymbol));
    if(pSymbol->get_bindSlot(&dwTest)==S_OK) qDebug("get_bindSlot: %d",_get_bindSlot(pSymbol));
    if(pSymbol->get_bindSpace(&dwTest)==S_OK) qDebug("get_bindSpace: %d",_get_bindSpace(pSymbol));
    if(pSymbol->get_bitPosition(&dwTest)==S_OK) qDebug("get_bitPosition: %d",_get_bitPosition(pSymbol));
    if(pSymbol->get_builtInKind(&dwTest)==S_OK) qDebug("get_builtInKind: %d",_get_builtInKind(pSymbol));
    if(pSymbol->get_callingConvention(&dwTest)==S_OK) qDebug("get_callingConvention: %d",_get_callingConvention(pSymbol));
    if(pSymbol->get_characteristics(&dwTest)==S_OK) qDebug("get_characteristics: %d",_get_characteristics(pSymbol));
    if(pSymbol->get_classParent(&pSymbolTest)==S_OK) qDebug("get_classParent");
    if(pSymbol->get_classParentId(&dwTest)==S_OK) qDebug("get_classParentId: %d",_get_classParentId(pSymbol));
    if(pSymbol->get_code(&bTest)==S_OK) qDebug("get_code: %d",_get_code(pSymbol));
    if(pSymbol->get_coffGroup(&pSymbolTest)==S_OK) qDebug("get_coffGroup");
    if(pSymbol->get_compilerGenerated(&bTest)==S_OK) qDebug("get_compilerGenerated: %d",_get_compilerGenerated(pSymbol));
    if(pSymbol->get_compilerName(&strTest)==S_OK) qDebug("get_compilerName: %s",_get_compilerName(pSymbol).toLatin1().data());
    if(pSymbol->get_constType(&bTest)==S_OK) qDebug("get_constType: %d",_get_constType(pSymbol));
    if(pSymbol->get_constantExport(&bTest)==S_OK) qDebug("get_constantExport: %d",_get_constantExport(pSymbol));
    if(pSymbol->get_constructor(&bTest)==S_OK) qDebug("get_constructor: %d",_get_constructor(pSymbol));
    if(pSymbol->get_container(&pSymbolTest)==S_OK) qDebug("get_container");
    if(pSymbol->get_count(&dwTest)==S_OK) qDebug("get_count: %d",_get_count(pSymbol));
    if(pSymbol->get_countLiveRanges(&dwTest)==S_OK) qDebug("get_countLiveRanges: %d",_get_countLiveRanges(pSymbol));
    if(pSymbol->get_customCallingConvention(&bTest)==S_OK) qDebug("get_customCallingConvention: %d",_get_customCallingConvention(pSymbol));
    if(pSymbol->get_dataBytes(256,&dwTest,bData)==S_OK) qDebug("get_dataBytes");
    if(pSymbol->get_dataExport(&bTest)==S_OK) qDebug("get_dataExport: %d",_get_dataExport(pSymbol));
    if(pSymbol->get_dataKind(&dwTest)==S_OK) qDebug("get_dataKind: %d",_get_dataKind(pSymbol));
    if(pSymbol->get_editAndContinueEnabled(&bTest)==S_OK) qDebug("get_editAndContinueEnabled: %d",_get_editAndContinueEnabled(pSymbol));
    if(pSymbol->get_exceptionHandlerAddressOffset(&dwTest)==S_OK) qDebug("get_exceptionHandlerAddressOffset: %d",_get_exceptionHandlerAddressOffset(pSymbol));
    if(pSymbol->get_exceptionHandlerAddressSection(&dwTest)==S_OK) qDebug("get_exceptionHandlerAddressSection: %d",_get_exceptionHandlerAddressSection(pSymbol));
    if(pSymbol->get_exceptionHandlerRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_exceptionHandlerRelativeVirtualAddress: %d",_get_exceptionHandlerRelativeVirtualAddress(pSymbol));
    if(pSymbol->get_exceptionHandlerVirtualAddress(&ullTest)==S_OK) qDebug("get_exceptionHandlerVirtualAddress");
    if(pSymbol->get_exportHasExplicitlyAssignedOrdinal(&bTest)==S_OK) qDebug("get_exportHasExplicitlyAssignedOrdinal: %d",_get_exportHasExplicitlyAssignedOrdinal(pSymbol));
    if(pSymbol->get_exportIsForwarder(&bTest)==S_OK) qDebug("get_exportIsForwarder: %d",_get_exportIsForwarder(pSymbol));
    if(pSymbol->get_farReturn(&bTest)==S_OK) qDebug("get_farReturn: %d",_get_farReturn(pSymbol));
    if(pSymbol->get_finalLiveStaticSize(&dwTest)==S_OK) qDebug("get_finalLiveStaticSize: %d",_get_finalLiveStaticSize(pSymbol));
    if(pSymbol->get_framePointerPresent(&bTest)==S_OK) qDebug("get_framePointerPresent: %d",_get_framePointerPresent(pSymbol));
    if(pSymbol->get_frameSize(&dwTest)==S_OK) qDebug("get_frameSize: %d",_get_frameSize(pSymbol));
    if(pSymbol->get_frontEndBuild(&dwTest)==S_OK) qDebug("get_frontEndBuild: %d",_get_frontEndBuild(pSymbol));
    if(pSymbol->get_frontEndMajor(&dwTest)==S_OK) qDebug("get_frontEndMajor: %d",_get_frontEndMajor(pSymbol));
    if(pSymbol->get_frontEndMinor(&dwTest)==S_OK) qDebug("get_frontEndMinor: %d",_get_frontEndMinor(pSymbol));
    if(pSymbol->get_frontEndQFE(&dwTest)==S_OK) qDebug("get_frontEndQFE: %d",_get_frontEndQFE(pSymbol));
    if(pSymbol->get_function(&bTest)==S_OK) qDebug("get_function: %d",_get_function(pSymbol));
    if(pSymbol->get_guid(&guidTest)==S_OK) qDebug("get_guid");
    if(pSymbol->get_hasAlloca(&bTest)==S_OK) qDebug("get_hasAlloca: %d",_get_hasAlloca(pSymbol));
    if(pSymbol->get_hasAssignmentOperator(&bTest)==S_OK) qDebug("get_hasAssignmentOperator: %d",_get_hasAssignmentOperator(pSymbol));
    if(pSymbol->get_hasCastOperator(&bTest)==S_OK) qDebug("get_hasCastOperator: %d",_get_hasCastOperator(pSymbol));
    if(pSymbol->get_hasControlFlowCheck(&bTest)==S_OK) qDebug("get_hasControlFlowCheck: %d",_get_hasControlFlowCheck(pSymbol));
    if(pSymbol->get_hasDebugInfo(&bTest)==S_OK) qDebug("get_hasDebugInfo: %d",_get_hasDebugInfo(pSymbol));
    if(pSymbol->get_hasEH(&bTest)==S_OK) qDebug("get_hasEH: %d",_get_hasEH(pSymbol));
    if(pSymbol->get_hasEHa(&bTest)==S_OK) qDebug("get_hasEHa: %d",_get_hasEHa(pSymbol));
    if(pSymbol->get_hasInlAsm(&bTest)==S_OK) qDebug("get_hasInlAsm: %d",_get_hasInlAsm(pSymbol));
    if(pSymbol->get_hasLongJump(&bTest)==S_OK) qDebug("get_hasLongJump: %d",_get_hasLongJump(pSymbol));
    if(pSymbol->get_hasManagedCode(&bTest)==S_OK) qDebug("get_hasManagedCode: %d",_get_hasManagedCode(pSymbol));
    if(pSymbol->get_hasNestedTypes(&bTest)==S_OK) qDebug("get_hasNestedTypes: %d",_get_hasNestedTypes(pSymbol));
    if(pSymbol->get_hasSEH(&bTest)==S_OK) qDebug("get_hasSEH: %d",_get_hasSEH(pSymbol));
    if(pSymbol->get_hasSecurityChecks(&bTest)==S_OK) qDebug("get_hasSecurityChecks: %d",_get_hasSecurityChecks(pSymbol));
    if(pSymbol->get_hasSetJump(&bTest)==S_OK) qDebug("get_hasSetJump: %d",_get_hasSetJump(pSymbol));
    if(pSymbol->get_hasValidPGOCounts(&bTest)==S_OK) qDebug("get_hasValidPGOCounts: %d",_get_hasValidPGOCounts(pSymbol));
    if(pSymbol->get_hfaDouble(&bTest)==S_OK) qDebug("get_hfaDouble: %d",_get_hfaDouble(pSymbol));
    if(pSymbol->get_hfaFloat(&bTest)==S_OK) qDebug("get_hfaFloat: %d",_get_hfaFloat(pSymbol));
    if(pSymbol->get_indirectVirtualBaseClass(&bTest)==S_OK) qDebug("get_indirectVirtualBaseClass: %d",_get_indirectVirtualBaseClass(pSymbol));
    if(pSymbol->get_inlSpec(&bTest)==S_OK) qDebug("get_inlSpec: %d",_get_inlSpec(pSymbol));
    if(pSymbol->get_interruptReturn(&bTest)==S_OK) qDebug("get_interruptReturn: %d",_get_interruptReturn(pSymbol));
    if(pSymbol->get_intrinsic(&bTest)==S_OK) qDebug("get_intrinsic: %d",_get_intrinsic(pSymbol));
    if(pSymbol->get_intro(&bTest)==S_OK) qDebug("get_intro: %d",_get_intro(pSymbol));
    if(pSymbol->get_isAcceleratorGroupSharedLocal(&bTest)==S_OK) qDebug("get_isAcceleratorGroupSharedLocal: %d",_get_isAcceleratorGroupSharedLocal(pSymbol));
    if(pSymbol->get_isAcceleratorPointerTagLiveRange(&bTest)==S_OK) qDebug("get_isAcceleratorPointerTagLiveRange: %d",_get_isAcceleratorPointerTagLiveRange(pSymbol));
    if(pSymbol->get_isAcceleratorStubFunction(&bTest)==S_OK) qDebug("get_isAcceleratorStubFunction: %d",_get_isAcceleratorStubFunction(pSymbol));
    if(pSymbol->get_isAggregated(&bTest)==S_OK) qDebug("get_isAggregated: %d",_get_isAggregated(pSymbol));
    if(pSymbol->get_isCTypes(&bTest)==S_OK) qDebug("get_isCTypes: %d",_get_isCTypes(pSymbol));
    if(pSymbol->get_isCVTCIL(&bTest)==S_OK) qDebug("get_isCVTCIL: %d",_get_isCVTCIL(pSymbol));
    if(pSymbol->get_isConstructorVirtualBase(&bTest)==S_OK) qDebug("get_isConstructorVirtualBase: %d",_get_isConstructorVirtualBase(pSymbol));
    if(pSymbol->get_isCxxReturnUdt(&bTest)==S_OK) qDebug("get_isCxxReturnUdt: %d",_get_isCxxReturnUdt(pSymbol));
    if(pSymbol->get_isDataAligned(&bTest)==S_OK) qDebug("get_isDataAligned: %d",_get_isDataAligned(pSymbol));
    if(pSymbol->get_isHLSLData(&bTest)==S_OK) qDebug("get_isHLSLData: %d",_get_isHLSLData(pSymbol));
    if(pSymbol->get_isHotpatchable(&bTest)==S_OK) qDebug("get_isHotpatchable: %d",_get_isHotpatchable(pSymbol));
    if(pSymbol->get_isInterfaceUdt(&bTest)==S_OK) qDebug("get_isInterfaceUdt: %d",_get_isInterfaceUdt(pSymbol));
    if(pSymbol->get_isLTCG(&bTest)==S_OK) qDebug("get_isLTCG: %d",_get_isLTCG(pSymbol));
    if(pSymbol->get_isLocationControlFlowDependent(&bTest)==S_OK) qDebug("get_isLocationControlFlowDependent: %d",_get_isLocationControlFlowDependent(pSymbol));
    if(pSymbol->get_isMSILNetmodule(&bTest)==S_OK) qDebug("get_isMSILNetmodule: %d",_get_isMSILNetmodule(pSymbol));
    if(pSymbol->get_isMatrixRowMajor(&bTest)==S_OK) qDebug("get_isMatrixRowMajor: %d",_get_isMatrixRowMajor(pSymbol));
    if(pSymbol->get_isMultipleInheritance(&bTest)==S_OK) qDebug("get_isMultipleInheritance: %d",_get_isMultipleInheritance(pSymbol));
    if(pSymbol->get_isNaked(&bTest)==S_OK) qDebug("get_isNaked: %d",_get_isNaked(pSymbol));
    if(pSymbol->get_isOptimizedAway(&bTest)==S_OK) qDebug("get_isOptimizedAway: %d",_get_isOptimizedAway(pSymbol));
    if(pSymbol->get_isOptimizedForSpeed(&bTest)==S_OK) qDebug("get_isOptimizedForSpeed: %d",_get_isOptimizedForSpeed(pSymbol));
    if(pSymbol->get_isPGO(&bTest)==S_OK) qDebug("get_isPGO: %d",_get_isPGO(pSymbol));
    if(pSymbol->get_isPointerBasedOnSymbolValue(&bTest)==S_OK) qDebug("get_isPointerBasedOnSymbolValue: %d",_get_isPointerBasedOnSymbolValue(pSymbol));
    if(pSymbol->get_isPointerToDataMember(&bTest)==S_OK) qDebug("get_isPointerToDataMember: %d",_get_isPointerToDataMember(pSymbol));
    if(pSymbol->get_isPointerToMemberFunction(&bTest)==S_OK) qDebug("get_isPointerToMemberFunction: %d",_get_isPointerToMemberFunction(pSymbol));
    if(pSymbol->get_isRefUdt(&bTest)==S_OK) qDebug("get_isRefUdt: %d",_get_isRefUdt(pSymbol));
    if(pSymbol->get_isReturnValue(&bTest)==S_OK) qDebug("get_isReturnValue: %d",_get_isReturnValue(pSymbol));
    if(pSymbol->get_isSafeBuffers(&bTest)==S_OK) qDebug("get_isSafeBuffers: %d",_get_isSafeBuffers(pSymbol));
    if(pSymbol->get_isSdl(&bTest)==S_OK) qDebug("get_isSdl: %d",_get_isSdl(pSymbol));
    if(pSymbol->get_isSingleInheritance(&bTest)==S_OK) qDebug("get_isSingleInheritance: %d",_get_isSingleInheritance(pSymbol));
    if(pSymbol->get_isSplitted(&bTest)==S_OK) qDebug("get_isSplitted: %d",_get_isSplitted(pSymbol));
    if(pSymbol->get_isStatic(&bTest)==S_OK) qDebug("get_isStatic: %d",_get_isStatic(pSymbol));
    if(pSymbol->get_isStripped(&bTest)==S_OK) qDebug("get_isStripped: %d",_get_isStripped(pSymbol));
    if(pSymbol->get_isValueUdt(&bTest)==S_OK) qDebug("get_isValueUdt: %d",_get_isValueUdt(pSymbol));
    if(pSymbol->get_isVirtualInheritance(&bTest)==S_OK) qDebug("get_isVirtualInheritance: %d",_get_isVirtualInheritance(pSymbol));
    if(pSymbol->get_isWinRTPointer(&bTest)==S_OK) qDebug("get_isWinRTPointer: %d",_get_isWinRTPointer(pSymbol));
    if(pSymbol->get_language(&dwTest)==S_OK) qDebug("get_language: %d",_get_language(pSymbol));
    if(pSymbol->get_length(&ullTest)==S_OK) qDebug("get_length");
    if(pSymbol->get_lexicalParent(&pSymbolTest)==S_OK) qDebug("get_lexicalParent");
    if(pSymbol->get_lexicalParentId(&dwTest)==S_OK) qDebug("get_lexicalParentId: %d",_get_lexicalParentId(pSymbol));
    if(pSymbol->get_libraryName(&strTest)==S_OK) qDebug("get_libraryName: %s",_get_libraryName(pSymbol).toLatin1().data());
    if(pSymbol->get_liveRangeLength(&ullTest)==S_OK) qDebug("get_liveRangeLength");
    if(pSymbol->get_liveRangeStartAddressOffset(&dwTest)==S_OK) qDebug("get_liveRangeStartAddressOffset: %d",_get_liveRangeStartAddressOffset(pSymbol));
    if(pSymbol->get_liveRangeStartAddressSection(&dwTest)==S_OK) qDebug("get_liveRangeStartAddressSection: %d",_get_liveRangeStartAddressSection(pSymbol));
    if(pSymbol->get_liveRangeStartRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_liveRangeStartRelativeVirtualAddress: %d",_get_liveRangeStartRelativeVirtualAddress(pSymbol));
    if(pSymbol->get_localBasePointerRegisterId(&dwTest)==S_OK) qDebug("get_localBasePointerRegisterId: %d",_get_localBasePointerRegisterId(pSymbol));
    if(pSymbol->get_locationType(&dwTest)==S_OK) qDebug("get_locationType: %d",_get_locationType(pSymbol));
    if(pSymbol->get_lowerBound(&pSymbolTest)==S_OK) qDebug("get_lowerBound");
    if(pSymbol->get_lowerBoundId(&dwTest)==S_OK) qDebug("get_lowerBoundId: %d",_get_lowerBoundId(pSymbol));
    if(pSymbol->get_machineType(&dwTest)==S_OK) qDebug("get_machineType: %d",_get_machineType(pSymbol));
    if(pSymbol->get_managed(&bTest)==S_OK) qDebug("get_managed: %d",_get_managed(pSymbol));
    if(pSymbol->get_memorySpaceKind(&dwTest)==S_OK) qDebug("get_memorySpaceKind: %d",_get_memorySpaceKind(pSymbol));
    if(pSymbol->get_modifierValues(0,&dwTest,wData)==S_OK) qDebug("get_modifierValues");
    if(pSymbol->get_msil(&bTest)==S_OK) qDebug("get_msil: %d",_get_msil(pSymbol));
    if(pSymbol->get_name(&strTest)==S_OK) qDebug("get_name: %s",_get_name(pSymbol).toLatin1().data());
    if(pSymbol->get_nested(&bTest)==S_OK) qDebug("get_nested: %d",_get_nested(pSymbol));
    if(pSymbol->get_noInline(&bTest)==S_OK) qDebug("get_noInline: %d",_get_noInline(pSymbol));
    if(pSymbol->get_noNameExport(&bTest)==S_OK) qDebug("get_noNameExport: %d",_get_noNameExport(pSymbol));
    if(pSymbol->get_noReturn(&bTest)==S_OK) qDebug("get_noReturn: %d",_get_noReturn(pSymbol));
    if(pSymbol->get_noStackOrdering(&bTest)==S_OK) qDebug("get_noStackOrdering: %d",_get_noStackOrdering(pSymbol));
    if(pSymbol->get_notReached(&bTest)==S_OK) qDebug("get_notReached: %d",_get_notReached(pSymbol));
    if(pSymbol->get_numberOfAcceleratorPointerTags(&dwTest)==S_OK) qDebug("get_numberOfAcceleratorPointerTags: %d",_get_numberOfAcceleratorPointerTags(pSymbol));
    if(pSymbol->get_numberOfColumns(&dwTest)==S_OK) qDebug("get_numberOfColumns: %d",_get_numberOfColumns(pSymbol));
    if(pSymbol->get_numberOfModifiers(&dwTest)==S_OK) qDebug("get_numberOfModifiers: %d",_get_numberOfModifiers(pSymbol));
    if(pSymbol->get_numberOfRegisterIndices(&dwTest)==S_OK) qDebug("get_numberOfRegisterIndices: %d",_get_numberOfRegisterIndices(pSymbol));
    if(pSymbol->get_numberOfRows(&dwTest)==S_OK) qDebug("get_numberOfRows: %d",_get_numberOfRows(pSymbol));
    if(pSymbol->get_numericProperties(0,&dwTest,dwData)==S_OK) qDebug("get_numericProperties");
    if(pSymbol->get_objectFileName(&strTest)==S_OK) qDebug("get_objectFileName: %s",_get_objectFileName(pSymbol).toLatin1().data());
    if(pSymbol->get_objectPointerType(&pSymbolTest)==S_OK) qDebug("get_objectPointerType");
    if(pSymbol->get_oemId(&dwTest)==S_OK) qDebug("get_oemId: %d",_get_oemId(pSymbol));
    if(pSymbol->get_oemSymbolId(&dwTest)==S_OK) qDebug("get_oemSymbolId: %d",_get_oemSymbolId(pSymbol));
    if(pSymbol->get_offset(&lTest)==S_OK) qDebug("get_offset");
    if(pSymbol->get_offsetInUdt(&dwTest)==S_OK) qDebug("get_offsetInUdt: %d",_get_offsetInUdt(pSymbol));
    if(pSymbol->get_optimizedCodeDebugInfo(&bTest)==S_OK) qDebug("get_optimizedCodeDebugInfo: %d",_get_optimizedCodeDebugInfo(pSymbol));
    if(pSymbol->get_ordinal(&dwTest)==S_OK) qDebug("get_ordinal: %d",_get_ordinal(pSymbol));
    if(pSymbol->get_overloadedOperator(&bTest)==S_OK) qDebug("get_overloadedOperator: %d",_get_overloadedOperator(pSymbol));
    if(pSymbol->get_packed(&bTest)==S_OK) qDebug("get_packed: %d",_get_packed(pSymbol));
    if(pSymbol->get_paramBasePointerRegisterId(&dwTest)==S_OK) qDebug("get_paramBasePointerRegisterId: %d",_get_paramBasePointerRegisterId(pSymbol));
    if(pSymbol->get_phaseName(&strTest)==S_OK) qDebug("get_phaseName: %s",_get_phaseName(pSymbol).toLatin1().data());
    if(pSymbol->get_platform(&dwTest)==S_OK) qDebug("get_platform: %d",_get_platform(pSymbol));
    if(pSymbol->get_privateExport(&bTest)==S_OK) qDebug("get_privateExport: %d",_get_privateExport(pSymbol));
    if(pSymbol->get_pure(&bTest)==S_OK) qDebug("get_pure: %d",_get_pure(pSymbol));
    if(pSymbol->get_rank(&dwTest)==S_OK) qDebug("get_rank: %d",_get_rank(pSymbol));
    if(pSymbol->get_reference(&bTest)==S_OK) qDebug("get_reference: %d",_get_reference(pSymbol));
    if(pSymbol->get_registerId(&dwTest)==S_OK) qDebug("get_registerId: %d",_get_registerId(pSymbol));
    if(pSymbol->get_registerType(&dwTest)==S_OK) qDebug("get_registerType: %d",_get_registerType(pSymbol));
    if(pSymbol->get_relativeVirtualAddress(&dwTest)==S_OK) qDebug("get_relativeVirtualAddress: %d",_get_relativeVirtualAddress(pSymbol));
    if(pSymbol->get_restrictedType(&bTest)==S_OK) qDebug("get_restrictedType: %d",_get_restrictedType(pSymbol));
    if(pSymbol->get_samplerSlot(&dwTest)==S_OK) qDebug("get_samplerSlot: %d",_get_samplerSlot(pSymbol));
    if(pSymbol->get_scoped(&bTest)==S_OK) qDebug("get_scoped: %d",_get_scoped(pSymbol));
    if(pSymbol->get_sealed(&bTest)==S_OK) qDebug("get_sealed: %d",_get_sealed(pSymbol));
    if(pSymbol->get_signature(&dwTest)==S_OK) qDebug("get_signature: %d",_get_signature(pSymbol));
    if(pSymbol->get_sizeInUdt(&dwTest)==S_OK) qDebug("get_sizeInUdt: %d",_get_sizeInUdt(pSymbol));
    if(pSymbol->get_slot(&dwTest)==S_OK) qDebug("get_slot: %d",_get_slot(pSymbol));
    if(pSymbol->get_sourceFileName(&strTest)==S_OK) qDebug("get_sourceFileName: %s",_get_sourceFileName(pSymbol).toLatin1().data());
    if(pSymbol->get_staticSize(&dwTest)==S_OK) qDebug("get_staticSize: %d",_get_staticSize(pSymbol));
    if(pSymbol->get_strictGSCheck(&bTest)==S_OK) qDebug("get_strictGSCheck: %d",_get_strictGSCheck(pSymbol));
    if(pSymbol->get_stride(&dwTest)==S_OK) qDebug("get_stride: %d",_get_stride(pSymbol));
    if(pSymbol->get_subType(&pSymbolTest)==S_OK) qDebug("get_subType");
    if(pSymbol->get_subTypeId(&dwTest)==S_OK) qDebug("get_subTypeId: %d",_get_subTypeId(pSymbol));
    if(pSymbol->get_symIndexId(&dwTest)==S_OK) qDebug("get_symIndexId: %d",_get_symIndexId(pSymbol));
    if(pSymbol->get_symTag(&dwTest)==S_OK) qDebug("get_symTag: %d",_get_symTag(pSymbol));
    if(pSymbol->get_symbolsFileName(&strTest)==S_OK) qDebug("get_symbolsFileName: %s",_get_symbolsFileName(pSymbol).toLatin1().data());
    if(pSymbol->get_targetOffset(&dwTest)==S_OK) qDebug("get_targetOffset: %d",_get_targetOffset(pSymbol));
    if(pSymbol->get_targetRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_targetRelativeVirtualAddress: %d",_get_targetRelativeVirtualAddress(pSymbol));
    if(pSymbol->get_targetSection(&dwTest)==S_OK) qDebug("get_targetSection: %d",_get_targetSection(pSymbol));
    if(pSymbol->get_targetVirtualAddress(&ullTest)==S_OK) qDebug("get_targetVirtualAddress");
    if(pSymbol->get_textureSlot(&dwTest)==S_OK) qDebug("get_textureSlot: %d",_get_textureSlot(pSymbol));
    if(pSymbol->get_thisAdjust(&lTest)==S_OK) qDebug("get_thisAdjust");
    if(pSymbol->get_thunkOrdinal(&dwTest)==S_OK) qDebug("get_thunkOrdinal: %d",_get_thunkOrdinal(pSymbol));
    if(pSymbol->get_timeStamp(&dwTest)==S_OK) qDebug("get_timeStamp: %d",_get_timeStamp(pSymbol));
    if(pSymbol->get_token(&dwTest)==S_OK) qDebug("get_token: %d",_get_token(pSymbol));
    if(pSymbol->get_type(&pSymbolTest)==S_OK) qDebug("get_type");
    if(pSymbol->get_typeId(&dwTest)==S_OK) qDebug("get_typeId: %d",_get_typeId(pSymbol));
    if(pSymbol->get_typeIds(0,&dwTest,dwData)==S_OK) qDebug("get_typeIds");
    if(pSymbol->get_types(0,&dwTest,&pSymbolTest)==S_OK) qDebug("get_types");
    if(pSymbol->get_uavSlot(&dwTest)==S_OK) qDebug("get_uavSlot: %d",_get_uavSlot(pSymbol));
    if(pSymbol->get_udtKind(&dwTest)==S_OK) qDebug("get_udtKind: %d",_get_udtKind(pSymbol));
    if(pSymbol->get_unalignedType(&bTest)==S_OK) qDebug("get_unalignedType: %d",_get_unalignedType(pSymbol));
    if(pSymbol->get_undecoratedName(&strTest)==S_OK) qDebug("get_undecoratedName: %s",_get_undecoratedName(pSymbol).toLatin1().data());
    if(pSymbol->get_undecoratedNameEx(0,&strTest)==S_OK) qDebug("get_undecoratedNameEx: %s",_get_undecoratedNameEx(pSymbol).toLatin1().data());
    if(pSymbol->get_unmodifiedType(&pSymbolTest)==S_OK) qDebug("get_unmodifiedType");
    if(pSymbol->get_unmodifiedTypeId(&dwTest)==S_OK) qDebug("get_unmodifiedTypeId: %d",_get_unmodifiedTypeId(pSymbol));
    if(pSymbol->get_unused(&strTest)==S_OK) qDebug("get_unused: %s",_get_unused(pSymbol).toLatin1().data());
    if(pSymbol->get_upperBound(&pSymbolTest)==S_OK) qDebug("get_upperBound");
    if(pSymbol->get_upperBoundId(&dwTest)==S_OK) qDebug("get_upperBoundId: %d",_get_upperBoundId(pSymbol));
    if(pSymbol->get_value(&varTest)==S_OK) qDebug("get_value");
    if(pSymbol->get_virtual(&bTest)==S_OK) qDebug("get_virtual: %d",_get_virtual(pSymbol));
    if(pSymbol->get_virtualAddress(&ullTest)==S_OK) qDebug("get_virtualAddress");
    if(pSymbol->get_virtualBaseClass(&bTest)==S_OK) qDebug("get_virtualBaseClass: %d",_get_virtualBaseClass(pSymbol));
    if(pSymbol->get_virtualBaseDispIndex(&dwTest)==S_OK) qDebug("get_virtualBaseDispIndex: %d",_get_virtualBaseDispIndex(pSymbol));
    if(pSymbol->get_virtualBaseOffset(&dwTest)==S_OK) qDebug("get_virtualBaseOffset: %d",_get_virtualBaseOffset(pSymbol));
    if(pSymbol->get_virtualBasePointerOffset(&lTest)==S_OK) qDebug("get_virtualBasePointerOffset");
    if(pSymbol->get_virtualBaseTableType(&pSymbolTest)==S_OK) qDebug("get_virtualBaseTableType");
    if(pSymbol->get_virtualTableShape(&pSymbolTest)==S_OK) qDebug("get_virtualTableShape");
    if(pSymbol->get_virtualTableShapeId(&dwTest)==S_OK) qDebug("get_virtualTableShapeId: %d",_get_virtualTableShapeId(pSymbol));
    if(pSymbol->get_volatileType(&bTest)==S_OK) qDebug("get_volatileType: %d",_get_volatileType(pSymbol));
    if(pSymbol->get_wasInlined(&bTest)==S_OK) qDebug("get_wasInlined: %d",_get_wasInlined(pSymbol));
//    if(pSymbol->findChildren(&bTest)==S_OK) qDebug("findChildren");
//    if(pSymbol->findChildrenEx(&bTest)==S_OK) qDebug("findChildrenEx");
//    if(pSymbol->findChildrenExByAddr(&bTest)==S_OK) qDebug("findChildrenExByAddr");
//    if(pSymbol->findChildrenExByRVA(&bTest)==S_OK) qDebug("findChildrenExByRVA");
//    if(pSymbol->findChildrenExByVA(&bTest)==S_OK) qDebug("findChildrenExByVA");
//    if(pSymbol->findInlineFramesByAddr(&bTest)==S_OK) qDebug("findInlineFramesByAddr");
//    if(pSymbol->findInlineFramesByRVA(&bTest)==S_OK) qDebug("findInlineFramesByRVA");
//    if(pSymbol->findInlineFramesByVA(&bTest)==S_OK) qDebug("findInlineFramesByVA");
//    if(pSymbol->findInlineeLines(&bTest)==S_OK) qDebug("findInlineeLines");
//    if(pSymbol->findInlineeLinesByAddr(&bTest)==S_OK) qDebug("findInlineeLinesByAddr");
//    if(pSymbol->findInlineeLinesByRVA(&bTest)==S_OK) qDebug("findInlineeLinesByRVA");
//    if(pSymbol->findInlineeLinesByVA(&bTest)==S_OK) qDebug("findInlineeLinesByVA");
//    if(pSymbol->findSymbolsByRVAForAcceleratorPointerTag(&bTest)==S_OK) qDebug("findSymbolsByRVAForAcceleratorPointerTag");
//    if(pSymbol->findSymbolsForAcceleratorPointerTag(&bTest)==S_OK) qDebug("findSymbolsForAcceleratorPointerTag");
//    if(pSymbol->getSrcLineOnTypeDefn(&bTest)==S_OK) qDebug("getSrcLineOnTypeDefn");
//    if(pSymbol->get_acceleratorPointerTags(&bTest)==S_OK) qDebug("get_acceleratorPointerTags");

    qDebug("Number of Children: %d",getNumberOfChildren(pSymbol));
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::getNumberOfChildren(IDiaSymbol *pSymbol)
{
    quint32 nResult=0;

    IDiaEnumSymbols *pEnumSymbols;
    if(pSymbol->findChildren(SymTagNull,nullptr,nsNone,&pEnumSymbols)==S_OK)
    {
        LONG nCount=0;

        if(pEnumSymbols->get_Count(&nCount)==S_OK)
        {
            nResult=nCount;
        }

        pEnumSymbols->Release();
    }

    return nResult;
}
#endif
