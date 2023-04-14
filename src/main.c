#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>

#if CONFIG_SPI_LOOPBACK_MODE_LOOP
#define MODE_LOOP SPI_MODE_LOOP
#else
#define MODE_LOOP 0
#endif

#define SPI_DEV DT_COMPAT_GET_ANY_STATUS_OKAY(test)
#define SPI_OP SPI_OP_MODE_MASTER | SPI_MODE_CPOL | MODE_LOOP | SPI_MODE_CPHA | SPI_WORD_SET(8) | SPI_LINES_SINGLE

struct spi_dt_spec spi_com = SPI_DT_SPEC_GET(SPI_DEV, SPI_OP, 0);

#define BUF_SIZE 5

/*Test Buffer*/
uint8_t buffer_tx[BUF_SIZE] = {0xAA, 0xBB, 0xCC, 0xDD, 0xFF};
uint8_t buffer_rx[BUF_SIZE] = {};

uint8_t ret;

void main(void)
{

    printk("Hi \n");

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



    ret = spi_transceive_dt(&spi_com, &tx, &rx);
    printk("Transceive 1 return: %u \n", ret);

    for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of tx buf: %x \n", buffer_tx[i]);
    }
        for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of rx buf: %x \n", buffer_rx[i]);
    }

    ret = spi_transceive_dt(&spi_com, &tx, &rx);
    printk("Transceive 2 return: %u \n", ret);

    for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of tx buf: %x \n", buffer_tx[i]);
    }
        for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printk("Content of rx buf: %x \n", buffer_rx[i]);
    }
}
