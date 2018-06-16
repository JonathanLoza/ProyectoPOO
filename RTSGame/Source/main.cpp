#include <iostream>
#include "../Include/Controlador.h"
#include "../Include/Datos.h"

int main() {
    Controller controlador;

    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    controlador.move_all();

    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    cachimbo_velocidad=7;
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    controlador.move_all();
    return 0;
}