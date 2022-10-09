#pragma once

#include "BaseURL.h"
#include <QList>
#include <QUrl>

using net::draconia::mdb::model::BaseURL;
using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace model
            {
                class MDBSettingsModel : public Observable
                {
                    QList<BaseURL> mLstBaseURLs;
                protected:
                    QList<BaseURL> &getBaseURLsInternal() const;
                public:
                    MDBSettingsModel();
                    MDBSettingsModel(QList<BaseURL> &lstURLs);
                    MDBSettingsModel(const MDBSettingsModel &refCopy);

                    void addBaseURL(const BaseURL &urlBase);
                    void addBaseURLs(const QList<BaseURL> &lstBaseURLs);
                    void clearBaseURLs();
                    const QList<BaseURL> &getBaseURLs() const;
                    void removeBaseURL(const BaseURL &urlBase);
                    void removeBaseURL(const QUrl &urlBase);
                    void removeBaseURLs(const QList<BaseURL> &lstBaseURLs);
                    void setBaseURLs(const QList<BaseURL> &lstBaseURLs);
                };
            }
        }
    }
}
