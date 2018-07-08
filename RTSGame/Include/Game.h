
#define RTSGAME_GAME_H

#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Map.h"

class Game{
private:
    sf::Music song;
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void handleMouseInput( bool isPressed);
public:
    Game();
    void run();
private:
    static const float PlayerSpeed;
    sf::RenderWindow mWindow;
    Map map;
};

static sf::Vector2f mousePos;
const sf::Time TimePerFrame = sf::seconds(1.f/60.f);