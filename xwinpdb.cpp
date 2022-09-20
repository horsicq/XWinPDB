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

void XWinPDB::test()
{
#ifdef Q_OS_WIN
    QString sCompilerName=_get_compilerName(g_pGlobal);
    QString sName=_get_name(g_pGlobal);
#endif
}
#ifdef Q_OS_WIN
void XWinPDB::_testSymbol(IDiaSymbol *pSymbol)
{
    DWORD dwTest=0;
    ULONGLONG ullTest=0;
    BSTR strTest;
    BOOL bTest=0;

    if(pSymbol->get_symIndexId(&dwTest)==S_OK) qDebug("get_symIndexId");
    if(pSymbol->get_symTag(&dwTest)==S_OK) qDebug("get_symTag");
    if(pSymbol->get_name(&strTest)==S_OK) qDebug("get_name");
    if(pSymbol->get_lexicalParent(&bTest)==S_OK) qDebug("get_lexicalParent");
    if(pSymbol->get_classParent(&bTest)==S_OK) qDebug("get_classParent");
    if(pSymbol->get_type(&bTest)==S_OK) qDebug("get_type");
    if(pSymbol->get_dataKind(&dwTest)==S_OK) qDebug("get_dataKind");
    if(pSymbol->get_locationType(&dwTest)==S_OK) qDebug("get_locationType");
    if(pSymbol->get_addressSection(&dwTest)==S_OK) qDebug("get_addressSection");
    if(pSymbol->get_addressOffset(&dwTest)==S_OK) qDebug("get_addressOffset");
    if(pSymbol->get_relativeVirtualAddress(&dwTest)==S_OK) qDebug("get_relativeVirtualAddress");
    if(pSymbol->get_virtualAddress(&ullTest)==S_OK) qDebug("get_virtualAddress");
    if(pSymbol->get_registerId(&dwTest)==S_OK) qDebug("get_registerId");
    if(pSymbol->get_offset(&bTest)==S_OK) qDebug("get_offset");
    if(pSymbol->get_length(&ullTest)==S_OK) qDebug("get_length");
    if(pSymbol->get_slot(&dwTest)==S_OK) qDebug("get_slot");
    if(pSymbol->get_volatileType(&bTest)==S_OK) qDebug("get_volatileType");
    if(pSymbol->get_constType(&bTest)==S_OK) qDebug("get_constType");
    if(pSymbol->get_unalignedType(&bTest)==S_OK) qDebug("get_unalignedType");
    if(pSymbol->get_access(&dwTest)==S_OK) qDebug("get_access");
    if(pSymbol->get_libraryName(&bTest)==S_OK) qDebug("get_libraryName");
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
    if(pSymbol->get_thisAdjust(&bTest)==S_OK) qDebug("get_thisAdjust");
    if(pSymbol->get_virtualBaseOffset(&bTest)==S_OK) qDebug("get_virtualBaseOffset");
    if(pSymbol->get_virtual(&bTest)==S_OK) qDebug("get_virtual");
    if(pSymbol->get_intro(&bTest)==S_OK) qDebug("get_intro");
    if(pSymbol->get_pure(&bTest)==S_OK) qDebug("get_pure");
    if(pSymbol->get_callingConvention(&dwTest)==S_OK) qDebug("get_callingConvention");
    if(pSymbol->get_value(&bTest)==S_OK) qDebug("get_value");
    if(pSymbol->get_baseType(&dwTest)==S_OK) qDebug("get_baseType");
    if(pSymbol->get_token(&dwTest)==S_OK) qDebug("get_token");
    if(pSymbol->get_timeStamp(&dwTest)==S_OK) qDebug("get_timeStamp");
    if(pSymbol->get_guid(&bTest)==S_OK) qDebug("get_guid");
    if(pSymbol->get_symbolsFileName(&strTest)==S_OK) qDebug("get_symbolsFileName");
    if(pSymbol->get_reference(&bTest)==S_OK) qDebug("get_reference");
    if(pSymbol->get_count(&dwTest)==S_OK) qDebug("get_count");
    if(pSymbol->get_bitPosition(&dwTest)==S_OK) qDebug("get_bitPosition");
    if(pSymbol->get_arrayIndexType(&bTest)==S_OK) qDebug("get_arrayIndexType");
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
    if(pSymbol->get_virtualBasePointerOffset(&bTest)==S_OK) qDebug("get_virtualBasePointerOffset");
    if(pSymbol->get_virtualTableShape(&bTest)==S_OK) qDebug("get_virtualTableShape");
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
    if(pSymbol->get_lowerBound(&bTest)==S_OK) qDebug("get_lowerBound");
    if(pSymbol->get_upperBound(&bTest)==S_OK) qDebug("get_upperBound");
    if(pSymbol->get_lowerBoundId(&dwTest)==S_OK) qDebug("get_lowerBoundId");
    if(pSymbol->get_upperBoundId(&dwTest)==S_OK) qDebug("get_upperBoundId");
    if(pSymbol->get_dataBytes(&bTest)==S_OK) qDebug("get_dataBytes");
    if(pSymbol->findChildren(&bTest)==S_OK) qDebug("findChildren");
    if(pSymbol->findChildrenEx(&bTest)==S_OK) qDebug("findChildrenEx");
    if(pSymbol->findChildrenExByAddr(&bTest)==S_OK) qDebug("findChildrenExByAddr");
    if(pSymbol->findChildrenExByVA(&bTest)==S_OK) qDebug("findChildrenExByVA");
    if(pSymbol->findChildrenExByRVA(&bTest)==S_OK) qDebug("findChildrenExByRVA");
    if(pSymbol->get_targetSection(&dwTest)==S_OK) qDebug("get_targetSection");
    if(pSymbol->get_targetOffset(&dwTest)==S_OK) qDebug("get_targetOffset");
    if(pSymbol->get_targetRelativeVirtualAddress(&dwTest)==S_OK) qDebug("get_targetRelativeVirtualAddress");
    if(pSymbol->get_targetVirtualAddress(&ullTest)==S_OK) qDebug("get_targetVirtualAddress");
    if(pSymbol->get_machineType(&dwTest)==S_OK) qDebug("get_machineType");
    if(pSymbol->get_oemId(&dwTest)==S_OK) qDebug("get_oemId");
    if(pSymbol->get_oemSymbolId(&dwTest)==S_OK) qDebug("get_oemSymbolId");
    if(pSymbol->get_types(&bTest)==S_OK) qDebug("get_types");
    if(pSymbol->get_typeIds(&bTest)==S_OK) qDebug("get_typeIds");
    if(pSymbol->get_objectPointerType(&bTest)==S_OK) qDebug("get_objectPointerType");
    if(pSymbol->get_udtKind(&dwTest)==S_OK) qDebug("get_udtKind");
    if(pSymbol->get_undecoratedNameEx(&bTest)==S_OK) qDebug("get_undecoratedNameEx");
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
    if(pSymbol->get_container(&bTest)==S_OK) qDebug("get_container");
    if(pSymbol->get_inlSpec(&bTest)==S_OK) qDebug("get_inlSpec");
    if(pSymbol->get_noStackOrdering(&bTest)==S_OK) qDebug("get_noStackOrdering");
    if(pSymbol->get_virtualBaseTableType(&bTest)==S_OK) qDebug("get_virtualBaseTableType");
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
    if(pSymbol->get_unmodifiedType(&bTest)==S_OK) qDebug("get_unmodifiedType");
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
    if(pSymbol->get_liveRangeLength(&bTest)==S_OK) qDebug("get_liveRangeLength");
    if(pSymbol->get_offsetInUdt(&dwTest)==S_OK) qDebug("get_offsetInUdt");
    if(pSymbol->get_paramBasePointerRegisterId(&dwTest)==S_OK) qDebug("get_paramBasePointerRegisterId");
    if(pSymbol->get_localBasePointerRegisterId(&dwTest)==S_OK) qDebug("get_localBasePointerRegisterId");
    if(pSymbol->get_isLocationControlFlowDependent(&bTest)==S_OK) qDebug("get_isLocationControlFlowDependent");
    if(pSymbol->get_stride(&dwTest)==S_OK) qDebug("get_stride");
    if(pSymbol->get_numberOfRows(&dwTest)==S_OK) qDebug("get_numberOfRows");
    if(pSymbol->get_numberOfColumns(&dwTest)==S_OK) qDebug("get_numberOfColumns");
    if(pSymbol->get_isMatrixRowMajor(&bTest)==S_OK) qDebug("get_isMatrixRowMajor");
    if(pSymbol->get_numericProperties(&bTest)==S_OK) qDebug("get_numericProperties");
    if(pSymbol->get_modifierValues(&bTest)==S_OK) qDebug("get_modifierValues");
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
    if(pSymbol->get_subType(&bTest)==S_OK) qDebug("get_subType");
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
    if(pSymbol->get_baseSymbol(&bTest)==S_OK) qDebug("get_baseSymbol");
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
    if(pSymbol->findInlineFramesByAddr(&bTest)==S_OK) qDebug("findInlineFramesByAddr");
    if(pSymbol->findInlineFramesByRVA(&bTest)==S_OK) qDebug("findInlineFramesByRVA");
    if(pSymbol->findInlineFramesByVA(&bTest)==S_OK) qDebug("findInlineFramesByVA");
    if(pSymbol->findInlineeLines(&bTest)==S_OK) qDebug("findInlineeLines");
    if(pSymbol->findInlineeLinesByAddr(&bTest)==S_OK) qDebug("findInlineeLinesByAddr");
    if(pSymbol->findInlineeLinesByRVA(&bTest)==S_OK) qDebug("findInlineeLinesByRVA");
    if(pSymbol->findInlineeLinesByVA(&bTest)==S_OK) qDebug("findInlineeLinesByVA");
    if(pSymbol->findSymbolsForAcceleratorPointerTag(&bTest)==S_OK) qDebug("findSymbolsForAcceleratorPointerTag");
    if(pSymbol->findSymbolsByRVAForAcceleratorPointerTag(&bTest)==S_OK) qDebug("findSymbolsByRVAForAcceleratorPointerTag");
    if(pSymbol->get_acceleratorPointerTags(&bTest)==S_OK) qDebug("get_acceleratorPointerTags");
    if(pSymbol->getSrcLineOnTypeDefn(&bTest)==S_OK) qDebug("getSrcLineOnTypeDefn");
    if(pSymbol->get_isPGO(&bTest)==S_OK) qDebug("get_isPGO");
    if(pSymbol->get_hasValidPGOCounts(&bTest)==S_OK) qDebug("get_hasValidPGOCounts");
    if(pSymbol->get_isOptimizedForSpeed(&bTest)==S_OK) qDebug("get_isOptimizedForSpeed");
    if(pSymbol->get_PGOEntryCount(&dwTest)==S_OK) qDebug("get_PGOEntryCount");
    if(pSymbol->get_PGOEdgeCount(&dwTest)==S_OK) qDebug("get_PGOEdgeCount");
    if(pSymbol->get_PGODynamicInstructionCount(&bTest)==S_OK) qDebug("get_PGODynamicInstructionCount");
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
    if(pSymbol->findInputAssemblyFile(&bTest)==S_OK) qDebug("findInputAssemblyFile");
    if(pSymbol->get_characteristics(&dwTest)==S_OK) qDebug("get_characteristics");
    if(pSymbol->get_coffGroup(&bTest)==S_OK) qDebug("get_coffGroup");
    if(pSymbol->get_bindID(&dwTest)==S_OK) qDebug("get_bindID");
    if(pSymbol->get_bindSpace(&dwTest)==S_OK) qDebug("get_bindSpace");
    if(pSymbol->get_bindSlot(&dwTest)==S_OK) qDebug("get_bindSlot");
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
