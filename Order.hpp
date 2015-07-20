//
// Order.hpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Tue Apr 21 14:50:07 2015 jonathan kauch
// Last update Wed Apr 22 17:49:39 2015 jonathan kauch
//

#ifndef		ORDER_HPP_
# define	ORDER_HPP_

# include <string>
# include <list>

# include "Pizza.hpp"

class Order
{
public:
  int			_nbOrder;
  int			_nbPizza;
  std::list<Pizza *>	_listPizza;

public:
  explicit Order(int, int, std::list<Pizza* >);
  Order(Order const&);
  Order& operator=(Order const&);
  ~Order();

public:
  int		getNbOrder() const;
  int		getNbPizza() const;
  std::list<Pizza *> const&	getListPizza() const;
  void		setNbOrder(int);
  void		setNbPizza(int);
  void		setListPizza(std::list<Pizza *> const&);
};

#endif
