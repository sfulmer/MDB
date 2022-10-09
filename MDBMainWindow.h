#pragma once

#include "MDBController.h"
#include "MDBMainPanel.h"
#include <QMainWindow>

using net::draconia::mdb::MDBController;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace ui
            {
                class MDBMainWindow : public QMainWindow
                {
                    Q_OBJECT

                    const MDBController &mRefController;
                    MDBMainPanel *mPnlMain;
                protected:
                    const MDBController &getController() const;
                    MDBMainPanel *getMainPanel();
                    void initControls();
                    void initMenus();
                    void initWindow();
                public:
                    explicit MDBMainWindow(QWidget *parent = nullptr);
                    MDBMainWindow(QWidget *parent, const MDBController &refController);
                };
            }
        }
    }
}
