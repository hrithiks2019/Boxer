# Boxer (Spoilers: Not Yet Completed)
IOT_based_dog

# Short Intro:
    As you all  know this is a IOT Based (quadraped) Machine . Which can interact around Physically in the world.
 I Created this project as my summer project . I Thought it'll be easy to create a machine like this considering my past experiece with robotics ,But To my Surprise this Project was Not Like the others , This is a Total Pain in the @$$ ....
 
    Now back to the nerd part :
    
# Components used :
  1. ESP-8266         X 1
  2. Arduino UNO      X 1
  3. MG-90 Servo      X 11  ( 8 for legs , 2 for head movement and one for tail movement)
  4. Li-ion 2s battery pack     X 1
  5. 6 X 6 Led matrix (homemade)  X 2
  6. Laptop or Desktop  ( For Face Tracking )
      Guys , you can't run face tracking program with a low spec Computer , Cause Processig the video metadata in real time to track faces can really gonna consume a lot of resources.
      
# usage :
    step 1 : Use the provided Laser cut template to make the idividual structural components to make the body of the dog
    step 2 : Place the servo in the mentioned spots and secure them with screws.
    step 3 : Ue the provided platic conecting parts to connect the servo to the legs .
# sorry guys its hard to explain , how to join the components through text (don't worry i'll post a video on how to do that ASAP)
    step 4 : Use the pin allotment text file to correctly connect all the servo's signal wire to the correct pwm output terminal of the
              ESP-8266
    step 5 : 1. Now Upload the Trail.ino , to test the setup .
             2. Upload the Serial.ino to the esp and run the voice.py on your computer (don't forgot to connect the esp to the computer) 
              this setup can be used to control the dog using voice 
              
 # Usage of Python Scripts used in this project :
          Prequisites:
                  Install the following library by using up cmd terminal and pasting the command (Assuming you have already installed python and pip before hand) :
                  
                      1. cv2 = pip install opencv-python
                      2. speech recognition =  pip install SpeechRecognition
                      3. serial = pip install pyserial
                      4. tts = pip install pyttsx3
                      5. numpy = pip install numpy
                    


# THIS PROJECT IS CURRENTLY ONGOING :

Feel Free to Help ME ..... coz..... NOT EVERYONE KNOWS EVERYTHING RIGHT

if you find lot of spelling mistakes in this readme , its bcoz i'm half asleep while typing this .

# Lessons Learned :
   1. Don't use Cheap Crappy Servos (its gear starts to wear of Easily with heavy load);
   2. Don't Connect anything to the esp-8266 digital pin D3 , Especially SERVO ..... If you do , i assure you you are going to have a very bad day.
   3. Always Make sure to take notes .dont rely on soft copies.( all the cordinated angles for the servo got deleted , So i'm Starting it from scratch).
   4. Don't Use PLA , ABS or any kind of plasic or other flexible material for making the body. use hard things such as wood , mdf or something.
   5. Super Glue is your friend , Use Screws for connecting the servo heads to the servo but don't completely rely on them cause they tend to get lose . so Use a little bit of super glue to keep the in their places.
