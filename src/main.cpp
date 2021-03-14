
#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "config.hh"
#include "utils/utils.hh"

int main(int argc, char** argv)
{
  std::cout << argv[0] << std::endl << "Version " << IR_Controller_VERSION_MAJOR << "." << IR_Controller_VERSION_MINOR << std::endl;
  
  ir_controller::UtilTest();

  return 0;
}
