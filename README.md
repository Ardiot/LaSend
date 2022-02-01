# LaSend
## _ARDUINO LIBRARY FOR DATA TRANSMISSION THROUGH LASER_



LaSend is an arduino library very easy to use for data transmission through laser technology. 

- Send and recive all kind of data . 
- Easy to use

## Constructors

    - lasend(frequency, laserPin, laserMode)
    - lasend(frequency, laserPinIn, laserPinOut, laserMode)

- Frequency: Time in ms between bit transmission.
- LaserPin: Arduino digital pin connected to the laser.
- LaserPinIn & laserPinOut: Pins connected to the laser and sensor/receiver respectively.
- laserMode: 0:Emitter, 1:Receiver, 2:Emitter and receiver (NOT implemented :) )


## Methods


    -void send(T data, sizeOfData)
        This method send data trhought laser.
        T data is the data to be sent.
        sizeOfData is the size of data in bits.
        
    -void receive(T data, sizeOfData)
        This method receive data trhought laser.
        T data is the variable where data captured by sensor will be stored.
        sizeOfData is the size of data in bits.**
        
    -void change(int frequency)
        Change the frequency of the transmission
        
    -void set(int time)
        Turn on the laser to facilitate the orientation with the sensor.

## Installation

__Platformio__
- Clone this repo and change the board in the *platformio.ini* file.

__Arduino Ide__
- Change the *main.cpp* extension to *.ino* and open it with Arduino Ide
- Go to ***../Arduino/library*** and create new folder called LaSend and copy the *lasend.h* file inside.
- Add ***#include <lasend.h>*** in main.ino  or import it from the library manager 

## Examples
Example for int variable transmission
```
/* Written by Carlos Ardiot 2022*/

#include "Arduino.h"
#include "lasend.h"
lasend laser(50,5,0); //Creation of our laser object in emitter mode

void setup(){
  Serial.begin(9600);
  laser.set(6000);//Time for orientation
  delay(1000);
}

void loop(){
int i=0;
int tam=sizeof(i)*8;
  for ( i = 0; i < 1000; i++)
  {
    laser.send(i,tam);//Data transmission
    delay(1000);
  }
  
}
``` 

Example for int variable reception
```
/* Written by Carlos Ardiot 2022*/

#include "Arduino.h"
#include "lasend.h"
lasend laser(50,10,1); //Creation of our laser object in receiver mode

void setup(){
  Serial.begin(9600);
}

void loop(){
int data;    
int tam=sizeof(data)*8;

  laser.receive(data,tam);
  Serial.println(data);
  
}
``` 





## License

MIT
