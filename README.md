# catpoo-controller

i2c based controller application for my CATPOO robot.

This will mostly be called by webserver to pass commands along from the
website user to the microcontroller.

## Compilation instructions

```
$ mkdir build
$ cd build/
$ cmake ../
$ make
```

## Non-default bus and address example usage

If the slave address or bus needs changed temporarily,
you can do the following:

```
$ cmake -D I2C_ADDR="0x96" -D I2C_DEVICE="dev/i2c-4" ../
```


