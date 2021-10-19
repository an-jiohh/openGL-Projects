#include<gl/freeglut.h>
#include<math.h>

GLvoid drawScene(GLvoid);

void DrawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void DrawEllipse(float cx, float cy, float rx, float ry, int num_segments) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

		float x = rx * cosf(theta);
		float y = ry * sinf(theta);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

int main() {
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Example");
	glutDisplayFunc(drawScene);
	glutMainLoop();
}

GLvoid drawScene(GLvoid) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	/*
	glScalef(2.0f, 2.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.0f, 0.3f);
	glEnd();
	*/

	DrawEllipse(0.0f, -0.3f, 0.75f, 0.3f, 80);

	glRectf(-0.75f, -0.3f, 0.75f, 0.2f);

	DrawCircle(-0.60f, 0.2f, 0.15f, 60);
	DrawCircle(-0.30f, 0.2f, 0.15f, 60);

	DrawCircle(0.30f, 0.2f, 0.15f, 60);
	DrawCircle(0.60f, 0.2f, 0.15f, 60);

	glRectf(-0.15f, 0.2f, 0.15f, 0.65f);
	DrawCircle(0.0f, 0.65f, 0.15f, 60);

	glFlush();
}