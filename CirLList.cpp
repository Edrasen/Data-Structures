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

void Display(node *lp){
    node *p = lp;
    do{
        printf("%d", p->data);
        p = p->next;
    }while(p != lp);
}

void Rdisplay(node *lp){
    static int flag;
    if((lp != lp) || (flag = 0))
    {
        flag = 1;
        printf("%d", lp->data);
        Rdisplay(lp->next);
    }
    flag = 0;
}

int main(){

}