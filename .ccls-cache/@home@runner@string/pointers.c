#include <stdio.h>
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define TEN 10
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define TYP unsigned short
  
bool ptrIsEven(TYP* num)
{
    // Code section
    return EQUAL(*num%2,0);
}

bool ptrIsOdd(TYP* num)
{
    // Code section
    return EQUAL(*num%2,1);
}
//---------------------------------------------------------
//                        swap
//                      ---------
// General : The function exchanges values between two pointers 
//
// Parameters :
// *ptrX - pointer of int (In)
// *ptrY : pointer of int
// return:NONE
// --------------------------------------------------------
void
swap (TYP *ptrX, TYP *ptrY)
{
  // Code section
  ptrX ^= ptrY;
  ptrY ^= ptrX;
  ptrX ^= ptrY;
}

TYP ptrsumTwoNum(TYP* sNum1,TYP* sNum2)
{
      // Code section
    return *sNum1+*sNum2;
}
TYP
ptrSumEvenDigits (TYP *ptrNum)
{
    // Variable definition
    TYP sum = 0,digit;
    TYP temp = *ptrNum;
    
    // Code section
    while (temp)
    {
        digit= temp % TEN;
        sum += EQUAL(digit%2,0)?digit:0;
        temp= temp / TEN;

    }
    return sum;
}

TYP
ptrSumOddDigits (TYP *ptrNum)
{
    // Variable definition
    TYP sum = 0,digit;
    TYP temp = *ptrNum;
    
    // Code section
    while (temp)
    {
        digit= temp % TEN;
        sum += EQUAL(digit%2,1)?digit:0;
        temp= temp / TEN;

    }
    return sum;
}

TYP
ptrDigitInNum (TYP *ptrNum,TYP digit)
{
    // Variable definition
    TYP sum = 0,tempDigit;
    TYP temp = *ptrNum;
    
    // Code section
    while (temp)
    {
        tempDigit= temp % TEN;
        sum += EQUAL(tempDigit,digit)?tempDigit:0;
        temp= temp / TEN;

    }
    return POSITIVE(sum);
}

//---------------------------------------------------------
//                        IsPrime
//                      ---------
// General : The function check if the number is a prime number 
//
// Parameters :
// *sNum - pointer of unsigned short (In)
// return:NONE
// --------------------------------------------------------
boolean
IsPrime ( TYP *sNum)
{
  // Variable definition
  TYP sCounter = 2;
  boolean bIsFirst = FALSE;
  float fSqrt = sqrt (*sNum);
  // Code section

  while (sCounter <= fSqrt && *sNum % sCounter++);
  bIsFirst = sCounter > fSqrt;

  return bIsFirst;
}

//---------------------------------------------------------
//                        Reverse
//                      ---------
// General : The function reverse thr digits of the num 
//
// Parameters :
// nNum- number
// *prtResult - pointer of unsigned short to the reversed num (In)
// return:NONE
// -------------------------------------------------------
void
Reverse (TYP nNum, TYP *prtResult)
{
  // Variable definition
  *prtResult = 0;

  // Code section
  while (nNum)
    {
      *prtResult += nNum % TEN;
      *prtResult *= TEN;
      nNum /= TEN;
    }
  *prtResult /= TEN;
}

//---------------------------------------------------------
//                      IsPalindrom
//                      ---------
// General : The function check if the num is palindrom
//
// Parameters :
// nNum- number
// *prtResult - pointer of unsigned short to the reversed num (In)
// return:NONE
// -------------------------------------------------------
boolean
IsPalindrom (TYP nNum)
{
  // Variable definition
  boolean bArePalindroms;
  TYP nReversedNum;

  // Code section
  Reverse (nNum, &nReversedNum);
  bArePalindroms = EQUAL(nNum , nReversedNum);

  return bArePalindroms;
}
