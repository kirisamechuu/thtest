#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"

namespace touhou
{
class MenuScreen : public Screen
{
public:
    MenuScreen();
    void handleinput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
    void display(sf::RenderWindow& window) override;
    void handleevent(sf::RenderWindow& window, std::optional<sf::Event> event) override;
    static int bgmvolume;
private:
    sf::Texture bgtexture, bgtexture2, startbutton0, quitbutton0, startbutton1, quitbutton1, htpbutton0, htpbutton1, digitbutton0, digitbutton1;
    std::shared_ptr<sf::Sprite> bgsprite, bgsprite2, startsprite0, startsprite1, quitsprite0, quitsprite1,htpsprite0, htpsprite1, digitsprite0, digitsprite1; 
    sf::Music bgm_;
    bool mouse_in_start;
    bool mouse_in_quit;
    bool mouse_in_htp;
    // void setTexture(sf::Texture & texture, const std::filesystem::__cxx11::path &filename, sf::IntRect area);
    // void setTexture(sf::Texture & texture, const std::filesystem::__cxx11::path &filename);

};
}

