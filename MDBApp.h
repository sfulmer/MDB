#pragma once

#include "MDBController.h"
#include "MDBMainWindow.h"
#include <QApplication>
#include <QList>

namespace net
{
    namespace draconia
    {
        namespace mdb
        {
            class MDBApp : public QApplication
            {
                MDBMainWindow mWndMain;
                QList<QString> mLstArgs;
            protected:
                const QList<QString> getArgs() const;
                void setCmdLineArgs(const int argc, const char **argv);
                void setCmdLineArgs(const int argc, const wchar_t **argv);
                void setCmdLineArgs(const QList<QString> &args);
                void showMainWindow();
            public:
                MDBApp(const int argc, const char **argv);
                ~MDBApp();

                int exec();
                MDBMainWindow &getMainWindow() const;
            };
        }
    }
}
