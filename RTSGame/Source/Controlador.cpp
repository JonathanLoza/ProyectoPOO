#include "../Include/Controlador.h"
#include <list>
#include "../Include/Game.h"
using  namespace std;

void Controller::incluir(Aliadas* unidad) {

    if (dynamic_cast<Cachimbo*>(unidad) != nullptr) {
        unidades.emplace_back(unidad);
    }
    else if (dynamic_cast<Mentor*>(unidad) != nullptr) {
        unidades.emplace_back(unidad);
    }
    else if (dynamic_cast<Prota*>(unidad) != nullptr) {
        unidades.emplace_back(unidad);
    }
}

void Controller::move_all() {
    for(auto unidad:unidades){
        unidad->mover(TimePerFrame);
    }
    for(auto unidad:enemigos){
        unidad->mover(TimePerFrame);
    }
}
void Controller::mouse_all(sf::Time deltaTime, sf::Vector2f mousePos) {
    for(auto unidad:unidades){
        unidad->moverMouse(TimePerFrame,mousePos);
    }
}

void Controller::atk_all() {
    for(auto unidad:unidades){
        unidad->atacar();
    }
}


void Controller::boolUp(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingUp=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingUp=isPressed;
    }
}

void Controller::boolDown(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingDown=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingDown=isPressed;
    }
}

void Controller::boolRight(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingRight=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingRight=isPressed;
    }
}

void Controller::boolmouse(bool isPressed) {
    for(auto unidad:unidades){
        unidad->movingmouse=isPressed;
    }
}

void Controller::boolLeft(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingLeft=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingLeft=isPressed;
    }
}

void Controller::draw_all(sf::RenderWindow *window) {
    for(auto unidad:unidades){
        unidad->draw(window);
    }
    for(auto unidad:enemigos){
        unidad->draw(window);
    }
}

void Controller::projdraw(sf::RenderWindow *window) {
    for(auto unidad:unidades){
        unidad->updateprojectile(window);
    }
}

void Controller::incluirenemigos(Enemigos *unidad) {
    if (dynamic_cast<Profesor*>(unidad) != nullptr) {
        enemigos.emplace_back(unidad);
    }
    else if (dynamic_cast<TA*>(unidad) != nullptr) {
        enemigos.emplace_back(unidad);
    }
}





