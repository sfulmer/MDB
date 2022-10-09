#include "BaseURLsDetailsPanel.h"
#include "MDBApp.h"
#include <QFormLayout>
#include <QHBoxLayout>

using net::draconia::mdb::MDBApp;
using namespace net::draconia::mdb::ui;

void BaseURLsDetailsPanel::changeEvent(QEvent *ptrEvent)
{
    if(ptrEvent->type() == QEvent::EnabledChange)
        {
        getNameField()->setEnabled(isEnabled());
        getNameLabel()->setEnabled(isEnabled());
        getApplyButton()->setEnabled(isEnabled());
        getCancelButton()->setEnabled(isEnabled());
        getSaveButton()->setEnabled(isEnabled());
        getURLField()->setEnabled(isEnabled());
        getURLLabel()->setEnabled(isEnabled());
        }
}

QPushButton *BaseURLsDetailsPanel::getApplyButton()
{
    if(mBtnApply == nullptr)
        {
        mBtnApply = new QPushButton("&Apply", this);

        connect(mBtnApply, &QPushButton::clicked, this, &BaseURLsDetailsPanel::apply);
        }

    return(mBtnApply);
}

QWidget *BaseURLsDetailsPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        {
        mPnlButtons = new QWidget(this);
        QLayout *layout = new QHBoxLayout(mPnlButtons);

        layout->addWidget(getApplyButton());
        layout->addWidget(getCancelButton());
        layout->addWidget(getSaveButton());

        mPnlButtons->setLayout(layout);
        }

    return(mPnlButtons);
}

QPushButton *BaseURLsDetailsPanel::getCancelButton()
{
    if(mBtnCancel == nullptr)
        {
        mBtnCancel = new QPushButton("&Cancel", this);

        connect(mBtnCancel, &QPushButton::clicked, this, &BaseURLsDetailsPanel::cancel);
        }

    return(mBtnCancel);
}

const MDBController &BaseURLsDetailsPanel::getController()
{
    return(mRefController);
}

QLineEdit *BaseURLsDetailsPanel::getNameField()
{
    if(mTxtName == nullptr)
        {
        mTxtName = new QLineEdit(this);

        connect(mTxtName, SIGNAL(QLineEdit::textChanged(QString&)), this, SLOT(BaseURLsDetailsPanel::nameChanged(QString&)));
        }

    return(mTxtName);
}

QLabel *BaseURLsDetailsPanel::getNameLabel()
{
    if(mLblName == nullptr)
        {
        mLblName = new QLabel("&Name:", this);

        mLblName->setAutoFillBackground(false);
        mLblName->setBuddy(getNameField());
        }

    return(mLblName);
}

QPushButton *BaseURLsDetailsPanel::getSaveButton()
{
    if(mBtnSave == nullptr)
        {
        mBtnSave = new QPushButton("&Save", this);

        connect(mBtnSave, &QPushButton::clicked, this, &BaseURLsDetailsPanel::save);
        }

    return(mBtnSave);
}

QLineEdit *BaseURLsDetailsPanel::getURLField()
{
    if(mTxtURL == nullptr)
        {
        mTxtURL = new QLineEdit(this);

        connect(mTxtURL, SIGNAL(QLineEdit::textChanged(QString&)), this, SLOT(BaseURLsDetailsPanel::urlChanged(QString&)));
        }

    return(mTxtURL);
}

QLabel *BaseURLsDetailsPanel::getURLLabel()
{
    if(mLblURL == nullptr)
        {
        mLblURL = new QLabel("&URL:", this);

        mLblURL->setAutoFillBackground(false);
        mLblURL->setBuddy(getURLField());
        }

    return(mLblURL);
}

void BaseURLsDetailsPanel::initControls()
{
    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(getNameLabel(), getNameField());
    layout->addRow(getURLLabel(), getURLField());
    layout->addRow(getButtonPanel());

    setLayout(layout);
}

void BaseURLsDetailsPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();

    setEnabled(false);
}

void BaseURLsDetailsPanel::apply()
{ }

void BaseURLsDetailsPanel::cancel()
{ }

void BaseURLsDetailsPanel::nameChanged(const QString &sText)
{
    Q_UNUSED(sText);
}

void BaseURLsDetailsPanel::save()
{ }

void BaseURLsDetailsPanel::urlChanged(const QString &sText)
{
    Q_UNUSED(sText);
}

BaseURLsDetailsPanel::BaseURLsDetailsPanel(QWidget *parent)
    :   BaseURLsDetailsPanel(parent, static_cast<MDBApp *>(qApp)->getController())
{ }

BaseURLsDetailsPanel::BaseURLsDetailsPanel(QWidget *parent, const MDBController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mLblName(nullptr)
    ,   mLblURL(nullptr)
    ,   mTxtName(nullptr)
    ,   mTxtURL(nullptr)
    ,   mBtnApply(nullptr)
    ,   mBtnCancel(nullptr)
    ,   mBtnSave(nullptr)
    ,   mPnlButtons(nullptr)
{
    initPanel();
}

BaseURL &BaseURLsDetailsPanel::getModifiedModel()
{
    return(mObjModified);
}

BaseURL &BaseURLsDetailsPanel::getOriginalModel()
{
    return(mObjOriginal);
}

void BaseURLsDetailsPanel::setOriginalModel(const BaseURL &refModel)
{
    mObjOriginal = refModel;
    mObjModified = mObjOriginal.clone();

    setEnabled(true);

    getNameField()->setFocus();
}
