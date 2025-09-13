#include<stdio.h>
#include<conio.h>
typedef struct
{
	int data;
	struct Node *next,*prev;
}Node;
Node* insertBeg(Node*,int);
Node* insertEnd(Node*,int);
Node* insertLoc(Node*,int,int);
Node* insertAfter(Node*,int,int);
Node* insertBefore(Node*,int,int);
Node* deleteBeg(Node*);
Node* deleteEnd(Node*);
Node* deleteLoc(Node*,int);
Node* deleteAfter(Node*,int);
Node* deleteBefore(Node*,int);
void display(Node*);
int peek(Node*);
void main()
{
	Node *start=NULL;
	int choice,ele,i,ch;
	clrscr();
	do
	{
		printf("1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element to insert:");
			scanf("%d",&ele);
			printf("1.Beginning\n2.End\n3.At a location\n4.After an element\n5.Before an element\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:start=insertBeg(start,ele);
				break;
				case 2:start=insertEnd(start,ele);
				break;
				case 3:printf("Enter the location:");
				scanf("%d",&i);
				start=insertLoc(start,ele,i);
				break;
				case 4:printf("Enter element after which it is to be inserted:");
				scanf("%d",&i);
				start=insertAfter(start,ele,i);
				break;
				case 5:printf("Enter element before which it is to be inserted:");
				scanf("%d",&i);
				start=insertBefore(start,ele,i);
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 2:printf("1.Beginning\n2.End\n3.At a location\n4.After an element\n5.Before an element\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:start=deleteBeg(start);
				break;
				case 2:start=deleteEnd(start);
				break;
				case 3:printf("Enter the location:");
				scanf("%d",&i);
				start=deleteLoc(start,i);
				break;
				case 4:printf("Enter element after which it is to be deleted:");
				scanf("%d",&i);
				start=deleteAfter(start,i);
				break;
				case 5:printf("Enter element before which it is to be deleted:");
				scanf("%d",&i);
				start=deleteBefore(start,i);
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 3:i=peek(start);
			if(i==-1) printf("List is empty\n");
			else printf("%d is contents of node pointed by start\n",i);
			break;
			case 4:display(start);
			break;
			case 5:break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=5);
	getch();
}
Node* deleteBefore(Node *start,int i)
{
	Node *p,*q,*r;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->data==i)
	{
		printf("No node before this\n");
		return start;
	}
	q=start->next;
	if(q->data==i)
	{
		start=deleteBeg(start);
		return start;
	}
	r=start;
	p=q;
	q=q->next;
	while(q->data!=i && q!=start)
	{
		q=q->next;
		p=p->next;
		r=r->next;
	}
	if(q==start)
	{
		printf("Location doesn't exists\n");
		return start;
	}
	r->next=q;
	q->prev=r;
	printf("%d deleted\n",p->data);
	free(p);
	return start;
}
Node* deleteAfter(Node *start,int i)
{
	Node *p,*q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->data==i)
	{
		p=start->next;
		start->next=p->next;
		q=p->next;
		q->prev=start;
		printf("%d delted\n",p->data);
		free(p);
		return start;
	}
	q=start->next;
	while(q->data!=i && q!=start)
	{
		q=q->next;
	}
	p=q;
	q=q->next;
	if(p==start)
	{
		printf("Location doesn't exists\n");
		return start;
	}
	if(q==start)
	{
		printf("No node after this node\n");
		return start;
	}
	p->next=q->next;
	p=q->next;
	p->prev=q->prev;
	printf("%d deleted\n",q->data);
	free(q);
	return start;
}
Node* deleteLoc(Node *start,int loc)
{
	Node *p,*q;
	int i=1;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(loc==1)
	{
		start=deleteBeg(start);
		return start;
	}
	q=start->next;
	p=start;
	while(i<loc-1 && q!=start)
	{
		q=q->next;
		p=p->next;
		i++;
	}
	if(q==start)
	{
		printf("Location doesn't exists\n");
		return start;
	}
	p->next=q->next;
	p=q->next;
	p->prev=q->prev;
	printf("%d deleted\n",q->data);
	free(q);
	return start;
}
Node* insertAfter(Node *start,int ele,int i)
{
	Node *p,*q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	p=(Node*) malloc(sizeof(Node));
	p->data=ele;
	if(start->data==i)
	{
		p->next=start->next;
		start->next=p;
		p->prev=start;
		q=p->next;
		q->prev=p;
		return start;
	}
	q=start->next;
	while(q->data!=i && q!=start)
	{
		q=q->next;
	}
	if(q!=start)
	{
		p->next=q->next;
		q->next=p;
		p->prev=q;
		q=p->next;
		q->prev=p;
		return start;
	}
	printf("Node after which it is to be inserted is not found\n");
	return start;
}
Node* insertBefore(Node *start,int ele,int i)
{
	Node *p,*q,*r;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->data==i)
	{
		start=insertBeg(start,ele);
		return start;
	}
	p=(Node*) malloc(sizeof(Node));
	p->data=ele;
	q=start->next;
	r=start;
	while(q->data!=i && q!=start)
	{
		q=q->next;
		r=r->next;
	}
	if(q!=start)
	{
		p->next=r->next;
		r->next=p;
		p->prev=r;
		q->prev=p;
		return start;
	}
	printf("Node before which it is to be inserted is not found\n");
	return start;
}
Node* insertLoc(Node *start,int ele,int loc)
{
	Node *p,*q;
	int i=1;
	if(loc==1)
	{
		start=insertBeg(start,ele);
		return start;
	}
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	if(loc==2)
	{
		p->next=start->next;
		start->next=p;
		return start;
	}
	q=start->next;
	while(i<loc-2 && q!=start)
	{
		q=q->next;
		i++;
	}
	if(q==start)
	{
		printf("Location doesn't exists\n");
		return start;
	}
	p->next=q->next;
	p->prev=q;
	q->next=p;
	q=p->next;
	q->prev=p;
	return start;
}
Node* insertBeg(Node *start,int ele)
{
	Node *p,*q;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	p->next=start;
	if(start==NULL)
	{
		p->next=p->prev=p;
		return p;
	}
	q=start->prev;
	q->next=p;
	p->prev=q;
	start->prev=p;
	return p;
}
Node* insertEnd(Node *start,int ele)
{
	Node *p,*q;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	p->next=start;
	if(start==NULL)
	{
		p->next=p->prev=p;
		return p;
	}
	q=start->prev;
	q->next=p;
	p->prev=q;
	start->prev=p;
	return start;
}
int peek(Node *start)
{
	if(start==NULL) return -1;
	return(start->data);
}
void display(Node *start)
{
	Node *p=start;
	if(p==NULL) printf("List is empty\n");
	else
	{
		printf("List contains:\n%d\n",p->data);
		p=p->next;
		while(p!=start)
		{
			printf("%d\n",p->data);
			p=p->next;
		}
	}
}
Node* deleteBeg(Node *start)
{
	Node *p,*q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->next==start)
	{
		printf("%d deleted\n",start->data);
		free(start);
		return NULL;
	}
	p=start->next;
	q=start->prev;
	p->prev=q;
	q->next=p;
	printf("%d deleted\n",start->data);
	free(start);
	return p;
}
Node* deleteEnd(Node *start)
{
	Node *p,*q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->next==start)
	{
		printf("%d deleted\n",start->data);
		free(start);
		return NULL;
	}
	p=start->prev;
	q=p->prev;
	q->next=start;
	start->prev=q;
	printf("%d deleted\n",p->data);
	free(p);
	return start;
}