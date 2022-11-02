/*
 * ldr.c
 *
 *  Created on: Jul 17, 2022
 *      Author: Admin
 */

#include "ldr.h"

void ADCLight_Init(void)
{
	IADC_Init_t init = IADC_INIT_DEFAULT;
	IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
	IADC_InitSingle_t initSingle = IADC_INITSINGLE_DEFAULT;
	IADC_SingleInput_t initSingleInput = IADC_SINGLEINPUT_DEFAULT;
	// Khởi tạo xung nhịp cho IADC0 và một số thông số cần thiết khác
	CMU_ClockEnable(cmuClock_IADC0, true);
	IADC_reset(IADC0);
	CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);  // FSRCO - 20MHz
	init.warmup = iadcWarmupKeepWarm;
	init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, CLK_SRC_ADC_FREQ, 0);
	initAllConfigs.configs[0].reference = iadcCfgReferenceVddx;
	initAllConfigs.configs[0].vRef = 3300;
	initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0,
										 CLK_ADC_FREQ,
										 0,
										 iadcCfgModeNormal,
										 init.srcClkPrescale);
	initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed32x;
	initSingle.dataValidLevel = _IADC_SINGLEFIFOCFG_DVL_VALID1;
	// Gán chân dương của ADC với chân PC5 và gán chân âm với chân GND
	initSingleInput.posInput   = IADC_INPUT_0_PORT_PIN;
	initSingleInput.negInput   = IADC_INPUT_1_PORT_PIN;
	// Khởi tạo IADC0
	IADC_init(IADC0, &init, &initAllConfigs);
	IADC_initSingle(IADC0, &initSingle, &initSingleInput);
	// Kết nối đầu vào IADC0 qua bus CD
	GPIO->IADC_INPUT_0_BUS |= IADC_INPUT_0_BUSALLOC;
}
uint32_t ADCLight(void)
{
	uint32_t res, light;
	IADC_Result_t sample;
	IADC_command(IADC0, iadcCmdStartSingle);
	// Đợi quá trình chuyển đổi hoàn tất
	while((IADC0->STATUS & (_IADC_STATUS_CONVERTING_MASK
			  | _IADC_STATUS_SINGLEFIFODV_MASK)) != IADC_STATUS_SINGLEFIFODV);
	// Đọc kết quả và tính ra giá trị cường độ sáng
	sample = IADC_pullSingleFifoResult(IADC0);
	res = 10000*(3300-sample.data)/sample.data;
	light = 316*pow(10,5)*pow(res,-1.4);
	return light;
}
