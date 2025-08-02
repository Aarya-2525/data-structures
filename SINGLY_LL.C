#include<stdio.h>
#include<conio.h>
typedef struct
{
	int data;
	struct Node *next;
}Node;
Node* insertB(Node *start, int ele)
{
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	p->next=start;
	return p;
}
Node* insertE(Node *start, int ele)
{
	Node *p,*q;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	p->next=NULL;
	if(start==NULL) return p;
	q=start;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	return start;
}
Node* insertAt(Node *start, int ele, int loc)
{
	Node *p,*q;
	int i=1;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	if(loc==1)
	{
		p->next=start;
		return p;
	}
	q=start;
	while(i<loc-1)
	{
		q=q->next;
		if(q==NULL) break;
		i++;
	}
	if(q==NULL)
	{
		printf("Location doesn't exist\n");
		return start;
	}
	p->next=q->next;
	q->next=p;
	return start;
}
Node* insertBefore(Node *start,int ele, int el1)
{
	Node *p,*q,*r;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	q=start;
	if(q->data==el1)
	{
		p->next=start;
		return p;
	}
	r=q;
	q=q->next;
	while(q->data!=el1 && q!=NULL)
	{
		q=q->next;
		r=r->next;
	}
	if(q==NULL)
	{
		printf("Element not found\n");
		return start;
	}
	p->next=r->next;
	r->next=p;
	return start;
}
Node* insertAfter(Node *start,int ele,int el1)
{
	Node *p,*q;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	q=start;
	while(q->data!=el1 && q!=NULL)
	{
		q=q->next;
	}
	if(q==NULL)
	{
		printf("Element not found\n");
		return start;
	}
	p->next=q->next;
	q->next=p;
	return start;
}
/*void display(Node *start)
{
	if(start==NULL) printf("List is empty\n");
	else
	{
		printf("List contains:\n");
		while(start!=NULL)
		{
			printf("%d\n",start->data);
			start=start->next;
		}
	}
}*/
void display(Node *start)
{
	if(start!=NULL)
	{
		printf("%d\n",start->data);
		display(start->next);
	}
}
void displayR(Node *start)
{
	if(start!=NULL)
	{
		displayR(start->next);
		printf("%d\n",start->data);
	}
}
void main()
{
	int choice,ele,ch,loc,el1;
	Node *start=NULL;
	clrscr();
	do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Display reverse\n7.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to insert:");
			scanf("%d",&ele);
			printf("1.Beginning\n2.End\n3.At a location\n4.After an element\n5.Before an element\n6.In sorted list\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:start=insertB(start,ele);
				break;
				case 2:start=insertE(start,ele);
				break;
				case 3:printf("Enter the location to insert at:");
				scanf("%d",&loc);
				start=insertAt(start,ele,loc);
				break;
				case 4:printf("Enter the element after which to be inserted:");
				scanf("%d",&el1);
				start=insertAfter(start,ele,el1);
				break;
				case 5:printf("Enter the element before which to be inserted:");
				scanf("%d",&el1);
				start=insertBefore(start,ele,el1);
				break;

			}
			break;
			case 2:
			break;
			case 3:display(start);
			break;
			case 4:
			break;
			case 5:
			break;
			case 6:displayR(start);
			break;
			case 7:
			break;

		}
	}while(choice!=7);
	getch();
}