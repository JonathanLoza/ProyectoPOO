#include "../Include/Controlador.h"
#include <list>
using  namespace std;
void Controller::move_all() {
    for(auto unidad:unidades){
        unidad->mover();
    }
}

void Controller::atk_all() {
    for(auto unidad:unidades){
        unidad->atacar();
    }
}

void Controller::incluir(Aliadas* unidad) {
    if (dynamic_cast<Cachimbo*>(unidad) != nullptr) {
        unidades.emplace_back(unidad);
    }
    else if (dynamic_cast<Mentor*>(unidad) != nullptr) {
        unidades.emplace_back(unidad);
    }
}

