#include <Arduino.h>

const int LED_PIN = PIN3;
const int MIN_B = 0;
const int MAX_B = 60;
const int FADE_IN_TIME = 1000;
const int FADE_OUT_TIME = 2000;
const int DWELL_ON = 3000;
const int DWELL_OFF = 2000;

const int FRAME = 16;
const int B_RANGE = MAX_B - MIN_B;
const int FADE_IN_STEP = floor(FADE_IN_TIME / FRAME / B_RANGE);
const int FADE_OUT_STEP = floor(FADE_OUT_TIME / FRAME / B_RANGE);

int brightness = MIN_B;
bool fadeUp = true;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  analogWrite(LED_PIN, brightness);
  if (brightness == MIN_B)
  {
    delay(DWELL_OFF);
  }
  else if (brightness == MAX_B)
  {

    delay(DWELL_ON);
  }

  if (fadeUp)
  {
    brightness += FADE_IN_STEP;
    if (brightness >= MAX_B)
    {
      brightness = MAX_B;
      fadeUp = false;
    }
  }
  else
  {
    brightness -= FADE_OUT_STEP;
    if (brightness <= MIN_B)
    {
      brightness = MIN_B;
      fadeUp = true;
    }
  }

  delay(FRAME);
}
