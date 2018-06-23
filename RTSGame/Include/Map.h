#ifndef RTSGAME_MAP_H
#define RTSGAME_MAP_H

#include <SFML/Graphics.hpp>
#include "Unidad.h"
#include "Choza.h"
#include <iostream>
class Map{
public:
    Map();
    sf::Texture mTexture;
    sf::Sprite mMap;
    Cachimbo c;
    Profesor p;
    Cubiculo choza;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
};


#endif //RTSGAME_MAP_H
