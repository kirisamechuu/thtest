#include "GameScreen.h"
#include "MenuScreen.h"
#include "loadtex.h"
#include "Player.h"
#include <iostream>

using namespace touhou;
bool GameScreen::rightpd = false;
bool GameScreen::leftpd = false;
bool GameScreen::uppd = false;
bool GameScreen::downpd = false;
bool GameScreen::zpd = false;
bool GameScreen::shiftpd = false;

GameScreen::GameScreen()
{
    //bgm
    if (!bgm_game.openFromFile("../Music/secret.mp3"));
    bgm_game.setLooping(true);
    bgm_game.play();
    bgm_game.setVolume(MenuScreen::bgmvolume);
    
    //background
    loadtexture("../Texture/stg3bg.png",bgt_r1,sf::IntRect({0,0}, {128,256}));
    loadtexture("../Texture/stg3bg.png",bgt_r2,sf::IntRect({128,0}, {128,256}));
    loadtexture("../Texture/stg3bg3.png",bgt_r3);
    loadtexture("../Texture/stg3bg2.png",bgt_r4);
    loadtexture("../Texture/stg3bg4.png",bgt_r5);
    loadtexture("../Texture/front00.png",ft1,sf::IntRect({0, 0}, {32, 480}));
    loadtexture("../Texture/front00.png",ft2,sf::IntRect({32, 0}, {224, 480}));
    loadtexture("../Texture/front00.png",ft3,sf::IntRect({0, 480}, {384, 16}));
    loadtexture("../Texture/front00.png",ft4,sf::IntRect({0, 496}, {384, 16}));

    //set background state
    float height = 512;
    float height_w = 256;

    for (int i = 0; i < 3; ++i)
    {
  //    bg_r1[i]->setTexture(bgt_r1); segmentation fault  
        bg_r1[i] = std::make_shared<sf::Sprite>(bgt_r1);
        bg_r1[i]->setScale({2.0f, 2.0f});
        bg_r1[i]->setPosition({64, i*height});

        bg_r2[i] = std::make_shared<sf::Sprite>(bgt_r2);
        bg_r2[i]->setOrigin({128, 0});
        bg_r2[i]->setScale({2.0f, 2.0f});
        bg_r2[i]->setPosition({832, i*height});

        bg_r3[i] = std::make_shared<sf::Sprite>(bgt_r3);
        bg_r3[i]->setScale({1.0f, 1.0f});
        bg_r3[i]->setPosition({128, i*height});

        bg_r5[i] = std::make_shared<sf::Sprite>(bgt_r5);
        bg_r5[i]->setPosition({120, i*height});
    }
    bg_r5r = std::make_shared<sf::Sprite>(bgt_r5);
    bg_r5r->setScale({2.0f, 2.0f});
    bg_r5r->setRotation(sf::degrees(180));
    bg_r5r->setPosition({832,0});
    for (int i = 0; i < 12; ++i)
    {
        bg_r4[i] = std::make_shared<sf::Sprite>(bgt_r4);
        bg_r4[i]->setScale({2.0f, 2.0f});
        bg_r4[i]->setPosition({128.0f+ (i / 6)*256.0f, height_w*(i % 6)});
        bg_r4[i]->setColor(sf::Color(255, 255, 255, 128));
    }
    frame1 = std::make_shared<sf::Sprite>(ft1);
    frame1->setScale({2.0f,2.0f});
    frame1->setPosition({0, 0});
    
    frame2 = std::make_shared<sf::Sprite>(ft2);
    frame2->setScale({2.0f, 2.0f});
    frame2->setPosition({832, 0});

    frame3 = std::make_shared<sf::Sprite>(ft3);
    frame3->setScale({2.0f, 2.0f});
    frame3->setPosition({64, 0});

    frame4 = std::make_shared<sf::Sprite>(ft4);
    frame4->setScale({2.0f, 2.0f});
    frame4->setPosition({64, 928});

    //player
    pl;
}

void GameScreen::handleevent(sf::RenderWindow& window,const std::optional<sf::Event> event)
{

}

void GameScreen::handleinput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            leftpd = true;
            rightpd = false;
        }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            rightpd = true;
            leftpd = false;
        }
    else 
    {
        rightpd = false;
        leftpd = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        uppd = true;
        downpd = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        downpd = true;
        uppd = false;
    }
    else
    {
         downpd = false;
         uppd = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Z))
        zpd = true;
    else zpd = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
        shiftpd = true;
    else shiftpd = false;


}

void GameScreen::update(sf::Time delta)
{
    //update background
    float height = 512;
    float height_w = 256;
    float bg12_move = 60*delta.asSeconds();
    float bg3_move = 30*delta.asSeconds();
    float bg4_move = 45*delta.asSeconds();
    for (auto& sprite : bg_r1)
    {
        sprite->move({0,bg12_move});
        if (sprite->getPosition().y >= 2*height)
            sprite->setPosition({64, -height});
    }
    for (auto& sprite : bg_r2)
    {
        sprite->move({0,bg12_move});
        if (sprite->getPosition().y >= 2*height)
            sprite->setPosition({832, -height});
    }
    for (auto& sprite : bg_r3)
    {
        sprite->move({0, bg3_move});
        if (sprite->getPosition().y >= 2*height)
            sprite->setPosition({128, -height});
    }
    for (int i = 0; i < 12; ++i)
    {
        bg_r4[i]->move({0,bg4_move});
        if (bg_r4[i]->getPosition().y >= 5*height_w)
            bg_r4[i]->setPosition({128 + 256.0f*( i / 6), -height_w});
    }
    for (auto& sprite : bg_r5)
    {
        sprite->move({0, bg12_move});
        if (sprite->getPosition().y >= 2*height)
            sprite->setPosition({120, -height});
    }
    bg_r5r->move({0, bg12_move});
    if (bg_r5r->getPosition().y >= 4*height)
        bg_r5r->setPosition({832, 0});

    //update player
    pl.update(delta);
    
}

void GameScreen::display(sf::RenderWindow& window)
{
    window.clear();

    for (auto& sprite : bg_r3)
        window.draw(*sprite);
    for (auto& sprite : bg_r4)
        window.draw(*sprite);
    for (auto& sprite : bg_r1)
        window.draw(*sprite);
    for (auto& sprite : bg_r2)
        window.draw(*sprite);
    for (auto& sprite : bg_r5)
        window.draw(*sprite);
    window.draw(*bg_r5r);

    window.draw(*frame1);
    window.draw(*frame2);
    window.draw(*frame3);
    window.draw(*frame4);

    pl.display(window);

    window.display();
}