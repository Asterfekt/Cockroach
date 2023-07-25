/*
 * steps.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Mateusz Krzyściak
 */


#include "main.h"
#include "i2c.h"
#include "steps.h"
#include "math.h"
#include "pca9685.h"

#define SERVO_COUNT	5
 uint8_t ActiveServo;
int stepss()
{
				  PCA9685_SetServoAngle(0, 0);
				  PCA9685_SetServoAngle(1, 0);
				  PCA9685_SetServoAngle(2, 0);
				  HAL_Delay(1000);
				  PCA9685_SetServoAngle(0, 180);
				  PCA9685_SetServoAngle(1, 180);
				  PCA9685_SetServoAngle(2, 180);
				  HAL_Delay(1000);
		//	  for (uint16_t Angle = 45; Angle > 0; Angle--) {
			//	  PCA9685_SetServoAngle(0, Angle);
			//	  PCA9685_SetServoAngle(1, Angle);
			//  }
			//  HAL_Delay(100);
			 if (ActiveServo >= SERVO_COUNT) ActiveServo = 0;
			  return 0;
}
