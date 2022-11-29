// Online C compiler to run C program online
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define MAX(x, y) (x > y) ? TRUE : FALSE
#define MIN(x, y) (x < y) ? TRUE : FALSE
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define SIZEN 6
#define SIZEM 7
#define TYP unsigned short

//------------------------------------------------------------
//                      submatrixAreaByCorners
//                      ---------
// General : The function calculates the area between two values(corners of
// subMatrix) in an ascending sorted matrix;
//
// Parameters :
// matix - matrix (In)
// fCorner- corner value(In)
// sCorner-corner value(In)
//
// Return Value : the area
// -----------------------------------------------------------
short submatrixAreaByCorners(unsigned short mat[SIZEN][SIZEM],
                             unsigned short fCorner, unsigned short sCorner) {
  unsigned short length, width, area, offset, flag = 0;
  offset = mat[SIZEN - 1][SIZEM - 1];
  length = ((sCorner - fCorner) / SIZEM) + 1;
  width = (sCorner % SIZEM) - (fCorner % SIZEM) + 1;
  flag += MAX(fCorner, offset);
  flag += MAX(sCorner, offset);
  area = EQUAL(flag, 0) ? width * length : -1;
  return area;
}
//------------------------------------------------------------
//                      submatrixAreaByCorners
//                      ---------
// General :  The function gets two pairs of subarea corners and prints the
// largest area with its corners.
//
// Parameters :
// matix - matrix (In)
// fCornerOne- corner value(In)
// sCornerOne-corner value(In)
// fCornerTwo- corner value(In)
// sCornerTwo-corner value(In)
//
// Return Value : NONE
// -----------------------------------------------------------
void subAreaBigger(unsigned short mat[SIZEN][SIZEM], unsigned short fCornerOne,
                   unsigned short sCornerOne, short fCornerTwo,
                   unsigned short sCornerTwo) {
  unsigned short areaOne, areaTwo, biggerArea, biggerFCorner, biggerSCorner;
  areaOne = submatrixAreaByCorners(mat, fCornerOne, sCornerOne);
  areaTwo = submatrixAreaByCorners(mat, fCornerTwo, sCornerTwo);
  biggerArea = (MAX(areaOne, areaTwo)) ? areaOne : areaTwo;
  biggerFCorner = (MAX(areaOne, areaTwo)) ? fCornerOne : fCornerTwo;
  biggerSCorner = (MAX(areaOne, areaTwo)) ? sCornerOne : sCornerTwo;
  printf("%d,%dand the area is:%d", biggerFCorner, biggerSCorner, biggerArea);
}

int main() {

  TYP mat2[SIZEN][SIZEM] = {0};
  subAreaBigger(mat2, 11, 34, 0, 41);
  return 0;
}