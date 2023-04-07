#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int day;
  int month;
  int year;
} Date;

int differenceBetweenDates(Date *date1, Date *date2){
  int difference = 0;
  difference += (date1->year - date2->year) * 365;
  difference += (date1->month - date2->month) * 30;
  difference += (date1->day - date2->day);
  return difference;
}

void main(){
  
  Date *date1 = malloc(sizeof(Date));
  Date *date2 = malloc(sizeof(Date));

  date1->day = 15;
  date1->month = 1;
  date1->year = 2001;

  date2->day = 23;
  date2->month = 03;
  date2->year = 2023;

  int difference = differenceBetweenDates(date2, date1);
  

  printf("Difference between dates in years: %d)", difference/365);
}