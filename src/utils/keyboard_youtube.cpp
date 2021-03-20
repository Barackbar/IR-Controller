
#include "keyboard_youtube.hh"

#include <cstdlib>

namespace ir_controller
{

void Keyboard_Youtube::ClearState()
{
  this->m_letterNotSpecial = true;
}

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

  if (src.compare(dst) == 0)
  {
    return outVec;
  }

  std::pair<Keyboard_Youtube::ButtonSet,Keyboard::Key> srcLoc
     = this->GetLoc(src);
  std::pair<Keyboard_Youtube::ButtonSet,Keyboard::Key> dstLoc
     = this->GetLoc(dst);

//  printf("src:\n  Set: %u\n  Key: %s\n  Loc: %u,%u\n",srcLoc.first,srcLoc.second.val.c_str(),srcLoc.second.x,srcLoc.second.y);
//  printf("dst:\n  Set: %u\n  Key: %s\n  Loc: %u,%u\n",dstLoc.first,dstLoc.second.val.c_str(),dstLoc.second.x,dstLoc.second.y);

  std::vector<char> tempVec;

  // If src and dst are in the same set
  if (srcLoc.first == dstLoc.first)
  {
    outVec = this->GetPathWithXY(srcLoc.second.x, srcLoc.second.y,
                               dstLoc.second.x, dstLoc.second.y);
    return outVec;
  }

  // If we have to go from a Letter to a Side
  // Note: We always go to the letter2special key for ease/consistency.
  if (   srcLoc.first == Keyboard_Youtube::ButtonSet::letter
      && dstLoc.first == Keyboard_Youtube::ButtonSet::side)
  {
    // Get Path from current position to one below the top right corner
    tempVec = this->GetPathWithXY(srcLoc.second.x,
                                srcLoc.second.y,
                                m_letterDimXY.first-1,
                                1);
    // Add an 'r'
    tempVec.push_back('r');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    // We're now at "letter2special"
    // Get path from letter2special to dst
    tempVec = this->GetPath("letter2special",dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  // If we have to go from a Side to a Letter 
  if (   srcLoc.first == Keyboard_Youtube::ButtonSet::side
      && dstLoc.first == Keyboard_Youtube::ButtonSet::letter)
  {
    tempVec = this->GetPath(src,"letter2special");
    // If we have special pulled up
    if (!(this->m_letterNotSpecial))
    {
      tempVec.push_back('e');
      this->m_letterNotSpecial = true;
    }
    tempVec.push_back('l');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    // We're now at one below the top right corner
    // Get path from one below the top right corner to dst
    Keyboard::Key tempKey = this->GetKeyAtXY(Keyboard_Youtube::letter,
                                             this->m_letterDimXY.first-1,
                                             1);
    tempVec = this->GetPath(tempKey.val,dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  // How to go from Special to Side
  if (   srcLoc.first == Keyboard_Youtube::ButtonSet::special
      && dstLoc.first == Keyboard_Youtube::ButtonSet::side)
  {
    // Get Path from current position to one below the top right corner
    tempVec = this->GetPathWithXY(srcLoc.second.x,
                                srcLoc.second.y,
                                m_specialDimXY.first-1,
                                1);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    // Add an 'r'
    outVec.push_back('r');
    // We're now at "letter2special"
    // Get path from letter2special to dst
    tempVec = this->GetPath("letter2special",dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  // How to go from Side to Special
  if (   srcLoc.first == Keyboard_Youtube::ButtonSet::side
      && dstLoc.first == Keyboard_Youtube::ButtonSet::special)
  {
    tempVec = this->GetPath(src,"letter2special");
    // If we have letter pulled up
    if (this->m_letterNotSpecial)
    {
      tempVec.push_back('e');
      this->m_letterNotSpecial = false;
    }
    tempVec.push_back('l');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    // We're now at one below the top right corner
    // Get path from one below the top right corner to dst
    Keyboard::Key tempKey = this->GetKeyAtXY(Keyboard_Youtube::special,
                                             this->m_specialDimXY.first-1,
                                             1);
    tempVec = this->GetPath(tempKey.val,dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  // If we have to go between letters and special characters
  if ((   srcLoc.first == Keyboard_Youtube::ButtonSet::letter
       && dstLoc.first == Keyboard_Youtube::ButtonSet::special)
      ||
      (   srcLoc.first == Keyboard_Youtube::ButtonSet::special
       && dstLoc.first == Keyboard_Youtube::ButtonSet::letter))
  {
    // Get path from src to Side
    tempVec = this->GetPath(src,"letter2special");
    // Swap to the other one
    tempVec.push_back('e');
    // Record that we changed between letter and special
    this->m_letterNotSpecial = !(this->m_letterNotSpecial);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    // Get path from Side to dst
    tempVec = this->GetPath("letter2special",dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  // If we have to go from letter or special to bottom
  if ((   srcLoc.first == Keyboard_Youtube::ButtonSet::letter
       && dstLoc.first == Keyboard_Youtube::ButtonSet::bottom)
      ||
      (   srcLoc.first == Keyboard_Youtube::ButtonSet::special
       && dstLoc.first == Keyboard_Youtube::ButtonSet::bottom))
  {
    // Get path from src to bottom left corner
    // If we have the letter set up
    if (this->m_letterNotSpecial)
    {
      // Get path from src to bottom left corner
      tempVec = this->GetPathWithXY(srcLoc.second.x,
                              srcLoc.second.y,
                              0,
                              this->m_letterDimXY.second-1);
    }
    else // we have the special set up
    {
      // Get path from src to bottom left corner
      tempVec = this->GetPathWithXY(srcLoc.second.x,
                              srcLoc.second.y,
                              0,
                              this->m_specialDimXY.second-1);
    }
    tempVec.push_back('d');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    // Get path from "space" to dst
    tempVec = this->GetPath("space",dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  // If we need to go from bottom to either letter or special
  if ((   srcLoc.first == Keyboard_Youtube::ButtonSet::bottom
       && dstLoc.first == Keyboard_Youtube::ButtonSet::letter)
      ||
      (   srcLoc.first == Keyboard_Youtube::ButtonSet::bottom
       && dstLoc.first == Keyboard_Youtube::ButtonSet::special))
  {
    // Note: we will always transition from "space" to bottom left corner,
    // thus, going straight up will put us in bottom left corner
    outVec.push_back('u');

    // Get where we are right now, after that 'u'
    Keyboard::Key tempKey;
    if (this->m_letterNotSpecial)
    {
      tempKey = this->GetKeyAtXY(Keyboard_Youtube::ButtonSet::letter,
                                 0,
                                 this->m_letterDimXY.second-1);
    }
    else
    {
      tempKey = this->GetKeyAtXY(Keyboard_Youtube::ButtonSet::special,
                                 0,
                                 this->m_specialDimXY.second-1);
    }

    // Get remaining path
    tempVec = this->GetPath(tempKey.val,dst);
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
    return outVec;
  }

  return outVec;
}

std::pair<Keyboard_Youtube::ButtonSet,Keyboard::Key>
Keyboard_Youtube::GetLoc(std::string button)
{
  std::pair<Keyboard_Youtube::ButtonSet,Keyboard::Key> outPair;
  // Check letters
  for (auto it = this->m_letterLayout.begin();
       it != this->m_letterLayout.end();
       ++it)
  {
    if (it->val.compare(button) == 0)
    {
      outPair.first = Keyboard_Youtube::ButtonSet::letter;
      outPair.second = *it;
      return outPair;
    }
  }
  // Check specials
  for (auto it = this->m_specialLayout.begin();
       it != this->m_specialLayout.end();
       ++it)
  {
    if (it->val.compare(button) == 0)
    {
      outPair.first = Keyboard_Youtube::ButtonSet::special;
      outPair.second = *it;
      return outPair;
    }
  }
  // Check side
  for (auto it = this->m_sideLayout.begin();
       it != this->m_sideLayout.end();
       ++it)
  {
    if (it->val.compare(button) == 0)
    {
      outPair.first = Keyboard_Youtube::ButtonSet::side;
      outPair.second = *it;
      return outPair;
    }
  }
  // Check bottom
  for (auto it = this->m_bottomLayout.begin();
       it != this->m_bottomLayout.end();
       ++it)
  {
    if (it->val.compare(button) == 0)
    {
      outPair.first = Keyboard_Youtube::ButtonSet::bottom;
      outPair.second = *it;
      return outPair;
    }
  }
  outPair.first = Keyboard_Youtube::ButtonSet::none;
  return outPair;
}

Keyboard::Key Keyboard_Youtube::GetKeyAtXY(
  Keyboard_Youtube::ButtonSet set,
  unsigned int x,
  unsigned int y)
{
  std::vector<Keyboard::Key>* setPtr;
  if (set == Keyboard_Youtube::ButtonSet::letter)
  {
    setPtr = &(this->m_letterLayout);
  }
  else if (set == Keyboard_Youtube::ButtonSet::special)
  {
    setPtr = &(this->m_specialLayout);
  }
  else if (set == Keyboard_Youtube::ButtonSet::side)
  {
    setPtr = &(this->m_sideLayout);
  }
  else if (set == Keyboard_Youtube::ButtonSet::bottom)
  {
    setPtr = &(this->m_bottomLayout);
  }

  for (auto it = setPtr->begin();
       it != setPtr->end();
       ++it)
  {
    if (it->x == x && it->y == y)
    {
      return *it;
    }
  }
}

std::vector<char> Keyboard_Youtube::GetPathWithXY(
  unsigned int srcX,
  unsigned int srcY,
  unsigned int dstX,
  unsigned int dstY)
{
  std::vector<char> outVec = {};
  std::vector<char> tempVec;
  int x_diff = (int) dstX - (int) srcX;
  int y_diff = (int) dstY - (int) srcY;
  unsigned int x_diff_mag = abs(x_diff);
  unsigned int y_diff_mag = abs(y_diff);

  if (x_diff < 0)
  {
    tempVec = std::vector<char>(x_diff_mag,'l');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
  }
  else if (x_diff > 0)
  {
    tempVec = std::vector<char>(x_diff_mag,'r');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
  }

  if (y_diff < 0)
  {
    tempVec = std::vector<char>(y_diff_mag,'u');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
  }
  else if (y_diff > 0)
  {
    tempVec = std::vector<char>(y_diff_mag,'d');
    outVec.insert(outVec.end(),tempVec.begin(),tempVec.end());
  }

  return outVec;
}

} // namespace ir_controller
