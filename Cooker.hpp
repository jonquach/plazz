#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <unistd.h>
#include <pthread.h>
#include <ncurses.h>

#include "Pizza.hpp"

class Cooker
{
private:
  int					_id;
  std::list<Pizza *>			_pizzaList;
  WINDOW				*_body;
  int					_x;
  int					_y;
  double				_time;

public:
  Cooker(int, std::list<Pizza *> &, double);
  ~Cooker();

  void					cookPizza(Pizza *);
  int					checkPizza(Pizza *);
  void					start();
  void					setList(std::list<Pizza *> &);
};

void					*cooker_start(void * c);
