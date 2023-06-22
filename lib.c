#include "./lib.h"

void pasoCompleto(void)
{
  for(int i = 0; i < 512; i++)
  {
    PORTD |= _BV(PORTD5);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD5);
    PORTD |= _BV(PORTD4);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD4);
    PORTD |= _BV(PORTD3);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD3);
    PORTD |= _BV(PORTD2);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD2); 
  }
}

void pasoUnipolar(void)
{
  for(int i = 0; i < 512; i++)
  {
    PORTD |= _BV(PORTD5) | _BV(PORTD4);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD5);
    PORTD |= _BV(PORTD3);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD4);
    PORTD |= _BV(PORTD2);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD3);
    PORTD |= _BV(PORTD5);
    _delay_ms(10);
    PORTD &= ~_BV(PORTD2) & ~_BV(PORTD5);
  }
}
