#include "glut.h"

void ellipse(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0, 0, 0, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_QUAD_STRIP);
	float n = 0;
	while (dx < dy) {

		if (n > 20) {
			glVertex3f(x + xc, y + yc, 0);
			glVertex3f(-x + xc, y + yc, 0);
			glVertex3f(x + xc, -y + yc, 0);
			glVertex3f(-x + xc, -y + yc, 0);
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
			glVertex3f(x + xc, y + yc, 0);
			glVertex3f(-x + xc, y + yc, 0);
			glVertex3f(x + xc, -y + yc, 0);
			glVertex3f(-x + xc, -y + yc, 0);
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


void face(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0, 0, 0, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_QUAD_STRIP);
	while (dx < dy) {

		glVertex3f(x + xc, y + yc, 0);
		glVertex3f(-x + xc, y + yc, 0);
		glVertex3f(x + xc, -y + yc, 0);
		glVertex3f(-x + xc, -y + yc, 0);

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

		glVertex3f(x + xc, y + yc, 0);
		glVertex3f(-x + xc, y + yc, 0);
		glVertex3f(x + xc, -y + yc, 0);
		glVertex3f(-x + xc, -y + yc, 0);

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

void circle(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0, 0, 0, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_POINTS);
	while (dx < dy) {

		glVertex3f(x + xc, y + yc, 0);
		glVertex3f(-x + xc, y + yc, 0);
		glVertex3f(x + xc, -y + yc, 0);
		glVertex3f(-x + xc, -y + yc, 0);

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

		glVertex3f(x + xc, y + yc, 0);
		glVertex3f(-x + xc, y + yc, 0);
		glVertex3f(x + xc, -y + yc, 0);
		glVertex3f(-x + xc, -y + yc, 0);

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

void semicircle(int rx, int ry, int xc, int yc, float r, float g, float b) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	glClearColor(0, 0, 0, 0);
	glColor3f(r, g, b);
	// glColor3f(r, g, b);
	glPointSize(1);
	glBegin(GL_QUAD_STRIP);
	while (dx < dy) {

		glVertex3f(x + xc, y + yc, 0);
		glVertex3f(-x + xc, y + yc, 0);
		//glVertex3f(x + xc, -y + yc, 0);
		//glVertex3f(-x + xc, -y + yc, 0);

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

		glVertex3f(x + xc, y + yc, 0);
		glVertex3f(-x + xc, y + yc, 0);
		//glVertex3f(x + xc, -y + yc, 0);
		//glVertex3f(-x + xc, -y + yc, 0);

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



