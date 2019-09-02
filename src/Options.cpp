#include <tclap/CmdLine.h>

#include "Options.h"

using namespace TCLAP;

namespace Options
{
  ValueArg<int> xSpeed("X", "x-speed", "X movement speed (0-100)", false, 50, "Vx");
  ValueArg<int> xDistance("x", "x-distance", "X movement distance (negative=left, positive=right)", false, 0, "Dx");

  ValueArg<int> ySpeed("Y", "y-speed", "Y movement speed (0-100)", false, 50, "Vy");
  ValueArg<int> yDistance("y", "y-distance", "Y movement distance (negative=backwards, positive=forwards)", false, 0, "Dy");

  ValueArg<int> rotSpeed("R", "rot-speed", "Rotation speed (0-100)", false, 50, "Vz");
  ValueArg<int> rotDistance("r", "rot-distance", "Rotation distance (negative=clockwise, positive=counterclockwise)", false, 0, "Dz");

  SwitchArg distances("d", "distances", "Print range finder distances", false);

  SwitchArg verbose("v", "verbose", "Print out a ton of info", false);

}
