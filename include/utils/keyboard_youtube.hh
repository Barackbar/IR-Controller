
#ifndef __IR_CONTROLLER_KEYBOARD_YOUTUBE_HH__
#define __IR_CONTROLLER_KEYBOARD_YOUTUBE_HH__

#include "keyboard.hh"

#include <string>
#include <utility>

namespace ir_controller
{

class Keyboard_Youtube : public Keyboard
{
 public:
  Keyboard_Youtube() : Keyboard()
  {
      // 0,0 is the top left corner
      // 1,1 is down one, right one from 0,0
      m_letterLayout.push_back(Key("a",0,0));
      m_letterLayout.push_back(Key("b",1,0));
      m_letterLayout.push_back(Key("c",2,0));
      m_letterLayout.push_back(Key("d",3,0));
      m_letterLayout.push_back(Key("e",4,0));
      m_letterLayout.push_back(Key("f",5,0));
      m_letterLayout.push_back(Key("g",6,0));

      m_letterLayout.push_back(Key("h",0,1));
      m_letterLayout.push_back(Key("i",1,1));
      m_letterLayout.push_back(Key("j",2,1));
      m_letterLayout.push_back(Key("k",3,1));
      m_letterLayout.push_back(Key("l",4,1));
      m_letterLayout.push_back(Key("m",5,1));
      m_letterLayout.push_back(Key("n",6,1));

      m_letterLayout.push_back(Key("o",0,2));
      m_letterLayout.push_back(Key("p",1,2));
      m_letterLayout.push_back(Key("q",2,2));
      m_letterLayout.push_back(Key("r",3,2));
      m_letterLayout.push_back(Key("s",4,2));
      m_letterLayout.push_back(Key("t",5,2));
      m_letterLayout.push_back(Key("u",6,2));

      m_letterLayout.push_back(Key("v",0,3));
      m_letterLayout.push_back(Key("w",1,3));
      m_letterLayout.push_back(Key("x",2,3));
      m_letterLayout.push_back(Key("y",3,3));
      m_letterLayout.push_back(Key("z",4,3));
      m_letterLayout.push_back(Key("-",5,3));
      m_letterLayout.push_back(Key("'",6,3));

      m_specialLayout.push_back(Key("1",0,0));
      m_specialLayout.push_back(Key("2",1,0));
      m_specialLayout.push_back(Key("3",2,0));
      m_specialLayout.push_back(Key("&",3,0));
      m_specialLayout.push_back(Key("#",4,0));
      m_specialLayout.push_back(Key("(",5,0));
      m_specialLayout.push_back(Key(")",6,0));

      m_specialLayout.push_back(Key("4",0,1));
      m_specialLayout.push_back(Key("5",1,1));
      m_specialLayout.push_back(Key("6",2,1));
      m_specialLayout.push_back(Key("@",3,1));
      m_specialLayout.push_back(Key("!",4,1));
      m_specialLayout.push_back(Key("?",5,1));
      m_specialLayout.push_back(Key(":",6,1));

      m_specialLayout.push_back(Key("7",0,2));
      m_specialLayout.push_back(Key("8",1,2));
      m_specialLayout.push_back(Key("9",2,2));
      m_specialLayout.push_back(Key("0",3,2));
      m_specialLayout.push_back(Key(".",4,2));
      m_specialLayout.push_back(Key("_",5,2));
      m_specialLayout.push_back(Key("\"",6,2));

      m_sideLayout.push_back(Key("backspace",0,0));
      m_sideLayout.push_back(Key("letter2special",0,1));

      m_bottomLayout.push_back(Key("space",0,0));
      m_bottomLayout.push_back(Key("clear",1,0));
      m_bottomLayout.push_back(Key("search",2,0));

      m_letterDimXY.first  = 7;
      m_letterDimXY.second = 4;

      m_specialDimXY.first  = 7;
      m_specialDimXY.second = 3;

      m_sideDimXY.first  = 1;
      m_sideDimXY.second = 2;

      m_bottomDimXY.first  = 3;
      m_bottomDimXY.second = 1;

      m_letterNotSpecial = true;
  };
  ~Keyboard_Youtube()
  {};
  std::vector<char> GetPath(std::string src, std::string dst);
  void ClearState();
 protected:
 private:
  enum ButtonSet
  {
    none,
    letter,
    special,
    side,
    bottom
  };

  std::pair<ButtonSet,Key> GetLoc(std::string button);
  Key GetKeyAtXY(ButtonSet set, unsigned int x, unsigned int y);
  std::vector<char> GetPathWithXY(
    unsigned int srcX,
    unsigned int srcY,
    unsigned int dstX,
    unsigned int dstY);

  std::vector<Key> m_letterLayout;
  std::pair<unsigned int,unsigned int> m_letterDimXY;
  std::vector<Key> m_specialLayout;
  std::pair<unsigned int,unsigned int> m_specialDimXY;
  std::vector<Key> m_sideLayout;
  std::pair<unsigned int,unsigned int> m_sideDimXY;
  std::vector<Key> m_bottomLayout;
  std::pair<unsigned int,unsigned int> m_bottomDimXY;

  // Whether or not we're currently in the letter or special set.
  bool m_letterNotSpecial;
};

} // namespace ir_controller

#endif
