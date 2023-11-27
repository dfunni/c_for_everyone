#include <stdio.h>
#include <stdlib.h>



int main(void) {
    FILE *fp;
    char weight[7]; // 5 digit weights since elephant seals can be over 10000 lbs
    int sum = 0;
    int num_seals = 0;
    double avg;
    
    fp = fopen("elephant_seal_data.txt", "r");

    // size of 7 used to parse 4 digits + " /t"
    while (fgets(weight, 7, fp) != NULL) {
        sum += atoi(weight);
        num_seals++;
    }

    avg = sum / num_seals;
    printf("%.2f\n", avg);
    return 0;
}