#include <stdlib.h>
#include "CPowerUp.h"
#include "glut.h"
#include "Shapes.h"

void CPowerUp::draw() {
	face(30, 60, xpos, ypos, 1, 1, 0);
}

Rectangle CPowerUp::getRectangle() {
	Rectangle result;
	result.top = ypos + 60;
	result.bottom = ypos - 60;
	result.left = xpos - 30;
	result.right = xpos + 30;
	return result;
}

