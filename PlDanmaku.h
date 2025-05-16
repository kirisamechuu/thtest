#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

namespace touhou
{
enum class dtype
{
    ORIGIN,
    ADDED,
    LASER
};
class PlDanmaku
{
public:

    PlDanmaku(dtype type);
    void move(sf::Vector2f move_);
    bool shouldremoved();
private:
    float speed_;
    dtype type_;
    sf::Vector2f direction_;
    sf::Vector2f pos_;
    std::shared_ptr<sf::Sprite> sprite_;
    sf::Texture tex_;
    float damage_;
    sf::FloatRect judgearea_;
    void initpos_();
    void setjudgearea_();
friend class Player;
};
} // namespace touhou
