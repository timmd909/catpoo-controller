# catpoo-controller

i2c based controller application

## Required Packages 

* libboost-all-dev (not sure which I need, but meh... space is cheap)
* libpthread-stubs0-dev 
* wiringPi from https://github.com/WiringPi/WiringPi.git (since the offical repo was down)

## Compilation instructions

```
$ autoreconf --install
$ ./configure
$ make
```
