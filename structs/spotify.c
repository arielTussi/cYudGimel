// Online C compiler to run C program online
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define bool unsigned char
#define us unsigned short
#define AMOUNT_OF_SUBSCRIBERS 2000
#define AMOUNT_OF_MALE_SINGER 200
#define AMOUNT_OF_FEMALE_SINGER 200
#define AMOUNT_OF_BANDS 300
#define AMOUNT_OF_GENERES 41
#define MAX(x, y) (x > y) ? TRUE : FALSE
#define MIN(x, y) (x < y) ? TRUE : FALSE
#define EQUAL(x, y) !(x - y)
#define NOTEQUAL(x, y) !!(x - y)
#define POSITIVE(x) (0 < x) ? TRUE : FALSE
typedef char string[12];

typedef struct Date
{
  us day;
  us month;
  us year;
} Date;

typedef struct Song
{
  long genere;
} Song;

typedef struct Performer
{
  long genere;
  Song songs[];
} Performer;

typedef struct Play
{
  Song song;
  Date date;
  Performer p;
} Play;

typedef struct Subscriber
{
  long genere;
  Play playlist[];
} Subscriber;


typedef struct Spotify
{
  Subscriber subscriberVec[AMOUNT_OF_SUBSCRIBERS];
  Performer maleSingerVec[AMOUNT_OF_MALE_SINGER];
  Performer femaleSingerVec[AMOUNT_OF_FEMALE_SINGER];
  Performer bandVec[AMOUNT_OF_BANDS];
  string genereVec[AMOUNT_OF_GENERES];
} Spotify;

int
main ()
{
  // Write C code here
  printf ("Hello world");

  return 0;
}
