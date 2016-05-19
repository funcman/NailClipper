#ifndef NCMAINWINDOW_H
#define NCMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class ncMainWindow;
}

class ncMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ncMainWindow(QWidget* parent=0);
    ~ncMainWindow();

private:
    Ui::ncMainWindow* ui;
};

#endif//NCMAINWINDOW_H
