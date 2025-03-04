//
//  BresenhamLine.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 28/01/25.
//

//// Bresenham's Line Drawing Algorithm
//#include <GLUT/glut.h>
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void drawLineBresenham() {
//    int x1 = 100, y1 = 100; // Starting point
//    int x2 = 400, y2 = 300; // Ending point
//
//    int dx = abs(x2 - x1);
//    int dy = abs(y2 - y1);
//    int sx = (x2 > x1) ? 1 : -1; // Step for x
//    int sy = (y2 > y1) ? 1 : -1; // Step for y
//
//    int err = dx - dy; // Initial decision parameter
//
//    glBegin(GL_POINTS);
//    while (1) {
//        glVertex2i(x1, y1); // Plot the pixel
//
//        if (x1 == x2 && y1 == y2) break; // Line completed
//
//        int e2 = 2 * err;
//        if (e2 > -dy) {
//            err -= dy;
//            x1 += sx;
//        }
//        if (e2 < dx) {
//            err += dx;
//            y1 += sy;
//        }
//    }
//    glEnd();
//    glFlush(); // Render the points
//}
//
//// OpenGL initialization
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color: Black
//    glColor3f(1.0, 1.0, 1.0);         // Line color: White
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 500, 0, 500);       // Set the coordinate system
//}
//
//// Display callback function
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
//    drawLineBresenham();          // Call the Bresenham line drawing function
//}
//
//// Main function
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);      // Window size
//    glutInitWindowPosition(100, 100); // Window position
//    glutCreateWindow("Bresenham Line Drawing");
//
//    init();
//    glutDisplayFunc(display);         // Set the display callback function
//    glutMainLoop();                   // Enter the GLUT event-processing loop
//
//    return 0;
//}
