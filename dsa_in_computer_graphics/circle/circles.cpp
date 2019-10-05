// Circle Drawing Algorithm
// Editor: kirito_ys

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <time.h>
#include<unistd.h>

int WINDOW_WIDTH = 900;
int WINDOW_HEIGHT = 600;

float COLOR_GRAY = 0.5;

struct Point{
  GLint x;
  GLint y;
};
struct Color{
  GLfloat r;
  GLfloat g;
  GLfloat b;
};

double X1, Y1, X2, Y2;
int x0=0;
//int y0=0;

void draw_circle(float radius,int x_center,int y_center);
void make_points(int x0,int y0,int x,int y);
int give_rand(int MAX=WINDOW_HEIGHT);
void putPoint(float x, float y);
void Init(){
  // Set clear color to white
  glClearColor(0.0,0.0,0.0,0);
  // Set fill color to black
  glColor3f(1.0,1.0,1.0);
  //glViewport(0 , 0 , 500 , 500);
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // gluOrtho2d(left,right,bottom,top)
  gluOrtho2D(-WINDOW_WIDTH/2 , WINDOW_WIDTH/2 , -WINDOW_HEIGHT/2 , WINDOW_HEIGHT/2);
}

void make_axis(){

	glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINES);
		glVertex2f(0,WINDOW_HEIGHT/2);
		glVertex2f(0,-WINDOW_HEIGHT/2);
		glVertex2f(WINDOW_WIDTH/2,0);
		glVertex2f(-WINDOW_WIDTH/2,0);
	glEnd();
}

Color get_pixel_color(GLint x,GLint y){
  Color color;
  glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT, &color);
  return color;
}
Color c;
int flood_fill(int x,int y){
  c = get_pixel_color(x,y);
  printf("\n Color of %d %d is %f %f %f",x,y,c.r,c.g,c.b);
  printf("Caleed");
  glColor3f(1,0,1.2);
  glPointSize(10);
  putPoint(x,y);
  glFlush();
  glColor3f(1,1,1);
  c = get_pixel_color(x,y);
  printf("\n Color of %d %d is %f %f %f",x,y,c.r,c.g,c.b);
}

void graphics_draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

	make_axis();

	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	for(int i=2;i<10;i=i+1){
		glColor3f(1,1,1);
		draw_circle(give_rand(),give_rand(),give_rand());
		usleep(50000);
	}

  flood_fill(0,0);
  glFlush();
}

int give_rand(int MAX){
	//return (MAX*rand())/RAND_MAX;
  return rand()%800 - 400;
}
void draw_circle(float radius,int x0,int y0){

	float p = 5/4 - radius;
	int x = 0;

	int y = radius;

	while(x<y){
		//Sleep(10);
		if(p<0){
			x = x + 1;
			y = y;
			p = p + 2*x + 1;
		}
		else{
			x = x + 1;
			y = y - 1;
			p = p + 2*x + 1 - 2*y;
		}

		make_points(x0,y0,x,y);

		glFlush();
	}
	//glFlush();
}
void make_points(int x0,int y0,int x,int y){
	glBegin(GL_POINTS);
			glVertex2d(x0+x,y0+y);
			glVertex2d(x0+x,y0-y);
			glVertex2d(x0-x,y0+y);
			glVertex2d(x0-x,y0-y);
			glVertex2d(x0+y,y0+x);
			glVertex2d(x0+y,y0-x);
			glVertex2d(x0-y,y0+x);
			glVertex2d(x0-y,y0-x);
		glEnd();
}
void putPoint(float x,float y){
	int x0 = 0;
	int y0 = 0;

	glBegin(GL_POINTS);
			glVertex2f(x0+x,y0+y);
	glEnd();
	glFlush();
}


int main(int argc, char **argv){
  //make random really random
  srand(time(0));

  glFlush();
  // Initialise GLUT library
  glutInit(&argc,argv);
  // Set the initial display mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // Set the initial window position and size
  //position means the position of the output screen with respect to the monitor screen
  glutInitWindowPosition(0,0);
  glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
  // Create the window with title "DDA_Line"
  glutCreateWindow("Computer Graphics Lab - 115cs0243");
  // Initialize drawing colors
  Init();
  // Call the displaying function
  glutDisplayFunc(graphics_draw);
  // Keep displaying untill the program is closed
  glutMainLoop();

  return 0;
}
