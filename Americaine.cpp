//
// Americaine.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:37:24 2015 jonathan kauch
// Last update Fri Apr 17 11:47:59 2015 jonathan kauch
//

#include "Americaine.hpp"

Americaine::Americaine(Pizza::TaillePizza size, int order)
  : Pizza(Pizza::Americaine, size, order) , _typeStr("americaine")
{
  this->initIngredient();
}

Americaine::Americaine(Americaine const &pizza)
  : Pizza(pizza) , _typeStr("americaine")
{
  this->initIngredient();
}

Americaine::~Americaine()
{

}

void Americaine::initIngredient()
{
  this->_ingredient["doe"] = 1;
  this->_ingredient["tomato"] = 1;
  this->_ingredient["gruyere"] = 1;
  this->_ingredient["steak"] = 1;
  this->setCookTime(2);
}

std::string const &Americaine::getTypeStr() const
{
  return (this->_typeStr);
}

std::map<std::string, int> const& Americaine::getIngredient() const
{
  return (this->_ingredient);
}

Pizza& Americaine::clone() const
{
  return (* new Americaine(this->getTaillePizza()));
}
