#include <stdbool.h>
#include "./lib.h"

#define motorPin1 2
#define motorPin2 3
#define motorPin3 4
#define motorPin4 5

void setup(void);
void loop(void);

int main(void)
{ 
  setup();

  while(true)
  {
    loop();
  }

  return 0;
}

void setup(void)
{
  DDRD |= (1 << motorPin4) | (1 << motorPin3) | (1 << motorPin2) | (1 << motorPin1);
  PORTD &= ~(_BV(PORTD5) | _BV(PORTD4) | _BV(PORTD3) | _BV(PORTD2));
}

void loop(void)
{
  pasoCompleto();
  _delay_ms(2000);
  PORTD &= ~(_BV(PORTD5) | _BV(PORTD4) | _BV(PORTD3) | _BV(PORTD2));
  pasoUnipolar();
  _delay_ms(2000);
}
