#pragma once
#include "CGameObject.h"
class CHealthBar :
    public CGameObject
{
public:

    int width;
    CHealthBar(int width) {
        this->width = width;
    }

    void draw();
    Rectangle getRectangle();
};

