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

bool chckOrdr(node *lp){
    int x = 0;
    node *aux = lp;
    while (aux)
    {
        if(aux->data < x)
            return false;
        x = aux->data;
        aux = aux->next;
    }
    return true;
}
void sortedver(bool f){
    if(f){
        printf("List is sorted\n");
    }
    else
    {
        printf("List is not sorted\n");
    }
}

void rmvrep(node *lp){
    node *p = lp;
    node *q = lp->next;
    while (q)
    {
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else
        {          
            p->next = q->next;
            delete(q);
            q = p->next;
        }
    }   
}

void reversewar(node *&lp){
    int *A;
    int i = 0;
    node *q = lp;
    A = (int*)malloc(sizeof(int)*count(lp));
    while (q)
    {
        A[i] = q->data;
        i++;
        q = q->next;
    }
    q = lp;
    while(q)
    {
        i--;
        q->data = A[i];
        q = q->next;
    }
}

void revers(node *&lp){
    node *p = lp;
    node *q = NULL;
    node *r;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    lp = q;
}
void Rrevers(node *q, node *lp, node *&list)
{  
    if(lp){
        Rrevers(lp, lp->next, list);
        lp->next = q;
    }
    else
    {
        list = q;
    }    
}

node* concat(node *lp1, node *lp2){
    node *aux = lp1;
    while (aux->next)
    {
        aux = aux->next;
    }
    aux->next = lp2;
    lp2 = NULL; 
    return lp1;
}

node* merging(node *l1, node *l2){
    node *aux = NULL;
    node *last = NULL;
    if(l1->data < l2->data){
        aux = last = l1;
        l1 = l1->next;
        aux->next = NULL;
    }
    else{
        aux = last = l2;
        l2 = l2 ->next;
        aux->next = NULL;
    }
    while (l1 && l2)
    {
        if(l1->data < l2->data){
            last->next = l1;
            last = l1;
            l1 = l1->next;
            last->next = NULL;
        }
        else{
            last->next = l2;
            last = l2;
            l2 = l2->next;
            last->next = NULL;
        }
        if(l1)last->next = l1;
        if(l2)last->next = l2; 
    }
    return aux;
}

bool isloop(node *lp){
    node *p, *q;
    p = q = lp;
    do{
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : NULL;
    }while (p&&q && p!=q);
    if(p == q)
        return true;
    else
    {
        return false;
    }
}

void loopver(bool f){
    if(f){
        printf("\nThere is a loop\n");
    }
    else
    {
        printf("\nThere is not a loop\n");
    }
}

int main()
{ 
    node *mylist;
    node *mylist2;
    node *temp;
    node *concatelist;
    node *t1;
    node *t2;
    int B[] = {10, 20, 20, 20, 30, 40, 50};
    int A[] = {3, 5, 7, 9, 12, 24};
    mylist = create(A, 6);
    mylist2 = create(B,7);
    Rdisplay(mylist);
    printf("\nNumber of nodes is %d\n", Rcount(mylist));
    printf("Sum of data in nodes is %d\n", Rsum(mylist));
    printf("Maximum number in nodes is %d\n", MaxNmbr(mylist));
    /*temp = lsearch(mylist, 9);
    temp = lsearch(mylist, 2);
    temp = lsearch(mylist, 4);
    verification(temp);*/
    //insert(mylist, 15, 3);
    //insertLst(mylist, 24);
    //insertaftr(mylist, 2);
    //insinor(mylist,1);
    //delfirst(mylist);
    //delkey(mylist, 24);
    Rdisplay(mylist);
    printf("\nNumber of nodes is %d\n", Rcount(mylist));
    printf("last element on the list is %d \n", (last(mylist)->data));
    sortedver(chckOrdr(mylist));
    //revers(mylist);
    //reversewar(mylist);
    //Rrevers(NULL, mylist, mylist);
    Rdisplay(mylist);
    printf("\n");
    //using mylist2
    //Rdisplay(mylist2);
    rmvrep(mylist2);
    printf("\n");
    rmvrep(mylist2);
    Rdisplay(mylist2);
    printf("\n");
    //concatenated list
    printf("\n");
    //concatelist = concat(mylist, mylist2);
    Rdisplay(merging(mylist, mylist2));
    printf("\n");
    //printf("\n");
    //printf("\n");
    /////////Proving loops
    /* 
    t1 = mylist->next->next;
    t2 = mylist->next->next->next->next->next;
    t2->next = t1;
    loopver(isloop(mylist));
    */
    return 0;
}
