
#include <ULTRAX.h> //Incluindo a biblioteca so sensor HC-SR04

ULTRAX ULTRA(5,6); //Criando objeto do sensor

void setup(){  
	Serial.begin(9600); //Porta serial
}  
   
void loop(){ 
	Serial.print("Distancia em centimetros: ");
	Serial.println(ULTRA.getDistance_MM());//Recebe a distancia em centimetros
}  
