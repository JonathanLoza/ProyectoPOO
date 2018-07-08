
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
    Unidad(int vida, int atk, int rango, int def, int velocidad): vida(vida), atk(atk), def(def),rango(rango),velocidad(velocidad), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false), movingmouse(false){}
    virtual ~Unidad(){}
    int get_vida();
    int get_atk();
    int get_def();
    int get_rango();
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
    bool movingmouse;
    sf::Texture mTexture;
    sf::Sprite mSprite;
    void mover(sf::Time deltaTime);
    virtual  void atacar()=0;
};

class Aliadas: public Unidad{
public:
    Aliadas(int vida, int atk, int def, int rango, int velocidad):Unidad(vida,atk,def,rango, velocidad){}
    void atacar()override;
    void moverMouse(sf::Time deltaTime,sf::Vector2f mousePos);
};

class Enemigos: public Unidad{
public:
    Enemigos(int vida, int atk, int def, int rango, int velocidad):Unidad(vida,atk,def,rango,velocidad){}
    void atacar()override;
};

class Cachimbo: public Aliadas{
public:
    Cachimbo(int vida, int atk, int def, int rango, int velocidad):Aliadas(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/Hyde.png");
        mSprite.setTexture(mTexture);
        mSprite.setOrigin(sf::Vector2f(mTexture.getSize().x*0.5,mTexture.getSize().y*0.5));
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
    Profesor(int vida, int atk, int def, int rango, int velocidad):Enemigos(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/profe.png");
        mSprite.setTexture(mTexture);
        mSprite.setOrigin(sf::Vector2f(mTexture.getSize().x*0.5,mTexture.getSize().y*0.5));
        mSprite.setPosition(120.f, 120.f);
        mSprite.setScale(0.3,0.3);
    }
};

class TA: public Enemigos{
public:
    TA(int vida, int atk, int def, int rango, int velocidad):Enemigos(vida,atk,def,rango, velocidad){}
};


#endif //PROYECTOPOO_UNIDAD_H
