# ofxArduinoDjShield

![ofxArduinoDjShield](https://raw.github.com/fluaten/ofxArduinoDjShield/master/ofxaddons_thumbnail.png)

Openframeworks addon C++

Addon to use easily the DJ Shield for Arduino by Nootropic Design

<https://nootropicdesign.com/djshield/>


   	Specification of the DJ Shield for Arduino :

   		- 5 tactile buttons, connected to digital pins 2-6
   		- 3 10K linear potentiometers connected to analog pins 0,1,2. (shaft is 1/4")
   		- 2 LEDs (one red, one blue) connected to analog pins 4 and 5 (analog pins can also be used as digital pins)
   		- 3 ABS plastic or aluminium knobs for the potentiometers.
   		- Compatible with the Arduino Uno, Duemilanove, Mega or Leonardo
   




Credits for the addon : 

Code for Arduino from **examples/communication/firmataExample**

Code for DjShield : Nicolas Boillot <http://www.fluate.net>

Webpage for the addon : <http://www.fluate.net/code/ofxArduinoDjShield>


  
    
    
## USAGE:


- Get an Arduino Uno, Duemilanove, Mega or Leonardo <http://arduino.cc/en/Main/arduinoBoardUno>

- Upload StandardFirmata on the arduino :

    
	Open Arduino app (preferably Arduino 1.0) and
	navigate to File -> Examples -> Firmata and open StandardFirmata.
	Compile and upload StandardFirmata for your board, then close
	the Arduino application and run the application.
	
	![ofxArduinoDjShield](http://www.fluate.net/media/blog/ofxArduinoDjShield_firmata_exemple.png)


- Get a DJ Shield for Arduino : <https://nootropicdesign.com/djshield/>


- Add to your code :

    

in __ofApp.h__ add :

	#include "ofxArduinoDjShield.h" 
	
	and after "public:" :
	
	ofxArduinoDjShield DjShield;
	
	bool ArduinoUSB; // if Arduino connected to USB port
	
	string deviceInit;
	
	
===
in __ofApp.c__ add :
		
		- in setup() { }

		   vector <ofSerialDeviceInfo> devices = (ofSerial()).getDeviceList();

	for(auto & device : devices){
		if(device.getDeviceID() == 0){
			deviceInit = device.getDeviceName();
		}
	}

	// Here the list of 4 USB Port of the computer, change them in case..
    
    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices

	string ArduinoPort01 = "tty.usbmodem1411";
	string ArduinoPort02 = "tty.usbmodem1d11421";
	string ArduinoPort03 = "tty.usbmodem1421";
	string ArduinoPort04 = "tty.usbmodem1431";

	if((deviceInit == ArduinoPort01) || (deviceInit == ArduinoPort02)  || (deviceInit == ArduinoPort03)  || (deviceInit == ArduinoPort04)){
		ArduinoUSB = true;
	}
	else{
		ArduinoUSB = false;
	}

	if(ArduinoUSB){
		DjShield.setup("/dev/" + deviceInit);
	}
        
 ![ofxArduinoDjShield](http://www.fluate.net/media/blog/ofxArduinoDjShield_port_exemple.png)
        
        --------------------------------------
        
       - in update() {}
       
       if(ArduinoUSB){
        
        DjShield.udpate();
        
       // then use :

		bool DjShield.bSetupArduino // if arduino ready
	
		// Potentiometers A0-A2
		float DjShield.PotA0(); // native, from 0 to 1
		float DjShield.PotA1(TRUE, 0,255); // rescale from 0 to 255
		float DjShield.PotA2(TRUE, 3, 10); // rescale from 3 to 10

		// Buttons D2-D6
		bool DjShield.ButtonD2();
		bool DjShield.ButtonD3();
		bool DjShield.ButtonD4();
		bool DjShield.ButtonD5(0.5); // 0.5 s delay before next hit
		bool DjShield.ButtonD6();

		// LED	A4-A5
		DjShield.LedA4(true);
        DjShield.LedA4(false);
        DjShield.LedA5(true);
		DjShield.LedA5(false);
		
		}


	


![ofxArduinoDjShield](http://www.fluate.net/media/blog/ofxArduinoDjShield_screen_exemple.png)
	
See examples for more details.

See release for OSC Bridge app : [https://github.com/fluaten/ofxArduinoDjShield/releases](https://github.com/fluaten/ofxArduinoDjShield/releases)

	



