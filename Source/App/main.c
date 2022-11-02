/*
 * main.c
 *
 *  Created on: Jul 17, 2022
 *      Author: Admin
 */

#include "Source/Middle/Si7020/Si7020.h"
#include "Source/Middle/LDR/ldr.h"
#include "kalman_filter.h"
#include <stdio.h>
#include <stdlib.h>
// Định nghĩa các khoảng thời gian delay giữa 2 lần lấy mẫu, cũng như ngưỡng giới hạn để thay mới dữ liệu hiển thị
#define TEMPHUM_DELAY			10000
#define LIGHT_DELAY				5000
#define TEMP_THRESHOLD			2
#define HUM_THRESHOLD			2
#define LIGHT_THRESHOLD			10
// Khai báo biến sự kiện cập nhật dữ liệu, cũng như các chuỗi ký tự hiển thị và các biến lưu dữ liệu gần nhất
EmberEventControl temphumUpdateEventControl, lightUpdateEventControl;
char tempStr[30] = "";
char humStr[30] = "";
char lightStr[30] = "";
int16_t tempSaved = 0;
uint16_t humSaved = 0;
float lightSaved = 0;

void emberAfMainInitCallback(void)
{
	// Gọi hàm khởi tạo bộ lọc Kalman, khởi tạo các cảm biến, và sự kiện cập nhật dữ liệu
	emberAfCorePrintln("Main Init Callback");
	KalmanFilterInit(5, 5, 0.01);
	I2CTempHum_Init();
	ADCLight_Init();
	emberEventControlSetActive(temphumUpdateEventControl);
	emberEventControlSetActive(lightUpdateEventControl);
}
int16_t Get_Temp(void)
{
	// Lấy dữ liệu nhiệt độ đọc được từ cảm biến để so sánh với dữ liệu lưu gần nhất, nếu thay đổi quá ngưỡng sẽ cập nhật
	int16_t temp = I2CTemp();
	if (abs(temp - tempSaved) >= TEMP_THRESHOLD)
	{
		tempSaved = temp;
		return temp;
	}
	else
	{
		return tempSaved;
	}
}
uint16_t Get_Hum(void)
{
	// Lấy dữ liệu độ ẩm đọc được từ cảm biến để so sánh với dữ liệu lưu gần nhất, nếu thay đổi quá ngưỡng sẽ cập nhật
	uint16_t hum = I2CHum();
	if (abs(hum - humSaved) >= HUM_THRESHOLD)
	{
		humSaved = hum;
		return hum;
	}
	else
	{
		return humSaved;
	}
}
void temphumUpdateEventHandler(void)
{
	// Trong hàm xử lý sự kiện, các dữ liệu nhiệt độ và độ ẩm sẽ được gán vào chuỗi ký tự thông báo và gửi lên màn hình PC
	int16_t Temp = Get_Temp();
	sprintf(tempStr, "Temp = %d oC", Temp);
	emberAfCorePrintln(tempStr);
	uint16_t Hum = Get_Hum();
	sprintf(humStr, "Hum = %d \%", Hum);
	emberAfCorePrintln(humStr);
	emberEventControlSetDelayMS(temphumUpdateEventControl, TEMPHUM_DELAY); // Tạo thời gian nghỉ trước khi lập lại quy trình đọc ghi
}
float Get_Light(void)
{
	uint32_t light = ADCLight();
	float lightData = KalmanFilter_updateEstimate(light);
	if (abs(lightData - lightSaved) >= LIGHT_THRESHOLD)
	{
		lightSaved = lightData;
		return lightData;
	}
	else
	{
		return lightSaved;
	}
}
void lightUpdateEventHandler(void)
{
	uint32_t Light = (uint32_t) Get_Light();
	sprintf(lightStr, "Light = %u lux", Light);
	emberAfCorePrintln(lightStr);
	emberEventControlSetDelayMS(lightUpdateEventControl, LIGHT_DELAY);
}
