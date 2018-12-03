#include <iostream>
#include <string.h>
#include <cstring>
int pop(char *mas)
{
	for(int i=0;i<10;i++)
	{
		
	}
}
int main( ) 
{
	char mas[10]={'0','0','0','0','0','0','0','0','0','0'};
	int a=0;
	bool check;
	std::string str;
	std::cout<<"Write your string: ";
	std::cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]==40||str[i]==91)
		{
			mas[a]=str[i];
			a++;
		}
		if(str[i]==41)
		{
			if(mas[a-1]==40)
			{
				mas[a-1]= '0';
				a--;
			}
		}
		if(str[i]==93)
		{
			if(mas[a-1]==91)
			{
				mas[a-1]= '0';
				a--;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		if(mas[i]=='0')
		{
			check=true;
		}
		else 
		{
			check=false;
			i=11;
		}
	}
	for(int i=0;i<10;i++)
	{
		std::cout<<mas[i];
	}
	if(check==true)
	{
		std::cout<<"\n"<<"This sting true"; 
	} else std::cout<<"\n"<<"This string false";
	return 0;
}
