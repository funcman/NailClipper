#include "ncMainWindow.h"
#include "ui_ncMainWindow.h"

ncMainWindow::ncMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ncMainWindow) {
    ui->setupUi(this);
}

ncMainWindow::~ncMainWindow() {
    delete ui;
}
