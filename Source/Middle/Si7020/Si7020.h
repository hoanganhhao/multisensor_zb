/*
 * Si7020.h
 *
 *  Created on: Jul 17, 2022
 *      Author: Admin
 */

#include "app/framework/include/af.h"
#include "em_i2c.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "hal-config.h"

#ifndef SOURCE_MIDDLE_SI7020_SI7020_H_
#define SOURCE_MIDDLE_SI7020_SI7020_H_

// Định nghĩa địa chỉ cảm biến
#define TEMPHUM_ADDR			0x40
// Định nghĩa các mã lệnh có thể gửi tới cảm biến
#define CMD_HUM_HOLD			0xE5
#define CMD_HUM_NOHOLD			0xF5
#define CMD_TEMP_HOLD			0xE3
#define CMD_TEMP_NOHOLD			0xF3
#define CMD_TEMP_FROM_HUM		0xE0

void I2CTempHum_Init(void);
int16_t I2CTemp(void);
uint16_t I2CHum(void);

#endif /* SOURCE_MIDDLE_SI7020_SI7020_H_ */
