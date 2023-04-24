#include "main.h"


uint8_t buffer_tx[BUF_SIZE] = {0xAA, 0xBB, 0xCC, 0xDD, 0xFF};
uint8_t buffer_rx[BUF_SIZE] = {};

uint8_t ret;

uint8_t rx_test[BUF_SIZE]={0,0,0,0,0};
uint32_t rx_test_value = 0;

void main(void)
{


    printk("Hi \n");
   
   init_tmc(&spi_com);
//------------ Init Done --------------------
/*    write_register(&spi_com,0x24,0x000003E8);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x25,0x000186A0);
   k_msleep(SLEEP_TIME);
   
   write_register(&spi_com,0x26,0x0000C350);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x27,0x000186A0);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x2A,0x00000578);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x2B,0x0000000A);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x20,0x00000000);
   k_msleep(SLEEP_TIME);
   
   write_register(&spi_com,0x21,0x00000000);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x2D,0x00000000);
   k_msleep(SLEEP_TIME);

   write_register(&spi_com,0x2D,0x0007D000);
   k_msleep(SLEEP_TIME);
 */

}


