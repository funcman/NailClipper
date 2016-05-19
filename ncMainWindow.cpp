#include "ncMainWindow.h"
#include "ui_ncMainWindow.h"
#include <QUrl>
#include <QDesktopServices>

ncMainWindow::ncMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ncMainWindow) {
    ui->setupUi(this);
}

ncMainWindow::~ncMainWindow() {
    delete ui;
}

void ncMainWindow::on_actionGitHub_triggered() {
    QUrl url("https://github.com/funcman/NailClipper");
    QDesktopServices::openUrl(url);
}
