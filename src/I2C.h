#ifndef __CATPOO_CONTROLLER_I2C_H_
#define __CATPOO_CONTROLLER_I2C_H_

#include <vector>

namespace I2C
{
  void send(char byte);
  void send(std::vector<char> bytes);

  std::vector<char> read(int numBytes);
}

#endif
