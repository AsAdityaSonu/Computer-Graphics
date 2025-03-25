//
//  FillPolygon.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 25/03/25.
//

//#include <GLUT/glut.h>
//#include <stdio.h>
//
//#define MAX_VERTICES 10
//int vertices[MAX_VERTICES][2];
//int vertexCount = 0;
//
//void drawPolygon() {
//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_LINE_LOOP);
//    for (int i = 0; i < vertexCount; i++) {
//        glVertex2i(vertices[i][0], vertices[i][1]);
//    }
//    glEnd();
//}
//
//void scanlineFill() {
//    int yMin = vertices[0][1], yMax = vertices[0][1];
//    for (int i = 1; i < vertexCount; i++) {
//        if (vertices[i][1] < yMin) yMin = vertices[i][1];
//        if (vertices[i][1] > yMax) yMax = vertices[i][1];
//    }
//    
//    for (int y = yMin; y <= yMax; y++) {
//        int intersections[MAX_VERTICES], count = 0;
//        
//        for (int i = 0; i < vertexCount; i++) {
//            int x1 = vertices[i][0], y1 = vertices[i][1];
//            int x2 = vertices[(i + 1) % vertexCount][0], y2 = vertices[(i + 1) % vertexCount][1];
//            
//            if (y1 == y2) continue;
//            if (y >= y1 && y < y2 || y >= y2 && y < y1) {
//                int x = x1 + (float)(y - y1) * (x2 - x1) / (y2 - y1);
//                intersections[count++] = x;
//            }
//        }
//        
//        for (int i = 0; i < count - 1; i++) {
//            for (int j = 0; j < count - i - 1; j++) {
//                if (intersections[j] > intersections[j + 1]) {
//                    int temp = intersections[j];
//                    intersections[j] = intersections[j + 1];
//                    intersections[j + 1] = temp;
//                }
//            }
//        }
//        
//        glColor3f(1.0, 0.0, 0.0);
//        glBegin(GL_LINES);
//        for (int i = 0; i < count; i += 2) {
//            glVertex2i(intersections[i], y);
//            glVertex2i(intersections[i + 1], y);
//        }
//        glEnd();
//    }
//    glFlush();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawPolygon();
//    scanlineFill();
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
//int main(int argc, char** argv) {
//    printf("Enter the number of vertices: ");
//    scanf("%d", &vertexCount);
//    
//    printf("Enter the coordinates (x, y) of the vertices:\n");
//    for (int i = 0; i < vertexCount; i++) {
//        scanf("%d %d", &vertices[i][0], &vertices[i][1]);
//    }
//    
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Scanline Fill Algorithm");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
