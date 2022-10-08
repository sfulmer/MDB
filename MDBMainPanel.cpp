#include "MDBMainPanel.h"

using namespace net::draconia::mdb::ui;

void MDBMainPanel::initControls()
{ }

void MDBMainPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

MDBMainPanel::MDBMainPanel(QWidget *parent)
