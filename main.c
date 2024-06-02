#include <18F4550.h>
#use delay(clock=20000000)

#FUSES NOMCLR
#FUSES NOWDT                    // No Watch Dog Timer
#FUSES HS                       // High speed Osc (> 4mhz)
#FUSES NOPROTECT                // Code not protected from reading
#FUSES NOBROWNOUT               // No brownout reset
#FUSES NOPUT                    // No Power Up Timer
#FUSES NOLVP                    // Low Voltage Programming on B3(PIC16) or B5(PIC18)
#FUSES NOWRT

#use rs232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7)

void main()
{
   setup_adc_ports(NO_ANALOGS|VREF_VREF);
   setup_timer_3(T3_DISABLED | T3_DIV_BY_1);
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_4);
   setup_timer_2(T2_DIV_BY_16,241,13);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   while (TRUE) {
      int value = 5;
      printf("%d", value);
      printf("\n");
      delay_ms(1000);
   }
}
