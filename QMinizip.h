/*
--------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2015 Ralph-Gordon Paul. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
--------------------------------------------------------------------------------
*/

#include <QObject>
#include <QFile>

namespace rgp {

class QMinizip : QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList *unzippedFiles READ unzippedFiles)
    Q_PROPERTY(QStringList *zipFileContents READ zipFileContents)
public:
    explicit QMinizip(QObject *parent = 0);
    ~QMinizip();
    
    // accessors
    QStringList *unzippedFiles() const;
    QStringList *zipFileContents() const;
    
    // zip
    Q_INVOKABLE bool createZipFile(QString *file, QString *password = nullptr);
    Q_INVOKABLE bool addFileToZip(QString *file, QString *newname);
    Q_INVOKABLE bool closeZipFile();

    // unzip
    Q_INVOKABLE bool openUnzipFile(QString *file, QString *password = nullptr);
    Q_INVOKABLE bool unzipFilesTo(QString *path, bool overwrite = false);
    Q_INVOKABLE bool closeUnzipFile();

signals:
    void error(QString message);
    
public slots:
    
private:
    QFile *m_zipFile { nullptr };
    QFile *m_unzipFile { nullptr };
    QString *m_password { nullptr };
    
    QStringList *m_unzippedFiles { nullptr };
};
} // namespace rgp