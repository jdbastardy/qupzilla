/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2013  Mattias Cibien <mattias@mattiascibien.net>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef IEIMPORTER_H
#define IEIMPORTER_H

#include <QObject>

#include "qz_namespace.h"
#include "bookmarksmodel.h"

#include <QFileInfoList>

class IeImporter : public QObject
{
    Q_OBJECT
public:
    explicit IeImporter(QObject* parent = 0);

    void setFile(const QString &path);
    bool openFile();

    QVector<BookmarksModel::Bookmark> exportBookmarks();

    bool error() { return m_error; }
    QString errorString() { return m_errorString; }


private:
    bool m_error;
    QString m_errorString;
    QString m_path;

    QFileInfoList urls;
};

#endif // IEIMPORTER_H
