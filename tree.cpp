#include<iostream>

using namespace std;

typedef struct stack{
    int data;
    stack *n;

    public:
      void push(int n){
        data = n;
    }
}s;

typedef struct node{
    int data;
    node *r;
    node *l;

    node(int d){
        data = d;
        r = NULL;
        l = NULL;
    }
};

void Rinsert(node *&p, int n){
    //This part create the first new node, it couold be created by an array, but we will do that later
    if(p == NULL){       
        node *nnode = new node(n);
        p =  nnode;
    }
    else
    {
        int root_d =  p->data;
        if(n < root_d)
            Rinsert(p->l, n);
        else
        {
            Rinsert(p->r, n);
        }
    }
}

void insert(node *p, int key){
    node *r = NULL, *p;
    if(p == NULL){
        p = new node(key);
        p = p; 
    }
    while (p!=NULL)
    {
        r = p;
        if (key == p->data)
            return;
        else if(key < p->data)
            p = p->l;
        else
            p = p->r;
    }
    p =  new node(key);
    if(key < r->data)r->l = p;
    else r->r = p;
}

/////////////////////PREORDER ITERATIVE PRINT FUNCTION////////////////////

//next its a iterative way to display or print it is necessary to 
//add stack basic functions (push, pop, top, and empty)

/* 
void preor_showtree(node *p){
    stack *s;
    node *aux = p;
    do
    {
         if(aux != NULL){
        cout<<aux->data<<" ";
        s.push(aux);
        aux = aux->l;
    }else if(!s.empty()){
        aux = s.top)();
        s.pop();
        aux = aux->r;
    }
    }while(!s.empty() || aux != NULL);
}

*/

/////////////////////INORDER ITERATIVE PRINT FUNCTION////////////////////
//next its a iterative way to display or print it is necessary to 
//add stack basic functions (push, pop, top, and empty)
/* 
void inor_showtree(node *p){
    stack *s;
    node *aux =  p;
    do
    {
        if (!s.empty() && aux == NULL)
        {
            cout<<(s.top()-> data << " ";
        }

        if (aux != NULL)
        {
            s.push(aux);
            aux = aux-l;
        }
        else if (!s.empty())
        {
            aux = s.top();
            s.pop();
            aux = aux->r;
        }
    } while (!s.empty() || aux != NULL);    
}
*/

void RpreOrder(node *p){
    if(p != NULL){
        cout<<p->data;
        RpreOrder(p->l);
        RpreOrder(p->r);
    }
}

void RinOrder(node *p){
    if(p != NULL){
        RinOrder(p->l);
        cout<<p->data;
        RinOrder(p->r);
    }
}

void RposOrder(node **root, node *p){
    if(p != NULL){
        RposOrder(root, p->l);
        RposOrder(root, p->r);
        cout<<p->data;
    }
}

node *search(node *p, int key){
    while (p != NULL)
    {
        if(key == p->data){
            return p;
        }
        else if (key < p->data){
            p = p->l;
        }
        else
        {
            p = p->r;
        }
    }
}

node* Rsearch(node *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    else if(key < p->data)
        Rsearch(p->l, key);
    else
        Rsearch(p->r, key);
}

int Height(struct node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x = Height(p->l);
    y = Height(p->r);
    return x>y ? x+1 : y+1;
}
node*InPre(node *p)
{
while(p && p->r != NULL)
    p = p->r;
    return p;
}

node* InSucc(node *p)
{
    while(p && p->l!=NULL)
    p = p->l;
    return p;
}

node* Del(node *root,int key)
{
    node *p = p;
    node *q;
    if(p==NULL)
    return NULL;
    if(p->l==NULL && p->r==NULL)
    {
        if(p==root)
        root = NULL;
        delete(p);
        return NULL;
    }
    if(key < p->data)
        p->l=Del(p->l,key);
    else if(key > p->data)
        p->r=Del(p->r,key);
    else
    {
        if(Height(p->l) > Height(p->r))
        {
            q = InPre(p->l);
            p->data = q->data;
            p->l = Del(p->l,q->data);
        }
        else
        {
            q=InSucc(p->r);
            p->data = q->data;
            p->r = Del(p->r,q->data);
        }
    }
    return p;
}

int numleafs(node *root)
{
    int count;
    if(root != NULL){
        if(root->l && root->r)count++;
        else{
            numleafs(root->l);
            numleafs(root->r);
        }
    }
}

int main(){


}