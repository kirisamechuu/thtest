#include "Player.h"
#include "loadtex.h"
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "GameScreen.h"

using namespace touhou;

float Player::timeperframe = 0.15f;

void Player::inittexture_()
{
    Player::sprite_ = std::make_shared<sf::Sprite>(plani_.getfirsttex());
    loadtexture("../Texture/pl01.png", Player::jptex_, sf::IntRect({136,200},{16,16}));
    Player::judgepointsprite_ = std::make_shared<sf::Sprite>(Player::jptex_);
}

void Player::initpos_()
{
    sprite_->setOrigin({16.0f, 24.0f});
    sprite_->setPosition({448.0f, 810.0f});
    sprite_->setScale({2.0f, 2.0f});
    judgepointsprite_->setOrigin({8.0f, 8.0f});
    judgepointsprite_->setPosition({448.0f, 810.0f});
    judgepointsprite_->setScale({2.0f, 2.0f});
}

Player::Player()
{
    life_ = 3;
    speed_ = 2.0f;
    plani_.loadtotaltex();
    inittexture_();
    initpos_();
    conti_ = sf::seconds(0);
    setjudgearea_();
}

void Player::checkboundary_(sf::Sprite &sprite)
{   
    sf::Vector2f pos = sprite.getPosition();
    pos.x = std::clamp(pos.x, 90.0f, 806.0f);
    pos.y = std::clamp(pos.y, 75.0f, 895.0f);
    sprite.setPosition(pos);
}

void Player::setjudgearea_()
{
    sf::FloatRect judgearea = judgepointsprite_->getGlobalBounds();
    judgearea.size -= sf::Vector2f({8.0f, 8.0f});
    judgearea.position  += sf::Vector2f({4.0f, 4.0f});
    judgearea_ = judgearea;
}

void Player::move_()
{
    if ((GameScreen::leftpd + GameScreen::rightpd) && (GameScreen::uppd + GameScreen::downpd)){
    sprite_->move({(-speed_*(3-2*slow_mode_)*GameScreen::leftpd + speed_*(3-2*slow_mode_)*GameScreen::rightpd)*0.707f, (-speed_*(3-2*slow_mode_)*GameScreen::uppd + speed_*(3-2*slow_mode_)*GameScreen::downpd)*0.707f});
    judgepointsprite_->move({(-speed_*(3-2*slow_mode_)*GameScreen::leftpd + speed_*(3-2*slow_mode_)*GameScreen::rightpd)*0.707f, (-speed_*(3-2*slow_mode_)*GameScreen::uppd + speed_*(3-2*slow_mode_)*GameScreen::downpd)*0.707f});
    }
    else if ((GameScreen::leftpd + GameScreen::rightpd) || (GameScreen::uppd + GameScreen::downpd)){
    sprite_->move({(-speed_*(3-2*slow_mode_)*GameScreen::leftpd + speed_*(3-2*slow_mode_)*GameScreen::rightpd), (-speed_*(3-2*slow_mode_)*GameScreen::uppd + speed_*(3-2*slow_mode_)*GameScreen::downpd)});
    judgepointsprite_->move({(-speed_*(3-2*slow_mode_)*GameScreen::leftpd + speed_*(3-2*slow_mode_)*GameScreen::rightpd), (-speed_*(3-2*slow_mode_)*GameScreen::uppd + speed_*(3-2*slow_mode_)*GameScreen::downpd)});
    }
    checkboundary_(*sprite_);
    checkboundary_(*judgepointsprite_);
    setjudgearea_();
}

void Player::update(sf::Time delta)
{
    conti_ += delta;
    float conti_f = conti_.asSeconds();
    int framecount = static_cast<int>(conti_f / timeperframe);
    if (!GameScreen::rightpd && !GameScreen::leftpd)
    sprite_->setTexture(plani_.idle_anim[framecount % 8]);
    if (GameScreen::rightpd)
    {
        if (framecount >= 8)
        sprite_->setTexture(plani_.right_anim[7]);
        else 
        sprite_->setTexture(plani_.right_anim[framecount]);
    }
    if (GameScreen::leftpd)
    {
        if (framecount >= 8)
        sprite_->setTexture(plani_.left_anim[7]);
        else
        sprite_->setTexture(plani_.left_anim[framecount]);
    }
    if (GameScreen::zpd)
        shooting_mode_ = true;
        else shooting_mode_ = false;
    if (GameScreen::shiftpd)
        slow_mode_ = true;
        else slow_mode_ = false;
    move_();
}

void Player::display(sf::RenderWindow& window)
{
    window.draw(*sprite_);
    if (slow_mode_)
    window.draw(*judgepointsprite_);
}