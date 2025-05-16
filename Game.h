#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>

#include "Screen.h"
#include "MenuScreen.h"

namespace touhou
{
class Game
{
public:
	Game();

	void run();
	void handleinput();
	void update(sf::Time delta);
	void display();

	static const int Width = 1280;
	static const int Height = 960;

	static std::shared_ptr<Screen> screen;
	static std::shared_ptr<Screen> mnScreen;
private:
	sf::RenderWindow window_;
	static const sf::Time TimePerFrame;
};
}
