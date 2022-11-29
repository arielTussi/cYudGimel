// Online C compiler to run C program online
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define MAX(x, y) (x > (y)) ? x : y
#define MIN(x, y) (x < y) ? TRUE : FALSE
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define SIZE 4
#define AMOUNTOFDIAGONALS SIZE*SIZE-2
#define TYP unsigned short
//-------------------------------------------------------------
//                      sumOfDiagonal2DOffset
//                      ---------
// General : The function calculates the sum of all the places in matrix that the result of adding their offsets equals what we got as parameter. exp: mat[1][2]=3
//
// Parameters :
// matix - matrix (In)
// offset - offset= result of adding two offsets of place (In)
// sum- sum of the diagonal(out)
//
// Return Value : The result of sum
// ------------------------------------------------------------
TYP sumOfDiagonal2DOffset(TYP mat[][SIZE], unsigned short offset)
{
    unsigned short count,sum=0;
    for(count=0;count<=offset;count++)
    {
        sum+=((MAX(count,offset-count))<SIZE) ?mat[count][offset-count] :0;
    }
    return sum;
}

//-------------------------------------------------------------
//                      sumOfAllDiagonals
//                      ---------
// General : The function calculates the sum of all the diagonals in matrix 
//
// Parameters :
// matix - matrix (In)
// sum- sum of the diagonals(out)
//
// Return Value : The result of sum
// ------------------------------------------------------------
TYP sumOfAllDiagonals(TYP mat[][SIZE])
{
    unsigned short count,sum=0;
    for(count=0;count<=AMOUNTOFDIAGONALS;count++)
    {
        sum+=sumOfDiagonal2DOffset(mat,count);
    }

    return sum;
}



int main() {
    TYP mat[][SIZE] =   {
                        {4, 9, 2,1}, 
                        {3, 5, 7,1}, 
                        {8, 1, 6,1},
                        {4, 9, 2,1}};
    printf("%d",sumOfAllDiagonals(mat));

    return 0;
}