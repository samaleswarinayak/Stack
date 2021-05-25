/*Stack Operations using Array*/
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

int stack[30],size,top=-1;
main()
{
	int option;
	printf("Enter the size of stack");
	scanf("%d",&size);
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Enter your choice");
		scanf("%d",&option);
		switch(option)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:
				printf("\nWrong Choice\n");
		}
	}
}

void push()
{
	int item;
	if(top == size-1)
	{
		printf("\nStack Overflow");
	}
	else
	{
		printf("\nEnter value to push");
		scanf("%d",&item);
		top++;
		stack[top] = item;
	}
}
void pop()
{
	if(top == -1)
	{
		printf("\nStack Uderflow");
	}
	else
	{
		printf("\nPopped item = %d",stack[top]);
		top--;
	}
}
void display()
{
	int index;
	if(top == -1)
	{
		printf("\nStack Uderflow");
	}
	else
	{
		printf("\nValues of stack are\n");
		index=top;
		while(index>=0)
		{
			printf("%d\n",stack[index]);
			index--;
		}
	}
}
