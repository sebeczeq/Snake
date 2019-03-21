#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "Menu.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"

int main() {
	Game game = Game();
	game.launch();
	return 0;
}