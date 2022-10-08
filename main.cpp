#include "MDBMainWindow.h"

#include "MDBApp.h"

using net::draconia::mdb::MDBApp;

int main(int argc, char *argv[])
{
    MDBApp app(argc, argv);

    return(app.exec());
}
