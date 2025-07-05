#include<conio.h>
#include<stdio.h>
#define MAX 100

void push(int val, int ar[MAX], int *tos)
{
	if(*tos==MAX-1) printf("Stack Overflow");
	else
	{
		(*tos)++;
		ar[*tos] = val;
	}
}
int pop(int ar[MAX], int *tos)
{
	int ele;
	if(*tos==-1) return -1;
	ele = ar[*tos];
	(*tos)--;
	return ele;
}
void isEmpty(int tos)
{
	if(tos==-1) printf("Stack is EMPTY");
	else printf("Stack is NOT EMPTY");
}
void isFull(int tos)
{
	if(tos==MAX-1) printf("Stack is FULL");
	else printf("STack is NOT FULL");
}
int peek(int ar[MAX], int tos)
{

	if(tos==-1) printf("Stack is EMPTY\n");
	return ar[tos];
}
void display(int ar[MAX], int tos)
{
	int i;
	for(i=tos; i>=0; i--)
	{
		printf("%d\n",ar[i]);
	}
}
void main()
{
	int choice, dat, arr_no;
	int ar1[MAX],ar2[MAX],tos1=-1,tos2=-1;
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
			printf("Enter array no. : ");
			scanf("%d",&arr_no);
			if(arr_no==1) push(dat,ar1,&tos1);
			else if(arr_no==2) push(dat,ar2,&tos2);
			break;
			case 2: printf("Enter array no. : ");
			scanf("%d",&arr_no);
			if(arr_no==1) dat=pop(ar1, &tos1);
			else if(arr_no==2) dat=pop(ar2, &tos2);
			printf("Popped value: %d",dat);
			break;
			case 3:printf("Enter array no. : ");
			scanf("%d",&arr_no);
			if(arr_no==1) display(ar1, tos1);
			else if(arr_no==2) display(ar2, tos2);
			break;
			case 4:printf("Enter array no. : ");
			scanf("%d",&arr_no);
			if(arr_no==1) isEmpty(tos1);
			else if(arr_no==2) isEmpty(tos2);
			break;
			case 5:printf("Enter array no. : ");
			scanf("%d",&arr_no);
			if(arr_no==1) isFull(tos1);
			else if(arr_no==2) isFull(tos2);
			break;
			case 6: printf("Enter array no. : ");
			scanf("%d",&arr_no);
			if(arr_no==1) dat=peek(ar1, tos1);
			else if(arr_no==2) dat=peek(ar2, tos2);
			printf("Peeked value: %d",dat);
			break;
			case 7: break;
			default: printf("Invalid choice");
		}
	}while(choice!=7);
	getch();
}

