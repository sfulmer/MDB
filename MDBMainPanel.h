#pragma once

#include <QWidget>

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
                protected:
                    void initControls();
                    void initPanel();
                public:
                    MDBMainPanel(QWidget *parent);
                };
            }
        }
    }
}

