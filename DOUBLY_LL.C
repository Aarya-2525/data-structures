#include<stdio.h>
#include<conio.h>
typedef struct
{
	int data;
	struct Node *next,*prev;
}Node;
Node* insertB(Node *start, int ele)
{
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	if(start==NULL)
	{
		p->prev=p->next=NULL;
		return p;
	}
	p->next=start;
	start->prev=p;
	p->prev=NULL;
	return p;
}
Node* insertE(Node *start, int ele)
{
	Node *p,*q;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	p->next=p->prev=NULL;
	if(start==NULL) return p;
	q=start;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	p->prev=q;
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
		if(start!=NULL)
		start->prev=p;
		p->prev=NULL;
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
	p->prev=q;
	q=p->next;
	if(q!=NULL) q->prev=p;
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
		start->prev=p;
		p->prev=NULL;
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
	p->prev=r;
	r=p->next;
	if(r!=NULL) r->prev=p;
	return start;
}
Node* insertSorted(Node *start,int ele)
{
	Node *p,*q,*r;
	p=(Node*)malloc(sizeof(Node));
	p->data=ele;
	if(start==NULL)
	{
		p->next=p->prev=NULL;
		return p;
	}
	q=start;
	if(q->data>ele)
	{
		p->next=start;
		p->prev=NULL;
		start->prev=p;
		return p;
	}
	r=q;
	q=q->next;
	while(q->data<ele && q!=NULL)
	{
		q=q->next;
		r=r->next;
	}
	p->next=q;
	if(q!=NULL) q->prev=p;
	r->next=p;
	p->prev=r;
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
	p->prev=q;
	q=p->next;
	if(q!=NULL) q->prev=p;
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
Node* deleteB(Node *start)
{
	Node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	p=start;
	start=p->next;
	printf("%d deleted\n",p->data);
	free(p);
	start->prev=NULL;
	return start;
}
Node* deleteEnd(Node *start)
{
	Node *q,*r;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->next==NULL)
	{
		free(start);
		return NULL;
	}
	r=start;
	q=r->next;
	while(q->next!=NULL)
	{
		q=q->next;
		r=r->next;
	}
	free(q);
	r->next=NULL;
	return start;
}
Node* deleteAt(Node *start, int loc)
{
	Node *q,*r;
	int i=1;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(loc==1)
	{
		q=start->next;
		free(start);
		q->prev=NULL;
		return q;
	}
	r=start;
	q=r->next;
	while(i<loc-1 && q!=NULL)
	{
		i++;
		q=q->next;
		r=r->next;
	}
	if(q==NULL)
	{
		printf("Location doesn't exist\n");
		return start;
	}
	r->next=q->next;
	r=r->next;
	r->prev=q->prev;
	free(q);
	return start;
}
Node* deleteBefore(Node *start, int el1)
{
	Node *q,*r,*s;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	s=start;
	if(s->data==el1)
	{
		printf("No node before this\n");
		return start;
	}
	r=s->next;
	if(r->data==el1)
	{
		printf("%d deleted\n",s->data);
		r->prev=NULL;
		free(s);
		return (r);
	}
	q=r->next;
	while(q->data!=el1 && q!=NULL)
	{
		q=q->next;
		r=r->next;
		s=s->next;
	}
	if(q==NULL)
	{
		printf("Data doesn't exist\n");
		return start;
	}
	s->next=q;
	q->prev=s;
	free(r);
	return start;
}
Node* deleteAfter(Node *start, int el1)
{
	Node *q,*r;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	q=start;
	while(q->data!=el1 && q!=NULL)
	{
		q=q->next;
	}
	if(q->next==NULL)
	{
		printf("No node after this\n");
		return start;
	}
	if(q==NULL)
	{
		printf("Data doesn't exist\n");
		return start;
	}
	r=q->next;
	q->next=r->next;
	q=q->next;
	q->prev=r->prev;
	free(r);
	return start;
}
Node* deleteEle(Node *start,int el1)
{
	Node *q,*r;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	r=start;
	if(r->data==el1)
	{
		printf("%d deleted\n",r->data);
		q=r->next;
		free(r);
		q->prev=NULL;
		return (q);
	}
	q=r->next;
	while(q->data!=el1 && q!=NULL)
	{
		q=q->next;
	}
	if(q==NULL)
	{
		printf("Data doesn't exist\n");
		return start;
	}
	r=q->prev;
	r->next=q->next;
	r=r->next;
	r->prev=q->prev;
	free(q);
	return start;
}
int Search(Node *start, int ele)
{
	Node *q=start;
	int i=1;
	while(q->data!=ele && q!=NULL)
	{
		i++;
		q=q->next;
	}
	if(q==NULL)
	return -1;
	return i;
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
				case 6:start=insertSorted(start,ele);
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 2:printf("1.Start\n2.End\n3.At a location\n4.After an element\n5.Before an element\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:start=deleteB(start);
				break;
				case 2:start=deleteEnd(start);
				break;
				case 3:printf("Enter the location to be deleted:");
				scanf("%d",&loc);
				start=deleteAt(start,loc);
				break;
				case 4:printf("Enter the element after which to be deleted:");
				scanf("%d",&el1);
				start=deleteAfter(start,el1);
				break;
				case 5:printf("Enter the element before which to be deleted:");
				scanf("%d",&el1);
				start=deleteBefore(start,el1);
				break;
				case 6:printf("Enter value of node to be deleted:");
				scanf("%d",&ele);
				start=deleteEle(start,ele);
				break;
				default:printf("Invalid choice\n");
			}
			break;
			break;
			case 3:display(start);
			break;
			case 4:printf("Enter element to search:");
			scanf("%d",&ele);
			loc=Search(start,ele);
			if(loc==-1) printf("Element not found\n");
			else printf("Found at %d\n",loc);
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