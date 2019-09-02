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
  void write(vector<char> bytes)
  {
    for (vector<char>::iterator it = bytes.begin(); it != bytes.end(); it++) {
      write(*it);
    }
  }

  void write(char byte)
  {
    if (Options::verbose.getValue()) {
      cout << "SEND: " << hex << byte << " (" << dec << byte << ")" << endl;
    }
    // implement me here
  }

  vector<char> read(int numBytes)
  {
    vector<char> result(numBytes);

    return result;
  }
}
