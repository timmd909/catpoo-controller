#include <iostream>
#include <vector>
#include <string>
#include <boost/program_options.hpp>

#include "config.h"
#include "I2C.h"

using namespace std;
namespace po = boost::program_options;

vector<string> commands;

void process_args(int &argc, char **argv)
{
  po::options_description generic("Generic Options");
  po::options_description hidden("Hidden Options");
  po::options_description visible("Allowed options");
  po::options_description cmdline_options;
  po::positional_options_description p;

  po::variables_map vm;

  generic.add_options()
    ("help", "Show command usage")
    ("verbose", "Enable verbose output")
  ;

  hidden.add_options()
    ("commands", po::value< vector<string> >(), "Commands")
  ;

  cmdline_options.add(generic).add(hidden);

  visible.add(generic);

  p.add("commands", -1);

  store(
    po::command_line_parser(argc, argv)
      .options(cmdline_options)
      .positional(p)
      .run(),
    vm
  );
  notify(vm);

  if (vm.count("help"))
  {
    cout << visible << endl;
    exit(1);
  }

  if (vm.count("commands"))
  {
    vector<string> commands = vm["commands"].as< vector<string> >();
    for (int i = 0; i < commands.size(); i++) {
      cout << "CMD: " << commands[i] << endl;
    }
    // cout << "Commands are: "
    //   << vm["commands"].as< vector<string> >() << "\n";
  }

}

int main (int argc, char **argv)
{
  cout << "==== CATPOO Controller ====" << endl;

  process_args(argc, argv);

  I2C::init();

  return 0;
}
