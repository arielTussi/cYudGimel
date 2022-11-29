#include <stdio.h>
#define TEN 10
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define TYP int
//---------------------------------------------------------
//                        maskForNBits
//                      ---------
// General : The function makes a mask of 1's
//
// Parameters :
// size -size of mask (In)
// mask- mask of 1's(out)
// return: mask 
// --------------------------------------------------------
TYP 
 maskForNBits (TYP size) 
{
  
    // Variable definition
    TYP mask = 0;
  
    // Code section
    for (int i = 0; i <= n; mask |= 1 << i++);
  
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
// --------------------------------------------------------
  TYP 
 maskCheckNBit (TYP n) 
{
  
    // Variable definition
    TYP mask = 1;
  
    // Code section
    for (int i = 0; i < n - 1; mask <<= 1, i++);
  
return mask;

}


//---------------------------------------------------------
//                        printNumberInBinary
//                      ---------
// General : The function prints the binary value of number in a range 
//
// Parameters :
// num -the number (In)
// size- the end of range to print(in)
// return: NONE 
// --------------------------------------------------------
void 
printNumberInBinary (TYP num, unsigned short size) 
{
  
unsigned TYP i;
  
for (i = 1 << size; i > 0; i = i / 2)
    
(num & i) ? printf ("1") : printf ("0");

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
// --------------------------------------------------------
  TYP 
 sumBitsOn (TYP num) 
{
  
TYP CNT;
  
unsigned short I; 
TYP A;  
CNT = 0;
A = 0X0001;
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
sumBitsOnRange (TYP num,us start,us amount,us size) 
{
TYP CNT;
unsigned short I;
TYP A;
CNT = 0;
A = maskCheckNBit(size-start);
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
  
num |= maskCheckNBit (bit);
  
return num;

}


//--------------------------------------------------------
//                        offBitInNum
//                          ---------
// General : The function turn off a specific bit in a number
//
// Parameters :
// num -the number (In/out)
// bit- the place of the bit supposed to be off(in)
// return: num 
// --------------------------------------------------------
  TYP 
offBitInNum (TYP num, unsigned short bit) 
{
  
num ^= maskCheckNBit (bit);
  
return num;

}