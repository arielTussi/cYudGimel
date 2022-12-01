#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define us unsigned short
#define MAX(x, y) (x > y) ? TRUE : FALSE
#define MIN(x, y) (x < y) ? TRUE : FALSE
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
typedef char string[12];

typedef struct book{
    string bookName;
    string authorName;
    string publishingCompanyName;
    us year;
    us price;
    us idBook;
}book;

unsigned short StringLen(string str)
{
    unsigned short count=0;
    while (str[count++]);
    
    return count-1;
    
}

bool isEqaul(string str1,string str2)
{
    unsigned short count=0,temp=0;
    while (str1[count]==str2[count++]?str2[++temp]:0);
    return !(StringLen(str1)-temp+(StringLen(str2)-temp));
    
}


void makeABook( book* booksVec, us size) {
    book* ptrEndBooks = booksVec+size-1;
    while(booksVec++ <= ptrEndBooks)
    {
        printf( "Book Name :\n");
        scanf("%s",&booksVec->bookName);
        printf( "Book author :\n");
        scanf("%s",&booksVec->authorName);
        printf( "Book publishing Company Name : \n"); 
        scanf("%s",&booksVec->publishingCompanyName);
        printf( "Book year : \n");
        scanf("%d",&booksVec->year);
        printf( "Book price : \n");
        scanf("%d",&booksVec->price);
        printf( "Book id : \n");  
        scanf("%d",&booksVec->idBook);

    }
}

void printBook( book* b ) {

   printf( "Book Name : %s\n", b->bookName);
   printf( "Book author : %s\n", b->authorName);
   printf( "Book  publishing Company Name  : %s\n", b->publishingCompanyName);
   printf( "Book year : %d\n", b->year);
   printf( "Book price : %d\n", b->price);
   printf( "Book id : %d\n", b->idBook);
}

void findABookByName( book* booksVec,us size,string name) {
    book* ptrEndBooks = booksVec+size-1;
    while(booksVec++ <= ptrEndBooks)
    {
      isEqaul(booksVec -> bookName,name) ? printBook(booksVec) : 0;

    }
}

void findABookByAuthor( book* booksVec,us size,string author) {
    book* ptrEndBooks = booksVec+size-1;
    while(booksVec++ <= ptrEndBooks)
    {
      isEqaul(booksVec -> authorName,author) ? printBook(booksVec) : 0;

    }
}

void findBooksInYears( book* booksVec,us size,us startYear,us endYear) {
    book* ptrEndBooks = booksVec+size-1;
    while(booksVec++ <= ptrEndBooks)
    {
      (endYear+1) > booksVec->year && (startYear-1) < booksVec->year ? printBook(booksVec) : 0;

    }
}


int main() {
    book v[2];
    makeABook(v,2);
    // findABookByAuthor(v,2,"aa");
    findBooksInYears(v,2,1999,2000);


    return 0;
}