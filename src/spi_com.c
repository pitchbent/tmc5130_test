#include "spi_com.h"


uint8_t write_register(struct spi_dt_spec *spi,uint8_t reg, uint32_t value)
{
    int ret = 0;

    //Bit shift the value and register so the register is the first 8 bit
    uint8_t buffer_tx[5] = {WRITE_OFFSET | reg, value >> 24, value >> 16, value >> 8, value};
    //uint8_t buffer_tx[5] = {value, value >> 8, value >> 16, value >> 24, WRITE_OFFSET | reg};
    //Data structure for SPI
    const struct spi_buf spi_buf_tx = {
    .buf = buffer_tx,
    .len = ARRAY_SIZE(buffer_tx),
	};
	struct spi_buf_set tx = {
		.buffers = &spi_buf_tx,
		.count = 1,
	};

    ret = spi_transceive_dt(spi,&tx,NULL); //No need to receive, only write


    for (uint8_t i = 0; i < 5; i++)
    {
        printk("tx value on pos %u is %x \n", i, buffer_tx[i]);
    }
    
    printk("------------------ \n");


    return ret; //Returns 1 if it failed

}

uint8_t read_register(struct spi_dt_spec *spi,uint8_t reg, uint8_t *data)
{
   
    int ret = 0;

    //Only the address is needed
    uint8_t buffer_tx[5] = {reg,0,0,0,0};

    //Data structure for SPI
    const struct spi_buf spi_buf_tx = {
    .buf = buffer_tx,
    .len = ARRAY_SIZE(buffer_tx),
	};
	struct spi_buf_set tx = {
		.buffers = &spi_buf_tx,
		.count = 1,
	};

    const struct spi_buf spi_buf_rx = {
    .buf = data,
    .len = ARRAY_SIZE(buffer_tx),
	};
	struct spi_buf_set rx = {
		.buffers = &spi_buf_rx,
		.count = 1,
	};

    
    ret = spi_transceive_dt(spi,&tx,&rx);

    k_msleep(1000);

    ret = spi_transceive_dt(spi,&tx,&rx); //Do it twice to remove old reading
        for (uint8_t i = 0; i < 5; i++)
    {
        printk("tx value on pos %u is %x \n", i, buffer_tx[i]);

    }
        for (uint8_t i = 0; i < 5; i++)
    {
        printk("rx value on pos %u is %x \n", i, data[i]);
        
    }
    return ret; //Returns 1 if it failed

}