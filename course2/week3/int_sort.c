#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 100
#define NUM_COLUMNS 5
#define MAX_INT 1000

typedef struct List {
    int data;
    struct List *next;
} List;


int is_empty(const List *l) {
    return (l == NULL);
}


List* create_list(int d) {
    List* head = malloc(sizeof(List));
    head->data = d;
    head->next = NULL;
    return head;
}


List* add_to_front(int d, List* h) {
    List* head = create_list(d);
    head->next = h;
    return head;
}


List* array_to_list(int d[], int size) {
    List* head = create_list(d[0]);
    for (int i=1; i<size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}


void print_list(List *h, int col) {
    for (int i = 1; i < SIZE+1; i++) {
        printf("%d\t", h->data);
        h = h->next;
        if (i % col == 0) printf("\n");
    }
    printf("\n");
}


// compare node data and swap data if out of order
int compare(List* p1, List* p2) {
    int swapped = 0;
    assert (p1->next == p2);
    if (p1->data > p2->data) {
        swapped = 1;
        int tmp = p2->data;
        p2->data = p1->data;
        p1->data = tmp;
    }
    return swapped;
}


// iterative bubble sort swapping nodes where necessary
void bubble(List* h, int n) {
    List *head = h;
    int i, j, swapped = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            swapped += compare(h, h->next);
            h = h->next;
        }
        h = head;
        if (!swapped) break; // stop early if no swaps
        swapped = 0;
    }
}


int main() {
    List* head = NULL;
    int data[SIZE];

    srand(time(NULL)); // seed the RNG

    for (int i=0; i<SIZE; i++) {
        data[i] = rand() % MAX_INT;
    }
    head = array_to_list(data, SIZE);
    printf("Initial list:\n");
    print_list(head, NUM_COLUMNS);
    bubble(head, SIZE);
    printf("Sorted list:\n");
    print_list(head, NUM_COLUMNS);
    return 0;
}