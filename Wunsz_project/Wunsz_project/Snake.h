#ifndef snake_h_
#define snake_h_
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include "Setting.h"
class Snake : public Setting{
	sf::RectangleShape wunsz;
public:
	Snake(Setting set);
	void draw(sf::RenderWindow &window);
	void move(int x, int y, Setting set);
	void setpos(int x, int y);
	sf::Vector2f getpos();
};
#endif snake_h_