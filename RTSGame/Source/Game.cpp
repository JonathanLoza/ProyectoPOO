#include "../Include/Game.h"
//#include "../Include/Datos.h"

sf::Vector2f mousePos;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game():mWindow(sf::VideoMode(1400, 1200), "SFML Application"),map(){

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
void Game::handleMouseInput(sf::Keyboard::Key key, bool isPressed) {
        map.c.movingmouse = isPressed;
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W )
        map.c.mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S )
        map.c.mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A )
        map.c.mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D )
        map.c.mIsMovingRight = isPressed;
    else if (key == sf::Keyboard:: Down ){
        map.mIsMovingDown = isPressed;
        map.c.mIsMovingUp = isPressed;
        map.p.mIsMovingUp = isPressed;
        map.choza.mIsMovingUp= isPressed;
    }
    else if (key == sf::Keyboard::Left){
        map.mIsMovingLeft = isPressed;
        map.c.mIsMovingRight = isPressed;
        map.p.mIsMovingRight = isPressed;
        map.choza.mIsMovingRight= isPressed;
    }
    else if (key == sf::Keyboard::Right ){
        map.mIsMovingRight = isPressed;
        map.c.mIsMovingLeft = isPressed;
        map.p.mIsMovingLeft = isPressed;
        map.choza.mIsMovingLeft= isPressed;
    }
    else if (key == sf::Keyboard::Up ){
        map.mIsMovingUp = isPressed;
        map.c.mIsMovingDown = isPressed;
        map.p.mIsMovingDown = isPressed;
        map.choza.mIsMovingDown= isPressed;
    }

    if (map.altura <= 0) { // con el techo 0
        map.mIsMovingUp=false;
        map.c.mIsMovingDown = false;
        map.p.mIsMovingDown = false;
        map.choza.mIsMovingDown= false;

    }
    if (map.altura >= 80600){ // con el suelo 80600
        map.mIsMovingDown = false;
        map.c.mIsMovingUp = false;
        map.p.mIsMovingUp = false;
        map.choza.mIsMovingUp= false;

    }
    if (map.ancho <= 0){ // con la izquierda 0
        map.mIsMovingLeft = false;
        map.c.mIsMovingRight = false;
        map.p.mIsMovingRight =false;
        map.choza.mIsMovingRight= false;
    }
    if (map.ancho >= 88600){ // con la derecha 88600
        map.mIsMovingRight = false;
        map.c.mIsMovingLeft = false;
        map.p.mIsMovingLeft =false;
        map.choza.mIsMovingLeft= false;
    }
}

void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch (event.type)
        { case sf::Event::KeyPressed:handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                if(event.key.code==sf::Keyboard::T)
                    handleMouseInput(event.key.code,false);
                else
                    handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::MouseButtonPressed:
            {
                mousePos = sf::Vector2f(event.mouseButton.x,event.mouseButton.y);
                if (event.mouseButton.button == sf::Mouse::Right)
                    handleMouseInput(event.key.code,true);

                break;
            }
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{

    map.c.moverMouse(TimePerFrame,mousePos);
    map.c.mover(deltaTime);
    map.mover(deltaTime);
    map.p.mover(deltaTime);
    map.choza.mover(deltaTime);



}
void Game::render() {
    mWindow.clear();
    mWindow.draw(map.mMap);
    mWindow.draw(map.choza.mChoza);
    mWindow.draw(map.p.mSprite);
    mWindow.draw(map.c.mSprite);
    mWindow.display();
}

