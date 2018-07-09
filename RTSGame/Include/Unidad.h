
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
static auto dist2 = std::uniform_real_distribution<>{-200, 300};
static auto dist3 = std::uniform_real_distribution<>{0, 2300};
static auto dist4 = std::uniform_real_distribution<>{600, 2000};
static auto dist5 = std::uniform_real_distribution<>{0, 10};

class Unidad{
protected:
    int atk;
    int def;
    int rango;
    float velocidadmapa=400;
    float velocidad;
public:
    Unidad(int vida, int atk, int rango, int def, float velocidad): vida(vida), atk(atk), def(def),rango(rango),velocidad(velocidad), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false), movingmouse(false),Up(false),Down(false),Left(false),Right(false){
    }
    int vida;
    virtual ~Unidad(){}
    int get_vida();
    int get_atk();
    int get_def();
    int get_rango();
    bool alive = true;
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
        sprite.temp.setSize(sf::Vector2f(32, 32));
    }
    void atacar()override;
    void moverMouse(sf::Time deltaTime,sf::Vector2f mousePos);
    void updateprojectile(sf::RenderWindow *window);
};


class Prota: public Aliadas{
public:
    Prota(int vida, int atk, int def, int rango, float velocidad):Aliadas(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/spriteWalk.png");
        sprite.sprite.setTexture(mTexture);
        sprite.rect.setSize(sf::Vector2f(32, 32));
        sprite.sprite.setPosition(dist(gen), dist(gen));
        sprite.sprite.setTextureRect(sf::IntRect(0,0,32,32));
        projectile1.rect.setFillColor(sf::Color::White);
        projectile1.lifeTime=rango;
        projectile1.attackDamage=this->atk;
    }
};

class Cachimbo: public Aliadas{
public:
    Cachimbo(int vida, int atk, int def, int rango, float velocidad):Aliadas(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/character.png");
        sprite.sprite.setTexture(mTexture);
        sprite.rect.setSize(sf::Vector2f(32, 32));
        sprite.sprite.setPosition(dist(gen), dist(gen));
        sprite.sprite.setTextureRect(sf::IntRect(0,0,32,32));
        projectile1.rect.setFillColor(sf::Color::Cyan);
        projectile1.lifeTime=rango;
        projectile1.attackDamage=this->atk;

    }
};

class Mentor: public Aliadas{
public:
    Mentor(int vida, int atk, int def, int rango, float velocidad):Aliadas(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/player.png");
        sprite.sprite.setTexture(mTexture);
        sprite.rect.setSize(sf::Vector2f(32, 32));
        sprite.sprite.setPosition(dist(gen), dist(gen));
        sprite.sprite.setTextureRect(sf::IntRect(0,0,32,32));
        projectile1.rect.setFillColor(sf::Color::Red);
        projectile1.lifeTime=rango;
        projectile1.attackDamage=this->atk;

    }
};
class Enemigos: public Unidad{
public:
    vector<projectile>::const_iterator iter;
    vector<projectile> projectileAr;
    projectile projectile1;
    int counter = 0;
    int movementLength = 100;
    bool atkrandom=false;
    sf::Vector2f velocity;
    Enemigos(int vida, int atk, int def, int rango, float velocidad):Unidad(vida,atk,def,rango,velocidad){
        sprite.temp.setSize(sf::Vector2f(64, 64));
    }
    void atacar()override;
    void updateprojectile(sf::RenderWindow *window);
    void moverene(sf::Time deltaTime);
    void moverrandom();

};
class Profesor: public Enemigos{
public:
    Profesor(int vida, int atk, int def, int rango, float velocidad):Enemigos(vida,atk,def,rango, velocidad){
        mTexture.loadFromFile("../Media/profesorsprite.png");
        sprite.sprite.setTexture(mTexture);
        sprite.rect.setSize(sf::Vector2f(32, 32));
        sprite.sprite.setPosition(dist3(gen), dist4(gen));
        sprite.sprite.setTextureRect(sf::IntRect(0,0,64,64));
        projectile1.rect.setFillColor(sf::Color::Cyan);
        projectile1.efe.setFillColor(sf::Color::White);
        projectile1.lifeTime=rango;
        projectile1.attackDamage=atk;
        this->velocity.x = 10;
        this->velocity.y = 10;
    }
};

class TA: public Enemigos{
public:
    TA(int vida, int atk, int def, int rango, float velocidad):Enemigos(vida,atk,def,rango, velocidad){}
};


#endif //PROYECTOPOO_UNIDAD_H
