
#ifndef __IR_CONTROLLER_KEYBOARD_HH__
#define __IR_CONTROLLER_KEYBOARD_HH__

#include <string>
#include <vector>

namespace ir_controller
{

class Keyboard
{
 public:
  Keyboard()
  {};
  ~Keyboard()
  {};
  /* Path
   * Returns a path from one key to another given a keyboard layout
   * Arguments:
   *   src: The initial key position.
   *   dst: The desired final key position.
   * Returns:
   *  A vector of characters defining the sequence of directions to take to
   *  reach the destination, where up = u, down = d, left = l, right = r,
   *  enter = e.
   */
  virtual std::vector<char> GetPath(std::string src, std::string dst) = 0;
  /* ClearState
   * Clears out any state information that may persist between calls.
   */
  virtual void ClearState() = 0;
 protected:
  struct Key
  {
    Key()
    {
      val = "";
      x = 0;
      y = 0;
    };
    Key(std::string val_in, unsigned int x_in, unsigned int y_in)
    {
      val = val_in;
      x = x_in;
      y = y_in;
    };
    std::string val;
    unsigned int x;
    unsigned int y;
  };
 private:
};

} // namespace ir_controller

#endif
