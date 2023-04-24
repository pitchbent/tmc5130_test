#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>

#include "spi_com.h"


 #define SLEEP_TIME 10

uint8_t init_tmc(struct spi_dt_spec *spi);

uint8_t set_speeds(struct spi_dt_spec *spi);

