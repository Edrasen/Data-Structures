#include<iostream>

using namespace std;

typedef struct node{
    node *prev;
    int data;
    node *next;
    
    node(){
        next = prev = NULL;
    }

    node(int d){
        data = d;
        next = prev = NULL;
    }
}node;

node* create(int A[], int n){
    int i;
    node *aux;
    node *last;
    node *first = new node(A[0]);
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        aux = new node(A[i]);
        aux->next = last->next;
        aux->prev = last;
        last->next = aux;
        last = aux;
    }
    return first;
}

void Display(node *lp){
    while (lp)
    {
        printf("%d \t", lp->data);
        lp = lp->next;
    }
}

int count(node *lp){
    int i = 0;
    while (lp)
    {
        i++;
        lp = lp->next;
    }
    return i;
}
//function to insert a new element AFTER a given position
void insert(node *&lp, int index, int x){
    int i;
    node *p = lp;
    node *aux;
    if(index < 0 || index > count(lp))
        return;
    if(index == 0){
        aux = new node(x);
        aux->next = lp;
        lp->prev = aux;
        lp = aux;
    }
    else
    {
        for(i = 0; i < index-1; i++)
            p = p->next;
        aux = new node(x);
        
        aux->prev = p;
        aux->next = p->next;
        if(p->next)p->next->prev = aux;
        p->next = aux; 
    }
}

int rmv(node *&lp, int index){
    int x = -1, i;
    node *p = lp;
    if(index < 1 || index > count(lp))
        return -1;
    if(index == 1){
        lp = lp->next;
        if(lp)lp->prev = NULL;
        x = p->data;
        delete(p);
    }
    else{
        for(i = 0; i < index-1; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete(p);
    }
    return x;
}

int main(){
    int A[] = {3, 5 ,7, 9};
    node *myDLlist;
    myDLlist = create(A, 4);
    Display(myDLlist);
    insert(myDLlist, 3, 18);
    printf("\n");
    rmv(myDLlist, 1);
    Display(myDLlist);
    printf("\nEl numero de nodos en la lista es %d\n", count(myDLlist));
}