//
// Pipe.hpp for  in /home/quach_a/Lab/plazza
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sun Apr 26 11:22:31 2015 Jonathan Quach
// Last update Sun Apr 26 19:23:32 2015 Jonathan Quach
//

#ifndef PIPE_HPP
#define PIPE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "Exception.hpp"

class Pipe
{
private:
  int _id;
  bool _isPipeOpen;
  bool _isSon;
  std::string _in;
  std::string _out;

  // int _pipeIn;
  // int _pipeOut;

  std::ifstream _pipeIn;
  std::ofstream _pipeOut;

public:
  Pipe(int);
  ~Pipe();
  Pipe(const Pipe &);

  void setSon(bool);
  void writeOutPipe(const std::string &str);
  const std::string readInPipe();
  const std::string getLine();
  Pipe &operator=(const Pipe &);
  int getId() const;
};

#endif
