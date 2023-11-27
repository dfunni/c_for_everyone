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

int count();

list* concat();

list* insert();

list* delete();

void print_list_recursive(list *h, char *title) {
    if (title) printf("%s\n", title);
    if (!is_empty(h)) {
        printf("%d :", h->data);
        print_list_recursive(h->next, NULL);
    }
}