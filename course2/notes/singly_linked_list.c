#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} list;

int is_empty(const list *l) {
    return (l == NULL);
}

list* create_list(int d) {
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list* add_to_front(int d, list* h){
    list* head = create_list(d);
    head->next = h;
    return head;
}

list* array_to_list(int d[], int size) {
    list* head = create_list(d[0]);
    int i;
    for (i=1; i<size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title) {
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d :", h->data);
        h = h->next;
    }
}

void print_list_recursive(list *h, char *title) {
    if (title) printf("%s\n", title);
    if (!is_empty(h)) {
        printf("%d :", h->data);
        print_list_recursive(h->next, NULL);
    }
}

int main() {
    list list_of_int;
    list *head = NULL;
    // head = malloc(sizeof(list));
    int data[6] = {2, 3, 5, 7, 8, 9};
    head = array_to_list(data, 6);
    printf("sizeof(list) = %lu bytes\n", sizeof(list)); // unsigned long
    // head->data = 5;
    // head->next = NULL;
    print_list(head, "multi-element list");
    printf("\n\n");
    return 0;
}