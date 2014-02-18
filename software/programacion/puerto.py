import Tkinter as tk
import serial
from serial.tools import list_ports
import os
def serial_ports():
    """
    Returns a generator for all available serial ports
    """
    if os.name == 'nt':
        # windows
        for i in range(256):
            try:
                s = serial.Serial(i)
                s.close()
                yield 'COM' + str(i + 1)
            except serial.SerialException:
                pass
    else:
        # unix
        for port in list_ports.comports():
            yield port[0]
            
OPTIONS = list(serial_ports())

class App(object):
    def __init__(self, master, **kwargs):
        self.master = master
        self.var = tk.StringVar()
        self.var.set('Puertos')
        self.option = tk.OptionMenu(master, self.var, *OPTIONS)
        self.option.pack()


root = tk.Tk()
app = App(root)
root.mainloop()