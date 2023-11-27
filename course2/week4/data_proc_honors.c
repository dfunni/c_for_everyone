#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary Tree definition
typedef int DATA;
typedef struct node {
    DATA d;
    struct node *left;
    struct node *right;
} Node;

typedef Node *BTREE;

// Binary Tree creation 
BTREE new_node(void);
BTREE init_node(DATA d1, BTREE p1, BTREE p2);
BTREE create_tree(DATA a[], int i, int size);
// Binary Tree traversal
void inorder(BTREE root);
void preorder(BTREE root);
void postorder(BTREE root);
// File io functions
void read_data(FILE *fp, int d[], int *sz);
void write_data(FILE *fp, int *sz, int *mx, double *avg);
// array processing functions
double average(int d[], int *sz);
int max(int d[], int *sz);
// data visualization functions
void print_data(int d[], char *message);


int main() 
{
    FILE *ifp, *ofp;
    int size, mx;
    double avg;

    // open the files
    ifp = fopen("data.txt", "r");
    ofp = fopen("answer-hw4.txt", "w");
    // get the size (first) value
    fscanf(ifp, "%d", &size); 
    int data[size];                 // initialize the data array to specified size
    memset(data, 0, sizeof data);   // initialize array to 0s

    // read data into the array
    read_data(ifp, data, &size);

    // process the array data
    avg = average(data, &size);
    mx = max(data, &size);

    // print to console
    printf("There are %d integers\n", size);
    printf("Avg: %.4f\n", avg);
    printf("Max: %d\n", mx);
    print_data(data, "Data array");
    // write output file
    write_data(ofp, &size, &mx, &avg);
    // close files
    fclose(ifp);
    fclose(ofp);

    // Convert array to binary tree and print inorder traversal to console
    BTREE b;
    b = create_tree(data, 0, size);
    inorder(b);
    printf("\n");
    return 0;
}


// Binary Tree creation
BTREE new_node(void) 
{
    return (malloc(sizeof(Node)));
}

BTREE init_node(DATA d1, BTREE p1, BTREE p2) 
{
    BTREE t;
    t = new_node();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}

BTREE create_tree(DATA a[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return (init_node(a[i], 
                create_tree(a, 2*i + 1, size),
                create_tree(a, 2*i + 2, size)));
}

// Binary Tree processing
void inorder(BTREE root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->d);
        inorder(root->right);
    }
}

void preorder(BTREE root) 
{
    if (root != NULL) {
        printf("%d  ", root->d);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BTREE root) 
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c  ", root->d);
   }
}

// File io functions
void read_data(FILE *fp, int d[], int *sz)
{
    int i;
    for(i = 0; i < *sz; i++)
        fscanf(fp, "%d", &d[i]);
}

void write_data(FILE *fp, int *sz, int *mx, double *avg)
{
    fprintf(fp, "There are %d integers\n", *sz);
    fprintf(fp, "Avg: %.4f\n", *avg);
    fprintf(fp, "Max: %d\n", *mx);
}

// array processing functions
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

// data visualization functions
void print_data(int d[], char *message)
{
    int i;
    printf("%s:\n", message);
    for (i=0; i < sizeof(*d); i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
}