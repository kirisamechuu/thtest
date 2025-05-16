#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace touhou
{
inline void loadtexture(const std::filesystem::__cxx11::path path, sf::Texture &texture)
{
    if (!texture.loadFromFile(path, false))
    std::cout << "Can't open " << path << std::endl;
}

inline void loadtexture(const std::filesystem::__cxx11::path path, sf::Texture &texture, sf::IntRect area)
{
    if (!texture.loadFromFile(path, false, area))
    std::cout << "Can't open " << path <<std::endl;
}
}