#include "Stack.h"
#include <stdlib.h>

Node* push(Node** pTop, info_t value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->info = value;
	newNode->prev = *pTop;
	*pTop = newNode;
	return newNode;
}


info_t pop(Node** pTop)
{
	Node* oldTop = *pTop;
	info_t info = oldTop->info;

	*pTop = (*pTop)->prev;
	free(oldTop);
	return info;
}

info_t getTopValue(Node* top)
{
	return top->info;
}

bool isEmpty(Node* top)
{
	return top == NULL;
}
void WriteStack(Node *top)
{
		Node *buffer = top;
		Node *Check = top;
		info_t info;
		while(!isEmpty(Check))
		{
		std::cout<<Check->info<<"\n";
		Check = Check->prev;	
		}
		*top = *buffer;
}