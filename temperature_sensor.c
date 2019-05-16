#include "temp.h"
#include <stdint.h>
#include "ADC.h"
#include "tm4c123gh6pm.h"

#define ADC0_SS0_PRI 			0x3
#define ADC0_SS1_PRI 			(0x2 << 4)
#define ADC0_SS2_PRI 			(0x1 << 8)
#define ADC0_SS3_PRI 			(0x0 << 12)
#define ADC0_ACTSS_SS3 		0x8
#define ADC0_EMUX_SS3			(0x0 << 12) // Processor Trigger
#define ADC0_SSMUX3				0x0					// AIN0 (PE3)
#define ADC0_SSCTL3_IE0		(0x1 << 2)
#define ADC0_SSCTL3_END0	(0x1 << 1)
#define ADC0_PSSI_SS3			(0x1 << 3)
#define ADC0_RIS_INR3			(0x1 << 3)
#define GPIO_PE3_M				(0x1 << 3)

double Temperature_sensor(void)
{
	volatile unsigned long ADC_Output=0;
	volatile  double Temp_O=0;
	/*ADC_INIT();
	ADC0_SS3_In(uint16_t *data)*/
	ADC0_PSSI_R = ADC0_PSSI_SS3;
	//while((ADC0_RIS_R & 0x8) == 0);                 /* wait for conversion complete */
	//ADC_Output=ADC0_SSFIFO3_R & 0xFFF;
	while((ADC0_RIS_R&ADC0_RIS_INR3)!=ADC0_RIS_INR3);
	ADC_Output = ADC0_SSFIFO3_R&0xFFF;
	Temp_O = 147 - (247 *ADC_Output ) / 4096; 
	ADC0_ISC_R = ADC0_RIS_INR3;
	// read result
/////	Temp_O = 147 - (247 *ADC_Output ) / 4096;       //TEMP = 147.5 - ((75 * (VREFP - VREFN) × ADCCODE) / 4096)
	//ADC0_ISC_R = 0x8;                              /* clear completion flag */
	
	return Temp_O;
}
