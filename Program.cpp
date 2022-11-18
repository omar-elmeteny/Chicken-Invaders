#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <time.h>

#include "CGame.h"

using namespace std;

CGame game;

float ypos = 0;
int state = 1;



void timer(int) {

	game.tick();
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);

	/*ypos = ypos + 40;

	if (ypos > 1500) {
		ypos = 0;
	}*/

}


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	game.draw();

	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void specialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (game.spaceship->ypos + game.spaceShipSpeed < game.top - 250) {
			game.spaceship->ypos += game.spaceShipSpeed;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_DOWN:
		if (game.spaceship->ypos - game.spaceShipSpeed > game.bottom + 70) {
			game.spaceship->ypos -= game.spaceShipSpeed;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_LEFT:
		if (game.spaceship->xpos - game.spaceShipSpeed > game.left - 40) {
			game.spaceship->xpos -= game.spaceShipSpeed;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_RIGHT:
		if (game.spaceship->xpos + game.spaceShipSpeed < game.right - 150) {
			game.spaceship->xpos += game.spaceShipSpeed;
			glutPostRedisplay();
		}
		break;
	case ' ':
		game.addBullet();
	}
}

void charKey(unsigned char key, int x, int y) {
	switch (key) {
	case ' ':
		game.addBullet();
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
	gluOrtho2D(game.left, game.right, game.bottom, game.top);

	glutSpecialFunc(specialKey);
	glutKeyboardFunc(charKey);
	glutTimerFunc(0, timer, 0);

	glutMainLoop();


	return 0;
}
