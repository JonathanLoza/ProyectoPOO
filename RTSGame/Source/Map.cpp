#include "../Include/Map.h"
#include "../Source/Datos.cpp"


Map::Map(): choza(100), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false) {
    mTexture.loadFromFile("../Media/Desert.png");
    controlador.incluir(new Prota(prota_vida,prota_atk,prota_def,prota_rango,prota_velocidad));
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    controlador.incluir(new Mentor(mentor_vida,mentor_atk,mentor_def,mentor_rango,mentor_velocidad));
    controlador.incluir(new Mentor(mentor_vida,mentor_atk,mentor_def,mentor_rango,mentor_velocidad));
    controlador.incluir(new Mentor(mentor_vida,mentor_atk,mentor_def,mentor_rango,mentor_velocidad));
    for (int i = 0; i <10; ++i) {
        controlador.incluirenemigos(new Profesor(profesor_vida,profesor_atk,profesor_def,profesor_rango,profesor_velocidad));
    }
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
