#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {
    int data;
    struct list *next;
} list;

int is_empty(const list *l) 
{
    return (l == NULL);
}

list* create_list(int d) 
{
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list* add_to_front(int d, list* h) 
{
    list* head = create_list(d);
    head->next = h;
    return head;
}

list* array_to_list(int d[], int size) 
{
    list* head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d\t", h->data);
        h = h->next;
    }
    printf("\n\n");
}

int count(list *h)
{
    int i = 0;
    while(h != NULL) {
        i++;
        h = h->next;
    }
    return i;
}

void delete(list *elem, list **prev, list **hd) // pointer to pointer passed to allow manipulation of pointers
{ 
    if (*hd == *prev) // elem is head of list
        *hd = elem->next; // replace head with elem->next
    else    // elem is internal to list
        (*prev)->next = elem->next; // requires both the element to delete and the reference to it's previous element for relinking to elem->next
    free(elem); // clear memory
}

void delete_list(list *h)
{
    list *temp;
    if (h != NULL){
        temp = h;
        delete_list(h = h->next); // recursively get to end of list and delete elements backward from there
        free(temp);
    }
}

void concat(list *h1, list *h2)
{
    if (h1 == NULL) h1 = h2; // empty h1
    else if (h1->next == NULL) h1->next = h2; // single item h1
    else concat(h1->next, h2); // recursively go to end of h1 and concat h2
}

int main()
{
    list *head1 = NULL, *head2 = NULL;
    int data[6] = {2, 3, 5, 7, 8, 9};
    int data2[] = {17, 6, 99};
    head1 = array_to_list(data, 6);
    head2 = array_to_list(data2, 3);
    print_list(head1, "data[6] made into a 6 element list");
    print_list(head2, "data[3] made into a 3 element list");
    concat(head1, head2);
    print_list(head1, "concatenated list");
    printf("\nSize of concat list is %d\n", count(head1));
    delete(head1, &head1, &head1); // delete first element from head1
    print_list(head1, "delet from front of list");
    delete(head1->next->next, &head1->next, &head1);
    print_list(head1, "delete head1[2] from list");
    printf("\n");
    return 0;

}