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


void Unidad::mover(sf::Time deltaTime) {
    sf::Vector2f movementP(0.f, 0.f);
    if (mIsMovingUp)
        movementP.y -= velocidadmapa;
    if (mIsMovingDown)
        movementP.y += velocidadmapa;
    if (mIsMovingLeft)
        movementP.x -= velocidadmapa;
    if (mIsMovingRight)
        movementP.x += velocidadmapa;
    sprite.sprite.move(movementP * deltaTime.asSeconds());

}

void Unidad::draw(sf::RenderWindow *window) {
    window->draw(sprite.sprite);
}

void Unidad::handleMouseInput( bool isPressed,sf::Vector2f mousePos){
    sf::FloatRect mouse(mousePos,{70,70});
    sf::Vector2i alemouse=sf::Vector2i(mousePos);
    sf::Vector2i posi=sf::Vector2i(sprite.sprite.getPosition());

    //
    if(posi.x==alemouse.x && posi.y>alemouse.y ){
        Left=false;
        Right=false;
        Up=isPressed;
        Down=false;

    }
    else if(posi.x<alemouse.x && posi.y>alemouse.y ){
        Left=false;
        Right=isPressed;
        Up=isPressed;
        Down=false;
    }
    else if(posi.x<alemouse.x && posi.y==alemouse.y ){
        Left=false;
        Right=isPressed;
        Up=false;
        Down=false;

    }
    else if(posi.x<alemouse.x && posi.y<alemouse.y ){
        Left=false;
        Right=isPressed;
        Up=false;
        Down=isPressed;
    }
    else if(posi.x==alemouse.x && posi.y<alemouse.y ){
        Left=false;
        Right=false;
        Up=false;
        Down=isPressed;

    }
    else if(posi.x>alemouse.x && posi.y<alemouse.y ){
        Left=isPressed;
        Right=false;
        Up=false;
        Down=isPressed;
    }
    else if(posi.x>alemouse.x && posi.y==alemouse.y ){
        Left=isPressed;
        Right=false;
        Up=false;
        Down=false;

    }
    else if(posi.x>alemouse.x && posi.y>alemouse.y ){
        Left=isPressed;
        Right=false;
        Up=isPressed;
        Down=false;
    }
}

void Aliadas::moverMouse(sf::Time deltaTime, sf::Vector2f mousePos) {

    sf::FloatRect mouse(mousePos,{40,40});
    sf::Vector2f ale=mousePos;
    ale.x+=dist2(gen);
    ale.y+=dist2(gen);

    sf::Vector2f posi=sprite.sprite.getPosition();
    if(movingmouse){
        handleMouseInput(true,mousePos);
        if (Up)
        {   sprite.direccion=1;
            sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 32, 32 * 3, 32, 32));
        }
        if (Down)
        {
            sprite.direccion=2;
            sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 32, 0, 32, 32));

        }
        if(Left)
        {
            sprite.direccion=3;
            sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 32, 32 * 1, 32, 32));

        }
        if (Right)
        {
            sprite.direccion=4;
            sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 32, 32 * 2, 32, 32));

        }
        sprite.sprite.move((ale - posi)*deltaTime.asSeconds());
        sprite.counterWalking++;

        if (sprite.counterWalking == 2)
        {
            sprite.counterWalking = 0;
        }
    }
    sprite.rect.setPosition(sprite.sprite.getPosition());
}

void Aliadas::updateprojectile(sf::RenderWindow *window) {
    projectile1.counter = 0;
    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
    {
        if (projectileArray[projectile1.counter].destroy == true)
        {
            projectileArray.erase(iter);
            break;
        }

        projectile1.counter++;
    }
    projectile1.counter = 0;

    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
    {
        projectileArray[projectile1.counter].update();
        window->draw(projectileArray[projectile1.counter].rect);
        projectile1.counter++;

    }
}
void Aliadas::atacar() {
    projectile1.rect.setPosition(sprite.sprite.getPosition().x+sprite.sprite.getGlobalBounds().width/2-projectile1.rect.getSize().x/2,
                                 sprite.sprite.getPosition().y+sprite.sprite.getGlobalBounds().height/2-projectile1.rect.getSize().y/2);
    projectile1.direction = sprite.direccion;
    projectileArray.push_back(projectile1);
}

void Enemigos::atacar() {
    projectile1.efe.setPosition(sprite.sprite.getPosition().x+sprite.sprite.getGlobalBounds().width/2-projectile1.efe.getRadius(),
                                 sprite.sprite.getPosition().y+sprite.sprite.getGlobalBounds().height/2-projectile1.efe.getRadius());
    projectile1.direction = sprite.direccion;
    projectileAr.push_back(projectile1);
}

void Enemigos::updateprojectile(sf::RenderWindow *window) {
    projectile1.counter = 0;
    for (iter = projectileAr.begin(); iter != projectileAr.end(); iter++)
    {
        if (projectileAr[projectile1.counter].destroy == true)
        {
            projectileAr.erase(iter);
            break;
        }

        projectile1.counter++;
    }
    projectile1.counter = 0;
    for (iter = projectileAr.begin(); iter != projectileAr.end(); iter++)
    {
        projectileAr[projectile1.counter].update();
        window->draw(projectileAr[projectile1.counter].efe);
        projectile1.counter++;

    }
}

void Enemigos::moverene(sf::Time deltaTime) {
    sf::Vector2f movementP(0.f, 0.f);
    if (Up)
    {   sprite.direccion=1;
        movementP.y -= velocidad;
        sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 64, 64 * 3, 64, 64));
    }
    if (Down)
    {
        sprite.direccion=2;
        movementP.y += velocidad;
        sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 64, 0, 64, 64));

    }
    if(Left)
    {
        movementP.x -= velocidad;
        sprite.direccion=3;
        sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 64, 64* 1, 64, 64));

    }
    if (Right)
    {
        movementP.x += velocidad;
        sprite.direccion=4;
        sprite.sprite.setTextureRect(sf::IntRect(sprite.counterWalking * 64, 64* 2, 64,64));
    }
    sprite.sprite.move(movementP * deltaTime.asSeconds());
    sprite.counterWalking++;


    if (sprite.counterWalking == 3)
    {
        sprite.counterWalking = 0;
    }
    sprite.rect.setPosition(sprite.sprite.getPosition());
}

