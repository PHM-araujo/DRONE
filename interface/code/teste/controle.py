from PyQt5 import uic, QtWidgets 
import serial
 
aux = True

# Other functions

def sendSerial(value):
    ser = serial.Serial('/dev/ttyUSB0', baudrate=115200, timeout=1)
    ser.write(value.encode())
    ser.close()

# Buttons Functions 
def pushButton_ligar(): 
    sendSerial("C")

def Disclicked():
    sendSerial("D")

def pushButton_sobe(): 
    sendSerial("S,SD200,HA127,FT127,ED127,")

def pushButton_horario(): 
    sendSerial("S,SD127,HA200,FT127,ED127,")

def pushButton_antihorario(): 
    sendSerial("S,SD127,HA54,FT127,ED127,")

def pushButton_esquerda(): 
    sendSerial("S,SD127,HA127,FT127,ED200,")

def pushButton_direita(): 
    sendSerial("S,SD127,HA127,FT127,ED54,")

def pushButton_desce(): 
    sendSerial("S,SD54,HA127,FT127,ED127,")

def pushButton_frente(): 
    sendSerial("S,SD127,HA127,FT200,ED127,")

def pushButton_tras(): 
    sendSerial("S,SD127,HA127,FT54,ED127,")

def pushButton_pousar():
    sendSerial("I")

def pushButton_desligar():
    sendSerial("O")

# App Exec 
app = QtWidgets.QApplication([])
screen1 = uic.loadUi("/home/pedro/Documents/Projects/LASC/DRONE/interface/code/teste/interface_teste.ui")

# Pushbuttons 
screen1.pushButton_ligar.clicked.connect(pushButton_ligar)

screen1.pushButton_sobe.pressed.connect(pushButton_sobe)
screen1.pushButton_sobe.clicked.connect(Disclicked)

screen1.pushButton_horario.pressed.connect(pushButton_horario)
screen1.pushButton_horario.clicked.connect(Disclicked)

screen1.pushButton_antihorario.pressed.connect(pushButton_antihorario)
screen1.pushButton_antihorario.clicked.connect(Disclicked)


screen1.pushButton_esquerda.pressed.connect(pushButton_esquerda)
screen1.pushButton_esquerda.clicked.connect(Disclicked)


screen1.pushButton_direita.pressed.connect(pushButton_direita)
screen1.pushButton_direita.clicked.connect(Disclicked)


screen1.pushButton_desce.pressed.connect(pushButton_desce)
screen1.pushButton_desce.clicked.connect(Disclicked)

screen1.pushButton_frente.pressed.connect(pushButton_frente)
screen1.pushButton_frente.clicked.connect(Disclicked)

screen1.pushButton_tras.pressed.connect(pushButton_tras)
screen1.pushButton_tras.clicked.connect(Disclicked)

screen1.pushButton_desligar.clicked.connect(pushButton_desligar)

screen1.pushButton_pousar.clicked.connect(pushButton_pousar)



screen1.show()
app.exec()
