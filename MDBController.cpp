#include "MDBApp.h"
#include "MDBController.h"

using namespace net::draconia::mdb;

QException *AppNotConfiguredException::clone() const
{
    return(new AppNotConfiguredException());
}

void AppNotConfiguredException::raise() const
{
    throw *this;
}

MDBController::MDBController(const MDBApp *ptrApp)
    :   mPtrApp(const_cast<MDBApp *>(ptrApp))
    ,   mPtrSettingsModel(nullptr)
{ }

MDBController::MDBController(const MDBController &refCopy)
    :   MDBController(&(refCopy.getApp()))
{ }

MDBController::MDBController(MDBController &refMove)
    :   MDBController(&(refMove.getApp()))
{ }

MDBController::~MDBController()
{
    if(mPtrApp != nullptr)
        delete mPtrApp;
    if(mPtrSettingsModel != nullptr)
        delete mPtrSettingsModel;
}

MDBApp &MDBController::getApp() const
{
    if(mPtrApp == nullptr)
        throw AppNotConfiguredException();

    return(*mPtrApp);
}

MDBSettingsModel &MDBController::getSettingsModel()
{
    if(mPtrSettingsModel == nullptr)
        mPtrSettingsModel = new MDBSettingsModel();

    return(*mPtrSettingsModel);
}
