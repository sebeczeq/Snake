#ifndef game_h_
#define game_h_
#include <vector>
#include "Snake.h"
#include "Menu.h"
#include "Food.h"
#include "Setting.h"
class Game : public Setting {
	std::vector <Snake> snake;
	Food eat;
	Setting sets;
	enum direction {
		up,
		down,
		left,
		right,
		none
	};
	enum direction where;
	bool select;
	bool loser;
	sf::Clock clock;
	sf::Time time;
	sf::Text back;
	sf::Text back2;
	sf::Font font;
public:
	void launch();
	void new_game();
	void change(sf::Event event);
	void move_whole();
	void draw_whole(sf::RenderWindow &window);
	void bang();
	void lost(sf::RenderWindow& window);
	void set_text();
	void draw_text(sf::RenderWindow &window);
	//Game() :Setting() {};
	Game() {};
	~Game();
};
#endif game_h_