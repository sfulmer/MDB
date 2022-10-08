#include "MDBSettingsDialog.h"
#include <QHBoxLayout>

using namespace net::draconia::mdb::ui;

QSplitter *MDBSettingsDialog::getSplitterPanel()
{
    if(mPnlSplitter == nullptr)
        {
        mPnlSplitter = new QSplitter(Qt::Horizontal, this);
        }

    return(mPnlSplitter);
}

void MDBSettingsDialog::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getSplitterPanel());

    setLayout(layout);
}

void MDBSettingsDialog::initDialog()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

MDBSettingsDialog::MDBSettingsDialog(const QWidget *parent)
    :   QDialog(const_cast<QWidget *>(parent), Qt::Dialog)
    ,   mPnlSplitter(nullptr)
{ }

MDBSettingsDialog::~MDBSettingsDialog()
{ }
