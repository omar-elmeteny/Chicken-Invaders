#include "CHeart.h"
#include "glut.h"
#include "Shapes.h"

void CHeart::draw() {
	semicircle(rx, ry, xc-rx, yc, r, g, b);
	semicircle(rx, ry, xc+rx, yc, r, g, b);
	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex3f(xc - 2 * rx, yc, 0);
		glVertex3f(xc, yc - 3 * ry, 0);
		glVertex3f(xc + 2 * rx, yc, 0);
	glEnd();
}

Rectangle CHeart::getRectangle() {
	Rectangle result;
	result.top = yc + ry;
	result.bottom = yc - 3 * ry;
	result.left = xc - 2 * rx;
	result.right = xc + 2 * rx;
	return result;
}
