//
// Exception.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Mon Apr 13 14:27:26 2015 jonathan kauch
// Last update Mon Apr 13 14:32:51 2015 jonathan kauch
//

#include "Exception.hpp"

errorException::errorException(std::string const& str)
{
  _str = str;
}

const char	*errorException::what() const throw()
{
  return _str.c_str();
}
