//
// Kitchen.cpp for  in /home/kauch_j/lab/Plazza
// 
// Made by jonathan kauch
// Login   <kauch_j@epitech.net>
// 
// Started on  Tue Apr 21 16:14:34 2015 Jonathan Quach
// Last update Sun Apr 26 23:16:56 2015 Jonathan Quach
//

#include "Kitchen.hpp"

Kitchen::Kitchen(double multi, int nbCooks, int time, WINDOW *body,
		 int id) :
  _multi(multi), _nbCooks(nbCooks), _time(time / 1000),
  _isFree(true), _body(body), _id(id)
{
  _ingredient["doe"] = 5;
  _ingredient["tomato"] = 5;
  _ingredient["gruyere"] = 5;
  _ingredient["ham"] = 5;
  _ingredient["mushrooms"] = 5;
  _ingredient["steak"] = 5;
  _ingredient["eggplant"] = 5;
  _ingredient["goat cheese"] = 5;
  _ingredient["chief love"] = 5;

  _isOpen = true;
  _isRunning = false;

  //Mutex init
  pthread_mutex_init(&_mutexIngredient, NULL);
}

Kitchen::~Kitchen()
{
  _ingredient.clear();
}

void	Kitchen::run(int x, int y, Pipe *pipe)
{
  _pipe = pipe;
  _isRunning = true;
  _x = x;
  _y = y;

  //Coockers init
  this->createCookers();

  //Ingredient thread
  pthread_create(&_thread, NULL, &threadRunner, this);

  //Running
  std::string line;
  std::map<std::string, void (Kitchen::*)()> funct;

  funct["PIZZA"] = &Kitchen::addPizza;
  funct["EXIT"] = &Kitchen::end;

  while (_isOpen)
    {
      line = _pipe->readInPipe();
      if (line == "")
	end();
      if (funct.find(line) != funct.end())
        (this->*funct[line])();
      line.clear();
    }
}

void	Kitchen::end()
{
  _isRunning = false;
  _isOpen = false;
  pthread_join(_thread, NULL);
  pthread_mutex_destroy(&_mutexIngredient);
  exit(EXIT_SUCCESS);
}

Kitchen::Kitchen(Kitchen const& other)
{
  _multi = other._multi;
  _nbCooks = other._nbCooks;
  _time = other._time;
  _body = other._body;
  _pipe = other._pipe;
}

Kitchen&	Kitchen::operator=(Kitchen const& other)
{
  _multi = other._multi;
  _nbCooks = other._nbCooks;
  _time = other._time;
  _body = other._body;
  _pipe = other._pipe;
  return *this;
}

template<typename T>
Pizza		*Kitchen::createPizza(Pizza::TaillePizza size, int order)
{
  return new T(size, order);
}

bool	Kitchen::checkPizzaList(int id)
{
  for (std::list<Pizza *>::iterator it = _pizzaList.begin();
       it != _pizzaList.end(); ++it)
    {
      if ((*it)->getId() == id)
	return false;
    }
  return true;
}

void	Kitchen::addPizza()
{
  int	pizzaId;
  int	pizzaNb;
  std::string tmp;
  std::string pizzaName;
  Pizza::TaillePizza size;

  tmp = _pipe->readInPipe();

  std::istringstream iss(tmp);

  iss >> pizzaId;
  if (checkPizzaList(pizzaId))
    {
      pizzaName = _pipe->readInPipe();

      tmp = _pipe->readInPipe();

      std::istringstream iss2(tmp);
      iss2 >> pizzaNb;

      size = static_cast<Pizza::TaillePizza>(pizzaNb);

      std::map<std::string, Pizza *(*)(Pizza::TaillePizza, int)> _mapPizza;

      _mapPizza["regina"] = &Kitchen::createPizza<Regina>;
      _mapPizza["margarita"] = &Kitchen::createPizza<Margarita>;
      _mapPizza["americaine"] = &Kitchen::createPizza<Americaine>;
      _mapPizza["fantasia"] = &Kitchen::createPizza<Fantasia>;

      _pizzaList.push_back((_mapPizza[pizzaName])(size, 0));

      for (std::list<std::pair<Cooker *, pthread_t *> >::iterator it = _cookerList.begin();
	   it != _cookerList.end(); ++it)
	{
	  (*it).first->setList(_pizzaList);
	}
    }
}

void	Kitchen::createCookers()
{
  for (int i = 0; i < this->_nbCooks; ++i)
    {
      pthread_t	* t = new pthread_t;
      Cooker	* c = new Cooker(i, this->_pizzaList, _time);
      std::pair<Cooker *, pthread_t *> couple(c, t);

      pthread_create(t,  NULL, &cooker_start, (void *) c);
      this->_cookerList.push_back(couple);
    }
}

void	Kitchen::addIngredient()
{
  while (_isOpen)
    {
      sleep(_time);

      if (pthread_mutex_lock(&_mutexIngredient) != 0)
	throw errorException("Error pthread mutex lock failed.");

      for (std::map<std::string, int>::iterator it = _ingredient.begin();
	   it != _ingredient.end(); ++it)
	{
	  it->second += 1;
	}

      if (pthread_mutex_unlock(&_mutexIngredient) != 0)
      	throw errorException("Error pthread unlock");
    }
}

void	*threadRunner(void *threadRun)
{
  Kitchen *kitchen = static_cast<Kitchen *>(threadRun);

  kitchen->addIngredient();
  return NULL;
}

void	Kitchen::setPizza(Pizza * pizza)
{
  _pizzaList.push_back(pizza);
}

void	Kitchen::displayPizzaList() const
{
  for (std::list<Pizza *>::const_iterator it = _pizzaList.begin(); it != _pizzaList.end(); ++it)
    {
      std::cout << (*it)->getTypeStr() << std::endl;
    }
}

void	Kitchen::setIsFree(bool isFree)
{
  _isFree = isFree;
}

bool	Kitchen::getIsFree() const
{
  return _isFree;
}

void	Kitchen::deleteDrawing()
{
  wclear(_body);
  wrefresh(_body);
}

std::map<std::string, int> const &Kitchen::getIngredient() const
{
  return _ingredient;
}

int	Kitchen::getId() const
{
  return _id;
}

bool	Kitchen::getIsRunning() const
{
  if (_isRunning)
    return _isRunning;
  return false;
}

Pipe	*Kitchen::getPipe() const
{
  return _pipe;
}

void	Kitchen::setPipe(Pipe *pipe)
{
  _pipe = pipe;
}
