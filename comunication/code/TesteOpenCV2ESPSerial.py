import serial
import cv2
import time

def sendSerial(value):
	ser=serial.Serial('/dev/ttyUSB0',baudrate=115200, timeout=1, write_timeout=1)
	ser.flush()
	ser.write(value.encode())
	ser.close()


#pinE="S,SD107,HA127,FT127,ED147,"
#pinD="S,SD127,HA127,FT127,ED107,"
#pinC="S,SD127,HA127,FT127,ED127,"
#pinB="S,SD127,HA127,FT127,ED127,"
pinD="S,SD100,HA127,FT127,ED127,"

#import requests
URL = "http://192.168.3.101:81/stream"
webCamera = cv2.VideoCapture(0)
#webCamera = cv2.VideoCapture(URL)
classificadorVideoFace = cv2.CascadeClassifier('./cascade_alvo_central.xml')
classificadorOlho = cv2.CascadeClassifier('./cascade_alvo_central.xml')

vermelho = (0, 0, 255)
verde = (0, 255, 0)

# webcam 640x480
# esp 320X240
width=640
height=480
width=width/2
height=height/2

#while cv2.waitKey(1) != ord('w'):
#	a=1

# while True:
# 	sendSerial("P")


while True:
	time.sleep(1)
	sendSerial("T")
	if webCamera.isOpened(): 
		camera, frame = webCamera.read()
		cinza = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
		detecta = classificadorVideoFace.detectMultiScale(cinza)
		#print(frame.shape[1])
		#print(camera.shape[0])
		for(x, y, l, a) in detecta:
			cv2.rectangle(frame, (x, y), (x + l, y + a), (255, 0, 0), 2)
			cv2.line(frame, (int(width), int(height)), (x+l//2, int(height)), vermelho, 1)
			cv2.line(frame, (int(width), int(height)), (int(width), y+a//2), verde, 1)
			#cv2.line(frame, (x, 240), (320, 240), vermelho, 1)
			#cv2.line(frame, (320, y), (320, 240), verde, 1)
			#cv2.line(frame, (180, 120), (x+l//2, 120), verde, 1)
			#cv2.line(frame, (0, 0), (320, 240), verde, 1)
			#print(x, l)
			#print(frame.shape[1])
			#print(frame.shape[0])

			if (width-(x+l//2))>=0:
				#board.digital[2].write(1)
				#board.digital[3].write(0)
				print("ESQ")
			else:
				#board.digital[2].write(0)
				#board.digital[3].write(1)
				print("DIR")

			if (height-(y+a//2))>=0:
				#board.digital[5].write(1)
				#board.digital[4].write(0)
				print("BAIXO")
			else:
				#board.digital[5].write(0)
				#board.digital[4].write(1)
				print("CIM")
			sendSerial(pinD)		

	        #pegaOlho = frame[y:y + a, x:x + l]
	        #OlhoCinza = cv2.cvtColor(pegaOlho, cv2.COLOR_BGR2GRAY)
	        #localizaOlho = classificadorOlho.detectMultiScale(OlhoCinza)
	        #for (ox, oy, ol, oa) in localizaOlho:
			#cv2.rectangle(pegaOlho, (ox, oy), (ox + ol, oy + oa), (0, 255, 0), 2)

		cv2.imshow("Video WebCamera", frame)
	
		if cv2.waitKey(1) == ord('q'):
			break
		# else:
		# 	#sendSerial("T")


webCamera.release()
cv2.destroyAllWindows()
