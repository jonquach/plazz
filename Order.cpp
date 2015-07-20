//
// Order.cpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Tue Apr 21 14:50:00 2015 jonathan kauch
// Last update Tue Apr 21 15:05:33 2015 jonathan kauch
//

#include "Order.hpp"

Order::Order(int nbOrder, int nbPizza, std::list<Pizza *> listPizza) :
  _nbOrder(nbOrder),
  _nbPizza(nbPizza),
  _listPizza(listPizza)
{
}

Order::Order(Order const& other) :
  _nbOrder(other._nbOrder),
  _nbPizza(other._nbPizza),
  _listPizza(other._listPizza)
{
}

Order&	Order::operator=(Order const& other)
{
  if (this != &other)
    {
      _nbOrder = other._nbOrder;
      _nbPizza = other._nbPizza;
      _listPizza = other._listPizza;
    }
  return *this;
}

Order::~Order()
{
  _listPizza.clear();
}

/***************************************/
/*		GET SETTER	       */
/***************************************/

int		Order::getNbOrder() const
{
  return _nbOrder;
}

int		Order::getNbPizza() const
{
  return _nbPizza;
}

std::list<Pizza *> const&	Order::getListPizza() const
{
  return _listPizza;
}

void		Order::setNbOrder(int other)
{
  _nbOrder = other;
}

void		Order::setNbPizza(int other)
{
  _nbPizza = other;
}


void		Order::setListPizza(std::list<Pizza *> const& other)
{
  _listPizza = other;
}
