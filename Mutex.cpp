//
// Mutex.cpp for  in /home/quach_a/Lab/plazza
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Fri Apr 24 17:56:29 2015 Jonathan Quach
// Last update Sat Apr 25 19:08:21 2015 Jonathan Quach
//

#include <iostream>

#include "Mutex.hpp"

Mutex::Mutex(pthread_mutex_t &mutex) : _mutex(mutex)
{
  // std::cout << "lock" << std::endl;
  if (pthread_mutex_lock(&_mutex) != 0)
    throw errorException("Error : phtread_mutex_lock failed\n");
}

Mutex::~Mutex()
{
  // std::cout << "unlock" << std::endl;
  if (pthread_mutex_unlock(&_mutex) != 0)
    throw errorException("Error : phtread_mutex_unlock failed\n");;
}
