//
//  main.c
//  Computer-Graphics
//
//  Created by Aditya Pandey on 14/01/25.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define XMAX 1200
#define YMAX 700
#define SPACESHIP_SPEED 20

enum view {INTRO, MENU, INSTRUCTIONS, GAME, GAMEOVER};
enum view viewPage = INTRO;

bool mButtonPressed = false;
float mouseX, mouseY;
bool keyStates[256] = {false};
bool laser1Dir[2] = {false};
bool laser2Dir[2] = {false};

int alienLife1 = 100;
int alienLife2 = 100;
float xOne = 500, yOne = 0;
float xTwo = 500, yTwo = 0;
bool laser1 = false, laser2 = false;
int CI = 0;

GLfloat AlienBody[][2] = {{-4,9}, {-6,0}, {0,0}, {0.5,9}, {0.15,12}, {-14,18}, {-19,10}, {-20,0}, {-6,0}};
GLfloat AlienCollar[][2] = {{-9,10.5}, {-6,11}, {-5,12}, {6,18}, {10,20}, {13,23}, {16,30}, {19,39}, {16,38},
                          {10,37}, {-13,39}, {-18,41}, {-20,43}, {-20.5,42}, {-21,30}, {-19.5,23}, {-19,20},
                          {-14,16}, {-15,17}, {-13,13}, {-9,10.5}};
GLfloat ALienFace[][2] = {{-6,11}, {-4.5,18}, {0.5,20}, {0.,20.5}, {0.1,19.5}, {1.8,19}, {5,20}, {7,23}, {9,29},
                        {6,29.5}, {5,28}, {7,30}, {10,38}, {11,38}, {11,40}, {11.5,48}, {10,50.5}, {8.5,51}, {6,52},
                        {1,51}, {-3,50}, {-1,51}, {-3,52}, {-5,52.5}, {-6,52}, {-9,51}, {-10.5,50}, {-12,49}, {-12.5,47},
                        {-12,43}, {-13,40}, {-12,38.5}, {-13.5,33}, {-15,38}, {-14.5,32}, {-14,28}, {-13.5,33}, {-14,28},
                        {-13.8,24}, {-13,20}, {-11,19}, {-10.5,12}, {-6,11}};
GLfloat ALienBeak[][2] = {{-6,21.5}, {-6.5,22}, {-9,21}, {-11,20.5}, {-20,20}, {-14,23}, {-9.5,28}, {-7,27}, {-6,26.5},
                        {-4.5,23}, {-4,21}, {-6,19.5}, {-8.5,19}, {-10,19.5}, {-11,20.5}};
GLfloat LightColor[][3] = {{1,1,0}, {0,1,1}, {0,1,0}};

void displayRasterText(float x, float y, float z, const char *stringToDisplay) {
    glRasterPos3f(x, y, z);
    for(const char *c = stringToDisplay; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1200, 1200, -700, 700);
    glMatrixMode(GL_MODELVIEW);
}

void introScreen() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-425, 490, 0.0, "Thapar Institute of Engineering & Technology");
    
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-700, 385, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    
    glColor3f(0.0, 0.0, 1.0);
    displayRasterText(-225, 300, 0.0, "Project on");
    
    glColor3f(1.0, 0.0, 1.0);
    displayRasterText(-125, 225, 0.0, "Space Shooter");
    
    glColor3f(1.0, 0.7, 0.8);
    displayRasterText(-800, -30, 0.0, " STUDENT NAMES");
    
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-800, -130, 0.0, " Aditya Pandey");
    displayRasterText(-800, -215, 0.0, " Tanisha");
    displayRasterText(-800, -300, 0.0, " Ketan Maini");
    
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(500, -30, 0.0, "Submitted to ");
    
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(500, -130, 0.0, "Dr. Nisha Thakur");
    
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-250, -400, 0.0, "Academic Year 2025-2026");
    
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-300, -550, 0.0, "Press ENTER to start the game");
    
    glutSwapBuffers();
}

void startScreenDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(10);

    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-750, -500);
        glVertex2f(-750, 550);
        glVertex2f(750, 550);
        glVertex2f(750, -500);
    glEnd();

    glLineWidth(1);

    // Start Game Button
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-200, 300);
        glVertex2f(-200, 400);
        glVertex2f(200, 400);
        glVertex2f(200, 300);
    glEnd();

    // Instructions Button
    glBegin(GL_POLYGON);
        glVertex2f(-200, 50);
        glVertex2f(-200, 150);
        glVertex2f(200, 150);
        glVertex2f(200, 50);
    glEnd();

    // Quit Button
    glBegin(GL_POLYGON);
        glVertex2f(-200, -200);
        glVertex2f(-200, -100);
        glVertex2f(200, -100);
        glVertex2f(200, -200);
    glEnd();

    // Button labels
    if(mouseX >= -200 && mouseX <= 200 && mouseY >= 300 && mouseY <= 400) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            alienLife1 = alienLife2 = 100;
            viewPage = GAME;
            mButtonPressed = false;
        }
    } else {
        glColor3f(0, 0, 0);
    }
    displayRasterText(-100, 340, 0.4, "Start Game");

    if(mouseX >= -200 && mouseX <= 200 && mouseY >= 50 && mouseY <= 150) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            viewPage = INSTRUCTIONS;
            mButtonPressed = false;
        }
    } else {
        glColor3f(0, 0, 0);
    }
    displayRasterText(-120, 80, 0.4, "Instructions");

    if(mouseX >= -200 && mouseX <= 200 && mouseY >= -200 && mouseY <= -100) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            exit(0);
        }
    } else {
        glColor3f(0, 0, 0);
    }
    displayRasterText(-100, -170, 0.4, "Quit");
    
    glutSwapBuffers();
}

void backButton() {
    if(mouseX <= -450 && mouseX >= -500 && mouseY >= -275 && mouseY <= -250) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            viewPage = MENU;
            mButtonPressed = false;
        }
    } else {
        glColor3f(1, 0, 0);
    }
    displayRasterText(-1000, -550, 0, "Back");
}

void instructionsScreenDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1, 0, 0);
    displayRasterText(-900, 550, 0.4, "INSTRUCTIONS");
    
    glColor3f(1, 0, 0);
    displayRasterText(-1000, 400, 0.4, "PLAYER 1");
    displayRasterText(200, 400, 0.4, "PLAYER 2");
    
    glColor3f(1, 1, 1);
    displayRasterText(-1100, 300, 0.4, "Key 'w' to move up.");
    displayRasterText(-1100, 200, 0.4, "Key 's' to move down.");
    displayRasterText(-1100, 100, 0.4, "Key 'd' to move right.");
    displayRasterText(-1100, 0, 0.4, "Key 'a' to move left.");
    
    displayRasterText(100, 300, 0.4, "Key 'i' to move up.");
    displayRasterText(100, 200, 0.4, "Key 'k' to move down.");
    displayRasterText(100, 100, 0.4, "Key 'j' to move right.");
    displayRasterText(100, 0, 0.4, "Key 'l' to move left.");
    
    displayRasterText(-1100, -100, 0.4, "Key 'c' to shoot, Use 'w' and 's' to change direction.");
    displayRasterText(100, -100, 0.4, "Key 'm' to shoot, Use 'i' and 'k' to change direction.");
    
    displayRasterText(-1100, -300, 0.4, "The Objective is to kill your opponent.");
    displayRasterText(-1100, -370, 0.4, "Each time a player gets shot, LIFE decreases by 5 points.");
    
    backButton();
    glutSwapBuffers();
}

void DrawAlienBody(bool isPlayer1) {
    if(isPlayer1)
        glColor3f(0, 1, 0);
    else
        glColor3f(1, 1, 0);
    
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 8; i++)
        glVertex2fv(AlienBody[i]);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 8; i++)
        glVertex2fv(AlienBody[i]);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-13, 11);
        glVertex2f(-15, 9);
    glEnd();
}

void DrawAlienCollar() {
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 20; i++)
        glVertex2fv(AlienCollar[i]);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 20; i++)
        glVertex2fv(AlienCollar[i]);
    glEnd();
}

void DrawAlienFace(bool isPlayer1) {
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 42; i++)
        glVertex2fv(ALienFace[i]);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 42; i++)
        glVertex2fv(ALienFace[i]);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(3.3, 22);
        glVertex2f(4.4, 23.5);
        glVertex2f(6.3, 26);
    glEnd();
}

void DrawAlienBeak() {
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 14; i++)
        glVertex2fv(ALienBeak[i]);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 14; i++)
        glVertex2fv(ALienBeak[i]);
    glEnd();
}

void DrawAlienEyes(bool isPlayer1) {
    glColor3f(0, 1, 1);
    glPushMatrix();
    glRotated(-10, 0, 0, 1);
    glTranslated(-6, 32.5, 0);
    glScalef(2.5, 4, 0);
    glutSolidSphere(1, 20, 30);
    glPopMatrix();

    glPushMatrix();
    glRotated(-1, 0, 0, 1);
    glTranslated(-8, 36, 0);
    glScalef(2.5, 4, 0);
    glutSolidSphere(1, 100, 100);
    glPopMatrix();
}

void DrawAlien(bool isPlayer1) {
    DrawAlienBody(isPlayer1);
    DrawAlienCollar();
    DrawAlienFace(isPlayer1);
    DrawAlienBeak();
    DrawAlienEyes(isPlayer1);
}

void DrawSpaceshipBody(bool isPlayer1) {
    if(isPlayer1)
        glColor3f(1, 0, 0);
    else
        glColor3f(0.5, 0, 0.5);

    glPushMatrix();
    glScalef(70, 20, 1);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glScalef(3, 3, 1);
    glTranslated(-20, 0, 0);
    glColor3fv(LightColor[(CI+0)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+1)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+2)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+0)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+1)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+2)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+0)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+1)%3]);
    glutSolidSphere(1, 1000, 1000);
    glTranslated(5, 0, 0);
    glColor3fv(LightColor[(CI+2)%3]);
    glutSolidSphere(1, 1000, 1000);
    glPopMatrix();
}

void DrawSteeringWheel() {
    glPushMatrix();
    glLineWidth(3);
    glColor3f(0.20, 0., 0.20);
    glScalef(7, 4, 1);
    glTranslated(-1.9, 5.5, 0);
    glutWireSphere(1, 8, 8);
    glPopMatrix();
}

void DrawSpaceshipDoom() {
    glColor4f(0.7, 1, 1, 0.0011);
    glPushMatrix();
    glTranslated(0, 30, 0);
    glScalef(35, 50, 1);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();
}

void DrawLaser(int x, int y, bool dir[]) {
    int xend = -XMAX, yend = y;
    if(dir[0])
        yend = YMAX;
    else if(dir[1])
        yend = -YMAX;
    
    glLineWidth(5);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(xend, yend);
    glEnd();
}

void SpaceshipCreate(int x, int y, bool isPlayer1) {
    glPushMatrix();
    glTranslated(x, y, 0);
    DrawSpaceshipDoom();
    glPushMatrix();
    glTranslated(4, 19, 0);
    DrawAlien(isPlayer1);
    glPopMatrix();
    DrawSteeringWheel();
    DrawSpaceshipBody(isPlayer1);
    glPopMatrix();
}

void DisplayHealthBar1() {
    char temp1[40];
    glColor3f(1, 1, 1);
    sprintf(temp1, "LIFE = %d", alienLife1);
    displayRasterText(-1100, 600, 0.4, temp1);
}

void DisplayHealthBar2() {
    char temp2[40];
    glColor3f(1, 1, 1);
    sprintf(temp2, "LIFE = %d", alienLife2);
    displayRasterText(800, 600, 0.4, temp2);
}

void checkLaserContact(int x, int y, bool dir[], int xp, int yp, bool player1) {
    int xend = -XMAX, yend = y;
    xp += 8; yp += 8;
    if(dir[0])
        yend = YMAX;
    else if(dir[1])
        yend = -YMAX;

    float m = (float)(yend - y) / (float)(xend - x);
    float k = y - m * x;
    int r = 50;

    float b = 2 * xp - 2 * m * (k - yp);
    float a = 1 + m * m;
    float c = xp * xp + (k - yp) * (k - yp) - r * r;

    float d = (b * b - 4 * a * c);
    if(d >= 0) {
        if(player1)
            alienLife1 -= 5;
        else
            alienLife2 -= 5;
    }
}

void gameScreenDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    DisplayHealthBar1();
    DisplayHealthBar2();
    
    glPushMatrix();
    glScalef(2, 2, 0);

    if(alienLife1 > 0) {
        SpaceshipCreate(xOne, yOne, true);
        if(laser1) {
            DrawLaser(xOne, yOne, laser1Dir);
            checkLaserContact(xOne, yOne, laser1Dir, -xTwo, yTwo, true);
        }
    } else {
        viewPage = GAMEOVER;
    }

    if(alienLife2 > 0) {
        glPushMatrix();
        glScalef(-1, 1, 1);
        SpaceshipCreate(xTwo, yTwo, false);
        if(laser2) {
            DrawLaser(xTwo, yTwo, laser2Dir);
            checkLaserContact(xTwo, yTwo, laser2Dir, -xOne, yOne, false);
        }
        glPopMatrix();
    } else {
        viewPage = GAMEOVER;
    }

    glPopMatrix();
    
    if(viewPage == GAMEOVER) {
        xOne = xTwo = 500;
        yOne = yTwo = 0;
    }
    
    glutSwapBuffers();
}

void displayGameOverMessage() {
    glColor3f(1, 1, 0);
    const char *message;
    if(alienLife1 > 0)
        message = "Game Over! Player 1 won the game";
    else
        message = "Game Over! Player 2 won the game";

    displayRasterText(-350, 600, 0.4, message);
}

void keyOperations() {
    if(keyStates[13] == true && viewPage == INTRO) {
        viewPage = MENU;
    }
    if(viewPage == GAME) {
        laser1Dir[0] = laser1Dir[1] = false;
        laser2Dir[0] = laser2Dir[1] = false;
        
        // Player 2 controls (WASD + C for laser)
        if(keyStates['c'] == true) {
            laser2 = true;
            if(keyStates['w'] == true) laser2Dir[0] = true;
            if(keyStates['s'] == true) laser2Dir[1] = true;
        } else {
            laser2 = false;
            if(keyStates['d'] == true) xTwo -= SPACESHIP_SPEED;
            if(keyStates['a'] == true) xTwo += SPACESHIP_SPEED;
            if(keyStates['w'] == true) yTwo += SPACESHIP_SPEED;
            if(keyStates['s'] == true) yTwo -= SPACESHIP_SPEED;
        }

        // Player 1 controls (IJKL + M for laser)
        if(keyStates['m'] == true) {
            laser1 = true;
            if(keyStates['i'] == true) laser1Dir[0] = true;
            if(keyStates['k'] == true) laser1Dir[1] = true;
        } else {
            laser1 = false;
            if(keyStates['l'] == true) xOne += SPACESHIP_SPEED;
            if(keyStates['j'] == true) xOne -= SPACESHIP_SPEED;
            if(keyStates['i'] == true) yOne += SPACESHIP_SPEED;
            if(keyStates['k'] == true) yOne -= SPACESHIP_SPEED;
        }
    }
}

void display() {
    keyOperations();
    glClear(GL_COLOR_BUFFER_BIT);

    switch(viewPage) {
        case INTRO:
            introScreen();
            break;
        case MENU:
            startScreenDisplay();
            break;
        case INSTRUCTIONS:
            instructionsScreenDisplay();
            break;
        case GAME:
            gameScreenDisplay();
            break;
        case GAMEOVER:
            glClear(GL_COLOR_BUFFER_BIT);
            displayGameOverMessage();
            startScreenDisplay();
            break;
    }
}

void passiveMotionFunc(int x, int y) {
    mouseX = (float)x/(1200.0/2400.0)-1200.0;
    mouseY = -((float)y/(700.0/1400.0)-700.0);
    glutPostRedisplay();
}

void mouseClick(int buttonPressed, int state, int x, int y) {
    if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y) {
    keyStates[key] = true;
    glutPostRedisplay();
}

void keyReleased(unsigned char key, int x, int y) {
    keyStates[key] = false;
}

void timer(int value) {
    CI = (CI + 1) % 3;
    glutPostRedisplay();
    glutTimerFunc(300, timer, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 700);
    glutCreateWindow("Space Shooter");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMotionFunc);
    glutTimerFunc(300, timer, 0);
    
    glutMainLoop();
    return 0;
}
