//
// Fantasia.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:31:51 2015 jonathan kauch
// Last update Fri Apr 17 11:47:11 2015 jonathan kauch
//

#ifndef		FANTASIA_HPP_
# define	FANTASIA_HPP_

# include <iostream>
# include <string>
# include <map>

# include "Pizza.hpp"

class				Fantasia : public Pizza
{

private:
  std::map<std::string, int>	_ingredient;
  std::string			_typeStr;

  Fantasia(void);
  void                initIngredient(void);

public:
  Fantasia(Pizza::TaillePizza, int order = 0);
  Fantasia(Fantasia const&);

  virtual std::string const&			getTypeStr() const;
  virtual std::map<std::string, int> const&	getIngredient() const;
  virtual Pizza&				clone() const;

  ~Fantasia(void);
};

#endif
