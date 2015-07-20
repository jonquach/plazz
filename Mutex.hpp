//
// Mutex.hpp for  in /home/quach_a/Lab/plazza
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Fri Apr 24 17:54:41 2015 Jonathan Quach
// Last update Sat Apr 25 18:58:54 2015 Jonathan Quach
//

#ifndef MUTEX_HPP
# define MUTEX_HPP

#include <pthread.h>

#include "Exception.hpp"

class Mutex
{
private:
  pthread_mutex_t &_mutex;

public:
  Mutex(pthread_mutex_t &);
  ~Mutex();
};

#endif
