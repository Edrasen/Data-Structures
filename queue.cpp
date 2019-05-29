#include<iostream>

using namespace std;

typedef unsigned char boolean;

typedef struct node{
    node *siguiente;
    char elem;
    node(char c){
        elem = c;
        siguiente = NULL;
    }
}node;

typedef struct queue{
    node *top;
    node *bottom;
    int num_E;
    queue(){
        top =  NULL;
        bottom = NULL;
    }
}queue;

bool Empty(queue *c){
   if(c->top == NULL && c->bottom == NULL){
       return true;
   }
   else{
       return false;
   }
}

void enqueue(queue *&c, char e){ 
    node *aux = new node(e);
    if (Empty(c))
    {
        c->top = aux;
        c->bottom = aux;
    }
    else{
        c->top->siguiente = aux;
        c->top = aux;
    }
}

char Dequeue(queue *&c, char &l){
    if (c->bottom == NULL)
    {
        exit(1);
    }
    else
    {
        node *aux = c->top;
        l = c->bottom->elem;
        aux = c->bottom->siguiente;
        delete(c->bottom);
        c->top = aux;
    }
    return l;
}

int size (queue *c){
    return c->num_E;
}

char element (queue *c, int i){
    node *aux;
    char e;
    int j;
    if (i>0&&i<=size(c))
    {
        aux = c->top;
        for (j = 1; j < i; j++)
        {
            aux = aux->siguiente;
            e = aux->elem;
        }
        
    }
    else
    {
        exit(1);
    }
    return e;
}



int main(){

}