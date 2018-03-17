#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void makeList(Node** head){
	int n;
	printf("Enter the number of elements to be inserted in the list initially: \n");
	scanf("%d",&n);
	if(n==0)
		return;
	int data;
	Node* temp = *head;
	printf("Enter the elements:\n");
	for(int i=0; i<n; i++ ){
		scanf("%d",&data);
		Node* nnode = (Node*)malloc(sizeof(Node));
		nnode->data = data;
		nnode->next = NULL;
		if(temp==NULL){
			*head = nnode;
			temp = nnode;
		}
		else{
			temp->next = nnode;
			temp = temp->next;
		}
	}
	return;
}

void insertNode(Node **head_ref, int data, int position){
	Node* nnode = (Node*)malloc(sizeof(Node));
	nnode->data = data;
	nnode->next = NULL;
	if(position==0){
		nnode->next = *head_ref;
		*head_ref = nnode;
		return;
	}
	int i = 0;
	Node* prev = *head_ref;
	while(i<position-1 && prev->next!=NULL){
		prev=prev->next;
		i++;
	}
	if(prev->next==NULL){
		//appending to the list
		prev->next = nnode;
	}
	else{
		nnode->next = prev->next;
		prev->next  = nnode;
	}
	return;
}

void deleteNodeByData(Node** head_ref,int data){
	Node* temp = *head_ref;
	if(temp->data==data){
		*head_ref = temp->next;	
		return;
	}
	Node *prev;
	temp = *head_ref;
	while(temp->data!=data && temp->next!=NULL){
		prev = temp;
		temp = temp->next;
	}
	if(temp->data!=data && temp->next==NULL){
		printf("The node to be deleted is not present in the list.\n" );
		return;
	}
	prev->next = temp->next;
	temp->next = NULL;
	free(temp);
	return;
}

void deleteNodeByPosition(Node** head_ref, int position){
	Node *prev = *head_ref, *temp;
	if(position==0){
		*head_ref = prev->next;
		return;
	}
	int i = 0;
	while(i<position-1 && prev->next!=NULL){
		prev = prev->next;
		i++;
	}
	if(prev->next==NULL){
		printf("The node to be deleted is not present in the list.\n");
		return;
	}
	else{
		temp=prev->next;
		prev->next = temp->next;
		temp->next = NULL;
		free(temp);
	}
	return;
}

void printList(Node *head){
	Node* ptr = head;
	while(ptr!=NULL){
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int countNodesInList(Node *head){
	int count = 0;
	Node* ptr = head;
	while(ptr!=NULL){
		count++;
		ptr = ptr->next;
	}
	printf("Number of nodes in the list is: %d\n", count);
}