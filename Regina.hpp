//
// Regina.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:30:54 2015 jonathan kauch
// Last update Fri Apr 17 11:47:39 2015 jonathan kauch
//

#ifndef		REGINA_HPP_
# define	REGINA_HPP_

# include <iostream>
# include <string>
# include <map>

# include "Pizza.hpp"

class				Regina : public Pizza
{

private:
  std::map<std::string, int>	_ingredient;
  std::string			_typeStr;

  Regina(void);
  void                initIngredient(void);

public:
  Regina(Pizza::TaillePizza, int order = 0);
  Regina(Regina const&);

  virtual std::string const&			getTypeStr() const;
  virtual std::map<std::string, int> const&	getIngredient() const;
  virtual Pizza&				clone() const;

  ~Regina(void);
};

#endif
