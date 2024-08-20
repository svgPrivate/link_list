#include<stdio.h>
#include<stdlib.h>

struct nodetype {
int data;
struct nodetype * next;
};
typedef struct nodetype node;
node * head= NULL;
/* Always create a node at the beginning in the main(), otherwise this algorithm
will not capable to update null head in the case of first insertion. Whenever insert
an element , consider the boundary case for head is NULL*/
/* Alternatively we can pass ** ptr address of the head, in that case it will run*/
/* Create node function will increase the counter , which will keep track the
number of elements in the list. Declare the list size globally */
int count=0;
node * create_node()
{
	int x;
	node * ptr;
	ptr=(node *) malloc(sizeof(node));
	printf("Enter a value\n");
	scanf("%d",&x);
	ptr->data=x;// initialize
	ptr->next=NULL;
	count ++;
return ptr;
};
node *create_List(int nc, node * hpt)
{
	int i;
	node * ptr;
	ptr=hpt=create_node();
		for(i=0;i<nc-1;i++)
			{
				ptr->next= create_node();
				ptr=ptr->next;
				
			}
/* nc is actually n-1*/
return hpt;
}
void del_from( node * hpt, int index)
{
	node* ptr,*prev;
	int i;
	ptr=hpt;
		for(i=1;i<index;i++)
		{
			prev=ptr;
			ptr=ptr->next;
		}
prev->next= ptr->next;
count--;
printf("Item Deleted......\n");
free(ptr);
}
void del_end(node* hpt)
{
	node * ptr, *prev;
	ptr= hpt;
	while(ptr->next!=NULL)
		{
			prev= ptr;
			ptr=ptr->next;
		}
prev->next=NULL;
count--;
printf("Item Deleted......\n");
free(ptr);
}

node *del_head(node * hpt)
{
	node* ptr;
	ptr=hpt;
	hpt=ptr->next;
	count--;
	free(ptr);
	printf("Item Deleted......\n");
	return hpt;
}
void display(node * hpt)
{
	node * ptr=hpt;
		while(ptr!=NULL)
			{
				printf("%d\t",ptr->data);
				ptr=ptr->next;
			}
}	

int main()
{
	node * head=NULL;
	int x,n,pos;
/*Initialize first element , otherwise we have to pass ** pointer*/
int opt=-4;// any negetive value
		while(opt!=3)
				{
						printf("Enter your option\n");
						printf("deletion from head :[4]\n");
						printf("Deletion from POS [7]\n, deletion from end [8]\n");
						printf("\nExit from program[9]");
						scanf("%d",&opt);
						switch(opt)
						{
							
                                                        case 1: if(count==0)
									printf("List is Empty\n");
									else if ( count==1)
											{
													free(head);
													count--;
													head=NULL;
													printf("Item Deleted");
											}
										else
									head= del_head(head);
													break;
							

							case 2:
								printf("Enter the position");
								scanf("%d",&pos);
								if(pos>count || pos<=0)
								printf(" position must be greater than list size or less than equal to zero:\n");
								else if( pos==1)
								head=del_head(head);
								else if(pos==count)
								del_end(head);
								else
								 del_from(head, pos);
								 break;	
							case 3:
								if(count ==0)
							printf("List is empty:\n");
							else if( count==1)
								{
										free(head);
										head=NULL;
										count--;
										printf("Item deleted\n");
								}
								else
							del_end(head);
							break;
                                                 case 4: exit(1);break;
							
						default : printf(" Wrong choice\n");
									 break;					
													
					}
					
	}
	
	
return 0;	
}
