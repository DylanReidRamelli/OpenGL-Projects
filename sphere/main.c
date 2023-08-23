#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>

float angle = 0.0f; // rotation angle
float x = 0.0f;     // x position
float y = 0.0f;     // y position
float z = -5.0f;    // z position

void idle() { glutPostRedisplay(); }

void renderScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
  glutSwapBuffers();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Simple 3D Object");

  // glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(renderScene);
  // glutIdleFunc(idle);

  glutMainLoop();

  return 1;
}
