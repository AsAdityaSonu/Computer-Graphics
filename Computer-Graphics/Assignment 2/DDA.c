//
//  DDA.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 28/01/25.
//

// // DDA
//#include <GLUT/glut.h>
//#include <math.h>
//
//// DDA Line Drawing Algorithm
//void drawLineDDA() {
//    int x1 = 100, y1 = 100; // Starting point of the line
//    int x2 = 400, y2 = 300; // Ending point of the line
//
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); // Number of steps
//    float x_inc = dx / steps;  // Increment for x
//    float y_inc = dy / steps;  // Increment for y
//
//    float x = x1, y = y1;
//
//    glBegin(GL_POINTS);
//    for (int i = 0; i <= steps; i++) {
//        glVertex2i(round(x), round(y)); // Plot the point
//        x += x_inc; // Update x
//        y += y_inc; // Update y
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
//    drawLineDDA();                // Call the DDA line drawing function
//}
//
//// Main function
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);      // Window size
//    glutInitWindowPosition(100, 100); // Window position
//    glutCreateWindow("DDA Line Drawing");
//
//    init();
//    glutDisplayFunc(display);         // Set the display callback function
//    glutMainLoop();                   // Enter the GLUT event-processing loop
//
//    return 0;
//}
