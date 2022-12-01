#include <stdio.h>
#define TEN 10
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define TYP int
#define us unsigned short
#define MAXSIZEBOARD 31
#define  AMOUNTPLUSAIZE 6
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE

//-----------------------mask lib:---------------------------

//---------------------------------------------------------
//                        maskForNBits
//                      ---------
// General : The function makes a mask of 1's
//
// Parameters :
// usSize -usSize of mask (In)
// mask- mask of 1's(out)
// return: mask 
// run time function - T(n)=2n
// --------------------------------------------------------
TYP 
 maskForNBits (TYP usSize) 
{
  
    // Variable definition
    TYP mask = 0;
    TYP i;
  
    // Code section
    for (i = 0; i <= usSize; mask |= 1 << i++);
  
return mask;

}


//---------------------------------------------------------
//                        maskCheckNBit
//                          ---------
// General : The function makes a mask that just one bit is on
//
// Parameters :
// n -place of the lit bit (In)
// mask- mask of 0's and just one bit is on(out)
// return: mask 
// run time function - T(n)=2n
// --------------------------------------------------------
  TYP 
 maskCheckNBit (TYP n) 
{
  
    // Variable definition
    TYP mask = 1;
  
    // Code section
    for (int i = 1; i < n ; mask <<= 1, i++);
  
return mask;

}


//---------------------------------------------------------
//                        printNumberInBinary
//                      ---------
// General : The function prints the binary value of number in a range 
//
// Parameters :
// num -the number (In)
// usSize- the end of range to print(in)
// return: NONE 
// run time function - T(n)=3n+1
// --------------------------------------------------------
void 
printNumberInBinary (TYP num, us usSize) 
{
    // Variable definition
    unsigned TYP i;
    usSize=usSize-1;
    // Code section
  
    for (i = 1 << usSize; i > 0; i = i / 2)
        
    (num & i) ? printf ("1 ") : printf ("0 ");

}


//---------------------------------------------------------
//                        sumBitsOn
//                          ---------
// General : The function sums up the amount of the lit bits in binary value of num
//
// Parameters :
// num -the number (In)
// mask- mask of 0's and just one bit is on(in)
// A- mask check a specific bit(in)
// CNT - sum of lit bits(out)
// return: CNT 
// run time function - T(n)=3n

// --------------------------------------------------------
  TYP 
 sumBitsOn (TYP num) 
{
    // Variable definition
    TYP CNT;
    unsigned short I;
    TYP A;
    CNT = 0;
    A = 0X0001;
    // Code section
    for (I = 0; I < 32; I++, A <<= 1)
    {
        CNT += ! !(num & A);
    }
    return CNT;

}

//---------------------------------------------------------
//                        sumBitsOnRange
//                          ---------
// General : The function sums up the amount of the lit bits in binary value of num within a ragne of bits
//
// Parameters :
// num -the number (In)
// mask- mask of 0's and just one bit is on(in)
// A- mask check a specific bit(in)
// CNT - sum of lit bits(out)
// return: CNT 
// --------------------------------------------------------
TYP 
sumBitsOnRange (TYP num,us start,us amount,us usSize) 
{    
    // Variable definition
    TYP CNT;
    unsigned short I;
    TYP A;
    CNT = 0;
    // Code section
    A = maskCheckNBit(usSize-start);
    for (I = 0; I < amount; I++, A >>= 1)
    {
    CNT += ! !(num & A);
    }
    return CNT;

}


//---------------------------------------------------------
//                        litBitInNum
//                          ---------
// General : The function lit a specific bit in a number
//
// Parameters :
// num -the number (In/out)
// bit- the place of the bit supposed to be on(in)
// return: num 
// --------------------------------------------------------
  TYP 
 litBitInNum (TYP num, unsigned short bit) 
{
    // Code section
    num |= maskCheckNBit (bit);
    
    return num;

}

//---------------------------------------------------------
//                        offBitInNum
//                          ---------
// General : The function turn off a specific bit in a number
//
// Parameters :
// num -the number (In/out)
// bit- the place of the bit supposed to be off(in)
// return: num 
// run time function - T(n)=1

// --------------------------------------------------------
  TYP 
offBitInNum (TYP num, unsigned short bit) 
{
    // Code section
    num ^= maskCheckNBit (bit);
      
    return num;

}
//-----------------------------------------------------------

//---------------------------------------------------------
//                         print Board
//                          ---------
// General : The function gets a var and prints it
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// return: none
// run time function - T(n)=2n

// --------------------------------------------------------
void printBoard(TYP var[],TYP usSize) 
{
    // Variable definition
    unsigned short offset = 0;
    // Code section
    for (offset = 0; offset < usSize ; offset++)
    {
        printNumberInBinary(var[offset],usSize);
        printf("\n");
    }
}
//------------------------valid input-----------------------
//   when you put submarines on the board at the beginning of the game,the input needs to be checked

//---------------------------------------------------------
//                        make a frame
//                          ---------
// General : The function surrounds the arr with o's
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// newBoard - the board surrounded  (In/out)
// return: none
// run time function - T(n)=2n+1

// --------------------------------------------------------
void makeAFrame(TYP board[],us usSize,TYP newBoard[])
{
    // Variable definition
    us offset;
    newBoard[0]=0;
    newBoard[usSize+1]=0;
    // Code section
    for(offset=1;offset<usSize;offset++)
    {
        newBoard[offset]=board[offset-1];
    }
}

//---------------------------------------------------------
//                        shift left board
//                          ---------
// General : The function shift left all the valus in arr 
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// newBoard - the board surrounded  (In/out)
// return: none
// run time function - T(n)=3n
// --------------------------------------------------------
void shiftLeftBoard(TYP board[],us usSize,TYP newBoard[])
{
    // Variable definition
    us offset;
    // Code section
    for(offset=0;offset<usSize;offset++)
    {
        newBoard[offset+1]=board[offset]<<1;
    }
}
//---------------------------------------------------------
//                       sum Of Neighbors Sub Along
//                          ---------
// General : The function sums up the values of the Neighbors of submarine that along 
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the start Row of submarine (In)
// usColumn - the start Column of submarine (In)
// range - the Size  of submarine (In)
// sum- the sum of Neighbors(out)
// return: sum 
// run time function - T(n)=8

// --------------------------------------------------------
us sumOfNeighborsSubAlong(TYP board[],us usSize,us usRow,us usColumn,us range)
{
    // Variable definition
    us sum=0;
    // Code section
    sum+=sumBitsOnRange(board[usRow],usColumn,range+2,usSize);
    sum+=sumBitsOnRange(board[usRow+1],usColumn,range+2,usSize);
    sum+=sumBitsOnRange(board[usRow+2],usColumn,range+2,usSize);
    return sum;

}
//---------------------------------------------------------
//                       sum Of Neighbors Sub Across
//                          ---------
// General : The function sums up the values of the Neighbors of submarine that Across 
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the start Row of submarine (In)
// usColumn - the start Column of submarine (In)
// range - the Size of submarine (In)
// sum- the sum of Neighbors(out)
// return: sum 
// run time function - T(n)=3n
// --------------------------------------------------------
us sumOfNeighborsSubAcross(TYP board[],us usSize,us usRow,us usColumn,us range)
{
    // Variable definition
    us sum=0,offset;
    // Code section
    for(offset=0;offset<range+2;offset++)
    {
    sum+=sumBitsOnRange(board[usRow+offset],usColumn,3,usSize);
    }
    return sum;

}
//---------------------------------------------------------
//                          in Board
//                          ---------
// General : The function checks if the submarine can be in  in the board
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the start Row of submarine (In)
// usColumn - the start Column of submarine (In)
// range - the Size of submarine (In)
// usDir -the Direction  of submarine (In)
// sum - the sum of Neighbors(out)
// bIsIn - flag if in board
// return: bIsIn 
// run time function - T(n)=3
// --------------------------------------------------------
bool inBoard(TYP board[], us usSize, us usRow, us usColumn, us range,us usDir) 
{
    // Variable definition
    bool bIsIn=TRUE;
    // Code section
    bIsIn= usRow < usSize ? bIsIn : FALSE;
    bIsIn= usColumn < usSize ? bIsIn : FALSE;
    if (usDir)
        bIsIn = (usRow + range) < usSize ? bIsIn : FALSE;
    else
        bIsIn = (usColumn + range) < usSize ? bIsIn : FALSE;
        
    return bIsIn;
    
}
//---------------------------------------------------------
//                          check If Valid Input
//                          ---------
// General : The function checks if the submarine is valid to put in the board
//
// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the start Row of submarine (In)
// usColumn - the start Column of submarine (In)
// range - the Size  of submarine (In)
// usDir -the Direction  of submarine (In)
// sum - the sum of Neighbors(out)
// bcanBeIn - flag if the submarine cen be in board
// return: bIsbcanBeInIn 
// run time function - T(n)=5

// --------------------------------------------------------
bool
checkIfValidInput (TYP board[], us usSize, us usRow, us usColumn, us range,us usDir) 
{
    // Variable definition
    bool bcanBeIn;
    TYP board2[MAXSIZEBOARD] ={0};
    // Code section
    makeAFrame (board, usSize, board2);
    shiftLeftBoard (board, usSize, board2);
    bcanBeIn= usDir ?
        !POSITIVE (sumOfNeighborsSubAcross (board2, usSize + 2, usRow, usColumn, range))
        :
        !POSITIVE (sumOfNeighborsSubAlong (board2, usSize + 2, usRow, usColumn, range));
    bcanBeIn=inBoard(board,usSize,usRow,usColumn,range,usDir) ? bcanBeIn : FALSE;
    
    return bcanBeIn;
    
}

// -------------------game beginning -----------------------
// At the beginning of the game each participant places his submarines on the board

// The Direction of the board is opposite to the Direction of reading a binary variable, this means that if a Row on the board is 00100, if we want to make a change in a certain bit, the position is the length of the board minus the  position. For example, we would like to turn on the bit position 1(01100), we will make a change to (5-1) bit 

//---------------------------------------------------------
//                        getBoardSize
//                          ---------
// General : The function get input of board's Size
//
// Parameters :
// boardSize - the Size of the board (out)
// bit- the place of the bit supposed to be off(in)
// return: num 
// run time function - T(n)=0

// --------------------------------------------------------
us getBoardSize()
{
    // Variable definition
    us boardSize;
    // Code section
    printf("board usSize:25-31\n");
    scanf("%hu",&boardSize);
    return boardSize;
}
//---------------------------------------------------------
//                     put Submarines Along
//                          ---------
// General : The function turn on the bits the representing the submarine

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the start Row of submarine (In)
// usColumn - the start Column of submarine (In)
// amount - the Size of submarine(amount of bits) 
// offset - the start Column 
// endOfLitBits - the end Column 
// return: none 
// run time function - T(n)=2n+2

// --------------------------------------------------------
void putSubmarinesAlong(TYP board[],us usSize,us usRow,us usColumn,us amount)
{
    // Variable definition
    us offset=(usSize-usColumn);
    us endOfLitBits=(usSize-usColumn-amount);
    // Code section
    for(offset;offset>endOfLitBits;offset--)
    {
        board[usRow]=litBitInNum(board[usRow],offset);
    }
}

//---------------------------------------------------------
//                     put Submarines Across
//                          ---------
// General : The function turn on the bits the representing the submarine

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the start Row of submarine (In)
// usColumn - the start Column of submarine (In)
// amount - the Size  of submarine(amount of bits) 
// offset - the start Row 
// endOfLitBits - the end Row 
// return: none 
// run time function - T(n)=2n+2

// --------------------------------------------------------
void putSubmarinesAcross(TYP board[],us usSize,us usRow,us usColumn,us amount)
{
    // Variable definition
    us offset;
    us endOfLitBits=(usRow+amount);
    usColumn=usSize-usColumn;
    // Code section
    for(offset=usRow;offset<endOfLitBits;offset++)
    {
        board[offset]=litBitInNum(board[offset],usColumn);
    }
}
//---------------------------------------------------------
//                         Sub Place
//                          ---------
// General : The function gets input about the submarine and 
// checks if valid. puts the submarine in the board. 
// prints the board

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// amount - how many Submarine left to put(in)
// usSizeSub - the Size of Submarine(in)
// usRow - the start Row of submarine (i)
// usColumn - the start Column of submarine (i)
// usDir - the Direction of submarine (i)
// return: none 
// run time function - T(n)=4

// --------------------------------------------------------
void SubPlace(TYP board[],us usSize,us *amount,us usSizeSub){
    // Variable definition 
    us usRow,usColumn,usDir;
    bool valid;
    // Code section
    printf("Submarine usSize: %d, left to put:%d",usSizeSub,*amount);
    printf("\nenter start usRow\n");
    scanf("%hu",&usRow);
    printf("enter start usColumn\n");
    scanf("%hu",&usColumn);
    printf("enter for along-0 and for across-1\n");
    scanf("%hu",&usDir);
    
    valid = checkIfValidInput(board,usSize,usRow,usColumn,usSizeSub,usDir);
    if (valid)
    {
        usDir?putSubmarinesAcross(board,usSize,usRow,usColumn,usSizeSub):putSubmarinesAlong(board,usSize,usRow,usColumn,usSizeSub);
        (*amount)--;
    }
    else 
    {
        printf("worng input\n");
    }
    printBoard(board,usSize);

}

//---------------------------------------------------------
//                   places Of One Kind Sub
//                          ---------
// General : The function asks for info of one kind of submarine 
// and puts the submarine in the board.

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// amount - how many Submarine left to put from this kind(in)
// usSizeOfSubmarine- the Size of the Submarine
// return: none 
// run time function - T(n)=n+1

// --------------------------------------------------------
void placesOfOneKindSub(TYP board[],us usSize,us amount)
{
    // Variable definition
    us usSizeOfSubmarine=(AMOUNTPLUSAIZE-amount);
    // Code section
    while(amount)
    {
        SubPlace(board,usSize,&amount,usSizeOfSubmarine);
    }
}

//---------------------------------------------------------
//                         initialize Board
//                          ---------
// General : The function initializes the board with all kind of submarines

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)

// return: none 
// run time function - T(n)=2n

// --------------------------------------------------------
void initializeBoard(TYP board[],TYP usSize)
{
    // Variable definition
    us kindsOfSubmarines=5;
    // Code section// Code section
    while(kindsOfSubmarines)
    {
        placesOfOneKindSub(board,usSize,kindsOfSubmarines--);
    }
}

// ---------------------------------------------------------

// -----------------------game progress---------------------
// During the game, each player in his turn guess the location of submarine, if he hits - a message is printed and he has  another turn. If not - a message is printed as well. The game ends when there are no submarines on the board (the sum of the entire board equals 0).

//---------------------------------------------------------
//                         check If Hit
//                          ---------
// General : The function checks if in the guessed location there is a submarine

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the guessed Row of submarine (In)
// usColumn - the guessed Column of submarine (In)
// ifHit- flag if the player guessed a location with a submarine(out)
// return: ifHit  
// run time function - T(n)=2

// --------------------------------------------------------   
bool checkIfHit(TYP board[],us usSize,us usRow,us usColumn)
{
    // Variable definition
    bool ifHit;
    usColumn=usSize-usColumn;
    // Code section
    ifHit=!!(maskCheckNBit(usColumn)&board[usRow]);
    return ifHit;
}

//---------------------------------------------------------
//                         take Sub Down
//                          ---------
// General : The function take down a submarine( turns off a bit)

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the guessed Row of submarine (In)
// usColumn - the guessed Column of submarine (In)

// return: none  
// run time function - T(n)=2
// --------------------------------------------------------  
void takeSubDown(TYP board[],us usSize,us usRow,us usColumn)
{
    // Variable definition
    usColumn=usSize-usColumn;
    // Code section
    board[usRow]=offBitInNum(board[usRow],usColumn);
    
}
//---------------------------------------------------------
//                            won
//                          ---------
// General :  The function checks if  there are no submarines on the board (the sum of the entire board equals 0).

// Parameters :
// board - the board of the game (In)
// usSize- the Size of the board(in)
// usRow - the guessed Row of submarine (In)
// usColumn - the guessed Column of submarine (In)
// isWon - if the sum of the entire board equals 0 (out)
// return: isWon  
// run time function - T(n)=3

// --------------------------------------------------------  
bool won(TYP board[],us usSize)
{
    // Variable definition
    unsigned short offset = 0, sum = 0;
    bool isWon;
    // Code section
    for (offset = 0; offset < usSize; sum += sumBitsOn(board[offset++]));
    isWon = !POSITIVE(sum);
    return isWon;
}
//---------------------------------------------------------
//                         who won
//                          ---------
// General :  The function checks who won.

// Parameters :
// board - one of the boards of the game (In)
// usSize- the Size of the board(in)
// return: isWon  
// run time function - T(n)=1
// --------------------------------------------------------
void whoWon(TYP board[],us usSize)
{
    // Variable definition
    us winner; 
    // Code section
    winner = won(board,usSize) ? printf("one won") :  
    printf("two won");
}

//---------------------------------------------------------
//                        guess Place
//                          ---------
// General :  The function get info of on guess. if hit right- take the submarine down

// Parameters :
// board - one of the boards of the game (In)
// usSize- the Size of the board(in)
// ptrTurn- the turn number-first player is even num,second player is odd num
// usRow - the guessed Row of submarine (i)
// usColumn - the guessed Column of submarine (i)
// usDir - the guessed Direction of submarine (i)
// return: none  
// run time function - T(n)=3

// --------------------------------------------------------
void guessPlace(TYP board[],us usSize,us *ptrTurn)
{
    // Variable definition
    us usRow,usColumn,usDir;
    // Code section
    EQUAL(*ptrTurn%2,0) ? printf("first player turn:") : printf("second player turn:");
    printf("\nenter usRow\n");
    scanf("%hu",&usRow);
    printf("enter usColumn\n");
    scanf("%hu",&usColumn);

    (*ptrTurn) += checkIfHit(board,usSize,usRow,usColumn) ? 0 : 1;
    checkIfHit(board,usSize,usRow,usColumn)?
    takeSubDown(board,usSize,usRow,usColumn),printf("\nThere is submarine\n"): printf("\nThere is no submarine\n");
    
}


//---------------------------------------------------------
//                         get Guesses
//                          ---------
// General :  The function lets each player in turn to guess until the game is over

// Parameters :
// boardOne - first player's game board (In)
// boardTwo - second player's game board  (In)
// usSize- the Size of the board(in)

// return: none  
// run time function - T(n)=3

// --------------------------------------------------------
void getGuesses(TYP boardOne[],TYP boardTwo[],us usSize)
{
    // Variable definition
    us turn=0;// first player is even,second player is odd
    // Code section
    while(!(won(boardOne,usSize)||won(boardTwo,usSize)))
    {
        EQUAL(turn%2,0) ? guessPlace(boardTwo,usSize,&turn) : guessPlace(boardOne,usSize,&turn);
    }
}



// -------------------------------------------------------



//-----------------------------------------------------------
//                         submarine game
//                          -----------
//
// General : The program runs the submarine game
//
// Input : The location of the submarines and guesses of their location
//
// Process : board initialization and guesses management
//
// Output : The board, requests from the players, error messages
//
//------------------------------------------------------------
// Programmer : Ariel Tussi
// Date : 19.11.2022
//------------------------------------------------------------
void GAME()
{
    // Variable definition
    us logicalSizeOfBoard;
    TYP board1[MAXSIZEBOARD]={0};
    TYP board2[MAXSIZEBOARD]={0};
    logicalSizeOfBoard=getBoardSize();
    
    
    
    initializeBoard(board1,logicalSizeOfBoard);
    initializeBoard(board2,logicalSizeOfBoard);


    printBoard(board1,logicalSizeOfBoard);
    printf("\n");
    printBoard(board2,logicalSizeOfBoard);
    
    getGuesses(board1,board2,logicalSizeOfBoard);
    whoWon(board1,logicalSizeOfBoard);
    printf("\nhh");

}

int main ()
{
    GAME();
    return 0;
}