#include "Game.h"
#include <ctime>
#include <cstdlib>
void Game::launch() {
	srand(std::time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Wunsz");
	window.setVerticalSyncEnabled(true);
	Menu menu;
	menu = Menu();
	set_text();
	sets = Setting();
	if (!eat.texture.loadFromFile("Apple.png"))
	{
		// error...
	}
	new_game();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			while (!menu.is_started && menu.is_set) {
				menu.show(window);
				window.display();
			}
			while (!menu.is_set && !menu.is_started) {
				menu.showset(window);
				menu.startset(window, sets);
				window.display();
			}
			while (loser && menu.is_started) {
				lost(window);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
					menu.is_started = false;
					new_game();
				}
				window.display();
			}
			if (!select) change(event);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) snake.push_back(Snake(sets));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) snake.pop_back();
			if (menu.is_started && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				menu.is_started = false;
				new_game();
			}
		}
		window.clear(sf::Color::White);
		time = clock.getElapsedTime();
		if (time.asSeconds() >= sets.times)  move_whole();
		if (snake[0].getpos() == eat.getpos()) {
			eat.reset(snake, sets);
			snake.push_back(Snake(sets));
		}
		bang();
		window.draw(eat);
		draw_whole(window);
		draw_text(window);
		window.display();
	}
}
void Game::change(sf::Event event) {
		switch (event.key.code) {
		case sf::Keyboard::Up: if (where != down) { where = up; select = true; } break;
		case sf::Keyboard::Down: if (where != up) { where = down; select = true; } break;
		case sf::Keyboard::Left: if (where != right) { where = left; select = true; } break;
		case sf::Keyboard::Right: if (where != left) { where = right; select = true; } break;
	}
}
void Game::move_whole() {
	for (int i = snake.size() - 1; i > 0; i--) snake[i].setpos(snake[i - 1].getpos().x, snake[i - 1].getpos().y);
	switch (where) {
	case up: snake[0].move(0, -sets.sizes, sets); break;
	case down: snake[0].move(0, sets.sizes, sets); break;
	case left: snake[0].move(-sets.sizes, 0, sets); break;
	case right: snake[0].move(sets.sizes, 0, sets); break;
	}
	select = false;
	clock.restart();
}
void Game::draw_whole(sf::RenderWindow &window) {
	for (int i = 0; i < snake.size(); i++) {
		snake[i].draw(window);
	}
}
void Game::bang() {
	for (int i = 1; i < snake.size(); i++) {
		if (snake[0].getpos() == snake[i].getpos()) {
			loser = true;
			return;
		}
	}
}
void Game::new_game() {
	snake.clear();
	snake.push_back(Snake(sets));
	where = none;
	select = true;
	loser = false;
	eat = Food(sets);
	snake[0].setpos(0, 0);
	while (eat.getpos() == snake[0].getpos()) {
		eat.~Food();
		eat = Food(sets);
	}
}
void Game::set_text() {
	if (!font.loadFromFile("Menu.font.ttf")) {
		//error
	}
	back.setFont(font); back2.setFont(font);
	back.setString("Back to menu:"); back2.setString("<backspace>");
	back.setCharacterSize(18); back2.setCharacterSize(18);
	back.setPosition(620, 20); back2.setPosition(635, 40);
	back.setColor(sf::Color::Black); back2.setColor(sf::Color::Black);
}
void Game::draw_text(sf::RenderWindow &window) {
	window.draw(back);
	window.draw(back2);
}
Game::~Game() {
	snake.clear();
}
void Game::lost(sf::RenderWindow& window) {
	window.clear();
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(32);
	text.setString("You lost <backspace to menu>");
	text.setPosition(200, 150);
	window.draw(text);
}