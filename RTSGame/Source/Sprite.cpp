//
// Created by jonathan on 08/07/18.
//

#include "../Include/Sprite.h"
projectile::projectile()
{
    rect.setSize(sf::Vector2f(6, 6));
    rect.setPosition(400, 200);
    efe.setPosition(400, 200);
    efe.setRadius(10);

}
//Update del Sprite
void projectile::update()
{
    if(direction==1)
    {
        rect.move(0,-movementSpeed);
        efe.move(0,-movementSpeed);
    }
    if(direction==2)
    {
        rect.move(0,movementSpeed);
        efe.move(0,movementSpeed);
    }
    if(direction==3)
    {
        rect.move(-movementSpeed,0);
        efe.move(-movementSpeed,0);
    }
    if(direction==4)
    {
        rect.move(movementSpeed,0);
        efe.move(movementSpeed,0);
    }
    counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }
}
