
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

Bomb::Bomb(const Bomb& pBomb)
{
    this->speed = pBomb.speed;
    this->xDirction = pBomb.xDirction;
    this->yDirection = pBomb.yDirection;
    this->width = pBomb.width;
    this->x = pBomb.x;
    this->y = pBomb.y;
}

Bomb* Bomb::clone()
{
    return new Bomb(*this);
}