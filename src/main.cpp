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

#define FIELD_WIDTH 10

vector<string> commands;

CmdLine commandLine("CATPOO Controller", ' ', VERSION);

void process_args(int argc, char **argv)
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

  commandLine.add(Options::distances);
  commandLine.add(Options::verbose);

  //
  // Parse the command line Arguments
  //
  commandLine.parse(argc, argv);
}

int main(int argc, char **argv)
{
  process_args(argc, argv);

  vector<char> commands;

  if (Options::verbose.getValue()) {
    cout << "Options successfully parsed" << endl;
  }

  //
  // Send all the simple commands first that don't
  // need to read values
  //
  int
    xSpeed = Options::xSpeed.getValue(),
    xDistance = Options::xDistance.getValue(),
    ySpeed = Options::ySpeed.getValue(),
    yDistance = Options::yDistance.getValue(),
    rotSpeed = Options::rotSpeed.getValue(),
    rotDistance = Options::rotDistance.getValue();

  // dump out of a table of the new state before we send it
  // across the I2C bus.
  if (Options::verbose.getValue()) {
    // header row
    cout << "| "  << left
      << setw(FIELD_WIDTH) << "Movement" << " | "
      << setw(FIELD_WIDTH) << "Distance" << " | "
      << setw(FIELD_WIDTH) << "Speed" << " |" << endl;

    // Horizontal rule
    cout << "|"
      << setfill('-') << setw(FIELD_WIDTH + 2) << "-" << "|"
      << setfill('-') << setw(FIELD_WIDTH + 2) << "-" << "|"
      << setfill('-') << setw(FIELD_WIDTH + 2) << "-" << "|"
      << endl;

    // items
    cout << setfill(' ') << "| "
      << left << setw(FIELD_WIDTH) << "X" << " | "
      << right << setw(FIELD_WIDTH) << xDistance << " | "
      << right << setw(FIELD_WIDTH) << xSpeed << " |" << endl;

    cout << setfill(' ') << "| "
      << left << setw(FIELD_WIDTH) << "Y" << " | "
      << right << setw(FIELD_WIDTH) << yDistance << " | "
      << right << setw(FIELD_WIDTH) << ySpeed << " |" << endl;

    cout << setfill(' ') << "| "
      << left << setw(FIELD_WIDTH) << "Rotation" << " | "
      << right << setw(FIELD_WIDTH) << rotDistance << " | "
      << right << setw(FIELD_WIDTH) << rotSpeed << " |" << endl;
    ;
  }

  // last but not least, query the range finder distances.
  // We do this last cuz this is the only time we need to
  // receive bytes. All the other commands are one way,
  // fire and forget.
  if (Options::distances.getValue()) {
    // if (Options::verbose.getValue()) {
    //   cout << "Querying state" << endl;
    // }
    I2C::write(RANGES);
    // there's 6 range finders, each of which uses up 10 bits
    // so we need 2 bytes per reading to not lose resolution
    I2C::read(6 * 2);
  }

  return 0;
}
