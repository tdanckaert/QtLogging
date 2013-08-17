#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <log4cxx/logger.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    static log4cxx::LoggerPtr logger;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_errorButton_clicked();

    void on_warnButton_clicked();

    void on_infoButton_clicked();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
