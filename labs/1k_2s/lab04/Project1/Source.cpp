#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutInitContextVersion(4, 1); // ¬ерси€ OpenGL, которую вы хотите использовать
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);

	if (glewInit()) {
		std::cerr << "Unable to initialize GLEW ... exiting\n";
		exit(EXIT_FAILURE);
	}

	glutMainLoop();

}