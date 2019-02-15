#include "F:\documentos\Microcontroladores\PIC C\lector_devoltaje_18\lector_fotoresistor.h"
  #ZERO_RAM
#include <lcd.c> 
float voltaje;

void main()
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
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   // TODO: USER CODE!!  
   lcd_init(); 
   lcd_gotoxy(5,1);  
   printf(lcd_putc,"Voltaje"); 
   delay_ms(350); 
   lcd_init();
   while(true)
   { 
    voltaje = read_adc(); 
    lcd_gotoxy(5,1); 
    printf(lcd_putc,"%f",voltaje); 
    lcd_gotoxy(14,1); 
    printf(lcd_putc,"v"); 
    delay_ms(200);
   }

}
