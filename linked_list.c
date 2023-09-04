//1. Write a template to represent a node in a single linked list that have the fields:  information of a node and next pointer. Write a menu driven program to perform the different operations.

#include<stdio.h>
#include<stdlib.h>

typedef struct slnknode
{
	int info;
	struct slnknode * next;
}node;

node * create_node(node *head, int item)
{
	node * nw;
	nw= (node*) malloc( sizeof (node));
	if(nw==NULL)
	{
		printf("Node is already created!\n");
		return 0;
	}
	nw-> info= item;
	nw-> next= NULL;
	if(head == NULL)
	{
		head= nw;
		return head;
	}
}

node* insert_beg(node* head, int item)
{
	node* nw;
	nw= (node *) malloc(sizeof(node));
	if(nw==NULL)
	{
		printf("Unable to create node.\n");
		return 0;
	}
	nw-> info= item;
	nw-> next= NULL;
	if(head== NULL)
		head= nw;
	else
	{
		nw-> next= head;
		head= nw;
	}
	return head;
}

node* insert_end(node* head, int item)
{
	node* nw;
	node* ptr;
	nw= (node*) malloc(sizeof (node));
	if(nw== NULL)
	{
		printf("Unable to create node\n");
		return 0;
	}
	nw-> info= item;
	nw-> next= NULL;
	if(head== NULL)
		head= nw;
	else
	{
		for(ptr= head; ptr->next!= NULL; ptr= ptr->next);
			ptr-> next=nw;
	}
	return head;
}

void traverse(node* head)
{
	node * ptr;
	for(ptr=head; ptr!= NULL; ptr=ptr->next)
	{
		printf("%u\t %d\t %u\n", ptr, ptr->info, ptr->next);
	}
	printf("\n");
}

int search(node* head,int item)
{
	node* ptr;
	int pos;
	for(ptr= head, pos=1; ptr!=NULL; ptr=ptr-> next, pos++)
	{
		if(ptr->info==item)
			return pos;
	}
	return 0;
}

int count_node(node* head)
{
	int count=0;
	node* ptr;
	for(ptr=head; ptr!=NULL; ptr=ptr->next)
	{
		count++;
	}
	return count;
}

node* insert_pos(node* head,int pos, int item)
{
	node* nw;
	node* ptr;
	int i;
	nw= (node *) malloc (sizeof (node));
	if(nw== NULL)
	{
		printf("Unable to create node\n");
		return 0;
	}
	nw->info= item;
	nw->next= NULL;
	if(pos==1)
	{
		nw->next=head;
		head=nw;
	}
	else
	{
		for(ptr= head, i=1; i<pos-1 && ptr!= NULL; ptr=ptr->next, i++); //An important line that depicts the travesal fo ptr along all the node
		if(ptr== NULL)
		{
			printf("Less number of element\n");
			return 0;
		}
		else
		{
			nw->next= ptr->next;
			ptr->next= nw;
		}
	}
	return head;
}

node* insert(node* head, int item)
{
	node *nw, *ptr, *prev;
	nw= (node *) malloc(sizeof (node));
	nw->info= item;
	nw->next= NULL;
	if(nw== NULL)
	{
		printf("Unable to create node\n");
		return 0;
	}
	if(head== NULL)
		head= nw;
	else
	{
		for(ptr= head; ptr!= NULL && nw->info > ptr->info; prev= ptr, ptr= ptr->next);
		if(ptr== NULL)
		{
			prev->next= nw;
		}
		else if(ptr== head)
		{
			nw-> next= head;
			head= nw;
		}
		else
		{
			prev->next= nw;
			nw-> next= ptr;
		}
	}
	return head;
}

node* delete(node* head, int item)
{
	node *ptr, *prev;
	for(ptr= head; ptr!= NULL && ptr->info!=item; prev= ptr, ptr=ptr->next);
	if(ptr== NULL)
	{
		printf("Node not found\n");
		return 0;
	}
	else if(ptr== head)
	{
		head= ptr->next;
	}
	else
	{
		prev->next = ptr->next;
	}
	free(ptr);
	return head;
}

node* reverse(node *head)
{
	node *p, *q, *r;
	p= head;
	q= p->next;
	r= q->next;
	p->next= NULL;
	while(q!= NULL)
	{
		q->next= p;
		p=q;
		q=r;
		if(r!= NULL)
			r= r->next;
	}
	head=p;
	return head;
}

void main()
{
	node* head= NULL;
	int item, ch, pos,c, info;
	do
	{
		printf("LINK LIST OPERATIONS:\n");
		printf("0. To create the node\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Traverse\n");
		printf("4. Search\n");
		printf("5. Count\n");
		printf("6. Delete\n");
		printf("7. Insert at a specified position\n");
		printf("8. Insert in a sorted Linked list\n");
		printf("9. Reverse a Linked list\n");
		printf("10. EXIT!\n");
		printf("Enter your Choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 0 :printf("Enter an item to store in a node: ");
				scanf("%d",&item);
				create_node(head, item);
				break;

			case 1 :printf("Enter the item to insert at the beginning: ");
				scanf("%d", &item);
				head= insert_beg(head, item);
				break;

			case 2 :printf("Enter the item to insert at the end: ");
				scanf("%d", &item);
				head= insert_end(head,item);
				break;

			case 3 :traverse(head);
				break;

			case 4 :printf("Enter an item to search: ");
				scanf("%d", &item);
				pos= search(head,item);
				if(pos>0)
					printf("Found at %dth position.\n", pos);
				else
					printf("Item NOT found!\n");
				break;

			case 5 : c=count_node(head);
				 if(c>0)
					 printf("Number of nodes= %d. \n", c);
				 else
					 printf("Not found!\n");
				 break;

			case 6 : printf("Enter item to delete: ");
				 scanf("%d", &item);
				 head= delete(head, item);
				 break;

			case 7 :printf("Enter position to insert: ");
				scanf("%d", &pos);
				printf("Enter the item to insert: ");
				scanf("%d", &item);
				head= insert_pos(head, pos, item);
				break;

			case 8 : printf("Sorting of a linked list\n");
				 printf("Enter the item to be inserted in a sorted Linked lsit: ");
				 scanf("%d", &item);
				 head= insert(head, item);
				 break;

			case 9 : printf("The linked list is reversed!\n");
				 head= reverse(head);
				 break;

			case 10 : printf("EXIT!\n");
				 break;
		}
	}while(ch!=10);
}
