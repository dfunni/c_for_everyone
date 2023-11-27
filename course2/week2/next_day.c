
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

// #define NDEBUG


int MAX_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef enum month { 
    jan, 
    feb,
    mar, 
    apr, 
    may, 
    jun, 
    jul, 
    aug, 
    sep, 
    oct, 
    nov, 
    dec
} month;

typedef struct date {
    month mon;
    int day;
} date;


date next_day(date today) {
    date tomorrow;
    if ((today.day+1) > MAX_DAYS[today.mon]) { // tomomrrow is new month
        tomorrow.mon = (today.mon + 1) % 12;
        tomorrow.day = 1;
    }
    else {
        tomorrow.mon = today.mon;
        tomorrow.day = today.day + 1; 
    }

    assert(today.day > 0);
    assert(today.day <= MAX_DAYS[today.mon]);
    assert(tomorrow.day > 0);
    assert(tomorrow.day <= MAX_DAYS[tomorrow.mon]);

    return tomorrow;
}


void print_day(date* pdate) {
    switch(pdate->mon) {
        case jan: printf("January"); break;
        case feb: printf("February"); break;
        case mar: printf("March"); break;
        case apr: printf("April"); break;
        case may: printf("May"); break;
        case jun: printf("June"); break;
        case jul: printf("July"); break;
        case aug: printf("August"); break;
        case sep: printf("September"); break;
        case oct: printf("October"); break;
        case nov: printf("November"); break;
        case dec: printf("December"); break;
        default: printf("ERROR"); break;
    }
    printf(" %d", pdate->day);
}


int main() {
    date test_cases[4] = {{feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}};
    for (int i=0; i < 4; i++) {
        date today = test_cases[i];
        date tomorrow = next_day(today);
        print_day(&today); printf(" -> "); print_day(&tomorrow); printf("\n");
    }
    return 0;
}
