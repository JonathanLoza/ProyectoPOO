#ifndef RTSGAME_CONTROLADOR_H
#define RTSGAME_CONTROLADOR_H

#include <list>
#include <vector>
#include <memory>
#include "Unidad.h"

using namespace std;

class Controller{
    list <Aliadas*> unidades;
public:
    ~Controller(){};
    void incluir(Aliadas* unidad);
    void move_all();
    void projdraw(sf::RenderWindow* window);
    void mouse_all(sf::Time deltaTime, sf::Vector2f mousePos);
    void draw_all(sf::RenderWindow* window);
    void boolUp(bool isPressed);
    void boolDown(bool isPressed);
    void boolRight(bool isPressed);
    void boolLeft(bool isPressed);
    void boolmouse(bool isPressed);
    void atk_all();
};

#endif //RTSGAME_CONTROLADOR_H
