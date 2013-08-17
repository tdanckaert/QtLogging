#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtappender.h"

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>

LoggerPtr MainWindow::logger(Logger::getLogger("QtLogging.MainWindow"));

QtAppender *app;

unsigned int messagecounter = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    app = new QtAppender(ui->textEdit);
    BasicConfigurator::configure(log4cxx::AppenderPtr(app));
    ui->textEdit->document()->setMaximumBlockCount(200);

    LOG4CXX_INFO(logger, "UI Ready.");

}

MainWindow::~MainWindow()
{

    delete ui;

    LOG4CXX_INFO(logger, "UI Closed.");
}

void MainWindow::on_errorButton_clicked()
{
    LOG4CXX_ERROR(logger, "Alarm! Alarm!");
}

void MainWindow::on_warnButton_clicked()
{
    LOG4CXX_WARN(logger, "Warning! Warning!");
}

void MainWindow::on_infoButton_clicked()
{
    LOG4CXX_INFO(logger, "Just an informational message. ");
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
