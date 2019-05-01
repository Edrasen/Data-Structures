#include<stdio.h>

#define TRUE  1
#define FALSE  0

typedef unsigned char boolean;

typedef struct
{
	char e;
}element;

typedef struct
{
	element e;
	node *next;

}node;

typedef struct
{
	node *up;
	node *down;
	int num_elem;
}queue;

void Initialize(queue *q){
	q->up = NULL;
	q->down = NULL;
	q->num_elem = 0;
}

void nqueue(queue *q, element e){
	/*new element pointer, all this block could be replaced by "new" C++ function, 
	which it is used like constructor*/
	node *aux;
	aux = malloc(sizeof(node));
	//there is not memory available
	if(aux == NULL)
		exit(1);
	//introducing the element into the memory address refered.
	aux->e = e;
	aux->next = NULL;
	
	/********HERE BEGGIN THE QUEUE PROCESS*******/

	//if queue is empty is easy to know both of pointers will make reference the same element
	if(q->num_elem == 0)
	{
		q->up = aux;
		q->down = aux;
	}
	//if queue is not empty, it is necesary make a reference to the new element 
	else
	{
		q->up->next = aux;
		q->up = aux;
	}
	//finally increase counter by each element added
	q->num_elem++;

	return;
}	


element Dequeue(queue *q){
	element e;
	node *aux;
	if(q->num_elem == 0){
		exit(1);
	}	
	
	else{
		aux = q->down;
		e = q->down->e;
		aux = q->down->next;
		free(q->down);
		q->num_elem--;
		q->down = aux;

		if(q->num_elem == 0)
		{
			Initialize(q);
		}
	}
	return e;
}

boolean Empty(queue *q){
	return (q->num_elem==0) ? TRUE : FALSE;	
}

element Down(queue *q){
	return q->down->e;
}

element Up(queue *q){
	return q->up->e; 
}

int size(queue *q){
	return q->num_elem;
}

element Elemento(queue *q, int i){
	node *aux;
	element r;
	int j;

	if(i>0&&i<=Size(q)){
		aux = q->up;
		for(j=1; j<i j++)
		{
			aux = aux->next;
			r = aux->e;
		}
	}

	else{
		exit(1);	
	}
	return r;
}

void Destroy(queue *q){
	node *aux;

	while(q->down != NULL){
		aux = q->down;	
		q->down = q->down->next;
		
		free(aux); 
	}

	q->num_elem = 0;
	q->up = NULL;
}