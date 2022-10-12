//////ROTINAS DE TESTE
// /*
// #
// # Rotinas de testes baseada no TRELLO
// #
// #
// */
// orientação dos motores olhando robo de costas

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID "4f5e3185-74ef-424f-93d7-5a4b9f7d74d3"
#define CHARACTERISTIC_UUID "3af6985a-c1e7-410c-9ace-594e8cac2a80"

#define LED_ONBOARD 2

// MOTOR A - ESQUERDO
#define PWMA 23
#define IN1_A 33
#define IN2_A 32

// MOTOR B - DIREITO
#define PWMB 19
#define IN3_B 26
#define IN4_B 25

// SENSORES DISTANCIA
#define SENSOR_LAT_ESQ 18
#define SENSOR_FRONT_ESQ 05
#define SENSOR_FRONT_DIR 17
#define SENSOR_LAT_DIR 16

// SENSORES LINHA
#define SENSOR_LINHA_ESQ 36
#define SENSOR_LINHA_DIR 39

// SIN MODULO START
#define START 14

// DISPLAY 7SEG
#define DISPA 03
#define DISPB 15
#define DISPC 04
#define DISPD 01

// COMANDOS
const char COMANDO_LIGA_DESLIGA_LED = 'L';
const char COMANDO_MOTOR_A_FRENTE = 'A';
const char COMANDO_MOTOR_B_FRENTE = 'B';
const char COMANDO_MOTOR_A_TRAS = 'C';
const char COMANDO_MOTOR_B_TRAS = 'D';
const char COMANDO_MOTORES_AB_REVERSOS = 'E';
const char COMANDO_MOTORES_AB_REVERSOS_2 = 'F';
const char COMANDO_ANDAR_FRENTE_SE_SENSORES_NAO_VEM_NADA = 'G';
const char COMANDO_ANDAR_FRENTE = 'H';
const char COMANDO_LER_SENSORES_DISTANCIA = 'I';
const char COMANDO_LER_SENSORES_LINHA = 'J';
const char COMANDO_TESTE_BLUETOOTH = 'K';
const char COMANDO_ARCO_MAO = 'M';
const char COMANDO_PARAR = 'P';
const char STRAT1 = 'S';
const char STRAT2 = 'T';

char comando = 'z';
char direcao;

static BLERemoteCharacteristic *pRemoteCharacteristic;

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();

    if (value == "L" || value == "l")
    {
      comando = COMANDO_LIGA_DESLIGA_LED;
    }

    if (value == "P" || value == "p")
    {
      comando = COMANDO_PARAR;
    }

    if (value == "A" || value == "a")
    {
      comando = COMANDO_MOTOR_A_FRENTE;
    }

    if (value == "B" || value == "b")
    {
      comando = COMANDO_MOTOR_B_FRENTE;
    }

    if (value == "C" || value == "c")
    {
      comando = COMANDO_MOTOR_A_TRAS;
    }

    if (value == "D" || value == "d")
    {
      comando = COMANDO_MOTOR_B_TRAS;
    }

    if (value == "E" || value == "e")
    {
      comando = COMANDO_MOTORES_AB_REVERSOS;
    }

    if (value == "F" || value == "f")
    {
      comando = COMANDO_MOTORES_AB_REVERSOS_2;
    }

    if (value == "G" || value == "g")
    {
      comando = COMANDO_ANDAR_FRENTE_SE_SENSORES_NAO_VEM_NADA;
    }

    if (value == "H" || value == "h")
    {
      comando = COMANDO_ANDAR_FRENTE;
    }

    if (value == "I" || value == "i")
    {
      comando = COMANDO_LER_SENSORES_DISTANCIA;
      pCharacteristic->setValue("sensor");
    }

    if (value == "J" || value == "j")
    {
      comando = COMANDO_LER_SENSORES_LINHA;
    }

    if (value == "K" || value == "k")
    {
      comando = COMANDO_TESTE_BLUETOOTH;
    }

    if (value == "M" || value == "m")
    {
      comando = COMANDO_ARCO_MAO;
    }

    if (value == "S" || value == "s")
    {
      comando = STRAT1;
    }
    if (value == "T" || value == "t")
    {
      comando = STRAT2;
    }
  }

   void onRead(BLECharacteristic *pCharacteristic){
    if(comando == COMANDO_LER_SENSORES_DISTANCIA){
      int leitura_lat_esq = digitalRead(SENSOR_LAT_ESQ);
      int leitura_front_esq = digitalRead(SENSOR_FRONT_ESQ);
      int leitura_front_dir = digitalRead(SENSOR_FRONT_DIR);
      int leitura_lat_dir = digitalRead(SENSOR_LAT_DIR);

      std::string sensores = "LE:";
      sensores.append(std::to_string(leitura_lat_esq));
      sensores.append(" FE:");
      sensores.append(std::to_string(leitura_front_esq));
      sensores.append(" FD:");
      sensores.append(std::to_string(leitura_front_dir));
      sensores.append(" LD:");
      sensores.append(std::to_string(leitura_lat_dir));

      pCharacteristic->setValue(sensores);
      Serial.println(sensores.c_str());
    }

    if(comando == COMANDO_LER_SENSORES_LINHA){
      int leitura_linha_esq = analogRead(SENSOR_LINHA_ESQ);
      int leitura_linha_dir = analogRead(SENSOR_LINHA_DIR);

      std::string sensores = "ESQ:";
      sensores.append(std::to_string(leitura_linha_esq));
      sensores.append(" DIR:");
      sensores.append(std::to_string(leitura_linha_dir));
    
      pCharacteristic->setValue(sensores);
      Serial.println(sensores.c_str());
    }
  }
};

void setup()
{
  pinMode(LED_ONBOARD, OUTPUT);
  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);
  pinMode(IN3_B, OUTPUT);
  pinMode(IN4_B, OUTPUT);

  pinMode(SENSOR_LINHA_ESQ, INPUT);
  pinMode(SENSOR_LINHA_DIR, INPUT);

  pinMode(SENSOR_LAT_ESQ, INPUT_PULLDOWN);
  pinMode(SENSOR_FRONT_ESQ, INPUT_PULLDOWN);
  pinMode(SENSOR_FRONT_DIR, INPUT_PULLDOWN);
  pinMode(SENSOR_LAT_DIR, INPUT_PULLDOWN);

  pinMode(DISPA, OUTPUT);
  pinMode(DISPB, OUTPUT);
  pinMode(DISPC, OUTPUT);
  pinMode(DISPD, OUTPUT);

  pinMode(START, INPUT_PULLDOWN);

  ledcAttachPin(PWMA, 0);
  ledcSetup(0, 5000, 10);
  ledcAttachPin(PWMB, 1);
  ledcSetup(1, 5000, 10);
  Serial.begin(9600);

  BLEDevice::init("SOMBRA");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new MyCallbacks());

  pCharacteristic->setValue("Hello World");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void linha()
{
  if (SENSOR_LINHA_ESQ && !SENSOR_LINHA_DIR)
  {
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);
    ledcWrite(0, 500);
    digitalWrite(IN3_B, LOW);
    digitalWrite(IN4_B, HIGH);
    ledcWrite(1, 500);
  }
  else if (!SENSOR_LINHA_ESQ && SENSOR_LINHA_DIR)
  {
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    ledcWrite(0, 500);
    digitalWrite(IN3_B, HIGH);
    digitalWrite(IN4_B, LOW);
    ledcWrite(1, 1000);
  }
  else if (!SENSOR_LINHA_ESQ && !SENSOR_LINHA_DIR)
  {
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    ledcWrite(0, 500);
    digitalWrite(IN3_B, LOW);
    digitalWrite(IN4_B, HIGH);
    ledcWrite(1, 500);
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);
    ledcWrite(0, 500);
    digitalWrite(IN3_B, HIGH);
    digitalWrite(IN4_B, LOW);
    ledcWrite(1, 1000);
  }
}

void displayZero(){
digitalWrite(DISPA, 0);
digitalWrite(DISPB, 0);
digitalWrite(DISPC, 0);
digitalWrite(DISPD, 0);
}

void displayUm(){
digitalWrite(DISPA, 1);
digitalWrite(DISPB, 0);
digitalWrite(DISPC, 0);
digitalWrite(DISPD, 0);
}

void loop()
{
  //Serial.println(digitalRead(START));
  //while (digitalRead(START))
  //{
    if (comando == COMANDO_LIGA_DESLIGA_LED) // L
    {
      delay(1000);
      digitalWrite(LED_ONBOARD, HIGH);
      delay(1000);
      digitalWrite(LED_ONBOARD, LOW);
    }

    if (comando == COMANDO_MOTOR_A_FRENTE) // A
    {
      digitalWrite(IN1_A, HIGH);
      digitalWrite(IN2_A, LOW);
      ledcWrite(0, 200);
      delay(1000);
    }

    if (comando == COMANDO_MOTOR_B_FRENTE) // B
    {
      digitalWrite(IN3_B, HIGH);
      digitalWrite(IN4_B, LOW);
      ledcWrite(1, 200);
      delay(1000);
    }

    if (comando == COMANDO_MOTOR_A_TRAS) // C
    {
      digitalWrite(IN1_A, LOW);
      digitalWrite(IN2_A, HIGH);
      ledcWrite(0, 200);
      delay(1000);
    }

    if (comando == COMANDO_MOTOR_B_TRAS) // D
    {
      digitalWrite(IN3_B, LOW);
      digitalWrite(IN4_B, HIGH);
      ledcWrite(1, 200);
      delay(1000);
    }

    if (comando == COMANDO_MOTORES_AB_REVERSOS) // E
    {
      // rodar motor A para trás
      digitalWrite(IN1_A, LOW);
      digitalWrite(IN2_A, HIGH);
      ledcWrite(0, 200);

      // rodar motor B para frente
      digitalWrite(IN3_B, HIGH);
      digitalWrite(IN4_B, LOW);
      ledcWrite(1, 200);

      delay(1000);
    }

    if (comando == COMANDO_MOTORES_AB_REVERSOS_2) // F
    {
      // rodar motor A para frente
      digitalWrite(IN1_A, HIGH);
      digitalWrite(IN2_A, LOW);
      ledcWrite(0, 200);

      // rodar motor B para trás
      digitalWrite(IN3_B, LOW);
      digitalWrite(IN4_B, HIGH);
      ledcWrite(1, 200);

      delay(1000);
    }

    while (comando == COMANDO_ANDAR_FRENTE_SE_SENSORES_NAO_VEM_NADA) // G
    {
      // ENQUANTO SENSORES NAO VEEM NADA, ROBO ANDA PARA FRENTE
      if ((analogRead(SENSOR_LINHA_ESQ) == 0) && (analogRead(SENSOR_LINHA_DIR) == 0))
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, LOW);
        ledcWrite(1, 200);
      }
      else
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, HIGH);
        ledcWrite(0, 0);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
    }

    if (comando == COMANDO_ANDAR_FRENTE) // H
    {
      // andar reto
      digitalWrite(IN1_A, HIGH);
      digitalWrite(IN2_A, LOW);
      ledcWrite(0, 200);
      digitalWrite(IN3_B, HIGH);
      digitalWrite(IN4_B, LOW);
      ledcWrite(1, 200);
    }

    // retorno dos sensores de distancia
    /*if (comando == COMANDO_LER_SENSORES_DISTANCIA) // I
    {
      Serial.print("SDA: ");
      Serial.println(digitalRead(SENSOR_LAT_ESQ));
      Serial.print("SDB: ");
      Serial.println(digitalRead(SENSOR_FRONT_ESQ));
      Serial.print("SDC: ");
      Serial.println(digitalRead(SENSOR_FRONT_DIR));
      Serial.print("SDD: ");
      Serial.println(digitalRead(SENSOR_LAT_DIR));
      delay(1000);
    }*/

    // retorno dos sensores de linha
    if (comando == COMANDO_LER_SENSORES_LINHA) // J
    {
      Serial.print("SLA ");
      Serial.println(analogRead(SENSOR_LINHA_ESQ));
      delay(1000);
      Serial.print("SLB ");
      Serial.println(analogRead(SENSOR_LINHA_DIR));
      delay(1000);
    }

    // andar com comando bluetooth
    if (comando == COMANDO_TESTE_BLUETOOTH) // K
    {
      // TODO: atribuir um valor para direcao, não está inicializada
      if (direcao == 'F')
      { // andar para frente
        digitalWrite(IN1_A, LOW);
        digitalWrite(IN2_A, HIGH);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, LOW);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 200);
        // andar para trás
      }
      if (direcao == 'T')
      { // andar para trás
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, LOW);
        ledcWrite(1, 200);
      }
    }
    // arco acompanhando mão
    while (comando == COMANDO_ARCO_MAO) // M
    {
      if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // sem ver nada
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, HIGH);
        ledcWrite(0, 0);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (!SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // apenas sensor esquerda
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (SENSOR_LAT_ESQ && !SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // apenas sensor central esquerdo
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && !SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // apenas sensor direito/central
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && !SENSOR_LAT_DIR) // apenas sensor direito
      {
        digitalWrite(IN1_A, HIGH);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, HIGH);
        digitalWrite(IN4_B, HIGH);
        ledcWrite(1, 0);
      }
      else if (!SENSOR_LAT_ESQ && !SENSOR_FRONT_ESQ && !SENSOR_FRONT_DIR && !SENSOR_LAT_DIR) // todos sensores
      {
        digitalWrite(IN1_A, LOW);
        digitalWrite(IN2_A, LOW);
        ledcWrite(0, 200);
        digitalWrite(IN3_B, LOW);
        digitalWrite(IN4_B, LOW);
        ledcWrite(1, 200);
      }
    }

    while (comando == STRAT1) // S1
    {
      Serial.println("S1");

      if (!SENSOR_LINHA_ESQ || !SENSOR_LINHA_DIR)
      {
        linha();
      }
      else
      {

        if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // nenhum
        {
          digitalWrite(IN1_A, HIGH);
          digitalWrite(IN2_A, LOW);
          ledcWrite(0, 800);
          digitalWrite(IN3_B, HIGH);
          digitalWrite(IN4_B, LOW);
          ledcWrite(1, 800);
        }
        else if (!SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // apenas esquerdo
        {
          digitalWrite(IN1_A, HIGH);
          digitalWrite(IN2_A, LOW);
          ledcWrite(0, 800);
          digitalWrite(IN3_B, LOW);
          digitalWrite(IN4_B, HIGH);
          ledcWrite(1, 800);
        }
        else if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && !SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // apenas central direito
        {
          digitalWrite(IN1_A, HIGH);
          digitalWrite(IN2_A, LOW);
          ledcWrite(0, 700);
          digitalWrite(IN3_B, LOW);
          digitalWrite(IN4_B, HIGH);
          ledcWrite(1, 700);
        }
        else if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && !SENSOR_FRONT_DIR && !SENSOR_LAT_DIR) // apenas frontal esquerdo
        {
          digitalWrite(IN1_A, LOW);
          digitalWrite(IN2_A, HIGH);
          ledcWrite(0, 700);
          digitalWrite(IN3_B, HIGH);
          digitalWrite(IN4_B, LOW);
          ledcWrite(1, 700);
        }
        else if (SENSOR_LAT_ESQ && SENSOR_FRONT_ESQ && SENSOR_FRONT_DIR && !SENSOR_LAT_DIR) // apenas direito
        {
          digitalWrite(IN1_A, HIGH);
          digitalWrite(IN2_A, LOW);
          ledcWrite(0, 800);
          digitalWrite(IN3_B, LOW);
          digitalWrite(IN4_B, HIGH);
          ledcWrite(1, 800);
        }
        else if (SENSOR_LAT_ESQ && !SENSOR_FRONT_ESQ && !SENSOR_FRONT_DIR && SENSOR_LAT_DIR) // centrais
        {
          digitalWrite(IN1_A, HIGH);
          digitalWrite(IN2_A, LOW);
          ledcWrite(0, 1000);
          digitalWrite(IN3_B, HIGH);
          digitalWrite(IN4_B, LOW);
          ledcWrite(1, 1000);
        }
      }
    }

    while (comando == STRAT2)
    { // S2
    }

    if (comando == COMANDO_PARAR)
    {
      ledcWrite(0, 0);
      ledcWrite(1, 0);
      Serial.println("P");
    }
  //}
}