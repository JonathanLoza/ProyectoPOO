#ifndef RTSGAME_CONTROLADOR_H
#define RTSGAME_CONTROLADOR_H

#include <list>
#include <vector>
#include <memory>
#include "Unidad.h"

using namespace std;

class Controller{
    vector <Aliadas*> unidades;
    vector<Enemigos*> enemigos;
    vector<Enemigos*>::const_iterator iterenemigos;
    vector<Aliadas*>::const_iterator iteraliados;
    int counter1;
    int counter2;
    int counter3;
public:
    ~Controller(){};
    void incluir(Aliadas* unidad);
    void incluirenemigos(Enemigos* unidad);
    void move_all();
    void enemove();
    void projdraw(sf::RenderWindow* window);
    void mouse_all(sf::Time deltaTime, sf::Vector2f mousePos);
    void draw_all(sf::RenderWindow* window);
    void boolUp(bool isPressed);
    void booleneUp(bool isPressed);
    void boolDown(bool isPressed);
    void booleneDown(bool isPressed);
    void boolRight(bool isPressed);
    void booleneRight(bool isPressed);
    void boolLeft(bool isPressed);
    void booleneLeft(bool isPressed);
    void boolmouse(bool isPressed);
    void detectar();
    void atk_all();
    void eneatk();
    void checkcolisiones();
};

#endif //RTSGAME_CONTROLADOR_H
