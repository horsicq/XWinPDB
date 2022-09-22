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
#ifndef XWINPDB_H
#define XWINPDB_H

#include <QObject>
#include <QIODevice>
#include "xpe.h"
#include "xwinpdb_def.h"

class XWinPDB: public XBinary
{
    Q_OBJECT

public:
    struct PDB_INFO
    {
        QString sName;
        QString sGUID;
        QString sFileName;
        QString sArch;
        quint32 nAge;
        quint32 nSignature;
        bool bIsCTypes;
        bool bIsStripped;
        QList<quint32> listCompiland;
        QList<quint32> listData;
        QList<quint32> listFunction;
        QList<quint32> listUDT_struct;
        QList<quint32> listUDT_class;
        QList<quint32> listUDT_union;
        QList<quint32> listUDT_interface;
        QList<quint32> listTypeDef;
        QList<quint32> listPublicSymbol;
        QList<quint32> listEnum;
        QList<quint32> listPointerType;
        QList<quint32> listBaseClass;
        QList<quint32> listFunctionType;
        QList<quint32> listArrayType;
        QList<quint32> listVTable;
        QList<quint32> listFunctionArgType;
        QList<quint32> listBaseType;
    };

    XWinPDB(QIODevice *pDevice);
    ~XWinPDB();

    bool loadMSDIALibrary(QString sFileName);
    bool loadFile(QString sFileName);
    virtual QString getName();
    virtual QString getArch();
    PDB_INFO getPdbInfo(PDSTRUCT *pPdStruct);
    void test();

private:
#ifdef Q_OS_WIN
    void _testSymbol(IDiaSymbol *pSymbol);
    quint32 _get_symIndexId(IDiaSymbol *pSymbol);
    quint32 _get_symTag(IDiaSymbol *pSymbol);
    QString _get_name(IDiaSymbol *pSymbol);
    QString _get_guid(IDiaSymbol *pSymbol);
    QString _get_symbolsFileName(IDiaSymbol *pSymbol);
    quint32 _get_age(IDiaSymbol *pSymbol);
    quint32 _get_signature(IDiaSymbol *pSymbol);
    quint32 _get_machineType(IDiaSymbol *pSymbol);
    bool _get_isCTypes(IDiaSymbol *pSymbol);
    bool _get_isStripped(IDiaSymbol *pSymbol);
    QString _get_compilerName(IDiaSymbol *pSymbol);
    quint32 _get_Count(IDiaEnumSymbols *pEnumSymbols);
#endif
private:
#ifdef Q_OS_WIN
    IDiaDataSource *g_pDiaDataSource;
    IDiaSession *g_pDiaSession;
    IDiaSymbol *g_pGlobal;
#endif
};

#endif // XWINPDB_H
