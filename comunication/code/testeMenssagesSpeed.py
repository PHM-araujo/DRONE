import serial
import time



ser=serial.Serial('/dev/ttyUSB0',baudrate=115200)
value =  "T"	

while True:
	time.sleep(0.5)
	ser.write(value.encode())