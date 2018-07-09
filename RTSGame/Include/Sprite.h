//
// Created by jonathan on 08/07/18.
//

#ifndef RTSGAME_SPRITE_H
#define RTSGAME_SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite {
public:
    sf::RectangleShape rect;
    sf::CircleShape efe;
    sf::Sprite sprite;
    int counterWalking = 0;
    int direccion=1;
};

class projectile : public  Sprite
{
public:
    int counter;
    int movementSpeed = 10;
    int attackDamage = 5;
    int direction= 0 ;
    projectile();
    void update();
};
#endif //RTSGAME_SPRITE_H
