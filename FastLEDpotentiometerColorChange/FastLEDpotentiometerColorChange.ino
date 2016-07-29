/* based on the FastLED-tutorials of https://github.com/FastLED/FastLED. Many thanks, awesome stuff :)


 #include <FastLED.h>
    #define NUM_LEDS 64
    #define DATA_PIN 6


CRGB leds[NUM_LEDS];

  void setup() { 
       FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

       // Serial print is not really needed but useful for manual calibrating
       Serial.begin(9600);
       Serial.println("Okay, ready");
   }

void loop() {
  // read the sensor:
  double val = analogRead(2);

  // Use the range value of the potentiometer to map the LEDs to it.
  // I have tried mapping and calibrating min and max value before with code,
  // but this gave strange errors (the last two LEDs wouldnt light up) 
  // so I found it easiest to use the Serial info and just put it in here manually.
        int numLedsToLight = map(val, 0, 990, 0, NUM_LEDS);

        // First, clear the existing led values
        FastLED.clear();
        for(int led = 0; led < numLedsToLight; led++) { 
          
           // uncomment this line if you want a static color transition
           // while turning the LED on one after the other via pot.
           //leds[led] = map(led, 0, NUM_LEDS, CRGB::Blue, CRGB::Red); 
           
           // This lets the colors of the 64 Leds shift from blue to red 
           // while lighting one after the other    
             leds[led] = map(numLedsToLight, 0, NUM_LEDS, CRGB::Blue, CRGB::Red); 
             
        }
       
        FastLED.show();

Serial.println(val);
}
