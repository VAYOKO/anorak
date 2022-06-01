//anorak edit by Varis Vipavanich date 5/28/2022#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.

#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
float flexA1 = A0;
float flexA2 = A1;
void setup() {
  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();          //This sets the module as transmitter

  Serial.begin(9600);
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  } else {
    Serial.println("ArdinoAll OLED Start Work !!!");
  }
  pinMode(flexA1, INPUT);
  pinMode(flexA2, INPUT);

  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println("ANORAK"); // แสดงผลข้อความ ALL

  OLED.setTextSize(1);
  OLED.print("VER4.1");
  OLED.println(" All");


  OLED.display(); // สั่งให้จอแสดงผล
  delay(3000);
  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.display(); // สั่งให้จอแสดงผล
  Serial.println("table of Flex Sensor");
  Serial.println("FlexA                    flexB");

}

void loop() {
  int flex1 = map(analogRead(flexA1), 700, 900, 0, 255);
  int flex2 = map(analogRead(flexA2), 700, 900, 0, 255);
  //  float flexA1D = flex1;
  //  float flexA2D = flex2;
  //  radio.write(&flexA2D, sizeof(flexA2D));
  //  radio.write(&flexA1D, sizeof(flexA1D));
  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println(analogRead(flexA1)); // แสดงผลข้อความ ALL
  OLED.setCursor(0, 30); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println(analogRead(flexA2)); // แสดงผลข้อความ ALL
  OLED.display(); // สั่งให้จอแสดงผล
  Serial.print(analogRead(flexA1));
  Serial.print("                    ");
  Serial.print(analogRead(flexA2));
  Serial.println();
 
}
