/*
License Apache v1.0
Adruino NodeMCU 1.0 ESP8266
Fire , Smoke detection with Telegram API + Buzzer Physical Sound 
*/
#include "CTBot.h"
CTBot myBot;

String ssid = "m03";     // Sesuikan dengan nama wifi anda
String pass = "m03guffoe"; // sesuaikan password wifi
String token = "6152483448:AAE7ZYs-wBpxn-ZuCJNaDEU6u02vJDnz1-M"; // token bot telegram yang telah dibuat

#define Api 12 //GPIO12 (D6)
#define Gas 14 //GPIO14 (D5)
#define buzzerPin 15 //GPIO15 (D8)
                    
void setup() {
  pinMode(Api, INPUT);
  pinMode(Gas, INPUT);
  pinMode(buzzerPin,OUTPUT);                 
  Serial.begin(115200);
  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\n Terhubung");
  else
    Serial.println("\n Tidak Terhubung");
}
  
void loop() {
  int bacasensorapi = digitalRead(Api);
  int bacasensorgas = digitalRead(Gas);
  Serial.print("Api : ");
  Serial.print(bacasensorapi);
  Serial.print("   Gas : ");
  Serial.println(bacasensorgas);
  if(bacasensorgas==0) //terdeteksi gas
  {
    String kirim;
    kirim ="Warning bossku..! Ada Kebocoran Gas";
    myBot.sendMessage(724268164, kirim);
    delay(1000); 
    tone(buzzerPin, 277, 1000); // (freq , duration)
    delay(500); 
  }
  if(bacasensorapi==0) //terdeteksi api
  {
    String kirim;
    kirim ="Warning bossku..! Ada Kebakaran";
    myBot.sendMessage(724268164, kirim);
    delay(1000); 
    tone(buzzerPin, 440, 3000); // (freq , duration)
    delay(500); 
  }
    delay(1000);
}

/*
Author : fanthaghiro.foe@xlm03lx.github.com
Release Date : 19-July-2023
Rev : b01
*/
