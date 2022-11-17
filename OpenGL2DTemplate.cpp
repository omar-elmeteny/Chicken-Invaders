#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

using namespace std;

float xr = 0;
float yr = 0;

float ypos = 0;
int state = 1;

void ellipse(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	float r = glfwGetTime();

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0.29, 0.27, 0.35, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_QUAD_STRIP);
	float n = 0;
	while (dx < dy) {

		if (n > 20) {
			glVertex3f(x + xc + xr, y + yc + yr, 0);
			glVertex3f(-x + xc + xr, y + yc + yr, 0);
			glVertex3f(x + xc + xr, -y + yc + yr, 0);
			glVertex3f(-x + xc + xr, -y + yc + yr, 0);
		}

		if (d1 < 0) {
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
		n++;
	}
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
	n = 0;
	while (y >= 0) {
		if (n > 20) {
			glVertex3f(x + xc + xr, y + yc + yr, 0);
			glVertex3f(-x + xc + xr, y + yc + yr, 0);
			glVertex3f(x + xc + xr, -y + yc + yr, 0);
			glVertex3f(-x + xc + xr, -y + yc + yr, 0);
		}

		if (d2 > 0) {
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (ry * ry);
		}
		n++;
	}
	glEnd();
}


void bullet(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0.29, 0.27, 0.35, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_QUAD_STRIP);
	float n = 0;
	while (dx < dy) {

		glVertex3f(x + xc + xr, ypos + y + yc + yr, 0);
		glVertex3f(-x + xc + xr, ypos + y + yc + yr, 0);
		if (n > 20) {
			glVertex3f(x + xc + xr, ypos - y + yc + yr, 0);
			glVertex3f(-x + xc + xr, ypos - y + yc + yr, 0);
		}

		if (d1 < 0) {
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
		n++;
	}
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
	n = 0;
	while (y >= 0) {

		glVertex3f(x + xc + xr, ypos + y + yc + yr, 0);
		glVertex3f(-x + xc + xr, ypos + y + yc + yr, 0);
		if (n > 20) {
			glVertex3f(x + xc + xr, ypos - y + yc + yr, 0);
			glVertex3f(-x + xc + xr, ypos - y + yc + yr, 0);
		}

		if (d2 > 0) {
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (ry * ry);
		}
		n++;
	}
	glEnd();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);

	ypos = ypos + 40;

}


void circle(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0.29, 0.27, 0.35, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_POINTS);
	while (dx < dy) {

		glVertex3f(x + xc + xr, y + yc + yr, 0);
		glVertex3f(-x + xc + xr, y + yc + yr, 0);
		glVertex3f(x + xc + xr, -y + yc + yr, 0);
		glVertex3f(-x + xc + xr, -y + yc + yr, 0);

		if (d1 < 0) {
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
	while (y >= 0) {

		glVertex3f(x + xc + xr, y + yc + yr, 0);
		glVertex3f(-x + xc + xr, y + yc + yr, 0);
		glVertex3f(x + xc + xr, -y + yc + yr, 0);
		glVertex3f(-x + xc + xr, -y + yc + yr, 0);

		if (d2 > 0) {
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (ry * ry);
		}
	}
	glEnd();
}



void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(73 + xr, 190 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(100 + xr, 250 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(127 + xr, 190 + yr, 0);
	glEnd();

	ellipse(40, 120, 100, 100, 0.26, 0.87, 0.85);
	bullet(10, 40, 100, 275, 1, 0.84, 0);

	circle(20, 30, 100, 120, 0, 0, 0);
	circle(10, 15, 100, 120, 0, 0, 0);



	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(85 + xr, 10 + yr, 0);
	glColor3f(1, 1, 0);
	glVertex3f(95 + xr, -60 + yr, 0);
	glColor3f(1, 1, 0);
	glVertex3f(105 + xr, -60 + yr, 0);
	glColor3f(1, 1, 0);
	glVertex3f(115 + xr, 10 + yr, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(63 + xr, 60 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(40 + xr, 35 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(40 + xr, 5 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(65 + xr, 30 + yr, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(137 + xr, 60 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(160 + xr, 35 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(160 + xr, 5 + yr, 0);
	glColor3f(1, 0, 0);
	glVertex3f(135 + xr, 30 + yr, 0);
	glEnd();

	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void specialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		yr = yr + 15;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		yr = yr - 15;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		xr = xr - 15;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		xr = xr + 15;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(250, 150);

	glutCreateWindow("Chicken invaders");
	glutDisplayFunc(Display);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
	gluOrtho2D(-560, 750, -100, 1500);

	glutSpecialFunc(specialKey);
	glutTimerFunc(0, timer, 0);

	glutMainLoop();


	return 0;
}
