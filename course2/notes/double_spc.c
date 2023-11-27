#include <stdio.h>
#include <stdlib.h>

void print_file(FILE *fptr) {
    int c;
    rewind(fptr);
    while ((c = getc(fptr)) != EOF) {
        putc(c, stdout);
    }
}

void double_space(FILE *ifp, FILE *ofp) {
    int c;
    rewind(ifp);
    while ((c = getc(ifp)) != EOF ) {
        putc(c, ofp);
        if (c == '\n') putc('\n', ofp); // single quotes are important here for some reason
    }
}

int main(int argc, char *argv[]) {
    FILE *ifp, *ofp;

    if (argc != 3) {
        printf("Usage: a.out inputfile outputfile\n");
        exit(1);
    }

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");
    print_file(ifp);
    printf("\n\n");
    double_space(ifp, ofp);
    print_file(ofp);
    printf("\n\n");
    fclose(ifp);
    fclose(ofp);
}
