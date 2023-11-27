#include <stdio.h>

int mystery(int p, int q){
    int r;
    if ((r = p % q) == 0)
        return q; 
    else 
        printf("%d %d\t", q,r);
        return mystery(q, r);
}

int main(void){
    printf("%d\n", mystery(7,91));
    return 0;
}