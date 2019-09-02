#include <iostream>
#include <vector>
#include <string>

#include <tclap/CmdLine.h>
#include "config.h"
#include "Controller.h"
#include "Commands.h"
#include "I2C.h"
#include "Options.h"

using namespace std;
using namespace TCLAP;

vector<string> commands;

CmdLine commandLine("CATPOO Controller", '=', VERSION);

int main (int argc, char **argv)
{
  //
  // Build up all the possible arguments
  //
  commandLine.add(Options::xSpeed);
  commandLine.add(Options::xDistance);

  commandLine.add(Options::ySpeed);
  commandLine.add(Options::yDistance);

  commandLine.add(Options::rotSpeed);
  commandLine.add(Options::rotDistance);

  commandLine.add(Options::queryState);
  commandLine.add(Options::verbose);

  //
  // Parse the command line Arguments
  //
  commandLine.parse(argc, argv);

  //
  // Execution time!
  //
  if (Options::verbose.getValue()) {
    cout << "DEBUG: Options successfully parsed" << endl;
  }

  if (Options::queryState.getValue()) {
    if (Options::verbose.getValue()) {
      cout << "DEBUG: Querying state" << endl;
    }
  }

  return 0;
}
