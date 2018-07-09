#include "../Include/Controlador.h"
#include <stdlib.h>
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
void Controller::enemove() {
    for(auto unidad:enemigos){
        unidad->moverene(TimePerFrame);
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
    for(auto unidad:enemigos){
        unidad->updateprojectile(window);
    }
}

void Controller::incluirenemigos(Enemigos* unidad) {
    if (dynamic_cast<Profesor*>(unidad) != nullptr) {
        enemigos.emplace_back(unidad);
    }
    else if (dynamic_cast<TA*>(unidad) != nullptr) {
        enemigos.emplace_back(unidad);
    }
}

void Controller::booleneUp(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Up=isPressed;
    }
}

void Controller::booleneDown(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Down=isPressed;
    }
}

void Controller::booleneRight(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Right=isPressed;
    }
}

void Controller::booleneLeft(bool isPressed) {
    for(auto unidad:enemigos){
        unidad->Left=isPressed;
    }
}

void Controller::eneatk() {
    for(auto unidad:enemigos){
        unidad->atacar();
    }
}

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
            if(dx<350.0 and dy-350.0)
                enemigos[counter2]->sprite.sprite.setPosition(unidades[counter1]->sprite.sprite.getPosition());

            //unidades[counter1].update();
            //window->draw(projectileArray[projectile1.counter].rect);
            counter2++;

        }
        counter1++;

    }

}

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

                    enemigos[counter3]->vida -= unidades[counter1]->projectileArray[counter2].attackDamage;
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

}

void Controller::checkdeads() {
    this->counter1 = 0;
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


}






