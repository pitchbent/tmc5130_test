# Setting up SPI com with RT1020_EVK & Zephyr OS

Sadly, there is no easy to understand demo from official Zephyr sources, only the rather complex SPI test project. It took some time to understand how SPI com works, but it does now. 

This should be easily transferable to other boards, you may have to adapt the .overlay file to your board.

This demo shows how to send data, receiving should not be an issue aswell, you need to use the function `spi_read_dt()`.

Understanding how the devicetree and bindings work is crucial, i recommend [this talk](https://www.youtube.com/watch?v=o-f2qCd2AXo).

# Building

`west build -p -b mimxrt1020_evk`

If you want to build for a different board, change `mimxrt1020_evk` to your board specifier.

