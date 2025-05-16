#pragma once

#include "PlayerAnimation.h"
#include <array>
#include <optional>
#include <SFML/Graphics.hpp>

namespace touhou
{
class Player
{
public:
    Player();
    bool shooting_mode_;
    bool slow_mode_;
    static float timeperframe;
private:
    int life_;
    float speed_;
    sf::Time conti_;
    sf::Vector2f pos_;
    //judgepoint
    std::shared_ptr<sf::Sprite> judgepointsprite_;
    sf::Texture jptex_;
    sf::FloatRect judgearea_;
    //playeranimation
    std::shared_ptr<sf::Sprite> sprite_;
    PlayerAnimation plani_;
    //
    float power_;
    unsigned long long score_;

    void inittexture_();
    void update(sf::Time delta);
    void initpos_();
    void display(sf::RenderWindow& window);
    void move_();
    void checkboundary_(sf::Sprite &sprite);
    void setjudgearea_();
friend class GameScreen;
};


}