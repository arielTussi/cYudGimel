// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 1000
#define us unsigned short
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
#define ABS(x) (0 < x) ? x : -x
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


Stack reverseStack(Stack s)
{
    Stack sDst;
    inItStack(&sDst);
    
    while (!isEmpty(&s))
    {
        push(&sDst, pop(&s));
    }
    return sDst;
}

void
copyStack (Stack sSrc, Stack * sDst)
{
    inItStack (sDst);
    while (!isEmpty (&sSrc))
    {
        push (sDst, pop (&sSrc));
    }
    *sDst=reverseStack(*sDst);
}

bool
ifNumInStack (Stack s, short x)
{
    bool flag = FALSE;
    while (!isEmpty (&s))
    {
        flag = EQUAL (x, pop (&s)) ? TRUE : flag;
    }
    return flag;
}

us
totalItemsInStack (Stack s)
{
    us count = 0;
    while (!isEmpty (&s))
    {
        count++;
        pop (&s);
    }
    return count;
}

void
splitStack (Stack s, Stack * sDstFlase, Stack * sDstTrue)
{
    bool flag;
    short temp;
    inItStack (sDstFlase);
    inItStack (sDstTrue);
    while (!isEmpty (&s))
    {
        temp = pop (&s);
        EQUAL (temp % 2, 0) ? push (sDstTrue, temp) : push (sDstFlase, temp);
    }
}

void
unitedStack (Stack sOne, Stack sTwo, Stack * sDst)
{
    inItStack (sDst);
    sOne = reverseStack (sOne);
    sTwo = reverseStack (sTwo);
    while (!isEmpty (&sOne))
    {
        push (sDst, pop (&sOne));
    }
    while (!isEmpty (&sTwo))
    {
        push (sDst, pop (&sTwo));
    }
}

void
emptyStack (Stack * s)
{
    while (!isEmpty (s))
    {
        pop (s);
    }
}

bool
isEqualStacks (Stack s1, Stack s2)
{
    bool flag = TRUE;
    while (!isEmpty (&s1) && !isEmpty (&s2))
    {
        flag = EQUAL (pop (&s1), pop (&s2)) ? flag : FALSE;
    }
    flag *=  isEmpty (&s1) * isEmpty (&s2);
    return flag;
}

short
sumStack (Stack s)
{
    short sum = 0;
    while (!isEmpty (&s))
    {
        sum += pop (&s);
    }
    return sum;
}

void
printStack (Stack s)
{
    s = reverseStack(s);
    while (!isEmpty (&s))
    {
        printf ("%d ", pop (&s));
    }
}


int
main ()
{
  Stack s;
  Stack s2;
  Stack s3;

  inItStack (&s);
  inItStack (&s2);
  push (&s, 1);
  push (&s, 2);
  push (&s2, 4);
  push (&s2, 1);
  push (&s2, 2);
  printf("%d",isEqualStacks(s,s2));

  return 0;
}
