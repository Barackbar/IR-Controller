
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <vector>

#include "config/config.hh"
#include "utils/utils.hh"
#include "utils/keyboard_youtube.hh"

int main(int argc, char** argv)
{
  std::cout << argv[0] << std::endl << "Version " << IR_Controller_VERSION_MAJOR << "." << IR_Controller_VERSION_MINOR << std::endl;
 
/* 
  ir_controller::UtilTest();

  std::cout << "DeviceStatus(/dev/lirc0)" << ir_controller::DeviceStatus(std::string("/dev/lirc0")) << std::endl;
  std::cout << "DeviceStatus(/dev/lirc1)" << ir_controller::DeviceStatus(std::string("/dev/lirc1")) << std::endl;
  std::cout << "DeviceStatus(/dev/notadevice)" << ir_controller::DeviceStatus(std::string("/dev/notadevice")) << std::endl;
*/
  ir_controller::Keyboard_Youtube ky = ir_controller::Keyboard_Youtube();

  if (argc == 3)
  {
    std::vector<char> pathVec = ky.GetPath(std::string(argv[1]),std::string(argv[2]));

    std::cout << "Path:" << std::endl;
    for (auto it = pathVec.begin();
         it != pathVec.end();
         ++it)
    {
      std::cout << *it << std::endl;
    }
  }

  return 0;
}
