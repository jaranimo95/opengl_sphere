#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>
#include "initShader.h"
#include "VecLib.h"



GLuint ctm_location;
Mat4 tr_matrix =
  {{1.0, 0.0, 0.0, 0.0},
   {0.0, 1.0, 0.0, 0.0},
   {0.0, 0.0, 1.0, 0.0},
   {0.0, 0.0, 0.0, 1.0}};

const Vec4 Ix = {1,0,0,0};
const Vec4 Iy = {0,1,0,0};
const Vec4 Iz = {0,0,1,0};


#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

void genColors();
void createSphereVertices();
void unProjectScreenCoord(int x, int y, Vec4* point);
void getRotMatrix(Mat4* ret, Vec4* v1, Vec4* v2);


Vec4 vertices[342];
Vec4 colors[342];

int num_vertices = 342;

//mouse screen coords
Vec4 origin = {0,0,0,-1};
Vec4 msc = {-1,-1,0,0};

void init(void)
{
  genColors();
  createSphereVertices();

  //int bound = 342;

  GLuint program = initShader("vshader.glsl", "fshader.glsl");
  glUseProgram(program);

  GLuint vao;
  glGenVertexArraysAPPLE(1, &vao);
  glBindVertexArrayAPPLE(vao);

  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_DYNAMIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

  GLuint vPosition = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(vPosition);
  glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vec4), BUFFER_OFFSET(0));

  GLuint vColor = glGetAttribLocation(program, "vColor");
  glEnableVertexAttribArray(vColor);
  glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) sizeof(vertices));

  ctm_location = glGetUniformLocation(program, "ctm");

  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glDepthRange(1,0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUniformMatrix4fv(ctm_location, 1, GL_FALSE, (GLfloat *) &tr_matrix);

  glPolygonMode(GL_FRONT, GL_FILL);
  glPolygonMode(GL_BACK, GL_LINE);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, num_vertices);

  glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
  if (state == GLUT_UP)
    {
      if (button == 3)
        {
          Scale(&tr_matrix,1.2,1.2,1.2);
        }
      else if (button == 4)
        {
          Scale(&tr_matrix,.8,.8,.8);
        }
    }
    if (state == GLUT_DOWN)
    {
      if (button == GLUT_LEFT_BUTTON)
        {
	  //msc
	  Vec4 point;
	  unProjectScreenCoord(x,y,&point);
	  printVector(&point);


	  
	  /* printf("\n"); */
	  /* Vec4 v1; */
	  /* subVec4(&v1,&point,&msc); */

	  /* Vec4 v2; */
	  /* subVec4(&v2,&origin,&point); */

	  /* /\* printf("MSC and Point\n"); *\/ */
	  /* /\* printVector(&msc); *\/ */
	  /* /\* printVector(&point); *\/ */

	  /* /\* printf("v1 v2\n"); *\/ */
	  /* /\* printVector(&v1); *\/ */
	  /* /\* printVector(&v2); *\/ */
	  /* /\* printf("\n"); *\/ */

	  /* normalize(&v1,&v1); */
	  /* normalize(&v2,&v2); */

	  /* float t; */
	  /* vecSize(&t,&v1); */
	  /* vecSize(&t,&v2); */

	  /* Vec4 n; */
	  /* cross(&n,&v1,&v2); */
	  /* normalize(&n,&n); */
	  /* printVector(&n); */


	  
	  /* float d; */
	  /* dot(&d, &v1,&v2); */
	  /* d = acos(d); */
	  /* printf("angle is %f\n",d); */
  

	  msc = point;
	}
}

  /* Handle rotation*/


	init();
  glutPostRedisplay();
}

void keyboard(unsigned char key, int mousex, int mousey)
{
  if(key == 'q')
    exit(0);

  if (key == '+')
    {
      Scale(&tr_matrix,1.2,1.2,1.2);
    }
  if (key == '-')
    {
      Scale(&tr_matrix,.8,.8,.8);
    }

  if (key == 't')
    {
      rotateX(&tr_matrix,M_PI/8);
    }
  if (key == 'y')
    {
      rotateX(&tr_matrix,-M_PI/8);
    }

  if (key == 'u')
    {
      rotateY(&tr_matrix,M_PI/8);
    }
  if (key == 'i')
    {
      rotateY(&tr_matrix,-M_PI/8);
    }

  if (key == 'o')
    {
      rotateZ(&tr_matrix,M_PI/8);
    }
  if (key == 'p')
    {
      rotateZ(&tr_matrix,-M_PI/8);
    }
	
	init();
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  //Vec4 x = {1,2,3,4};
  //Vec4 y = {1,2,3,4};
  //Vec4 z = {1,2,3,4};
  //Vec4 w = {9,9,9,0};
  //Mat4 i = {x,y,z,w};

  //Vec4 temp = {5,19,0,0};
  //vecSize(&temp,&temp);
  //normalize(&temp,&temp);
  //printVector(&temp);

  //return;

  /* printVector(&temp); */
  /* Scale(&temp,&temp,1.2,1.2,1.2); */
  /* printVector(&temp); */

  /* rotateZ(&temp,&temp,M_PI/2); */
  /* printVector(&temp); */
  /* rotateY(&temp,&temp,M_PI/2); */
  /* printVector(&temp); */
  /* rotateX(&temp,&temp,M_PI/2); */
  /* printVector(&temp); */

  //Mat4MultVec4(&temp,&tempp,&i);
  /* printMatrix(&i); */
  //translatePoint(&temp,&temp,&i);

  //return 0;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(512, 512);
  //glutInitWindowPosition(100,100);
  glutCreateWindow("Model Viewer");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();

  return 0;
}

void createSphereVertices()
{
  const float DegreesToRadians = M_PI / 180.0; // M_PI = 3.14159...
  //  Vec4 vertices[342]; // 8 rows of 18 quads
  int k = 0;
  for(float phi = -80.0; phi <= 80.0; phi += 20.0)
    {
      float phir = phi*DegreesToRadians;
      float phir20 = (phi + 20.0)*DegreesToRadians;
      for(float theta = -180.0; theta <= 180.0; theta += 20.0)
        {
          float thetar = theta*DegreesToRadians;
          Vec4 temp;
          temp.x = sin(thetar)*cos(phir);
          temp.y = cos(thetar)*cos(phir);
          temp.z = sin(phir);
          vertices[k] = temp;
          k++;
          temp.x = sin(thetar)*cos(phir20);
          temp.y = cos(thetar)*cos(phir20);
          temp.z =sin(phir20);
          vertices[k] = temp;
          k++;
        }
    }
}
void genColors()
{
  for (int i = 0; i < 342; i++)
    {
      float r = 0 + rand() % 100;
      r*=.01;
      float g = 0 + rand() % 100;
      g*=.01;
      float b = 0 + rand() % 100;
      b*=.01;

      //printf("rand %f\n",r);
      colors[i].x = r;
      colors[i].y = g;
      colors[i].z = b;
      colors[i].w = 1;
    }
}
void getRotMatrix(Mat4* ret, Vec4* v1, Vec4* v2)
{
  Vec4 n;
  cross(&n,v1,v2);
  normalize(&n,&n);

  Mat4 k = {{0,-1*n.z,n.y,0},
			{n.z,0,-1*n.x,0},
			{-n.y,n.x,0,0},
			{0,0,0,0}};

  Mat4 i = {{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,0}};

  normalize(v1,v1);
  normalize(v2,v2);

  float d;
  dot(&d,v1,v2);
  float theta = acos(d);

  Mat4 sinThetaK;
  scalarMultMat4(&sinThetaK, &k, sin(theta));

  Mat4 ksquared;
  matMult(&ksquared,&k,&k);
  scalarMultMat4(&ksquared, &ksquared, (1-cos(theta)));
  
  Mat4* rot;
  addMatrix(rot, &i, &sinThetaK);
  addMatrix(rot, rot, &ksquared);;

}

void unProjectScreenCoord(int x, int y, Vec4* point)
{
  int viewport[4];
  double modelview[16];
  double projection[16];
  float winX, winY, winZ;
  double posX, posY, posZ;

  glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
  glGetDoublev( GL_PROJECTION_MATRIX, projection );
  glGetIntegerv( GL_VIEWPORT, viewport );

  winX = (float)x;
  winY = (float)viewport[3] - (float)y;
  glReadBuffer(GL_COLOR_ATTACHMENT0);
  glReadPixels(x , (int)(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
  glReadBuffer(GL_BACK);
  
  gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
  float newz = sqrt(1-pow(posX,2)-pow(posY,2));

  posZ = newz;
  if (posZ != posZ)
  {
      posZ = 0;
  }
  point->x = posX;
  point->y = posY;
  point->z = posZ;
  point->w = 1;
  //printf("%f %f %f \n",posX,posY,posZ);
  
}
