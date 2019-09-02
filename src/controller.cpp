#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <queue>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "controller.h"
#include "Commands.h"

using namespace std;

queue<char> commands;


int main(int argc, char **argv)
{
  if (argc <= 1) {
    std::cout << "You must supply a command" << endl;
    return -1;
  }

  string command = boost::to_upper_copy<string>(argv[1]);
  cout << "Command: " << command << endl;

  //
  // TESTS
  //
  if (command == "DANCE") {
    commands.push(0x69);
  } else if (command == "WHEEL") {
    commands.push(0x68);
  }

  //
  // MOVEMENT
  //
  if (command == "ROTATE") {
    commands.push(ROTATE);
    commands.push(atoi(argv[2]) & 0xff);
    commands.push(atoi(argv[2]) >> 8);

  } else if (command == "TRANSLATE") {
    commands.push(TRANSLATE);
    commands.push(atoi(argv[2]) & 0xff);
    commands.push(atoi(argv[2]) >> 8);
    commands.push(atoi(argv[3]) & 0xff);
    commands.push(atoi(argv[3]) >> 8);

  } else if (command == "TURN") {
    commands.push(TURN);
    commands.push(atoi(argv[2]) & 0xff);
    commands.push(atoi(argv[2]) >> 8);

  } else if (command == "MOVE") {
    commands.push(MOVE);
    commands.push(atoi(argv[2]) & 0xff);
    commands.push(atoi(argv[2]) >> 8);
    commands.push(atoi(argv[3]) & 0xff);
    commands.push(atoi(argv[3]) >> 8);

  }

  //
  // MISC
  //
  if (command == "RESET") {
    commands.push(0x01);
  }

  //
  // SEND THE COMMANDS
  //
  cout << "Sending commands to Arduino\n";
  int arduino = wiringPiI2CSetup(ARDUINO_I2C_ADDR);
  while (!commands.empty()) {
    int curr = commands.front();
    cout << "Sending 0x" << hex << curr << " (" << dec << curr << ")"<< endl;
    wiringPiI2CWrite(arduino, curr);
    commands.pop();
  }

  cout << "All done" << endl;
  return 0;
}
