#include <16F877A.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES RESERVED                 //Used to set the reserved FUSE bits 

#use delay(clock=4000000) 
  #define LCD_ENABLE_PIN PIN_D0 
  #define LCD_RS_PIN     PIN_D1 
  #define LCD_RW_PIN     PIN_D2
  #define LCD_DATA4      PIN_D4 
  #define LCD_DATA5      PIN_D5 
  #define LCD_DATA6      PIN_D6 
  #define LCD_DATA7      PIN_D7 

