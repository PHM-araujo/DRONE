from PyQt5 import uic, QtWidgets 
import serial


# Other functions

def sendSerial(value):
    ser = serial.Serial('/dev/ttyUSB0', baudrate=115200, timeout=1)
    ser.write(value.encode())
    ser.close()

# Btn Fuctions

# ---------------- Btns rotinas ----------------#
def pushButton_parear(): 
    sendSerial("P")

def pushButton_iniciar():
    sendSerial("I")

def pushButton_desligar():
    sendSerial("D")

def Disclicked():
    sendSerial("R")

def calibChao():
    sendSerial("C")

def calibSDAdd():
    sendSerial("1")

def calibFTAdd():
    sendSerial("2")

def calibEDAdd():
    sendSerial("3")

def calibSDMinnus():
    sendSerial("4")

def calibFTMinnus():
    sendSerial("5")

def calibEDMinnus():
    sendSerial("6")   


# ---------------- Btns direções ---------------- #
def pushButton_sobe(): 
    passo = str(screen1.horizontalSlider_passo.sliderPosition() + 127)
    msg = "S,SD" + passo + ",HA127,FT127,ED127,"
    sendSerial(msg)

def pushButton_desce(): 
    passo = str(127 - screen1.horizontalSlider_passo.sliderPosition())
    msg = "S,SD" + passo + ",HA127,FT127,ED127,"
    sendSerial(msg)

def pushButton_horario(): 
    passo = str(screen1.horizontalSlider_passo.sliderPosition() + 127)
    msg = "S,SD127,HA" + passo + ",FT127,ED127,"
    sendSerial(msg)

def pushButton_antihorario(): 
    passo = str(127 - screen1.horizontalSlider_passo.sliderPosition())
    msg = "S,SD127,HA" + passo + ",FT127,ED127,"
    sendSerial(msg)

def pushButton_frente(): 
    passo = str(screen1.horizontalSlider_passo.sliderPosition() + 127)
    msg = "S,SD127,HA127,FT" + passo + ",ED127,"
    sendSerial(msg)

def pushButton_tras(): 
    passo = str(127 - screen1.horizontalSlider_passo.sliderPosition())
    msg = "S,SD127,HA127,FT" + passo + ",ED127,"
    sendSerial(msg)

def pushButton_direita(): 
    passo = str(screen1.horizontalSlider_passo.sliderPosition() + 127)
    msg = "S,SD127,HA127,FT127,ED" + passo + ","
    sendSerial(msg)

def pushButton_esquerda(): 
    passo = str(127 - screen1.horizontalSlider_passo.sliderPosition())
    msg = "S,SD127,HA127,FT127,ED" + passo + ","
    sendSerial(msg)

# ---------------- Btns others ----------------# 
def pushButton_passoAdd(): 
    aux = screen1.horizontalSlider_passo.sliderPosition() + 1;

    if aux < 127:
        screen1.horizontalSlider_passo.setValue(aux);
        screen1.lcdNumber_passo.display(aux) 


def pushButton_passoMinus(): 
    aux = screen1.horizontalSlider_passo.sliderPosition() - 1;
    
    if aux >= 0:
        screen1.horizontalSlider_passo.setValue(aux);
        screen1.lcdNumber_passo.display(aux)  
    


# Sld Fuctions
def  slider_passo():
    screen1.lcdNumber_passo.display(screen1.horizontalSlider_passo.sliderPosition())


# App Exec 
app = QtWidgets.QApplication([])
screen1 = uic.loadUi("/home/pedro/Documents/Projects/LASC/DRONE/interface/code/teste/interface_teste.ui")

# Pushbuttons 
# ----------------Rotinas---------------- #
screen1.pushButton_parear.clicked.connect(pushButton_parear)
screen1.pushButton_desligar.clicked.connect(pushButton_desligar)
screen1.pushButton_iniciar.clicked.connect(pushButton_iniciar)
screen1.pushButtonCalibChao.clicked.connect(calibChao)

screen1.pushButton_CalibMaxSD.clicked.connect(calibSDAdd)
screen1.pushButton_CalibMaxFT.clicked.connect(calibFTAdd)
screen1.pushButton_CalibMaxED.clicked.connect(calibEDAdd)


screen1.pushButton_CalibMinSD.clicked.connect(calibSDMinnus)
screen1.pushButton_CalibMinFT.clicked.connect(calibFTMinnus)
screen1.pushButton_CalibMinED.clicked.connect(calibEDMinnus)

# ----------------Direções---------------- #
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

# ----------------Others---------------- #
screen1.pushButton_passoAdd.clicked.connect(pushButton_passoAdd)
screen1.pushButton_passoMinus.clicked.connect(pushButton_passoMinus)

# Sliders
screen1.horizontalSlider_passo.valueChanged.connect(slider_passo)


# Leds
screen1.lcdNumber_passo.display(screen1.horizontalSlider_passo.sliderPosition())


screen1.show()
app.exec()
