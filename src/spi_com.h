#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>

#define WRITE_OFFSET 0x80

uint8_t write_register(struct spi_dt_spec *spi,uint8_t reg, uint32_t value);
uint8_t read_register(struct spi_dt_spec *spi,uint8_t reg, uint8_t *data);
