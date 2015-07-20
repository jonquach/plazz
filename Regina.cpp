//
// Regina.cpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:32:22 2015 jonathan kauch
// Last update Fri Apr 17 11:42:30 2015 jonathan kauch
//

#include "Regina.hpp"

Regina::Regina(Pizza::TaillePizza size, int order)
  : Pizza(Pizza::Regina, size, order) , _typeStr("regina")
{
  this->initIngredient();
}

Regina::Regina(Regina const &pizza)
  : Pizza(pizza) , _typeStr("regina")
{
  this->initIngredient();
}

Regina::~Regina()
{

}

void Regina::initIngredient()
{
  this->_ingredient["doe"] = 1;
  this->_ingredient["tomato"] = 1;
  this->_ingredient["gruyere"] = 1;
  this->_ingredient["ham"] = 1;
  this->_ingredient["mushrooms"] = 1;
  this->setCookTime(2);
}

std::string const &Regina::getTypeStr() const
{
  return (this->_typeStr);
}

std::map<std::string, int> const& Regina::getIngredient() const
{
  return (this->_ingredient);
}

Pizza& Regina::clone() const
{
  return (* new Regina(this->getTaillePizza()));
}
