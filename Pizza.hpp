//
// Pizza.hpp for  in /home/kauch_j/lab/plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Wed Apr 15 15:17:41 2015 jonathan kauch
// Last update Sun Apr 26 22:12:10 2015 Jonathan Quach
//

#ifndef		PIZZA_HPP_
# define	PIZZA_HPP_

# include <iostream>
# include <string>
# include <map>
# include <pthread.h>

class Pizza
{

public:
  enum TypePizza
    {
      Unknown = 0,
      Regina = 1,
      Margarita = 2,
      Americaine = 4,
      Fantasia = 8
    };

  enum TaillePizza
    {
      U = 0,
      S = 1,
      M = 2,
      L = 4,
      XL = 8,
      XXL = 16
    };

private:
  int					_cookTime;
  std::map<TaillePizza, std::string>	_sizeTab;
  std::map<TypePizza, std::string>	_mapPizza;
  TypePizza				_typePizza;
  TaillePizza				_taillePizza;
  int					_order;
  pthread_mutex_t			_mut;
  bool					_done;
  int					_id;

  void		initTab();

public:
  explicit Pizza(Pizza::TypePizza, Pizza::TaillePizza, int order = 0);
  Pizza(Pizza const& other);
  Pizza& operator=(Pizza const& other);
  virtual ~Pizza();

public:
  int		getCookTime() const;
  TaillePizza	getTaillePizza() const;
  TypePizza	getTypePizza() const;
  int		getOrder() const;
  bool		getDone() const;
  void		setCookTime(int);
  void		setTaillePizza(TaillePizza);
  void		setTypePizza(TypePizza);
  void		setOrder(int);
  void		setDone(bool);
  int		tryLock();
  int		unlock();
  void		setId(int);
  int		getId() const;

  virtual std::string const&			getTypeStr() const = 0;
  virtual std::map<std::string, int> const&	getIngredient() const = 0;
  virtual Pizza&				clone() const = 0;
};

#endif	/*	!PIZZA_HPP_	*/
