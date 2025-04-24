//
//  ObjectMove.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 04/04/25.
//

//#include <GLUT/glut.h>
//#include <stdio.h>
//#include <math.h>
//
//#define PI 3.14159265
//
//float points[3][2] = {{100, 100}, {200, 100}, {150, 200}};
//int numPoints = 3;
//float fixedX = 150, fixedY = 150;
//
//void drawPolygon() {
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_LINE_LOOP);
//    for (int i = 0; i < numPoints; i++) {
//        glVertex2i(points[i][0], points[i][1]);
//    }
//    glEnd();
//    glFlush();
//}
//
//void translate(float tx, float ty) {
//    for (int i = 0; i < numPoints; i++) {
//        points[i][0] += tx;
//        points[i][1] += ty;
//    }
//    glutPostRedisplay();
//}
//
//void rotate(float angle, int aboutFixed) {
//    float rad = angle * PI / 180.0;
//    float cosA = cos(rad), sinA = sin(rad);
//    float x, y;
//    float originX = aboutFixed ? fixedX : 0;
//    float originY = aboutFixed ? fixedY : 0;
//    
//    for (int i = 0; i < numPoints; i++) {
//        x = points[i][0] - originX;
//        y = points[i][1] - originY;
//        
//        points[i][0] = x * cosA - y * sinA + originX;
//        points[i][1] = x * sinA + y * cosA + originY;
//    }
//    glutPostRedisplay();
//}
//
//void scale(float sx, float sy, int aboutFixed) {
//    float originX = aboutFixed ? fixedX : 0;
//    float originY = aboutFixed ? fixedY : 0;
//    
//    for (int i = 0; i < numPoints; i++) {
//        points[i][0] = originX + (points[i][0] - originX) * sx;
//        points[i][1] = originY + (points[i][1] - originY) * sy;
//    }
//    glutPostRedisplay();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawPolygon();
//    glFlush();
//}
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 500, 0, 500);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//        case 'w': translate(0, 10); break;
//        case 's': translate(0, -10); break;
//        case 'a': translate(-10, 0); break;
//        case 'd': translate(10, 0); break;
//        case 'r': rotate(10, 0); break; // Rotate about origin
//        case 'R': rotate(10, 1); break; // Rotate about fixed point
//        case 'x': scale(1.1, 1.1, 0); break; // Scale about origin
//        case 'X': scale(1.1, 1.1, 1); break; // Scale about fixed point
////        case 'q': exit(0);
//    }
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("2D Transformations");
//    init();
//    glutDisplayFunc(display);
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
//    return 0;
//}
