
#include "stdint.h"
#ifndef MPU6050_I2C__H
#define MPU6050_I2C__H


void  i2cBasla(void);
void i2cYaz(uint8_t adres,uint8_t veri);
int I2C1_Oku (int adres);


#endif

