#include "PlDanmaku.h"
#include "loadtex.h"
#include <SFML/Graphics.hpp>

using namespace touhou;

PlDanmaku::PlDanmaku(dtype t)
{
    if (t == dtype::ORIGIN)
    {
        type_ = t;
        speed_ = 50.0f;
        damage_ = 50.0f;
        direction_ = sf::Vector2f({0.0f, -1.0f});
        loadtexture("../Texture/pl01.png", tex_, sf::IntRect({},{}));
        sprite_ = std::make_shared<sf::Sprite>(tex_);
    }
    else if (t == dtype::ADDED)
    {
        type_ = t;
        speed_ = 20.0f;
        damage_ = 100.0f;
        direction_ = sf::Vector2f({0.0f, -1.0f});
        loadtexture("../Texture/pl01.png", tex_, sf::IntRect({},{}));
        sprite_ = std::make_shared<sf::Sprite>(tex_);
    }
    else 
    {
        type_ = t;
        speed_ = 10.0f;
        damage_ = 80.0f;
        direction_ = sf::Vector2f({0.0f, -1.0f});
        loadtexture("../Texture/pl01.png", tex_, sf::IntRect({},{}));
        sprite_ = std::make_shared<sf::Sprite>(tex_);
    }
}