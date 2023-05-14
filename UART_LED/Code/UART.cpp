#include "UART.h" //Hämtar vår samlingsfil för header och funktioer 

void USART2_Init(void){ //Deklarera en funktion för att initiera USART-protokollet och dess beståndsdelar

// 1. Enablea klocktillgång för uart2

RCC->APB1ENR |= 0x20000; //Aktiverar UART2 genom att sätta bit 17 i APB1ENR till 1

// 2. Enablea klocktillgång för portA

RCC->AHB1ENR |= 0x01; //Aktiverar GPIO genom att sätta bit 0 i AHB1ENR til ett 1

// 3. Enablea pins relaterade till vald port för alternativ funktion 

GPIO->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2 och PA3 
//samt ~forcerar en invertering som leder till att bitarna som via hex betecknas med 1, i realvärde ersätts med 0

GPIO->MODER |= 0x00A0; //Sätter bitarna 5 och 7 till 1 för att aktivera alternativ funktionalitet på pins PA2 och PA3

// 4    . Välja typen av alternativ funktion för de valda pinsen
GPIO->AFR[0] &= ~0xFF00; //Rensar bitarna 8-15 för att förbereda pins PA2 PA3
GPIO->AFR[0] |= 0x7700; //Sätter vi bitarna 8-11 samt 12-15 till formatet 0111

//* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = Ox0683; //Sätter vi standard baud-rate med hjälp av hexadecimalen 0x0683 (9600bps) 
USART2->CR1 = 0x000C; //Sätter vi tx(transmitter) och rx(receiver) till att arbeta i 8 bitars data. (8 bitars data, 1 stop bit, ingen paritet)
USART2->CR2 = 0x000; //Nollställer CR2  "är ett "control register som inom USART kan sätta konfigurerings alternativ samt flow control och klockan"
USART2->CR3 = 0x000; //Nollställer CR3
USART2->CR1 |= 0x2000; // Omställer bit 13 (UART aktiveringen) till 1

}
// UART Write
int USART2_Write(int ch){ //Deklarerar skrivfunktion (Överföringen av data till terminalen)

  while(!(USART2->SR & 0x0080)){}//busy-wait loop som endast körs om den sjunde biten som står från höger i OR bitwise operatorn har rätt "conditionss". Skulle den sjunde biten stå som 1 så i SR(status register) fortgår programmet. I SR finns info om nuvarande status på USART ex. felmedelanden data trafik och överföring är klar.
    USART2->DR = (ch & 0xFF); //Sätter vi ett krav som kontrollerar att statusen på överföringen är tom och kan ta emot nästa karaktär(byte). DR(DataRegister) är registret för tx(transmitter) rx(reciever och har ansvar för trafiken mellan tx rx och konfigurationen dem emellan. 

    return ch;

}
//UART Read
int USART2_Read(void){ //Deklarerar läsfunktionen (mottagning av information)

    while(!(USART2->SR & 0x0020)){} //Sätter vi ett krav som kontrollerar om det finns mer data att hämta. AND bitwise operator som kolla om den 5e biten är 1 och väntar med att köras tills denna konfiguration är sann.
    return USART2->DR; //Läser ut datan


}
