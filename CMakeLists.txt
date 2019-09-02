cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project ("Controller")

set (Controller_VERSION_MAJOR 0)
set (Controller_VERSION_MINOR 1)
set (I2C_DEVICE "/dev/i2c-1" CACHE STRING "i2c device")
set (I2C_ADDR 0x53 CACHE STRING "i2c slave address")

configure_file (
  "config.h.in"
  "config.h"
)

add_subdirectory(src)
