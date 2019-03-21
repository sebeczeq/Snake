#include "Food.h"
#include <cstdlib>
Food::Food(Setting& set) {
	edible.setSize(sf::Vector2f(set.sizes, set.sizes));
	edible.setFillColor(sf::Color::Green);
	eaten = false;
	edible.setTexture(&texture);
	x = (rand() % 10) * set.sizes;
	y = (rand() % 10) * set.sizes;
	edible.setPosition(sf::Vector2f(x, y));
	edible.setTextureRect(sf::IntRect(x, y, set.sizes, set.sizes));
}
sf::Vector2f Food::getpos() {
	return edible.getPosition();
}
void Food::reset(std::vector <Snake> & snake, Setting& set) {
	x = (rand() % 10) * set.sizes;
	y = (rand() % 10) * set.sizes;
	edible.setPosition(sf::Vector2f(x, y));
	bool outside = true;
	do {
		for (int i = 0; i < snake.size(); i++) {
			if (snake[i].getpos() == sf::Vector2f(x, y)) {
				outside = false;
				break;
			}
			else outside = true;
		}
		if (!outside) {
			x = (rand() % 10) * set.sizes;
			y = (rand() % 10) * set.sizes;
			edible.setPosition(sf::Vector2f(x, y));
		}
	} while (!outside);
}
void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(edible);
}