#ifndef DRAW_TREE_H
#define DRAW_TREE_H

#include "AFuntions.h"

node* root = NULL;

void InizializeGlutRoot(node* root_tmp) {
	root = root_tmp;
}

void drawCircle(float segments, float radius, float sx, float sy)
{
	float theta = 2 * (float)3.1415926 / segments;
	float tan_factor = tanf(theta);
	float radial_factor = cosf(theta);
	float x = radius;
	float y = 0;

	int cache_pt = 0;
	double cache_x;
	double cache_y;

	glBegin(GL_LINES);
	for (int ii = 0; ii < segments; ii++) {
		if (!cache_pt) {
			cache_x = x + sx;
			cache_y = y + sy;
			cache_pt = 1;
		}
		else {
			//glVertex2f(cache_x,cache_y);
			glVertex2f(x + sx, y + sy);
			cache_x = x + sx;
			cache_y = y + sy;
		}
		float tx = -y;
		float ty = x;
		x += tx * tan_factor;
		y += ty * tan_factor;
		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}

void draw_line(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void draw_text(char* text, float x, float y) {
	GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;
	glRasterPos3f(x, y, 0);
	for (int i = 0; text[i] != '\0'; i++) {
		glutBitmapCharacter(font_style, text[i]);
	}
}

void drawNode(node* t_root, float x1, float y1, int level) {
	if (t_root == NULL) {
		return;
	}
	float segments = 25;
	float radius = 1.0;
	float left_angle = 245;
	float right_angle = 115;
	float branch_length = 12 - level * (float)2.5;
	float angle_change = 20;

	// Draw the current circle

	drawCircle(segments, radius, x1, y1);

	char buff[5];
	strcpy_s(buff, (t_root->data).c_str());
	draw_text(buff, x1, y1);

	if (t_root->left) {
		// Draw the Left circle
		float angle = left_angle - level * angle_change;
		double radian = angle * 3.14 / 180;
		float m = (double)tan((double)radian);
		float x2 = x1 + branch_length * sin((double)radian);
		float y2 = y1 + branch_length * cos((double)radian);
		drawNode(t_root->left, x2, y2, level + 1);
		draw_line(x1, y1, x2, y2);
	}
	if (t_root->right) {
		// Draw the Right circle
		float angle = right_angle + level * angle_change;
		float radian = angle * 3.14 / 180;
		float m = (double)tan((double)radian);
		float x2 = x1 + branch_length * sin((double)radian);
		float y2 = y1 + branch_length * cos((double)radian);
		drawNode(t_root->right, x2, y2, level + 1);
		draw_line(x1, y1, x2, y2);
	}

}


void display(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 10, -30);
	glColor3f(1, 1, 1);

	drawNode(root, 0, 0, 0);

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

#endif