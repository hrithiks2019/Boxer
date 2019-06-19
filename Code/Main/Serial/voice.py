# Code is Written By Hrithik aka MrX_ham1

import speech_recognition as sr
import pyttsx3
import scom
import serial
import time


def talktome(audio):
    print(audio)
    engine = pyttsx3.init()
    engine.setProperty('rate', 120)
    engine.setProperty('volume', 100.0)
    engine.say(audio)
    engine.runAndWait()


def mycommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('Ready...')
        r.pause_threshold = 1
        r.adjust_for_ambient_noise(source, duration=1)
        audio = r.listen(source)
    try:
        command = r.recognize_google(audio).lower()
        print('You said: ' + command + '\n')
    except sr.UnknownValueError:
        print('Your last command couldn\'t be heard')
        command = mycommand()
    return command


def assistant(command):
    if 'test' in command:
        talktome('Command Received Moving Forward')
		data = 1
		print ("test in progress")
        arduino.write(data)
    elif 'sit' in command:
        talktome('Command Received Running Now')
		data = 2
		print ("Sit")
        arduino.write(data)
    elif 'hello' in command:
        talktome('Hello Human')
		data = 4
		print ("Hello Human Being")
        arduino.write(data)
    elif 'stand' in command:
        talktome('Command Received Sitting Down')
		data = 3
		print ("Stand")
        arduino.write(data)




port = str(input("Enter the communication port"))
baudrate = int(input("Enter the Baudrate"))
print("Serial Com port is:",port,"\n"," Baudrate is:",baudrate)
time.sleep(2)
arduino = serial.Serial(port, baudrate) 
time.sleep(2)
print("Connection to arduino...")

while True:
    assistant(mycommand())


# Code is Written By Hrithik aka MrX_ham1