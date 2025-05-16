#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

namespace touhou
{
class Screen
{
public:
    virtual void handleinput(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void display(sf::RenderWindow& window) = 0;
    virtual void handleevent(sf::RenderWindow& window, const std::optional<sf::Event> event) = 0;
};
}