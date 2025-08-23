#include<stdio.h>
#include<conio.h>
typedef struct
{
	int data;
	struct Node *next;
}Node;
Node* push(Node *start, int ele)
{
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	p->next=start;
	return p;
}
void display(Node *start)
{
	if(start==NULL) printf("Stack is empty\n");
	else
	{
		printf("Stack contains:\n");
		while(start!=NULL)
		{
			printf("%d\n",start->data);
			start=start->next;
		}
	}
}
void peek(Node *start)
{
	if(start==NULL)
	printf("Stack is empty\n");
	else printf("Top of stack contains : %d\n",start->data);
}
Node* pop(Node *start)
{
	Node *p;
	if(start==NULL)
	{
		printf("Stack underflow\n");
		return NULL;
	}
	p=start;
	start=p->next;
	printf("%d deleted\n",p->data);
	free(p);
	return start;
}
void main()
{
	int choice,ele,ch,loc,el1;
	Node *start=NULL,*start1;
	clrscr();
	do
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to push:");
			scanf("%d",&ele);
			start=push(start,ele);
			break;
			case 2:start=pop(start);
			break;
			case 3:display(start);
			break;
			case 4:peek(start);
			break;
			case 5:
			break;
			default:printf("invalid choice");

		}
	}while(choice!=5);
	getch();
}