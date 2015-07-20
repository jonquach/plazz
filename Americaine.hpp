//
// Americaine.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Fri Apr 17 11:31:27 2015 jonathan kauch
// Last update Fri Apr 17 11:46:04 2015 jonathan kauch
//

#ifndef		AMERICAINE_HPP_
# define	AMERICAINE_HPP_

# include <iostream>
# include <string>
# include <map>

# include "Pizza.hpp"

class				Americaine : public Pizza
{

private:
  std::map<std::string, int>	_ingredient;
  std::string			_typeStr;

  Americaine(void);
  void                initIngredient(void);

public:
  Americaine(Pizza::TaillePizza, int order = 0);
  Americaine(Americaine const&);

  virtual std::string const&			getTypeStr() const;
  virtual std::map<std::string, int> const&	getIngredient() const;
  virtual Pizza&				clone() const;

  ~Americaine(void);
};

#endif
