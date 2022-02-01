/* Written by Carlos Ardiot 2022*/

#include "Arduino.h"
#include "lasend.h"

//create our new laser in sending mode(0)
//lasend laser(50,5,0);//emisor
lasend laser(50,10,1);//receptor
int i=0;
int tam=sizeof(i);

void setup(){
  
  Serial.begin(9600);
  /*laser.set(6000);
  delay(1000);*/
}

void loop(){
  
  
  //Send part
  /*
  for ( i = 0; i < 1000; i++)
  {
    laser.send(i,tam*8);
    delay(1000);
  }*/
  

  //Receive part
  laser.receive(i,tam*8);
  

}



