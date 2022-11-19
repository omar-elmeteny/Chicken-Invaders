#pragma once
#include "CGameObject.h"
class CChicken :
    public CGameObject
{
public:
    void draw();
    Rectangle getRectangle();
};

