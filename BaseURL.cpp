#include "BaseURL.h"

using namespace net::draconia::mdb::model;

BaseURL::BaseURL()
    :   Observable()
{ }

BaseURL::BaseURL(const QUrl &url)
    :   Observable()
    ,   mObjURL(url)
{ }

BaseURL::BaseURL(const QUrl &url, const QString &sName)
    :   Observable()
    ,   msName(sName)
    ,   mObjURL(url)
{ }

const QString &BaseURL::getName() const
{
    return(msName);
}

const QUrl &BaseURL::getURL() const
{
    return(mObjURL);
}

void BaseURL::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void BaseURL::setURL(const QUrl &url)
{
    mObjURL = url;

    setChanged();
    notifyObservers("URL");
}

BaseURL &BaseURL::operator=(const BaseURL &refCopy)
{
    setName(refCopy.getName());
    setURL(refCopy.getURL());

    return(*this);
}

bool BaseURL::operator==(const BaseURL &refOther)
{
    return((getName() == refOther.getName()) && (getURL() == refOther.getURL()));
}

bool BaseURL::operator!=(const BaseURL &refOther)
{
    return(!operator==(refOther));
}

BaseURL BaseURL::clone() const
{
    return(BaseURL(getURL(), getName()));
}
