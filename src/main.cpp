#include <Arduino.h>
#include <ModbusMaster.h>
#include <HardwareSerial.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <UrlEncode.h>
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

#define NUM_TELEFONO_SMS 666666666



// Define el objeto de comunicación Modbus RTU, DISPLAY
ModbusMaster node;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//VARIABLES GLOBALES Y FUNCIONES

bool conexionWithInv=false;
bool isSendMsg=false;
String phoneNumberWhatapp = "+34648749355";
String apiKey = "7327197";

void printOLED(String marca,String inversor, String sim);
void printOLEDmensaje(String msj);
void sendWhatapp(String msg);


//FIN VARIABLES GLOBALES 

void setup() {


//CONFIGURACION DE LOS PUERTOS SERIAL

  // Inicializa la comunicación Serie para la depuración
  Serial.begin(9600);
  // Inicializa la comunicación RS485 con la placa XY485
  Serial2.begin(BAUD_RATE_RS485, SERIAL_8N1, TX_RS485, RX_RS485); // Configura los pines  (TX2) y (RX2) para RS485
  // Inicializa el objeto ModbusMaster
  node.begin(DIR_ID_MODBUS, Serial2); // El número 3 es la dirección del dispositivo Modbus

//FIN CONFIGURACION DE LOS PUERTOS SERIAL

  
//CONFIGURACION DE LA PANTALLA OLED SSD1306  
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS)){
    Serial.println("FALLO EN PANTALLA");
  }
// FIN CONFIGURACION DE LA PANTALLA OLED SSD1306  

//CONFIGURACION DE LA WIFI
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  bool res;
  res=wm.autoConnect("AP-4705","123456789");
  if (!res)
  {
    Serial.println("Fallo de conexion");
    printOLEDmensaje("Esperando WIFI");
  }
  else{
    Serial.println("conectado");
    printOLEDmensaje("Cargando...");

  }
  

}

void loop() {
  uint8_t result;
  uint16_t data;
  static String comRs485 = "";

//bool conexionWithInv=false;
//bool isSendMsg=false;

  // Realiza una lectura de un registro Modbus (por ejemplo, el registro 0x0001)
  result = node.readHoldingRegisters(ADDRESS_MODBUS, 1);
  // Verifica si la lectura fue exitosa
  if (result == node.ku8MBSuccess) {
    data = node.getResponseBuffer(0);
    Serial.print("Frecuencia de la red: ");
    Serial.println(data);
    comRs485="OK";
    conexionWithInv=true;
    isSendMsg=false;
  } else {
    Serial.print("Error al leer el registro. Código de error: ");
    Serial.println(result);
    comRs485="ERROR";
    //comprobaremos los estados para decidir si enviamos mensajes o no 

    if(conexionWithInv==true && isSendMsg==false)// si estabamos conectado con el inversor
    {
      sendWhatapp("Fallo de alimentacion del inversor ");
      isSendMsg=true;

    }
  }

  //Serial.println("ip Serial:"+WiFi.localIP());
  printOLED("ALICR",comRs485,"ERROR"); 
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
  display.setCursor(0, 20);
  display.println("CONEX.INVER: "+inversor);
  //---------------------------------
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 30);
  display.println("CONEX.GSM: "+sim);
  //-------------------------------
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 50);
  //display.println("IP: "+WiFi.localIP());
  display.println("IP: ");

  //-------------------------------

  display.display();
}
void printOLEDmensaje(String msj){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 30);
  display.println(msj);
  display.display();
}
void sendWhatapp(String msg)
{
 // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumberWhatapp + "&apikey=" + apiKey + "&text=" + urlEncode(msg);    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();

  //CODE FUNCTION
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(msg);
  display.display();
}
