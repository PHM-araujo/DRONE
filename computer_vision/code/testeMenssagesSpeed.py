import serial
import time



ser=serial.Serial('/dev/ttyUSB0',baudrate=115200, write_timeout=0, timeout=0, stopbits=1)
value = "T"	

while True:
	time.sleep(0.001)
	ser.write(value.encode())