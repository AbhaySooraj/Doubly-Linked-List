/* Program to implement doubly linked list*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	
	int option,entry;
	struct node *head=NULL, *pos =NULL, *tail=NULL, *temp=NULL;
	
	while(1)
	{
		
		printf("\n Menu \n 1:Insertion (End) \n 2:Insertion (Beginning) \n 3:Display(Forward) \n 4:Display(Reverse) \n 5:Deletion (Front) \n 6:Deletion (End) \n 7:Deletion (Between) \n 8:Exit \n\n Enter Choice :");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				printf(" Enter Data :");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node *) malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node *) malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				}
				break;
			}
			
			case 2:
			{
				printf(" Enter Data :");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node *) malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					temp=(struct node *) malloc(sizeof(struct node));
					head->prev=temp;
					temp->data=entry;
					temp->next=head;
					temp->prev=NULL;
					head=temp;
				}
				break;
			}				
					
			case 3:
			{
				pos=head;
				printf("\n Elements are :");
				while(pos!=NULL)
				{
					printf("%d\t",pos->data);
					pos=pos->next;
				}
				break;
			}
			
			case 4:
			{
				pos=tail;
				printf("\n Elements are :");
				while(pos!=NULL)
				{	
					printf("%d\t",pos->data);
					pos=pos->prev;
				}
				break;
			}
			
			case 5:
			{
				struct node *del;
				del=head;
				head=del->next;
				head->prev=NULL;
				free(del);
				break;
				
			}
			
			case 6:
			{
				struct node *del;
				del=tail;
				tail=del->prev;
				tail->next=NULL;
				free(del);
				break;
			}		
				
			case 7:
			{
				int x,i;
				struct node *temp=head;
				printf("Enter postion to be deleted :");
				scanf("%d",&x);
				if(x==0)
				{
					head=head->next;
					temp->next=NULL;
					free(temp);
				}
				else
				{
					for(i=0;i<x-1;i++)
					{
						temp=temp->next;
						
					}
					struct node *del=temp->next;
					temp->next=temp->next->next;
					del->next=NULL;
					free(del);
				}
				break;		
			}
			
			case 8:
			{
				printf("Exiting");
				exit(0);
			}
			
			default :
			{
				printf("Wrong Option !!!");
			}
		}
	}
}
			
				
				
			
			
				
				
				
				
				
				
				
				
		
		
		
		
		
		
