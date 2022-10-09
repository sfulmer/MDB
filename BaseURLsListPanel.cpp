#include "BaseURLsDetailsPanel.h"
#include "BaseURLsListPanel.h"
#include "MDBApp.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

using net::draconia::mdb::MDBApp;
using namespace net::draconia::mdb::ui;

QPushButton *BaseURLsListPanel::getAddButton()
{
    if(mBtnAdd == nullptr)
        {
        mBtnAdd = new QPushButton("&Add", this);

        connect(mBtnAdd, &QPushButton::clicked, this, &BaseURLsListPanel::add);
        }

    return(mBtnAdd);
}

QListView *BaseURLsListPanel::getBaseURLsList()
{
    if(mLstBaseURLs == nullptr)
        {
        mLstBaseURLs = new QListView(this);

        connect(mLstBaseURLs->selectionModel(), SIGNAL(QItemSelectionModel::selectionChanged(const QItemSelection &, const QItemSelection &)), this, SLOT(BaseURLsListPanel::baseURLsSelectionChanged(const QItemSelection &, const QItemSelection &)));
        }

    return(mLstBaseURLs);
}

const MDBController &BaseURLsListPanel::getControler() const
{
    return(mRefController);
}

QWidget *BaseURLsListPanel::getCRUDButtonPanel()
{
    if(mPnlCRUD == nullptr)
        {
        mPnlCRUD = new QWidget(this);
        QLayout *layout = new QHBoxLayout(mPnlCRUD);

        layout->addWidget(getAddButton());
        layout->addWidget(getEditButton());
        layout->addWidget(getRemoveButton());

        mPnlCRUD->setLayout(layout);
        }

    return(mPnlCRUD);
}

QPushButton *BaseURLsListPanel::getEditButton()
{
    if(mBtnEdit == nullptr)
        {
        mBtnEdit = new QPushButton("&Edit", this);

        connect(mBtnEdit, &QPushButton::clicked, this, &BaseURLsListPanel::edit);
        }

    return(mBtnEdit);
}

QPushButton *BaseURLsListPanel::getMoveDownButton()
{
    if(mBtnMoveDown == nullptr)
        {
        mBtnMoveDown = new QPushButton("▼");

        connect(mBtnMoveDown, &QPushButton::clicked, this, &BaseURLsListPanel::moveDown);
        }

    return(mBtnMoveDown);
}

QPushButton *BaseURLsListPanel::getMoveUpButton()
{
    if(mBtnMoveUp == nullptr)
        {
        mBtnMoveUp = new QPushButton("▲");

        connect(mBtnMoveUp, &QPushButton::clicked, this, &BaseURLsListPanel::moveUp);
        }

    return(mBtnMoveUp);
}

QPushButton *BaseURLsListPanel::getRemoveButton()
{
    if(mBtnRemove == nullptr)
        {
        mBtnRemove = new QPushButton("&Remove", this);

        connect(mBtnRemove, &QPushButton::clicked, this, &BaseURLsListPanel::remove);
        }

    return(mBtnRemove);
}

QWidget *BaseURLsListPanel::getUpDownButtonPanel()
{
    if(mPnlUpDown == nullptr)
        {
        mPnlUpDown = new QWidget(this);
        QLayout *layout = new QVBoxLayout(mPnlUpDown);

        layout->addWidget(getMoveUpButton());
        layout->addWidget(getMoveDownButton());

        layout->setSpacing(-1);

        mPnlUpDown->setLayout(layout);
        }

    return(mPnlUpDown);
}

void BaseURLsListPanel::initControls()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(getBaseURLsList(), 0, 0, 1, 1, Qt::AlignCenter);
    layout->addWidget(getUpDownButtonPanel(), 0, 1, 1, 1, Qt::AlignCenter);
    layout->addWidget(getCRUDButtonPanel(), 1, 0, 1, 2, Qt::AlignCenter);

    setLayout(layout);
}

void BaseURLsListPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

void BaseURLsListPanel::add()
{
    static_cast<BaseURLsDetailsPanel *>(parentWidget())->setOriginalModel(BaseURL());
}

void BaseURLsListPanel::baseURLsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(selected);
    Q_UNUSED(deselected);
}

void BaseURLsListPanel::edit()
{ }

void BaseURLsListPanel::moveDown()
{ }

void BaseURLsListPanel::moveUp()
{ }

void BaseURLsListPanel::remove()
{ }

BaseURLsListPanel::BaseURLsListPanel(QWidget *parent)
    :   BaseURLsListPanel(parent, static_cast<MDBApp *>(qApp)->getController())
{ }

BaseURLsListPanel::BaseURLsListPanel(QWidget *parent, const MDBController &refController)
    :   QGroupBox("Base URLs:", parent)
    ,   mRefController(refController)
    ,   mLstBaseURLs(nullptr)
    ,   mBtnAdd(nullptr)
    ,   mBtnEdit(nullptr)
    ,   mBtnMoveDown(nullptr)
    ,   mBtnMoveUp(nullptr)
    ,   mBtnRemove(nullptr)
    ,   mPnlCRUD(nullptr)
    ,   mPnlUpDown(nullptr)
{
    initPanel();
}
