//
// Kitchen.hpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Sat Apr 25 00:02:38 2015 jonathan kauch
// Last update Sun Apr 26 23:09:43 2015 jonathan kauch
//

#ifndef KITCHEN_HPP
# define KITCHEN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <pthread.h>
#include <unistd.h>
#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>

#include "Pizza.hpp"
#include "Item.hpp"
#include "Cooker.hpp"
#include "Fork.hpp"
#include "Mutex.hpp"
#include "Pipe.hpp"
#include "Regina.hpp"
#include "Margarita.hpp"
#include "Americaine.hpp"
#include "Fantasia.hpp"

class Kitchen
{
private:
  int						_multi;
  int						_nbCooks;
  double					_time;
  static int					_nbKitchen;
  std::map<std::string, int>  			_ingredient;
  std::list<std::pair<Cooker *, pthread_t *> >	_cookerList;
  std::list<Pizza *>				_pizzaList;
  bool						_isFree;
  bool						_isOpen;
  pid_t						_pid;
  WINDOW					*_body;
  int						_id;
  Fork						*_fork;
  int						_x;
  int						_y;
  bool						_isRunning;
  pthread_t					_thread;
  Pipe						*_pipe;

  pthread_mutex_t			_mutexIngredient;

public:
  Kitchen(double, int, int, WINDOW *, int);
  ~Kitchen();
  Kitchen(Kitchen const&);
  Kitchen& operator=(Kitchen const&);

  void run(int, int, Pipe *);
  void end();
  bool checkPizzaList(int);
  void addPizza();
  void createCookers();
  void addIngredient();
  bool removeIngredient();
  void displayPizzaList() const;
  void setPizza(Pizza *);
  void setIsFree(bool);
  bool getIsFree() const;
  void displayIngredient();
  void deleteDrawing();
  void printYes(Pizza *);
  std::map<std::string, int> const &getIngredient() const;
  void removeIngredient(std::map<std::string, int> const&);
  int getId() const;
  bool getIsRunning() const;
  Pipe *getPipe() const;
  void setPipe(Pipe *);

  template<typename T>
  static Pizza		*createPizza(Pizza::TaillePizza, int);
};

void *threadRunner(void *);

#endif
