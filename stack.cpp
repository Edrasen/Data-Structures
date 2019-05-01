#include<iostream>
#include<bool>
using namespace std;

struct node{
	int data;
	struct node *next;

	node(int d){
	data: = d;
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
	cout<<"La pila esta vacia";
	return true;
}

int main(){
	int ctrl;
	node *stack = NULL;
	do{	
		cout<<"Ingrese la opcion que desea realizar";
		cout<<"1.-Ingresar elemento a la pila";	
		cout<<"2.-Retirar elemento de la pila";		
		cout<<"3.-Verificar si la pila esta vacia";
		cout<<"4.-Salir";

		cin>>ctrl;

		if(ctrl == 1){
		int num;
		cout<<"Que numero desea agregar a la pila?";
		cin>>num;
		push(stack,num);
		}
		else if(ctrl == 2){
		int aux;
		pop(stack, aux);
		cout<<"Se retiro el elemento"<< aux <<"de la pila";
		}
		else if(ctrl == 3)
		isEMpty(stack); 
	}while(ctrl!=4);
}
