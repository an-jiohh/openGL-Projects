#include<gl/freeglut.h>

GLvoid drawScene(GLvoid);

int main() {
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Example");
	glutDisplayFunc(drawScene);
	glutMainLoop();
}

GLvoid drawScene(GLvoid) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glRectf(-0.9f, -0.9f, 0.0f, 0.0f);
	
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);
	glLineWidth(3.0f);
	//glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	//glBegin(GL_LINE_LOOP);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.1f, 0.7f);
	glVertex2f(0.7f, 0.7f);
	glVertex2f(0.7f, 0.1f);
	
	glEnd();

	glFlush();
}