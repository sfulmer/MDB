#pragma once

#include <QMainWindow>

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

                    MDBMainPanel *mPnlMain;
                protected:
                    void initControls();
                    void initMenus();
                    void initWindow();
                public:
                    MDBMainWindow(QWidget *parent = nullptr);
                    ~MDBMainWindow();
                };
            }
        }
    }
}
