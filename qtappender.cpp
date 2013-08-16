#include "qtappender.h"

IMPLEMENT_LOG4CXX_OBJECT(QtAppender)

void QtAppender::append(const log4cxx::spi::LoggingEventPtr& event, log4cxx::helpers::Pool& p) {

    textEdit->append(QString::fromStdString(event->getMessage()));

}

void QtAppender::close() {
  closed = true;
}
