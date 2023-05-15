#include "LED.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner

//Konstruktorn för LED-lamporna
//color samt state värdena finns som enums i led.h
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  this->color = _color;//color och state attributen tas från den privata klassen som finns i Led.h filen  med "this" funktionen och sätter dem lika med _color _state
  this->state = _state;//
  
  //Enablea klockan för LED-porten (GPIOB) med ett AHB1 register som har en maximal domän frekvens på 100MHz "ENR = enable"
  RCC->AHB1ENR |= LED_PORT_CLOCK;
  
  //Konfigurera LED-pinsen baserad på deras färg och status
  //Switch-sats som kollar LED färg.
  switch(_color){
  
    case RED: //Sätta portläget för LED-konfigurationen till output
      //MODER registret styr vilket värde eller MODE pinnen skall ha. EX. Output eller Input.
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        //Sätter på LED
	//ODR styr man outputen med och i dett fall så sätter man output som ON.
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Stänga av LED
	//Sätter output till OFF
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;
     
      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Sätter på LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;
         
      case BLUE: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Sätter på LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;
               
      case GREEN: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Sätter  på LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  
  }
  
  
}
               
void Led::setState(LedState_Type _state){

  //Sätta statusen av LED:n ON=1, OFF=0
  this->state = _state;
  
x  //Kolla färgen på LED för att veta att korrekt LED manipuleras
  switch(this->color){
  
      //om LED Röd
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;
            
      case YELLOW:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;
               
      case BLUE:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;
               
      case GREEN:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  //Kontrollera färgen av den LED som efterfrågas, printa sedan statusen
  switch(this->color){
  
    case RED:
      break;
             
    case YELLOW:
      break;
             
    case BLUE:
      break;
             
    case GREEN:
      break;
  }
             //Returnerar LED-lampans status av vald färg
             return this->state;
}
