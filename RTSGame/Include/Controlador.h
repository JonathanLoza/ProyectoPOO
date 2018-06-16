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
    void atk_all();
};

#endif //RTSGAME_CONTROLADOR_H
