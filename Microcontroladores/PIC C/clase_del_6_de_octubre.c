//This is a program which works as a counter
#include "F:\documentos\Microcontroladores\PIC C\clase_del_6_de_octubre.h"
  #ZERO_RAM
  
void config(); 
void led();   //The context of the program is used as a function
int8 boton=0;  //Declaration of the in data, which starts with a 0 as a value  
int contador; 
void main() 
{ 
   config(); 
   led();   //Program is calling the function   
}
void config() 
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_comparator(NC_NC);
   setup_vref(FALSE);

   // TODO: USER CODE!!

} 
void led() 
{  
   while(TRUE) //while context is TRUE
   { 
   boton = input(PIN_A4); //pin assignation for 'boton' in the 12f675 pic 
     if(boton == 1) 
      {
       loop: 
         delay_ms(1000); //one second time pushing the boton
         contador++;      //starts to count 
         boton = input(PIN_A4); 
          if(boton == 1) 
          { 
           goto loop; 
           contador=contador+1; //boton is pushed for one second 
           boton = input(PIN_A4); 
            if(boton == 1) 
            {  
             goto loop;
              contador=contador+2; //boton is pushed for two seconds
             boton = input(PIN_A4); 
               if(boton == 1) 
               {  
                goto loop;
                contador=contador+3; //boton is pushed for three seconds
                 boton = input(PIN_A4); 
                   if(boton == 1) 
                   {  
                    goto loop;
                      contador=contador+4; //boton is pushed for four seconds
                      }
                     } 
                   } 
          }        
      } 
      else 
      { 
      //this is what should happen when boton is pushed for those seconds 
        switch(contador) 
       { 
         case 1: output_low(PIN_A0); //led off
                 contador=0;  
                 break;
         case 2: while(true)
                 { 
                 if(input(PIN_A4)){contador=0;break;}
                  output_high(PIN_A0); 
                  delay_ms(100); 
                  output_low(PIN_A0); 
                  delay_ms(100);
                 } 
       
                 contador=0; 
                 break;
         case 3: output_high(PIN_A0); //led on
                 contador=0;
                 break;
         case 4: output_low(PIN_A0); //led off 
                 contador=0; 
                 break;
       }
     }
   }
}
  
//if(!input(PIN_A4)){contador=0;break;}




