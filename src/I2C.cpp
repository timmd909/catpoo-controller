#include <iostream>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "I2C.h"
#include "config.h"

using namespace std;

namespace I2C
{
  void init()
  {
    cout << "Initializing I2C bus on " << I2C_DEVICE << endl;
  }
}
