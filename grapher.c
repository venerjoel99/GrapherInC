void init(){
}


void configureLighting(){
}

void configureViews(){
}

void setupGraphics(){
    
    //Create a window
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE); 
    glutCreateWindow("Grapher");.
    
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
}

int main(int argc, char **argv){
    
    //Init GLUT
    glutInit(&argc, argv);
    setupGraphics();
    glutMainLoop();
    
}

