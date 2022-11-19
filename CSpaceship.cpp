#include "glut.h"
#include "CSpaceship.h"
#include "Shapes.h"
void CSpaceship::draw() {

	if (hasPowerUp) {
		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 1);
		glVertex3f(73 + xpos, 190 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(100 + xpos, 250 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(127 + xpos, 190 + ypos, 0);
		glEnd();

		ellipse(40, 120, 100 + xpos, 100 + ypos, 1-0.26, 1-0.87, 1-0.85);


		circle(20, 30, 100 + xpos, 120 + ypos, 1, 1, 1);
		circle(10, 15, 100 + xpos, 120 + ypos, 1, 1, 1);



		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex3f(85 + xpos, 10 + ypos, 0);
		glColor3f(1, 1, 0);
		glVertex3f(95 + xpos, -60 + ypos, 0);
		glColor3f(1, 1, 0);
		glVertex3f(105 + xpos, -60 + ypos, 0);
		glColor3f(1, 1, 0);
		glVertex3f(115 + xpos, 10 + ypos, 0);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 1, 1);
		glVertex3f(63 + xpos, 60 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(40 + xpos, 35 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(40 + xpos, 5 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(65 + xpos, 30 + ypos, 0);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 1, 1);
		glVertex3f(137 + xpos, 60 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(160 + xpos, 35 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(160 + xpos, 5 + ypos, 0);
		glColor3f(0, 1, 1);
		glVertex3f(135 + xpos, 30 + ypos, 0);
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex3f(73 + xpos, 190 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(100 + xpos, 250 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(127 + xpos, 190 + ypos, 0);
		glEnd();

		ellipse(40, 120, 100 + xpos, 100 + ypos, 0.26, 0.87, 0.85);


		circle(20, 30, 100 + xpos, 120 + ypos, 0, 0, 0);
		circle(10, 15, 100 + xpos, 120 + ypos, 0, 0, 0);



		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex3f(85 + xpos, 10 + ypos, 0);
		glColor3f(1, 1, 0);
		glVertex3f(95 + xpos, -60 + ypos, 0);
		glColor3f(1, 1, 0);
		glVertex3f(105 + xpos, -60 + ypos, 0);
		glColor3f(1, 1, 0);
		glVertex3f(115 + xpos, 10 + ypos, 0);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(63 + xpos, 60 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(40 + xpos, 35 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(40 + xpos, 5 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(65 + xpos, 30 + ypos, 0);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(137 + xpos, 60 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(160 + xpos, 35 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(160 + xpos, 5 + ypos, 0);
		glColor3f(1, 0, 0);
		glVertex3f(135 + xpos, 30 + ypos, 0);
		glEnd();
	}
}


Rectangle CSpaceship::getRectangle() {
	Rectangle result;
	result.top = 250 + ypos;
	result.bottom = -60 + ypos;
	result.left = 40 + xpos;
	result.right = 160 + xpos;
	return result;
}