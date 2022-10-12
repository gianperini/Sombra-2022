// //exercicio 1
// #include <Arduino.h>
// #define SENSOR_1 13
// #define SENSOR_2 12
// #define SENSOR_3 14
// #define SENSOR_4 27
// #define PWM_A 25
// int sensores_ativos = 0 ;

// void setup() {
//   pinMode(SENSOR_1, INPUT_PULLDOWN);
//   pinMode(SENSOR_2, INPUT_PULLDOWN);
//   pinMode(SENSOR_3, INPUT_PULLDOWN);
//   pinMode(SENSOR_4, INPUT_PULLDOWN);
//   ledcAttachPin(PWM_A, 0);
//   ledcSetup(0, 5000, 10);

// }

// void loop() {
//   if(digitalRead(SENSOR_1) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_2) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_3) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_4) == true){
//     sensores_ativos++;
//   }

//   if(sensores_ativos%2 != 0){
//       ledcWrite(0, 1023);
//   } else {
//     ledcWrite(0, 0);
//   }
//   sensores_ativos = 0 ;
// }

// // //exercicio 2
// #include <Arduino.h>
// #define SENSOR_1 13
// #define SENSOR_2 12
// #define SENSOR_3 14
// #define SENSOR_4 27
// #define PWM_A 25
// int sensor_ativo = 0 ;

// void setup() {
//   pinMode(SENSOR_1, INPUT_PULLDOWN);
//   pinMode(SENSOR_2, INPUT_PULLDOWN);
//   pinMode(SENSOR_3, INPUT_PULLDOWN);
//   pinMode(SENSOR_4, INPUT_PULLDOWN);
//   ledcAttachPin(PWM_A, 0);
//   ledcSetup(0, 5000, 10);

// }

// void loop(){
//   if(digitalRead(SENSOR_1) && !digitalRead(SENSOR_2) && !digitalRead(SENSOR_3) && !digitalRead(SENSOR_4))
//   {
//     sensor_ativo = 1;
//     ledcWrite(0, sensor_ativo*100);
//   }

//   else if(!digitalRead(SENSOR_1) && digitalRead(SENSOR_2) && !digitalRead(SENSOR_3) && !digitalRead(SENSOR_4))
//   {
//     sensor_ativo = 2;
//     ledcWrite(0, sensor_ativo*100);
//   }

//   else if(!digitalRead(SENSOR_1) && !digitalRead(SENSOR_2) && digitalRead(SENSOR_3) && !digitalRead(SENSOR_4))
//   {
//     sensor_ativo = 3;
//     ledcWrite(0, sensor_ativo*100);
//   }

//   else if(!digitalRead(SENSOR_1) && !digitalRead(SENSOR_2) && !digitalRead(SENSOR_3) && digitalRead(SENSOR_4))
//   {
//     sensor_ativo = 4;
//     ledcWrite(0, sensor_ativo*100);
//   }

//   else {
//     ledcWrite(0,0);
//   }

// }

// exercicio 3
// #include <Arduino.h>
// #define SENSOR_1 13
// #define SENSOR_2 12
// #define SENSOR_3 14
// #define SENSOR_4 27
// #define PWM_A 25
// int sensores_ativos = 0 ;

// void setup() {
//   pinMode(SENSOR_1, INPUT_PULLDOWN);
//   pinMode(SENSOR_2, INPUT_PULLDOWN);
//   pinMode(SENSOR_3, INPUT_PULLDOWN);
//   pinMode(SENSOR_4, INPUT_PULLDOWN);
//   ledcAttachPin(PWM_A, 0);
//   ledcSetup(0, 5000, 10);

// }

// void loop() {
//   if(digitalRead(SENSOR_1) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_2) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_3) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_4) == true){
//     sensores_ativos++;
//   }

//   if(sensores_ativos%2 != 0){
//     for(int i=0; i<=1023; i++){
//       ledcWrite(0, i);
//       delay(5);
//     }
//   } else {
//     ledcWrite(0, 0);
//   }
//   sensores_ativos = 0 ;
// }

// //exercicio 4
// #include <Arduino.h>
// #define SENSOR_1 13
// #define SENSOR_2 12
// #define SENSOR_3 14
// #define SENSOR_4 27
// #define PWM_A 25
// int sensores_ativos = 0 ;

// void setup() {
//   pinMode(SENSOR_1, INPUT_PULLDOWN);
//   pinMode(SENSOR_2, INPUT_PULLDOWN);
//   pinMode(SENSOR_3, INPUT_PULLDOWN);
//   pinMode(SENSOR_4, INPUT_PULLDOWN);
//   ledcAttachPin(PWM_A, 0);
//   ledcSetup(0, 5000, 10);

// }

// void loop() {
//   if(digitalRead(SENSOR_1) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_2) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_3) == true){
//     sensores_ativos++;
//   }
//   if(digitalRead(SENSOR_4) == true){
//     sensores_ativos++;
//   }

//   if(sensores_ativos%2 == 0){
//     for(int i=1023; i>=0; i--){
//       ledcWrite(0, i);
//       delay(5);
//     }
//   } else {
//     ledcWrite(0, 0);
//   }
//   sensores_ativos = 0 ;
// }

//////ROTINAS DE TESTE
// /*
// #
// # Rotinas de testes baseada no TRELLO
// #
// #
// */

#include <Arduino.h>
#define LED_ONBOARD 2

// MOTOR A
#define PWMA 23
#define IN1_A 33
#define IN2_A 32

// MOTOR B
#define PWMB 19
#define IN3_B 26
#define IN4_B 25

// SENSORES
#define _SDA 18
#define _SDB 05
#define _SDC 17
#define _SDD 16
#define SLA 36
#define SLB 39

char comando;
char direcao;

void setup()
{
  pinMode(LED_ONBOARD, OUTPUT);
  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);
  pinMode(IN3_B, OUTPUT);
  pinMode(IN4_B, OUTPUT);

  pinMode(SLA, INPUT);
  pinMode(SLB, INPUT);

  pinMode(_SDA, INPUT_PULLDOWN);
  pinMode(_SDB, INPUT_PULLDOWN);
  pinMode(_SDC, INPUT_PULLDOWN);
  pinMode(_SDD, INPUT_PULLDOWN);

  ledcAttachPin(PWMA, 0);
  ledcSetup(0, 5000, 10);
  ledcAttachPin(PWMB, 1);
  ledcSetup(1, 5000, 10);
  Serial.begin(9600);
}

void loop()
{
  if (comando == 'L')
  {
    // ligar e desligar led
    delay(1000);
    digitalWrite(LED_ONBOARD, HIGH);
    delay(1000);
    digitalWrite(LED_ONBOARD, LOW);
  }

  if (comando == 'A')
  {
    // rodar motor A para frente
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);
    ledcWrite(0, 5);
    delay(1000);
  }

  if (comando == 'B')
  {
    // rodar motor B para frente
    digitalWrite(IN3_B, HIGH);
    digitalWrite(IN4_B, LOW);
    ledcWrite(1, 5);
    delay(1000);
  }

  if (comando == 'C')
  {
    // rodar motor A para trás
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    ledcWrite(0, 5);
    delay(1000);
  }

  if (comando == 'D')
  {
    // rodar motor B para trás
    digitalWrite(IN3_B, LOW);
    digitalWrite(IN4_B, HIGH);
    ledcWrite(1, 5);
    delay(1000);
  }

  if (comando == 'E')
  {
    // rodar um motor para cado lado 1
    // rodar motor A para trás
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    ledcWrite(0, 5);
    // rodar motor B para frente
    digitalWrite(IN3_B, HIGH);
    digitalWrite(IN4_B, LOW);
    ledcWrite(1, 5);
    delay(1000);
  }

  if (comando == 'F')
  {
    // rodar um motor para cado lado 2
    // rodar motor A para frente
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);
    ledcWrite(0, 5);
    // rodar motor B para trás
    digitalWrite(IN3_B, LOW);
    digitalWrite(IN4_B, HIGH);
    ledcWrite(1, 5);
    delay(1000);
  }

  while (comando == 'G')
  {
    // ENQUANTO SENSORES NAO VEEM NADA, ROBO ANDA PARA FRENTE
    if ((analogRead(SLA) == 0) && (analogRead(SLB) == 0))
    {
      digitalWrite(IN1_A, HIGH);
      digitalWrite(IN2_A, LOW);
      ledcWrite(0, 5);
      digitalWrite(IN3_B, HIGH);
      digitalWrite(IN4_B, LOW);
      ledcWrite(0, 5);
    }
    else
    {
      digitalWrite(IN1_A, HIGH);
      digitalWrite(IN2_A, HIGH);
      ledcWrite(0, 0);
      digitalWrite(IN3_B, HIGH);
      digitalWrite(IN4_B, HIGH);
      ledcWrite(0, 0);
    }
  }

  while (comando == 'H')
  {
    // andar reto
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);
    ledcWrite(0, 5);
    digitalWrite(IN3_B, HIGH);
    digitalWrite(IN4_B, LOW);
    ledcWrite(0, 5);
  }

  // retorno dos sensores de distancia
  while (comando == 'I')
  {
    Serial.print(analogRead(_SDA) + ' ');
    Serial.print(analogRead(_SDB) + ' ');
    Serial.print(analogRead(_SDC) + ' ');
    Serial.println(analogRead(_SDC));
  }

  // retorno dos sensores de linha
  while (comando == 'J')
  {
    Serial.print(SLA + ' ');
    Serial.println(SLB);
  }

  // andar com comando bluetooth
  if (comando == 'K')
  {
    if (direcao == 'F')
    { // andar para frente
      digitalWrite(IN1_A, LOW);
      digitalWrite(IN2_A, HIGH);
      ledcWrite(0, 50);
      digitalWrite(IN3_B, LOW);
      digitalWrite(IN4_B, HIGH);
      ledcWrite(1, 50);
      // andar para trás
    }
    if (direcao == 'T')
    { // andar para trás
      digitalWrite(IN1_A, HIGH);
      digitalWrite(IN2_A, LOW);
      ledcWrite(0, 50);
      digitalWrite(IN3_B, HIGH);
      digitalWrite(IN4_B, LOW);
      ledcWrite(1, 50);
    }
  }
    // arco acompanhando mão
    while (comando == 'L')
    {
      if (_SDA && _SDB && _SDC && _SDD) // sem ver nada
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, HIGH);
        ledcWrite(0, 0);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (!_SDA && _SDB && _SDC && _SDD) // apenas sensor mais a esquerda
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 50);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (_SDA && !_SDB && _SDC && _SDD) // sensor esquerdo/central
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 50);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (_SDA && _SDB && !_SDC && _SDD) // apenas sensor direito/central
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 50);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (_SDA && _SDB && _SDC && !_SDD) // apenas sensor direito
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 50);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (!_SDA && !_SDB && !_SDC && !_SDD) // todos sensores
      {
        digitalWrite(IN1_A, LOW);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 50);
        digitalWrite(IN3_B, LOW);
        digitalWrite(IN4_B, LOW);
        ledcWrite(1, 50);
      }
    }

    if (comando == 'P')
    {
      ledcWrite(0, 0);
      ledcWrite(1, 0);
    }
  }