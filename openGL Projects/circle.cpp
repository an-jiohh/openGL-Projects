#include<gl/freeglut.h>
#include<math.h>

GLvoid drawScene(GLvoid);

void DrawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void DrawEllipse(float cx, float cy, float rx, float ry, int num_segments) {
	glBegin(GL_LINE_LOOP);
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

	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_POLYGON);
	//glBegin(GL_LINE_LOOP);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.7f, 0.1f);
	glVertex2f(0.7f, 0.7f);
	glVertex2f(0.1f, 0.7f);
	glEnd();

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	DrawCircle(0.1f, 0.1f, 0.6f, 60);

	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	DrawEllipse(0.1f, 0.1f, 0.6f, 0.4f, 80);

	glFlush();
}