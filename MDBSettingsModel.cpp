#include "MDBSettingsModel.h"

using namespace net::draconia::mdb::model;

QList<BaseURL> &MDBSettingsModel::getBaseURLsInternal() const
{
    return(const_cast<MDBSettingsModel &>(*this).mLstBaseURLs);
}

MDBSettingsModel::MDBSettingsModel()
    :   Observable()
{ }

MDBSettingsModel::MDBSettingsModel(QList<BaseURL> &lstURLs)
    :   Observable()
    ,   mLstBaseURLs(lstURLs)
{ }

MDBSettingsModel::MDBSettingsModel(const MDBSettingsModel &refCopy)
    :   MDBSettingsModel(const_cast<QList<BaseURL> &>(refCopy.getBaseURLs()))
{ }

void MDBSettingsModel::addBaseURL(const BaseURL &urlBase)
{
    getBaseURLsInternal().append(urlBase);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::addBaseURLs(const QList<BaseURL> &lstBaseURLs)
{
    getBaseURLsInternal().append(lstBaseURLs);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::clearBaseURLs()
{
    getBaseURLsInternal().clear();

    setChanged();
    notifyObservers("BaseURLs");
}

const QList<BaseURL> &MDBSettingsModel::getBaseURLs() const
{
    return(getBaseURLsInternal());
}

void MDBSettingsModel::removeBaseURL(const BaseURL &urlBase)
{
    getBaseURLsInternal().removeOne(urlBase);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::removeBaseURL(const QUrl &urlBase)
{
    for(BaseURL &url : getBaseURLsInternal())
        if(url.getURL() == urlBase)
            {
            getBaseURLsInternal().removeOne(url);

            setChanged();
            notifyObservers("BaseURLs");

            break;
            }
}

void MDBSettingsModel::removeBaseURLs(const QList<BaseURL> &lstBaseURLs)
{
    for(const BaseURL &url : lstBaseURLs)
        getBaseURLsInternal().removeOne(url);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::setBaseURLs(const QList<BaseURL> &lstBaseURLs)
{
    mLstBaseURLs = lstBaseURLs;

    setChanged();
    notifyObservers("BaseURLs");
}
