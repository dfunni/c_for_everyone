#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_data(FILE *fp, int d[], int *sz)
{
    int i;
    for(i = 0; i < *sz; i++)
        fscanf(fp, "%d", &d[i]);
}

double average(int d[], int *sz)
{
    int i;
    double avg = 0.0;
    for (i = 0; i < *sz; i++) {
        avg += d[i];
    }
    return (avg / *sz);
}

int max(int d[], int *sz)
{
    int i;
    int max = 0;
    for (i = 0; i < *sz; i++) {
        if (d[i] > max) max = d[i];
    }
    return (max);
}

void write_data(FILE *fp, int *sz, int *mx, double *avg)
{
    fprintf(fp, "There are %d integers\n", *sz);
    fprintf(fp, "Avg: %.4f\n", *avg);
    fprintf(fp, "Max: %d\n", *mx);
}

int main() 
{
    FILE *ifp, *ofp;
    int size, mx;
    double avg;
    ifp = fopen("data.txt", "r");
    ofp = fopen("answer-hw4.txt", "w");

    fscanf(ifp, "%d", &size); // get the size (first) value
    
    int data[size];           // initialize the data array to specified size
    memset(data, 0, sizeof data); // initialize array to 0s
    read_data(ifp, data, &size);

    avg = average(data, &size);
    mx = max(data, &size);

    printf("There are %d integers\n", size);
    printf("Avg: %.4f\n", avg);
    printf("Max: %d\n", mx);
    write_data(ofp, &size, &mx, &avg);
    fclose(ifp);
    fclose(ofp);
}