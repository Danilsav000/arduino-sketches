#include <ESP8266WiFi.h>
#include <UniversalTelegramBot.h>
//#include "DHT.h"
#include <Adafruit_NeoPixel.h>

#define WIFI_SSID "25_home_net2"
#define WIFI_PASSWORD "IWB15n88Neyro"

#define led 14
#define numpixels 5
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numpixels, led, NEO_GRB + NEO_KHZ800);

WiFiClientSecure secured_client;

#define BOT_TOKEN "1853384613:AAFtFWOAq4-YYWk-DMppVAWxH-MxJLTpwSQ"
#define CHAT_ID "649803077" //https://api.telegram.org/bot1853384613:AAFtFWOAq4-YYWk-DMppVAWxH-MxJLTpwSQ/getUpdates
const unsigned long BOT_MTBS = 10000;
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime;
int i = 0;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  configTime (0,0,"pool.ntp.org");
  secured_client.setTrustAnchors(&cert);
  Serial.print("Connecting to WiFi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.print("\nWiFi connected. IP adress: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Hi I'm online!", "");
}

void loop() {
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while(numNewMessages)
    {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    bot_lasttime = millis();
      
  }
}
  void handleNewMessages(int numNewMessages)
  {
    for(int i = 0; i < numNewMessages; i++)
    {
      if(bot.messages[i].chat_id == CHAT_ID)
      {
        String text = bot.messages[i].text;
       }
       

      if(text == "/led")
      {
        ledPix(5);
      }  

      if(text.length() > 4)
      {
        if(text[0] == '/' && text[1] == 'l' && text[2] == 'e' && text[3] == 'd' ) 
        {
          if(text[4] == '0')
            ledPix(0);
          if(text[4] == '1')
            ledPix(1);

          if(text[4] == '2')
            ledPix(2);

          if(text[4] == '3')
            ledPix(3);

          if(text[4] == '4')
            ledPix(4);

          if(text[4] == '5')
            ledPix(5);
          }
        }
        
    
  }

void ledPix(int led)
{  
    for(int i = 0; i < 5; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    pixels.show();
    
    for(int i = 0; i < led; i++)
    {
            pixels.setPixelColor(i, pixels.Color(200,0,0));

      }
      pixels.show();
      
    }
}
