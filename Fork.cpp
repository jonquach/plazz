//
// Fork.cpp for  in /home/quach_a/Lab/plazza
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Fri Apr 24 16:50:41 2015 Jonathan Quach
// Last update Fri Apr 24 17:01:44 2015 Jonathan Quach
//

#include "Fork.hpp"

Fork::Fork()
{
  _pid = fork();
  if (_pid == -1)
    throw errorException("Error : fork failed\n");
}

Fork::~Fork()
{
  int status;

  waitpid(_pid, &status, 0);
}

bool Fork::isChildren() const
{
  if (_pid == 0)
    return true;
  return false;
}

int Fork::getPid() const
{
  return _pid;
}
