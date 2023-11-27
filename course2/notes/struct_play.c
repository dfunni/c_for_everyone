#include <stdio.h>

struct complex {
    double real;
    double imag;
} c1, c2, c3;

typedef struct {
    float real;
    float imag;
} cplx_t;

int main() {
    struct complex* ptr = &c1;
    // cplx_t num = {1.1, 2.2};
    struct complex num = {1.11, 2.22};
    printf("%.2f, %.2f\n", num.real, num.imag);
    printf("%f, %f\n", ptr->real, ptr->imag);
}