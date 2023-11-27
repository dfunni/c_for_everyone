#include <stdio.h>
#include <stdlib.h>

#define MAX_HW 10

void read_data(FILE *fp, int data[], int* size);
double average(int d[], int size);
void print_data(int data[], int size);

int main() {
    int sz = MAX_HW;
    FILE *ifp;
    ifp = fopen("myhw.txt", "r");

    int data[MAX_HW];
    read_data(ifp, data, &sz);
    printf("my %d homework scores are:\t", sz);
    print_data(data, sz);
    printf("\naverage score was %10f\n", average(data, sz));
    fclose(ifp);
}

void read_data(FILE *fp, int d[], int *size) {
    *size = 0;
    while(fscanf(fp, "%d", &d[*size]) == 1) {
        (*size)++;
    }
}

double average(int d[], int size) {
    int i;
    double avg = 0.0;
    for (i = 0; i < size; i++) {
        avg += d[i];
    }
    return (avg / size);
}

void print_data(int d[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", d[i]);
        if ((i+1) % 10 == 0) printf("\n");
    }
}
