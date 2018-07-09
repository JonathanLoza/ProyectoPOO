#include "../Include/Game.h"
#include "unistd.h"
inline void delay(unsigned long ms){
    usleep(static_cast<__useconds_t >(ms*1000));
}

Game::Game():mWindow(sf::VideoMode(1400, 1200), "SFML Application"),map(){
    mWindow.setFramerateLimit(120);
}

void Game::run()
{
    song.openFromFile("../Media/Dominator.wav");
    song.setLoop(true);
    song.play();
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            sf::Vector2f mousePos=sf::Vector2f(sf::Mouse::getPosition(mWindow));
            update(TimePerFrame);
        }
        render();
    }
}
//Booleano para movimiento por mouse
void Game::handleMouseInput( bool isPressed) {
        //map.c.movingmouse = isPressed;
        map.controlador.boolmouse(isPressed);
}
//Boleanos para el movimiento de todas las unidades
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Up ){
        //map.p.sprite.direccion=1;
        //map.p.mIsMovingUp = isPressed;
        map.controlador.booleneUp(isPressed);
        //map.p.Up = isPressed;

    }
    else if (key == sf::Keyboard::Down){
        //map.p.mIsMovingDown = isPressed;
        map.controlador.booleneDown(isPressed);
        //map.p.Down = isPressed;
        //map.p.sprite.direccion=2;
    }
    else if (key == sf::Keyboard::Left){
        //map.p.mIsMovingLeft = isPressed;
        map.controlador.booleneLeft(isPressed);
        //map.p.Left = isPressed;
        //map.p.sprite.direccion=3;
    }
    else if (key == sf::Keyboard::Right ){
        map.controlador.booleneRight(isPressed);
        //map.p.mIsMovingRight = isPressed;
       // map.p.Right = isPressed;
        //map.p.sprite.direccion=4;
    }
    if (key == sf::Keyboard:: S ){
        map.mIsMovingDown = isPressed;
        map.pre.mIsMovingUp = isPressed;
        map.controlador.boolUp(isPressed);
        map.choza.mIsMovingUp= isPressed;
    }
    else if (key == sf::Keyboard::A){
        map.mIsMovingLeft = isPressed;
        map.pre.mIsMovingRight = isPressed;
        map.controlador.boolRight(isPressed);
        map.choza.mIsMovingRight= isPressed;
    }
    else if (key == sf::Keyboard::D ){
        map.mIsMovingRight = isPressed;
        map.pre.mIsMovingLeft = isPressed;
        map.controlador.boolLeft(isPressed);
        map.choza.mIsMovingLeft= isPressed;
    }
    else if (key == sf::Keyboard::W ){
        map.mIsMovingUp = isPressed;
        map.pre.mIsMovingDown = isPressed;
        map.controlador.boolDown(isPressed);
        map.choza.mIsMovingDown= isPressed;
    }

    if (map.altura <= 0) { // con el techo 0
        map.mIsMovingUp=false;
        map.pre.mIsMovingDown = false;
        map.controlador.boolDown(false);
        map.choza.mIsMovingDown= false;

    }
    if (map.altura >= 80600){ // con el suelo 80600
        map.mIsMovingDown = false;
        map.pre.mIsMovingUp = false;
        map.controlador.boolUp(false);
        map.choza.mIsMovingUp= false;

    }
    if (map.ancho <= 0){ // con la izquierda 0
        map.mIsMovingLeft = false;
        map.pre.mIsMovingRight = false;
        map.controlador.boolRight(false);
        map.choza.mIsMovingRight= false;
    }
    if (map.ancho >= 80000){ // con la derecha 88600
        map.mIsMovingRight = false;
        map.pre.mIsMovingLeft = false;
        map.controlador.boolLeft(false);
        map.choza.mIsMovingLeft= false;
    }
}

//Eventos
void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch (event.type)
        { case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                    map.controlador.atk_all();
                    delay(5);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                    map.controlador.eneatk();
                    delay(5);
                }
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                if(event.key.code==sf::Keyboard::Space)
                    handleMouseInput(false);
                else
                    handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::MouseButtonPressed:
            {
                if (event.mouseButton.button == sf::Mouse::Right){
                    mousePos = sf::Vector2f(event.mouseButton.x,event.mouseButton.y);
                    handleMouseInput(true);
                }
                if (event.mouseButton.button == sf::Mouse::Left){
                    mousePos = sf::Vector2f(event.mouseButton.x,event.mouseButton.y);
                    map.crear(mousePos);

                }
                break;
            }
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

//update del juego
void Game::update(sf::Time deltaTime)
{
    //map.controlador.detectar();
    //map.controlador.eneatk();
    map.controlador.checkcolisiones();
    map.controlador.checkdeads();
    map.controlador.randomenem();
    map.controlador.mouse_all(TimePerFrame,mousePos);
    map.controlador.move_all();
    map.controlador.enemove();
    map.mover(deltaTime);
    //map.p.moverene(deltaTime);
    map.pre.mover(deltaTime);
    map.choza.mover(deltaTime);

}
//Render del juego
void Game::render() {
    mWindow.clear();
    mWindow.draw(map.mMap);
    mWindow.draw(map.choza.mChoza);
    mWindow.draw(map.pre.mChoza);
    map.controlador.draw_all(&mWindow);
    map.controlador.projdraw(&mWindow);
    //map.p.updateprojectile(&mWindow);
    mWindow.display();
}

