#include<iostream>

using namespace std;

struct node{
        int data;
        struct node *next;

        node(int d){
        data = d;
        next = NULL;
        }
};

void push(node *&stack, int data){
        node *nnode = new node(data);
        nnode->next = stack;
        stack = nnode;
}

void pop(node *&stack, int &d){
        node *aux = stack;
        d = stack->data;
        stack = aux->next;
        delete(aux);
}

bool isEmpty(node *stack){
        if(stack == NULL)
        cout<<"La pila esta vacia\n";
        return true;
}

int main(){
        int ctrl;
        node *stack = NULL;
        do{
                cout<<"/******Ingrese la opcion que desea realizar*********/"<<endl;
                cout<<"1.-Ingresar elemento a la pila"<<endl;
                cout<<"2.-Retirar elemento de la pila"<<endl;
                cout<<"3.-Verificar si la pila esta vacia"<<endl;
                cout<<"4.-Salir"<<endl;

                cin>>ctrl;

                if(ctrl == 1){
                int num;
                cout<<"Que numero desea agregar a la pila?"<<endl;
                cin>>num;
                push(stack,num);
                }
                else if(ctrl == 2){
                int aux;
                pop(stack, aux);
                cout<<"Se retiro el elemento\t"<< aux <<"\tde la pila"<<endl;
                }
                else if(ctrl == 3)
                isEmpty(stack);
        }while(ctrl!=4);
}

