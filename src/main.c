#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/byteorder.h>

#include "spi_com.h"
#include "tmc51xx.h"


#define SLEEP_TIME 1000

/*Configure SPI*/
#define SPI_DEV DT_COMPAT_GET_ANY_STATUS_OKAY(test)
#define SPI_OP SPI_OP_MODE_MASTER | SPI_MODE_GET(3) | SPI_WORD_SET(8) | SPI_TRANSFER_MSB

struct spi_dt_spec spi_com = SPI_DT_SPEC_GET(SPI_DEV, SPI_OP, 0);

/*Test Buffer*/
#define BUF_SIZE 5
uint8_t buffer_tx[BUF_SIZE] = {0xAA, 0xBB, 0xCC, 0xDD, 0xFF};
uint8_t buffer_rx[BUF_SIZE] = {};

uint8_t ret;

uint8_t rx_test[BUF_SIZE]={0,0,0,0,0};
uint64_t rx_test_value = 0;

void main(void)
{


    printk("Hi \n");

 
    write_register(&spi_com,0x6C,0x000100C3);

    write_register(&spi_com,0x10,0x00061F0A);
    write_register(&spi_com,0x11,0x0000000A);
    write_register(&spi_com,0x00,0x00000004);
    write_register(&spi_com,0x13,0x000001F4);
    write_register(&spi_com,0x70,0x000401C8);

    write_register(&spi_com,0x24,0x000003E8);
    write_register(&spi_com,0x25,0x0000C350);
    write_register(&spi_com,0x26,0x000001F4);
    write_register(&spi_com,0x27,0x00030D40);
    write_register(&spi_com,0x28,0x000002BC);
    write_register(&spi_com,0x2A,0x00000578);
    write_register(&spi_com,0x2B,0x0000000A);
    write_register(&spi_com,0x20,0x00000000); 
    write_register(&spi_com,0x2D,0xFFFF3800);

    printk("Read chopconf register\n");
    read_register(&spi_com,0x6c,rx_test);

    rx_test_value = sys_get_be32(&rx_test[1]);
    printk("Read value: %llx \n", rx_test_value); 
    printk("------------\n");

    printk("Read XACTUAL register\n");
    read_register(&spi_com,0x21,rx_test);

    rx_test_value = sys_get_be32(&rx_test[1]);
    printk("Read value: %llx \n", rx_test_value); 
    printk("------------\n");
}


