// // /*
// // #
// // # Rotinas de testes baseada no TRELLO
// // # 
// // #
// // */

// #include <Arduino.h>
// #define LED_ONBOARD 2
// #define PWMA 23
// #define PWMB 19
// #define IN1 33
// #define IN2 32
// #define IN3 26
// #define IN4 25
// #define _SDA 18
// #define _SDB 05
// #define _SDC 17
// #define _SDD 16
// #define SLA 36
// #define SLB 39

// void setup() {
// 	pinMode(LED_ONBOARD, OUTPUT);
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);
//     pinMode(IN3, OUTPUT);
//     pinMode(IN4, OUTPUT);

//     pinMode(_SDA, INPUT_PULLDOWN);
//     pinMode(_SDB, INPUT_PULLDOWN);
//     pinMode(_SDC, INPUT_PULLDOWN);
//     pinMode(_SDD, INPUT_PULLDOWN);

//     ledcAttachPin(PWMA, 0);
//     ledcSetup(0, 5000, 10);
//     ledcAttachPin(PWMB, 1);
//     ledcSetup(1, 5000, 10);
//     Serial.begin(3600);
// }

// void loop() {
//     //ligar e desligar led
// 	delay(1000);
//     digitalWrite(ONBOARD_LED,HIGH);
//     delay(1000);
//     digitalWrite(ONBOARD_LED,LOW);

//     //rodar motor A para frente
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     ledcWrite(0, 5);
//     delay(1000);

//     //rodar motor B para frente
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);
//     ledcWrite(1, 5);
//     delay(1000);

//     //rodar motor A para trás
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2,HIGH);
//     ledcWrite(0, 5);
//     delay(1000);

//     //rodar motor B para trás
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4,HIGH);
//     ledcWrite(1, 5);
//     delay(1000);

//     //rodar um motor para cado lado 1
//     //rodar motor A para trás
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2,HIGH);
//     ledcWrite(0, 5);
//     //rodar motor B para frente
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);
//     ledcWrite(1, 5);
//     delay(1000);

//     //rodar um motor para cado lado 2
//     //rodar motor A para frente
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     ledcWrite(0, 5);
//     //rodar motor B para trás
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);
//     ledcWrite(1, 5);
//     delay(1000);

//     //ENQUANTO SENSORES NAO VEEM NADA, ROBO ANDA PARA FRENTE
//     if((SLA == FALSE) && (SLB == FALSE)){
//         digitalWrite(IN1, HIGH);
//         digitalWrite(IN2, LOW);
//         ledcWrite(0, 5);
//         digitalWrite(IN3, HIGH);
//         digitalWrite(IN4, LOW);
//         ledcWrite(0, 5);
//     } else {
//         digitalWrite(IN1, HIGH);
//         digitalWrite(IN2, HIGH);
//         ledcWrite(0, 0);
//         digitalWrite(IN3, HIGH);
//         digitalWrite(IN4, HIGH);
//         ledcWrite(0, 0);
//     }

//     //andar reto
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     ledcWrite(0, 5);
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);
//     ledcWrite(0, 5);





// }