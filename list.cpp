#include<iostream>


using namespace std;

typedef struct node{
    int info;  
    node *next;
    node(int x){
        info = 0;
     next = NULL;

    }
};

void push(node *plist, int x){

}

void insafter(node *nref, int x){
    node *nnode = new node(x);
    nnode->next = nref->next;
    nref->next = nnode;
}

void delafter(node *nref, int *x){
    node *naux = nref->next;
    *x = naux->info;
    nref->next = naux->next;
    delete(naux);
}

void place(node *plist, int x){
    node *p,*q;
    q = NULL;
    for(p = plist; p != NULL && x > p->info; p =p->next){
        q = p;
        if(q == NULL){
            push(plist, x);
        }
        insafter(q,x);
    
    }
}

void insend(node *plist, int x){
    node *q = NULL; 
    node *p = new node(x);
    if(plist == NULL){
        plist = p;
    }
    else{
        for (q = plist; q != NULL; q = q->next)
            q->next = p;   
    }
}

int main(){
    
}