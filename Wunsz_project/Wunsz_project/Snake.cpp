#include "Snake.h"
Snake::Snake(Setting set) {
	wunsz.setSize(sf::Vector2f(set.sizes, set.sizes));
	wunsz.setFillColor(sf::Color::Yellow);
	wunsz.setPosition(sf::Vector2f(-100, -100));
}
void Snake::draw(sf::RenderWindow &window) {
	window.draw(wunsz);
}
void Snake::move(int x, int y, Setting set) {
	wunsz.move(sf::Vector2f(x, y));
	x = wunsz.getPosition().x;
	y = wunsz.getPosition().y;
	if (x < 0) {
		x = ((600 / set.sizes)-1) * set.sizes;
		wunsz.setPosition(sf::Vector2f(x, y));
	}
	else if (x >= (600)) {
		x = 0;
		wunsz.setPosition(sf::Vector2f(x, y));
	}
	else if (y < 0) {
		y = ((600 / set.sizes) - 1) * set.sizes;
		wunsz.setPosition(sf::Vector2f(x, y));
	}
	else if (y >= (600)) {
		y = 0;
		wunsz.setPosition(sf::Vector2f(x, y));
	}
}
sf::Vector2f Snake::getpos() {
	return wunsz.getPosition();
}
void Snake::setpos(int x, int y) {
	wunsz.setPosition(sf::Vector2f(x, y));
}