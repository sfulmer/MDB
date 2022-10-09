#include "MDBApp.h"

using namespace net::draconia::mdb;

const QList<QString> MDBApp::getArgs() const
{
    return(mLstArgs);
}

void MDBApp::setCmdLineArgs(const int argc, const char **argv)
{
    QList<QString> lstArgs;

    for(unsigned uiLength = argc, uiLoop = 0; uiLoop < uiLength; uiLoop++)
        lstArgs.append(argv[uiLoop]);

    setCmdLineArgs(lstArgs);
}

void MDBApp::setCmdLineArgs(const int argc, const wchar_t **argv)
{
    QList<QString> lstArgs;

    for(unsigned uiLength = argc, uiLoop = 0; uiLoop < uiLength; uiLoop++)
        lstArgs.append(QString::fromWCharArray(argv[uiLoop]));
}

void MDBApp::setCmdLineArgs(const QList<QString> &args)
{
    mLstArgs = args;
}

void MDBApp::showMainWindow()
{
    getMainWindow().show();
}

MDBApp::MDBApp(int &argc, const char **argv)
    :   QApplication(argc, const_cast<char **>(argv))
    ,   mPtrController(nullptr)
{
    setCmdLineArgs(argc, argv);
}

MDBApp::~MDBApp()
{ }

int MDBApp::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

MDBController &MDBApp::getController()
{
    if(mPtrController == nullptr)
        mPtrController = new MDBController(this);

    return(*mPtrController);
}

MDBMainWindow &MDBApp::getMainWindow() const
{
    return(const_cast<MDBApp &>(*this).mWndMain);
}
