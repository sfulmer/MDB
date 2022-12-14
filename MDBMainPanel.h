#pragma once

#include "MDBController.h"
#include <QWidget>

using net::draconia::mdb::MDBController;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace ui
            {
                class MDBMainPanel : public QWidget
                {
                    Q_OBJECT
                    const MDBController &mRefController;
                protected:
                    const MDBController &getController() const;
                    void initControls();
                    void initPanel();
                public:
                    explicit MDBMainPanel(QWidget *parent);
                    MDBMainPanel(QWidget *parent, const MDBController &refController);
                };
            }
        }
    }
}

