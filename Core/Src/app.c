/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: rlawj
 */
#include "app.h"
#include "math.h"
// 장치 선언
extern TIM_HandleTypeDef htim1;

void setDuty(uint8_t r, uint8_t g, uint8_t b){
	htim1.Instance->CCR1 = r * 10;
	htim1.Instance->CCR2 = g * 10;
	htim1.Instance->CCR3 = b * 10;
	print("fun start");
}

void app(){
	// 타이머 장치 시작 (타이머는 따로 시작 명령을 줘야 동작함)
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	while(1){
		static int angle_r = 0;
		static int angle_g = 120;
		static int angle_b = 240;
		angle_r++;
		angle_g++;
		angle_b++;
		angle_r %= 360;
		angle_g %= 360;
		angle_b %= 360;
		uint8_t sin_r = sin(angle_r * M_PI / 180) * 50 + 49;
		uint8_t sin_g = sin(angle_g * M_PI / 180) * 50 + 49;
		uint8_t sin_b = sin(angle_b * M_PI / 180) * 50 + 49;
		setDuty(sin_r, sin_g, sin_b);
		HAL_Delay(10);
	}
}
