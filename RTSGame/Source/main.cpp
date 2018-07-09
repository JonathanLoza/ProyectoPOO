#include <iostream>
#include "../Include/Controlador.h"
#include "Datos.cpp"
#include "../Include/Game.h"

int main() {
    Controller controlador;

    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));

    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    cachimbo_velocidad=7;
    controlador.incluir(new Cachimbo(cachimbo_vida,cachimbo_atk,cachimbo_def,cachimbo_rango,cachimbo_velocidad));
    Game game;
    game.run();
    return 0;
}