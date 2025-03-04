//
//  main.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 14/01/25.
//

#include <GLUT/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glColor3f(1.0, 0.0, 0.0);       // Set color to red (R=1, G=0, B=0)

    glBegin(GL_POINTS);             // Start drawing a point
        glVertex2f(10.0, 0.0);        // Position the point at the center (origin)
    glEnd();

    glFlush();  // Render the point
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glPointSize(5.0);                 // Set the size of the point
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 20, -1, 20);         // Set coordinate system (-1 to 1)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Red Point");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
