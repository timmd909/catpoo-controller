#include <iostream>
#include <vector>
#include <string>

#include <tclap/CmdLine.h>
#include "config.h"
#include "Controller.h"
#include "I2C.h"

using namespace std;
using namespace TCLAP;

vector<string> commands;

CmdLine commandLine("CATPOO Controller", '=', VERSION);

int main (int argc, char **argv)
{
  cout << "==== CATPOO Controller ====" << endl;

  ValueArg<int> xSpeed("X", "x-speed", "X movement speed (0-100)", false, 50, "Vx", commandLine);
  ValueArg<int> xDistance("x", "x-distance", "X movement distance (negative=left, positive=right)", false, 0, "Dx", commandLine);

  ValueArg<int> ySpeed("Y", "y-speed", "Y movement speed (0-100)", false, 50, "Vy", commandLine);
  ValueArg<int> yDistance("y", "y-distance", "Y movement distance (negative=backwards, positive=forwards)", false, 0, "Dy", commandLine);

  ValueArg<int> rotSpeed("R", "rot-speed", "Rotation speed (0-100)", false, 50, "Vz", commandLine);
  ValueArg<int> rotDistance("r", "rot-distance", "Rotation distance (negative=clockwise, positive=counterclockwise)", false, 0, "Dz", commandLine);

  commandLine.parse(argc, argv);

  if (!xDistance.getValue() && !yDistance.getValue() && !rotDistance.getValue()) {
    cout << "You.... uh... wanted to do something...?\n";
  } else {
    cout << "xDistance.getValue() = " << xDistance.getValue() << endl;
    cout << "yDistance.getValue() = " << yDistance.getValue() << endl;
  }

  I2C::init();

  return 0;
}
