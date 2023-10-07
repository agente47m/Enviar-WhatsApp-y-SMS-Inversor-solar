#include <Arduino.h>
#include <ModbusMaster.h>
#include <HardwareSerial.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>


//INICIO VARIABLES DE PANTALLA OLED

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

//FIN VARIABLES DE PANTALLA OLED
//INICIO VARIABLES DE MODBUS

#define TX_RS485 17
#define RX_RS485 16
#define BAUD_RATE_RS485 9600
#define DIR_ID_MODBUS 3
#define ADDRESS_MODBUS 11015
//FIN VARIABLES DE PANTALLA OLED

#define NUM_TELEFONO 666666666



// Define el objeto de comunicación Modbus RTU, DISPLAY
ModbusMaster node;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void printOLED(String marca,String inversor, String sim);

void setup() {
  // Inicializa la comunicación Serie para la depuración
  Serial.begin(9600);
  // Inicializa la comunicación RS485 con la placa XY485
  Serial2.begin(BAUD_RATE_RS485, SERIAL_8N1, TX_RS485, RX_RS485); // Configura los pines  (TX2) y (RX2) para RS485
  // Inicializa el objeto ModbusMaster
  node.begin(DIR_ID_MODBUS, Serial2); // El número 3 es la dirección del dispositivo Modbus

  if(!display.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS)){
    Serial.println("FALLO EN PANTALLA");
  }
  
}

void loop() {
 uint8_t result;
  uint16_t data;
  static String comRs485 = "";


  // Realiza una lectura de un registro Modbus (por ejemplo, el registro 0x0001)
  result = node.readHoldingRegisters(ADDRESS_MODBUS, 1);
  // Verifica si la lectura fue exitosa
  if (result == node.ku8MBSuccess) {
    data = node.getResponseBuffer(0);
    Serial.print("Frecuencia de la red: ");
    Serial.println(data);
    comRs485="OK";
  } else {
    Serial.print("Error al leer el registro. Código de error: ");
    Serial.println(result);
    comRs485="ERROR";
  }

  printOLED("SALICRU",comRs485,"ERROR");
  
  delay(1000); // Espera un segundo antes de realizar la siguiente lectura
}

void printOLED(String marca,String inversor, String sim)
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("  "+marca+"  ");
  //-----------------
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 30);
  display.println("CONEX.INVER: "+inversor);
  //---------------------------------
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 50);
  display.println("CONEX.GSM: "+sim);

  display.display();
}
