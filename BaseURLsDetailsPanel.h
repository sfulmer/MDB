#pragma once

#include "BaseURL.h"
#include "MDBController.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

using net::draconia::mdb::MDBController;
using net::draconia::mdb::model::BaseURL;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            namespace ui
            {
                class BaseURLsDetailsPanel : public QWidget
                {
                    Q_OBJECT

                    BaseURL mObjModified, mObjOriginal;
                    const MDBController &mRefController;
                    QLabel *mLblName, *mLblURL;
                    QLineEdit *mTxtName, *mTxtURL;
                    QPushButton *mBtnApply, *mBtnCancel, *mBtnSave;
                    QWidget *mPnlButtons;
                protected:
                    virtual void changeEvent(QEvent *event);
                    QPushButton *getApplyButton();
                    QWidget *getButtonPanel();
                    QPushButton *getCancelButton();
                    const MDBController &getController();
                    QLineEdit *getNameField();
                    QLabel *getNameLabel();
                    QPushButton *getSaveButton();
                    QLineEdit *getURLField();
                    QLabel *getURLLabel();
                    void initControls();
                    void initPanel();
                protected slots:
                    void apply();
                    void cancel();
                    void nameChanged(const QString &sText);
                    void save();
                    void urlChanged(const QString &sText);
                public:
                    explicit BaseURLsDetailsPanel(QWidget *parent = nullptr);
                    BaseURLsDetailsPanel(QWidget *parent, const MDBController &refController);

                    BaseURL &getModifiedModel();
                    BaseURL &getOriginalModel();
                    void setOriginalModel(const BaseURL &refModel);
                };
            }
        }
    }
}
