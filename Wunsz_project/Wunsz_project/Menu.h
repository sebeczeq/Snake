#ifndef menu_h_
#define menu_h_
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Snake.h"
#include "Setting.h"
#include "Game.h"
class Menu{
	sf::Font font;
public:
	bool is_started;
	bool is_set;
	void start(sf::RenderWindow&window);
	void startset(sf::RenderWindow&window, Setting& sett);
	void show(sf::RenderWindow&window);
	void showset(sf::RenderWindow&window);
	void showsetp(sf::RenderWindow&window, int i);
	Menu();
};
#endif menu_h_