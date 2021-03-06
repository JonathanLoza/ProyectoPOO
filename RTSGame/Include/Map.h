#ifndef RTSGAME_MAP_H
#define RTSGAME_MAP_H

#include <SFML/Graphics.hpp>
#include "Unidad.h"
#include "Controlador.h"
#include "Choza.h"
#include <iostream>
#include <vector>

class Map{
    const float Speed = 400.f;
public:
    Map();
    sf::Texture mTexture;
    sf::Sprite mMap;
    Controller controlador;
    Cubiculo choza;
    Pre pre;
public:
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
    float altura=0;
    float ancho=0;
public:
    void mover(sf::Time deltaTime);
    void crear(sf::Vector2f mousePos);
};


#endif //RTSGAME_MAP_H
