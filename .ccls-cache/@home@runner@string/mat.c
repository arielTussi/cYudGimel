// Online C compiler to run C program online
#include <stdio.h>
#define NUMOFLETTERS 26
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define ADDSCOPE 0
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define TYP unsigned short
#define SIZE 3
// ------------------------general func-----------------------
// get matrix and row retun sum of row
unsigned short sumArray(TYP mat[][SIZE], unsigned short row) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE; sum += mat[row][offset], offset++)
    ;
  return sum;
}

// get matrix and row print row
void printArray(TYP mat[][SIZE + ADDSCOPE], unsigned short row) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE + ADDSCOPE;
       printf("%d ", mat[row][offset]), offset++)
    ;
  printf("\n");
}
// get matrix , row and num return if num is in row
bool isInArray(TYP mat[][SIZE], unsigned short row, TYP num) {
  unsigned short offset, counter = 0;
  for (offset = 0; offset < SIZE; offset++) {
    counter += EQUAL(mat[row][offset], num);
  }
  return POSITIVE(counter);
}
// get matrix , row and num return sum of appearance in row
unsigned short appearanceInArray(TYP mat[][SIZE], unsigned short row, TYP num) {
  unsigned short offset, counter = 0;
  for (offset = 0; offset < SIZE; offset++) {
    counter += EQUAL(mat[row][offset], num);
  }
  return counter;
}
// get matrix ,row and num return index of first appearance in row
short placeInArray(TYP mat[][SIZE], unsigned short row, TYP num) {
  unsigned short offset = 0, index = 0, flag = 0;
  while (offset < SIZE && !index) {
    index = (EQUAL(mat[row][offset], num) ? offset + 1 : 0);
    offset++;
  }
  return index - 1;
}
// get matrix , row  return max value in row
unsigned short maxValueArray(TYP mat[][SIZE], unsigned short row) {
  unsigned short bigger = mat[row][0], offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    bigger = MAX(mat[row][offset], bigger);
  }
  return bigger;
}
// get matrix , row  return min value in row
unsigned short minValueArray(TYP mat[][SIZE], unsigned short row) {
  unsigned short smaller = mat[row][0], offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    smaller = MIN(mat[row][offset], smaller);
  }
  return smaller;
}

// get matrix , row,start of SubArray ,range SubArray and retun sum of subrow
unsigned short sumSubArray(TYP mat[][SIZE + ADDSCOPE], unsigned short row,
                           unsigned short start, unsigned short range) {
  unsigned short offset, sum = 0;
  for (offset = start; offset < start + range;
       sum += mat[row][offset], offset++)
    ;
  return sum;
}

// get matrix , new matrix full in 0 bigger in 2 and row, insert data of old
// into new line
void addNullInSidesArray(TYP mat[][SIZE], TYP NewMat[][SIZE + ADDSCOPE],
                         unsigned short row) {
  unsigned short sum = 0, offset = 0;
  for (offset = 1; offset < SIZE + 1; offset++) {
    NewMat[row][offset] = mat[row - 1][offset - 1];
  }
}

// --------------------------funcs----------------------
// get matrix and retun sum
unsigned short sumMat(TYP mat[][SIZE]) {
  unsigned short offset, sum = 0;
  for (offset = 0; offset < SIZE; offset++) {
    sum += sumArray(mat, offset);
  }
  return sum;
}
// get matrix and print it
void printMat(TYP mat[][SIZE + ADDSCOPE]) {
  unsigned short offset, sum = 0;
  for (offset = 0; offset < SIZE + ADDSCOPE; offset++) {
    printArray(mat, offset);
  }
}

// get matrix and num return if num is in mat
bool isInMat(TYP mat[][SIZE], TYP num) {
  unsigned short offset, counter = 0;
  for (offset = 0; offset < SIZE; offset++) {
    counter += isInArray(mat, offset, num);
  }
  return POSITIVE(counter);
}

// get matrix  and num return sum of appearance in mat
unsigned short appearanceInMat(TYP mat[][SIZE], TYP num) {
  unsigned short offset, counter = 0;
  for (offset = 0; offset < SIZE; offset++) {
    counter += appearanceInArray(mat, offset, num);
  }
  return counter;
}

// get matrix , num ,empty place[0][0] ,change it to place[row of num][column of
// num]
void placeInMat(TYP mat[][SIZE], unsigned short place[1], TYP num) {
  unsigned short offset = 0, counter = 0, index = 0;
  while (offset < SIZE && !index) {
    index = (isInArray(mat, offset, num) ? offset + 1 : 0);
    offset++;
  }
  place[0] = placeInArray(mat, index - 1, num);
  place[1] = index - 1;
}
// get matrix  return max value in mat
unsigned short maxValueMat(TYP mat[][SIZE]) {
  unsigned short bigger = maxValueArray(mat, 0), offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    bigger = MAX(maxValueArray(mat, offset), bigger);
  }
  return bigger;
}
// get matrix  return min value in mat
unsigned short minValueMat(TYP mat[][SIZE]) {
  unsigned short smaller = minValueArray(mat, 0), offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    smaller = MIN(minValueArray(mat, offset), smaller);
  }
  return smaller;
}
// get matrix  return sum of main Diagonal
unsigned short sumMainDiagonal(TYP mat[][SIZE]) {
  unsigned short sum = 0, offset = 0;
  for (offset = 0; offset < SIZE; offset++) {
    sum += mat[offset][offset];
  }
  return sum;
}
// get matrix  return sum of seconed Diagonal
unsigned short sumSecDiagonal(TYP mat[][SIZE]) {
  unsigned short sum = 0, offset = 0;
  for (offset = 0; offset < SIZE; offset++) {
    sum += mat[offset][SIZE - offset - 1];
  }
  return sum;
}
// get matrix  return if sum of seconed Diagonal equal main Diagonal
bool sumSecAndMainDiagonalEqual(TYP mat[][SIZE]) {
  return EQUAL(sumSecDiagonal(mat), sumMainDiagonal(mat));
}

// get matrix  return if seconed Diagonal equal main Diagonal
bool SecAndMainDiagonalEqual(TYP mat[][SIZE]) {
  unsigned short flag = 0, offset = 0;
  for (offset = 0; offset < SIZE; offset++) {
    flag += NOTEQUAL(mat[offset][SIZE - offset - 1], mat[offset][offset]);
  }
  return EQUAL(flag, 0);
}

// get matrix, row and column of submatrix,range of substring and retun sum of
// submatrix
unsigned short sumSubMat(TYP mat[][SIZE + ADDSCOPE], unsigned short start,
                         unsigned short end, unsigned short range) {
  unsigned short offset, sum = 0;
  for (offset = start; offset < start + range; offset++) {
    sum += sumSubArray(mat, offset, end, range);
  }
  return sum;
}

// get matrix  return sum Scope
unsigned short sumMatScope(TYP mat[][SIZE]) {
  return sumMat(mat) - sumSubMat(mat, 1, 1, SIZE - 2);
}

// get matrix , new matrix full in 0 bigger in 2  insert data of old into new
// mat
void addNullScope(TYP mat[][SIZE], TYP NewMat[][SIZE + ADDSCOPE]) {
  unsigned short offset = 0;
  for (offset = 1; offset < SIZE + 1; offset++) {
    addNullInSidesArray(mat, NewMat, offset);
  }
}

// get matrix , row, column of place and return sum of Neighbors
unsigned short sumOfNeighbors(TYP mat[][SIZE], unsigned short row,
                              unsigned short column) {
  TYP Newmat[SIZE + ADDSCOPE][SIZE + ADDSCOPE] = {0};
  addNullScope(mat, Newmat);
  return sumSubMat(Newmat, row, column, 3) - mat[row][column];
}

// לתקן
// get matrix ,empty place[0][0] ,change it to place[row of
// MAX sum of Neighbors][column of MAX sum of Neighbors]
void placeMaxSumNeighbors(TYP mat[][SIZE], unsigned short place[1], TYP num) {
  unsigned short offset = 0, counter = 0, index = 0;

  place[0] = placeInArray(mat, index - 1, num);
  place[1] = index - 1;
}

// get matrix and column retun sum of column
unsigned short sumColumn(TYP mat[][SIZE], unsigned short column) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE; sum += mat[offset][column], offset++)
    ;
  return sum;
}

// get matrix , column  return max sum column
unsigned short maxSumColumn(TYP mat[][SIZE], unsigned short column) {
  unsigned short bigger = sumColumn(mat, 0), offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    bigger = MAX(sumColumn(mat, offset), bigger);
  }
  return bigger;
}
// get matrix , column  return min sum column
unsigned short minValueArray(TYP mat[][SIZE], unsigned short column) {
  unsigned short smaller = sumColumn(mat, 0), offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    smaller = MIN(sumColumn(mat, offset), smaller);
  }
  return smaller;
}

// get matrix , row  return max sum row
unsigned short maxSumColumn(TYP mat[][SIZE], unsigned short row) {
  unsigned short bigger = sumArray(mat, 0), offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    bigger = MAX(sumArray(mat, offset), bigger);
  }
  return bigger;
}
// get matrix , row  return min sum row
unsigned short minValueArray(TYP mat[][SIZE], unsigned short row) {
  unsigned short smaller = sumArray(mat, 0), offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    smaller = MIN(sumArray(mat, offset), smaller);
  }
  return smaller;
}

// get matrix , column  return max value in column
unsigned short maxValueColumn(TYP mat[][SIZE], unsigned short column) {
  unsigned short bigger = mat[0][column], offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    bigger = MAX(mat[offset][column], bigger);
  }
  return bigger;
}
// get matrix , column  return min value in column
unsigned short minValueColumn(TYP mat[][SIZE], unsigned short column) {
  unsigned short smaller = mat[0][column], offset = 0;
  for (offset = 1; offset < SIZE; offset++) {
    smaller = MIN(mat[offset][column], smaller);
  }
  return smaller;
}
// get a matrix and return if magic square
//sum -what supposed to be the sum of every row, column, and main,sec diagonal
// flag- 0 if the same in every row, column, and main,sec diagona
bool isMagicSquare(TYP mat[][SIZE])
{
    unsigned short count;
     unsigned short sum=sumMainDiagonal(mat);
     bool flag=!sumSecAndMainDiagonalEqual(mat);
     
     for(count=0;count<SIZE &&!flag;count++)
     {
         sumArray(mat,count)==sumColumn(mat,count)?flag=0:flag++;
        sumArray(mat,count)==sum?flag=0:flag++;
     }
     return !flag;
     
     
}
int main() {
  TYP mat[][SIZE] = {{1, 2, 3}, {3, 5, 6}, {7, 8, 9}};
  TYP mat1[5][5] = {0};
  TYP arr[] = {1, 2, 3, 4, 5};
  // printArray(mat,0);
  // placeInMat(mat,arr,11);
  // printf("%d %d",arr[0],arr[1]);
  // printMat(mat);

  printf("%d ", sumMatScope(mat));

  return 0;
}