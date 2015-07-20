//
// Margarita.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:13:11 2015 jonathan kauch
// Last update Fri Apr 17 11:46:14 2015 jonathan kauch
//

#ifndef		MARGARITA_HPP_
# define	MARGARITA_HPP_

# include <iostream>
# include <string>
# include <map>

# include "Pizza.hpp"

class				Margarita : public Pizza
{

private:
  std::map<std::string, int>	_ingredient;
  std::string			_typeStr;

  Margarita(void);
  void                initIngredient(void);

public:
  Margarita(Pizza::TaillePizza, int order = 0);
  Margarita(Margarita const&);

  virtual std::string const&			getTypeStr() const;
  virtual std::map<std::string, int> const&	getIngredient() const;
  virtual Pizza&				clone() const;

  ~Margarita(void);
};

#endif
