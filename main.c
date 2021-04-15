
#include "stm32f4xx.h"                  
#include "rcc.h"
#include "mpu6050_i2c.h"


int powerRegister=0;
int whoIam=0;

int ivmeX=0,ivmeY=0,ivmeZ=0;
int gyroX=0,gyroY=0,gyroZ=0;
float icSicaklik=0;
float aX=0,aY=0,aZ=0;
float gX=0,gY=0,gZ=0;

void bekle(uint32_t sure)
{

while(sure--);
}


void hazirla()
{

	while(powerRegister!=64)  
	{
	powerRegister=I2C1_Oku(0x6B); //0x40 reset degeri.
	}
	
	while(whoIam!=104)  
	{
	whoIam=I2C1_Oku(0x75); //0x68 reset degeri.
	}
	
}

int main()
	
{
	
	RCC_Ayar();
	SystemCoreClockUpdate();//168 MHZ 
	i2cBasla();
 // hazirla();
	powerRegister=I2C1_Oku(0x6B);
	whoIam=I2C1_Oku(0x75);
	i2cYaz(0x6B,0x00);//Uyku modundan cikarmak icin.
	i2cYaz(0x19,0x07);//1khz accelometre icin.

while(1)
{
	
	ivmeX=(int16_t)(I2C1_Oku(0x3C)+256*I2C1_Oku(0x3B));
	ivmeY=(int16_t)(I2C1_Oku(0x3E)+256*I2C1_Oku(0x3D));
	ivmeZ=(int16_t)(I2C1_Oku(0x40)+256*I2C1_Oku(0x3F));
	
	gyroX=(int16_t)(I2C1_Oku(0x44)+256*I2C1_Oku(0x43));
	gyroY=(int16_t)(I2C1_Oku(0x46)+256*I2C1_Oku(0x45));
	gyroZ=(int16_t)(I2C1_Oku(0x48)+256*I2C1_Oku(0x47));
	
	icSicaklik=(int16_t)(I2C1_Oku(0x42)+256*I2C1_Oku(0x41));
	icSicaklik=icSicaklik/340;
	icSicaklik +=36.53;
	
	aX=ivmeX/16384.0;
	aY=ivmeY/16384.0;
	aZ=ivmeZ/16384.0;
	
	gX=gyroX/131.0;
	gY=gyroY/131.0;
	gZ=gyroZ/131.0;
	
	bekle(80000000);

}

}







