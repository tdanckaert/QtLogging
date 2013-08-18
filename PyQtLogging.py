#!/usr/bin/python

import sys
from os import path
from PyQt4 import QtGui, uic

import logging

import QTextEditHandler

class PyQtLogging(QtGui.QMainWindow):

    logger = logging.getLogger('PyQtLogging')

    def __init__(self):

        PyQtLogging.logger = logging.getLogger('PyQtLogging')
        QtGui.QMainWindow.__init__(self)
        modulePath = path.dirname(path.realpath(__file__))
        self.ui = uic.loadUi(modulePath + '/mainwindow.ui', self)

        # add handler to display logging information in the GUI
        handler = QTextEditHandler.QTextEditHandler(self.textEdit)
        PyQtLogging.logger.addHandler(handler)

        self.infoButton.clicked.connect(self.info)
        self.warnButton.clicked.connect(self.warn)
        self.errorButton.clicked.connect(self.error)

        # connect 'Quit' action
        self.actionQuit.triggered.connect(QtGui.qApp.quit)
        self.actionQuit.setShortcut('Ctrl+Q')
        self.actionQuit.setStatusTip('Exit application')

        self.show()
        PyQtLogging.logger.info('UI Loaded.')

    def info(self):
        PyQtLogging.logger.info('This is just an informational message.')

    def warn(self):
        PyQtLogging.logger.warn('Warning! Warning!')

    def error(self):
        PyQtLogging.logger.error('Alarm! Alarm!')

def main():
    logging.basicConfig(level=logging.INFO)
    logging.info('Entering application.')
    app = QtGui.QApplication(sys.argv)
    window = PyQtLogging()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
