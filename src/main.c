#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>

#include "spi_com.h"




/*Configure SPI*/
#define SPI_DEV DT_COMPAT_GET_ANY_STATUS_OKAY(test)
#define SPI_OP SPI_OP_MODE_MASTER | SPI_MODE_CPOL | SPI_MODE_CPHA | SPI_WORD_SET(8) | SPI_LINES_SINGLE

struct spi_dt_spec spi_com = SPI_DT_SPEC_GET(SPI_DEV, SPI_OP, 0);

/*Test Buffer*/
#define BUF_SIZE 5
uint8_t buffer_tx[BUF_SIZE] = {0xAA, 0xBB, 0xCC, 0xDD, 0xFF};
uint8_t buffer_rx[BUF_SIZE] = {};

uint8_t ret;

uint8_t rx_test[BUF_SIZE]={0,0,0,0,0};

void main(void)
{

    printk("Hi \n");

    /*Configure buffers*/
    const struct spi_buf spi_buf_tx = {
		.buf = buffer_tx,
		.len = sizeof(buffer_tx),
	};
	struct spi_buf_set tx = {
		.buffers = &spi_buf_tx,
		.count = 1,
	};

	struct spi_buf spi_buf_rx = {
		.buf = buffer_rx,
		.len = sizeof(buffer_rx),
	};
	struct spi_buf_set rx = {
		.buffers = &spi_buf_rx,
		.count = 1,
	};


    /*Transceive*/
    ret = spi_transceive_dt(&spi_com, &tx, &rx);
    printk("Transceive 1 return: %u \n", ret);

    /*Print contents of buffers*/
    for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of tx buf: %x \n", buffer_tx[i]);
    }
        for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of rx buf: %x \n", buffer_rx[i]);
    }

    /*Transceive*/
    ret = spi_transceive_dt(&spi_com, &tx, &rx);
    printk("Transceive 2 return: %u \n", ret);

    /*Print contents of buffers*/
    for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of tx buf: %x \n", buffer_tx[i]);
    }
        for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of rx buf: %x \n", buffer_rx[i]);
    }

    printk("Write stuff \n");
    write_register(&spi_com,0x6C,0x000100C3);

    printk("Read stuff \n");
    read_register(&spi_com,0x6C,rx_test);



}


