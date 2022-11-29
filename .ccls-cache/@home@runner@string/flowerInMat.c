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
#define SIZE 4
#define FLOWERSIZE 3
#define SIZEDIFFERENCE SIZE - FLOWERSIZE
#define TYP unsigned short
//----------------------GENERAL FUNCS--------------------------

// get matrix and row retun sum of row
unsigned short sumArray(TYP mat[][SIZE - (SIZEDIFFERENCE)],
                        unsigned short row) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE - (SIZEDIFFERENCE);
       sum += mat[row][offset], offset++)
    ;
  return sum;
}

// get matrix and retun sum
unsigned short sumMat(TYP mat[][SIZE - (SIZEDIFFERENCE)]) {
  unsigned short offset, sum = 0;
  for (offset = 0; offset < SIZE - (SIZEDIFFERENCE); offset++) {
    sum += sumArray(mat, offset);
  }
  return sum;
}

void printArray(TYP mat[][SIZE - (SIZEDIFFERENCE)], unsigned short row) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE - (SIZEDIFFERENCE);
       printf("%d ", mat[row][offset]), offset++)
    ;
  printf("\n");
}

// get matrix and print it
void printMat(TYP mat[][SIZE - (SIZEDIFFERENCE)]) {
  unsigned short offset, sum = 0;
  for (offset = 0; offset < SIZE - (SIZEDIFFERENCE); printArray(mat, offset++))
    ;
}

// get matrix , row,start of SubArray ,range SubArray and retun sum of subrow
void cutSubArray(TYP mat[][SIZE], TYP newMat[3][3], unsigned short row,
                 unsigned short newRow, unsigned short column,
                 unsigned short range) {
  unsigned short offset;
  for (offset = column; offset < column + range; offset++) {
    newMat[newRow][offset - column] = mat[row][offset];
  }
}

void cutSubMat(TYP mat[][SIZE], TYP newMat[3][3], unsigned short row,
               unsigned short column, unsigned short range) {
  unsigned short offset, sum = 0;
  for (offset = row; offset < row + range; offset++) {
    cutSubArray(mat, newMat, offset, offset - row, column, 3);
  }
}

//-------------------------TASK FUNCS-------------------------

//-------------------------------------------------------------
//                      isFlower
//                      ---------
// General : The function calculates if the value of the middle of the matrix
// equal to the sum of the corner values
//
// Parameters :
// matix - matrix (In)
// sum- corner values(In)
// middle-the value of the middle of the matrix(In)
//
// Return Value : if sum equal middle
// ------------------------------------------------------------
TYP isFlower(TYP mat[3][3]) {
  unsigned short middle = mat[1][1], sum = 0;
  sum += sumArray(mat, 0) - mat[0][1];
  sum += sumArray(mat, 2) - mat[2][1];
  return EQUAL(middle, sum);
}

// get matrix and print it
unsigned short howManyFlowersInArray(TYP mat[][SIZE], unsigned short row) {
  TYP newmat[3][3];
  unsigned short offset, sum = 0;
  for (offset = 1; offset < SIZE - 1; offset++) {

    cutSubMat(mat, newmat, row - 1, offset - 1, 3);
    sum += isFlower(newmat);
  }
  return sum;
}
// get matrix and print it
unsigned short howManyFlowers(TYP mat[][SIZE]) {
  unsigned short offset, sum = 0;
  for (offset = 1; offset < SIZE - 1; offset++) {
    sum += howManyFlowersInArray(mat, offset);
  }
  return sum;
}

bool isMatFloral(TYP mat[][SIZE]) { return MAX(howManyFlowers(mat), 5); }

//------------------------------------------------------------
//                      sumOfAllDiagonals
//                      ---------
// General : The function calculates the sum of all the diagonals in matrix
//
// Parameters :
// matix - matrix (In)
// sum- sum of the diagonals(out)
//
// Return Value : The result of sum
// -----------------------------------------------------------
int main() {
  TYP mat[][SIZE] = {{1, 9, 3, 1}, {3, 10, 15, 1}, {0, 24, 6, 1}, {4, 8, 2, 1}};
  TYP mat1[][3] = {
      {1, 9, 3},
      {3, 8, 7},
      {-2, 4, 6},
  };
  TYP mat2[3][3];
  // sumSubMat(mat,mat2,1,1,1);
  // cutSubMat(mat,mat2,0,0,3);
  // printMat(mat2);
  // howManyFlowersInArray(mat,1);
  printf("%d", isMatFloral(mat));

  // printf("%d",isFlowerByNeighbors(sumOfNeighbors(mat,1,1)));

  return 0;
}