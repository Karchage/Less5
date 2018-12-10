#include <iostream>
#include <stdlib.h>
typedef char ch;
typedef struct Cell
{
	ch data;
	struct Cell * prev;
}Cell;

Cell * push(Cell **PrevTop, ch value)
{
	Cell * NewTop = (Cell*)malloc(sizeof(Cell));
	NewTop->data = value;
	NewTop->prev = *PrevTop;
	*PrevTop=NewTop;
	return NewTop;
}
ch pop(Cell **PrevTop)
{
	Cell * OldTop = *PrevTop;
	char data = OldTop->data;
	*PrevTop= (*PrevTop)->prev;
	free(OldTop);
	return data;
}
int main() 
{
	char str;
	Cell* top = NULL;
	FILE * file;
	file = fopen("newfile.txt","r");
	if(file!=NULL)
	{
		std::cout<<"File Open: True\n";
	} else std::cout<<"File Open: False\nPlease check the path to the file or check file name\n";
	
	while(str=fgetc(file))
	{
		if(str==40||str==91||str==123)
		{
			push(&top,str);
		}
		if(str==41)
		{
			if(top->data==40)pop(&top);
		}
		else if(str==93)
		{
			if(top->data==91)pop(&top);
		}
		else if(str==125)
		{
			if(top->data==123)pop(&top);
		}
		if(str==EOF) break;	
	}
	
	if(top==NULL)
	{
		std::cout<<"\nSyntax in this file: True";
	}else std::cout<<"Syntax in this file: False\nPlease check file.";
	return 0;
}
