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
node * rev(node * hpt)
{
	node * prev, *current,*next;
	prev=NULL;
	current=hpt;
	next=NULL;
	while(current !=NULL)
	{
		
		next= current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	hpt=prev;
	return hpt;
}
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

void insert_at( node * hpt, int index)
{
	node* ptr,*prev, * new;
	int i;
	ptr=hpt;
	for(i=1;i<index;i++)
		{
			prev=ptr;
			ptr=ptr->next;
		}
	new= create_node();
	new->next=ptr;
	prev->next=new;
	printf("\nValue entered\n");

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
void append(node * hpt)
{
	node * ptr;
	ptr=hpt;
	while( ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
		ptr->next= create_node();
	printf("\nValue entered\n");
}
node * ins_head(node * hpt)
{
	node * ptr, * newnode;
	ptr=hpt;
	newnode= create_node();
	newnode->next= ptr;
	hpt=newnode;
    printf("\nValue entered\n");
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
int opt=-10;// any negetive value
		while(opt!=9)
				{
						printf("Enter your option\n");
						printf("Create list: [1], print List :[2], append :[3], deletion from head :[4]\n");
						printf(" Insert at head: [5], insert at POS [6], Deletion from POS [7], deletion from end [8]\n");
						printf("\nExit from program[9], List Reverse [10]\n");
						scanf("%d",&opt);
						switch(opt)
						{
							case 1: if( count==0 && head==NULL)
											{
												
													// create_list function will create a list with n number of elements
													printf("Enter the initial size of the list\n");
													scanf("%d",&n);
													head=create_List(n, head);
											}
									else 
											printf("List is not empty, wrong choice.......\n");
													break;
							case 2: if( count==0 && head==NULL)
								printf("List is empty:");	
									else
								display(head); break;
							case 3: if( count==0 && head==NULL)
									printf("List is empty :Wrong option");
									else append(head); break;
									
							case 4: if(count==0)
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
							case 5: if( count==0 && head==NULL)
									{
													    printf("Enter the value\n");
													    scanf("%d",&x);
													    head = (node*) malloc(sizeof(node));
													    head->data=x;
														head->next= NULL;
														count++;
									}
									else
									head= ins_head(head); break;
							case 6 : printf("Enter the position\n");
											scanf("%d",&pos);
										if(pos>count || pos<=0)
											printf("position is greater than list size or less than equal to zero:");
										else if( pos==1)
											head= ins_head(head);
											
											else insert_at( head, pos);
											break;

							case 7:
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
							case 8:
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
							case 9: exit(1);break;
							case 10: head=rev(head);break;
						default : printf(" Wrong choice\n");
									 break;					
													
					}
					
	}
	
	
return 0;	
}
