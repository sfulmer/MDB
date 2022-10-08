#pragma once

#include <QDialog>
#include <QLabel>
#include <QListView>
#include <QSplitter>

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace ui
            {
                class MDBSettingsDialog : public QDialog
                {
                    Q_OBJECT
                    QSplitter *mPnlSplitter;
                protected:
                    QSplitter *getSplitterPanel();
                    void initControls();
                    void initDialog();
                public:
                    MDBSettingsDialog(const QWidget *parent);
                    ~MDBSettingsDialog();
                };
            }
        }
    }
}
