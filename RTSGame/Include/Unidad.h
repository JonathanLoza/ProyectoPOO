
#ifndef PROYECTOPOO_UNIDAD_H
#define PROYECTOPOO_UNIDAD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#include "Sprite.h"

using namespace std;
static auto seed = std::random_device{}();
static auto gen = std::mt19937{ seed };
static auto dist = std::uniform_real_distribution<>{200, 500};
static auto dist2 = std::uniform_real_distribution<>{-700, 700};

class Unidad{
protected:
    int vida;
    int atk;
    int def;
    int rango;
    float velocidadmapa=200;
    float velocidad;
public:
    Unidad(int vida, int atk, int rango, int def, int velocidad): vida(vida), atk(atk), def(def),rango(rango),velocidad(velocidad), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false), movingmouse(false),Up(false),Down(false),Left(false),Right(false){
    }
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
    Sprite sprite;
    void mover(sf::Time deltaTime);
    virtual  void atacar()=0;
    void draw(sf::RenderWindow* window);
public:
    bool Up;
    bool Down;
    bool Left;
    bool Right;
    void handleMouseInput(bool isPressed,sf::Vector2f mousePos);

};

class Aliadas: public Unidad{
public:
    vector<projectile>::const_iterator iter;
    vector<projectile> projectileArray;
    projectile projectile1;
    Aliadas(int vida, int atk, int def, int rango, float velocidad):Unidad(vida,atk,def,rango, velocidad){
    }
    void atacar()override;
    void moverMouse(sf::Time deltaTime,sf::Vector2f mousePos);
    void updateprojectile(sf::RenderWindow *window);
};

class Enemigos: public Unidad{
public:
    Enemigos(int vida, int atk, int def, int rango, float velocidad):Unidad(vida,atk,def,rango,velocidad){}
    void atacar()override;
};

class Cachimbo: public Aliadas{
public:
    Cachimbo(int vida, int atk, int def, int rango, float velocidad):Aliadas(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/spriteWalk.png");
        sprite.sprite.setTexture(mTexture);
        sprite.rect.setSize(sf::Vector2f(32, 32));
        sprite.sprite.setPosition(dist(gen), dist(gen));
        sprite.sprite.setTextureRect(sf::IntRect(0,0,32,32));

    }
};

class Mentor: public Aliadas{
public:
    Mentor(int vida, int atk, int def, int rango, float velocidad):Aliadas(vida,atk,def,rango, velocidad){}
};

class Profesor: public Enemigos{
public:
    Profesor(int vida, int atk, int def, int rango, float velocidad):Enemigos(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/profe.png");
    }
};

class TA: public Enemigos{
public:
    TA(int vida, int atk, int def, int rango, float velocidad):Enemigos(vida,atk,def,rango, velocidad){}
};


#endif //PROYECTOPOO_UNIDAD_H
