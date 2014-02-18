
from Tkinter import *
import Tkinter as tk
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import tkMessageBox
import Tkinter
import time,random
from serial import *


try:
    serialPort = "/dev/ttyUSB0"
    baudRate = 9600
    ser = Serial(serialPort , baudRate, timeout=None, writeTimeout=0) #ensure non-blocking
except Exception, e:
    print "No connection to the device could be established"
    tkMessageBox.showinfo( "puerto no abierto", "Error abrir el puerto")


window= tk.Tk()
# width x height + x_offset + y_offset:
window.geometry("500x500+30+30") 
window.title('Configurando pid')
CheckVar0 = IntVar()
CheckVar1 = IntVar()
CheckVar2 = IntVar()


#configuramos cuadro y log de recepcion
log_rece = Text(window, width=30, height=30, takefocus=0)
log_rece.place(x = 30, y = 170, width=210, height=300)
scrollbar_rece = Scrollbar(log_rece)
scrollbar_rece.pack(side=RIGHT, fill=Y)
log_rece.config(yscrollcommand=scrollbar_rece.set)
scrollbar_rece.config(command=log_rece.yview)
serBuffer = ""

#configuramos cuadro y log de recepcion
log_envio = Text(window, width=30, height=30, takefocus=0)
log_envio.place(x = 260, y = 170, width=210, height=300)
scrollbar_envio = Scrollbar(log_envio)
scrollbar_envio.pack(side=RIGHT, fill=Y)
log_envio.config(yscrollcommand=scrollbar_envio.set)
scrollbar_envio.config(command=log_envio.yview)
serBuffer = ""


commonComPortSpeeds = ["1200", "2400", "4800", "9600", "14400", "19200", "38400", "57600", "115200"]





def readSerial():
    while True:
        c = ser.read() # attempt to read a character from Serial
        
        #was anything read?
        if len(c) == 0:
            break
        
        # get the buffer from outside of this function
        global serBuffer
        
        # check if character is a delimeter
        if c == '\r':
            c = '' # don't want returns. chuck it
            
        if c == '\n':
            serBuffer += "\n" # add the newline to the buffer
            
            #add the line to the TOP of the log
            log_rece.insert('0.0', serBuffer)
            serBuffer = "" # empty the buffer
        else:
            serBuffer += c # add to the buffer
    
    window.after(10, readSerial) # check serial again soon

def helloCallBack():
   tkMessageBox.showinfo( "Hello Python", "Hello World")
   print Bontones.l11.get()

i=0
l = tk.Label(window,text='Kp'+ str(i))
l.place(x = 0, y = 30+ i*30, width=30, height=25)
l10 = Entry(window,width=6)
l10.place(x = 30, y =  30+i*30, width=60, height=25)
l = tk.Label(window,text='Ki'+ str(i))
l.place(x = 90, y = 30+ i*30, width=30, height=25)
l20 = Entry(window,width=6)
l20.place(x = 120, y = 30+ i*30, width=60, height=25)
l = tk.Label(window,text='Kd'+ str(i))
l.place(x = 180, y =30+  i*30, width=30, height=25)
l30 = Entry(window,width=6)
l30.place(x = 210, y = 30+ i*30, width=60, height=25)
l = tk.Label(window,text='N'+ str(i))
l.place(x = 270, y = 30+ i*30, width=30, height=25)
l40 = Entry(window,width=6)
l40.place(x = 300, y = 30+ i*30, width=60, height=25)
l = Checkbutton(window, text = "activar pid "+ str(i), variable = CheckVar0, onvalue = 1, offvalue = 0)
l.place(x = 360, y = 30+ i*30, width=120, height=25)


i+=1

l = tk.Label(window,text='Kp'+ str(i))
l.place(x = 0, y = 30+ i*30, width=30, height=25)
l11 = Entry(window,width=6)
l11.place(x = 30, y =  30+i*30, width=60, height=25)
l = tk.Label(window,text='Ki'+ str(i))
l.place(x = 90, y = 30+ i*30, width=30, height=25)
l21 = Entry(window,width=6)
l21.place(x = 120, y = 30+ i*30, width=60, height=25)
l = tk.Label(window,text='Kd'+ str(i))
l.place(x = 180, y =30+  i*30, width=30, height=25)
l31 = Entry(window,width=6)
l31.place(x = 210, y = 30+ i*30, width=60, height=25)
l = tk.Label(window,text='N'+ str(i))
l.place(x = 270, y = 30+ i*30, width=30, height=25)
l41 = Entry(window,width=6)
l41.place(x = 300, y = 30+ i*30, width=60, height=25)
l = Checkbutton(window, text = "activar pid "+ str(i), variable = CheckVar1, onvalue = 1, offvalue = 0)
l.place(x = 360, y = 30+ i*30, width=120, height=25)

i+=1

l = tk.Label(window,text='Kp'+ str(i))
l.place(x = 0, y = 30+ i*30, width=30, height=25)
l12 = Entry(window,width=6)
l12.place(x = 30, y =  30+i*30, width=60, height=25)
l = tk.Label(window,text='Ki'+ str(i))
l.place(x = 90, y = 30+ i*30, width=30, height=25)
l22 = Entry(window,width=6)
l22.place(x = 120, y = 30+ i*30, width=60, height=25)
l = tk.Label(window,text='Kd'+ str(i))
l.place(x = 180, y =30+  i*30, width=30, height=25)
l32 = Entry(window,width=6)
l32.place(x = 210, y = 30+ i*30, width=60, height=25)
l = tk.Label(window,text='N'+ str(i))
l.place(x = 270, y = 30+ i*30, width=30, height=25)
l42 = Entry(window,width=6)
l42.place(x = 300, y = 30+ i*30, width=60, height=25)
l = Checkbutton(window, text = "activar pid "+ str(i), variable = CheckVar2, onvalue = 1, offvalue = 0)
l.place(x = 360, y = 30+ i*30, width=120, height=25)

enviar = Tkinter.Button( text ="enviar", command = helloCallBack)
enviar.place(x = 30, y = 30+ 90, width=220, height=25)

conectar = Tkinter.Button( text ="conectar", command = helloCallBack)
conectar.place(x = 250, y = 30+ 90, width=220, height=25)

#window.after(100, readSerial)

#RAUL
plot_x = [];	# Vector de donde almacenamos los datos recibidos por serial
loopcount = 0;	# Indice del bucle actual: Usado para fijar el eje horizontal del plot
RangoEjeX = 500; # Rango del eje horizontal
RangoEjeY = 100; # Rango del eje horizontal
    


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
    plot_x.append(int(line))
    loopcount = loopcount + 1
    
timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(50)


if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()

#FIN RAUL

window.mainloop()
