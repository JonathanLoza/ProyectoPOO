#include "../Include/Game.h"
//#include "../Include/Datos.h"

const float Game::PlayerSpeed = 200.f;
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
            update(TimePerFrame);
        }
        render();
    }
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
}

void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch (event.type)
        { case sf::Event::KeyPressed:handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movementP(0.f, 0.f);
    sf::Vector2f movementM(0.f, 0.f);
    sf::Vector2f movementProfe(0.f, 0.f);
    sf::Vector2f movementChoza(0.f, 0.f);

    if (map.c.mIsMovingUp)
        movementP.y -= PlayerSpeed;
    if (map.c.mIsMovingDown)
        movementP.y += PlayerSpeed;
    if (map.c.mIsMovingLeft)
        movementP.x -= PlayerSpeed;
    if (map.c.mIsMovingRight)
        movementP.x += PlayerSpeed;
    if (map.p.mIsMovingUp)
        movementProfe.y -= PlayerSpeed;
    if (map.p.mIsMovingDown)
        movementProfe.y += PlayerSpeed;
    if (map.p.mIsMovingLeft)
        movementProfe.x -= PlayerSpeed;
    if (map.p.mIsMovingRight)
        movementProfe.x += PlayerSpeed;
    if (map.choza.mIsMovingUp)
        movementChoza.y -= PlayerSpeed;
    if (map.choza.mIsMovingDown)
        movementChoza.y += PlayerSpeed;
    if (map.choza.mIsMovingLeft)
        movementChoza.x -= PlayerSpeed;
    if (map.choza.mIsMovingRight)
        movementChoza.x += PlayerSpeed;
    if (map.mIsMovingUp)
        movementM.y += PlayerSpeed;
    if (map.mIsMovingDown)
        movementM.y -= PlayerSpeed;
    if (map.mIsMovingLeft)
        movementM.x += PlayerSpeed;
    if (map.mIsMovingRight)
        movementM.x -= PlayerSpeed;
    map.choza.mChoza.move(movementChoza * deltaTime.asSeconds());
    map.p.mProfe.move(movementProfe * deltaTime.asSeconds());
    map.c.mSprite.move(movementP * deltaTime.asSeconds());
    map.mMap.move(movementM * deltaTime.asSeconds());
}
void Game::render() {
    mWindow.clear();
    mWindow.draw(map.mMap);
    mWindow.draw(map.choza.mChoza);
    mWindow.draw(map.p.mProfe);
    mWindow.draw(map.c.mSprite);
    mWindow.display();
}