/*
 * Si7020.c
 *
 *  Created on: Jul 17, 2022
 *      Author: Admin
 */

#include "Si7020.h"

void I2CTempHum_Init(void)
{
	// Cấp xung nhịp cho các chân GPIO và module I2C0
	CMU_ClockEnable(cmuClock_I2C0, true);
	CMU_ClockEnable(cmuClock_GPIO, true);
	// Gán giá trị khởi tạo mặc định cho I2C, ngoài trừ tần số clock đặt là 400 KHz và tỷ lệ xung thấp/cao là 6/3
	I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
	i2cInit.freq = I2C_FREQ_FAST_MAX;
	i2cInit.clhr = i2cClockHLRAsymetric;
	// Khởi tạo các chân PB0 và PB1 cho I2C
	GPIO_PinModeSet(BSP_I2C0_SCL_PORT, BSP_I2C0_SCL_PIN, gpioModeWiredAndPullUpFilter, 1);
	GPIO_PinModeSet(BSP_I2C0_SDA_PORT, BSP_I2C0_SDA_PIN, gpioModeWiredAndPullUpFilter, 1);
	// Thiết lập chân PB0 thành SCL và PB1 thành SDA
	GPIO->I2CROUTE[0].SDAROUTE = (GPIO->I2CROUTE[0].SDAROUTE & ~_GPIO_I2C_SDAROUTE_MASK)
	                        | (gpioPortB << _GPIO_I2C_SDAROUTE_PORT_SHIFT
	                        | (1 << _GPIO_I2C_SDAROUTE_PIN_SHIFT));
	GPIO->I2CROUTE[0].SCLROUTE = (GPIO->I2CROUTE[0].SCLROUTE & ~_GPIO_I2C_SCLROUTE_MASK)
							| (gpioPortB << _GPIO_I2C_SCLROUTE_PORT_SHIFT
							| (0 << _GPIO_I2C_SCLROUTE_PIN_SHIFT));
	GPIO->I2CROUTE[0].ROUTEEN = GPIO_I2C_ROUTEEN_SDAPEN | GPIO_I2C_ROUTEEN_SCLPEN;
	// Khởi tạo I2C0
	I2C_Init(I2C0, &i2cInit);
	I2C0->CTRL = I2C_CTRL_AUTOSN;
}
int16_t I2CTemp(void)
{
	// Khởi tạo các biến kiểu chuỗi dữ liệu truyền, biến kiểu chuỗi dữ liệu nhận về, mảng lưu dữ liệu nhận, và một số biến cần thiết khác
	I2C_TransferSeq_TypeDef seg;
	I2C_TransferReturn_TypeDef result;
	uint16_t data;
	int16_t temp;
	uint16_t addrTempHum = TEMPHUM_ADDR << 1;
	uint8_t cmd;
	uint8_t bufRx[2];
	// Gán địa chỉ cảm biến cho thành phần địa chỉ của chuỗi dữ liệu truyền; tương tự là lệnh đọc dữ liệu nhiệt độ, mảng lưu dữ liệu nhiệt độ
	cmd = CMD_TEMP_HOLD;
	seg.addr = addrTempHum;
	seg.flags = I2C_FLAG_WRITE_READ;
	seg.buf[0].len = 1;
	seg.buf[0].data = &cmd;
	seg.buf[1].len = 2;
	seg.buf[1].data = bufRx;
	// Bắt đầu quy trình đọc dữ liệu nhiệt độ qua I2C0, và chờ quá trình hoàn tất
	result = I2C_TransferInit(I2C0, &seg);
	while (result == i2cTransferInProgress)
	{
		result = I2C_Transfer(I2C0);
	}
	// Nếu cờ trạng thái báo việc đọc dữ liệu thành công, bắt đầu tính ra nhiệt độ theo công thức
	if (result == i2cTransferDone)
	{
		data = (uint16_t) bufRx[0] << 8;
		data |= bufRx[1];
		temp = (175.72 * (int16_t) data) / 65536 - 46.85;
		return temp;
	}
	else // Nếu cờ trạng thái không báo việc đọc dữ liệu thành công, nhiều khả năng xảy ra lỗi, nên lúc này trả về nhiệt độ 0 và báo lỗi
	{
		emberAfCorePrintln("Transfer Of Temperature Data Not Done");
		return 0;
	}
}
uint16_t I2CHum(void)
{
	// Khởi tạo các biến kiểu chuỗi dữ liệu truyền, biến kiểu chuỗi dữ liệu nhận về, mảng lưu dữ liệu nhận, và một số biến cần thiết khác
	I2C_TransferSeq_TypeDef seg;
	I2C_TransferReturn_TypeDef result;
	uint16_t data;
	uint16_t hum;
	uint16_t addrTempHum = TEMPHUM_ADDR << 1;
	uint8_t cmd;
	uint8_t bufRx[2];
	// Gán địa chỉ cảm biến cho thành phần địa chỉ của chuỗi dữ liệu truyền; tương tự là lệnh đọc dữ liệu độ ẩm, mảng lưu dữ liệu độ ẩm
	cmd = CMD_HUM_HOLD;
	seg.addr = addrTempHum;
	seg.flags = I2C_FLAG_WRITE_READ;
	seg.buf[0].len = 1;
	seg.buf[0].data = &cmd;
	seg.buf[1].len = 2;
	seg.buf[1].data = bufRx;
	// Bắt đầu quy trình đọc dữ liệu độ ẩm qua I2C0, và chờ quá trình hoàn tất
	result = I2C_TransferInit(I2C0, &seg);
	while (result == i2cTransferInProgress)
	{
		result = I2C_Transfer(I2C0);
	}
	// Nếu cờ trạng thái báo việc đọc dữ liệu thành công, bắt đầu tính ra độ ẩm theo công thức
	if (result == i2cTransferDone)
	{
		data = (uint16_t) bufRx[0] << 8;
		data |= bufRx[1];
		hum = (125 * data) / 65536 - 6;
		return hum;
	}
	else // Nếu cờ trạng thái không báo việc đọc dữ liệu thành công, nhiều khả năng xảy ra lỗi, nên lúc này trả về độ ẩm 0 và báo lỗi
	{
		emberAfCorePrintln("Transfer Of Humidity Data Not Done");
		return 0;
	}
}
