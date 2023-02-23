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
#define X_PDB_FUNCTION_DWORD(func_name, pdb_name) \
    quint32 func_name(IDiaSymbol *pSymbol)        \
    {                                             \
        quint32 nResult = 0;                      \
        DWORD dwTemp = 0;                         \
        if (pSymbol->pdb_name(&dwTemp) == S_OK) { \
            nResult = dwTemp;                     \
        }                                         \
        return nResult;                           \
    }

X_PDB_FUNCTION_DWORD(_pdb_sym_get_symIndexId, get_symIndexId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_symTag, get_symTag)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_age, get_age)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_signature, get_signature)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_machineType, get_machineType)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_lexicalParentId, get_lexicalParentId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_PGOEdgeCount, get_PGOEdgeCount)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_PGOEntryCount, get_PGOEntryCount)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_access, get_access)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_addressOffset, get_addressOffset)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_addressSection, get_addressSection)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_arrayIndexTypeId, get_arrayIndexTypeId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_backEndBuild, get_backEndBuild)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_backEndMajor, get_backEndMajor)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_backEndMinor, get_backEndMinor)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_backEndQFE, get_backEndQFE)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_baseDataOffset, get_baseDataOffset)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_baseDataSlot, get_baseDataSlot)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_baseSymbolId, get_baseSymbolId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_baseType, get_baseType)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_bindID, get_bindID)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_bindSlot, get_bindSlot)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_bindSpace, get_bindSpace)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_bitPosition, get_bitPosition)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_builtInKind, get_builtInKind)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_callingConvention, get_callingConvention)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_characteristics, get_characteristics)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_classParentId, get_classParentId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_count, get_count)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_countLiveRanges, get_countLiveRanges)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_dataKind, get_dataKind)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_exceptionHandlerAddressOffset, get_exceptionHandlerAddressOffset)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_exceptionHandlerAddressSection, get_exceptionHandlerAddressSection)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_exceptionHandlerRelativeVirtualAddress, get_exceptionHandlerRelativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_finalLiveStaticSize, get_finalLiveStaticSize)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_frameSize, get_frameSize)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_frontEndBuild, get_frontEndBuild)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_frontEndMajor, get_frontEndMajor)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_frontEndMinor, get_frontEndMinor)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_frontEndQFE, get_frontEndQFE)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_language, get_language)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_liveRangeStartAddressOffset, get_liveRangeStartAddressOffset)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_liveRangeStartAddressSection, get_liveRangeStartAddressSection)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_liveRangeStartRelativeVirtualAddress, get_liveRangeStartRelativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_localBasePointerRegisterId, get_localBasePointerRegisterId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_locationType, get_locationType)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_lowerBoundId, get_lowerBoundId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_memorySpaceKind, get_memorySpaceKind)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_numberOfAcceleratorPointerTags, get_numberOfAcceleratorPointerTags)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_numberOfColumns, get_numberOfColumns)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_numberOfModifiers, get_numberOfModifiers)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_numberOfRegisterIndices, get_numberOfRegisterIndices)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_numberOfRows, get_numberOfRows)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_oemId, get_oemId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_oemSymbolId, get_oemSymbolId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_offsetInUdt, get_offsetInUdt)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_ordinal, get_ordinal)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_paramBasePointerRegisterId, get_paramBasePointerRegisterId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_platform, get_platform)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_rank, get_rank)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_registerId, get_registerId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_registerType, get_registerType)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_relativeVirtualAddress, get_relativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_samplerSlot, get_samplerSlot)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_sizeInUdt, get_sizeInUdt)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_slot, get_slot)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_staticSize, get_staticSize)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_stride, get_stride)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_subTypeId, get_subTypeId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_targetOffset, get_targetOffset)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_targetRelativeVirtualAddress, get_targetRelativeVirtualAddress)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_targetSection, get_targetSection)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_textureSlot, get_textureSlot)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_thunkOrdinal, get_thunkOrdinal)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_timeStamp, get_timeStamp)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_token, get_token)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_typeId, get_typeId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_uavSlot, get_uavSlot)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_udtKind, get_udtKind)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_unmodifiedTypeId, get_unmodifiedTypeId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_upperBoundId, get_upperBoundId)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_virtualBaseDispIndex, get_virtualBaseDispIndex)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_virtualBaseOffset, get_virtualBaseOffset)
X_PDB_FUNCTION_DWORD(_pdb_sym_get_virtualTableShapeId, get_virtualTableShapeId)

#define X_PDB_FUNCTION_BOOL(func_name, pdb_name) \
    bool func_name(IDiaSymbol *pSymbol)          \
    {                                            \
        bool bResult = false;                    \
        BOOL bTemp = 0;                          \
        if (pSymbol->pdb_name(&bTemp) == S_OK) { \
            bResult = bTemp;                     \
        }                                        \
        return bResult;                          \
    }

X_PDB_FUNCTION_BOOL(_pdb_sym_get_isCTypes, get_isCTypes)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isStripped, get_isStripped)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_RValueReference, get_RValueReference)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_addressTaken, get_addressTaken)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_code, get_code)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_compilerGenerated, get_compilerGenerated)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_constType, get_constType)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_constantExport, get_constantExport)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_constructor, get_constructor)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_customCallingConvention, get_customCallingConvention)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_dataExport, get_dataExport)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_editAndContinueEnabled, get_editAndContinueEnabled)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_exportIsForwarder, get_exportIsForwarder)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_farReturn, get_farReturn)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_framePointerPresent, get_framePointerPresent)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_function, get_function)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasAlloca, get_hasAlloca)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasAssignmentOperator, get_hasAssignmentOperator)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasCastOperator, get_hasCastOperator)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasControlFlowCheck, get_hasControlFlowCheck)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasDebugInfo, get_hasDebugInfo)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasEH, get_hasEH)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasEHa, get_hasEHa)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasInlAsm, get_hasInlAsm)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasLongJump, get_hasLongJump)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasManagedCode, get_hasManagedCode)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasNestedTypes, get_hasNestedTypes)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasSEH, get_hasSEH)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasSecurityChecks, get_hasSecurityChecks)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasSetJump, get_hasSetJump)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hasValidPGOCounts, get_hasValidPGOCounts)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hfaDouble, get_hfaDouble)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_hfaFloat, get_hfaFloat)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_indirectVirtualBaseClass, get_indirectVirtualBaseClass)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_inlSpec, get_inlSpec)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_interruptReturn, get_interruptReturn)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_intrinsic, get_intrinsic)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_intro, get_intro)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isAcceleratorGroupSharedLocal, get_isAcceleratorGroupSharedLocal)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isAcceleratorPointerTagLiveRange, get_isAcceleratorPointerTagLiveRange)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isAcceleratorStubFunction, get_isAcceleratorStubFunction)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isAggregated, get_isAggregated)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isCVTCIL, get_isCVTCIL)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isConstructorVirtualBase, get_isConstructorVirtualBase)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isCxxReturnUdt, get_isCxxReturnUdt)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isDataAligned, get_isDataAligned)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isHLSLData, get_isHLSLData)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isHotpatchable, get_isHotpatchable)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isInterfaceUdt, get_isInterfaceUdt)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_exportHasExplicitlyAssignedOrdinal, get_exportHasExplicitlyAssignedOrdinal)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isLocationControlFlowDependent, get_isLocationControlFlowDependent)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isMSILNetmodule, get_isMSILNetmodule)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isMatrixRowMajor, get_isMatrixRowMajor)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isMultipleInheritance, get_isMultipleInheritance)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isNaked, get_isNaked)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isOptimizedAway, get_isOptimizedAway)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isOptimizedForSpeed, get_isOptimizedForSpeed)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isPGO, get_isPGO)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isPointerBasedOnSymbolValue, get_isPointerBasedOnSymbolValue)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isPointerToDataMember, get_isPointerToDataMember)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isPointerToMemberFunction, get_isPointerToMemberFunction)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isRefUdt, get_isRefUdt)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isReturnValue, get_isReturnValue)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isSafeBuffers, get_isSafeBuffers)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isSdl, get_isSdl)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isSingleInheritance, get_isSingleInheritance)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isSplitted, get_isSplitted)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isStatic, get_isStatic)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isValueUdt, get_isValueUdt)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isVirtualInheritance, get_isVirtualInheritance)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isWinRTPointer, get_isWinRTPointer)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_managed, get_managed)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_msil, get_msil)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_nested, get_nested)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_noInline, get_noInline)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_noNameExport, get_noNameExport)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_noReturn, get_noReturn)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_noStackOrdering, get_noStackOrdering)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_notReached, get_notReached)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_optimizedCodeDebugInfo, get_optimizedCodeDebugInfo)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_overloadedOperator, get_overloadedOperator)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_packed, get_packed)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_privateExport, get_privateExport)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_pure, get_pure)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_reference, get_reference)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_restrictedType, get_restrictedType)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_scoped, get_scoped)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_sealed, get_sealed)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_strictGSCheck, get_strictGSCheck)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_unalignedType, get_unalignedType)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_virtual, get_virtual)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_virtualBaseClass, get_virtualBaseClass)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_volatileType, get_volatileType)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_wasInlined, get_wasInlined)
X_PDB_FUNCTION_BOOL(_pdb_sym_get_isLTCG, get_isLTCG)

#define X_PDB_FUNCTION_BSTRING(func_name, pdb_name)     \
    QString func_name(IDiaSymbol *pSymbol)              \
    {                                                   \
        QString sResult;                                \
        BSTR bstring = nullptr;                         \
        if (pSymbol->pdb_name(&bstring) == S_OK) {      \
            sResult = QString::fromWCharArray(bstring); \
            SysFreeString(bstring);                     \
        }                                               \
        return sResult;                                 \
    }

X_PDB_FUNCTION_BSTRING(_pdb_sym_get_compilerName, get_compilerName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_libraryName, get_libraryName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_name, get_name)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_objectFileName, get_objectFileName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_phaseName, get_phaseName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_sourceFileName, get_sourceFileName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_symbolsFileName, get_symbolsFileName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_undecoratedName, get_undecoratedName)
X_PDB_FUNCTION_BSTRING(_pdb_sym_get_unused, get_unused)

#define X_PDB_FUNCTION_ULONGLONG(func_name, pdb_name) \
    quint64 func_name(IDiaSymbol *pSymbol)            \
    {                                                 \
        quint64 nResult = 0;                          \
        ULONGLONG llTemp = 0;                         \
        if (pSymbol->pdb_name(&llTemp) == S_OK) {     \
            nResult = llTemp;                         \
        }                                             \
        return nResult;                               \
    }

X_PDB_FUNCTION_ULONGLONG(_pdb_sym_get_PGODynamicInstructionCount, get_PGODynamicInstructionCount)
X_PDB_FUNCTION_ULONGLONG(_pdb_sym_get_exceptionHandlerVirtualAddress, get_exceptionHandlerVirtualAddress)
X_PDB_FUNCTION_ULONGLONG(_pdb_sym_get_length, get_length)
X_PDB_FUNCTION_ULONGLONG(_pdb_sym_get_liveRangeLength, get_liveRangeLength)
X_PDB_FUNCTION_ULONGLONG(_pdb_sym_get_targetVirtualAddress, get_targetVirtualAddress)
X_PDB_FUNCTION_ULONGLONG(_pdb_sym_get_virtualAddress, get_virtualAddress)

#define X_PDB_FUNCTION_LONG(func_name, pdb_name) \
    quint32 func_name(IDiaSymbol *pSymbol)       \
    {                                            \
        quint32 nResult = 0;                     \
        LONG lTemp = 0;                          \
        if (pSymbol->pdb_name(&lTemp) == S_OK) { \
            nResult = lTemp;                     \
        }                                        \
        return nResult;                          \
    }

X_PDB_FUNCTION_LONG(_pdb_sym_get_offset, get_offset)
X_PDB_FUNCTION_LONG(_pdb_sym_get_thisAdjust, get_thisAdjust)
X_PDB_FUNCTION_LONG(_pdb_sym_get_virtualBasePointerOffset, get_virtualBasePointerOffset)

#define X_PDB_FUNCTION_SYMBOL(func_name, pdb_name) \
    IDiaSymbol *func_name(IDiaSymbol *pSymbol)     \
    {                                              \
        IDiaSymbol *pResult = nullptr;             \
        IDiaSymbol *pTemp = nullptr;               \
        if (pSymbol->pdb_name(&pTemp) == S_OK) {   \
            pResult = pTemp;                       \
        }                                          \
        return pResult;                            \
    }

X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_arrayIndexType, get_arrayIndexType)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_baseSymbol, get_baseSymbol)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_classParent, get_classParent)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_coffGroup, get_coffGroup)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_container, get_container)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_lexicalParent, get_lexicalParent)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_lowerBound, get_lowerBound)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_objectPointerType, get_objectPointerType)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_subType, get_subType)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_type, get_type)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_unmodifiedType, get_unmodifiedType)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_upperBound, get_upperBound)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_virtualBaseTableType, get_virtualBaseTableType)
X_PDB_FUNCTION_SYMBOL(_pdb_sym_get_virtualTableShape, get_virtualTableShape)

QString _pdb_sym_get_undecoratedNameEx(IDiaSymbol *pSymbol)
{
    QString sResult;
    BSTR bstring = nullptr;

    if (pSymbol->get_undecoratedNameEx(0, &bstring) == S_OK) {
        sResult = QString::fromWCharArray(bstring);
        SysFreeString(bstring);
    }

    return sResult;
}

quint32 _pdb_sym_get_Count(IDiaEnumSymbols *pEnumSymbols)
{
    quint32 nResult = 0;
    LONG lTemp = 0;

    if (pEnumSymbols->get_Count(&lTemp) == S_OK) {
        nResult = lTemp;
    }

    return nResult;
}

QString _pdb_sym_get_guid(IDiaSymbol *pSymbol)
{
    QString sResult;

    GUID guid;

    if (pSymbol->get_guid(&guid) == S_OK) {
        QUuid uuid(guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6],
                   guid.Data4[7]);
        sResult = uuid.toString().remove("{").remove("}");
    }

    return sResult;
}

#endif

XWinPDB::XWinPDB(QIODevice *pDevice) : XBinary(pDevice)
{
#ifdef Q_OS_WIN
    g_pDiaDataSource = nullptr;
    g_pDiaSession = nullptr;
    g_pGlobal = nullptr;
#endif
}

XWinPDB::~XWinPDB()
{
#ifdef Q_OS_WIN
    if (g_pGlobal) {
        g_pGlobal->Release();
        g_pGlobal = nullptr;
    }

    if (g_pDiaSession) {
        g_pDiaSession->Release();
        g_pDiaSession = nullptr;
    }

    if (g_pDiaDataSource) {
        g_pDiaDataSource->Release();
        g_pDiaDataSource = nullptr;
    }
#endif
}

bool XWinPDB::loadMSDIALibrary(QString sFileName)
{
    bool bResult = false;
#ifdef Q_OS_WIN
    if (g_pDiaDataSource) {
        g_pDiaDataSource->Release();
        g_pDiaDataSource = nullptr;
    }

    wchar_t wszFilePath[512] = {};

    if (sFileName.toWCharArray(wszFilePath)) {
        HRESULT hr = NoRegCoCreate(wszFilePath, _uuidof(DiaSource), _uuidof(IDiaDataSource), (void **)(&g_pDiaDataSource));

        if (SUCCEEDED(hr)) {
            bResult = true;
        } else {
            emit errorMessage(tr("Cannot load MSDIA library"));
        }
    }
#endif
    return bResult;
}

bool XWinPDB::loadFile(QString sFileName)
{
    bool bResult = false;
#ifdef Q_OS_WIN
    if (g_pDiaDataSource) {
        wchar_t wszFilePath[512] = {};

        if (sFileName.toWCharArray(wszFilePath)) {
            HRESULT hr = g_pDiaDataSource->loadDataFromPdb(wszFilePath);

            if (SUCCEEDED(hr)) {
                if (g_pGlobal) {
                    g_pGlobal->Release();
                    g_pGlobal = nullptr;
                }

                if (g_pDiaSession) {
                    g_pDiaSession->Release();
                    g_pDiaSession = nullptr;
                }

                hr = g_pDiaDataSource->openSession(&g_pDiaSession);

                if (SUCCEEDED(hr)) {
                    hr = g_pDiaSession->get_globalScope(&g_pGlobal);

                    if (SUCCEEDED(hr)) {
                        bResult = true;
                    }
                } else {
                    emit errorMessage(tr("Cannot open session"));
                }
            } else {
                emit errorMessage(tr("Cannot load data from PDB"));
            }
        }
    }
#endif
    return bResult;
}

QString XWinPDB::getFileFormatString()
{
    QString sResult;
#ifdef Q_OS_WIN
    if (g_pGlobal) {
        sResult = _pdb_sym_get_name(g_pGlobal);
    }
#endif
    return sResult;
}

QString XWinPDB::getArch()
{
#ifdef Q_OS_WIN
    return XPE::getImageFileHeaderMachinesS().value(_pdb_sym_get_machineType(g_pGlobal));
#else
    return XBinary::getArch();
#endif
}

XWinPDB::PDB_INFO XWinPDB::getPdbInfo()
{
    PDB_INFO result = {};
#ifdef Q_OS_WIN
    result.sName = _pdb_sym_get_name(g_pGlobal);
    result.sGUID = _pdb_sym_get_guid(g_pGlobal);
    result.sFileName = _pdb_sym_get_symbolsFileName(g_pGlobal);
    result.sArch = getArch();
    result.nAge = _pdb_sym_get_age(g_pGlobal);
    result.nSignature = _pdb_sym_get_signature(g_pGlobal);
    result.bIsCTypes = _pdb_sym_get_isCTypes(g_pGlobal);
    result.bIsStripped = _pdb_sym_get_isStripped(g_pGlobal);
#endif
    return result;
}

XWinPDB::PDB_STATS XWinPDB::getPdbStats(PDSTRUCT *pPdStruct)
{
    PDB_STATS result = {};
#ifdef Q_OS_WIN

    IDiaEnumSymbols *pEnumSymbols = nullptr;

    qint32 nCurrent = 0;

    qint32 _nFreeIndex = XBinary::getFreeIndex(pPdStruct);

    if (g_pGlobal->findChildren(SymTagNull, nullptr, nsNone, &pEnumSymbols) == S_OK) {
        quint32 nCount = _pdb_sym_get_Count(pEnumSymbols);

        setPdStructTotal(pPdStruct, _nFreeIndex, nCount);

        //        QSet<quint32> stTypes;

        if (nCount) {
            IDiaSymbol *pSymbol;
            ULONG celt = 0;

            while (SUCCEEDED(pEnumSymbols->Next(1, &pSymbol, &celt)) && (celt == 1) && (!pPdStruct->bIsStop))  // TODO Stop
            {
                quint32 nSymTag = _pdb_sym_get_symTag(pSymbol);
                quint32 nID = _pdb_sym_get_symIndexId(pSymbol);

                if (nSymTag == SymTagUDT) {
                    quint32 nUDTKind = _pdb_sym_get_udtKind(pSymbol);

                    if (nUDTKind == 0)
                        result.listUDT_struct.append(nID);
                    else if (nUDTKind == 1)
                        result.listUDT_class.append(nID);
                    else if (nUDTKind == 2)
                        result.listUDT_union.append(nID);
                    else if (nUDTKind == 3)
                        result.listUDT_interface.append(nID);
                } else if (nSymTag == SymTagPublicSymbol) {
                    result.listPublicSymbol.append(nID);
                } else if (nSymTag == SymTagEnum) {
                    result.listEnum.append(nID);
                } else if (nSymTag == SymTagTypedef) {
                    result.listTypeDef.append(nID);
                }

                //                qDebug("%d %d",nID,nSymTag);

                pSymbol->Release();

                nCurrent++;
                setPdStructCurrent(pPdStruct, _nFreeIndex, nCurrent);
            }
        }

        pEnumSymbols->Release();
    }

    setPdStructFinished(pPdStruct, _nFreeIndex);

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

    //    QString v_compilerName=_pdb_sym_get_compilerName(g_pGlobal);
    //    quint32 v_symIndexId=_pdb_sym_get_symIndexId(g_pGlobal);
    //    quint32 v_symTag=_pdb_sym_get_symTag(g_pGlobal);

    OPTIONS options = {};
    options.bShowComments = true;
    options.bFixOffsets = true;

    PDSTRUCT pdStruct = {};

    PDB_STATS pdbInfo = getPdbStats(&pdStruct);

    qint32 nNumberOfRecords = pdbInfo.listUDT_struct.count();

    for (qint32 i = 0; i < nNumberOfRecords; i++) {
        if (pdbInfo.listUDT_struct.at(i) == 31174) {
            ELEMTYPE udtStruct = handleType(pdbInfo.listUDT_struct.at(i), &options);
            QString sRecord = elemTypeToString(udtStruct, &options);

            qDebug("%s", sRecord.toLatin1().data());
        }
        //        break;
    }

//    QString v_name=_pdb_sym_get_name(g_pGlobal);
//    QString v_guid=_pdb_sym_get_guid(g_pGlobal);
//    QString v_symbolsFileName=_pdb_sym_get_symbolsFileName(g_pGlobal);
//    quint32 v_age=_pdb_sym_get_age(g_pGlobal);
//    quint32 v_signature=_pdb_sym_get_signature(g_pGlobal);
//    quint32 v_machineType=_pdb_sym_get_machineType(g_pGlobal);
//    bool v_isCTypes=_pdb_sym_get_isCTypes(g_pGlobal);
//    bool v_isStripped=_pdb_sym_get_isStripped(g_pGlobal);

//    _testSymbol(g_pGlobal);
#endif
}

QString XWinPDB::tabString(qint32 nLevel)
{
    QString sResult;

    for (qint32 i = 0; i < nLevel; i++) {
        sResult += "    ";
    }

    return sResult;
}
#ifdef Q_OS_WIN
void XWinPDB::_testSymbol(IDiaSymbol *pSymbol)
{
    DWORD dwTest = 0;
    ULONGLONG ullTest = 0;
    LONG lTest = 0;
    BSTR strTest;
    BOOL bTest = 0;
    IDiaSymbol *pSymbolTest = 0;
    VARIANT varTest = {};
    GUID guidTest;
    BYTE bData[256];
    DWORD dwData[256];
    WORD wData[256];
    IDiaInputAssemblyFile *iafTest;

    if (pSymbol->findInputAssemblyFile(&iafTest) == S_OK) qDebug("findInputAssemblyFile");
    if (pSymbol->get_PGODynamicInstructionCount(&ullTest) == S_OK) qDebug("get_PGODynamicInstructionCount: %d", _pdb_sym_get_PGODynamicInstructionCount(pSymbol));
    if (pSymbol->get_PGOEdgeCount(&dwTest) == S_OK) qDebug("get_PGOEdgeCount: %d", _pdb_sym_get_PGOEdgeCount(pSymbol));
    if (pSymbol->get_PGOEntryCount(&dwTest) == S_OK) qDebug("get_PGOEntryCount: %d", _pdb_sym_get_PGOEntryCount(pSymbol));
    if (pSymbol->get_RValueReference(&bTest) == S_OK) qDebug("get_RValueReference: %d", _pdb_sym_get_RValueReference(pSymbol));
    if (pSymbol->get_access(&dwTest) == S_OK) qDebug("get_access: %d", _pdb_sym_get_access(pSymbol));
    if (pSymbol->get_addressOffset(&dwTest) == S_OK) qDebug("get_addressOffset: %d", _pdb_sym_get_addressOffset(pSymbol));
    if (pSymbol->get_addressSection(&dwTest) == S_OK) qDebug("get_addressSection: %d", _pdb_sym_get_addressSection(pSymbol));
    if (pSymbol->get_addressTaken(&bTest) == S_OK) qDebug("get_addressTaken: %d", _pdb_sym_get_addressTaken(pSymbol));
    if (pSymbol->get_age(&dwTest) == S_OK) qDebug("get_age: %d", _pdb_sym_get_age(pSymbol));
    if (pSymbol->get_arrayIndexType(&pSymbolTest) == S_OK) qDebug("get_arrayIndexType");
    if (pSymbol->get_arrayIndexTypeId(&dwTest) == S_OK) qDebug("get_arrayIndexTypeId: %d", _pdb_sym_get_arrayIndexTypeId(pSymbol));
    if (pSymbol->get_backEndBuild(&dwTest) == S_OK) qDebug("get_backEndBuild: %d", _pdb_sym_get_backEndBuild(pSymbol));
    if (pSymbol->get_backEndMajor(&dwTest) == S_OK) qDebug("get_backEndMajor: %d", _pdb_sym_get_backEndMajor(pSymbol));
    if (pSymbol->get_backEndMinor(&dwTest) == S_OK) qDebug("get_backEndMinor: %d", _pdb_sym_get_backEndMinor(pSymbol));
    if (pSymbol->get_backEndQFE(&dwTest) == S_OK) qDebug("get_backEndQFE: %d", _pdb_sym_get_backEndQFE(pSymbol));
    if (pSymbol->get_baseDataOffset(&dwTest) == S_OK) qDebug("get_baseDataOffset: %d", _pdb_sym_get_baseDataOffset(pSymbol));
    if (pSymbol->get_baseDataSlot(&dwTest) == S_OK) qDebug("get_baseDataSlot: %d", _pdb_sym_get_baseDataSlot(pSymbol));
    if (pSymbol->get_baseSymbol(&pSymbolTest) == S_OK) qDebug("get_baseSymbol");
    if (pSymbol->get_baseSymbolId(&dwTest) == S_OK) qDebug("get_baseSymbolId: %d", _pdb_sym_get_baseSymbolId(pSymbol));
    if (pSymbol->get_baseType(&dwTest) == S_OK) qDebug("get_baseType: %d", _pdb_sym_get_baseType(pSymbol));
    if (pSymbol->get_bindID(&dwTest) == S_OK) qDebug("get_bindID: %d", _pdb_sym_get_bindID(pSymbol));
    if (pSymbol->get_bindSlot(&dwTest) == S_OK) qDebug("get_bindSlot: %d", _pdb_sym_get_bindSlot(pSymbol));
    if (pSymbol->get_bindSpace(&dwTest) == S_OK) qDebug("get_bindSpace: %d", _pdb_sym_get_bindSpace(pSymbol));
    if (pSymbol->get_bitPosition(&dwTest) == S_OK) qDebug("get_bitPosition: %d", _pdb_sym_get_bitPosition(pSymbol));
    if (pSymbol->get_builtInKind(&dwTest) == S_OK) qDebug("get_builtInKind: %d", _pdb_sym_get_builtInKind(pSymbol));
    if (pSymbol->get_callingConvention(&dwTest) == S_OK) qDebug("get_callingConvention: %d", _pdb_sym_get_callingConvention(pSymbol));
    if (pSymbol->get_characteristics(&dwTest) == S_OK) qDebug("get_characteristics: %d", _pdb_sym_get_characteristics(pSymbol));
    if (pSymbol->get_classParent(&pSymbolTest) == S_OK) qDebug("get_classParent");
    if (pSymbol->get_classParentId(&dwTest) == S_OK) qDebug("get_classParentId: %d", _pdb_sym_get_classParentId(pSymbol));
    if (pSymbol->get_code(&bTest) == S_OK) qDebug("get_code: %d", _pdb_sym_get_code(pSymbol));
    if (pSymbol->get_coffGroup(&pSymbolTest) == S_OK) qDebug("get_coffGroup");
    if (pSymbol->get_compilerGenerated(&bTest) == S_OK) qDebug("get_compilerGenerated: %d", _pdb_sym_get_compilerGenerated(pSymbol));
    if (pSymbol->get_compilerName(&strTest) == S_OK) qDebug("get_compilerName: %s", _pdb_sym_get_compilerName(pSymbol).toLatin1().data());
    if (pSymbol->get_constType(&bTest) == S_OK) qDebug("get_constType: %d", _pdb_sym_get_constType(pSymbol));
    if (pSymbol->get_constantExport(&bTest) == S_OK) qDebug("get_constantExport: %d", _pdb_sym_get_constantExport(pSymbol));
    if (pSymbol->get_constructor(&bTest) == S_OK) qDebug("get_constructor: %d", _pdb_sym_get_constructor(pSymbol));
    if (pSymbol->get_container(&pSymbolTest) == S_OK) qDebug("get_container");
    if (pSymbol->get_count(&dwTest) == S_OK) qDebug("get_count: %d", _pdb_sym_get_count(pSymbol));
    if (pSymbol->get_countLiveRanges(&dwTest) == S_OK) qDebug("get_countLiveRanges: %d", _pdb_sym_get_countLiveRanges(pSymbol));
    if (pSymbol->get_customCallingConvention(&bTest) == S_OK) qDebug("get_customCallingConvention: %d", _pdb_sym_get_customCallingConvention(pSymbol));
    if (pSymbol->get_dataBytes(256, &dwTest, bData) == S_OK) qDebug("get_dataBytes");
    if (pSymbol->get_dataExport(&bTest) == S_OK) qDebug("get_dataExport: %d", _pdb_sym_get_dataExport(pSymbol));
    if (pSymbol->get_dataKind(&dwTest) == S_OK) qDebug("get_dataKind: %d", _pdb_sym_get_dataKind(pSymbol));
    if (pSymbol->get_editAndContinueEnabled(&bTest) == S_OK) qDebug("get_editAndContinueEnabled: %d", _pdb_sym_get_editAndContinueEnabled(pSymbol));
    if (pSymbol->get_exceptionHandlerAddressOffset(&dwTest) == S_OK) qDebug("get_exceptionHandlerAddressOffset: %d", _pdb_sym_get_exceptionHandlerAddressOffset(pSymbol));
    if (pSymbol->get_exceptionHandlerAddressSection(&dwTest) == S_OK)
        qDebug("get_exceptionHandlerAddressSection: %d", _pdb_sym_get_exceptionHandlerAddressSection(pSymbol));
    if (pSymbol->get_exceptionHandlerRelativeVirtualAddress(&dwTest) == S_OK)
        qDebug("get_exceptionHandlerRelativeVirtualAddress: %d", _pdb_sym_get_exceptionHandlerRelativeVirtualAddress(pSymbol));
    if (pSymbol->get_exceptionHandlerVirtualAddress(&ullTest) == S_OK)
        qDebug("get_exceptionHandlerVirtualAddress: %d", _pdb_sym_get_exceptionHandlerVirtualAddress(pSymbol));
    if (pSymbol->get_exportHasExplicitlyAssignedOrdinal(&bTest) == S_OK)
        qDebug("get_exportHasExplicitlyAssignedOrdinal: %d", _pdb_sym_get_exportHasExplicitlyAssignedOrdinal(pSymbol));
    if (pSymbol->get_exportIsForwarder(&bTest) == S_OK) qDebug("get_exportIsForwarder: %d", _pdb_sym_get_exportIsForwarder(pSymbol));
    if (pSymbol->get_farReturn(&bTest) == S_OK) qDebug("get_farReturn: %d", _pdb_sym_get_farReturn(pSymbol));
    if (pSymbol->get_finalLiveStaticSize(&dwTest) == S_OK) qDebug("get_finalLiveStaticSize: %d", _pdb_sym_get_finalLiveStaticSize(pSymbol));
    if (pSymbol->get_framePointerPresent(&bTest) == S_OK) qDebug("get_framePointerPresent: %d", _pdb_sym_get_framePointerPresent(pSymbol));
    if (pSymbol->get_frameSize(&dwTest) == S_OK) qDebug("get_frameSize: %d", _pdb_sym_get_frameSize(pSymbol));
    if (pSymbol->get_frontEndBuild(&dwTest) == S_OK) qDebug("get_frontEndBuild: %d", _pdb_sym_get_frontEndBuild(pSymbol));
    if (pSymbol->get_frontEndMajor(&dwTest) == S_OK) qDebug("get_frontEndMajor: %d", _pdb_sym_get_frontEndMajor(pSymbol));
    if (pSymbol->get_frontEndMinor(&dwTest) == S_OK) qDebug("get_frontEndMinor: %d", _pdb_sym_get_frontEndMinor(pSymbol));
    if (pSymbol->get_frontEndQFE(&dwTest) == S_OK) qDebug("get_frontEndQFE: %d", _pdb_sym_get_frontEndQFE(pSymbol));
    if (pSymbol->get_function(&bTest) == S_OK) qDebug("get_function: %d", _pdb_sym_get_function(pSymbol));
    if (pSymbol->get_guid(&guidTest) == S_OK) qDebug("get_guid");
    if (pSymbol->get_hasAlloca(&bTest) == S_OK) qDebug("get_hasAlloca: %d", _pdb_sym_get_hasAlloca(pSymbol));
    if (pSymbol->get_hasAssignmentOperator(&bTest) == S_OK) qDebug("get_hasAssignmentOperator: %d", _pdb_sym_get_hasAssignmentOperator(pSymbol));
    if (pSymbol->get_hasCastOperator(&bTest) == S_OK) qDebug("get_hasCastOperator: %d", _pdb_sym_get_hasCastOperator(pSymbol));
    if (pSymbol->get_hasControlFlowCheck(&bTest) == S_OK) qDebug("get_hasControlFlowCheck: %d", _pdb_sym_get_hasControlFlowCheck(pSymbol));
    if (pSymbol->get_hasDebugInfo(&bTest) == S_OK) qDebug("get_hasDebugInfo: %d", _pdb_sym_get_hasDebugInfo(pSymbol));
    if (pSymbol->get_hasEH(&bTest) == S_OK) qDebug("get_hasEH: %d", _pdb_sym_get_hasEH(pSymbol));
    if (pSymbol->get_hasEHa(&bTest) == S_OK) qDebug("get_hasEHa: %d", _pdb_sym_get_hasEHa(pSymbol));
    if (pSymbol->get_hasInlAsm(&bTest) == S_OK) qDebug("get_hasInlAsm: %d", _pdb_sym_get_hasInlAsm(pSymbol));
    if (pSymbol->get_hasLongJump(&bTest) == S_OK) qDebug("get_hasLongJump: %d", _pdb_sym_get_hasLongJump(pSymbol));
    if (pSymbol->get_hasManagedCode(&bTest) == S_OK) qDebug("get_hasManagedCode: %d", _pdb_sym_get_hasManagedCode(pSymbol));
    if (pSymbol->get_hasNestedTypes(&bTest) == S_OK) qDebug("get_hasNestedTypes: %d", _pdb_sym_get_hasNestedTypes(pSymbol));
    if (pSymbol->get_hasSEH(&bTest) == S_OK) qDebug("get_hasSEH: %d", _pdb_sym_get_hasSEH(pSymbol));
    if (pSymbol->get_hasSecurityChecks(&bTest) == S_OK) qDebug("get_hasSecurityChecks: %d", _pdb_sym_get_hasSecurityChecks(pSymbol));
    if (pSymbol->get_hasSetJump(&bTest) == S_OK) qDebug("get_hasSetJump: %d", _pdb_sym_get_hasSetJump(pSymbol));
    if (pSymbol->get_hasValidPGOCounts(&bTest) == S_OK) qDebug("get_hasValidPGOCounts: %d", _pdb_sym_get_hasValidPGOCounts(pSymbol));
    if (pSymbol->get_hfaDouble(&bTest) == S_OK) qDebug("get_hfaDouble: %d", _pdb_sym_get_hfaDouble(pSymbol));
    if (pSymbol->get_hfaFloat(&bTest) == S_OK) qDebug("get_hfaFloat: %d", _pdb_sym_get_hfaFloat(pSymbol));
    if (pSymbol->get_indirectVirtualBaseClass(&bTest) == S_OK) qDebug("get_indirectVirtualBaseClass: %d", _pdb_sym_get_indirectVirtualBaseClass(pSymbol));
    if (pSymbol->get_inlSpec(&bTest) == S_OK) qDebug("get_inlSpec: %d", _pdb_sym_get_inlSpec(pSymbol));
    if (pSymbol->get_interruptReturn(&bTest) == S_OK) qDebug("get_interruptReturn: %d", _pdb_sym_get_interruptReturn(pSymbol));
    if (pSymbol->get_intrinsic(&bTest) == S_OK) qDebug("get_intrinsic: %d", _pdb_sym_get_intrinsic(pSymbol));
    if (pSymbol->get_intro(&bTest) == S_OK) qDebug("get_intro: %d", _pdb_sym_get_intro(pSymbol));
    if (pSymbol->get_isAcceleratorGroupSharedLocal(&bTest) == S_OK) qDebug("get_isAcceleratorGroupSharedLocal: %d", _pdb_sym_get_isAcceleratorGroupSharedLocal(pSymbol));
    if (pSymbol->get_isAcceleratorPointerTagLiveRange(&bTest) == S_OK)
        qDebug("get_isAcceleratorPointerTagLiveRange: %d", _pdb_sym_get_isAcceleratorPointerTagLiveRange(pSymbol));
    if (pSymbol->get_isAcceleratorStubFunction(&bTest) == S_OK) qDebug("get_isAcceleratorStubFunction: %d", _pdb_sym_get_isAcceleratorStubFunction(pSymbol));
    if (pSymbol->get_isAggregated(&bTest) == S_OK) qDebug("get_isAggregated: %d", _pdb_sym_get_isAggregated(pSymbol));
    if (pSymbol->get_isCTypes(&bTest) == S_OK) qDebug("get_isCTypes: %d", _pdb_sym_get_isCTypes(pSymbol));
    if (pSymbol->get_isCVTCIL(&bTest) == S_OK) qDebug("get_isCVTCIL: %d", _pdb_sym_get_isCVTCIL(pSymbol));
    if (pSymbol->get_isConstructorVirtualBase(&bTest) == S_OK) qDebug("get_isConstructorVirtualBase: %d", _pdb_sym_get_isConstructorVirtualBase(pSymbol));
    if (pSymbol->get_isCxxReturnUdt(&bTest) == S_OK) qDebug("get_isCxxReturnUdt: %d", _pdb_sym_get_isCxxReturnUdt(pSymbol));
    if (pSymbol->get_isDataAligned(&bTest) == S_OK) qDebug("get_isDataAligned: %d", _pdb_sym_get_isDataAligned(pSymbol));
    if (pSymbol->get_isHLSLData(&bTest) == S_OK) qDebug("get_isHLSLData: %d", _pdb_sym_get_isHLSLData(pSymbol));
    if (pSymbol->get_isHotpatchable(&bTest) == S_OK) qDebug("get_isHotpatchable: %d", _pdb_sym_get_isHotpatchable(pSymbol));
    if (pSymbol->get_isInterfaceUdt(&bTest) == S_OK) qDebug("get_isInterfaceUdt: %d", _pdb_sym_get_isInterfaceUdt(pSymbol));
    if (pSymbol->get_isLTCG(&bTest) == S_OK) qDebug("get_isLTCG: %d", _pdb_sym_get_isLTCG(pSymbol));
    if (pSymbol->get_isLocationControlFlowDependent(&bTest) == S_OK)
        qDebug("get_isLocationControlFlowDependent: %d", _pdb_sym_get_isLocationControlFlowDependent(pSymbol));
    if (pSymbol->get_isMSILNetmodule(&bTest) == S_OK) qDebug("get_isMSILNetmodule: %d", _pdb_sym_get_isMSILNetmodule(pSymbol));
    if (pSymbol->get_isMatrixRowMajor(&bTest) == S_OK) qDebug("get_isMatrixRowMajor: %d", _pdb_sym_get_isMatrixRowMajor(pSymbol));
    if (pSymbol->get_isMultipleInheritance(&bTest) == S_OK) qDebug("get_isMultipleInheritance: %d", _pdb_sym_get_isMultipleInheritance(pSymbol));
    if (pSymbol->get_isNaked(&bTest) == S_OK) qDebug("get_isNaked: %d", _pdb_sym_get_isNaked(pSymbol));
    if (pSymbol->get_isOptimizedAway(&bTest) == S_OK) qDebug("get_isOptimizedAway: %d", _pdb_sym_get_isOptimizedAway(pSymbol));
    if (pSymbol->get_isOptimizedForSpeed(&bTest) == S_OK) qDebug("get_isOptimizedForSpeed: %d", _pdb_sym_get_isOptimizedForSpeed(pSymbol));
    if (pSymbol->get_isPGO(&bTest) == S_OK) qDebug("get_isPGO: %d", _pdb_sym_get_isPGO(pSymbol));
    if (pSymbol->get_isPointerBasedOnSymbolValue(&bTest) == S_OK) qDebug("get_isPointerBasedOnSymbolValue: %d", _pdb_sym_get_isPointerBasedOnSymbolValue(pSymbol));
    if (pSymbol->get_isPointerToDataMember(&bTest) == S_OK) qDebug("get_isPointerToDataMember: %d", _pdb_sym_get_isPointerToDataMember(pSymbol));
    if (pSymbol->get_isPointerToMemberFunction(&bTest) == S_OK) qDebug("get_isPointerToMemberFunction: %d", _pdb_sym_get_isPointerToMemberFunction(pSymbol));
    if (pSymbol->get_isRefUdt(&bTest) == S_OK) qDebug("get_isRefUdt: %d", _pdb_sym_get_isRefUdt(pSymbol));
    if (pSymbol->get_isReturnValue(&bTest) == S_OK) qDebug("get_isReturnValue: %d", _pdb_sym_get_isReturnValue(pSymbol));
    if (pSymbol->get_isSafeBuffers(&bTest) == S_OK) qDebug("get_isSafeBuffers: %d", _pdb_sym_get_isSafeBuffers(pSymbol));
    if (pSymbol->get_isSdl(&bTest) == S_OK) qDebug("get_isSdl: %d", _pdb_sym_get_isSdl(pSymbol));
    if (pSymbol->get_isSingleInheritance(&bTest) == S_OK) qDebug("get_isSingleInheritance: %d", _pdb_sym_get_isSingleInheritance(pSymbol));
    if (pSymbol->get_isSplitted(&bTest) == S_OK) qDebug("get_isSplitted: %d", _pdb_sym_get_isSplitted(pSymbol));
    if (pSymbol->get_isStatic(&bTest) == S_OK) qDebug("get_isStatic: %d", _pdb_sym_get_isStatic(pSymbol));
    if (pSymbol->get_isStripped(&bTest) == S_OK) qDebug("get_isStripped: %d", _pdb_sym_get_isStripped(pSymbol));
    if (pSymbol->get_isValueUdt(&bTest) == S_OK) qDebug("get_isValueUdt: %d", _pdb_sym_get_isValueUdt(pSymbol));
    if (pSymbol->get_isVirtualInheritance(&bTest) == S_OK) qDebug("get_isVirtualInheritance: %d", _pdb_sym_get_isVirtualInheritance(pSymbol));
    if (pSymbol->get_isWinRTPointer(&bTest) == S_OK) qDebug("get_isWinRTPointer: %d", _pdb_sym_get_isWinRTPointer(pSymbol));
    if (pSymbol->get_language(&dwTest) == S_OK) qDebug("get_language: %d", _pdb_sym_get_language(pSymbol));
    if (pSymbol->get_length(&ullTest) == S_OK) qDebug("get_length: %d", _pdb_sym_get_length(pSymbol));
    if (pSymbol->get_lexicalParent(&pSymbolTest) == S_OK) qDebug("get_lexicalParent");
    if (pSymbol->get_lexicalParentId(&dwTest) == S_OK) qDebug("get_lexicalParentId: %d", _pdb_sym_get_lexicalParentId(pSymbol));
    if (pSymbol->get_libraryName(&strTest) == S_OK) qDebug("get_libraryName: %s", _pdb_sym_get_libraryName(pSymbol).toLatin1().data());
    if (pSymbol->get_liveRangeLength(&ullTest) == S_OK) qDebug("get_liveRangeLength: %d", _pdb_sym_get_liveRangeLength(pSymbol));
    if (pSymbol->get_liveRangeStartAddressOffset(&dwTest) == S_OK) qDebug("get_liveRangeStartAddressOffset: %d", _pdb_sym_get_liveRangeStartAddressOffset(pSymbol));
    if (pSymbol->get_liveRangeStartAddressSection(&dwTest) == S_OK) qDebug("get_liveRangeStartAddressSection: %d", _pdb_sym_get_liveRangeStartAddressSection(pSymbol));
    if (pSymbol->get_liveRangeStartRelativeVirtualAddress(&dwTest) == S_OK)
        qDebug("get_liveRangeStartRelativeVirtualAddress: %d", _pdb_sym_get_liveRangeStartRelativeVirtualAddress(pSymbol));
    if (pSymbol->get_localBasePointerRegisterId(&dwTest) == S_OK) qDebug("get_localBasePointerRegisterId: %d", _pdb_sym_get_localBasePointerRegisterId(pSymbol));
    if (pSymbol->get_locationType(&dwTest) == S_OK) qDebug("get_locationType: %d", _pdb_sym_get_locationType(pSymbol));
    if (pSymbol->get_lowerBound(&pSymbolTest) == S_OK) qDebug("get_lowerBound");
    if (pSymbol->get_lowerBoundId(&dwTest) == S_OK) qDebug("get_lowerBoundId: %d", _pdb_sym_get_lowerBoundId(pSymbol));
    if (pSymbol->get_machineType(&dwTest) == S_OK) qDebug("get_machineType: %d", _pdb_sym_get_machineType(pSymbol));
    if (pSymbol->get_managed(&bTest) == S_OK) qDebug("get_managed: %d", _pdb_sym_get_managed(pSymbol));
    if (pSymbol->get_memorySpaceKind(&dwTest) == S_OK) qDebug("get_memorySpaceKind: %d", _pdb_sym_get_memorySpaceKind(pSymbol));
    if (pSymbol->get_modifierValues(0, &dwTest, wData) == S_OK) qDebug("get_modifierValues");
    if (pSymbol->get_msil(&bTest) == S_OK) qDebug("get_msil: %d", _pdb_sym_get_msil(pSymbol));
    if (pSymbol->get_name(&strTest) == S_OK) qDebug("get_name: %s", _pdb_sym_get_name(pSymbol).toLatin1().data());
    if (pSymbol->get_nested(&bTest) == S_OK) qDebug("get_nested: %d", _pdb_sym_get_nested(pSymbol));
    if (pSymbol->get_noInline(&bTest) == S_OK) qDebug("get_noInline: %d", _pdb_sym_get_noInline(pSymbol));
    if (pSymbol->get_noNameExport(&bTest) == S_OK) qDebug("get_noNameExport: %d", _pdb_sym_get_noNameExport(pSymbol));
    if (pSymbol->get_noReturn(&bTest) == S_OK) qDebug("get_noReturn: %d", _pdb_sym_get_noReturn(pSymbol));
    if (pSymbol->get_noStackOrdering(&bTest) == S_OK) qDebug("get_noStackOrdering: %d", _pdb_sym_get_noStackOrdering(pSymbol));
    if (pSymbol->get_notReached(&bTest) == S_OK) qDebug("get_notReached: %d", _pdb_sym_get_notReached(pSymbol));
    if (pSymbol->get_numberOfAcceleratorPointerTags(&dwTest) == S_OK)
        qDebug("get_numberOfAcceleratorPointerTags: %d", _pdb_sym_get_numberOfAcceleratorPointerTags(pSymbol));
    if (pSymbol->get_numberOfColumns(&dwTest) == S_OK) qDebug("get_numberOfColumns: %d", _pdb_sym_get_numberOfColumns(pSymbol));
    if (pSymbol->get_numberOfModifiers(&dwTest) == S_OK) qDebug("get_numberOfModifiers: %d", _pdb_sym_get_numberOfModifiers(pSymbol));
    if (pSymbol->get_numberOfRegisterIndices(&dwTest) == S_OK) qDebug("get_numberOfRegisterIndices: %d", _pdb_sym_get_numberOfRegisterIndices(pSymbol));
    if (pSymbol->get_numberOfRows(&dwTest) == S_OK) qDebug("get_numberOfRows: %d", _pdb_sym_get_numberOfRows(pSymbol));
    if (pSymbol->get_numericProperties(0, &dwTest, dwData) == S_OK) qDebug("get_numericProperties");
    if (pSymbol->get_objectFileName(&strTest) == S_OK) qDebug("get_objectFileName: %s", _pdb_sym_get_objectFileName(pSymbol).toLatin1().data());
    if (pSymbol->get_objectPointerType(&pSymbolTest) == S_OK) qDebug("get_objectPointerType");
    if (pSymbol->get_oemId(&dwTest) == S_OK) qDebug("get_oemId: %d", _pdb_sym_get_oemId(pSymbol));
    if (pSymbol->get_oemSymbolId(&dwTest) == S_OK) qDebug("get_oemSymbolId: %d", _pdb_sym_get_oemSymbolId(pSymbol));
    if (pSymbol->get_offset(&lTest) == S_OK) qDebug("get_offset: %d", _pdb_sym_get_offset(pSymbol));
    if (pSymbol->get_offsetInUdt(&dwTest) == S_OK) qDebug("get_offsetInUdt: %d", _pdb_sym_get_offsetInUdt(pSymbol));
    if (pSymbol->get_optimizedCodeDebugInfo(&bTest) == S_OK) qDebug("get_optimizedCodeDebugInfo: %d", _pdb_sym_get_optimizedCodeDebugInfo(pSymbol));
    if (pSymbol->get_ordinal(&dwTest) == S_OK) qDebug("get_ordinal: %d", _pdb_sym_get_ordinal(pSymbol));
    if (pSymbol->get_overloadedOperator(&bTest) == S_OK) qDebug("get_overloadedOperator: %d", _pdb_sym_get_overloadedOperator(pSymbol));
    if (pSymbol->get_packed(&bTest) == S_OK) qDebug("get_packed: %d", _pdb_sym_get_packed(pSymbol));
    if (pSymbol->get_paramBasePointerRegisterId(&dwTest) == S_OK) qDebug("get_paramBasePointerRegisterId: %d", _pdb_sym_get_paramBasePointerRegisterId(pSymbol));
    if (pSymbol->get_phaseName(&strTest) == S_OK) qDebug("get_phaseName: %s", _pdb_sym_get_phaseName(pSymbol).toLatin1().data());
    if (pSymbol->get_platform(&dwTest) == S_OK) qDebug("get_platform: %d", _pdb_sym_get_platform(pSymbol));
    if (pSymbol->get_privateExport(&bTest) == S_OK) qDebug("get_privateExport: %d", _pdb_sym_get_privateExport(pSymbol));
    if (pSymbol->get_pure(&bTest) == S_OK) qDebug("get_pure: %d", _pdb_sym_get_pure(pSymbol));
    if (pSymbol->get_rank(&dwTest) == S_OK) qDebug("get_rank: %d", _pdb_sym_get_rank(pSymbol));
    if (pSymbol->get_reference(&bTest) == S_OK) qDebug("get_reference: %d", _pdb_sym_get_reference(pSymbol));
    if (pSymbol->get_registerId(&dwTest) == S_OK) qDebug("get_registerId: %d", _pdb_sym_get_registerId(pSymbol));
    if (pSymbol->get_registerType(&dwTest) == S_OK) qDebug("get_registerType: %d", _pdb_sym_get_registerType(pSymbol));
    if (pSymbol->get_relativeVirtualAddress(&dwTest) == S_OK) qDebug("get_relativeVirtualAddress: %d", _pdb_sym_get_relativeVirtualAddress(pSymbol));
    if (pSymbol->get_restrictedType(&bTest) == S_OK) qDebug("get_restrictedType: %d", _pdb_sym_get_restrictedType(pSymbol));
    if (pSymbol->get_samplerSlot(&dwTest) == S_OK) qDebug("get_samplerSlot: %d", _pdb_sym_get_samplerSlot(pSymbol));
    if (pSymbol->get_scoped(&bTest) == S_OK) qDebug("get_scoped: %d", _pdb_sym_get_scoped(pSymbol));
    if (pSymbol->get_sealed(&bTest) == S_OK) qDebug("get_sealed: %d", _pdb_sym_get_sealed(pSymbol));
    if (pSymbol->get_signature(&dwTest) == S_OK) qDebug("get_signature: %d", _pdb_sym_get_signature(pSymbol));
    if (pSymbol->get_sizeInUdt(&dwTest) == S_OK) qDebug("get_sizeInUdt: %d", _pdb_sym_get_sizeInUdt(pSymbol));
    if (pSymbol->get_slot(&dwTest) == S_OK) qDebug("get_slot: %d", _pdb_sym_get_slot(pSymbol));
    if (pSymbol->get_sourceFileName(&strTest) == S_OK) qDebug("get_sourceFileName: %s", _pdb_sym_get_sourceFileName(pSymbol).toLatin1().data());
    if (pSymbol->get_staticSize(&dwTest) == S_OK) qDebug("get_staticSize: %d", _pdb_sym_get_staticSize(pSymbol));
    if (pSymbol->get_strictGSCheck(&bTest) == S_OK) qDebug("get_strictGSCheck: %d", _pdb_sym_get_strictGSCheck(pSymbol));
    if (pSymbol->get_stride(&dwTest) == S_OK) qDebug("get_stride: %d", _pdb_sym_get_stride(pSymbol));
    if (pSymbol->get_subType(&pSymbolTest) == S_OK) qDebug("get_subType");
    if (pSymbol->get_subTypeId(&dwTest) == S_OK) qDebug("get_subTypeId: %d", _pdb_sym_get_subTypeId(pSymbol));
    if (pSymbol->get_symIndexId(&dwTest) == S_OK) qDebug("get_symIndexId: %d", _pdb_sym_get_symIndexId(pSymbol));
    if (pSymbol->get_symTag(&dwTest) == S_OK) qDebug("get_symTag: %d", _pdb_sym_get_symTag(pSymbol));
    if (pSymbol->get_symbolsFileName(&strTest) == S_OK) qDebug("get_symbolsFileName: %s", _pdb_sym_get_symbolsFileName(pSymbol).toLatin1().data());
    if (pSymbol->get_targetOffset(&dwTest) == S_OK) qDebug("get_targetOffset: %d", _pdb_sym_get_targetOffset(pSymbol));
    if (pSymbol->get_targetRelativeVirtualAddress(&dwTest) == S_OK) qDebug("get_targetRelativeVirtualAddress: %d", _pdb_sym_get_targetRelativeVirtualAddress(pSymbol));
    if (pSymbol->get_targetSection(&dwTest) == S_OK) qDebug("get_targetSection: %d", _pdb_sym_get_targetSection(pSymbol));
    if (pSymbol->get_targetVirtualAddress(&ullTest) == S_OK) qDebug("get_targetVirtualAddress: %d", _pdb_sym_get_targetVirtualAddress(pSymbol));
    if (pSymbol->get_textureSlot(&dwTest) == S_OK) qDebug("get_textureSlot: %d", _pdb_sym_get_textureSlot(pSymbol));
    if (pSymbol->get_thisAdjust(&lTest) == S_OK) qDebug("get_thisAdjust: %d", _pdb_sym_get_thisAdjust(pSymbol));
    if (pSymbol->get_thunkOrdinal(&dwTest) == S_OK) qDebug("get_thunkOrdinal: %d", _pdb_sym_get_thunkOrdinal(pSymbol));
    if (pSymbol->get_timeStamp(&dwTest) == S_OK) qDebug("get_timeStamp: %d", _pdb_sym_get_timeStamp(pSymbol));
    if (pSymbol->get_token(&dwTest) == S_OK) qDebug("get_token: %d", _pdb_sym_get_token(pSymbol));
    if (pSymbol->get_type(&pSymbolTest) == S_OK) qDebug("get_type");
    if (pSymbol->get_typeId(&dwTest) == S_OK) qDebug("get_typeId: %d", _pdb_sym_get_typeId(pSymbol));
    if (pSymbol->get_typeIds(0, &dwTest, dwData) == S_OK) qDebug("get_typeIds");
    if (pSymbol->get_types(0, &dwTest, &pSymbolTest) == S_OK) qDebug("get_types");
    if (pSymbol->get_uavSlot(&dwTest) == S_OK) qDebug("get_uavSlot: %d", _pdb_sym_get_uavSlot(pSymbol));
    if (pSymbol->get_udtKind(&dwTest) == S_OK) qDebug("get_udtKind: %d", _pdb_sym_get_udtKind(pSymbol));
    if (pSymbol->get_unalignedType(&bTest) == S_OK) qDebug("get_unalignedType: %d", _pdb_sym_get_unalignedType(pSymbol));
    if (pSymbol->get_undecoratedName(&strTest) == S_OK) qDebug("get_undecoratedName: %s", _pdb_sym_get_undecoratedName(pSymbol).toLatin1().data());
    if (pSymbol->get_undecoratedNameEx(0, &strTest) == S_OK) qDebug("get_undecoratedNameEx: %s", _pdb_sym_get_undecoratedNameEx(pSymbol).toLatin1().data());
    if (pSymbol->get_unmodifiedType(&pSymbolTest) == S_OK) qDebug("get_unmodifiedType");
    if (pSymbol->get_unmodifiedTypeId(&dwTest) == S_OK) qDebug("get_unmodifiedTypeId: %d", _pdb_sym_get_unmodifiedTypeId(pSymbol));
    if (pSymbol->get_unused(&strTest) == S_OK) qDebug("get_unused: %s", _pdb_sym_get_unused(pSymbol).toLatin1().data());
    if (pSymbol->get_upperBound(&pSymbolTest) == S_OK) qDebug("get_upperBound");
    if (pSymbol->get_upperBoundId(&dwTest) == S_OK) qDebug("get_upperBoundId: %d", _pdb_sym_get_upperBoundId(pSymbol));
    if (pSymbol->get_value(&varTest) == S_OK) qDebug("get_value");
    if (pSymbol->get_virtual(&bTest) == S_OK) qDebug("get_virtual: %d", _pdb_sym_get_virtual(pSymbol));
    if (pSymbol->get_virtualAddress(&ullTest) == S_OK) qDebug("get_virtualAddress: %d", _pdb_sym_get_virtualAddress(pSymbol));
    if (pSymbol->get_virtualBaseClass(&bTest) == S_OK) qDebug("get_virtualBaseClass: %d", _pdb_sym_get_virtualBaseClass(pSymbol));
    if (pSymbol->get_virtualBaseDispIndex(&dwTest) == S_OK) qDebug("get_virtualBaseDispIndex: %d", _pdb_sym_get_virtualBaseDispIndex(pSymbol));
    if (pSymbol->get_virtualBaseOffset(&dwTest) == S_OK) qDebug("get_virtualBaseOffset: %d", _pdb_sym_get_virtualBaseOffset(pSymbol));
    if (pSymbol->get_virtualBasePointerOffset(&lTest) == S_OK) qDebug("get_virtualBasePointerOffset: %d", _pdb_sym_get_virtualBasePointerOffset(pSymbol));
    if (pSymbol->get_virtualBaseTableType(&pSymbolTest) == S_OK) qDebug("get_virtualBaseTableType");
    if (pSymbol->get_virtualTableShape(&pSymbolTest) == S_OK) qDebug("get_virtualTableShape");
    if (pSymbol->get_virtualTableShapeId(&dwTest) == S_OK) qDebug("get_virtualTableShapeId: %d", _pdb_sym_get_virtualTableShapeId(pSymbol));
    if (pSymbol->get_volatileType(&bTest) == S_OK) qDebug("get_volatileType: %d", _pdb_sym_get_volatileType(pSymbol));
    if (pSymbol->get_wasInlined(&bTest) == S_OK) qDebug("get_wasInlined: %d", _pdb_sym_get_wasInlined(pSymbol));
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

    qDebug("Number of Children: %d", getNumberOfChildren(pSymbol));
}
#endif
#ifdef Q_OS_WIN
quint32 XWinPDB::getNumberOfChildren(IDiaSymbol *pSymbol)
{
    quint32 nResult = 0;

    IDiaEnumSymbols *pEnumSymbols;
    if (pSymbol->findChildren(SymTagNull, nullptr, nsNone, &pEnumSymbols) == S_OK) {
        LONG nCount = 0;

        if (pEnumSymbols->get_Count(&nCount) == S_OK) {
            nResult = nCount;
        }

        pEnumSymbols->Release();
    }

    return nResult;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::getSymbolName(IDiaSymbol *pSymbol)
{
    QString sResult;

    sResult = _pdb_sym_get_name(pSymbol);

    // TODO Check more
    if (sResult.contains("<unnamed-tag>")) {
        sResult = sResult.replace("<unnamed-tag>", QString("_unnamed_%1").arg(_pdb_sym_get_symIndexId(pSymbol)));
    } else if (sResult.contains("<anonymous-tag>")) {
        sResult = sResult.replace("<anonymous-tag>", QString("_anonymous_%1").arg(_pdb_sym_get_symIndexId(pSymbol)));
    }

    return sResult;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::handleFunctionArgs(IDiaSymbol *pSymbol, OPTIONS *pOptions, qint32 nLevel)
{
    QString sResult;

    QList<ELEMTYPE> listArgs;

    IDiaEnumSymbols *pEnumSymbols;
    if (pSymbol->findChildren(SymTagNull, nullptr, nsNone, &pEnumSymbols) == S_OK) {
        IDiaSymbol *pRecord = nullptr;
        ULONG celt = 0;

        while (SUCCEEDED(pEnumSymbols->Next(1, &pRecord, &celt)) && (celt == 1)) {
            ELEMTYPE record = handleType(pRecord, pOptions, nLevel + 1);

            listArgs.append(record);

            pRecord->Release();
        }

        pEnumSymbols->Release();
    }

    sResult += "(";

    qint32 nNumberOfRecords = listArgs.count();

    for (qint32 i = 0; i < nNumberOfRecords; i++) {
        sResult += listArgs.at(i).sName;

        if (i != (nNumberOfRecords - 1)) {
            sResult += ",";
        }
    }

    sResult += ")";

    return sResult;
}
#endif
#ifdef Q_OS_WIN
IDiaSymbol *XWinPDB::getSymbolById(quint32 nId)
{
    IDiaSymbol *pResult = nullptr;
    IDiaSymbol *pTemp = nullptr;

    if (g_pDiaSession) {
        DWORD dwId = nId;
        if (g_pDiaSession->symbolById(dwId, &pTemp) == S_OK) {
            pResult = pTemp;
        }
    }

    return pResult;
}
#endif
#ifdef Q_OS_WIN
XWinPDB::ELEMTYPE XWinPDB::handleType(quint32 nId, OPTIONS *pOptions)
{
    ELEMTYPE result = {};

    IDiaSymbol *pSymbol = getSymbolById(nId);

    if (pSymbol) {
        result = handleType(pSymbol, pOptions, 0);

        pSymbol->Release();
    }

    return result;
}
#endif
#ifdef Q_OS_WIN
XWinPDB::ELEMTYPE XWinPDB::handleType(IDiaSymbol *pSymbol, OPTIONS *pOptions, qint32 nLevel)
{
    //_testSymbol(pSymbol);

    ELEMTYPE result = {};

    result.nID = _pdb_sym_get_symIndexId(pSymbol);

    quint32 nSymTag = _pdb_sym_get_symTag(pSymbol);

    if (nSymTag == SymTagData) {
        result.eType = ET_DATA;
        // TODO get_dataKind
        // TODO get_locationType

        QString sName = getSymbolName(pSymbol);

        IDiaSymbol *pType = _pdb_sym_get_type(pSymbol);

        if (pType) {
            ELEMTYPE record = handleType(pType, pOptions, nLevel + 1);

            if (record.sName.contains("#NAME#")) {
                result.sName = record.sName.replace("#NAME#", sName).trimmed();
            } else {
                result.sName = QString("%1 %2").arg(record.sName, sName).trimmed();
            }

            result.nSize = record.nSize;

            pType->Release();
        }

        result.nOffset = _pdb_sym_get_offset(pSymbol);

        DWORD dwBitPosition = 0;

        if (pSymbol->get_bitPosition(&dwBitPosition) == S_OK) {
            result.nBitOffset = dwBitPosition;
            result.nBitSize = _pdb_sym_get_length(pSymbol);
        }
    } else if (nSymTag == SymTagBaseType) {
        result.eType = ET_BASETYPE;

        result.nSize = _pdb_sym_get_length(pSymbol);
        quint32 nBaseType = _pdb_sym_get_baseType(pSymbol);

        switch (nBaseType) {
            case 0:
                result.sName = "<btNoType>";
                break;
            case 1:
                result.sName = "void";
                break;
            case 2:
                result.sName = "char";
                break;
            case 3:
                result.sName = "wchar_t";
                break;
            case 4:
                result.sName = "signed char";
                break;
            case 5:
                result.sName = "unsigned char";
                break;
            case 6:
                result.sName = "int";
                break;
            case 7:
                result.sName = "unsigned int";
                break;
            case 8:
                result.sName = "float";
                break;
            case 9:
                result.sName = "BCD";
                break;
            case 10:
                result.sName = "bool";
                break;
            case 11:
                result.sName = "short";
                break;
            case 12:
                result.sName = "unsigned short";
                break;
            case 13:
                result.sName = "long";
                break;
            case 14:
                result.sName = "unsigned long";
                break;
            case 15:
                result.sName = "__int8";
                break;
            case 16:
                result.sName = "__int16";
                break;
            case 17:
                result.sName = "__int32";
                break;
            case 18:
                result.sName = "__int64";
                break;
            case 19:
                result.sName = "__int128";
                break;
            case 20:
                result.sName = "unsigned __int8";
                break;
            case 21:
                result.sName = "unsigned __int16";
                break;
            case 22:
                result.sName = "unsigned __int32";
                break;
            case 23:
                result.sName = "unsigned __int64";
                break;
            case 24:
                result.sName = "unsigned __int128";
                break;
            case 25:
                result.sName = "CURRENCY";
                break;
            case 26:
                result.sName = "DATE";
                break;
            case 27:
                result.sName = "VARIANT";
                break;
            case 28:
                result.sName = "COMPLEX";
                break;
            case 29:
                result.sName = "BIT";
                break;
            case 30:
                result.sName = "BSTR";
                break;
            case 31:
                result.sName = "HRESULT";
                break;
            case 32:
                result.sName = "char16_t";
                break;
            case 33:
                result.sName = "char32_t";
                break;
            default:
                qDebug("FIXME");
        }

        if (pOptions->bFixTypes) {
            // TODO Check!
            if (((nBaseType == 7) || (nBaseType == 14)) && (result.nSize != 4))  // "unsigned int"
            {
                switch (result.nSize) {
                    case 1:
                        result.sName = "unsigned char";
                        break;
                    case 2:
                        result.sName = "unsigned short";
                        break;
                    case 4:
                        result.sName = "unsigned int";
                        break;
                    case 8:
                        result.sName = "unsigned long long";
                        break;
                }
            }

            if (((nBaseType == 6) || (nBaseType == 13)) && (result.nSize != 4))  // "int"
            {
                switch (result.nSize) {
                    case 1:
                        result.sName = "char";
                        break;
                    case 2:
                        result.sName = "short";
                        break;
                    case 4:
                        result.sName = "int";
                        break;
                    case 8:
                        result.sName = "long long";
                        break;
                }
            }
        }
    } else if (nSymTag == SymTagUDT) {
        QString sType;

        QString sName = getSymbolName(pSymbol);
        quint32 nKind = _pdb_sym_get_udtKind(pSymbol);

        if (nKind == 0) {
            sType = "struct";
            result.eType = ET_STRUCT;
        } else if (nKind == 1) {
            sType = "class";
            result.eType = ET_CLASS;
        } else if (nKind == 2) {
            sType = "union";
            result.eType = ET_UNION;
        } else if (nKind == 3) {
            sType = "interface";
            result.eType = ET_INTERFACE;
        }

        result.sName = QString("%1 %2").arg(sType, sName);
        result.nSize = _pdb_sym_get_length(pSymbol);
    } else if (nSymTag == SymTagPointerType) {
        result.eType = ET_POINTERTYPE;
        QString sRef;

        if (_pdb_sym_get_reference(pSymbol)) {
            sRef = "&";
        } else {
            sRef = "*";
        }

        IDiaSymbol *pType = _pdb_sym_get_type(pSymbol);

        if (pType) {
            ELEMTYPE record = handleType(pType, pOptions, nLevel + 1);

            if (record.sName.contains("#NAME#")) {
                result.sName = record.sName.replace("#NAME#", QString("%1 #NAME#").arg(sRef)).trimmed();
            } else {
                result.sName = QString("%1 %2").arg(record.sName, sRef);
            }

            pType->Release();
        }

        result.nSize = _pdb_sym_get_length(pSymbol);
    } else if (nSymTag == SymTagArrayType) {
        result.eType = ET_ARRAYTYPE;
        quint32 nCount = _pdb_sym_get_count(pSymbol);
        // TODO [x][y][z]...
        // TODO if nLimit > X then no prefix type
        // TODO _pdb_sym_get_arrayIndexType

        IDiaSymbol *pType = _pdb_sym_get_type(pSymbol);

        if (pType) {
            ELEMTYPE record = handleType(pType, pOptions, nLevel + 1);

            result.sName = QString("%1 #NAME#[%2]").arg(record.sName, QString::number(nCount));
            result.nSize = nCount * record.nSize;
            // TODO Check get_length

            pType->Release();
        }
    } else if (nSymTag == SymTagEnum) {
        result.eType = ET_ENUM;
        QString sName = getSymbolName(pSymbol);

        result.sName = QString("enum %1").arg(sName);
        result.nSize = _pdb_sym_get_length(pSymbol);
    } else if (nSymTag == SymTagFunctionType) {
        result.eType = ET_FUNCTIONTYPE;
        // TODO get_callingConvention

        IDiaSymbol *pType = _pdb_sym_get_type(pSymbol);

        if (pType) {
            ELEMTYPE record = handleType(pType, pOptions, nLevel + 1);

            result.sName = QString("%1 (#NAME#)").arg(record.sName);
            result.nSize = record.nSize;

            pType->Release();
        }

        result.sName += handleFunctionArgs(pSymbol, pOptions, nLevel + 1);
    } else if (nSymTag == SymTagFunction) {
        result.eType = ET_FUNCTION;

        result.sName = _pdb_sym_get_name(pSymbol);
        result.nSize = _pdb_sym_get_length(pSymbol);
        // TODO get_callingConvention

        IDiaSymbol *pType = _pdb_sym_get_type(pSymbol);

        if (pType) {
            ELEMTYPE record = handleType(pType, pOptions, nLevel + 1);

            result.sName = QString("%1 %2").arg(record.sName, _pdb_sym_get_name(pSymbol));

            pType->Release();
        }

        result.sName += handleFunctionArgs(pSymbol, pOptions, nLevel + 1);
    } else if (nSymTag == SymTagFunctionArgType) {
        result.eType = ET_FUNCTIONARGTYPE;

        IDiaSymbol *pType = _pdb_sym_get_type(pSymbol);

        if (pType) {
            ELEMTYPE record = handleType(pType, pOptions, nLevel + 1);

            result.sName = record.sName;

            result.nSize = record.nSize;

            pType->Release();
        }
    } else {
        _testSymbol(pSymbol);
        qDebug("UnknownType: %d", nSymTag);
    }

    if ((nLevel == 0) && (result.eType != ET_FUNCTIONTYPE)) {
        IDiaEnumSymbols *pEnumSymbols;
        if (pSymbol->findChildren(SymTagNull, nullptr, nsNone, &pEnumSymbols) == S_OK) {
            IDiaSymbol *pRecord = nullptr;
            ULONG celt = 0;

            while (SUCCEEDED(pEnumSymbols->Next(1, &pRecord, &celt)) && (celt == 1)) {
                //                _testSymbol(pSymbol);
                ELEMTYPE record = handleType(pRecord, pOptions, nLevel + 1);

                result.listRecords.append(record);

                pRecord->Release();
            }

            pEnumSymbols->Release();
        }
    }

    return result;
}
#endif
#ifdef Q_OS_WIN
QString XWinPDB::elemTypeToString(ELEMTYPE elemType, OPTIONS *pOptions)
{
    // TODO hide fix offset and add alignment for classes
    QString sResult;

    if ((elemType.eType == ET_STRUCT) || (elemType.eType == ET_UNION)) {
        QList<TNODE> listNodes;

        {
            TNODE record = {};

            record.nID = 0;
            record.nOffset = 0;
            record.nSize = 0;
            record.bIsBegin = true;

            if (elemType.eType == ET_STRUCT) {
                record.bIsStruct = true;
            } else if (elemType.eType == ET_UNION) {
                record.bIsUnion = true;
            }

            record.nStructSize = elemType.nSize;

            if ((pOptions->bFixOffsets) || (pOptions->bAddAlignment)) {
                record.sGUID = XBinary::generateUUID();
            }

            listNodes.append(record);
        }

        {
            qint32 nNumberOfRecords = elemType.listRecords.count();

            for (qint32 i = 0; i < nNumberOfRecords; i++) {
                TNODE record = {};

                record.nID = elemType.listRecords.at(i).nID;
                record.nOffset = elemType.listRecords.at(i).nOffset;
                record.nSize = elemType.listRecords.at(i).nSize;
                record.sName = elemType.listRecords.at(i).sName;
                record.nBitOffset = elemType.listRecords.at(i).nBitOffset;
                record.nBitSize = elemType.listRecords.at(i).nBitSize;

                if ((pOptions->bFixOffsets) || (pOptions->bAddAlignment)) {
                    record.sGUID = XBinary::generateUUID();
                }

                listNodes.append(record);
            }
        }

        {
            TNODE record = {};

            record.nID = 0;
            record.nOffset = elemType.nSize;
            record.nSize = 0;
            record.bIsEnd = true;
            record.nStructSize = elemType.nSize;

            if (elemType.eType == ET_STRUCT) {
                record.bIsStruct = true;
            } else if (elemType.eType == ET_UNION) {
                record.bIsUnion = true;
            }

            if ((pOptions->bFixOffsets) || (pOptions->bAddAlignment)) {
                record.sGUID = XBinary::generateUUID();
            }

            listNodes.append(record);
        }

        if ((pOptions->bFixOffsets) || (pOptions->bAddAlignment)) {
            {
                qint32 nNumberOfRecords = listNodes.count();

                for (qint32 i = 0; i < nNumberOfRecords; i++) {
                    for (qint32 j = 0; j < nNumberOfRecords; j++) {
                        if (i != j) {
                            bool bNext = false;
                            bool bPrev = false;

                            if ((listNodes[i].nOffset + listNodes[i].nSize) == listNodes[j].nOffset) {
                                if (listNodes[i].nBitSize) {
                                    if ((listNodes[i].nBitOffset + listNodes[i].nBitSize) == listNodes[j].nBitOffset) {
                                        bNext = true;
                                    }
                                } else {
                                    bNext = true;
                                }
                            }

                            if ((listNodes[j].nOffset + listNodes[j].nSize) == listNodes[i].nOffset) {
                                if (listNodes[i].nBitSize) {
                                    if ((listNodes[j].nBitOffset + listNodes[j].nBitSize) == listNodes[i].nBitOffset) {
                                        bPrev = true;
                                    }
                                } else {
                                    bPrev = true;
                                }
                            }

                            if (bNext) {
                                listNodes[i].listNext.append(listNodes.at(j).sGUID);
                            }

                            if (bPrev) {
                                listNodes[i].listPrev.append(listNodes.at(j).sGUID);
                            }
                        }
                    }
                }
            }

            // TODO
            if (pOptions->bFixOffsets) {
                // TODO fix bit members
                // TODO bIsBitStruct
            }

            if (pOptions->bFixOffsets) {
                bool bFix = false;

                do {
                    qint32 nNumberOfRecords = listNodes.count();

                    for (qint32 i = 0; i < nNumberOfRecords; i++) {
                        qint32 nNumberOfNextRecords = listNodes.at(i).listNext.count();

                        if ((nNumberOfNextRecords > 1) && (!listNodes.at(i).bIsUnion)) {
                            qDebug("Fix offset");

                            // Get maximum size
                            qint32 nMaxSize = 0;

                            for (int j = 0; j < nNumberOfNextRecords; j++) {
                                qint32 nIndex = _findTNodeByGuid(&listNodes, listNodes.at(i).sGUID);

                                if (nIndex != -1) {
                                    nMaxSize = qMax(listNodes.at(i).nSize, nMaxSize);
                                    nMaxSize = qMax(listNodes.at(i).nStructSize, nMaxSize);
                                }
                            }

                            if (!nMaxSize) {
                                qDebug("Max size = 0");
                            }

                            // Remove prevs

                            // Add new Record
                        }

                        //                        if((listNodes.at(i).listPrev.count()>1)&&(!listNodes.at(i).bIsUnion))
                        //                        {
                        //                            qDebug("Fix offset end");
                        //                        }
                    }
                } while (bFix);
            }

            if (pOptions->bAddAlignment) {
                // TODO
            } else {
                // TODO
                // Find next
            }
        }

        sResult += elemType.sName;

        if (pOptions->bShowComments) {
            sResult += QString(" // Size=0x%1 (Id=%2)").arg(XBinary::valueToHexEx(elemType.nSize), QString::number(elemType.nID));
        }

        sResult += QString("\r\n");

        qint32 nLevel = 0;

        if (pOptions->bFixOffsets) {
            qint32 nNumberOfRecords = listNodes.count();

            for (qint32 i = 0; i < nNumberOfRecords; i++) {
                _addStringRecord(&sResult, &listNodes, i, &nLevel, pOptions);
            }
        } else {
            qint32 nNumberOfRecords = listNodes.count();

            for (qint32 i = 0; i < nNumberOfRecords; i++) {
                _addStringRecord(&sResult, &listNodes, i, &nLevel, pOptions);
            }
        }
    }

    return sResult;
}
#endif
void XWinPDB::_addStringRecord(QString *pString, QList<TNODE> *pListNodes, qint32 nIndex, qint32 *pnLevel, OPTIONS *pOptions)
{
    if (pListNodes->at(nIndex).bIsBegin) {
        *pString += tabString(*pnLevel);

        if (pListNodes->at(nIndex).bShowType) {
            if (pListNodes->at(nIndex).bIsStruct) {
                *pString += "struct";
            } else if (pListNodes->at(nIndex).bIsUnion) {
                *pString += "union";
            }
        }

        *pString += "{";
        (*pnLevel)++;
    } else if (pListNodes->at(nIndex).bIsEnd) {
        (*pnLevel)--;
        *pString += tabString(*pnLevel);
        *pString += "}";
    } else {
        *pString += tabString(*pnLevel);
        *pString += pListNodes->at(nIndex).sName;

        if (pListNodes->at(nIndex).nBitSize) {
            *pString += QString(":%1").arg(pListNodes->at(nIndex).nBitSize);
        }

        *pString += ";";

        if (pOptions->bShowComments) {
            *pString +=
                QString(" // Offset = 0x%1 Size = 0x%2").arg(XBinary::valueToHexEx(pListNodes->at(nIndex).nOffset), XBinary::valueToHexEx(pListNodes->at(nIndex).nSize));

            if (pListNodes->at(nIndex).nBitSize) {
                *pString += QString(" BitOffset=0x%1 BitSize=0x%2")
                                .arg(XBinary::valueToHexEx(pListNodes->at(nIndex).nBitOffset), XBinary::valueToHexEx(pListNodes->at(nIndex).nBitSize));
            }
        }
    }

    *pString += QString("\r\n");
}

qint32 XWinPDB::_findTNodeByGuid(QList<TNODE> *pListNodes, QString sGUID)
{
    qint32 nResult = -1;

    qint32 nNumberOfRecords = pListNodes->count();

    for (qint32 i = 0; i < nNumberOfRecords; i++) {
        if (pListNodes->at(i).sGUID == sGUID) {
            nResult = i;

            break;
        }
    }

    return nResult;
}
