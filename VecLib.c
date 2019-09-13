#include "VecLib.h"

/* Vector Functions*/
void constructVector(Vec4* vec, const float _x, const float _y, const float _z, const float _w)
{
  vec->x = _x;
  vec->y = _y;
  vec->z = _z;
  vec->w = _w;
}

void printVector(const Vec4* const vec){
  printf("[%f,%f,%f,%f]\n",vec->x,vec->y,vec->z,vec->w);
}
void cross(Vec4* ret, const Vec4* u, const Vec4* v){

  float x = (u->y*v->z - u->z*v->y);
  float y = -1*(u->x*v->z - v->x*u->z);
  float z = (u->x*v->y - u->y*v->x);
  float w = 1;   //wtf do i do for d

  ret->x = x;
  ret->y = y;
  ret->z = z;
  ret->w = w;
}
void dot(float* ret, const Vec4* const u, const Vec4* const v){
  float x = u->x * v->x;
  float y = u->y * v->y;
  float z = u->z * v->z;
  float w = u->w * v->w;

  *ret = x+y+z+w;
}
void scalarMultVec4(Vec4* ret, const Vec4* const u, const float s){
  ret->x = s * u->x;
  ret->y = s * u->y;
  ret->z = s * u->z;
  //ret->w = s * u->w;
}
void addVec4(Vec4* ret, const Vec4* const u, const Vec4* const v){

  Vec4 temp_u;
  Vec4 temp_v;
  copyVec4toVec4(&temp_u,u);
  copyVec4toVec4(&temp_v,v);
  ret->x = temp_u.x + temp_v.x;
  ret->y = temp_u.y + temp_v.y;
  ret->z = temp_u.z + temp_v.z;
  ret->w = temp_u.w + temp_v.w;
}
void subVec4(Vec4* ret, const Vec4* const u, const Vec4* const v){
  Vec4 temp_u;
  Vec4 temp_v;
  copyVec4toVec4(&temp_u,u);
  copyVec4toVec4(&temp_v,v);
  ret->x = temp_u.x - temp_v.x;
  ret->y = temp_u.y - temp_v.y;
  ret->z = temp_u.z - temp_v.z;
  ret->w = temp_u.w - temp_v.w;
  }

void vecSize(float* ret, const Vec4* const vec)
{
  Vec4 temp;
  copyVec4toVec4(&temp,vec);
  float dd;
  dot(ret,&temp,&temp);
  //printf("dot is %f\n",*ret);
  *ret = sqrt(*ret);
  printf("%f\n",*ret);
  
}
void normalize(Vec4* ret, const Vec4* const vec)
{
  Vec4 temp ;
  copyVec4toVec4(&temp,vec);
  float dd;
  dot(&dd,&temp,&temp);
  //printf("dot is %f\n", dd);
  scalarMultVec4(ret,&temp,1.0/sqrt(dd));
}

void constructMatrixFromVec4(Mat4* ret, const Vec4* const _x, const Vec4* const _y, const Vec4* const _z, const Vec4* const _w)
{
  ret->x = *_x;
  ret->y = *_y;
  ret->z = *_z;
  ret->w = *_w;
}


void printMatrix(const Mat4* mat){
  printf("[%f,%f,%f,%f]\n",mat->x.x,mat->y.x,mat->z.x,mat->w.x);
  printf("[%f,%f,%f,%f]\n",mat->x.y,mat->y.y,mat->z.y,mat->w.y);
  printf("[%f,%f,%f,%f]\n",mat->x.z,mat->y.z,mat->z.z,mat->w.z);
  printf("[%f,%f,%f,%f]\n",mat->x.w,mat->y.w,mat->z.w,mat->w.w);
}
void scalarMultMat4(Mat4* ret, const Mat4* const mat, const float s){
  ret->x.x = mat->x.x * s;
  ret->x.y = mat->x.y * s;
  ret->x.z = mat->x.z * s;
  ret->x.w = mat->x.w * s;

  ret->y.x = mat->y.x * s;
  ret->y.y = mat->y.y * s;
  ret->y.z = mat->y.z * s;
  ret->y.w = mat->y.w * s;

  ret->z.x = mat->z.x * s;
  ret->z.y = mat->z.y * s;
  ret->z.z = mat->z.z * s;
  ret->z.w = mat->z.w * s;

  ret->w.x = mat->w.x * s;
  ret->w.y = mat->w.y * s;
  ret->w.z = mat->w.z * s;
  ret->w.w = mat->w.w * s;
}
void addMat4(Mat4* ret, const Mat4* const u, const Mat4* const v){
  ret->x.x = u->x.x + v->x.x;
  ret->x.y = u->x.y + v->x.y;
  ret->x.z = u->x.z + v->x.z;
  ret->x.w = u->x.w + v->x.w;

  ret->y.x = u->y.x + v->y.x;
  ret->y.y = u->y.y + v->y.y;
  ret->y.z = u->y.z + v->y.z;
  ret->y.w = u->y.w + v->y.w;

  ret->z.x = u->z.x + v->z.x;
  ret->z.y = u->z.y + v->z.y;
  ret->z.z = u->z.z + v->z.z;
  ret->z.w = u->z.w + v->z.w;

  ret->w.x = u->w.x + v->w.x;
  ret->w.y = u->w.y + v->w.y;
  ret->w.z = u->w.z + v->w.z;
  ret->w.w = u->w.w + v->w.w;
}
void subMat4(Mat4* ret, const Mat4* const u, const Mat4* const v){
  ret->x.x = u->x.x - v->x.x;
  ret->x.y = u->x.y - v->x.y;
  ret->x.z = u->x.z - v->x.z;
  ret->x.w = u->x.w - v->x.w;

  ret->y.x = u->y.x - v->y.x;
  ret->y.y = u->y.y - v->y.y;
  ret->y.z = u->y.z - v->y.z;
  ret->y.w = u->y.w - v->y.w;

  ret->z.x = u->z.x - v->z.x;
  ret->z.y = u->z.y - v->z.y;
  ret->z.z = u->z.z - v->z.z;
  ret->z.w = u->z.w - v->z.w;

  ret->w.x = u->w.x - v->w.x;
  ret->w.y = u->w.y - v->w.y;
  ret->w.z = u->w.z - v->w.z;
  ret->w.w = u->w.w - v->w.w;
}
void matMult(Mat4* ret, const Mat4* const u, const Mat4* const v){
  
  Mat4 temp_u;
  Mat4 temp_v;
  /* copyMat4toMat4(&temp_u,ret); */
  /* copyMat4toMat4(&temp_v,ret); */
  copyMat4toMat4(&temp_u,u);
  copyMat4toMat4(&temp_v,v);
  
  ret->x.x = (temp_u.x.x * temp_v.x.x) + (temp_u.x.y * temp_v.y.x) + (temp_u.x.z * temp_v.z.x) + (temp_u.x.w * temp_v.w.x);
  ret->x.y = (temp_u.x.x * temp_v.x.y) + (temp_u.x.y * temp_v.y.y) + (temp_u.x.z * temp_v.z.y) + (temp_u.x.w * temp_v.w.y);
  ret->x.z = (temp_u.x.x * temp_v.x.z) + (temp_u.x.y * temp_v.y.z) + (temp_u.x.z * temp_v.z.z) + (temp_u.x.w * temp_v.w.z);
  ret->x.w = (temp_u.x.x * temp_v.x.w) + (temp_u.x.y * temp_v.y.w) + (temp_u.x.z * temp_v.w.z) + (temp_u.x.w * temp_v.w.w);

  ret->y.x = (temp_u.y.x * temp_v.x.x) + (temp_u.y.y * temp_v.y.x) + (temp_u.y.z * temp_v.z.x) + (temp_u.y.w * temp_v.w.x);
  ret->y.y = (temp_u.y.x * temp_v.x.y) + (temp_u.y.y * temp_v.y.y) + (temp_u.y.z * temp_v.z.y) + (temp_u.y.w * temp_v.w.y);
  ret->y.z = (temp_u.y.x * temp_v.x.z) + (temp_u.y.y * temp_v.y.z) + (temp_u.y.z * temp_v.z.z) + (temp_u.y.w * temp_v.w.z);
  ret->y.w = (temp_u.y.x * temp_v.x.w) + (temp_u.y.y * temp_v.y.w) + (temp_u.y.z * temp_v.w.z) + (temp_u.y.w * temp_v.w.w);

  ret->z.x = (temp_u.z.x * temp_v.x.x) + (temp_u.z.y * temp_v.y.x) + (temp_u.z.z * temp_v.z.x) + (temp_u.z.w * temp_v.w.x);
  ret->z.y = (temp_u.z.x * temp_v.x.y) + (temp_u.z.y * temp_v.y.y) + (temp_u.z.z * temp_v.z.y) + (temp_u.z.w * temp_v.w.y);
  ret->z.z = (temp_u.z.x * temp_v.x.z) + (temp_u.z.y * temp_v.y.z) + (temp_u.z.z * temp_v.z.z) + (temp_u.z.w * temp_v.w.z);
  ret->z.w = (temp_u.z.x * temp_v.x.w) + (temp_u.z.y * temp_v.y.w) + (temp_u.z.z * temp_v.w.z) + (temp_u.z.w * temp_v.w.w);

  ret->w.x = (temp_u.w.x * temp_v.x.x) + (temp_u.z.w * temp_v.y.x) + (temp_u.w.z * temp_v.z.x) + (temp_u.w.w * temp_v.w.x);
  ret->w.y = (temp_u.w.x * temp_v.x.y) + (temp_u.z.w * temp_v.y.y) + (temp_u.w.z * temp_v.z.y) + (temp_u.w.w * temp_v.w.y);
  ret->w.z = (temp_u.w.x * temp_v.x.z) + (temp_u.z.w * temp_v.y.z) + (temp_u.w.z * temp_v.z.z) + (temp_u.w.w * temp_v.w.z);
  ret->w.w = (temp_u.w.x * temp_v.x.w) + (temp_u.z.w * temp_v.y.w) + (temp_u.w.z * temp_v.w.z) + (temp_u.w.w * temp_v.w.w);
}
void detMat4(float* det, const Mat4* const mat)
{
  Vec4 w;
  Vec4 u;
  Vec4 v;
  Vec4 c;
  getRowAsVec4(&w,mat,0);
  getRowAsVec4(&u,mat,1);
  getRowAsVec4(&v,mat,2);
  getRowAsVec4(&c,mat,3);

  cross(&c,&u,&v);
  dot(det,&w,&c);
}

int matInv(Mat4* ret, const Mat4* const mat){
  //mother fucker..

  ret->x.x = mat->y.y * mat->z.z * mat->w.w - mat->y.y * mat->z.w * mat->w.z - mat->z.y * mat->y.z * mat->w.w + mat->z.y * mat->y.w * mat->w.z + mat->w.y * mat->y.z * mat->z.w - mat->w.y * mat->y.w * mat->z.z;
  ret->x.y = -mat->x.y * mat->z.z * mat->w.w + mat->x.y * mat->z.w * mat->w.z + mat->z.y * mat->x.z * mat->w.w - mat->z.y * mat->x.w * mat->w.z - mat->w.y * mat->x.z * mat->z.w + mat->w.y * mat->x.w * mat->z.z;
  ret->x.z = mat->x.y * mat->y.z * mat->w.w - mat->x.y * mat->y.w * mat->w.z - mat->y.y * mat->x.z * mat->w.w + mat->y.y * mat->x.w * mat->w.z + mat->w.y * mat->x.z * mat->y.w - mat->w.y * mat->x.w * mat->y.z;
  ret->x.w = -mat->x.y * mat->y.z * mat->z.w + mat->x.y * mat->y.w * mat->z.z + mat->y.y * mat->x.z * mat->z.w - mat->y.y * mat->x.w * mat->z.z - mat->z.y * mat->x.z * mat->y.w + mat->z.y * mat->x.w * mat->y.z;

  ret->y.x = -mat->y.x * mat->z.z * mat->w.w + mat->y.x * mat->z.w * mat->w.z + mat->z.x * mat->y.z * mat->w.w - mat->z.x * mat->y.w * mat->w.z - mat->w.x * mat->y.z * mat->z.w + mat->w.x * mat->y.w * mat->z.z;
  ret->y.y = mat->x.x * mat->z.z * mat->w.w - mat->x.x * mat->z.w * mat->w.z - mat->z.x * mat->x.z * mat->w.w + mat->z.x * mat->x.w * mat->w.z + mat->w.x * mat->x.z * mat->z.w - mat->w.x * mat->x.w * mat->z.z;
  ret->y.z = -mat->x.x * mat->y.z * mat->w.w + mat->x.x * mat->y.w * mat->w.z + mat->y.x * mat->x.z * mat->w.w - mat->y.x * mat->x.w * mat->w.z - mat->w.x * mat->x.z * mat->y.w + mat->w.x * mat->x.w * mat->y.z;
  ret->y.w = mat->x.x * mat->y.z * mat->z.w - mat->x.x * mat->y.w * mat->z.z - mat->y.x * mat->x.z * mat->z.w + mat->y.x * mat->x.w * mat->z.z + mat->z.x * mat->x.z * mat->y.w - mat->z.x * mat->x.w * mat->y.z;

  ret->z.x = mat->y.x * mat->z.y * mat->w.w - mat->y.x * mat->z.w * mat->w.y - mat->z.x * mat->y.y * mat->w.w + mat->z.x * mat->y.w * mat->w.y + mat->w.x * mat->y.y * mat->z.w - mat->w.x * mat->y.w * mat->z.y;
  ret->z.y = -mat->x.x * mat->z.y * mat->w.w + mat->x.x * mat->z.w * mat->w.y + mat->z.x * mat->x.y * mat->w.w - mat->z.x * mat->x.w * mat->w.y - mat->w.x * mat->x.y * mat->z.w + mat->w.x * mat->x.w * mat->z.y;
  ret->z.z = mat->x.x * mat->y.y * mat->w.w - mat->x.x * mat->y.w * mat->w.y - mat->y.x * mat->x.y * mat->w.w + mat->y.x * mat->x.w * mat->w.y + mat->w.x * mat->x.y * mat->y.w - mat->w.x * mat->x.w * mat->y.y;
  ret->z.w = -mat->x.x * mat->y.y * mat->z.w + mat->x.x * mat->y.w * mat->z.y + mat->y.x * mat->x.y * mat->z.w - mat->y.x * mat->x.w * mat->z.y - mat->z.x * mat->x.y * mat->y.w + mat->z.x * mat->x.w * mat->y.y;

  ret->w.x = -mat->y.x * mat->z.y * mat->w.z + mat->y.x * mat->z.z * mat->w.y + mat->z.x * mat->y.y * mat->w.z - mat->z.x * mat->y.z * mat->w.y - mat->w.x * mat->y.y * mat->z.z + mat->w.x * mat->y.z * mat->z.y;
  ret->w.y = mat->x.x * mat->z.y * mat->w.z - mat->x.x * mat->z.z * mat->w.y - mat->z.x * mat->x.y * mat->w.z + mat->z.x * mat->x.z * mat->w.y + mat->w.x * mat->x.y * mat->z.z - mat->w.x * mat->x.z * mat->z.y;
  ret->w.z = -mat->x.x * mat->y.y * mat->w.z + mat->x.x * mat->y.z * mat->w.y + mat->y.x * mat->x.y * mat->w.z - mat->y.x * mat->x.z * mat->w.y - mat->w.x * mat->x.y * mat->y.z + mat->w.x * mat->x.z * mat->y.y;
  ret->w.w = mat->x.x * mat->y.y * mat->z.z - mat->x.x * mat->y.z * mat->z.y - mat->y.x * mat->x.y * mat->z.z + mat->y.x * mat->x.z * mat->z.y + mat->z.x * mat->x.y * mat->y.z - mat->z.x * mat->x.z * mat->y.y;

  /*no point in redoing the det */
  float d = mat->x.x * ret->x.x + mat->x.y * ret->y.x + mat->x.z * ret->z.x + mat->x.w * ret->w.x;

  if (d == 0)
    {
      return 0;
    }
  d = 1.0 / d;
  scalarMultMat4(ret,ret,d);
  return 1;
}

void matTranspose(Mat4* ret, const Mat4* const mat){
  /*
    You have to have a temp here to make sure you dont cyclically write over something
  */

  Mat4 temp;
  copyMat4toMat4(&temp,mat);

  ret->x.x = temp.x.x;
  ret->x.y = temp.y.x;
  ret->x.z = temp.z.x;
  ret->x.w = temp.w.x;

  ret->y.x = temp.x.y;
  ret->y.y = temp.y.y;
  ret->y.z = temp.z.y;
  ret->y.w = temp.w.y;

  ret->z.x = temp.x.z;
  ret->z.y = temp.y.z;
  ret->z.z = temp.z.z;
  ret->z.w = temp.w.z;

  ret->w.x = temp.x.w;
  ret->w.y = temp.y.w;
  ret->w.z = temp.z.w;
  ret->w.w = temp.w.w;
}

void getRowAsVec4(Vec4* ret, const Mat4* const mat, const int row){
  if (row == 0)
    {
      ret->x = mat->x.x;
      ret->y = mat->y.x;
      ret->z = mat->z.x;
      ret->w = mat->w.x;
    }
  else if (row == 1)
    {
      ret->x = mat->x.y;
      ret->y = mat->y.y;
      ret->z = mat->z.y;
      ret->w = mat->w.y;
    }
  else if (row == 2)
    {
      ret->x = mat->x.z;
      ret->y = mat->y.z;
      ret->z = mat->z.z;
      ret->w = mat->w.z;
    }
  else if (row == 3)
    {
      ret->x = mat->x.w;
      ret->y = mat->y.w;
      ret->z = mat->z.w;
      ret->w = mat->w.w;
    }
}
void copyVec4toVec4(Vec4* ret, const Vec4* const vec)
{
  ret->x = vec->x;
  ret->y = vec->y;
  ret->z = vec->z;
  ret->w = vec->w;
}
/*Copies mat into ret */
void copyMat4toMat4(Mat4* ret, const Mat4* const mat)
{
  ret->x.x = mat->x.x;
  ret->x.y = mat->x.y;
  ret->x.z = mat->x.z;
  ret->x.w = mat->x.w;

  ret->y.x = mat->y.x;
  ret->y.y = mat->y.y;
  ret->y.z = mat->y.z;
  ret->y.w = mat->y.w;

  ret->z.x = mat->z.x;
  ret->z.y = mat->z.y;
  ret->z.z = mat->z.z;
  ret->z.w = mat->z.w;

  ret->w.x = mat->w.x;
  ret->w.y = mat->w.y;
  ret->w.z = mat->w.z;
  ret->w.w = mat->w.w;
}

void Mat4MultVec4(Vec4* ret, const Vec4* const vec, const Mat4* const mat) //todo
{
  
  Vec4 temp;
  temp.x = vec->x;
  temp.y = vec->y;
  temp.z = vec->z;
  temp.w = vec->w;
  

  Vec4 r1,r2,r3,r4;
  getRowAsVec4(&r1,mat,0);
  getRowAsVec4(&r2,mat,1);
  getRowAsVec4(&r3,mat,2);
  getRowAsVec4(&r4,mat,3);
  
  dot(&(ret->x), &temp, &r1);
  dot(&(ret->y), &temp, &r2);
  dot(&(ret->z), &temp, &r3);
  dot(&(ret->w), &temp, &r4);
}
void translatePoint(Vec4* ret, const Vec4* const vec, const Mat4* const mat)
{
  Vec4 temp;
  temp.x = vec->x;
  temp.y = vec->y;
  temp.z = vec->z;
  temp.w = vec->w;
  printMatrix(mat);
  
  ret->x = temp.x + mat->w.x;
  ret->y = temp.y + mat->w.y;
  ret->z = temp.z + mat->w.z;
  ret->w = temp.w + mat->w.w;
}

void rotateX(Mat4* ret, const double degree)
{
  Mat4 rotX = {{1,0,0,0},
	       {0,cos(degree),sin(degree),0},
	       {0,-1*sin(degree),cos(degree),0},
	       {0,0,0,1}};
  matMult(ret,ret,&rotX);
}

void rotateY(Mat4* ret, const double degree)
{
  Mat4 rotY = {{cos(degree),0,sin(degree),0},
	       {0,1,0,0},
	       {-1*sin(degree),0,cos(degree),0},
	       {0,0,0,1}};
  matMult(ret,ret,&rotY);
  
}
void rotateZ(Mat4* ret, const double degree)
{
  Mat4 rotZ = {{cos(degree),-1*sin(degree),0,0},
	       {sin(degree),cos(degree),0,0},
	       {0,0,1,0},
	       {0,0,0,1}};
  matMult(ret,ret,&rotZ);
}

void Scale(Mat4* ret, const double x, const double y, const double z)
{
  //  printMatrix(ret);
  Mat4 mat = {{x,0,0,0},
      {0,y,0,0},
      {0,0,z,0},
      {0,0,0,1}};

  matMult(ret, ret, &mat);
}

void addMatrix(Mat4* ret, const Mat4* const mat1, const Mat4* const mat2)
{
  Mat4* u;
  Mat4* v;
  copyMat4toMat4(u,mat1);
  copyMat4toMat4(v,mat2);

  ret->x.x = u->x.x + v->x.x;
  ret->x.y = u->x.y + v->x.y;
  ret->x.z = u->x.z + v->x.z;
  ret->x.w = u->x.w + v->x.w;

  ret->y.x = u->y.x + v->y.x;
  ret->y.y = u->y.y + v->y.y;
  ret->y.z = u->y.z + v->y.z;
  ret->y.w = u->y.w + v->y.w;

  ret->z.x = u->z.x + v->z.x;
  ret->z.y = u->z.y + v->z.y;
  ret->z.z = u->z.z + v->z.z;
  ret->z.w = u->z.w + v->z.w;

  ret->w.x = u->w.x + v->w.x;
  ret->w.y = u->w.y + v->w.y;
  ret->w.z = u->w.z + v->w.z;
  ret->w.w = u->w.w + v->w.w;

  
}

