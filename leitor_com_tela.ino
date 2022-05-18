#include <U8g2lib.h> // BIBLIOTECA PARA UTILIZAR O DISPLAY (https://github.com/olikraus/u8g2)
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h> //BIBLIOTECA PARA UTILIZAR O DISPLAY NATIVA DO ARDUINOIDE (https://www.arduino.cc/en/reference/SPI)
#endif
#include <PZEM004Tv30.h> //BIBLIOTECA PARA LER OS DADOS EXADECIMAIS DO PROTOCOLO TTL DO PZEM (https://github.com/mandulaj/PZEM-004T-v30) 
#include <SoftwareSerial.h> //BIBLIOTECA PARA EMULAR PORTA SERIAL NO ARDUINO NATIVA DO ARDUINOIDE
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);; //PARAMETRO DE PINOS DO DISPLAY
#if !defined(PZEM_RX_PIN) && !defined(PZEM_TX_PIN) //DEFINIÇÃO DOS PINOS DE COMUNICAÇÃO SERIAL DO PZEM COM ARDUINO
#define PZEM_RX_PIN 4 //PINO RECEPTOR DE DADOS DO PZEM
#define PZEM_TX_PIN 7 // PINO TRANSMISSOR DE DADOS DO PZEM
#endif
SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN); //COMUNICANDO A PLACA QUAIS OS PINOS DEVE EMULAR A COMUNICAÇÃO SERIAL
PZEM004Tv30 pzem(pzemSWSerial); //INICIANDO A BLBIOTECA DO PZEM INFORMANDO QUE VAI SE COMUNICAR VIA SERIAL
const char separador = '\t';



void setup() {
  u8g2.begin(); //INICIANDO A COMUNICAÇÃO ENTRE MICROCONTROLADOR E DISPLAY
  Serial.begin(9600); //INICIANDO A COMUNICAÇÃO SERIAL VIA USB
}




void loop() {

  //Serial.print("Custom Address:");
  // Serial.println(pzem.readAddress(), HEX);
  float voltage = pzem.voltage(); //CRIANDO A VARIVAL TENSÃO E PEDINDO A INFORMAÇÃO AO PZEM
  float current = pzem.current(); //CRIANDO A VARIVAL CORRENTE E PEDINDO A INFORMAÇÃO AO PZEM
  float power = pzem.power(); //CRIANDO A VARIVAL ATIVA E PEDINDO A INFORMAÇÃO AO PZEM
  float energy = pzem.energy(); //CRIANDO A VARIVAL ENERGIA E PEDINDO A INFORMAÇÃO AO PZEM
  float frequency = pzem.frequency(); //CRIANDO A VARIVAL FREQUENCIA E PEDINDO A INFORMAÇÃO AO PZEM
  float pf = pzem.pf(); //CRIANDO A VARIVAL FATOR DE POTENCIA E PEDINDO A INFORMAÇÃO AO PZEM
  float power2 = voltage * current; //CALCULANDO A POTENCIA APARENTE MULTIPLICANDO A TENSAO PELA CORRENTE
  float power3 = power2 * (sin(acos(pf))); //CALCULANDO A POTENCIA REATIVA MULTIPLICANDO A POTENRIA APARENTE PELO SENDO DO ARCOCOSSENO DO FATOR DE POTENCIA

  u8g2.clearBuffer(); // LIMPA O DISPLAY
  u8g2.setFont(u8g2_font_ncenB08_tr);  //ESCOLHE A FONTE
  u8g2.setCursor(0, 10); //SET DO CURSOR
  u8g2.print("tensao: "); //NOME QUE IRA APARECER
  u8g2.setCursor(40, 10);
  u8g2.print(voltage);
  u8g2.setCursor(75, 10);
  u8g2.print("V");
  u8g2.setFontMode(0);
  u8g2.setCursor(0, 20);
  u8g2.print("corrente: ");
  u8g2.setCursor(52, 20);
  u8g2.print(current);
  u8g2.setCursor(80, 20);
  u8g2.print("A");
  u8g2.setCursor(0, 30);
  u8g2.print("ativa: ");
  u8g2.setCursor(31, 30);
  u8g2.print(power);
  u8g2.setCursor(82, 30);
  u8g2.print("W");
  u8g2.setCursor(0, 40);
  u8g2.print("aparente: ");
  u8g2.setCursor(52, 40);
  u8g2.print(power2);
  u8g2.setCursor(90, 40);
  u8g2.print("VA");
  u8g2.setCursor(0, 50);
  u8g2.print("reativa: ");
  u8g2.setCursor(44, 50);
  u8g2.print(power3);
  u8g2.setCursor(83, 50);
  u8g2.print("VAr");
  u8g2.setCursor(0, 62);
  u8g2.print("fp: ");
  u8g2.setCursor(20, 62);
  u8g2.print(pf);
  u8g2.setCursor(113, 62);
  u8g2.print("Hz");
  u8g2.setCursor(86, 62);
  u8g2.print(frequency);
  u8g2.sendBuffer();

  Serial.print("V");
  Serial.print(separador);
  Serial.print(voltage);
  Serial.print(separador);
  Serial.print("A");
  Serial.print(separador);
  Serial.print(current);
  Serial.print(separador);
  Serial.print("W");
  Serial.print(separador);
  Serial.print(power);
  Serial.print(separador);
  Serial.print("FP");
  Serial.print(separador);
  Serial.print(pf);
  Serial.print(separador);
  Serial.print("VA");
  Serial.print(separador);
  Serial.print(power2);
  Serial.print(separador);
  Serial.print("VAr");
  Serial.print(separador);
  Serial.println(power3);

  delay(10);
}
