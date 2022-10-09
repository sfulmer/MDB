#include "BaseURLsTabPanel.h"
#include <QHBoxLayout>
#include "MDBApp.h"

using net::draconia::mdb::MDBApp;
using namespace net::draconia::mdb::ui;

const MDBController &BaseURLsTabPanel::getController() const
{
    return(mRefController);
}

QSplitter *BaseURLsTabPanel::getSplitter()
{
    if(mSplitter == nullptr)
        mSplitter = new QSplitter(this);

    return(mSplitter);
}

void BaseURLsTabPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getSplitter());

    setLayout(layout);
}

void BaseURLsTabPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

BaseURLsTabPanel::BaseURLsTabPanel(QWidget *parent)
    :   BaseURLsTabPanel(parent, static_cast<MDBApp *>(qApp)->getController())
{ }

BaseURLsTabPanel::BaseURLsTabPanel(QWidget *parent, const MDBController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mSplitter(nullptr)
{
    initPanel();
}
