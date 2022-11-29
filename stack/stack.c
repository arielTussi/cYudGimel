// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 1000
#define us unsigned short
#define FALSE 0
#define TRUE 1
#define bool unsigned char
typedef struct Stack
{
  us vec[SIZE];
  short top;
} Stack;

inItStack(Stack* s)
{
    s.top = -1;
}

void push(Stack* s,us x )
{
    s.vec[++s.top]=x;
}
us pop(Stack* s)
{
    us head = s.vec[s.top];
    s.top--;
    return head;
}
bool isEmpty(Stack* s)
{
    return (s.top == -1);
}
 
int main() {
    // Write C code here
    printf("Hello world");

    return 0;
}