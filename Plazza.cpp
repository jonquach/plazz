//
// Plazza.cpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Mon Apr 13 14:02:33 2015 jonathan kauch
// Last update Sun Apr 26 23:09:37 2015 Jonathan Quach
//

#include <unistd.h>
#include "Plazza.hpp"

Plazza::Plazza(double multiCooking, int nbCooks, int timeMillisecond) :
  _multiCooking(multiCooking),
  _nbCooks(nbCooks),
  _timeMillisecond(timeMillisecond),
  _total(0)
{
  _x = 1;
  _y = 1;

  initscr();
  keypad(stdscr, true);
  //  noecho();
  //nodelay(stdscr, TRUE);
  curs_set(1);
  start_color();
  has_colors();
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  refresh();

  getmaxyx(stdscr, _parentY, _parentX);

  _body = newwin(30, _parentX, 0, 0);
  wborder(_body, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(_body);

  _footer = newwin(12, _parentX, 30 , 0);
  wattron(_footer, COLOR_PAIR(3));
  wborder(_footer, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(_footer);
  wattroff(_footer, COLOR_PAIR(3));
}

Plazza::Plazza(Plazza const& other) :
  _multiCooking(other._multiCooking),
  _nbCooks(other._nbCooks),
  _timeMillisecond(other._timeMillisecond)
{
  int status;

  if (_pid != 0)
    waitpid(_pid, &status, 0);
}

Plazza& Plazza::operator=(Plazza const& other)
{
  if (this != &other)
    {
      _multiCooking = other._multiCooking;
      _nbCooks = other._nbCooks;
      _timeMillisecond = other._timeMillisecond;
    }
  return *this;
}

Plazza::~Plazza()
{
  if (this->_body != NULL)
    {
      if (delwin(_body) == ERR)
	throw errorException(std::string("Can't destroy the window"));
    }
  if (this->_footer != NULL)
    {
      if (delwin(_footer) == ERR)
	throw errorException(std::string("Can't destroy the window"));
    }
  if (endwin() == ERR)
    throw errorException(std::string("Can't restore the window"));
}

void		Plazza::draw_menu()
{
  wattron(_footer, COLOR_PAIR(3));
  mvwprintw(_footer, 1, 1, " +-------+\t+--------+\t |");
  mvwprintw(_footer, 2, 1, " | PIZZA |\t| TAILLE |\t |");
  mvwprintw(_footer, 3, 1, " +-------+\t+--------+\t |");
  mvwprintw(_footer, 4, 1, " Regina\t    S\t\t |");
  mvwprintw(_footer, 5, 1, " Margarita\t    M\t\t |");
  mvwprintw(_footer, 6, 1, " Americaine\t    L\t\t |");
  mvwprintw(_footer, 7, 1, " Fantasia\t  XL,XXL\t |");
  wattroff(_footer,COLOR_PAIR(3));
  wrefresh(_footer);
}

void		Plazza::draw_log()
{
  wattron(_footer,COLOR_PAIR(4));
  mvwprintw(_footer, 1, 35, "LOG");
  wattroff(_footer,COLOR_PAIR(4));
  wattron(_footer,COLOR_PAIR(3));
  mvwhline(_footer, 8, 1, '-', _parentX);
  wattroff(_footer,COLOR_PAIR(3));
  wrefresh(_footer);
}

void		Plazza::draw_body()
{
  _body = newwin(30, COLS / 1.2 , (LINES - 30) / 2, (COLS -(COLS / 1.2)) / 2);
  wborder(_body, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(_body);
}

Pizza::TaillePizza	Plazza::findPizzaSize(std::string const &size)
{
  std::map<std::string, Pizza::TaillePizza> _mapTaille;
  std::map<std::string, Pizza::TaillePizza>::const_iterator it;

  _mapTaille["s"] = Pizza::S;
  _mapTaille["m"] = Pizza::M;
  _mapTaille["l"] = Pizza::L;
  _mapTaille["xl"] = Pizza::XL;
  _mapTaille["xxl"] = Pizza::XXL;

  if ((it = _mapTaille.find(size)) != _mapTaille.end())
    return it->second;
  return Pizza::U;
}

template<typename T>
Pizza		*Plazza::createPizza(Pizza::TaillePizza size, int order)
{
  return new T(size, order);
}

void		Plazza::affOrderIntoLog(int const order, int const nb, std::string const& str)
{
  wattron(_body, COLOR_PAIR(2));
  std::stringstream ss;
  ss << "[command " << order << "]-> " << str;
  std::string tmp;
  tmp = ss.str();
  if (_x == 25)
    _x = 1;
  if (nb > 0)
    {
      mvwprintw(_body, _x++, 1, tmp.c_str());
      wrefresh(_body);
    }
  wattroff(_body, COLOR_PAIR(2));
}

void		Plazza::parsing(std::string &line)
{
  std::map<std::string, Pizza *(*)(Pizza::TaillePizza, int)> _mapPizza;
  std::vector<std::string> cmd;
  std::list<Pizza *> list;
  std::istringstream iss(line);
  std::string err = "";
  std::string pizza = "";
  std::string size = "";
  std::string str;
  static int order = 0;
  int nb = 0;

  _mapPizza["regina"] = &Plazza::createPizza<Regina>;
  _mapPizza["margarita"] = &Plazza::createPizza<Margarita>;
  _mapPizza["americaine"] = &Plazza::createPizza<Americaine>;
  _mapPizza["fantasia"] = &Plazza::createPizza<Fantasia>;

  std::transform(line.begin(), line.end(), line.begin(), ::tolower);

  wattron(_body, COLOR_PAIR(2));
  while (iss && iss.rdbuf()->in_avail() != -1)
    {
      iss >> pizza;
      iss >> size;
      iss.ignore(255, 'x');
      iss >> nb;
      iss.ignore(255, ';');
      if (nb < 0)
	nb = 0;

      if (_mapPizza.find(pizza) != _mapPizza.end())
	{
	  if (size == "s" || size == "m" || size == "l"
	      || size == "xl" || size == "xxl")
	    {
	      Pizza::TaillePizza _size = findPizzaSize(size);

	      // create pizza and push back into list
	      for (int i = 0; i < nb; ++i)
		list.push_back((_mapPizza[pizza])(_size, order));

	      // Insert order into list
	      Order	tmp(order, nb, list);

	      //affOrderIntoLog(tmp)

	      _order.push_back(tmp);
	      _total += nb;
	    }
	  else
	    {
	      err = "There no such size for a pizza : " + size;
	      wclrtoeol(_body);
	      mvwprintw(_body, 4, (_parentX / 2 - 45), err.c_str());
	    }
	}
      else
	{
	  err = "There is no pizza called : " + pizza;
	  wclrtoeol(_body);
	  mvwprintw(_body, 3, (_parentX / 2 - 45), err.c_str());
	}
    }
  wattroff(_body, COLOR_PAIR(2));
  if (nb > 0)
    order++;
  affOrderIntoLog(order, nb, std::string("preparation"));
}

void		Plazza::printEcrased()
{
  wattron(_footer, COLOR_PAIR(3));
  mvwprintw(_footer, 10, 0, "|");
  mvwprintw(_footer, 11, 0, "+");
  mvwhline(_footer, 11, 1, '-', _parentX);
  mvwhline(_footer, 11, _parentX - 1, '-', _parentX);
  wattron(_footer, COLOR_PAIR(4));
  mvwprintw(_footer, 9, 2, "What do you want buddy ?");
  wattroff(_footer, COLOR_PAIR(4));
  wrefresh(_footer);
  wattroff(_footer, COLOR_PAIR(3));
}

void		Plazza::displayKitchen(int nb)
{
  std::stringstream ss;
  ss << "[kitchen " << nb << "]-> has been created";
  std::string tmp;
  tmp = ss.str();
  wattron(_body, COLOR_PAIR(4));
  mvwprintw(_body, _x, _y, tmp.c_str());
  ss.str("");
  _x > 28 ? _x = 1 : _x++;
  wattroff(_body, COLOR_PAIR(4));
  wrefresh(_body);
  wattron(_body, COLOR_PAIR(5));
  ss << "[kitchen " << nb << "]-> start to refresh ingredient";
  tmp = ss.str();
  mvwprintw(_body, _x, _y, tmp.c_str());
  _x > 28 ? _x = 1 : _x++;
  wattroff(_body, COLOR_PAIR(5));
  wrefresh(_body);
  _x > 28 ? _x = 1 : _x++;
}

void		Plazza::createNewKitchens(int res)
{
  static int		id = 0;

  res = (res / (_nbCooks * 2)) + 1;

  while (res > 0)
    {
      //Pipe creation
      Pipe *_pipe = new Pipe(id);

      //Kitchen creation
      Kitchen *kitchen = new Kitchen(_multiCooking, _nbCooks, _timeMillisecond,
				     _body, id);

      displayKitchen(id);
      _kitchenList.push_back(kitchen);
      --res;

      ++id;

      //Fork init
      _pid = fork();

      if (_pid == -1)
      	throw errorException("Error : fork failed");

      if (_pid == 0) // CHILD
      	{
	  _pipe->setSon(true);
	  kitchen->run(_x, _y, _pipe);
      	}
      else // FATHER
	{
	  _pipe->setSon(false);
	  kitchen->setPipe(_pipe);
	  _pipeList.push_back(_pipe);
	}
    }
}

bool		Plazza::checkKitchen(Kitchen *kitchen, Pizza *i, int pizzaNb)
{
  std::cout << kitchen->getId()  << std::endl;
  if (kitchen->getIsFree() == true)
    {
      std::stringstream ss;
      ss << "PIZZA " << pizzaNb << " " << i->getTypeStr()
	 << " " << i->getTaillePizza();
      kitchen->getPipe()->writeOutPipe(ss.str());
      kitchen->setPizza(i);
      return true;
    }
  return false;
}

void		Plazza::distribToKitchen(Order& order)
{
  static int	pizzaNb = 0;

  std::list<Pizza *>::iterator i = order._listPizza.begin();
  std::vector<Kitchen *>::iterator it = _kitchenList.begin();

  while (i != order._listPizza.end())
    {
      while (it != _kitchenList.end() && i != order._listPizza.end())
	{
	  if (checkKitchen(*it, *i, pizzaNb) == true)
	    {
	      pizzaNb++;
	      i++;
	    }
	  ++it;
	}
      if (i != order._listPizza.end())
	++i;
    }
}

void		Plazza::distrib()
{
  for (std::list<Order>::iterator it = _order.begin(); it != _order.end(); ++it)
    {
      if (_total > 0)
	{
	  if (_total <= static_cast<int>(_kitchenList.size()) * _nbCooks * 2)
	    {
	      distribToKitchen(*it);
	    }
	  else
	    {
	      createNewKitchens(_total - (static_cast<int>(_kitchenList.size()) * _nbCooks * 2));
	      distribToKitchen(*it);
	    }
	}
      else
	{
	  std::cout << "There is no pizza to cook" << std::endl;
	}
    }
}

void		Plazza::start()
{
  draw_menu();
  draw_log();

  char	buff[4096];
  std::string line;

  while (line != "quit")
    {
      printEcrased();
      move(40, 2);
      clrtoeol();
      getstr(buff);
      line.assign(buff);
      parsing(line);
      distrib();
      wclrtoeol(_footer);
    }
}
