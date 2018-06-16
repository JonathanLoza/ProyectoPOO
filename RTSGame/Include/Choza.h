#ifndef RTSGAME_CHOZA_H
#define RTSGAME_CHOZA_H

#include "Unidad.h"

class Estructura{
    int vida;
public:
    Estructura(int vida):vida(vida){}
    virtual ~Estructura(){}
};
class Pre:public Estructura{
    int preciochachimbo;
    int preciomentor;
public:
    Pre(int vida, int preciocachimbo, int preciomentor): Estructura(vida),preciochachimbo(preciocachimbo),preciomentor(preciomentor){}
    void crear();
};

class Cubiculo:public Estructura{
    int precio_vc;
    int precio_ac;
    int precio_dc;
    int precio_rc;
    int precio_vec;
    int precio_uc;
    int precio_vm;
    int precio_am;
    int precio_dm;
    int precio_rm;
    int precio_vem;
    int precio_um;
public:
    Cubiculo(int vida):Estructura(vida){}
    void update_vida_cachimbo(int x);
    void update_atk_cachimbo(int x);
    void update_def_cachimbo(int x);
    void update_rango_cachimbo(int x);
    void update_velocidad_cachimbo(int x);
    void update_cachimbo(int x);
    void update_vida_mentor(int x);
    void update_atk_mentor(int x);
    void update_def_mentor(int x);
    void update_rango_mentor(int x);
    void update_velocidad_mentor(int x);
    void update_mentor(int x);


};
#endif //RTSGAME_CHOZA_H
