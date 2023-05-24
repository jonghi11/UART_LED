#include "led.h"

LedState_Type led1_state;//Från led.h, har lägen OFF=0, ON=1
LedState_Type led1_state;
LedState_Type led1_state;

//Från led klassen, ny instans som svarar på argumenten för color, state och ger värdena RED,ON för led1.
Led led1(RED,ON);

int main(void){ //huvudfunktion konstruerar och hanterar LED-lamporna
  USART2_Init();
  //Från led klassen, ny instans som svarar på argumenten för color, state och ger värdena BLUE,ON för led2.
  Led led2(BLUE,ON);
  //Från led klassen, ny instans som svarar på argumenten för color, state och ger värdena YELLOW,ON för led3. Skapad som en pekare. Skapas inte i Stack utan i heap.
  Led *led3 = new Led(YELLOW,ON);
  //Getter som returnerar det som sats för led1. (RED,ON)
  led1_state = led1.getState();
  //Setter som ger argument att statusen skall vara OFF
  led1.setState(OFF);
  //Tar bort och led3 och frigör minne.
  delete led3;
  //Loop som kör tillsvidare. Stänger ej ner program.
  while(1){}
  
}
