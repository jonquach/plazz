//
// Plazza.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Mon Apr 13 13:43:48 2015 jonathan kauch
// Last update Sun Apr 26 22:20:59 2015 Jonathan Quach
//

#ifndef		PLAZZA_HPP_
# define	PLAZZA_HPP_

# include <iostream>
# include <ncurses.h>
# include <signal.h>
# include <vector>
# include <string>
# include <sstream>
# include <algorithm>
# include <map>
# include "Pizza.hpp"
# include "Regina.hpp"
# include "Margarita.hpp"
# include "Americaine.hpp"
# include "Fantasia.hpp"
# include "Exception.hpp"
# include "Order.hpp"
# include "Kitchen.hpp"
# include "Pipe.hpp"

class		Plazza
{
private:
  double	_multiCooking;
  int		_nbCooks;
  int		_timeMillisecond;
  int		_total;
  int	        _x;
  int		_y;
  int	        _parentX;
  int		_parentY;
  WINDOW	*_header;
  WINDOW	*_body;
  WINDOW	*_footer;
  WINDOW	*_kitchen[16];
  std::list<Order> _order;
  std::vector<Kitchen *> _kitchenList;
  std::vector<Pipe *> _pipeList;
  pid_t		_pid;

  // ctor & dtor
public:
  explicit Plazza(double, int , int);
  Plazza(Plazza const&);
  Plazza& operator=(Plazza const&);
  ~Plazza();

  // getter & setter
public:
  double	getMultiCooking() const;
  int		getNbCooks() const;
  int		getTimeMillisecond() const;
  void		setMultiCooking(double const);
  void		setNbCooks(int const);
  void		setTimeMillisecond(int const);

  // method
public:
  void		start();
  void		parsing(std::string &);
  void		createNewKitchens(int);
  void		draw_header();
  void		draw_body();
  void		draw_kitchen();
  void		draw_menu();
  void		draw_log();
  void		printEcrased();
  void		affOrderIntoLog(int const, int const, std::string const&);
  void		distribToKitchen(Order&);
  void		distrib();
  void		displayAll();
  void		displayKitchen(int);
  bool		checkKitchen(Kitchen *, Pizza *, int);

  Pizza::TaillePizza	findPizzaSize(std::string const &);

  template<typename T>
  static Pizza		*createPizza(Pizza::TaillePizza, int);
};

#endif		/* !PLAZZA_HPP_ */
