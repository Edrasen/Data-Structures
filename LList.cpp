#include<iostream>

using namespace std;

typedef struct node
{
    node *next;
    int data;
    node(){
        next = NULL;
    }
    node(int d){
        data = d;
        next = NULL;
    }
}node;

node* create(int A[], int n)
{
    int i;
    node *aux, *last;
    node *first = new node(A[0]);
    last = first;

    for(i = 1; i<n; i++)
    {
        aux = new node(A[i]);
        last->next= aux;
        last = aux;
    }
    return first;
}

void display(node *p){
    while (p)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

int main()
{
    node *mylist;
    int A[] = {7, 9, 5, 3, 4};
    mylist = create(A, 5);
    display(mylist);
    return 0;
}
