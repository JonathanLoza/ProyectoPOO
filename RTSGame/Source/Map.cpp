#include "../Include/Map.h"


Map::Map(): c(10,10,10,10,10),p(10,10,10,10,10),choza(100), mIsMovingUp(false), mIsMovingDown(false), mIsMovingRight(false), mIsMovingLeft(false) {
    mTexture.loadFromFile("../Media/Desert.png");
    mMap.setTexture(mTexture);
    mMap.setPosition(0.f, 0.f);
    mMap.setScale(5,5);

}
