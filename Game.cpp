#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "MenuScreen.h"
#include "Game.h"

using namespace touhou;

std::shared_ptr<Screen> Game::screen = std::make_shared<MenuScreen>();
std::shared_ptr<Screen> Game::mnScreen = screen;
const sf::Time Game::TimePerFrame = sf::seconds(1.0f / 60.0f);

Game::Game()
: window_(sf::VideoMode({Game::Width, Game::Height}), "touhou")
{
 
}

void Game::handleinput()
{
	while (const std::optional event = window_.pollEvent())
	{
		Game::screen->handleevent(window_, event);
	}
	Game::screen->handleinput(window_);
}

void Game::update(sf::Time delta)
{
	Game::screen->update(delta);
}

void Game::display()
{
	Game::screen->display(window_);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleinput();
			update(TimePerFrame);
		}
		display();
	}
}