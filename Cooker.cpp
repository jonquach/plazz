#include "Cooker.hpp"

Cooker::Cooker(int id, std::list<Pizza *> &list, double time) :
  _id(id), _pizzaList(list), _time(time)
{
  int _parentX, _parentY;

  initscr();
  keypad(stdscr, true);
  noecho();
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
  static_cast<void>(_parentY);
  wattron(_body, COLOR_PAIR(2));
  _body = newwin(10, _parentX, 20, 20);
  wborder(_body, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(_body);
  wattroff(_body, COLOR_PAIR(2));
}

Cooker::~Cooker()
{
}

int	Cooker::checkPizza(Pizza *p)
{
  // std::cout << "La pizza est FUCK " << std::endl;
  if (p->getDone() == false)
    {
      if (p->tryLock() == 0)
	{
	  std::cout << "La pizza est CHECKING " << std::endl;
	  this->cookPizza(p);
	  return (0);
	}
    }
  return (-1);
}

void	Cooker::cookPizza(Pizza *p)
{
  std::cout << "La pizza est COOCKING " << std::endl;

  sleep(p->getCookTime() * _time);
  p->setDone(true);

  std::stringstream ss;
  std::string tmp;
  ss << p->getTypeStr() << " est prête";
  tmp = ss.str();
  mvwprintw(_body, _x, _y, tmp.c_str());
  wrefresh(_body);
  _x++;
  if (_x > 10)
    {
      _x = 2;
    }
  std::cout << "La pizza est prete" << std::endl;
  if (p->unlock() != 0)
    {
      std::cerr << "Unlock mutexes failed" << std::endl;
    }
}

void	Cooker::start()
{
  std::cout << "Coocker START" << std::endl;
  while (true)
    {
      std::list<Pizza *>::iterator i = _pizzaList.begin();
      while (i != _pizzaList.end())
	{
	  if (this->checkPizza(*i) == 0)
	    break;
	  ++i;
	}
      // std::cout << "Test" << std::endl;
    }
}

void	Cooker::setList(std::list<Pizza *> &list)
{
  _pizzaList = list;
}

void	*cooker_start(void * c)
{
  static_cast<Cooker *>(c)->start();
  return NULL;
}
