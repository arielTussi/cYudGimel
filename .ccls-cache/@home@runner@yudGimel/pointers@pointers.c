#include <stdio.h>
#include <math.h>
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define ABS(x) (0 < x) ? x : -x
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
  *ptrX ^= *ptrY;
  *ptrY ^= *ptrX;
  *ptrX ^= *ptrY;
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

    // Code section
    while (*ptrNum)
    {
        digit= *ptrNum % TEN;
        sum += EQUAL(digit%2,0)?digit:0;
        *ptrNum= *ptrNum / TEN;

    }
    return sum;
}

TYP
ptrSumOddDigits (TYP *ptrNum)
{
    // Variable definition
    TYP sum = 0,digit;

    // Code section
    while (*ptrNum)
    {
        digit= *ptrNum % TEN;
        sum += EQUAL(digit%2,1)?digit:0;
        *ptrNum= *ptrNum / TEN;

    }
    return sum;
}

TYP
ptrDigitInNum (TYP *ptrNum,TYP digit)
{
    // Variable definition
    bool flag=FALSE;
    TYP tempDigit;

    // Code section
    while (EQUAL(*ptrNum%TEN,digit)?FALSE,flag=TRUE:*ptrNum,*ptrNum /= TEN);
    
    return flag;
}

TYP 
ptrAmountOfDigits (TYP *ptrNum) { 
    // Variable definition 
    TYP count = 0; 
    // Code section 
    while (*ptrNum ? count ++: TRUE , *ptrNum /= TEN); 
    
    return count; 
    
}

TYP
ptrSumOfDigits (TYP *ptrNum)
{
    // Variable definition
    TYP sum = 0,tempDigit;

    // Code section
    while (*ptrNum)
    {
        tempDigit= *ptrNum % TEN;
        sum += tempDigit;
        *ptrNum= *ptrNum / TEN;

    }
    return sum;
}


TYP power(TYP a, TYP b){
    TYP i=1, sum=a;
    for(i=1;i<b;i++)
    {
        sum *= a;
    }
    return sum;
}
void
ptrChainTwo (TYP *ptrNum1,TYP *ptrNum2,TYP *ptrChaind)
{
    *ptrChaind=*ptrNum1;
    *ptrChaind *= power(10,ptrAmountOfDigits(ptrNum2));
    *ptrChaind+=*ptrNum2;
}

TYP
ptrIscommonDigits (TYP *ptrNum1,TYP *ptrNum2)
{
    // Variable definition
    TYP sum = 0,tempDigit;

    // Code section
    while (*ptrNum1)
    {
        tempDigit= *ptrNum1 % TEN;
        sum += ptrDigitInNum(ptrNum2,tempDigit);
        *ptrNum1= *ptrNum1 / TEN;
    }

    return POSITIVE(sum);
}

void
ptrNumFromEvenDigits (TYP *ptrNum,TYP *ptrNewNum)
{
    // Variable definition
    TYP sum = 0,digit;

    // Code section
    while (*ptrNum)
    {
        digit= *ptrNum % TEN;
        EQUAL(digit%2,0)?ptrChainTwo(ptrNewNum,&digit,ptrNewNum):0;
        *ptrNum= *ptrNum / TEN;

    }
}
void
ptrNumFromOddDigits (TYP *ptrNum,TYP *ptrNewNum)
{
    // Variable definition
    TYP sum = 0,digit;

    // Code section
    while (*ptrNum)
    {
        digit= *ptrNum % TEN;
        EQUAL(digit%2,1)?ptrChainTwo(ptrNewNum,&digit,ptrNewNum):0;
        *ptrNum= *ptrNum / TEN;

    }
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
bool
IsPrime ( TYP *sNum)
{
  // Variable definition
  TYP sCounter = 2;
  bool bIsFirst = FALSE;
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
bool
IsPalindrom (TYP nNum)
{
  // Variable definition
  bool bArePalindroms;
  TYP nReversedNum;

  // Code section
  Reverse (nNum, &nReversedNum);
  bArePalindroms = EQUAL(nNum , nReversedNum);

  return bArePalindroms;
}

TYP
pow1 ( TYP *ptrNum1,TYP *ptrNum2)
{
  // Variable definition
    TYP temp=*ptrNum1;
  // Code section
  while (*ptrNum2>1)
    {
      *ptrNum1 *= temp;
      (*ptrNum2)--;
    }
    return *ptrNum2 ? *ptrNum1: 1;
}

TYP
times ( TYP *ptrNum1,TYP *ptrNum2)
{
  // Variable definition
    TYP temp=*ptrNum1;
  // Code section
  while (*ptrNum2>1)
    {
      *ptrNum1 += temp;
      (*ptrNum2)--;
    }
    return *ptrNum1;
}


TYP
devied ( TYP *ptrNum1,TYP *ptrNum2)
{
  // Variable definition
    TYP count=0;
    
  // Code section
  while (*ptrNum1>=*ptrNum2)
    {
      *ptrNum1 -= *ptrNum2;
      count++;
    }
    return count;
}

TYP
moduloo ( TYP *ptrNum1,TYP *ptrNum2)
{
  // Variable definition
    TYP count=0;
    
  // Code section
  while (*ptrNum1 >= *ptrNum2)
    {
      *ptrNum1 -= *ptrNum2;
    }
    return *ptrNum1;
}

TYP
toTenBase ( TYP *base,TYP *ptrNum)
{
  // Variable definition
    TYP count=0,digit,sum=0;
    
  // Code section
  while (*ptrNum>0)
    {
    digit= *ptrNum % TEN;
    sum += pow1(base,&count) * digit;
    *ptrNum /= TEN;
    count++;
    }
    return sum;
}



int main ()
{
    int a=31102001,b=21102000;
    printf("%d",dateDif(&a,&b));
    // printf("%d",pow1(&a,&b));
    // printf("%d",pow1(&a,&b));

    return 0;
}

