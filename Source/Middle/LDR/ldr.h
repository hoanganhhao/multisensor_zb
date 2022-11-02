/*
 * ldr.h
 *
 *  Created on: Jul 17, 2022
 *      Author: Admin
 */

#include "app/framework/include/af.h"
#include <stdio.h>
#include "em_cmu.h"
#include "em_iadc.h"
#include "em_gpio.h"
#include "hal-config.h"

#ifndef SOURCE_MIDDLE_LDR_LDR_H_
#define SOURCE_MIDDLE_LDR_LDR_H_

#define CLK_SRC_ADC_FREQ            20000000
#define CLK_ADC_FREQ                10000000

#define IADC_INPUT_0_PORT_PIN     iadcPosInputPortCPin5;
#define IADC_INPUT_1_PORT_PIN     iadcNegInputGnd;

#define IADC_INPUT_0_BUS          CDBUSALLOC
#define IADC_INPUT_0_BUSALLOC     GPIO_CDBUSALLOC_CDODD0_ADC0
#define IADC_INPUT_1_BUS          CDBUSALLOC
#define IADC_INPUT_1_BUSALLOC     GPIO_CDBUSALLOC_CDEVEN0_ADC0

void ADCLight_Init(void);
uint32_t ADCLight(void);

#endif /* SOURCE_MIDDLE_LDR_LDR_H_ */
