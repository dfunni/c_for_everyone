#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 200
#define NUM_COLUMNS 5
#define MAX_INT 50

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Linked list utilies
int is_empty(const Node *l);
Node* create_node(int d);
Node* add_to_front(int d, Node* h);
Node* array_to_list(int d[], int size);
Node* get_tail(Node *h);

// List processing
int compare(Node *p1, Node *p2);
void bubble(Node* h, int n);
void dedup(Node* h, int n);

// IO funcitons
void print_list(Node *h, int col);
void print_list_reverse(Node *t, int col);

int main() {
    Node* head = NULL;
    int data[SIZE];

    srand(time(NULL)); // seed the RNG
    
    // fill array with random values
    for (int i=0; i<SIZE; i++) {
        data[i] = rand() % MAX_INT;
    }
    
    head = array_to_list(data, SIZE);
    printf("Initial list:\n");
    print_list(head, NUM_COLUMNS);
    
    bubble(head, SIZE);
    printf("Sorted list:\n");
    print_list(head, NUM_COLUMNS);
    
    dedup(head, SIZE);
    printf("Deduped list:\n");
    print_list(head, NUM_COLUMNS);

    dedup(head, SIZE);
    printf("Deduped list reversed:\n");
    print_list_reverse(get_tail(head), NUM_COLUMNS);
    
    return 0;
}


int is_empty(const Node *l) {
    return (l == NULL);
}


Node* create_node(int d) {
    Node* head = malloc(sizeof(Node));
    head->data = d;
    head->next = NULL;
    head->prev = NULL;
    return head;
}


Node* add_to_front(int d, Node* h) {
    Node* head = create_node(d);
    h->prev = head;
    head->next = h;
    return head;
}


Node* array_to_list(int d[], int size) {
    Node* head = create_node(d[0]);
    for (int i=1; i<size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}


// find the tail of the list
Node* get_tail(Node *h) {
    while (!is_empty(h->next)) h = h->next;
    return h;
}


// compare node data and swap data if out of order
int compare(Node *p1, Node *p2) {
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
void bubble(Node* h, int n) {
    Node *head = h;
    int i, j, swapped = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            swapped += compare(h, h->next);
            h = h->next;
        }
        h = head; // reset back to front of list
        if (!swapped) break; // stop early if no swaps
        swapped = 0;
    }
}

void dedup(Node* h, int n) {
    Node *p1, *p2;

    while (!is_empty(h->next)) {
        p1 = h;
        p2 = h->next;
        if (p1->data == p2->data) { // duplicate
            p1->next = p2->next; // pass the next pointer to
            free(p2); // free memory and keep h in place
        }
        else {
            p2->prev = h;
            h = h->next; // no more duplicates, update h
        }
    }
}


// print list from head to tail
void print_list(Node *h, int col) {
    int i = 1;
    while(!is_empty(h)) {
        printf("%d\t", h->data);
        h = h->next;
        if (i % col == 0) printf("\n");
        i++;
    }
    printf("\n");
}


// print the list from tail to head
void print_list_reverse(Node *t, int col) {
    int i = 1;
    while(!is_empty(t)) {
        printf("%d\t", t->data);
        t = t->prev;
        if (i % col == 0) printf("\n");
        i++;
    }
    printf("\n");
}
