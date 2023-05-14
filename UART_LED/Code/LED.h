#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h"
#include "stm32f4xx.h" //Device Header för enhetsspecifika angivelser om hårdvaran

//Definera vilken GPIO pin som skall vara ansvarig för LED-funktionen
#define LED_PORT GPIOB

//Definerar klocksignalen för porten
#define LED_PORT_CLOCK (1U<<1)


//Definierar konstanter för pinsen till LED-färgerna så att specifika pins kan kontrolleras.
#define LED_RED_PIN (1U<<14)//Sätter den 14e bit:en räknat från höger med värdet 1 och resten till 0.
#define LED_GREEN_PIN (1U<<12)//Sätter den 12e bit:en räknat från höger med värdet 1 och resten till 0.
#define LED_BLUE_PIN (1U<<15)//Sätter den 15e bit:en räknat från höger med värdet 1 och resten till 0.
#define LED_YELLOW_PIN (1U<<13)//Sätter den 13e bit:en räknat från höger med värdet 1 och resten till 0.

//Definerar konstanter för mode bits som är tilldelade olika LED-färger. Detta för att konfigurera vilket LED "mode". 
#define LED_RED_MODE_BIT (1U<<28)//Sätter den 28e bit:en räknat från höger med värdet 1 och resten till 0.
#define LED_GREEN_MODE_BIT (1U<<24)//Sätter den 24e bit:en räknat från höger med värdet 1 och resten till 0.
#define LED_YELLOW_MODE_BIT (1U<<26)//Sätter den 26e bit:en räknat från höger med värdet 1 och resten till 0.
#define LED_BLUE_MODE_BIT (1U<<30)//Sätter den 30e bit:en räknat från höger med värdet 1 och resten till 0.

//Definerar de olika LED-färgerna som finns med värdena incrementerat från 0-3. 
typedef enum {
  RED = 0,
  GREEN,//="1"
  YELLOW,//="2"
  BLUE//="3"
}LedColor_Type;

//Definerar numrerar de två olika lägena som LED kan befinna sig i.
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;

// Definerar de attribut som LED består utav
class Led{

private: //De två attribut som LED har finns privat och kan bara kallas på inom klassen Led.
      LedColor_Type color; 
      LedState_Type state;
  
  public:
  
  Led(LedColor_Type _color,LedState_Type _state);//Konstruktor som tar färg och status(mode) som argument.
  void setState(LedState_Type _state);//Funktion för setter för att kunna ta värden från privata color och state
  LedState_Type getState() const;//Funktion för getter för att kunna ta värden från privata color och state

};

#endif
