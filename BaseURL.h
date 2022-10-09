#pragma once

#include "Observable.h"
#include <QString>
#include <QUrl>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace model
            {
                class BaseURL : public Observable
                {
                    QString msName;
                    QUrl mObjURL;
                public:
                    BaseURL();
                    BaseURL(const QUrl &url);
                    BaseURL(const QUrl &url, const QString &sName);

                    const QString &getName() const;
                    const QUrl &getURL() const;
                    void setName(const QString &sName);
                    void setURL(const QUrl &url);

                    BaseURL &operator=(const BaseURL &refCopy);
                    bool operator==(const BaseURL &refOther);
                    bool operator!=(const BaseURL &refOther);

                    BaseURL clone() const;
                };
            }
        }
    }
}
