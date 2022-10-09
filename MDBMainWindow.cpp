#include "MDBApp.h"
#include "MDBMainWindow.h"

using net::draconia::mdb::MDBApp;
using namespace net::draconia::mdb::ui;

const MDBController &MDBMainWindow::getController() const
{
    return(mRefController);
}

MDBMainPanel *MDBMainWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        mPnlMain = new MDBMainPanel(this, getController());

    return(mPnlMain);
}

void MDBMainWindow::initControls()
{
    setCentralWidget(getMainPanel());
}

void MDBMainWindow::initMenus()
{ }

void MDBMainWindow::initWindow()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initMenus();
    initControls();
}

MDBMainWindow::MDBMainWindow(QWidget *parent)
    :   MDBMainWindow(parent, static_cast<MDBApp *>(qApp)->getController())
{ }

MDBMainWindow::MDBMainWindow(QWidget *parent, const MDBController &refController)
    :   QMainWindow(parent)
    ,   mRefController(refController)
    ,   mPnlMain(nullptr)
{
    initWindow();
}
