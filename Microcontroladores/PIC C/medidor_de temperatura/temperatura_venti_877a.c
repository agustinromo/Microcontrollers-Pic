#include "F:\documentos\Microcontroladores\PIC C\medidor_de temperatura\temperatura_venti_877a.h"
  #ZERO_RAM 
  #include <lcd.c>

float temperatura;
void main()
{

   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   // TODO: USER CODE!! 
   lcd_init(); 
   lcd_gotoxy(5,1);  
   printf(lcd_putc,"Temperatura"); //este aparece arriba
   delay_ms(350); 
   lcd_init(); 
 while(true) 
    { 
    temperatura= read_adc()/2; //grados centigrados
    lcd_gotoxy(5,1); 
    printf(lcd_putc,"%f",temperatura); 
    lcd_gotoxy(14,1); 
    printf(lcd_putc,"°C"); 
    delay_ms(200); 
    
    if(temperatura >=23) 
     { 
      output_high(PIN_A1); 
      lcd_gotoxy(5,2);
      printf(lcd_putc,"Ventilador on"); 
      delay_ms(200);
     } 
      else 
       { 
        output_low(PIN_A1); 
         lcd_gotoxy(5,2);
         printf(lcd_putc,"Chido clima"); //este va abajo
         delay_ms(200);
       }
   }

}
