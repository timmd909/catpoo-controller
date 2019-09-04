#ifndef __CATPOO_CONTROLLER_I2C_H_
#define __CATPOO_CONTROLLER_I2C_H_

#include <vector>

namespace I2C
{
  /**
   * Open the I2C bus for reading/writing.
   *
   * When using the write() functions, this isn't necessary
   * to explicitly call.
   */
  void open();

  /**
   * Close the I2C bus stream after we're done reading/writing.
   *
   * When using the write() functions, this isn't necessary
   * to explicitly call.
   */
  void close();

  /**
   * Open the I2C bus, send the requested byte, and then close
   * the stream.
   *
   * @param bytes Vector of bytes to send across the wire
   */
  void write(char byte);

  /**
   * Open the I2C bus, send the requested bytes, and then close
   * the stream.
   *
   * @param bytes Vector of bytes to send across the wire
   */
  void write(std::vector<char> bytes);

  /**
   * Open the I2C bus, send the requested number of bytes, and
   * then close the stream.
   *
   * @param numBytes Number of bytes to read off the wire
   */
  std::vector<char> read(int numBytes);
}

#endif
