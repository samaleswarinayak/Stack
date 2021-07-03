#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();
struct node
{
	int info;
	struct node *next;
};
struct node *top = NULL;

main()
{
	int choice;
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
					break;
			case 2:pop();
					break;
			case 3:display();
					break;
			case 4:exit(0);
			default:printf("\nWrong Choice\n");
		}
	}
}
void push()
{
	struct node *temp;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nStack Overflow\n");
	}
	else
	{
		printf("\nEnter the value to push\n");
		scanf("%d",&item);
		temp->info = item;
		temp->next = NULL;
		if(top == NULL)
		{
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
	}	
}
void pop()
{
	struct node *temp;
	if(top == NULL)	
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		temp = top;
		printf("\nPopped Value = %d\n",temp->info);
		top = top->next;
		free(temp);
	}
}
void display()
{
	struct node *temp;
	if(top == NULL)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		temp = top;
		printf("\nValues of Stack are\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}
		printf("\n");
	}
}
