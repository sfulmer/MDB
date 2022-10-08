#pragma once

#include <QLabel>
#include <QListView>
#include <QWidget>

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace ui
            {
                class MDBSettingsDialog;

                class MDBSettingsBaseURLsListPanel : public QWidget
                {
                    Q_OBJECT

                    QLabel *mLblBaseURLs;
                    QListView *mLstBaseURLs;
                protected:
                    QLabel *getBaseURLLabel();
                    QListView *getBaseURLsList();
                    void initControls();
                    void initPanel();
                public:
                    MDBSettingsBaseURLsListPanel(MDBSettingsDialog *parent);
                    ~MDBSettingsBaseURLsListPanel();
                signals:
                };
            }
        }
    }
}
