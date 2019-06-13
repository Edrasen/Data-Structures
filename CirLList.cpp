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

node* create(int A[], int n){
    int i;
    node *aux, *last;
    node *head = new node (A[0]);
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        aux = new node(A[i]);
        aux->next = last->next;
        last->next = aux;
        last = aux;
    }
    return head;
}

void Display(node *lp){
    node *p = lp;
    do{
        printf("%d\t", p->data);
        p = p->next;
    }while(p != lp);
}

void Rdisplay(node *lp, node *aux){
    static int flag = 0;
    if(aux != lp || flag == 0)
    {
        flag = 1;
        printf("%d\t", lp->data);
        Rdisplay(lp->next, aux);
    }
    flag = 0;
}

void insert(node *&lp, int index, int x){
    node *nnode;
    node *aux = lp;
    int i;

    if(index == 0){
        nnode = new node(x);
        if (lp == NULL)
        {
            lp = nnode;
            nnode->next = nnode;
        }  
        else
        {
            while (aux->next != lp)aux = aux->next;
            aux->next = nnode;
            nnode->next = lp;
            lp = nnode;
        }
    }
    else
    {
        //insert after a given position. 
        //If you want to locate new data at the specific position given use "index-2" instead
        for (i = 0; i < index-1; i++)aux = aux->next;
        nnode = new node(x);
        nnode->next = aux->next;
        aux->next = nnode;
    }
    
}

int del(node *lp, int index){
    int x;
    node *q;
    node *aux = lp;
    int i;
    if (index == 1)
    {
        while (aux->next != lp)
        {
            aux = aux->next;
        }
        x = lp->data;
        if (aux==lp)
        {
            delete(lp);
            lp = NULL;
        }
        else
        {
            aux->next = lp->next;
            delete(lp);
            lp = aux->next;
        }
    }
    else
    {
        for (i = 0; i < index-2; i++)
        {
            aux = aux->next;
        }
        q = aux->next;
        aux->next = q->next;
        x = q->data;
        delete(q);
    }
    return x;
}

int main(){
    node *myCList;
    int A[]={3,5,7,9,12};
    myCList = create(A, 5);
    insert(myCList,4, 45);
    del(myCList, 4);
    Rdisplay(myCList, myCList);
    printf("\n");
    return 0;
}