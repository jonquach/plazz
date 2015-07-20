//
// Fork.hpp for  in /home/quach_a/Lab/plazza
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Fri Apr 24 16:53:31 2015 Jonathan Quach
// Last update Fri Apr 24 17:01:35 2015 Jonathan Quach
//

#ifndef FORK_HPP
# define FORK_HPP

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Exception.hpp"

class Fork
{
private:
  pid_t _pid;

public:
  Fork();
  ~Fork();
  bool isChildren() const;
  int getPid() const;
};

#endif
