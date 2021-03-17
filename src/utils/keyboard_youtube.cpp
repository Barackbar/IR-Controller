
#include "keyboard_youtube.hh"

namespace ir_controller
{

std::vector<char> Keyboard_Youtube::GetPath(std::string src, std::string dst)
{
  std::vector<char> outVec = {};

  // Determine which key set src and dst are in.
  // 0 = letter
  // 1 = special
  // 2 = side
  // 3 = bottom
  /* 0--2--1
   *  \   /
   *    3
   */

  // If src == dst
  //   return outVec;
  // If src and dst in same set
  //   Get x_diff_mag, x_diff_dir, y_diff_mag, y_diff_dir
  //   If x_diff_dir == 1
  //     loop from 0 to x_diff_mag
  //       outVec.push_back("u");
  //   Else // x_diff_dir == -1
  //     loop from 0 to x_diff_mag
  //       outVec.push_back("d");
  //   If y_diff_dir == 1
  //     loop from 0 to y_diff_mag
  //       outVec.push_back("r");
  //   Else // y_diff_dir == -1
  //     loop from 0 to y_diff_mag
  //       outVec.push_back("l");
 // Else If    src in 0 and dst in 1
  //         OR dst in 1 and src in 0
  //   GetPath(src,letter2special)
  //   GetPath(letter2special,dst)
  // Else If src in 2 and dst in 3
  //   If      src == "backspace"
  //   Else If dst == "letter2special"
  // Else If src in 3 and dst in 0 || 1
  //   GetPath(src,m_lastBottomTrans)
  //   GetPath(m_lastBottomTrans,dst)
  // Else If src in 0 || 1 and dst in 3
  //   Go straight down to edge + 1, will end up at space
  //   GetPath("space",dst)

  return outVec;
}

} // namespace ir_controller
