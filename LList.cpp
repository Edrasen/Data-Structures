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

int MaxNmbr(node *pl){
    int max = -32768; //min_INT
    while(pl){
        if(pl->data > max){
            max = pl->data;
        }
        pl = pl->next;
    }
    return max;
}

int RMax(node *pl){
    int max = -32768;
    if(pl == NULL){
        return max;
    }
    else{
        max = RMax(pl->next);
        return (max < pl->data)? pl->data : max;
    }
}

node* search(node * pl, int key)
{
    while(pl){
        if(key == pl->data)
            return pl;
        pl = pl->next;
    }
    return NULL;
}

node* rsearch(node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    rsearch(p->next, key);
}

node* lsearch(node *&ls, int key)
{
    node *aux = ls;
    node *q;
    while (aux != NULL)
    {
        if(key == aux->data)
        {
            q->next = aux->next;
            aux->next = ls;
            ls = aux;
            return aux;
        }
    q = aux;
    aux = aux->next;
    }
}

void verification(node *temp)
{
    if(temp){
        printf("Key was found %d\n", temp->data);
    }
    else{
        printf("Key not found\n");
    } 
}

void push(node *&pl, int data){
    //Inserting at first
    node *nnode = new node(data);
    nnode->next = pl;
    pl = nnode;
}

void insert(node *pl, int data, int pos){
    //inserting after a given position
    int i;
    node *aux = pl;
    node *nwnode = new node(data);
    //if you want add new data in the specific 
    //position given it is need to use "pos-1" instead "pos"
    for(i = 0; i < pos-1; i++){
        aux = aux->next;
    }
    nwnode->next = aux->next;
    aux->next = nwnode;  
}

node *last(node *lp){
    while (lp->next)
    {
     lp = lp->next;   
    }
    return lp;
}

void insertLst(node *lp, int data){
    node *lst = last(lp);
    node *aux =  new node(data);
    lst->next = aux;
    lst = aux;
}

void insertaftr(node *lp, int x){ //this function works using an extra pointer too
    node *aux = lp;
    while(aux && aux->data < x){
        aux = aux->next;
    }
    if(!aux){               //aux = NULL
        insertLst(lp, x);
    }
    else{
    node *nnode = new node(aux->data);
    aux->data = x;
    nnode->next = aux->next;
    aux->next = nnode;
    }
}
//Inserting in a sorted list
void insinor(node *&lp, int x){
    node *q;
    node *p = lp;
    while(p && p->data < x){
        q = p;
        p = p->next;
    }  
    if(p == lp){
      push(lp, x);  
    } 
    else{
    node *nnode = new node(x);
    nnode->next = q->next;
    q->next = nnode;
    }    
}

int delfirst(node *&lp){
    node *aux = lp;
    lp = aux->next;
    delete(aux);
}

int delkey(node *&lp, int key){
    node *p = lp;
    node *q = NULL; 
    while(p){
        if(!q && p->data == key){
            delfirst(lp);
        }
        else{
            if(p->data == key)
            {
                q->next = p->next;
                delete(p);
            }
        }
        q = p;
        p = p->next;
    }
}

int main()
{
    node *mylist;
    node *temp;
    int A[] = {3, 5, 7, 9, 12, 24};
    mylist = create(A, 6);
    Rdisplay(mylist);
    printf("\nNumber of nodes is %d\n", Rcount(mylist));
    printf("Sum of data in nodes is %d\n", Rsum(mylist));
    printf("Maximum number in nodes is %d\n", MaxNmbr(mylist));
    /*temp = lsearch(mylist, 9);
    temp = lsearch(mylist, 2);
    temp = lsearch(mylist, 4);
    verification(temp);*/
    /*insert(mylist, 12, 3);
    push(mylist, 6); //we have added into the front part (also we can name it push)
    insertLst(mylist, 24);*/
    //insertaftr(mylist, 2);
    //insinor(mylist,1);
    //delfirst(mylist);
    delkey(mylist, 24);
    Rdisplay(mylist);
    printf("\nNumber of nodes is %d\n", Rcount(mylist));
    printf("last element on the list is %d \n", (last(mylist)->data));
    return 0;
}
