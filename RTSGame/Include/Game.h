
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
public:
    Game();
    void run();
private:
    static const float		PlayerSpeed;
    static const sf::Time	TimePerFrame;
    sf::RenderWindow mWindow;
    Map map;
};

