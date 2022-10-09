#pragma once

#include "MDBController.h"
#include "MDBMainWindow.h"
#include <QApplication>
#include <QList>

using net::draconia::mdb::ui::MDBMainWindow;

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            class MDBApp : public QApplication
            {
                MDBController *mPtrController;
                MDBMainWindow mWndMain;
                QList<QString> mLstArgs;
            protected:
                const QList<QString> getArgs() const;
                void setCmdLineArgs(const int argc, const char **argv);
                void setCmdLineArgs(const int argc, const wchar_t **argv);
                void setCmdLineArgs(const QList<QString> &args);
                void showMainWindow();
            public:
                MDBApp(int &argc, const char **argv);
                ~MDBApp();

                int exec();
                MDBController &getController();
                MDBMainWindow &getMainWindow() const;
            };
        }
    }
}
