#!/usr/bin/python
# -*- coding: utf-8 -*-

from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg
from pyqtgraph.ptime import time
from serial import *

app = QtGui.QApplication([])
serialPort = "/dev/ttyUSB0"
baudRate = 115200
ser = Serial(serialPort , baudRate, timeout=None, writeTimeout=0) #ensure non-blocking

#RAUL
plot_x = [];	# Vector de donde almacenamos los datos recibidos por serial
loopcount = 0;	# Indice del bucle actual: Usado para fijar el eje horizontal del plot
RangoEjeX = 500; # Rango del eje horizontal
RangoEjeY = 400; # Rango del eje horizontal
    

pg.mkQApp()
pw = pg.PlotWidget()
pw.show()
p1 = pw.plotItem
p2 = pg.ViewBox()
p1.showAxis('right')
p1.scene().addItem(p2)
p2.setGeometry(p1.vb.sceneBoundingRect())
p2.setXLink(p1)
pw.setWindowTitle("envio serial cuadcopter")
p1.setYRange(0,RangoEjeY);


def update():
    global pw, pg, loopcount, plot_x,plot_y,p1,p2
    if(loopcount < RangoEjeX):
        p1.setXRange(0, RangoEjeX)
    else:
        p1.setXRange(loopcount-RangoEjeX, loopcount)
    p1.plot(plot_x,pen='b')
    line = ser.readline()
    print int (line)
    plot_x.append(int(line))
    loopcount = loopcount + 1
    
timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(50)

#FIN RAUL




#def update():
#    global curve, data
#    line = ser.readline()
#    data.append(int(line))
#    xdata = np.array(data, dtype='float64')
#    curve.setData(xdata)
#    app.processEvents()

#timer = QtCore.QTimer()
#timer.timeout.connect(update)
#timer.start(0)

if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()
