
#include <UltrasonicSensor.h> //Incluindo a biblioteca so sensor HC-SR04

Ultra ultra_1; //Criando objeto do sensor

void setup(){  
	Serial.begin(9600); //Porta serial
	ultra_1.setPinSensor(13,12); //Seta as portas do sensor
	ultra_1.setPinBip(11); //Seta a porta do Bip
	ultra_1.setMinDistance(30); //Distancia minima para ativar o Bip em centimetros
	ultra_1.enableBip(true); //Ativa ou Desativa o Bip
	ultra_1.setReScan(0); //Tempo de Releitura do sensor em milisegundos
}  
   
void loop(){  
	Serial.print("Distancia em centimetros: ");
	Serial.print(ultra_1.getDistance());//Recebe a distancia em centimetros
	Serial.print(" ");
	Serial.print("Duracao do sinal: ");
	Serial.println(ultra_1.getDuration()); //Recebe a duração de ida e volta do sinal
}  