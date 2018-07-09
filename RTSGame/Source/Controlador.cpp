#include "../Include/Controlador.h"
#include <stdlib.h>
#include <unistd.h>
#include "../Include/Game.h"
using  namespace std;

//Agregar unidades al vecor unidades
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

//Mover por teclas de mapa
void Controller::move_all() {
    for(auto unidad:unidades){
        unidad->mover(TimePerFrame);
    }
    for(auto unidad:enemigos){
        unidad->mover(TimePerFrame);
    }
}
//Mover por mouse
void Controller::mouse_all(sf::Time deltaTime, sf::Vector2f mousePos) {
    for(auto unidad:unidades){
        unidad->moverMouse(TimePerFrame,mousePos);
    }
}
//Mover enemigos por mouse
void Controller::enemove() {
    for(auto unidad:enemigos){
        unidad->moverene(TimePerFrame);
    }
}
//Atk Unidades
void Controller::atk_all() {

    for(auto unidad:unidades){
        unidad->atacar();

    }

}

//Bool mIsMovingUp
void Controller::boolUp(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingUp=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingUp=isPressed;
    }
}
//Bool mIsMovingDown
void Controller::boolDown(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingDown=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingDown=isPressed;
    }
}

//Bool mIsMovingRight
void Controller::boolRight(bool isPressed) {
    for(auto unidad:unidades){
        unidad->mIsMovingRight=isPressed;
    }
    for(auto unidad:enemigos){
        unidad->mIsMovingRight=isPressed;
    }
}
//Bool Mouse
void Controller::boolmouse(bool isPressed) {
    for(auto unidad:unidades){
        unidad->movingmouse=isPressed;
    }
}
//Bool mIsMovingLeft
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
//Llamar a projectiles
void Controller::projdraw(sf::RenderWindow *window) {
    for(auto unidad:unidades){
        unidad->updateprojectile(window);
    }
    for(auto unidad:enemigos){
        unidad->updateprojectile(window);
    }
}
//Incluir enemigos al vector enemigos
void Controller::incluirenemigos(Enemigos* unidad) {
    if (dynamic_cast<Profesor*>(unidad) != nullptr) {
        enemigos.emplace_back(unidad);
    }
    else if (dynamic_cast<TA*>(unidad) != nullptr) {
        enemigos.emplace_back(unidad);
    }
}
//Bool enemigosUp
void Controller::booleneUp(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Up=isPressed;
    }
}
//Bool enemigosDown
void Controller::booleneDown(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Down=isPressed;
    }
}
//Bool enemigosRight
void Controller::booleneRight(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Right=isPressed;
    }
}
//Bool enemigosLeft
void Controller::booleneLeft(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Left=isPressed;
    }
}
//Enemigos atacar
void Controller::eneatk() {
    for(auto unidad:enemigos){
        unidad->atacar();
    }
}
//Detectar unidad cerca (aun en desarrollo, genera error)
void Controller::detectar() {
    this->counter1 = 0;
    this->counter2=0;
    sf::Vector2f uniposicion;
    sf::Vector2f eneposicion;

    for (iterenemigos = enemigos.begin(); iterenemigos != enemigos.end(); iterenemigos++)
    {
        eneposicion=enemigos[counter2]->sprite.sprite.getPosition();

        for (iteraliados = unidades.begin(); iteraliados != unidades.end(); iteraliados++)
        {
            uniposicion=unidades[counter1]->sprite.sprite.getPosition();
            float dx=abs(uniposicion.x-eneposicion.x);
            float dy=abs(uniposicion.y-eneposicion.y);
            if(dx<50.0 and dy-50.0){
                enemigos[counter2]->atkrandom=true;
                break;
            }else{
                enemigos[counter2]->atkrandom=false;
            }
            counter2++;

        }
        counter1++;

    }

}
//Colisiones entre profesor y los projectiles
void Controller::checkcolisiones() {
    this->counter1=0;
    this->counter2=0;
    this->counter3=0;
    for (iteraliados = unidades.begin(); iteraliados != unidades.end(); iteraliados++)
    {
        counter2 = 0;
        for (unidades[counter1]->iter = unidades[counter1]->projectileArray.begin(); unidades[counter1]->iter != unidades[counter1]->projectileArray.end(); unidades[counter1]->iter++)
        {
            counter3 = 0;
            for (iterenemigos = enemigos.begin(); iterenemigos != enemigos.end(); iterenemigos++)
            {
                if (unidades[counter1]->projectileArray[counter2].rect.getGlobalBounds().intersects(enemigos[counter3]->sprite.sprite.getGlobalBounds()))
                {
                    unidades[counter1]->projectileArray[counter2].destroy = true;

                    enemigos[counter3]->vida -= unidades[counter1]->get_atk();
                    if (enemigos[counter2]->vida <= 0)
                    {
                        enemigos[counter2]->alive = false;
                    }
                }
                counter3++;
            }
            counter2++;
        }
        counter1++;
    }
    /*this->counter1=0;
    this->counter2=0;
    this->counter3=0;
    for (iteraliados = unidades.begin(); iteraliados != unidades.end(); iteraliados++)
    {
        for (iterenemigos = enemigos.begin(); iterenemigos != enemigos.end(); iterenemigos++)
        {
            if (unidades[counter1]->sprite.temp.getGlobalBounds().intersects(enemigos[counter3]->sprite.temp.getGlobalBounds()))
            {
                unidades[counter1]->vida -= enemigos[counter3]->get_atk();
                if (unidades[counter1]->vida <= 0)
                {
                    unidades[counter1]->alive = false;
                }
            }
            counter3++;
        }
        counter1++;
    }*/
}
//Checkear las muertes
void Controller::checkdeads() {
    this->counter1 = 0;
    this->counter2=0;
    for (iterenemigos = enemigos.begin(); iterenemigos != enemigos.end(); iterenemigos++)
    {
        if (!enemigos[counter1]->alive)
        {
            delete enemigos[counter1];
            enemigos.erase(iterenemigos);
            break;
        }
        counter1++;
    }
    for (iteraliados = unidades.begin(); iteraliados != unidades.end(); iteraliados++)
    {
        if (!unidades[counter2]->alive)
        {
            delete unidades[counter2];
            unidades.erase(iteraliados);
            break;
        }
        counter2++;
    }


}
//Mover random
void Controller::randomenem() {
    for(auto unidad:enemigos){
        unidad->moverrandom();
    }
}
//Bool Random
void Controller::boolrandom(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->atkrandom=isPressed;
    }
}







