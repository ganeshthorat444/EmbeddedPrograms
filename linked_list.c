#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

/* Doubly Linked list 
 * Create Linked List 
 * Add Node at Start/End
 * Delete Node at End 
 * Sort Linked List 
 */

/* create the node structure for singly linked list */

typedef struct node 
{
	int value;
	struct node *next;
}node_t;

struct node *head = NULL;
struct node *Create_Newnode(void);

void Add_NodeAtEnd(int val);
void Delete_NodeAtEnd(void);
void print_list(struct node* head_ptr);
void Add_node(int val);


enum Choice
{
	ADD=1,
	DELETE,
	ADD_AT_LAST,
	DELETE_AT_LAST,
	PRINT
};

int main(int argc, char* argv[])
{
	int choice=1, value_entered;
	printf("linked list program !");
	while(choice != 0)
	{	
		system("clear");
		printf("Press \r\n\t0.Exit\r\n\t1.ADD\r\n\t2.DELETE\r\n\t3.ADD_AT_LAST\r\n\t4.DELETE_AT_LAST\r\n\t5.PRINT\r\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case ADD:
				printf("Enter the value to be add !\r\n");
				scanf("%d", &value_entered);
				Add_node(value_entered);
				break;
			case DELETE:
				printf("Deleting the value \r\n");
				Delete_NodeAtEnd();
				break;
			case ADD_AT_LAST:
				printf("Enter the value to be add_at_last !\r\n");
				scanf("%d", &value_entered);
				Add_NodeAtEnd(value_entered);
				break;
			case DELETE_AT_LAST:
				printf(" delete_at_last !\r\n");
				Delete_NodeAtEnd();
				break;
			case PRINT:
				printf("***********The Linked List Available is as below *********\r\n");
				print_list(head);
				break;
		}
	}
	return 0;
}

void Add_node(int val)
{
	struct node* newnode = Create_Newnode();
	if(newnode == NULL)
	{
		printf("[%s] Error While Malloc!\n", __func__);
		return;
	}
	newnode->next = head;
	newnode->value = val;
	head = newnode;
	printf("val = %d\r\n", newnode->value);
}

struct node* Create_Newnode(void)
{
	struct node *newnode = (struct node*) malloc(sizeof(node_t));
	memset(newnode, 0x0, sizeof(node_t));
	return newnode;
}

void Add_NodeAtEnd(int val)
{
	struct node* trav = head;
	struct node* newnode = Create_Newnode();
	while(trav->next != NULL)
	{
		trav = trav->next;	
	}
	trav->next  = newnode;	
	trav->next->value = val;	
	return ;
}

void Delete_NodeAtEnd(void)
{
	struct node* trav = head;
	while(trav->next->next != NULL)
	{
		trav = trav->next;	
	}
		free(trav->next);
		trav->next = NULL;
	return ;
}

void print_list(struct node* head_ptr)
{
	struct node* trav = head_ptr;
	while(trav!= NULL)
	{
		printf("[%d]-", trav->value);
		trav = trav->next;	
	}
	printf("\r\n");
	return ;	
}
