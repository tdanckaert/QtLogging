#!/usr/bin/python

import sys
from PyQt4 import QtGui, uic
from PyQt4.QtCore import SIGNAL
import logging

import QTextEditHandler

class PyQtLogging(QtGui.QMainWindow):

    def __init__(self):
        self.logger = logging.getLogger('PyQtLogging')
        QtGui.QMainWindow.__init__(self)
        self.ui = uic.loadUi('mainwindow.ui', self)
        self.logger.info('UI Loaded.')

        # add handler to display logging information in the GUI
        handler = QTextEditHandler.QTextEditHandler(self.textEdit)
        self.logger.addHandler(handler)

        self.infoButton.clicked.connect(self.info)
        self.warnButton.clicked.connect(self.warn)
        self.errorButton.clicked.connect(self.error)

        # connect 'Quit' action
        self.actionQuit.triggered.connect(QtGui.qApp.quit)
        self.actionQuit.setShortcut('Ctrl+Q')
        self.actionQuit.setStatusTip('Exit application')

        self.show()

    def info(self):
        self.logger.info('This is just an informational message.')

    def warn(self):
        self.logger.warn('Warning! Warning!')

    def error(self):
        self.logger.error('Alarm! Alarm!')

def main():
    logging.basicConfig(level=logging.INFO)
    logging.info('Entering application.')
    app = QtGui.QApplication(sys.argv)
    window = PyQtLogging()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
