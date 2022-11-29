// Online C compiler to run C program online
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define TEN 10
#define bool unsigned char
#define us unsigned short
#define MAX(x, y) (x > y) ? TRUE : FALSE
#define MIN(x, y) (x < y) ? TRUE : FALSE
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define ABS(x) (0 < x) ? x : -x
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define AMOUNT_OF_INTERESTS 7
typedef char string[12];

typedef struct date
{
  us day;
  us month;
  us year;
} date;

typedef struct person
{
  string firstName;
  string secondName;
  string address;
  bool sex;
  date dateOfBirth;
  int phoneNumber;
  string email;
  us interests;
} person;

//---------------------------------------------------------
//                        mask Check N Bit
//                          ---------
// General : The function makes a mask that just one bit is on
//
// Parameters :
// n -place of the lit bit (In)
// mask- mask of 0's and just one bit is on(out)
// return: mask 
// --------------------------------------------------------
us
maskCheckNBit (us n)
{

  // Variable definition
  us mask = 1;

  // Code section
  for (int i = 1; i <= n; mask <<= 1, i++);

  return mask;

}

// ---------------------------------------------------------
//                        lit Bit In Num
//                          ---------
// General : The function lits a specific bit in a number
//
// Parameters :
// num -the number (In/out)
// bit- the place of the bit supposed to be on(in)
// return: num 
// --------------------------------------------------------
us
litBitInNum (us num, us bit)
{

  num |= maskCheckNBit (bit);

  return num;

}

//---------------------------------------------------------
//                        print Number In Binary
//                      ---------
// General : The function prints the binary value of number in a range 
//
// Parameters :
// num -the number (In)
// usSize- the end of range to print(in)
// return: NONE 
// --------------------------------------------------------
void
printNumberInBinary (us num, us usSize)
{
  unsigned i;
  for (i = 1 << usSize - 1; i > 0; i = i / 2)
    (num & i) ? printf ("1 ") : printf ("0 ");

}

// ---------------------------------------------------------
//                        String Len
//                          ---------
// General : The function calculates the len of string
//
// Parameters :
// str- the string(in)
// return: len 
// --------------------------------------------------------
unsigned short
StringLen (string str)
{
  unsigned short count = 0;
  while (str[count++]);

  return count - 1;

}

// ---------------------------------------------------------
//                           is Eqaul 
//                          ---------
// General : The function checks if two strings Eqaul
//
// Parameters :
// str1- a string(in)
// str2- a string(in)
// return: bool flag 
// --------------------------------------------------------
bool
isEqaul (string str1, string str2)
{
  unsigned short count = 0, temp = 0;
  while (str1[count] == str2[count++] ? str2[++temp] : 0);
  return !(StringLen (str1) - temp + (StringLen (str2) - temp));

}

// ---------------------------------------------------------
//                         get Interests
//                          ---------
// General : The function asks for the Interests of person
//
// Parameters :
// personsVec- a pointer of persons(in)
// interests- arr of kind of interests(in)
// return: none
// --------------------------------------------------------

void
getInterests (person * personsVec, string interests[])
{
  bool likeOrNot;
  us offset, amountOfPersonsInterests = 0;
  personsVec->interests = 0;
  for (offset = 0; offset < AMOUNT_OF_INTERESTS; offset++)
    {
      printf ("if you like to do %s answer 1 else 0:", interests[offset]);
      scanf ("%hhd", &likeOrNot);

      personsVec->interests =
	likeOrNot ? litBitInNum (personsVec->interests,
				 offset) : personsVec->interests;
    }

}

// --------------------------------------------------------
//                         print Preson
//                          ---------
// General : The function prints all data of person
//
// Parameters :
// p- a pointer of person(in)
// return: none
// --------------------------------------------------------
  void
printPreson (person * p)
{

  printf ("first Name :%s \n", p->firstName);
  printf ("second Name :%s \n", p->secondName);
  printf ("address : %s  \n", p->address);
  printf ("sex : %hd \n ", p->sex);
  printf ("day : %hd\n", p->dateOfBirth.day);
  printf ("month:%hd \n", p->dateOfBirth.month);
  printf ("year :%hd \n", p->dateOfBirth.year);
  printf ("phone Number:%d\n", p->phoneNumber);
  printf ("email :%s \n", p->email);
  printf ("interests : \n");
  printNumberInBinary (p->interests, AMOUNT_OF_INTERESTS);
}

// ---------------------------------------------------------
//                         make Persons
//                          ---------
// General : The function asks for data of person and make pointer of persons 
//
// Parameters :
// personsVec- a pointer of persons(in)
// size- amount of persons
// interests- arr of kind of interests(in)
// return: none
// --------------------------------------------------------
void
makePersons (person * personsVec, us size, string interests[])
{
  person *ptrEndPersons = personsVec + size - 1;
  while (personsVec++ <= ptrEndPersons)
    {
      printf ("first Name :\n");
      scanf ("%s", &personsVec->firstName);
      printf ("second Name :\n");
      scanf ("%s", &personsVec->secondName);
      printf ("address : \n");
      scanf ("%s", &personsVec->address);
      printf ("sex : \n");
      scanf ("%hd", &personsVec->sex);
      printf ("day : \n");
      scanf ("%hd", &personsVec->dateOfBirth.day);
      printf (" month : \n");
      scanf ("%hd", &personsVec->dateOfBirth.month);
      printf (" year : \n");
      scanf ("%hd", &personsVec->dateOfBirth.year);
      printf ("phone Number : \n");
      scanf ("%d", &personsVec->phoneNumber);
      printf ("email : \n");
      scanf ("%s", &personsVec->email);
      getInterests (personsVec, interests);
    }
}

// ---------------------------------------------------------
//                         make Persons
//                          ---------
// General : The function check if the two persons are a match
//
// Parameters :
// humanOne- a pointer of person(in)
// humanTwo- a pointer of person(in)

// return: bool flag
// --------------------------------------------------------
bool
isAMatch (person * humanOne, person * humanTwo)
{
  bool flag = TRUE;

  // not same sex
  flag = (humanOne->sex != humanTwo->sex) ? flag : FALSE;

  // years dif smaller then 10
  flag =
    (MIN (ABS (humanOne->dateOfBirth.year - humanTwo->dateOfBirth.year), TEN))
    ? flag : FALSE;

  // same interests
  flag = ((humanOne->interests & humanTwo->interests)) ? flag : FALSE;


  return flag;
}

// ---------------------------------------------------------
//                         print Shared Interests 
//                          ---------
// General : The function print the places in the array that are lit in the result of an AND between two numbers
//
// Parameters :
// num1- mask of interests(in)
// num2- mask of interests(in)
// arr- arr of kind of interests(in)
// return: none
// --------------------------------------------------------
void
printSharedInterests (us num1, us num2, string arr[])
{
  us offset = 0;
  us I, sameBitsOn = num1 & num2;
  us A;
  A = 0X0001;
  for (I = 0; I < AMOUNT_OF_INTERESTS; I++, A <<= 1)
    {
      ! !(sameBitsOn & A) ? printf ("%s ", arr[offset]) : 0;
      offset++;
    }
}

// --------------------------------------------------------
//                         list Of Matches ]
//                          ---------
// General : The function prints all matches of person and what they have in common
//
// Parameters :
// human- a pointer of person(in)
// personsVec- a pointer of persons(in)
// size- amount of persons
// interests- arr of kind of interests(in)
// return: none
// --------------------------------------------------------
  void
listOfMatches (person * human, person * personsVec, us size,
	       string interests[])
{
  person *ptrEndPersons = personsVec + size - 1;
  while (personsVec++ <= ptrEndPersons)
    {
        isAMatch (human, personsVec) ?
        printSharedInterests (human->interests, personsVec        ->interests,
        interests), printf ("\nyears dif:%d\n",
					ABS ((human->dateOfBirth.year -
					personsVec -> dateOfBirth.year))) : 0;
    }
}

int
main ()
{
  string interests[AMOUNT_OF_INTERESTS] =
    { "art", "theater", "music", "travel", "literature", "sports",
"politics" };
  person v[20];
  makePersons (v, 20, interests);
  date d1 = { 1, 1, 2000 };
  person p1 = { "aa", "bb", "aa", 1, d1, 4343, "ffd", 71 };
  listOfMatches (&p1, v, 20, interests);


  return 0;
}
