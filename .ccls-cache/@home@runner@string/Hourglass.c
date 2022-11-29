// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 7
//-------------------------------------------------------------
//                      changeRowInMat
//                      ---------
// General : The function change a row in a exact range,depending on the initial value entered, each column increases the value by one.
//
// Parameters :
// matix - matrix (In)
// row- line that changes(In)
// startColumn-start of column range(In)
// endColumn-end of column range(In)
//count-initial value,increased by one in every column(In)
// Return Value : the value after increased (count)
// ------------------------------------------------------------
unsigned short changeRowInMat(unsigned short mat [][SIZE], unsigned short row, unsigned short startColumn, unsigned short endColumn,unsigned short count)
    {
    unsigned short offset;
    for(offset = startColumn; offset <endColumn; offset++)
    {
            mat[row][offset]=count++;
    }
    return count;
}
//-------------------------------------------------------------
//                      upperFunnelMat
//                      ---------
// General : The function change the top half of the matrix.
//
// Parameters :
// matix - matrix (In)
//count-initial value,increases according to the number of columns passed in the previous row (In)
// Return Value : the value after increased (count)
// ------------------------------------------------------------

unsigned short upperFunnelMat(unsigned short mat [][SIZE],unsigned short count)
{
    unsigned short offset1,topHalf=SIZE/2+1;
    for(offset1=0;offset1<topHalf;offset1++)
    {
        count=changeRowInMat(mat,offset1,offset1,SIZE-offset1,count);
    }
    return count;

}
//-------------------------------------------------------------
//                      lowerFunnelMat
//                      ---------
// General : The function change the lower half of the matrix.
//
// Parameters :
// matix - matrix (In)
//count-initial value,increases according to the number of columns passed in the previous row (In)
// Return Value : the value after increased (count)
// ------------------------------------------------------------
unsigned short lowerFunnelMat(unsigned short mat [][SIZE],unsigned short count)
{
    unsigned short offset1,topHalf=SIZE/2+1;

    for(offset1=topHalf;offset1<SIZE;offset1++)
    {
        count=changeRowInMat(mat,offset1,SIZE-offset1-1,offset1+1,count);
    }
        return count;
}
//-------------------------------------------------------------
//                      lowerFunnelMat
//                      ---------
// General : The function put in the matrix values that increase by one in the shape of an hourglass.
//
// Parameters :
// matix - matrix (In)
// Return Value : NONE
// ------------------------------------------------------------
void HourglassMat(unsigned short mat [][SIZE])
{
    unsigned short count=1;
    count=upperFunnelMat(mat,count);
    lowerFunnelMat(mat,count);
}



int main() {
    
    unsigned short mat[7][7]={0};
    unsigned short count=1,offset1,offset2;
    
    // upperFunnelMat(mat);
    HourglassMat(mat);

    for(offset1=0;offset1<7;offset1++)
    {
      for(offset2=0;offset2<7;offset2++) 
        {
            printf("%d ",mat[offset1][offset2]);
            
        }
        printf("\n");
    }
}