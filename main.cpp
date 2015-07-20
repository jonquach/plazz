//
// main.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Mon Apr 13 13:40:35 2015 jonathan kauch
// Last update Fri Apr 24 15:38:09 2015 Jonathan Quach
//

#include <iostream>
#include <sstream>

#include "Exception.hpp"
#include "Plazza.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void		sighandler(int sig)
{
  if (sig == SIGINT)
    {
      endwin();
      exit(-1);
    }
}

int		usage()
{
  std::cerr << "./plazza [multiplier] [number of cooks per kitchen] [time in millisecondes]" << std::endl;
  return (-1);
}

template <typename T>
T		myConvert(std::string const& nb)
{
  std::istringstream _nb(nb);
  T value;

  _nb >> value;
  return value;
}

int		main(int ac, char **av)
{
  if (ac != 4)
    return (usage());

  double	multi = myConvert<double>(av[1]);
  if (multi <= 0)
    {
      std::cerr << "Error : [multiplier] have to be greater than 0" << std::endl;
      return -1;
    }

  int		nbCook = myConvert<int>(av[2]);
   if (nbCook <= 0)
     {
       std::cerr << "Error : [nb of cooks per kitchen] have to be greater than 0" << std::endl;
       return -1;
     }

  int		timeMilli= myConvert<int>(av[3]);
   if (multi <= 0)
     {
       std::cerr << "Error : [time] have to be greater than 0" << std::endl;
       return -1;
     }

  //we need to check the value of the parameters
  try
    {
      signal(SIGINT, sighandler);
      Plazza plazza(multi, nbCook, timeMilli);
      // launch the pizzeria
      plazza.start();
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}

