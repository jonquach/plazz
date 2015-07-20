//
// Item.cpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Sat Apr 25 14:35:36 2015 jonathan kauch
// Last update Sat Apr 25 14:51:03 2015 jonathan kauch
//

#include "Item.hpp"

Item::Item(std::string const& name, int const nb) :
  _name(name), _nb(nb)
{

}

Item::Item(Item const& other) :
  _name(other._name), _nb(other._nb)
{

}

Item& Item::operator=(Item const& other)
{
  _name = other._name;
  _nb = other._nb;
  return *this;
}

Item::~Item()
{
}

std::string const&	Item::getName() const
{
  return _name;
}

int	Item::getNb() const
{
  return _nb;
}

void	Item::setNb(int const other)
{
  _nb = other;
}

bool	Item::removeIngredient(std::string const& name)
{
  if (_name == name)
    {
      if (_nb > 0)
	{
	  _nb--;
	  return true;
	}
    }
  return false;
}
