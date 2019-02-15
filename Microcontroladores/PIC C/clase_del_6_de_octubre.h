#include <12F675.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES INTRC_IO                 //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOCPD                    //No EE protection
#FUSES MCLR                     //Master Clear pin used for I/O
#FUSES PUT                      //Power Up Timer
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES BANDGAP_HIGH   
#FUSES RESERVED

#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_A3,rcv=PIN_A2,bits=8)

