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

 uint8_t angle;

 int first()
{
	//legs_1 poruszanie
				PCA9685_SetServoAngle(0, 45);
				PCA9685_SetServoAngle(1, 45);
				PCA9685_SetServoAngle(2, 45);
	//Legs_1 podnoszenie
				PCA9685_SetServoAngle(3, 0);
				PCA9685_SetServoAngle(4, 45);
				PCA9685_SetServoAngle(5, 45);
	//legs_2 poruszanie
				PCA9685_SetServoAngle(6, 0);
				PCA9685_SetServoAngle(7, 45);
				PCA9685_SetServoAngle(8, 0);
	//Legs_2 podnoszenie
				PCA9685_SetServoAngle(9, 45);
				PCA9685_SetServoAngle(10, 0);
				PCA9685_SetServoAngle(11, 0);

//	 for (uint8_t Angle = 0; Angle < 45; Angle++) {
	//			 PCA9685_SetServoAngle(3, Angle);
		//	    }
/*

		 for (uint8_t Angle = 0; Angle < 45; Angle++) {
			 // PCA9685_SetServoAngle(2, Angle);
			  PCA9685_SetServoAngle(3, Angle);
		    }
		  HAL_Delay(500);
		  for (uint8_t Angle = 0; Angle < 45; Angle++) {
		 			 PCA9685_SetServoAngle(2, Angle);
		 			//  PCA9685_SetServoAngle(3, Angle);
		 		    }
		 		  HAL_Delay(500);

		  for (uint16_t Angle = 45; Angle > 0; Angle--) {
			 // PCA9685_SetServoAngle(2, Angle);
			  PCA9685_SetServoAngle(3, Angle);
		  }
		  HAL_Delay(500);
		  for (uint8_t Angle = 45; Angle > 0; Angle--) {
		 		 			 PCA9685_SetServoAngle(2, Angle);
		 		 			 // PCA9685_SetServoAngle(3, Angle);
		 		 		    }
		 		 		  HAL_Delay(500);

*/

			 //if (ActiveServo >= SERVO_COUNT) ActiveServo = 0;
			  return 0;
}
int second()
{
//drugie nogi do góry
	                PCA9685_SetServoAngle(9, 0);
					PCA9685_SetServoAngle(10, 45);
					PCA9685_SetServoAngle(11, 45);
			HAL_Delay(500);
			//pierwsze nogi ruch
			PCA9685_SetServoAngle(0, 0);
			PCA9685_SetServoAngle(1, 0);
			PCA9685_SetServoAngle(2, 0);
			HAL_Delay(100);
//drugie nogi w doł
			PCA9685_SetServoAngle(9, 45);
			PCA9685_SetServoAngle(10, 0);
			PCA9685_SetServoAngle(11, 0);
			HAL_Delay(500);
	return 0;
}
int third()
{

			//Legs_1 podnoszenie
						PCA9685_SetServoAngle(3, 45);
						PCA9685_SetServoAngle(4, 0);
						PCA9685_SetServoAngle(5, 0);
						HAL_Delay(100);
			//pierwsze nogi ruch
									PCA9685_SetServoAngle(0, 45);
									PCA9685_SetServoAngle(1, 45);
									PCA9685_SetServoAngle(2, 45);

									PCA9685_SetServoAngle(6, 45);
									PCA9685_SetServoAngle(7, 0);
									PCA9685_SetServoAngle(8, 45);

									HAL_Delay(100);
									PCA9685_SetServoAngle(3, 0);
									PCA9685_SetServoAngle(4, 45);
									PCA9685_SetServoAngle(5, 45);
	return 0;
}
int fourth()
{


			//Legs_2 podnoszenie
				PCA9685_SetServoAngle(9, 0);
				PCA9685_SetServoAngle(10, 45);
				PCA9685_SetServoAngle(11, 45);
						//legs_2 poruszanie
						HAL_Delay(1500);
						PCA9685_SetServoAngle(6, 0);
						PCA9685_SetServoAngle(7, 45);
						PCA9685_SetServoAngle(8, 0);
																					PCA9685_SetServoAngle(2, 45);
	return 0;
}
