#ifndef QTAPPENDER_H
#define QTAPPENDER_H

#include <Qt/qtextbrowser.h>

#include <log4cxx/appenderskeleton.h>
#include <log4cxx/spi/loggingevent.h>

using namespace log4cxx;

class QtAppender : public log4cxx::AppenderSkeleton
{
public:
  DECLARE_LOG4CXX_OBJECT(QtAppender)
  BEGIN_LOG4CXX_CAST_MAP()
  LOG4CXX_CAST_ENTRY(QtAppender)
  LOG4CXX_CAST_ENTRY_CHAIN(AppenderSkeleton)
  END_LOG4CXX_CAST_MAP()

  /**
     This method is called by the AppenderSkeleton#doAppend
     method.
  */
  void append(const log4cxx::spi::LoggingEventPtr& event, log4cxx::helpers::Pool& p);

  void close();

  bool isClosed() const
  { return closed; };

  bool requiresLayout() const { return false;   };

  QtAppender() {
  };

  QtAppender(QTextEdit *t) :
      textEdit(t) {};

private:
  QTextEdit *textEdit;

};
typedef log4cxx::helpers::ObjectPtrT<QtAppender> QtAppenderPtr;

#endif // QTAPPENDER_H
