// Circle Drawing Algorithm
// Editor: kirito_ys

/* Tips for viewing the output:
 * Use Win +'+' to open magnifier.
 * Use Ctrl + Alt + 'F' for full screen
 * Use Ctrl + Alt + 'L' for lens mode
 * Use Win + Esc to exit magnifier
 */

#include <stdio.h>
//#include <math.h>
#include<unistd.h> //for sleep() in unix
#include <GL/glut.h>
//#include <windows.h>
#include <time.h>
#include<math.h>

#define size 800
#define POINTSIZE 1

int WINDOW_WIDTH = size;
int WINDOW_HEIGHT = size;

float COLOR_GRAY = 0.5;

double X1, Y1, X2, Y2;
int x0=0;
//int y0=0;


int give_rand(int MAX=WINDOW_HEIGHT);


void Init()
{
  // Set clear color to white
  glClearColor(0.0,0.0,0.0,0);
  // Set fill color to black
  glColor3f(1.0,1.0,1.0);
  //glViewport(0 , 0 , 500 , 500);
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // gluOrtho2d(left,right,bottom,top)
  gluOrtho2D(-WINDOW_WIDTH/2 , WINDOW_WIDTH/2 , -WINDOW_HEIGHT/2 , WINDOW_HEIGHT/2);
  //gluOrtho2D(-50,50,-50,50);
}
void make_axis(){

	glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINES);
		glVertex2f(1,WINDOW_HEIGHT/2);
		glVertex2f(1,-WINDOW_HEIGHT/2);
		glVertex2f(WINDOW_WIDTH/2,0);
		glVertex2f(-WINDOW_WIDTH/2,0);
	glEnd();
}

int give_rand(int MAX){
	return (MAX*rand())/RAND_MAX;
}

int number = 0;
int isPrime(int n){
	for(int i=2;i<=(float)sqrt((float)n);i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

void putPoint(int x,int y){
	int x0 = 0;
	int y0 = 0;

	number++;


	if(isPrime(number)){
		//glColor3f(0.6,0,1);
    glColor3f(0,0.7,1);
    printf("\n%d\t <- prime", number);
  }
	else{
		glColor3f(0,0,0);
    printf("\n%d ", number);
  }
  //sleep(1);
  glPointSize(POINTSIZE);
	glBegin(GL_POINTS);
			glVertex2i(x0+x,y0+y);
	glEnd();
	glFlush();
}
void graphics_draw(void){
	glClear(GL_COLOR_BUFFER_BIT);
	make_axis();
	glColor3f(1,1,1);
  int j=0;
	//number of squares is i
	for(int i=0;i<size;i+=POINTSIZE){
		//int i=5;
		//plot right mid-up of square
		// for(j=0;j<=i;j+=POINTSIZE)
		// 	putPoint(i,j);
		// for(j=i-1;j>=-i;j-=POINTSIZE)
		// 	putPoint(j,i);
		// for(j=i-1;j>=-i;j-=POINTSIZE)
		// 	putPoint(-i,j);
		// for(j=-i+1;j<=i;j+=POINTSIZE)
		// 	putPoint(j,-i);
		// for(j=-i+1;j<0;j+=POINTSIZE)
		// 	putPoint(i,j);

    for(j=0;j<=i;j+=POINTSIZE)
      putPoint(i,j);
    for(j=i;j>=-i;j-=POINTSIZE)
      putPoint(j,i);
    for(j=i;j>=-i;j-=POINTSIZE)
      putPoint(-i,j);
    for(j=-i;j<=i;j+=POINTSIZE)
      putPoint(j,-i);
    for(j=-i;j<=0;j+=POINTSIZE)
      putPoint(i,j);

    //for(j=0;j<50;j++)
    //putPoint(i,j);
	}

	glFlush();
}

int main(int argc, char **argv)
{
  printf("ORTHOGRAPHIC PROJECTIONS OF A RECTANGULAR PYRAMID:\n");

  //make random really random
  srand(time(0));

  printf("\n************************************");


  //printf("%d %d", give_rand(10),give_rand(1000));
  glFlush();
  // Initialise GLUT library
  glutInit(&argc,argv);
  // Set the initial display mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // Set the initial window position and size
  //position means the position of the output screen with r2espect to the monitor screen
  glutInitWindowPosition(0,0);
  glutInitWindowSize(size,size);
  // Create the window with title "DDA_Line"
  glutCreateWindow("Computer Graphics Lab - 115cs0243 | World of Primes");
  // Initialize drawing colors
  Init();
  // Call the displaying function
  glutDisplayFunc(graphics_draw);
  // Keep displaying untill the program is closed
  glutMainLoop();

  return 0;
}
