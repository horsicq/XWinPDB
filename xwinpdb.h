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

#include <QIODevice>
#include <QObject>

#include "xpe.h"
#include "xwinpdb_def.h"

#ifdef Q_OS_WIN32
#include <windows.h>

#include "cvConst.h"
#include "dia2.h"
#include "diaCreate.h"
#include "diacreate.h"
#endif

class XWinPDB : public XBinary {
    Q_OBJECT

public:
    struct OPTIONS {
        bool bFixTypes;
        bool bShowComments;
        bool bAddAlignment;
        bool bFixOffsets;
    };

    struct PDB_INFO {
        QString sName;
        QString sGUID;
        QString sFileName;
        QString sArch;
        quint32 nAge;
        quint32 nSignature;
        bool bIsCTypes;
        bool bIsStripped;
        QList<quint32> listCompiland;
    };

    struct PDB_STATS {
        QList<quint32> listUDT_struct;
        QList<quint32> listUDT_class;
        QList<quint32> listUDT_union;
        QList<quint32> listUDT_interface;
        QList<quint32> listTypeDef;
        QList<quint32> listPublicSymbol;
        QList<quint32> listEnum;
    };

    enum ET {
        ET_UNKNOWN = 0,
        ET_STRUCT,
        ET_CLASS,
        ET_UNION,
        ET_ENUM,
        ET_INTERFACE,
        ET_DATA,
        ET_FUNCTION,
        ET_BASETYPE,
        ET_ARRAYTYPE,
        ET_POINTERTYPE,
        ET_FUNCTIONTYPE,
        ET_FUNCTIONARGTYPE
    };

    struct ELEMTYPE {
        QString sName;
        qint32 nSize;
        ET eType;
        qint32 nOffset;
        quint32 nID;
        QList<ELEMTYPE> listRecords;
    };

    struct TNODE {
        QString sGUID;
        QString sName;
        qint32 nSize;
        qint32 nOffset;
        quint32 nID;
        bool bShowType;
        bool bIsBegin;
        bool bIsEnd;
        bool bIsStruct;
        bool bIsUnion;
        qint32 nStructSize;
        QList<QString> listPrev;
        QList<QString> listNext;
    };

    XWinPDB(QIODevice *pDevice);
    ~XWinPDB();

    bool loadMSDIALibrary(QString sFileName);
    bool loadFile(QString sFileName);
    virtual QString getFileFormatString();
    virtual QString getArch();
    PDB_INFO getPdbInfo();
    PDB_STATS getPdbStats(PDSTRUCT *pPdStruct);
    void test();
    QString tabString(qint32 nLevel);

private:
#ifdef Q_OS_WIN
    void _testSymbol(IDiaSymbol *pSymbol);
    quint32 getNumberOfChildren(IDiaSymbol *pSymbol);
    QString getSymbolName(IDiaSymbol *pSymbol);
    QString handleFunctionArgs(IDiaSymbol *pSymbol, OPTIONS *pOptions, qint32 nLevel);
    IDiaSymbol *getSymbolById(quint32 nId);
    ELEMTYPE handleType(quint32 nId, OPTIONS *pOptions);
    ELEMTYPE handleType(IDiaSymbol *pSymbol, OPTIONS *pOptions, qint32 nLevel = 0);
    QString elemTypeToString(ELEMTYPE elemType, OPTIONS *pOptions);
#endif
    void _addStringRecord(QString *pString, QList<TNODE> *pListNodes, qint32 nIndex, qint32 *pnLevel, OPTIONS *pOptions);
    qint32 _findTNodeByGuid(QList<TNODE> *pListNodes, QString sGUID);

private:
#ifdef Q_OS_WIN
    IDiaDataSource *g_pDiaDataSource;
    IDiaSession *g_pDiaSession;
    IDiaSymbol *g_pGlobal;
#endif
};

#endif  // XWINPDB_H
