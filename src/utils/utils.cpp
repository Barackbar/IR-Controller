
#include "utils.hh"

#include <cstdio>
#include <cstdlib>

#include <stdexcept>
#include <iostream>

void ir_controller::UtilTest()
{
  printf("Utils Test\n");
}

int ir_controller::DeviceStatus(std::string dev)
{
  unsigned int bufSize = 1024;
  char buf[bufSize];
  std::string result = "";

  std::string command = "ir-ctl -f -d ";
  command.append(dev);

  // Open a pipe to the command's process.
  FILE* pipe = popen(command.c_str(), "r");
  if (!pipe)
  {
    return -1;
  }

  // While there's still characters to read.
  while (!feof(pipe))
  {
    // Put those characters into the buffer, if we can.
    if (fgets(buf,bufSize,pipe) != NULL)
    {
      result += buf;
    }
  }

  // Close everything when we're done.
  pclose(pipe);

  // Search for magic words.
  std::string recvMagicWords = "Device can receive raw IR";
  std::string sendMagicWords = "Device can send raw IR";

  if (result.find(recvMagicWords) != std::string::npos)
  {
    return 1;
  }
  else if (result.find(sendMagicWords) != std::string::npos)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int ir_controller::SendIR(std::string dev, std::string filename)
{
  // The ir-ctl command
  std::string irCtlCmd = std::string("ir-ctl -d ")
                       + dev
                       + std::string(" --send=")
                       + filename;
  std::system(irCtlCmd.c_str());

  return 0;
}
