// Program to create a table of sine and cos values in (0,1)
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(void)
{ 
    float radians;
    printf(" arg  | sin    | cos    \n=======================\n"); // header
    for (int i = 0; i < 101; i++) {
        radians = i / 100.0;
        printf(" %0.2f | %0.4f | %0.4f\n", radians, sin(radians), cos(radians));
    }
    return 0;
}
