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
}queue;

bool Empty(queue *c){
   if(c->top == NULL && c->bottom){
       return true;
   }
   else{
       return false;
   }
}

void equeue(queue *c, char e){ 
    node *aux = new node(e);
    if (Empty)
    {
        c->top = aux;
        c->bottom = aux;
    }
    else{
        c->top->siguiente = aux;
        c->top = aux;
    }
}


int main(){

}