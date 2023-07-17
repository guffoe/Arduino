#include "CTBot.h"
CTBot myBot;

String ssid = "m03";     // dengan nama wifi anda
String pass = "m03guffoe"; // password wifi
String token = "6152483448:AAE7ZYs-wBpxn-ZuCJNaDEU6u02vJDnz1-M"; // token bot telegram

#define Fire 12 //GPIO12 (D6)
#define Smoke 14 //GPIO14 (D5)

void setup() {
  pinMode(Fire, INPUT);
  pinMode(Smoke, INPUT);
  Serial.begin(115200);
  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\n Connected");
  else
    Serial.println("\n Disconnected");
}
  
void loop() {
  int readfire = digitalRead(Fire);
  int readsmoke = digitalRead(Smoke);
  Serial.print("Fire : ");
  Serial.print(readfire);
  Serial.print("   Smoke : ");
  Serial.println(readsmoke);
  if(readsmoke==0) //detectection smoke
  {
    String kirim;
    kirim ="Lapor Bos.! Ada Kebocoran Gas";
    myBot.sendMessage(1186012126, kirim); 
    delay(500); 
  }
  if(readfire==0) //detectection fire
  {
    String kirim;
    kirim ="Lapor bos.! Ada Kebakaran";
    myBot.sendMessage(1186012126, kirim); 
    delay(500); 
  }
  delay(500);
}
