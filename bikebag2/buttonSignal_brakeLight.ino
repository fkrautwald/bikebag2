
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      6
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100;
int button = 4;
int buttonState = 0;


void setup()
{
  pinMode(button, INPUT);

  pixels.begin();
  pixels.setBrightness(225);

  pinMode(NUMPIXELS, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}

void loop() {

  buttonState = digitalRead(button);
  int digitalVal = digitalRead(2);

  {
    if (buttonState == HIGH) {
      for (int i = 0; i < NUMPIXELS; i++) {

        pixels.setPixelColor(i, pixels.Color(250, 0, 0));
        pixels.show();
        delay(delayval);
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
        delay(25);
        pixels.setPixelColor(1, pixels.Color(0, 255, 0));
        delay(25);
        pixels.setPixelColor(2, pixels.Color(0, 255, 0));
        delay(25);
        pixels.setPixelColor(3, pixels.Color(0, 255, 0));
        delay(25);
        pixels.setPixelColor(4, pixels.Color(0, 255, 0));
        delay(25);
        pixels.setPixelColor(5, pixels.Color(0, 255, 0));
        delay(delayval);
      }
    }

  }

  for (int i = 0; i < NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();

  }

  if (HIGH == digitalVal)
  {
    for (int i = 0; i < NUMPIXELS; i++) {

      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      pixels.show();

    }

    for (int i = 0; i < NUMPIXELS; i++) {

      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      pixels.show();

    }
  }

  else if ((LOW == digitalVal)) {
    {
      for (int i; i < NUMPIXELS; i++) {

        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
        pixels.show();


      }
    }
  }
}
