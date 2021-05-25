/*Conversion from infix to postfix expression*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1,size;

void push(char item)
{
	if(top >= size-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
char pop()
{
	char item ;
	if(top <0)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
/*Process to convert infix to postfix*/
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               
	strcat(infix_exp,")");                  

	i=0;
	j=0;
	item=infix_exp[i];         

	while(item != '\0')        
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              
			j++;
		}
		else if(is_operator(item) == 1)        
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);

			push(item);                 
		}
		else if(item == ')')         
		{
			x = pop();                   
			while(x != '(')               
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");       
			exit(1);
		}
		i++;
		item = infix_exp[i]; 
	}//End of while
	postfix_exp[j] = '\0';
}
main()
{
	char infix[100], postfix[100];         
	printf("\nEnter size of stack");
	scanf("%d",&size);
	printf("Assume the infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	scanf(" %s",infix);
	InfixToPostfix(infix,postfix);                  
	printf("Postfix Expression: ");
	printf("%s",postfix);                    
}

