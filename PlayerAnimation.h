#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>
#include "loadtex.h"
#include "Screen.h"



namespace touhou
{
class PlayerAnimation
{
public:
    enum class State {
        IDLE,
        MOVE_LEFT,
        MOVE_RIGHT,
        DEATH
    };
    void loadtotaltex();

    void update(sf::Time delta, State curstate);

    sf::Texture& getfirsttex();

    PlayerAnimation();
private:
    std::array<sf::Texture , 8> idle_anim, left_anim, right_anim;
    State curstate;

friend class Player;
};
}