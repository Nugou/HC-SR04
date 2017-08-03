# HC-SR04 Library (ULTRAX)

This library of easy access provides comands to receive all that module HC-SR04 offers.


# Installacion

To install, download and extract to the folder 'libraries' of arduino(C:\Program Files (x86)\Arduino\libraries\), done; 

# Comands

Instance: ULTRAX MYULTRA(int, int); -> Instance with the port echo and trigger;

*-> name of reference like 'MYULTRA';

To receive the distance of module, use comands: 

* *.getDistance(); -> Return distance in millimeters;
* *.getDistance_M(); -> Return distance in meters;
* *.getDistance_CM(); -> Return distance in centimeters;
* *.getDistance_IN(); -> Return distance in inch;

The library have more comands, like:

* *.enableMotor(int); -> (int = port of Motor[motors of vibration 1027])
	Enabled the library to work with motors of low ampere, like motors of smartphone and motors of vibration 1027;
	When a object is close of module, more the motors will vibration;
	
* *.enableBip(int); -> (int = port of Bip[Buzzer])
	Enabled the library to work with Buzzer;
	When a object is close of module, more the buzzers will whistle;
	
* *.enableAlert(int); -> (int = port of Alert[LED])
	Enabled the library to work with LED;
	When a object is close of module, the LED will light up.
	

The range of detection can be controlled with comands bellow; 

* *.setMinDistance(double); -> (double = distance minimum in millimeters to activate the module). default: 0;
* *.setMaxDistance(double); -> (double = distance maximum in millimeters to activate the module). default: 4000;

The force of motors can be controlled with comands bellow;

* *.setMinPower(int); -> (int = 0 - 255, values analog). default: 0;
* *.setMaxPower(int); -> (int = 0 - 255, values analog). default: 255;


# Tips

You can work this library together with 'FILX' to filter results with more precision;
 

# Change Log

1.0 - Library finished;
