#include "F:\documentos\Microcontroladores\PIC C\lector_devoltaje_18\lector_voltaje.h"
  #ZERO_RAM 
  
void conf(); 
void program();
int8 valor;
void main()
{ 
 conf(); 
 program();
}
void conf()
{

   setup_adc_ports(AN0|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE); 
   //set_adc_channel(0);
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   // TODO: USER CODE!! 
   

} 
void program()
{ 
  while(true) 
 { 
  //delay_us(50);
   valor=read_adc(); 
    //int voltaje=(valor*5)/1023.0; 
    //output_high(valor); 
    if(valor == 1) 
     { 
      output_high(PIN_A3); 
      output_low(PIN_A1); 
      output_low(PIN_A2);
     } 
      else if(valor == 2) 
      { 
       output_high(PIN_A2); 
       output_low(PIN_A3); 
      output_low(PIN_A1); 
      } 
       else if(valor == 3) 
      { 
       output_high(PIN_A2); 
       output_high(PIN_A3); 
      output_low(PIN_A1); 
      } 
       else if(valor == 4) 
      { 
       output_low(PIN_A2); 
       output_low(PIN_A3); 
      output_high(PIN_A1); 
      } 
       else if(valor == 5) 
      { 
       output_low(PIN_A2); 
       output_high(PIN_A3); 
      output_high(PIN_A1); 
      } 
     //delay_ms(100);
 }
}
