#include <iostream>
#include <stdlib.h>
#include <string>
typedef char ch;
typedef struct Cell
	{
		char data;
		struct Cell* prev;
	} Stack;

Cell *push(Cell ** PrevTop,ch value)
{
	Cell * NewCell = (Cell*)malloc(sizeof (Cell));
	NewCell->data = value;
	NewCell->prev = *PrevTop;
	*PrevTop = NewCell;
	return NewCell;
}
ch pop(Cell ** PrevTop)
{
	Cell * OldCell = *PrevTop;
	char data = OldCell->data;
	*PrevTop = (*PrevTop)->prev;
	free(OldCell);
	return data;
}

int main() 
{
	Cell * top = NULL;
	ch buffer = 0;
	bool check = true;
	std::string str;
	std::cin>>str;
	int size = str.size();
	for(int i=0;i<size;i++)
	{
		if(str[i]==40||str[i]==91)
		{
			
			push(&top,str[i]);
			buffer = str[i] ;
		}
		else if(str[i]==41)
		{
			if(buffer==40)
			{
				pop(&top);
			}else check = false;
		}
		else if(str[i]==93)
		{
			if(buffer==91)
			{
				pop(&top);
			}else check = false;
		}
	}
if (check==false || top!=NULL)
{
	std::cout<<"This string false";
} else if(top==NULL)std::cout<<"This string true";
	return 0;
}
