#include "MDBMainWindow.h"

using namespace net::draconia::mdb::ui;

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
    :   QMainWindow(parent)
    ,   mPnlMain(nullptr)
{
    initWindow();
}
}

MDBMainWindow::~MDBMainWindow()
{ }
