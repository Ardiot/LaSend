/* Written by Carlos Ardiot 2022*/


#ifndef _Arduino
#include "Arduino.h"
#endif

class lasend
{
private:
    int t;
    int pinIn,pinOut;
    int state;
    unsigned long previousMillis1;

    void setup_pinMode(int pin,int laser_state){

        if(laser_state==0){// 0 = Solo Emisor
            this->pinOut=pin;
            pinMode(pinOut,OUTPUT);
        }
        else if(laser_state==1){
            this->pinIn=pin;
            pinMode(pinIn,INPUT);
        }
    }

public:
    //constructors
    lasend(int period,int pin,int laser_state)
    {
        this->t=period;
        setup_pinMode(pin,laser_state);
    }
    lasend(int period,int pIn, int pOut,int laser_state)
    {
        this->t=period;
        setup_pinMode(pIn,1);
        setup_pinMode(pOut,0);
    }

    //methods
    template<typename T> void send(T sent, int tam)
    {
        int cont=0;
        while(cont<=tam){
            
            unsigned long currentMillis = millis();
        
            if(currentMillis-previousMillis1>t){
                if(cont==0){
                    digitalWrite(pinOut,1);
                    cont++;  
                }
                else{
                    digitalWrite(pinOut,bitRead(sent,cont-1));
                    Serial.print(bitRead(sent,cont-1));
                    cont++;
                }
                
                previousMillis1=millis();
            }
        }
        digitalWrite(pinOut,0);
        Serial.print("\n Envio completado \n\n\n");

    }


    template<typename T> void receive(T received, int tam)
    {
        //unsigned long currentMillis = millis();
        int i;
        if(digitalRead(pinIn)==0){
            delay(t);
            Serial.print("\n");
            for( i=0;i<tam;i++){
                    bitWrite(received,i,!digitalRead(pinIn));
                    Serial.print(!digitalRead(pinIn));
                    delay(t);
            }
            
            Serial.println("Value at i : ");
            Serial.print((T)received);
            Serial.print("\n Value at i in binari : ");
            Serial.print(received,BIN);
            Serial.print("\n");
        }
    }
    void change_t(int period)
    {
    this->t=period;
    }
    void set(int time){
        digitalWrite(pinOut,1);
        delay(time);
        digitalWrite(pinOut,0);
    }
    
};

