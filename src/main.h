#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/byteorder.h>

#include "spi_com.h"
#include "tmc51xx.h"


#define SLEEP_TIME 10

/*Configure SPI*/
#define SPI_DEV DT_COMPAT_GET_ANY_STATUS_OKAY(test)
#define SPI_OP SPI_OP_MODE_MASTER |  SPI_MODE_CPHA | SPI_MODE_CPOL | SPI_WORD_SET(8) | SPI_TRANSFER_MSB

struct spi_dt_spec spi_com = SPI_DT_SPEC_GET(SPI_DEV, SPI_OP, 0);

/*Test Buffer*/
#define BUF_SIZE 5