//
// Pizza.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Wed Apr 15 15:17:40 2015 jonathan kauch
// Last update Sun Apr 26 22:11:02 2015 Jonathan Quach
//

#include "Pizza.hpp"

Pizza::Pizza(Pizza::TypePizza type, Pizza::TaillePizza size, int order) :
  _typePizza(type), _taillePizza(size), _order(order), _done(false), _id(0)
{
  initTab();
  pthread_mutex_init(&_mut, NULL);
  _mapPizza[Pizza::Regina] = "regina";
  _mapPizza[Pizza::Margarita] = "margarita";
  _mapPizza[Pizza::Americaine] = "americaine";
  _mapPizza[Pizza::Fantasia] = "fantasia";
}

Pizza::Pizza(Pizza const& other) :
  _typePizza(other._typePizza), _taillePizza(other._taillePizza)
{
  initTab();
  pthread_mutex_destroy(&_mut);
}

Pizza& Pizza::operator=(Pizza const& other)
{
  if (this != &other)
    {
      _typePizza = other._typePizza;
      _taillePizza = other._taillePizza;
    }
  return *this;
}

Pizza::~Pizza()
{
}

void Pizza::initTab()
{
  this->_sizeTab[Pizza::S] = "S";
  this->_sizeTab[Pizza::M] = "M";
  this->_sizeTab[Pizza::L] = "L";
  this->_sizeTab[Pizza::XL] = "XL";
  this->_sizeTab[Pizza::XXL] = "XXL";
}

int Pizza::getCookTime() const
{
  return _cookTime;
}

Pizza::TaillePizza Pizza::getTaillePizza() const
{
  return _taillePizza;
}

Pizza::TypePizza Pizza::getTypePizza() const
{
  return _typePizza;
}

int Pizza::getOrder() const
{
  return _order;
}

bool Pizza::getDone() const
{
  return _done;
}

void Pizza::setCookTime(int other)
{
  _cookTime = other;
}

void Pizza::setTaillePizza(TaillePizza other)
{
  _taillePizza = other;
}

void Pizza::setTypePizza(TypePizza other)
{
  _typePizza = other;
}

void Pizza::setOrder(int other)
{
  _order = other;
}

void Pizza::setDone(bool other)
{
  _done = other;
}

void Pizza::setId(int id)
{
  _id = id;
}

int Pizza::getId() const
{
  return _id;
}

int Pizza::tryLock()
{
  return (pthread_mutex_trylock(&_mut));
}

int Pizza::unlock()
{
  return (pthread_mutex_unlock(&_mut));
}
