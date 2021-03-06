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

protected:
    virtual void showEvent(QShowEvent*);

private slots:
    void on_actionGitHub_triggered();

private:
    Ui::ncMainWindow* ui;
};

#endif//NCMAINWINDOW_H
