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
#include "xbinary.h"
#include "xwinpdb_def.h"

class XWinPDB: public XBinary
{
    Q_OBJECT

public:
    XWinPDB(QIODevice *pDevice);
    ~XWinPDB();

    bool loadMSDIALibrary(QString sFileName);
    bool loadFile(QString sFileName);
    virtual QString getName();
    void test();

private:
#ifdef Q_OS_WIN
    void _testSymbol(IDiaSymbol *pSymbol);
    QString _get_name(IDiaSymbol *pSymbol);
    QString _get_compilerName(IDiaSymbol *pSymbol);
#endif
private:
#ifdef Q_OS_WIN
    IDiaDataSource *g_pDiaDataSource;
    IDiaSession *g_pDiaSession;
    IDiaSymbol *g_pGlobal;
#endif
};

#endif // XWINPDB_H
