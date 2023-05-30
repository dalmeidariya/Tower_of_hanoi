#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
void MyInit(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
void Rectangle()
{
        glColor3f(1.0,1.0,0.0);
        glPointSize(2.0);
    // x1, x2, y1, y2
    glBegin(GL_POLYGON); //base
       glVertex2f(300,-350);
       glVertex2f(-300,-350);
       glVertex2f(-300,-300);
       glVertex2f(300,-300);
    glEnd();
 glColor3f(1.0,0.0,0.0);
     glBegin(GL_POLYGON);//pole2
                glVertex2f(-30,-300);
                glVertex2f(-25,-300);
                glVertex2f(-25,250);
                glVertex2f(-30,250);
        glEnd();//pole1
        glBegin(GL_POLYGON);
       glVertex2f(200,-300);
       glVertex2f(205,-300);
       glVertex2f(205,250);
       glVertex2f(200,250);
    glEnd();
    glBegin(GL_POLYGON);//pole3
               glVertex2f(-220,-300);
                glVertex2f(-215,-300);
                glVertex2f(-215,250);
                glVertex2f(-220,250);
        glEnd();
   glBegin(GL_POLYGON); //disk1
       glVertex2f(-270,-260);
       glVertex2f(-160,-260);
       glVertex2f(-160,-300);
       glVertex2f(-270,-300);
    glEnd();
    glBegin(GL_POLYGON); //disk2
       glVertex2f(-250,-220);
       glVertex2f(-180,-220);
       glVertex2f(-180,-260);
       glVertex2f(-250,-260);
    glEnd();
    glBegin(GL_POLYGON); //disk3
       glVertex2f(-230,-180);
       glVertex2f(-200,-180);
       glVertex2f(-200,-220);
       glVertex2f(-230,-220);
    glEnd();
glFlush();
}
void Wheel(int x,int y)//disk circle
{
        float th;
        glBegin(GL_POLYGON);
                glColor3f(1.0,0.0,0.0);
                for(int i =0;i<360;i++)
                {
                        th= i*(3.1416/180);
                        glVertex2f(x+19*cos(th),y+19*sin(th));
                }
                glEnd();
glFlush();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
   Rectangle();
  Wheel(-270,-280);//disk1
    Wheel(-160,-280);
    Wheel(-250,-240);//disk2
    Wheel(-180,-240);
    Wheel(-200,-200);
    Wheel(-230,-200);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500,500);
    glutInitWindowSize(0,0);
    glutCreateWindow("Hello");
    glutDisplayFunc(display);
    glColor3f(1.0,1.0,1.0);
    MyInit();
    glutMainLoop();
        return 0;
}

