//
// Fantasia.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:35:04 2015 jonathan kauch
// Last update Fri Apr 17 11:44:48 2015 jonathan kauch
//


#include "Fantasia.hpp"

Fantasia::Fantasia(Pizza::TaillePizza size, int order)
  : Pizza(Pizza::Fantasia, size, order) , _typeStr("fantasia")
{
  this->initIngredient();
}

Fantasia::Fantasia(Fantasia const &pizza)
  : Pizza(pizza) , _typeStr("fantasia")
{
  this->initIngredient();
}

Fantasia::~Fantasia()
{

}

void Fantasia::initIngredient()
{
  this->_ingredient["doe"] = 1;
  this->_ingredient["tomato"] = 1;
  this->_ingredient["goat cheese"] = 1;
  this->_ingredient["eggplant"] = 1;
  this->_ingredient["chief love"] = 1;
  this->setCookTime(4);
}

std::string const &Fantasia::getTypeStr() const
{
  return (this->_typeStr);
}

std::map<std::string, int> const& Fantasia::getIngredient() const
{
  return (this->_ingredient);
}

Pizza& Fantasia::clone() const
{
  return (* new Fantasia(this->getTaillePizza()));
}
