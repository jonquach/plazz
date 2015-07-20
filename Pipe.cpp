//
// Pipe.cpp for  in /home/quach_a/Lab/plazza
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sun Apr 26 11:21:49 2015 Jonathan Quach
// Last update Sun Apr 26 23:53:18 2015 Jonathan Quach
//

#include "Pipe.hpp"

Pipe::Pipe(int id) : _id(id), _isPipeOpen(false), _isSon(false)
{
  std::stringstream in;
  std::stringstream out;

  in << "pipeIn" << _id << ".pipe";
  _in = in.str();

  out << "pipeOut" << _id  << ".pipe";
  _out = out.str();

  if ((mkfifo(_in.c_str(), 0644)) == -1)
    throw errorException("Error : mkfifo failed\n");
  if ((mkfifo(_out.c_str(), 0644)) == -1)
    throw errorException("Error : mkfifo failed\n");
}

Pipe::Pipe(const Pipe &p) : _id(p._id), _isPipeOpen(p._isPipeOpen),
			    _isSon(p._isSon), _in(p._in), _out(p._out)
{
  std::stringstream in;
  std::stringstream out;

  _isSon = false;

  in << "pipeIn" << _id;
  _in = in.str();

  out << "pipeOut" << _id;
  _out = out.str();
}

Pipe &Pipe::operator=(const Pipe &p)
{
  if (this != &p)
    {
      _id = p._id;
      _isPipeOpen = p._isPipeOpen;
      _isSon = p._isSon;
      _in = p._in;
      _out = p._out;

      std::stringstream in;
      std::stringstream out;

      _isSon = false;

      in << "pipeIn" << _id;
      _in = in.str();

      out << "pipeOut" << _id;
      _out = out.str();
    }
  return *this;
}

Pipe::~Pipe()
{
  if (_isSon)
    {
      _pipeIn.close();
      _pipeOut.close();
    }
  else
    {
      _pipeIn.close();
      _pipeOut.close();
      unlink(_in.c_str());
      unlink(_out.c_str());
    }
}

void Pipe::setSon(bool isSon)
{
  _isSon = isSon;
  _isPipeOpen = true;

  if (_isSon)
    {
      _pipeIn.open(_in.c_str(), std::ostream::in);
      _pipeOut.open(_out.c_str(), std::ostream::out);
    }
  else
    {
      _pipeOut.open(_in.c_str(), std::ostream::out);
      _pipeIn.open(_out.c_str(), std::ostream::in);
    }
}

void Pipe::writeOutPipe(const std::string &str)
{
  if (_isPipeOpen)
    _pipeOut << str << std::endl;
}

const std::string Pipe::readInPipe()
{
  std::string str("");

  if (_isPipeOpen)
    {
      _pipeIn >> str;
    }
  return str;
}

const std::string Pipe::getLine()
{
  std::string line("");

  if (_isPipeOpen)
    std::getline(_pipeIn, line);
  return line;
}

int Pipe::getId() const
{
  return _id;
}
