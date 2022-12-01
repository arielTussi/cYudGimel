#include <stdio.h>
#define SIZE 1000
#define us unsigned short
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define ZERO 0
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define SMALLER(x, y) (x < y) ? TRUE : FALSE
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define ABS(x) (0 < x) ? x : -x
typedef char string[12];
typedef struct Stack
{
  us vec[SIZE];
  short top;
} Stack;

void
inItStack (Stack * s)
{
  s->top = -1;
}

void
push (Stack * s, us x)
{
  s->vec[++s->top] = x;
}

us
pop (Stack * s)
{
  us head = s->vec[s->top];
  s->top--;
  return head;
}

bool
isEmpty (Stack * s)
{
  return (s->top == -1);
}
// receives a string that starts with a sequence of the letter A and then a sequence of the letter B.
// Check whether the number of appearances of A is equal to the number of appearances of B.
bool 
checkIfStrHaveEqualAB(string str)
{
    Stack sTemp;
    inItStack (&sTemp);
    us count = 0;
    while(str[count])
    {
        EQUAL(str[count++],'A') ? push(&sTemp,1): pop(&sTemp);
    }
    return isEmpty(&sTemp);
}


int main() {
    // Write C code here
    printf("%d",checkIfStrHaveEqualAB("AAAAABBBBB"));

    return 0;
}