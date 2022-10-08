#pragma once

#include "MDBSettingsModel.h"
#include <QException>

using net::draconia::mdb::model::MDBSettingsModel;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            class MDBApp;

            class AppNotConfiguredException : public QException
            {
            public:
                virtual QException *clone() const;
                virtual void raise() const;
            };

            class MDBController
            {
                MDBApp *mPtrApp;
                MDBSettingsModel *mPtrSettingsModel;
            public:
                MDBController(const MDBApp *ptrApp);
                MDBController(const MDBController &refCopy);
                MDBController(MDBController &refMove);
                ~MDBController();

                MDBApp &getApp() const;
                MDBSettingsModel &getSettingsModel();
            };
        }
    }
}
