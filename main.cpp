#include <QtGui/QApplication>
#include "mainwindow.h"

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>

using namespace log4cxx;
using namespace log4cxx::helpers;
LoggerPtr logger(Logger::getLogger("QtLogging"));

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "UTF-8");
    BasicConfigurator::configure();
    LOG4CXX_INFO(logger, "Entering application.");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
        
    return a.exec();

}
