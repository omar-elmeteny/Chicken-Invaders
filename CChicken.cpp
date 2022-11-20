#include <stdlib.h>
#include "CChicken.h"
#include "glut.h"
#include "Shapes.h"

void CChicken::draw() {

	face(30, 60, 105 + xpos, 1400 + ypos, 1, 1, 1);

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(85 + xpos, 1350 + ypos, 0);
	glColor3f(1, 0, 0);
	glVertex3f(40 + xpos, 1200 + ypos, 0);
	glColor3f(1, 0, 0);
	glVertex3f(170 + xpos, 1200 + ypos, 0);
	glColor3f(1, 0, 0);
	glVertex3f(125 + xpos, 1350 + ypos, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(100 + xpos, 1460 + ypos, 0);
	glColor3f(1, 0, 0);
	glVertex3f(105 + xpos, 1490 + ypos, 0);
	glColor3f(1, 0, 0);
	glVertex3f(110 + xpos, 1460 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(55 + xpos, 1200 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(155 + xpos, 1200 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(145 + xpos, 1170 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(65 + xpos, 1170 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.64, 0);
	glVertex3f(75 + xpos, 1170 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(90 + xpos, 1170 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(90 + xpos, 1120 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(75 + xpos, 1120 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.64, 0);
	glVertex3f(75 + xpos, 1140 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(55 + xpos, 1140 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(55 + xpos, 1120 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(75 + xpos, 1120 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.64, 0);
	glVertex3f(135 + xpos, 1170 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(120 + xpos, 1170 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(120 + xpos, 1120 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(135 + xpos, 1120 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0.64, 0);
	glVertex3f(135 + xpos, 1140 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(155 + xpos, 1140 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(155 + xpos, 1120 + ypos, 0);
	glColor3f(1, 0.64, 0);
	glVertex3f(135 + xpos, 1120 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(77 + xpos, 1325 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(47 + xpos, 1225 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(20 + xpos, 1210 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(10 + xpos, 1340 + ypos, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(133 + xpos, 1325 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(163 + xpos, 1225 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(190 + xpos, 1210 + ypos, 0);
	glColor3f(1, 1, 1);
	glVertex3f(200 + xpos, 1340 + ypos, 0);
	glEnd();
}


Rectangle CChicken::getRectangle() {
	Rectangle result;
	result.top = 1490 + ypos;
	result.bottom = 1120 + ypos;
	result.left = 10 + xpos;
	result.right = 200 + xpos;
	return result;
}

