//
//  Circle.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 23/02/25.
//

//#include <GLUT/glut.h>
//#include <stdio.h>
//
//void plot(int x, int y, int xc, int yc) {
//    glBegin(GL_POINTS);
//    glVertex2i(xc + x, yc + y);
//    glVertex2i(xc - x, yc + y);
//    glVertex2i(xc + x, yc - y);
//    glVertex2i(xc - x, yc - y);
//    glEnd();
//}
//
//void midpointCircle(int xc, int yc, int r) {
//    int x = 0, y = r;
//    int d = 1 - r;
//    while (x <= y) {
//        plot(x, y, xc, yc);
//        plot(y, x, xc, yc);
//        plot(y, -x, xc, yc);
//        plot(x, -y, xc, yc);
//        
//        if (d < 0) {
//            d += 2 * x + 3;
//        } else {
//            d += 2 * (x - y) + 5;
//            y--;
//        }
//        x++;
//    }
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glPointSize(2.0);
//    
//    midpointCircle(0, 0, 100);
//    
//    glFlush();
//}
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-300, 300, -300, 300);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 600);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Midpoint Circle Algorithm");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
