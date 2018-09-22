#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>       /* for cos(), sin(), and sqrt() */
#include <GL/glut.h>    /* OpenGL Utility Toolkit header */

void init(){
}

typedef enum{
    RESERVED, CUBE_SIDE, CUBE_EDGE, CUBE_WHOLE
} displayLists;

static GLfloat lightColor[] = {0.8, 1.0, 0.8, 1.0}; /* green-tinted */
static GLfloat[][2] cube = {{0,1}, {0,11}, {10,1}, {10,11}};
static GLflot width = 10;
static skinColor[] = {0.1, 1.0, 0.1, 1.0};

void configureLighting(){
}

void configureViews(){
}

void drawCube(){
    extrudeSolidFromPolygon(cube, sizeof(cube), CUBE_SIDE, CUBE_EDGE, CUBE_WHOLE);
}

void displayCube(){
    glPushMatrix();
    glTranslatef(-8, 0, -5);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, skinColor);
    glCallList(CUBE_WHOLE);
    glPopMatrix();
}

void display(){
    displayCube();
}

void setupGraphics(){
    
    //Create a window
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE); 
    glutCreateWindow("Grapher");
    
    //Create cameras
    //Position and orient cameras
    //Create viewports
    //Connect cameras to viewports
    //Position viewports on the screen
    glMatrixMode(GL_PROJECTION);
    gluPerspective( /* field of view in degree */ 40.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 20.0, /* Z far */ 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 8.0, 60.0,  /* eye is at (0,8,60) */
    0.0, 8.0, 0.0,      /* center is at (0,8,0) */
    0.0, 1.0, 0.);      /* up is in postivie Y direction */
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glLineWidth(3.0);
    
    //Create lighting for objects
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    
    //Keep black backgrounds
    glutDisplayFunc(display);
}

int main(int argc, char **argv){
    
    //Init GLUT
    glutInit(&argc, argv);
    drawCube();
    setupGraphics();
    glutMainLoop();
    return 0;
}

