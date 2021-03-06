#include "../Include/Choza.h"
#include "Datos.cpp"
#include <iostream>
using namespace std;

//Para Cachimbo
void Cubiculo::update_vida_cachimbo(int x){
    //cachimbo_vida=cachimbo_vida+x;
}

void Cubiculo::update_atk_cachimbo(int x){
    //cachimbo_atk=+x;
}

void Cubiculo::update_def_cachimbo(int x){
    //cachimbo_def=+x;
}

void Cubiculo::update_rango_cachimbo(int x){
    //cachimbo_rango=+x;
}

void Cubiculo::update_velocidad_cachimbo(int x){
    //cachimbo_velocidad=+x;
}

void Cubiculo::update_cachimbo(int x){
    update_atk_cachimbo(x);
    update_def_cachimbo(x);
    update_rango_cachimbo(x);
    update_velocidad_cachimbo(x);
    update_vida_cachimbo(x);
}


//Para Mentor
void Cubiculo::update_vida_mentor(int x){
    //mentor_vida=+x;
}

void Cubiculo::update_atk_mentor(int x){
    //mentor_atk=+x;
}

void Cubiculo::update_def_mentor(int x){
    //mentor_def=+x;
}

void Cubiculo::update_rango_mentor(int x){
    //mentor_rango=+x;
}

void Cubiculo::update_velocidad_mentor(int x){
    //mentor_velocidad=+x;
}

void Cubiculo::update_mentor(int x){
    update_atk_mentor(x);
    update_def_mentor(x);
    update_rango_mentor(x);
    update_velocidad_mentor(x);
    update_vida_mentor(x);
}
//Mover por teclas
void Cubiculo::mover(sf::Time deltaTime) {
    sf::Vector2f movementChoza(0.f, 0.f);

    if (mIsMovingUp)
        movementChoza.y -= Speed;
    if (mIsMovingDown)
        movementChoza.y += Speed;
    if (mIsMovingLeft)
        movementChoza.x -= Speed;
    if (mIsMovingRight)
        movementChoza.x += Speed;
    mChoza.move(movementChoza * deltaTime.asSeconds());
}

//Mover por teclas
void Pre::mover(sf::Time deltaTime) {
    sf::Vector2f movementChoza(0.f, 0.f);

    if (mIsMovingUp)
        movementChoza.y -= Speed;
    if (mIsMovingDown)
        movementChoza.y += Speed;
    if (mIsMovingLeft)
        movementChoza.x -= Speed;
    if (mIsMovingRight)
        movementChoza.x += Speed;
    mChoza.move(movementChoza * deltaTime.asSeconds());
}



