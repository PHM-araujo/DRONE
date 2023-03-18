from PyQt5 import uic, QtWidgets 
import serial
 

# Other functions

def sendSerial(value):
    ser = serial.Serial('/dev/ttyUSB0', baudrate=115200, timeout=1)
    ser.write(value.encode())
    ser.close()

# Buttons Functions 
def pushButton_ligar(): 
    sendSerial("C")

def pushButton_sobe(): 
    sendSerial("S,SD150,HA127,FT127,ED127,")

def pushButton_horario(): 
    sendSerial("S,SD127,HA150,FT127,ED127,")

def pushButton_antihorario(): 
    sendSerial("S,SD127,HA104,FT127,ED127,")

def pushButton_esquerda(): 
    sendSerial("S,SD127,HA127,FT127,ED104,")

def pushButton_direita(): 
    sendSerial("S,SD127,HA127,FT127,ED150,")

def pushButton_desce(): 
    sendSerial("S,SD104,HA127,FT127,ED127,")

def pushButton_frente(): 
    sendSerial("S,SD127,HA127,FT150,ED127,")

def pushButton_tras(): 
    sendSerial("S,SD127,HA127,FT104,ED127,")

# App Exec 
app = QtWidgets.QApplication([])
screen1 = uic.loadUi("/home/pedro/Documents/Projects/LASC/DRONE/interface/code/teste/interface_teste.ui")

# Pushbuttons 
screen1.pushButton_ligar.clicked.connect(pushButton_ligar)
screen1.pushButton_sobe.clicked.connect(pushButton_sobe)
screen1.pushButton_horario.clicked.connect(pushButton_horario)
screen1.pushButton_antihorario.clicked.connect(pushButton_antihorario)
screen1.pushButton_esquerda.clicked.connect(pushButton_esquerda)
screen1.pushButton_direita.clicked.connect(pushButton_direita)
screen1.pushButton_desce.clicked.connect(pushButton_desce)
screen1.pushButton_frente.clicked.connect(pushButton_frente)
screen1.pushButton_tras.clicked.connect(pushButton_tras)



screen1.show()
app.exec()
