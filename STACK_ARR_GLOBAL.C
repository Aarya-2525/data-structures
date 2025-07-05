#include<conio.h>
#include<stdio.h>
#define MAX 100
int ar[MAX], tos = -1;
void push(int val)
{
	if(tos==MAX-1) printf("Stack Overflow");
	else
	{
		tos++;
		ar[tos] = val;
	}
}
int pop()
{
	int ele;
	if(tos==-1) return -1;
	ele = ar[tos];
	tos--;
	return ele;
}
void isEmpty()
{
	if(tos==-1) printf("Stack is EMPTY");
	else printf("Stack is NOT EMPTY");
}
void isFull()
{
	if(tos==MAX-1) printf("Stack is FULL");
	else printf("STack is NOT FULL");
}
int peek()
{

	if(tos==-1) printf("Stack is EMPTY\n");
	return ar[tos];
}
void display()
{
	int i;
	for(i=tos; i>=0; i--)
	{
		printf("%d\n",ar[i]);
	}
}
void main()
{
	int choice, dat;
	clrscr();
	do
	{
		printf("\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Check if empty\n");
		printf("5.Check if full\n");
		printf("6.Peek\n");
		printf("7.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter data to be pushed: ");
			scanf("%d",&dat);
			push(dat);
			break;
			case 2: dat=pop();
			printf("Popped value: %d",dat);
			break;
			case 3: display();
			break;
			case 4: isEmpty();
			break;
			case 5: isFull();
			break;
			case 6: dat=peek();
			printf("Peeked value: %d",dat);
			break;
			case 7: break;
			default: printf("Invalid choice");
		}
	}while(choice!=7);
	getch();
}

