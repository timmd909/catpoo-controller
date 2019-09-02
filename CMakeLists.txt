cmake_minimum_required(VERSION 3.2.2)

project ("Controller" VERSION "0.0.1")

set (I2C_DEVICE "/dev/i2c-1" CACHE STRING "i2c device")
set (I2C_ADDR 0x53 CACHE STRING "i2c slave address")
set (SPEED_DEFAULT 50 CACHE STRING "Default speed to move and rotate when none is specified")

configure_file (
  "config.h.in"
  "config.h"
)

add_subdirectory(src)
