// Name: Muaz Alhaidar
//
// Description: Using the diode drawing from project 1 to create
// a RECTIFIER and a ROTATED RECTIFIER
//
// Date: 10/13/2019

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <iostream>

void myInit(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);                 // Set the background color to white 

	glLineWidth(2.0f);                                // Set line width to 2.0
	
	glMatrixMode(GL_PROJECTION);                      //
	glLoadIdentity();                                 // Sets view port to (-1, 1, -1, 1) = (left, right, bottom, top)
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);             //
}

/*
	Draws out 3 lines and a triangle (which is colored red)
	In order to represent a diode
*/
void drawDiode(void) {

	glColor3f(0.0f, 0.0f, 0.0f);                      // Set line color to black

	glBegin(GL_LINE_STRIP);                           // Cross at the front of the diode

		glVertex2f(-0.25f, 0.0f);                     // Horizontal line at the front
		glVertex2f(-0.1f, 0.0f);

		glVertex2f(-0.1f, 0.1f);                      // Vertical line perpindicular to horizontal line
		glVertex2f(-0.1f, -0.1f);

	glEnd();

	glBegin(GL_LINE_STRIP);                           // Line at the back of the diode

		glVertex2f(0.1f, 0.0f);
		glVertex2f(0.25f, 0.0f);

	glEnd();

	glBegin(GL_LINE_LOOP);                            // Line loops around the triangle

		glVertex2f(-0.1f, 0.0f);
		glVertex2f(0.1f, -0.1f);
		glVertex2f(0.1f, 0.1f);

	glEnd();

	glBegin(GL_TRIANGLES);                            // Creates red triangle

		glColor3f(1.0f, 0.0f, 0.0f);                  // Set colour to red

		glVertex2f(-0.1f, 0.0f);                      // Left Corner
		glVertex2f(0.1f, 0.1f);                       // Top Corner
		glVertex2f(0.1f, -0.1f);                      // Bottom Corner

	glEnd();
}

/*
	Draws a Rectifier using four Diodes
*/
void drawRectifier(void) {


	glPushMatrix(); // Creates top Diode

		glTranslatef(0.0f, 0.3f, 0.0f);                // Moves created diode up
		drawDiode();                                   // Draws diode

	glPopMatrix();

	glPushMatrix(); // Creates bottom Diode

		glTranslatef(0.0f, -0.3f, 0.0f);               // Moves created diode down
		drawDiode();                                   // Draws diode

	glPopMatrix();

	glPushMatrix(); // Creates left Diode
		
		glTranslatef(-0.3f, 0.0f, 0.0f);               // Moves created diode to the left
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);            // Rotates diode 90 degrees counter-clockwise
		drawDiode();                                   // Draws diode

	glPopMatrix();

	glPushMatrix(); // Creates right Diode
		
		glTranslatef(0.3f, 0.0f, 0.0f);                // Moves created diode to the right
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);            // Rotates diode 90 degrees counter-clockwise
		drawDiode();                                   // Draws diode

	glPopMatrix();
}
/*
	Draws a rectifier to scale
*/
void drawScaledRectifier(void) {

	glPushMatrix();

		glScaled(2.0f, 2.0f, 1.0f); // scales rectifier to 2x the original size
		drawRectifier(); // draws the recifier

	glPopMatrix();

	glFlush(); // Outputs the rectifier
}

/*
	Draws a rectifier (to scale) that is rotated 45 degrees couter-clock wise
*/
void drawScaledRotatedRectifier(void) {

	glPushMatrix();
		
		glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // rotates rectifier 45 degrees counter-clock wise
		glScaled(2.0f, 2.0f, 1.0f); // scales rectifier to 2x the original size
		drawRectifier(); // draws the recifier

	glPopMatrix();

	glFlush(); // Outputs the rectifier
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(600, 600);                     // window size
	glutInitWindowPosition(500, 200);                 // distance from the top-left screen

	glutCreateWindow("Muaz Alhaidar PROG-2 Rectfier And Rotated Rectifier");// message displayed on top bar window
	
	int userChoice = 0; // Holds user choice for which rectifier to draw

	std::cout << "Would you like to display a: \n";
	std::cout << "1_Rectifier\n";
	std::cout << "2_Rotated Rectifier\n";
	std::cout << "Any other value to exit\n";
	std::cout << "Once you have entered a value, close out of the window\n";

	std::cin >> userChoice;							         // User's choice is entered

	if (userChoice == 1) {
		glutDisplayFunc(drawScaledRectifier);                // Display Scaled Rectifier
	}
	else if (userChoice == 2) {
		glutDisplayFunc(drawScaledRotatedRectifier);         // Display Scaled Rotated Rectifier
	}
	else {
		exit(0);                                             // Exit program if any other choice is entered
	}

	myInit();

	glutMainLoop();
	return 0;
}