#include "Menu.h"
#include "Snake.h"
void Menu::start(sf::RenderWindow&window) {
	window.clear();
	sf::Text text;
	sf::Text text2;
	sf::Text text3;
	text.setFont(font); text2.setFont(font) ; text3.setFont(font);
	text.setString("New game <1>"); text2.setString("Settings <2>"); text3.setString("Exit <Esc>");
	text.setCharacterSize(32); text2.setCharacterSize(32); text3.setCharacterSize(32);
	text2.setPosition(0, 33);
	text3.setPosition(0, 65);
	window.draw(text); window.draw(text2); window.draw(text3);
}
void Menu::show(sf::RenderWindow&window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
		is_started = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !is_started)
	{
		window.clear(sf::Color::White);
		is_started = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && is_set) {
		is_set = false;
	}
	else
	{
		start(window);
	}

}
Menu::Menu() {
	is_started = false;
	is_set = true;
	if (!font.loadFromFile("Menu.font.ttf"))
	{
		//error
	}
}
void Menu::showset(sf::RenderWindow&window) {
	window.clear();
	sf::Text text;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text text5;
	text.setFont(font); text2.setFont(font); text3.setFont(font); text4.setFont(font); text5.setFont(font);
	text.setString("30x30 <1>");
	text2.setString("60x60 <2>");
	text3.setString("Easy <3>");
	text4.setString("Hard <4>");
	text5.setString("Menu <Backspace>");
	text.setCharacterSize(32); text2.setCharacterSize(32); text3.setCharacterSize(32); text4.setCharacterSize(32); text5.setCharacterSize(32);
	text2.setPosition(0, 33);
	text3.setPosition(0, 65);
	text4.setPosition(0, 97);
	text5.setPosition(0, 129);
	window.draw(text); window.draw(text2); window.draw(text3); window.draw(text4); window.draw(text5);
}
void Menu::startset(sf::RenderWindow&window, Setting& sett) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
		is_set = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		sett.sizes = 30;
		showsetp(window, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		sett.sizes = 60;
		showsetp(window, 2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		sett.times = 0.7;
		showsetp(window, 3);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
		sett.times = 0.1;
		showsetp(window, 4);
	}
}
void Menu::showsetp(sf::RenderWindow&window, int i) {
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(32);
	text.setPosition(0, 200);
	switch (i)
	{
	case 1: text.setString("30x30"); break;
	case 2: text.setString("60x60"); break;
	case 3: text.setString("Easy"); break;
	case 4: text.setString("Hard"); break;
	}
}