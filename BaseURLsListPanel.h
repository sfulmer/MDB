#pragma once

#include "MDBController.h"
#include <QGroupBox>
#include <QListView>
#include <QPushButton>

using net::draconia::mdb::MDBController;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace ui
            {
                class BaseURLsListPanel : public QGroupBox
                {
                    Q_OBJECT

                    const MDBController &mRefController;
                    QListView *mLstBaseURLs;
                    QPushButton *mBtnAdd, *mBtnEdit;
                    QPushButton *mBtnMoveDown, *mBtnMoveUp;
                    QPushButton *mBtnRemove;
                    QWidget *mPnlCRUD, *mPnlUpDown;
                protected:
                    QPushButton *getAddButton();
                    QListView *getBaseURLsList();
                    const MDBController &getControler() const;
                    QWidget *getCRUDButtonPanel();
                    QPushButton *getEditButton();
                    QPushButton *getMoveDownButton();
                    QPushButton *getMoveUpButton();
                    QPushButton *getRemoveButton();
                    QWidget *getUpDownButtonPanel();
                    void initControls();
                    void initPanel();
                protected slots:
                    void add();
                    void baseURLsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
                    void edit();
                    void moveDown();
                    void moveUp();
                    void remove();
                public:
                    explicit BaseURLsListPanel(QWidget *parent = nullptr);
                    BaseURLsListPanel(QWidget *parent, const MDBController &refController);
                };
            }
        }
    }
}
