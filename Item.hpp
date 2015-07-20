//
// Item.hpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Sat Apr 25 14:35:35 2015 jonathan kauch
// Last update Sat Apr 25 14:50:57 2015 jonathan kauch
//

#ifndef		ITEM_HPP_
# define	ITEM_HPP_

# include <list>
# include <string>

class		Item
{
private:
  std::string		_name;
  int			_nb;
public:
  Item(std::string const&, int const);
  ~Item();
  Item(Item const&);
  Item& operator=(Item const&);

  std::string const& getName() const;
  int getNb() const;
  void setNb(int const);
  bool removeIngredient(std::string const&);
};

#endif	/*	!ITEM_HPP_	*/
