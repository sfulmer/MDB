#include "MDBSettingsModel.h"

using namespace net::draconia::mdb::model;

QList<QUrl> &MDBSettingsModel::getBaseURLsInternal() const
{
    return(const_cast<MDBSettingsModel &>(*this).mLstBaseURLs);
}

MDBSettingsModel::MDBSettingsModel()
    :   Observable()
{ }

MDBSettingsModel::MDBSettingsModel(const MDBSettingsModel &refCopy)
    :   Observable()
    ,   mLstBaseURLs(refCopy.getBaseURLs())
{ }

MDBSettingsModel::MDBSettingsModel(MDBSettingsModel &refMove)
    :   Observable()
    ,   mLstBaseURLs(refMove.getBaseURLs())
{ }

MDBSettingsModel::~MDBSettingsModel()
{ }

void MDBSettingsModel::addBaseURL(const QUrl &urlBase)
{
    getBaseURLsInternal().append(urlBase);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::addBaseURLs(const QList<QUrl> &lstBaseURLs)
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

const QList<QUrl> &MDBSettingsModel::getBaseURLs() const
{
    return(getBaseURLsInternal());
}

void MDBSettingsModel::removeBaseURL(const QUrl &urlBase)
{
    getBaseURLsInternal().removeOne(urlBase);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::removeBaseURLs(const QList<QUrl> &lstBaseURLs)
{
    for(const QUrl &url : lstBaseURLs)
        getBaseURLsInternal().removeOne(url);

    setChanged();
    notifyObservers("BaseURLs");
}

void MDBSettingsModel::setBaseURLs(const QList<QUrl> &lstBaseURLs)
{
    mLstBaseURLs = lstBaseURLs;

    setChanged();
    notifyObservers("BaseURLs");
}
