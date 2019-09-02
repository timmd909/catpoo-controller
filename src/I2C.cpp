#include <iostream>
#include <vector>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "Options.h"
#include "I2C.h"
#include "config.h"

using namespace std;

namespace I2C
{
  void send(vector<char> byte)
  {
    // begin transmissions
    //
    // send all the bytes
    //
    // end transmission
  }

  void send(char byte)
  {
    vector<char> bytes;
    bytes.push_back(byte);
    send(bytes);
  }

  vector<char> read(int numBytes)
  {
    vector<char> result(numBytes);

    return result;
  }
}
