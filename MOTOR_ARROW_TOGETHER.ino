

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <JC_Button.h>  



#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

const byte
    BUTTON_PIN(7),              // connect a button switch from this pin to ground
LED_PIN(13);   
    Button myBtn(BUTTON_PIN);  



#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif



void setup()   {        
  myBtn.begin();        
   pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1);

  // Clear the buffer.
  display.clearDisplay();

 


  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Motor 1");


  display.display();
  delay(2000);
  display.clearDisplay();

 

   
  
  delay(1);
}


void loop()
{
  
    static bool ledState;       // a variable that keeps the current LED status
    myBtn.read();               // read the button

    if (myBtn.wasReleased())    // if the button was released, change the LED state
    {
        display.clearDisplay();
          display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Motor 2");
   display.display();
        ledState = !ledState;
          display.clearDisplay();
          display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Motor 1");
   display.display();
        digitalWrite(LED_PIN, ledState);
        Serial.println(ledState);
    }
}
