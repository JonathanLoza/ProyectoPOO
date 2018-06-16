
#ifndef PROYECTOPOO_UNIDAD_H
#define PROYECTOPOO_UNIDAD_H

#include <iostream>
using namespace std;

class Unidad{
protected:
    int vida;
    int atk;
    int def;
    int rango;
    int velocidad;
public:
    Unidad(int vida, int atk, int rango, int def, int velocidad): vida(vida), atk(atk), def(def),rango(rango),velocidad(velocidad){}
    virtual ~Unidad(){}
    int get_vida();
    int get_atk();
    int get_def();
    int get_rango();
    virtual  void mover()=0;
    virtual  void atacar()=0;
};

class Aliadas: public Unidad{
public:
    Aliadas(int vida, int atk, int def, int rango, int velocidad):Unidad(vida,atk,def,rango, velocidad){}
    void mover() override;
    void atacar()override;
};

class Enemigos: public Unidad{
public:
    Enemigos(int vida, int atk, int def, int rango, int velocidad):Unidad(vida,atk,def,rango,velocidad){}
    void mover() override;
    void atacar()override;
};

class Cachimbo: public Aliadas{
public:
    Cachimbo(int vida, int atk, int def, int rango, int velocidad):Aliadas(vida,atk,def,rango, velocidad){}
};

class Mentor: public Aliadas{
public:
    Mentor(int vida, int atk, int def, int rango, int velocidad):Aliadas(vida,atk,def,rango, velocidad){}
};

class Profesor: public Enemigos{
public:
    Profesor(int vida, int atk, int def, int rango, int velocidad):Enemigos(vida,atk,def,rango, velocidad){}
};

class TA: public Enemigos{
public:
    TA(int vida, int atk, int def, int rango, int velocidad):Enemigos(vida,atk,def,rango, velocidad){}
};


#endif //PROYECTOPOO_UNIDAD_H
