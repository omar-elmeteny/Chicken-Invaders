#include <stdlib.h>
#include "CHealthBar.h"
#include "CHeart.h"
#include "glut.h"
#include "Shapes.h"

void CHealthBar::draw() {
	glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(-350, 1490, 0);
		glVertex3f(-350 + width, 1490, 0);
		glVertex3f(-350 + width, 1440, 0);
		glVertex3f(-350, 1440, 0);
	glEnd();
}

Rectangle CHealthBar::getRectangle() {
	Rectangle result;
	result.top = 1490;
	result.bottom = 1440;
	result.left = -350;
	result.right = -350 + width;
	return result;
}