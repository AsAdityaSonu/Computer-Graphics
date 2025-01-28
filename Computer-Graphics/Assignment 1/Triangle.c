//
//  Triangle.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 28/01/25.
//


//#include <GLUT/glut.h>
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glPointSize(10);
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//    glColor3f(0.0, 1.0, 0.0);
//    glBegin(GL_TRIANGLES);
//        glVertex2f(-0.5, -0.5);        glVertex2f(0.5, -0.5);
//        glVertex2f(0.0, 0.5);
//    glEnd();
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 400);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("OpenGL Triangle");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
