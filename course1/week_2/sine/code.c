#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(void)
{ 
    /* Takes user input of angle in degrees and outputs the value 
    of sin(deg) */
    float degrees, radians;

    printf("Enter an angle in degrees:");
    scanf("%f", &degrees);

    radians = PI * degrees / 180 ;
    
    printf("sine(%f) = %f\n ", degrees, sin(radians));
    return 0;
}
