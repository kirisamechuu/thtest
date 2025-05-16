#include "PlayerAnimation.h"
#include "loadtex.h"
#include <SFML/Graphics.hpp>

using namespace touhou;



void PlayerAnimation::loadtotaltex()
{
    for (int i = 0; i < 8; ++i) {
        loadtexture("../Texture/pl01.png", idle_anim[i],sf::IntRect({32*i, 0}, { 32, 48}));
        loadtexture("../Texture/pl01.png", left_anim[i],sf::IntRect({32*i, 48}, {32, 48}));
        loadtexture("../Texture/pl01.png", right_anim[i],sf::IntRect({32*i, 96}, {32, 48}));
    }
}

sf::Texture& PlayerAnimation::getfirsttex()
{
    return idle_anim[0];
}

PlayerAnimation::PlayerAnimation()
{
    void loadtotaltex();
}