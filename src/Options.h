#ifndef __CATPOO_CONTROLLER_OPTIONS_H_
#define __CATPOO_CONTROLLER_OPTIONS_H_

#include <tclap/CmdLine.h>

namespace Options
{
  extern TCLAP::ValueArg<int> xSpeed;
  extern TCLAP::ValueArg<int> xDistance;

  extern TCLAP::ValueArg<int> ySpeed;
  extern TCLAP::ValueArg<int> yDistance;

  extern TCLAP::ValueArg<int> rotSpeed;
  extern TCLAP::ValueArg<int> rotDistance;

  extern TCLAP::SwitchArg distances;
  extern TCLAP::SwitchArg verbose;
}

#endif
