#ifndef food_h_
#define food_h_
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include "Snake.h"
#include "Setting.h"
class Food : public sf::Drawable {
	sf::RectangleShape edible;
	//sf::Texture texture;
	bool eaten;
	int x, y;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	sf::Texture texture;
	Food() {};
	Food(Setting& set);
	~Food() {};
	sf::Vector2f getpos();
	void reset(std::vector <Snake> & snake, Setting& set);
};
#endif food_h_
