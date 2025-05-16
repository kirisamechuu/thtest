#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"
#include "Player.h"
#include <optional>
#include <vector>

namespace touhou
{
class GameScreen : public Screen
{
public:
    GameScreen();
    void handleinput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
    void display(sf::RenderWindow& window) override;
    void handleevent(sf::RenderWindow& window, const std::optional<sf::Event> event) override;
    static bool leftpd, rightpd, uppd, downpd, shiftpd, zpd;
private:
    sf::Texture bgt_r1, bgt_r2, bgt_r3, bgt_r4, bgt_r5;
    sf::Texture ft1, ft2, ft3, ft4;
    std::array<std::shared_ptr<sf::Sprite>, 3> bg_r1, bg_r2, bg_r3, bg_r5;
    std::array<std::shared_ptr<sf::Sprite>, 12> bg_r4;
    std::shared_ptr<sf::Sprite> bg_r5r;
    std::shared_ptr<sf::Sprite> frame1, frame2, frame3, frame4;
    sf::Music bgm_game;

    Player pl;
};
}