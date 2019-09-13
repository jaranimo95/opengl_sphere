#ifndef _VecLib_
#define _VecLib_

#include <stdio.h>
#include <math.h>

typedef struct Vec4
{
  float x;
  float y;
  float z;
  float w;
} Vec4;

typedef struct Mat4
{
  Vec4 x;
  Vec4 y;
  Vec4 z;
  Vec4 w;
} Mat4;

/* For refrence this is what a mat looks like 
    X      Y      Z      W   
   +-----------------------+
0  | x.x | y.x | z.x | w.x |
   |-----+-----+-----+-----|
1  | x.y | y.y | z.y | w.y |
   |-----+-----+-----+-----|
2  | x.z | y.z | z.z | w.z |
   |-----+-----+_----+-----|
3  | x.w | y.w | z.w | w.w |
   +-----------------------+
*/

/* Vector Functions*/
void constructVector(Vec4* vec, const float _x, const float _y, const float _z, const float _w);
void printVector(const Vec4* const vec);
void cross(Vec4* ret, const Vec4* const u, const Vec4* const v);
void dot(float* dot, const Vec4* const u, const Vec4* const v);
void scalarMultVec4(Vec4* ret, const Vec4* const u, const float factor);
void addVec4(Vec4* ret, const Vec4* const u, const Vec4* const v);
void subVec4(Vec4* ret, const Vec4* const u, const Vec4* const v);
void vecSize(float* ret, const Vec4* const vec);
void normalize(Vec4* ret, const Vec4* const vec);

/* Matrix Functions*/
void constructMatrixFromVec4(Mat4* ret, const Vec4* const _x, const Vec4* const _y, const Vec4* const _z, const Vec4* const _w);
void printMatrix(const Mat4* const mat);
void scalarMultMat4(Mat4* ret, const Mat4* const mat, const float s);
void addMat4(Mat4* ret, const Mat4* const u, const Mat4* const v);
void subMat4(Mat4* ret, const Mat4* const u, const Mat4* const v);
void matMult(Mat4* ret, const Mat4* const u, const Mat4* const v);
int matInv(Mat4* ret, const Mat4* const mat);
void matTranspose(Mat4* ret, const Mat4* const mat);
void getRowAsVec4(Vec4* ret, const Mat4* const mat, const int row);
void detMat4(float* det, const Mat4* const mat);
void copyMat4toMat4(Mat4* ret, const Mat4* const mat);
void copyVec4toVec4(Vec4* ret, const Vec4* const vec);

void Mat4MultVec4(Vec4* ret, const Vec4* const vec, const Mat4* const mat); //todo
void translatePoint(Vec4* ret, const Vec4* const vec, const Mat4* const mat);

//void rotateX(Vec4* ret, const Vec4* const vec, const double degree);

void rotateX(Mat4* ret, const double degree);
void rotateY(Mat4* ret, const double degree);
void rotateZ(Mat4* ret, const double degree);

//void Scale(Vec4* ret, const Vec4* const vec, const double x, const double y, const double z);
void Scale(Mat4* ret, const double x, const double y, const double z);
void addMatrix(Mat4* ret, const Mat4* const mat1, const Mat4* const mat2);
#endif

