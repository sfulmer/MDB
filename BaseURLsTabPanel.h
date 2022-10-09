#pragma once

#include "MDBController.h"
#include <QSplitter>
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
                class BaseURLsTabPanel : public QWidget
                {
                    Q_OBJECT

                    const MDBController &mRefController;
                    QSplitter *mSplitter;
                protected:
                    const MDBController &getController() const;
                    QSplitter *getSplitter();
                    void initControls();
                    void initPanel();
                public:
                    explicit BaseURLsTabPanel(QWidget *parent = nullptr);
                    BaseURLsTabPanel(QWidget *parent, const MDBController &refController);
                };
            }
        }
    }
}
