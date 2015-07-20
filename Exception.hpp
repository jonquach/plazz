//
// Exception.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Mon Apr 13 14:23:20 2015 jonathan kauch
// Last update Mon Apr 13 14:27:18 2015 jonathan kauch
//

#ifndef		EXCEPTION_HPP_
# define	EXCEPTION_HPP_

# include <string>
# include <exception>

class	errorException : public std::exception
{
public:
  errorException(std::string const&);
  virtual		~errorException() throw(){}

  virtual const char	*what() const throw();

private:
  std::string		_str;
};

#endif
