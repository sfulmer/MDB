#include "MDBApp.h"

using net::draconia::mdb::MDBApp;

int main(int argc, char **argv)
{
    MDBApp a(argc, const_cast<const char **>(argv));

    return(a.exec());
}
