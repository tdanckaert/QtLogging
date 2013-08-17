#include "qtappender.h"

IMPLEMENT_LOG4CXX_OBJECT(QtAppender)

void QtAppender::append(const log4cxx::spi::LoggingEventPtr& event, log4cxx::helpers::Pool& p) {

    switch(event->getLevel()->toInt()) {
    case log4cxx::Level::ERROR_INT:
        textEdit->setTextColor(Qt::red);
        break;
    case log4cxx::Level::WARN_INT:
        textEdit->setTextColor(Qt::black);
        break;
    case log4cxx::Level::INFO_INT:
        textEdit->setTextColor(Qt::darkGreen);
    }

    textEdit->append(QString::fromStdString(event->getMessage()));

}

void QtAppender::close() {
  closed = true;
}
