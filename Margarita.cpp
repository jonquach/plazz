//
// Margarita.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:23:18 2015 jonathan kauch
// Last update Fri Apr 17 11:42:15 2015 jonathan kauch
//

#include "Margarita.hpp"

Margarita::Margarita(Pizza::TaillePizza size, int order)
  : Pizza(Pizza::Margarita, size, order) , _typeStr("margarita")
{
  this->initIngredient();
}

Margarita::Margarita(Margarita const &pizza)
  : Pizza(pizza) , _typeStr("margarita")
{
  this->initIngredient();
}

Margarita::~Margarita()
{

}

void Margarita::initIngredient()
{
  this->_ingredient["doe"] = 1;
  this->_ingredient["tomato"] = 1;
  this->_ingredient["gruyere"] = 1;
  this->setCookTime(1);
}

std::string const &Margarita::getTypeStr() const
{
  return (this->_typeStr);
}

std::map<std::string, int> const& Margarita::getIngredient() const
{
  return (this->_ingredient);
}

Pizza& Margarita::clone() const
{
  return (* new Margarita(this->getTaillePizza()));
}
