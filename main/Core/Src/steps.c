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

//#define SERVO_COUNT	5

//Opuszczone Kończyny
#define legs1_3_Down	0
#define legs1_4_Down	45
#define legs1_5_Down	30

#define legs2_9_Down	45
#define legs2_10_Down	0
#define legs2_11_Down	15
//Podniesione Kończyny
#define legs1_3_Up	45
#define legs1_4_Up	0
#define legs1_5_Up	0

#define legs2_9_Up	0
#define legs2_10_Up	45
#define legs2_11_Up	45

//Ruch kończyn POCZĄTEK
#define legs1_0_START	45
#define legs1_1_START	45
#define legs1_2_START	45

#define legs2_6_START	0
#define legs2_7_START	45
#define legs2_8_START	0
//KONIEC
#define legs1_0_END	0
#define legs1_1_END	0
#define legs1_2_END	0

#define legs2_6_END	45
#define legs2_7_END	0
#define legs2_8_END	45

 uint8_t ActiveServo;

 uint8_t angle;

 int Set()
{
	//legs_1 Początkowy
				PCA9685_SetServoAngle(0, legs1_0_START);
				PCA9685_SetServoAngle(1, legs1_1_START);
				PCA9685_SetServoAngle(12, legs1_2_START);
	//Legs_1 Opuszczanie nóg
				PCA9685_SetServoAngle(3, legs1_3_Down);
				PCA9685_SetServoAngle(4, legs1_4_Down);
				PCA9685_SetServoAngle(5, legs1_5_Down);
	//legs_2 poruszanie
				PCA9685_SetServoAngle(6, legs2_6_START);
				PCA9685_SetServoAngle(7, legs2_7_START);
				PCA9685_SetServoAngle(8, legs2_8_START);
	//Legs_2 Opuszczanie
				PCA9685_SetServoAngle(9,  legs2_9_Down);
				PCA9685_SetServoAngle(10, legs2_10_Down);
				PCA9685_SetServoAngle(11, legs2_11_Down);

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
int first()
/* W tej pozycji podnoszą się nogi z pary odnóży pierwszej a odnóża z drugiej
 * pary dokonują ruchu */
{
					PCA9685_SetServoAngle(3, legs1_3_Up);
					PCA9685_SetServoAngle(4, legs1_4_Up);
					PCA9685_SetServoAngle(5, legs1_5_Up);
					HAL_Delay(500);
					PCA9685_SetServoAngle(6, legs2_6_END);
					PCA9685_SetServoAngle(7, legs2_7_END);
					PCA9685_SetServoAngle(8, legs2_8_END);

	return 0;
}
int second()
/* W tej pozycji wystepuje wymiana odnózy na ziemi  */
{
						PCA9685_SetServoAngle(3, legs1_3_Down);
						PCA9685_SetServoAngle(4, legs1_4_Down);
						PCA9685_SetServoAngle(5, legs1_5_Down);
						HAL_Delay(300);
						PCA9685_SetServoAngle(9,  legs2_9_Up);
						PCA9685_SetServoAngle(10, legs2_10_Up);
						PCA9685_SetServoAngle(11, legs2_11_Up);


	return 0;
}
int third()
{
					PCA9685_SetServoAngle(0, legs1_0_END);
					PCA9685_SetServoAngle(1, legs1_1_END);
					PCA9685_SetServoAngle(12, legs1_2_END);
					HAL_Delay(300);
					PCA9685_SetServoAngle(6, legs2_6_START);
					PCA9685_SetServoAngle(7, legs2_7_START);
					PCA9685_SetServoAngle(8, legs2_8_START);																PCA9685_SetServoAngle(2, 45);
	return 0;
}
int forth()
{
					PCA9685_SetServoAngle(9,  legs2_9_Down);
					PCA9685_SetServoAngle(10, legs2_10_Down);
					PCA9685_SetServoAngle(11, legs2_11_Down);
					HAL_Delay(300);
					PCA9685_SetServoAngle(3, legs1_3_Up);
					PCA9685_SetServoAngle(4, legs1_4_Up);
					PCA9685_SetServoAngle(5, legs1_5_Up);															PCA9685_SetServoAngle(2, 45);
	return 0;
}
int five()
{
					PCA9685_SetServoAngle(0, legs1_0_START);
					PCA9685_SetServoAngle(1, legs1_1_START);
					PCA9685_SetServoAngle(12, legs1_2_START);
					HAL_Delay(300);
					PCA9685_SetServoAngle(6, legs2_6_END);
					PCA9685_SetServoAngle(7, legs2_7_END);
					PCA9685_SetServoAngle(8, legs2_8_END);
																				PCA9685_SetServoAngle(2, 45);
	return 0;
}
