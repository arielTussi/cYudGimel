
//---------------------------------------------------------
//                      ptrLenStr   
//                      ---------
// General : The function calculates the numbers of chars
//
// Parameters :
// nNum- number
// *sPtr - pointer of char, string (In)
// count - amount of chars
// return: amount of chars in string.
// -------------------------------------------------------
unsigned short
ptrLenStr (char *sPtr)
{
  unsigned short count;
  count = 0;
  while (*(sPtr++))
    {
      count++;
    }
  return count;
}
char* end_of_string(char *ptr)
{
    char *end = ptr;
    while(*(end++));
    
    return end;
        
}

char* SearchCharInString (char *str, char tav)
{
char *start= str;
while(*(start) != tav && *(start++) );
return start;
}

void copy_str(char *pointer_str1 , char *pointer_str2)
{
   
    while(*(pointer_str1++) = *(pointer_str2++));

}

// void ptrReverseStr(char * ptr)
// {
//     char *end  = end_of_string(ptr)-1;  
//     while(str<end)
//     *str = *end;
// }

bool tavInString(char * sPtr,char letter)
{
    unsigned short count=0;
    while(*(sPtr++))
    {
        count+=EQUAL(*sPtr,letter);
    }
    return POSITIVE(count);
}
unsigned short amountOfTavInString(char * sPtr,char letter)
{
    unsigned short count=0;
    char * placeOfTav;
    while(*(sPtr++))
    {
        EQUAL(*sPtr,letter);
    }
    return count;
}


