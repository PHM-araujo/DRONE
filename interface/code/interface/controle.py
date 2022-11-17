from PyQt5 import uic, QtWidgets 
import serial

# Other functions

def sendSerial(value):
    ser = serial.Serial('/dev/ttyUSB0', baudrate=115200, timeout=1)
    ser.write(value.encode())
    ser.close()

# Buttons Functions 
def pushButton_ligar(): 
    screen1.label_ligado_or_desligado.setText("Ligado")
    sendSerial("1")

def pushButton_desligar(): 
    screen1.label_ligado_or_desligado.setText("Desligado")
    sendSerial("off")

    print("Desliguei Drone")

def pushButton_high(): 
    screen1.label_function.setText("Alta velocidade")
    print("Drone em alta velocidade")

def pushButton_low(): 
    screen1.label_function.setText("Baixa velocidade")
    print("Drone em baixa velocidade")   

def pushButton_headless(): 
    screen1.label_function.setText("Headless")
    print("Headless")  

def pushButton_acender(): 
    aux = screen1.verticalSlider_acender_descender.sliderPosition();

    if aux < 255:
        screen1.verticalSlider_acender_descender.setValue(aux + 1);

    screen1.lcdNumber_acender_descender.display(aux)

def pushButton_descender(): 
    aux = screen1.verticalSlider_acender_descender.sliderPosition();
    
    if aux > 0:
        screen1.verticalSlider_acender_descender.setValue(aux - 1);

    screen1.lcdNumber_acender_descender.display(aux)
    
def pushButton_anti(): 
    aux = screen1.verticalSlider_anti_horario.sliderPosition();
    
    if aux > 0:
        screen1.verticalSlider_anti_horario.setValue(aux - 1);

    screen1.lcdNumber_anti_horario.display(aux)   

def pushButton_horario(): 
    aux = screen1.verticalSlider_anti_horario.sliderPosition();

    if aux < 255:
        screen1.verticalSlider_anti_horario.setValue(aux + 1);

    screen1.lcdNumber_anti_horario.display(aux) 

def pushButton_esquerda(): 
    aux = screen1.verticalSlider_esquerda_direita.sliderPosition();
    
    if aux > 0:
        screen1.verticalSlider_esquerda_direita.setValue(aux - 1);

    screen1.lcdNumber_esq_dir.display(aux) 

def pushButton_direita(): 
    aux = screen1.verticalSlider_esquerda_direita.sliderPosition();

    if aux < 255:
        screen1.verticalSlider_esquerda_direita.setValue(aux + 1);

    screen1.lcdNumber_esq_dir.display(aux)   

def pushButton_frente(): 
    aux = screen1.verticalSlider_frente_tras.sliderPosition();

    if aux < 255:
        screen1.verticalSlider_frente_tras.setValue(aux + 1);

    screen1.lcdNumber_frente_tras.display(aux)   

def pushButton_tras(): 
    aux = screen1.verticalSlider_frente_tras.sliderPosition();
    
    if aux > 0:
        screen1.verticalSlider_frente_tras.setValue(aux - 1);

    screen1.lcdNumber_frente_tras.display(aux)  

def pushButton_ajuesteAnti(): 
    print("Ajustando giro no sentido horário")  

def pushButton_ajuesteHorario(): 
    print("Ajustando giro no horário")  

def pushButton_ajuesteEsquerda(): 
    print("Ajustando ida pra esquerda") 

def pushButton_ajuesteDireita(): 
    print("Ajustando ida pra direita")  

def pushButton_ajusteFrente(): 
    print("Ajustando ida pra frente")  

def pushButton_ajuesteTras(): 
    print("Ajustando ida pra trás")  

def pushButton_ligarHelices():
    sendSerial("Inicia");
    screen1.label_function.setText("Drone iniciado")
    print("Iniciei drone")


# Sliders functions

def slide_acenderDescender():
    screen1.lcdNumber_acender_descender.display(screen1.verticalSlider_acender_descender.sliderPosition())

def slide_antiHorario():
    screen1.lcdNumber_anti_horario.display(screen1.verticalSlider_anti_horario.sliderPosition())

def slide_frenteTras():
    screen1.lcdNumber_frente_tras.display(screen1.verticalSlider_frente_tras.sliderPosition())

def slide_esquerdaDireita():
    screen1.lcdNumber_esq_dir.display(screen1.verticalSlider_esquerda_direita.sliderPosition())


# App Exec 
app = QtWidgets.QApplication([])
screen1 = uic.loadUi("/home/pedro/Documents/Projects/LASC/interface/controle_interface.ui")

# Pushbuttons 
screen1.pushButton_ligar.clicked.connect(pushButton_ligar)
screen1.pushButton_desligar.clicked.connect(pushButton_desligar)
screen1.pushButton_high.clicked.connect(pushButton_high)
screen1.pushButton_low.clicked.connect(pushButton_low)
screen1.pushButton_headless.clicked.connect(pushButton_headless)
screen1.pushButton_Ascender.clicked.connect(pushButton_acender)
screen1.pushButton_Descender.clicked.connect(pushButton_descender)
screen1.pushButton_Anti.clicked.connect(pushButton_anti)
screen1.pushButton_Horario.clicked.connect(pushButton_horario)
screen1.pushButton_Esquerda.clicked.connect(pushButton_esquerda)
screen1.pushButton_Direita.clicked.connect(pushButton_direita)
screen1.pushButton_Frente.clicked.connect(pushButton_frente)
screen1.pushButton_Tras.clicked.connect(pushButton_tras)
screen1.pushButton_Ajuste_anti.clicked.connect(pushButton_ajuesteAnti)
screen1.pushButton_Ajuste_horario.clicked.connect(pushButton_ajuesteHorario)
screen1.pushButton_Ajuste_esquerda.clicked.connect(pushButton_ajuesteEsquerda)
screen1.pushButton_Ajuste_direita.clicked.connect(pushButton_ajuesteDireita)
screen1.pushButton_Ajuste_tras.clicked.connect(pushButton_ajuesteTras)
screen1.pushButton_Ajuste_frente.clicked.connect(pushButton_ajusteFrente)
screen1.pushButton_ligarHelices.clicked.connect(pushButton_ligarHelices)

# Sliders 
screen1.verticalSlider_acender_descender.valueChanged.connect(slide_acenderDescender)
screen1.verticalSlider_anti_horario.valueChanged.connect(slide_antiHorario)
screen1.verticalSlider_frente_tras.valueChanged.connect(slide_frenteTras)
screen1.verticalSlider_esquerda_direita.valueChanged.connect(slide_esquerdaDireita)

# Incializa os Sliders
screen1.lcdNumber_acender_descender.display(screen1.verticalSlider_acender_descender.sliderPosition())
screen1.lcdNumber_anti_horario.display(screen1.verticalSlider_anti_horario.sliderPosition())
screen1.lcdNumber_frente_tras.display(screen1.verticalSlider_frente_tras.sliderPosition())
screen1.lcdNumber_esq_dir.display(screen1.verticalSlider_esquerda_direita.sliderPosition())


screen1.show()
app.exec()
