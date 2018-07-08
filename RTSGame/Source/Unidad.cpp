#include "../Include/Unidad.h"

int Unidad::get_vida() {
    return vida;
}

int Unidad::get_atk() {
    return atk;
}

int Unidad::get_def() {
    return def;
}

int Unidad::get_rango() {
    return rango;
}


void Unidad::mover(sf::Time deltaTime) {
    sf::Vector2f movementP(0.f, 0.f);
    if (mIsMovingUp)
        movementP.y -= velocidad;
    if (mIsMovingDown)
        movementP.y += velocidad;
    if (mIsMovingLeft)
        movementP.x -= velocidad;
    if (mIsMovingRight)
        movementP.x += velocidad;
    mSprite.move(movementP * deltaTime.asSeconds());

}

void Aliadas::atacar() {

}

void Aliadas::moverMouse(sf::Time deltaTime, sf::Vector2f mousePos) {
    sf::FloatRect mouse(mousePos,{70,70});
    sf::Vector2f posicion=mSprite.getPosition();
    if(mSprite.getGlobalBounds().intersects(mouse)){
        movingmouse=false;
    }
    if(movingmouse)
        mSprite.move((mousePos - posicion)*deltaTime.asSeconds());

}

void Enemigos::atacar() {

}

