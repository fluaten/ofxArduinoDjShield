# ofxArduinoDjShield

![ofxArduinoDjShield](https://raw.github.com/fluaten/ofxArduinoDjShield/master/ofxaddons_thumbnail.png)

Openframeworks addon C++

Addon to use easily the DJ Shield for Arduino by Nootropic Design

<https://nootropicdesign.com/djshield/>


   	DJ Shield for Arduino by Nootropic Design :

   		- 5 tactile buttons, connected to digital pins 2-6
   		- 3 10K linear potentiometers connected to analog pins 0,1,2. (shaft is 1/4")
   		- 2 LEDs (one red, one blue) connected to analog pins 4 and 5 (analog pins can also be used as digital pins)
   		- 3 ABS plastic or aluminium knobs for the potentiometers.
   




Webpage : <http://www.fluate.net/code/ofxArduinoDjShield>


Code for Arduino from **examples/communication/firmataExample**

Code for DjShield : Nicolas Boillot <http://www.fluate.net>

  
    
    
## USAGE:


- Get an arduino uno <http://arduino.cc/en/Main/arduinoBoardUno>

- Upload StandardFirmata on the arduino :

  
    To do on Arduino UNO :
    
	To use this addon, open Arduino (preferably Arduino 1.0) and
	navigate to File -> Examples -> Firmata and open StandardFirmata.
	Compile and upload StandardFirmata for your board, then close
	the Arduino application and run this application.


- Get a DJ Shield for Arduino : <https://nootropicdesign.com/djshield/>


- Add to your code :

    

in __ofApp.h__ add :

	#include "ofxArduinoDjShield.h" 
	
	and afer "public:" :
	
	ofxArduinoDjShield DjShield;
	
	
===
in __ofApp.c__ add :
		
		in setup()

		DjShield.setup("/dev/tty.usbmodem1411");
		
		/*
		Replace the string below with the serial port for your Arduino board
        you can get this from the Arduino application or via command line
        
        For OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
        */
        
        --------------------------------------
        
        in update()
        
        DjShield.udpate();
        
        then use :

		bool DjShield.bSetupArduino // if arduino ready
	
		// Potentiometers A0-A2
		float DjShield.PotA0(); // native, from 0 to 1023
		float DjShield.PotA1(TRUE, 0,255); // rescale from 0 to 255
		float DjShield.PotA2(TRUE, 0, 10); // rescale from 0 to 10

		// Buttons D2-D6
		bool DjShield.ButtonD2();
		bool DjShield.ButtonD3();
		bool DjShield.ButtonD4();
		bool DjShield.ButtonD5();
		bool DjShield.ButtonD6();

		// LED	A4-A5
		DjShield.LedA4(true);
        DjShield.LedA4(false);
        DjShield.LedA5(true);
		DjShield.LedA5(false);


	


![ofxArduinoDjShield](http://www.fluate.net/media/blog/ofxArduinoDjShield_screen_exemple.png)
	
See example for more details.

	



