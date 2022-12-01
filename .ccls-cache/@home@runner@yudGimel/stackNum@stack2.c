// Online C compiler to run C program online
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

// receives two stacks and returns a stack with the numbers common to both stacks
void
appearsInBothStacks(Stack s1, Stack s2,Stack* sNew)
{
    inItStack (sNew);
    bool flag = TRUE;
    short sTop;
    s1=reverseStack(s1);
    while (!isEmpty (&s1))
    {
        sTop =pop(&s1);
        flag = ifNumInStack(s2,sTop) && 
        !ifNumInStack(*sNew,sTop);
        flag ? push(sNew,sTop) : FALSE;
    }
}

// receives two stacks and returns a stack with numbers that appear in the first stack and not in the second stack
void
appearsJustInFIrstStack(Stack s1, Stack s2,Stack* sNew)
{
    inItStack (sNew);
    bool flag = TRUE;
    short sTop;
    s1=reverseStack(s1);
    while (!isEmpty (&s1))
    {
        sTop =pop(&s1);
        flag = !ifNumInStack(s2,sTop) && 
        !ifNumInStack(*sNew,sTop);
        flag ? push(sNew,sTop) : FALSE;
    }
}
// receives two stacks and returns a stack with numbers that appear in the second stack and not the first
void
appearsJustInSecondStack(Stack s1, Stack s2,Stack* sNew)
{
    inItStack (sNew);
    bool flag = TRUE;
    short sTop;
    s2=reverseStack(s2);
    while (!isEmpty (&s2))
    {
        sTop =pop(&s2);
        flag = !ifNumInStack(s1,sTop) && 
        !ifNumInStack(*sNew,sTop);
        flag ? push(sNew,sTop) : FALSE;
    }
}


// receives a stack of repeating integers. The function  checks that each number Appears only once.
bool
ifAppearsOnlyOnceInSatck(Stack s1)
{
    Stack sTemp;
    inItStack (&sTemp);
    copyStack(s1,&sTemp);
    s1=reverseStack(s1);
    appearsInBothStacks(s1,sTemp,&sTemp);
    return isEqualStacks(s1,sTemp);
    
}

// accepts a stack and a numeric value. The function will return the number of occurrences of the value in the stack.
short
frequencyOfDigitInStack (Stack s,short num)
{
    short count = 0;
    while (!isEmpty (&s))
    {
        count += EQUAL(pop (&s),num);
    }
    return count;
}




// the member in which the order of the members has been reversed.
short 
whereOrderReversed(Stack s)
{
    bool flag = TRUE; 
    short smaller,bigger;
    while (!isEmpty (&s) && flag)
    {
        smaller = pop(&s);
        bigger = pop(&s);
        flag = SMALLER(smaller,bigger);
        flag ? push(&s,bigger) : push(&s,smaller);
    }
    return pop(&s);
}
// the place in which the order of the members has been reversed.
short 
placeWhereOrderReversed(Stack s)
{
    bool flag = TRUE; 
    short smaller,bigger,count=0;
    while (!isEmpty (&s) && flag)
    {
        smaller = pop(&s);
        bigger = pop(&s);
        flag = SMALLER(smaller,bigger);
        push(&s,bigger);
        count++;
    }
    return count;
}
// there is only one member of each value (deleting duplicates).
void
deleteDuplicatesInStack(Stack* s)
{
    short sTop;
    Stack sTemp;
    inItStack (&sTemp);
    while(!ifAppearsOnlyOnceInSatck(*s))
    {
        // printf("ff");

        sTop =pop(s);
        // printf("%d ",frequencyOfDigitInStack(*s,sTop));
        EQUAL(frequencyOfDigitInStack(*s,sTop),ZERO) ?
        push(&sTemp,sTop) : FALSE;
    }
    unitedStack(*s,sTemp,s);
    *s=reverseStack(*s);

}


int
main ()
{
  Stack s;
  Stack s2;
  Stack s3;
    inItStack (&s);
    inItStack (&s2);
    push (&s, 0);
    push (&s, 3);
    push (&s, 6);
    push (&s, 6);
    push (&s, 35);
    
    push (&s2, 0);
    push (&s2, 6);
    push (&s2, 6);
    push (&s2, 3);
    push (&s2, 35);
    deleteDuplicatesInStack(&s);
    //   printf("%d",placeWhereOrderReversed(s));
    //   printf("%d", frequencyOfDigitInStack(s,35));

    printStack(s);

  return 0;
}
