
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#include "config/config.hh"
#include "utils/utils.hh"
#include "utils/keyboard_youtube.hh"

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    std::cout << "Usage: IR_Controller DIRECTORY WAITTIME" << std::endl
              << "Version " << IR_Controller_VERSION_MAJOR << "." << IR_Controller_VERSION_MINOR << std::endl
              << "Use the pre-recorded .ir files in DIRECTORY." << std::endl
              << "Wait for WAITTIME seconds between automatically sent commands." << std::endl;
    return 1;
  }

  // Determine which device is the sender
  std::string dev0 = "/dev/lirc0";
  std::string dev1 = "/dev/lirc1";
  std::string dev;
  if (2 == ir_controller::DeviceStatus(std::string(dev0)))
  {
    dev = dev0;
  }
  else if (2 == ir_controller::DeviceStatus(std::string(dev1)))
  {
    dev = dev1;
  }
  else
  {
    std::cout << "Neither " << dev0 << " nor " << dev1 << " are seen as senders, exiting." << std::endl;
  // TODO: remove this when running on actual computer
//    return 1;
  }

  // Get the files from the directory we're working from.
  std::vector<std::string> filenames =
  {
    std::string(argv[1]) + std::string("/power.ir"),
    std::string(argv[1]) + std::string("/up.ir"),
    std::string(argv[1]) + std::string("/down.ir"),
    std::string(argv[1]) + std::string("/left.ir"),
    std::string(argv[1]) + std::string("/right.ir"),
    std::string(argv[1]) + std::string("/enter.ir"),
    std::string(argv[1]) + std::string("/input.ir"),
    std::string(argv[1]) + std::string("/vol_up.ir"),
    std::string(argv[1]) + std::string("/vol_dn.ir")
  };

  for (auto it = filenames.begin();
       it != filenames.end();
       ++it)
  {
    if (!fopen(it->c_str(),"r"))
    {
      std::cout << "Couldn't find file " << *it << ", exiting." << std::endl;
      return 1;
    }
  }

  int waitSec = 1;
  waitSec = std::stoi(std::string(argv[2]),nullptr,10);

  // The YouTube keyboard path maker thing
  ir_controller::Keyboard_Youtube ky = ir_controller::Keyboard_Youtube();

  unsigned int q  = 0;  // quit
  unsigned int p  = 1;  // power
  unsigned int u  = 2;  // up
  unsigned int d  = 3;  // down
  unsigned int l  = 4;  // left
  unsigned int r  = 5;  // right
  unsigned int e  = 6;  // enter
  unsigned int i  = 7;  // input
  unsigned int vu = 8;  // volume up
  unsigned int vd = 9;  // volume down
  unsigned int ys = 10; // YouTube Search

  char inBuf[1024];
  std::string inStr, tempStrSrc, tempStrDst;
  unsigned int in = 1;
  while (in != q)
  {
    std::cout << "Commands:"           << std::endl
              << "  0: Quit"           << std::endl
              << "  1: Power"          << std::endl
              << "  2: Up"             << std::endl
              << "  3: Down"           << std::endl
              << "  4: Left"           << std::endl
              << "  5: Right"          << std::endl
              << "  6: Enter"          << std::endl
              << "  7: Input"          << std::endl
              << "  8: Vol Up"         << std::endl
              << "  9: Vol Dn"         << std::endl
              << " 10: YouTube Search" << std::endl
              << "Choice: ";
    std::cin >> in;
    std::cout << "Entered: "<< in << std::endl;

    switch (in)
    {
      case 0:
        std::cout << "Exiting." << std::endl;
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
        std::cout << "SendIR(" << dev << "," << filenames[in-1] << ");" << std::endl;
        ir_controller::SendIR(dev,filenames[in-1]);
        break;
      case 10:
        // Get the user input text with spaces intact
        std::cin.ignore();
        std::cin.getline(inBuf,sizeof(inBuf));
        inStr = std::string(inBuf);
        // Add an extra 'a' to the front of inStr
        // Because that's where we're starting from
        inStr.insert(inStr.begin(),'a');
        std::vector<char> path;
        
        // For every character
        for (auto it = inStr.begin();
             it != inStr.end();
             ++it)
        {
          // If this character is " "
          if (*it == ' ')
          {
            // Replace it with "space"
            tempStrSrc = "space";
          }
          else
          {
            tempStrSrc = std::string(1,*it);
          }

          // If this is the last character, which needs to be
          // ended with a "search" path and selection
          if (it == (inStr.end()-1))
          {
            tempStrDst = "search";
          }
          else
          {
            // If the next character is " "
            if (*(it+1) == ' ')
            {
              // Replace it with "space"
              tempStrDst = "space";
            }
            else
            {
              tempStrDst = std::string(1,*(it+1));
            }
          }
          // Get the path from this char to the next one
          path = ky.GetPath(tempStrSrc,tempStrDst);
          // For every step in this path
          for (auto path_it = path.begin();
               path_it != path.end();
               ++path_it)
          {
            // Send IR commands from what we get with the path
            switch(*path_it)
            {
              case 'u':
                std::cout << "u" << std::endl;
                ir_controller::SendIR(dev,filenames[1]);
                break;
              case 'd':
                std::cout << "d" << std::endl;
                ir_controller::SendIR(dev,filenames[2]);
                break;
              case 'l':
                std::cout << "l" << std::endl;
                ir_controller::SendIR(dev,filenames[3]);
                break;
              case 'r':
                std::cout << "r" << std::endl;
                ir_controller::SendIR(dev,filenames[4]);
                break;
              case 'e':
                std::cout << "e" << std::endl;
                ir_controller::SendIR(dev,filenames[5]);
                break;
            }
            sleep(waitSec);
          }
          // At the end, send an 'e' to hit the character button
          std::cout << "e" << std::endl;
          ir_controller::SendIR(dev,filenames[5]);
          sleep(waitSec);
        }
        break;
    }
  }

  return 0;
}
