from PyQt5 import uic, QtWidgets 
import serial

# Other functions

def sendSerial(value):
    ser = serial.Serial('/dev/ttyUSB0', baudrate=115200, timeout=1)
    ser.write(value.encode())
    ser.close()

# Buttons Functions 
def pushButton_ligar(): 
    sendSerial("in")

def pushButton_sobe(): 
    sendSerial("s")

def pushButton_horario(): 
    sendSerial("h")

def pushButton_antihorario(): 
    sendSerial("ant")

def pushButton_esquerda(): 
    sendSerial("esq")

def pushButton_direita(): 
    sendSerial("dir")

def pushButton_desce(): 
    sendSerial("des")

def pushButton_frente(): 
    sendSerial("fr")

def pushButton_tras(): 
    sendSerial("tr")

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
