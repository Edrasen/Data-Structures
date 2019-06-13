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

void insert(node *lp, int index, int x){
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
        for (i = 0; i < index-2; i++)aux = aux->next;
        nnode = new node(x);
        nnode->next = aux->next;
        aux->next = nnode;
    }
    
}

int main(){
    node *myCList;
    int A[]={3,5,7,9,12};
    myCList = create(A, 5);
    insert(myCList,3, 45);
    Rdisplay(myCList, myCList);
    printf("\n");
    return 0;
}