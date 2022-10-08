#pragma once

#include "Observable.h"
#include <QList>
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
                class MDBSettingsModel : public Observable
                {
                    QList<QUrl> mLstBaseURLs;
                protected:
                    QList<QUrl> &getBaseURLsInternal() const;
                public:
                    MDBSettingsModel();
                    MDBSettingsModel(const MDBSettingsModel &refCopy);
                    MDBSettingsModel(MDBSettingsModel &refMove);
                    ~MDBSettingsModel();

                    void addBaseURL(const QUrl &urlBase);
                    void addBaseURLs(const QList<QUrl> &lstBaseURLs);
                    void clearBaseURLs();
                    const QList<QUrl> &getBaseURLs() const;
                    void removeBaseURL(const QUrl &urlBase);
                    void removeBaseURLs(const QList<QUrl> &lstBaseURLs);
                    void setBaseURLs(const QList<QUrl> &lstBaseURLs);
                };
            }
        }
    }
}
