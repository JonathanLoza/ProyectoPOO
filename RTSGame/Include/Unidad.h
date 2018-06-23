
#ifndef PROYECTOPOO_UNIDAD_H
#define PROYECTOPOO_UNIDAD_H

#include <SFML/Graphics.hpp>
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
    sf::Texture mTexture;
    sf::Sprite mSprite;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
public:
    Cachimbo(int vida, int atk, int def, int rango, int velocidad):Aliadas(vida,atk,def,rango, velocidad), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false){
        mTexture.loadFromFile("/home/jonathan/ProyectoPOO/RTSGame/Media/Hyde.png");
        mSprite.setTexture(mTexture);
        mSprite.setPosition(100.f, 100.f);
        mSprite.setScale(0.1,0.1);

    }
};

class Mentor: public Aliadas{
public:
    Mentor(int vida, int atk, int def, int rango, int velocidad):Aliadas(vida,atk,def,rango, velocidad){}
};

class Profesor: public Enemigos{
public:
    sf::Texture mTexture;
    sf::Sprite mProfe;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
public:
    Profesor(int vida, int atk, int def, int rango, int velocidad):Enemigos(vida,atk,def,rango, velocidad), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false){
        mTexture.loadFromFile("/home/jonathan/ProyectoPOO/RTSGame/Media/profe.png");
        mProfe.setTexture(mTexture);
        mProfe.setPosition(1200.f, 1200.f);
        mProfe.setScale(0.3,0.3);
    }
};

class TA: public Enemigos{
public:
    TA(int vida, int atk, int def, int rango, int velocidad):Enemigos(vida,atk,def,rango, velocidad){}
};


#endif //PROYECTOPOO_UNIDAD_H
