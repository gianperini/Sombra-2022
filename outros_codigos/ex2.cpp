// /*
// #
// # Ex. 2 [2022-W33]
// # 
// #   Escreva um programa que, baseado no número do sensor ativo, configure
// # o duty cycle de PWM_A como o número identificador desse sensor vezes 10.
// # e.g. Sensor 2 dá 2*10 = 20 de duty cycle
// #
// */

// #include <Arduino.h>
// #define SENSOR_1 13
// #define SENSOR_2 12
// #define SENSOR_3 14
// #define SENSOR_4 27
// #define SENSOR_QNT 4
// #define PWM_A 25
// #define FREQ_PWM 5000
// #define BIT_RESOLUTION_PWM 10

// int sensores[SENSOR_QNT] = { SENSOR_1, SENSOR_2, SENSOR_3, SENSOR_4 };

// void setup() {
// 	// Configurar os sensores de 1 a 4 como INPUT_PULLDOWN
// 	for(int i=0; i<SENSOR_QNT; i++) {
// 		pinMode(sensores[i], INPUT_PULLDOWN);
// 	}

// 	// Configurar PWM_A
// 	ledcAttachPin(PWM_A, 0);
// 	ledcSetup(0, FREQ_PWM, BIT_RESOLUTION_PWM);
// }

// void loop() {
// 	// Checar se apenas um sensor está ativo e salvar qual deles que é
// 	int numeroDeSensoresAtivos = 0;
// 	int sensorDetectado = 0;
// 	for(int i=0; i<SENSOR_QNT; i++) {
// 		if(digitalRead(sensores[i]) == HIGH) {
// 			numeroDeSensoresAtivos++;
// 			sensorDetectado = i+1; // pois a contagem da array começa do 0
// 		}
// 	}

// 	// Fazer o que o programa quer
// 	if(numeroDeSensoresAtivos == 1) {
// 		int duty_cicle = sensorDetectado*10;
// 		ledcWrite(0, (duty_cicle*10.23)); // Eu na verdade não sei se isso dá certo
// 	} else {
// 		ledcWrite(0, 0);
// 	}
// }