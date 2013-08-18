import logging
from PyQt4.QtCore import Qt

logColors = {
    logging.INFO : Qt.darkGreen,
    logging.WARN : Qt.black,
    logging.ERROR : Qt.darkRed
}

class QTextEditHandler(logging.Handler):
    def __init__(self, textEdit = None):
        logging.Handler.__init__(self)
        self.textEdit=textEdit
        self.level = logging.DEBUG

    def flush(self):
        """
        does nothing for this handler.
        """

    def emit(self, record):
        msg = self.format(record)
        textColor = logColors.get(record.levelno, Qt.black)
        self.textEdit.setColor(textColor)
        self.textEdit.append(msg)
