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
        printf("%d \t", p->data);
        p = p->next;
    }
}

void Rdisplay(node *p){
    if(p != NULL){
        printf("%d\t", p->data);
        Rdisplay(p->next);
    }
}

int count(node *p){
    int x;
    while(p){
        x++;
        p = p->next;
    }
    return x;
}

int Rcount(node *p){
    return  p == NULL ? 0 : Rcount(p->next) + 1;
}

int Suma(node *p){
    int sum = 0;
    while (p)
    {
        sum+=(p->data);
        p = p->next;
    }
    return sum;
}

int Rsum(node *p){
    return p == NULL ? 0 : Rsum(p->next) + p->data;
}

int main()
{
    node *mylist;
    int A[] = {7, 9, 5, 3, 4,2};
    mylist = create(A, 6);
    Rdisplay(mylist);
    printf("\nNumber of nodes is %d\n", Rcount(mylist));
    printf("Sum of data in nodes is %d\n", Rsum(mylist));
    return 0;
}
