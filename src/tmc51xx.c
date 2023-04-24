#include "tmc51xx.h"

//https://blog.trinamic.com/2017/04/05/how-to-use-tmc5130-eval-with-your-arduino-mega/
uint8_t init_tmc(struct spi_dt_spec *spi)
{
   write_register(spi,0x00,0x00000000); //GCONF
   k_msleep(SLEEP_TIME);

   write_register(spi,0x6C,0x000101D5); //CHOPCONF: TOFF=5, HSTRT=5, HEND=3, TBL=2, CHM=0 (spreadcycle)
   k_msleep(SLEEP_TIME);

   write_register(spi,0x10,0x00070603); //IHOLD_IRUN: IHOLD=3, IRUN=10 (max.current), IHOLDDELAY=6
   k_msleep(SLEEP_TIME);

   write_register(spi,0x11,0x0000000A); //TPOWERDOWN=10
   k_msleep(SLEEP_TIME);

   write_register(spi,0x70,0x00000000); //PWMCONF
   k_msleep(SLEEP_TIME);

    return 1;
    //sendData(0xF0,0x000401C8); //PWM_CONF: AUTO=1, 2/1024 Fclk, Switch amp limit=200, grad=1
}