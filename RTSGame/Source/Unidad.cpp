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

void Aliadas::mover() {
    cout<<"aliada se mueve a: "<<velocidad<<" de velocidad"<<endl;
}

void Aliadas::atacar() {
    cout<<"aliada ataca"<<endl;
}

void Enemigos::mover() {
    cout<<"enemigo se mueve"<<velocidad<<" de velocidad"<<endl;
}

void Enemigos::atacar() {
    cout<<"enemigo ataca"<<endl;
}
