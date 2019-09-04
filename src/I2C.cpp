#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "Options.h"
#include "I2C.h"
#include "config.h"

using namespace std;

namespace
{
  int i2c_stream;

  void _open()
  {
    if (i2c_stream = open(I2C_DEVICE, O_RDWR) < 0) {
      cerr << "Failed to open " << I2C_DEVICE << endl;
      cerr << strerror(errno) << endl;
      exit(2);
    }
    if (ioctl(i2c_stream, I2C_SLAVE, I2C_ADDR) < 0) {
      cerr << "Failed to get bus access to " << I2C_DEVICE << " at address: " << I2C_ADDR << endl;
      cerr << strerror(errno) << endl;
      exit(2);
    }
  }

  void _close()
  {
    close(i2c_stream);
  }

  /**
   * Sends a byte over the I2C wire, assuming it's have already
   * been initialized.
   * @param byte What to send
   */
  void _write(char byte)
  {
    if (Options::verbose.getValue())
    {
      cout << "SEND: " << hex << (int)byte << " (" << dec << (int)byte << ")" << endl;
    }
    write(i2c_stream, &byte, 1);
  }
}

namespace I2C
{

  void open()
  {
    cout << "Opening I2C bus" << endl;
    _open();
  }

  void close()
  {
    cout << "Closing I2C bus" << endl;
    _close();
  }

  void write(vector<char> bytes)
  {
    open();
    for (vector<char>::iterator it = bytes.begin(); it != bytes.end(); it++)
    {
      _write(*it);
    }
    close();
  }

  void write(char byte)
  {
    open();
    _write(byte);
    close();
  }

  vector<char> read(int numBytes)
  {
    vector<char> result(numBytes);

    return result;
  }
}
