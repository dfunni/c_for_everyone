#include <stdio.h>

int main(void) {
    int a = 3; // declare an integer variable a with value of 3
    int *p = &a; // assign the address of a to int pointer p
    printf("address: %p\nvalue: %d\n", p, *p); // print the address and value using pointer notation
    printf("address: %p\nvalue: %d\n", &a, a); // print the address and value using variable notation
}