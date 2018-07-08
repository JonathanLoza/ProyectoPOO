#include "../Include/Map.h"
#include "../Source/Datos.cpp"


Map::Map(): p(10,10,10,10,200),choza(100), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false) {
    mTexture.loadFromFile("../Media/Desert.png");
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    mMap.setTexture(mTexture);
    mMap.setOrigin(50.f,50.f);
    mMap.setPosition(0.f, 0.f);
    mMap.setScale(5,5);
}

void Map::mover(sf::Time deltaTime) {
    sf::Vector2f movementM(0.f, 0.f);

    if (mIsMovingUp){
        movementM.y += Speed;
        altura-=movementM.y;

    }
    if (mIsMovingDown){
        movementM.y -= Speed;
        altura-=movementM.y;

    }
    if (mIsMovingLeft){
        movementM.x += Speed;
        ancho-=movementM.x ;
    }
    if (mIsMovingRight){
        movementM.x -= Speed;
        ancho-=movementM.x ;
    }
    mMap.move(movementM * deltaTime.asSeconds());
}
