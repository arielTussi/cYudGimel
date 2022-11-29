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

#define TYP char
#define SUMXWON 88*3
#define SUMOWON 79*3
#define SUMMATRIXTIE 79*5+88*4


#define SIZE 3
// ---------------print board funcs:
// get matrix and row print row
void printArray(TYP mat[][SIZE], unsigned short row) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE ;
       printf("%c ", mat[row][offset]), offset++)
    ;
    printf("\n");
}

// get matrix and print it
void printMat(TYP mat[][SIZE ]) {
  unsigned short offset, sum = 0;
  for (offset = 0; offset < SIZE ; offset++) {
    printArray(mat, offset);
  }
}
//------------sum of row, column, and diagonals:------------

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
// get matrix and row retun sum of row
unsigned short sumArray(TYP mat[][SIZE], unsigned short row) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE; sum += mat[row][offset], offset++)
    ;
  return sum;
}

// get matrix and column retun sum of column
unsigned short sumColumn(TYP mat[][SIZE], unsigned short column) {
  unsigned short offset = 0, sum = 0;
  for (offset = 0; offset < SIZE; sum += mat[offset][column], offset++);
  return sum;
}

// get matrix,num  return if there is a column equals num
bool numEqualsSumColumn(TYP mat[][SIZE],unsigned short num) {
  unsigned short flag=0, offset ;
  for (offset = 0; offset < SIZE; offset++) {
    flag += EQUAL(sumColumn(mat, offset),num);
  }
  return POSITIVE(flag);
}

/// get matrix,num  return if there is a row equals num
bool numEqualsSumRow(TYP mat[][SIZE],unsigned short num) {
  unsigned short  flag=0, offset ;
  for (offset = 0; offset < SIZE; offset++) {
    flag += EQUAL(sumArray(mat, offset),num);
  }
  return POSITIVE(flag);
}
// get matrix and retun if sum equals the sum of the matrix in tie
bool sumTieMat(TYP mat[][SIZE]) {
  unsigned short offset, sum = 0;
  for (offset = 0; offset < SIZE; offset++) {
    sum += sumArray(mat, offset);
  }
  return EQUAL(SUMMATRIXTIE,sum);
}
// ---------------GAME FUNCS:
// gets a matrix,row, column and return if place is between 
// [0-2] [0-2]
bool checkIfPlaceValid(TYP mat[][SIZE],unsigned short row,unsigned short column)
{
    bool valid;
    valid = MIN(row,3) && MIN(column,3);
    return valid;
}
// gets a matrix,row, column and return if place in matrix is not full
bool checkIfPlaceEmpty(TYP mat[][SIZE],unsigned short row,unsigned short column)
{
    return !MAX(mat[row][column],('O'-1));
}
// input:
// gets a matrix. input is: a char 'X','O' , placement on the board,and place into the board.
void placeIntoBoard(TYP mat[][SIZE],unsigned short turn) 
{
    TYP sign;
    unsigned short row,column;
    sign= EQUAL(turn%2,0)?'O':'X';
    printf("enter the row:");
    scanf("%hu",&row);
    printf("enter the column:");
    scanf("%hu",&column);
    checkIfPlaceValid(mat,row,column)? 0:placeIntoBoard(mat,turn);
    checkIfPlaceEmpty(mat,row,column)?mat[row][column]=sign:placeIntoBoard(mat,turn);
    printf("\n");


}


// gets a matrix, returns whether there is a win or not
 unsigned short checkWinning(TYP mat[][SIZE]) 
{
    unsigned short flag=0;// 8- sum of checks
    sumTieMat(mat)?  flag=9 : 0;
    EQUAL(sumMainDiagonal(mat),SUMXWON)? flag=1 : 0;
    EQUAL(sumMainDiagonal(mat),SUMOWON)? flag=2 : 0;
    
    EQUAL(sumSecDiagonal(mat),SUMXWON)?  flag=3 : 0;
    EQUAL(sumSecDiagonal(mat),SUMOWON)?  flag= 4 : 0;
    
    numEqualsSumColumn(mat,SUMXWON)?  flag=5 : 0;
    numEqualsSumColumn(mat,SUMOWON)?  flag=6 : 0;
    
    numEqualsSumRow(mat,SUMXWON)?  flag=7 : 0;
    numEqualsSumRow(mat,SUMOWON)?  flag=8 : 0;
    return flag;
}

// output:
// gets a flag- if the flag is equal O won,odd x won.  
// returns who won
void whoWon(unsigned short flag)
{
    EQUAL(flag%2,0)?printf("O won"):printf("X won");
}


void GAME() 
{
    TYP mat1[3][3]={{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
    unsigned short flagOfTie=9,amountOfTurns=0;
    while (!POSITIVE(checkWinning(mat1)))
    {
        placeIntoBoard(mat1,amountOfTurns++);
        printMat(mat1);
        checkWinning(mat1);
    }   
    // Checks if the loop has ended and there is a tie or there is a winner
    checkWinning(mat1)!=flagOfTie? whoWon(checkWinning(mat1)) :printf("tie");
}







int main() {
GAME();

    return 0;
}