/*
 * LDR_program.c
 *
 *  Created on: Sep 1, 2023
 *        Authors: Mohamed Abosreea , Ahmed Maher , Kareem Abd Elrasheed , Mohamed Ramadan , Amr Gafer
 */
#include "../../LIB/BIT_MATH.h"

#include "LDR_interface.h"

/*Variable to return ADC value*/
uint32_t LDR1_Read = 0;
uint32_t LDR2_Read = 0;


void ADC0SS0_Handler(void)
{
    //ADCIntRegister(ui32Base, ui32SequenceNum, pfnHandler);
    ADCSequenceDataGet(ADC0_BASE, 0, &LDR1_Read);
    ADCIntClear(ADC0_BASE, 0);          /* clear coversion clear flag bit*/
}

void ADC0SS1_Handler(void)
{

    ADCSequenceDataGet(ADC0_BASE, 1, &LDR2_Read);
    ADCIntClear(ADC0_BASE, 1);          /* clear conversion clear flag bit*/
}

void ldrSensorInit(LDR_Sensor_t *sensor)
{
        /*Enable clock gate for PORTE for PINE2 for ADC0*/
        //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_PLL);
        /*configure pin E2 in analog mode*/
        GPIOPinTypeADC(sensor->ldrPort, sensor ->ldrPin);
        /*configure sequencer 0 to be triggered by processor*/
        ADCSequenceConfigure(ADC0_BASE, sensor->sequencer, ADC_TRIGGER_PROCESSOR, 0);
        /*configure adc step*/
        ADCSequenceStepConfigure(ADC0_BASE, sensor->sequencer, 0, ADC_CTL_END | sensor->adcChannel |ADC_CTL_IE);
        /*Enable Adc sequencer 0 */
        ADCSequenceEnable(ADC0_BASE, sensor->sequencer);

}


void ldrSensorReading(LDR_Sensor_t *sensor)
{
    /*Start adc conversion*/
    ADCProcessorTrigger(ADC0_BASE, sensor->sequencer);
    ADCIntEnable(ADC0_BASE, sensor->sequencer);

    switch(sensor->sequencer)
    {
    case 0:
        SET_BIT(NVIC_EN0_R,14);
        break;
    case 1:
        SET_BIT(NVIC_EN0_R,15);
        break;
    default:
        break;
    }

}
