
#include "MenuScreen.h"
#include "GameScreen.h"
#include "Game.h"
#include "loadtex.h"
#include <iostream>
#include <memory>
#include <optional>

using namespace touhou;
int MenuScreen::bgmvolume = 80;

MenuScreen::MenuScreen()
    :
    mouse_in_start(false),
    mouse_in_quit(false),
    mouse_in_htp(false)
{
    if (!bgm_.openFromFile("../Music/secret.mp3"))    
        std::cout << "Can't play the music." << std::endl; // error
	bgm_.setLooping(true);
	bgm_.play();
    bgm_.setVolume(bgmvolume);

    loadtexture("../Texture/title00a.png", bgtexture, sf::IntRect({0,0}, {512,480}));
    loadtexture("../Texture/title00b.png", bgtexture2, sf::IntRect({0,0}, {128, 480}));
    loadtexture("../Texture/title01.png",startbutton0, sf::IntRect({160, 0},{160,32}));
    loadtexture("../Texture/title01.png",startbutton1, sf::IntRect({0, 0},{160,32}));
    loadtexture("../Texture/title01.png",quitbutton0, sf::IntRect({80, 256},{64,32}));
    loadtexture("../Texture/title01.png",quitbutton1, sf::IntRect({0, 256},{64,32}));
    loadtexture("../Texture/title01.png",htpbutton0, sf::IntRect({176, 350},{174,32}));
    loadtexture("../Texture/title01.png",htpbutton1, sf::IntRect({0, 350},{174,32}));
    loadtexture("../Texture/title01.png",digitbutton0, sf::IntRect({0, 478},{24,32}));
    loadtexture("../Texture/title01.png",digitbutton1, sf::IntRect({24*(bgmvolume/10), 478},{24,32}));
   
    
    bgsprite = std::make_shared<sf::Sprite>(bgtexture);
    bgsprite2 = std::make_shared<sf::Sprite>(bgtexture2);
    startsprite0 = std::make_shared<sf::Sprite>(startbutton0);
    startsprite1 = std::make_shared<sf::Sprite>(startbutton1);
    quitsprite0 = std::make_shared<sf::Sprite>(quitbutton0);
    quitsprite1 = std::make_shared<sf::Sprite>(quitbutton1);
    htpsprite0 = std::make_shared<sf::Sprite>(htpbutton0);
    htpsprite1 = std::make_shared<sf::Sprite>(htpbutton1);
    digitsprite0 = std::make_shared<sf::Sprite>(digitbutton0);
    digitsprite1 = std::make_shared<sf::Sprite>(digitbutton1);

    bgsprite->setPosition({0, 0});
    bgsprite->setScale({2.0f, 2.0f});
    bgsprite2->setPosition({1024,0});
    bgsprite2->setScale({2.0f, 2.0f});
    startsprite0->setPosition({900, 600});
    startsprite1->setPosition({900, 600});
    htpsprite0->setPosition({900, 650});
    htpsprite1->setPosition({900, 650});
    digitsprite0->setPosition({1144, 650});
    digitsprite1->setPosition({1120, 650});
    quitsprite0->setPosition({900, 700});
    quitsprite1->setPosition({900, 700});
}

void MenuScreen::handleinput(sf::RenderWindow& window)
{
    sf::Vector2i mousePosi = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosf(mousePosi);
    mouse_in_start = startsprite0->getGlobalBounds().contains(mousePosf);
    mouse_in_htp = htpsprite0->getGlobalBounds().contains(mousePosf);
    mouse_in_quit = quitsprite0->getGlobalBounds().contains(mousePosf);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    window.close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        if (mouse_in_start) {
            //开始游戏
            Game::screen = std::make_shared<GameScreen>();
            bgm_.stop();
        }
        else if (mouse_in_htp) {

        }
        else if (mouse_in_quit) {
            window.close();
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (mouse_in_start) {
            //开始游戏
            Game::screen = std::make_shared<GameScreen>();
            bgm_.stop();
        }
        else if (mouse_in_htp) {

        }
        else if (mouse_in_quit) {
            window.close();
        }
    }
}

void MenuScreen::handleevent(sf::RenderWindow& window, const std::optional<sf::Event> event)
{
    if (event->is<sf::Event::Closed>())
		window.close();
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scan::Left)
        {
            if (mouse_in_htp && bgmvolume > 10)
            {
                bgmvolume -= 10;
                bgm_.setVolume(bgmvolume);
                if (!digitbutton1.loadFromFile("../Texture/title01.png", false, sf::IntRect({24*(bgmvolume/10),478},{24,32})))
                    std::cout <<"Can't open the title01 file." << std::endl;
                digitsprite1->setTexture(digitbutton1);
                digitsprite1->setPosition({1120, 650});
            }
        }
        if (keyPressed-> scancode == sf::Keyboard::Scan::Right)
        {
            if (mouse_in_htp && bgmvolume <100)
            {
                bgmvolume += 10;
                bgm_.setVolume(bgmvolume);
                if (!digitbutton1.loadFromFile("../Texture/title01.png", false, sf::IntRect({24*(bgmvolume/10),478},{24,32})))
                    std::cout <<"Can't open the title01 file." << std::endl;
                digitsprite1->setTexture(digitbutton1);
                digitsprite1->setPosition({1120, 650});
            }
        }
    }
}

void MenuScreen::update(sf::Time delta)
{

}

void MenuScreen::display(sf::RenderWindow& window)
{

    window.clear(sf::Color::Black);
    window.draw(*bgsprite);
    window.draw(*bgsprite2);
    if (mouse_in_start) {
        window.draw(*startsprite1);
    }
    else {
        window.draw(*startsprite0);
    }
    if (mouse_in_quit) {
        window.draw(*quitsprite1);
    }
    else {
        window.draw(*quitsprite0);
    }
    if (mouse_in_htp) {
        window.draw(*htpsprite1);
        window.draw(*digitsprite0);
        window.draw(*digitsprite1);
    }
    else {
        window.draw(*htpsprite0);
    }
    window.display();
}

