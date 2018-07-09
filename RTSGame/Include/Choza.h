#ifndef RTSGAME_CHOZA_H
#define RTSGAME_CHOZA_H


#include "Unidad.h"

class Estructura{
    int vida;
public:
    sf::Texture mTexture;
    sf::Sprite mChoza;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;
    const float Speed = 400.f;
public:
    Estructura(int vida):vida(vida),mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false){}
    virtual ~Estructura(){}
    virtual void mover(sf::Time deltaTime)=0;
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
    Cubiculo(int vida):Estructura(vida){
        mTexture.loadFromFile("../Media/Choza.png");
        mChoza.setTexture(mTexture);
        mChoza.setPosition(80.f, 60.f);
        mChoza.setScale(3,3);
    }
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
public:
    void mover(sf::Time deltaTime) override ;

};

#endif //RTSGAME_CHOZA_H
