#include "MDBApp.h"
#include "MDBMainPanel.h"

using net::draconia::mdb::MDBApp;
using namespace net::draconia::mdb::ui;

const MDBController &MDBMainPanel::getController() const
{
    return(mRefController);
}

void MDBMainPanel::initControls()
{ }

void MDBMainPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

MDBMainPanel::MDBMainPanel(QWidget *parent)
    :   MDBMainPanel(parent, static_cast<MDBApp *>(qApp)->getController())
{ }

MDBMainPanel::MDBMainPanel(QWidget *parent, const MDBController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
{
    initPanel();
}
