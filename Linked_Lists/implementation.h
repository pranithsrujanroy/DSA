#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printList(Node* head){
	Node* ptr = head;
	while(ptr!=NULL){
		printf("%d\t", ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

Node* makeList(int a[],int n){
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = a[0];
	Node* ptr = head;
	int i = 1;
	while(i<n){
		Node* nnode = (Node*)malloc(sizeof(Node));
		nnode->data = a[i];
		i++;
		nnode->next = NULL;
		ptr->next = nnode;
		ptr = ptr->next;
	}
	return head;
}
Node* insertNode(Node* head, int data, int position){
	Node* nnode = (Node*)malloc(sizeof(Node));
	nnode->data = data;
	nnode->next = NULL;
	int i = 1;
	Node* ptr = head;
	//It is important to note here the number of times we are looping because we already point to the first node and we wish to point
	//to the previous node of the position. Therefore we require to move the pointer position-2 times.
	while(i<(position-1)&&ptr->next!=NULL){
		ptr=ptr->next;
		i++;
	}
	//Now ptr points to the node previous to the position of the node to be inserted.
	if(ptr->next==NULL){
		ptr->next = nnode;
	}
	else{
		nnode->next = ptr->next;
		ptr->next = nnode;
	}
	ptr=NULL;
	free(ptr);
	return head;
}
Node* deleteNodeByData(Node* head, int data){
	Node* ptr=head;
	Node* temp;
	while(ptr->next!=NULL && (ptr->next)->data!=data)
		ptr=ptr->next;
	if(ptr->next==NULL){
		printf("The data to be deleted is not present in the list.\n");
		return head;
	}
	temp=ptr->next;
	ptr->next = temp->next;
	temp->next=NULL;
	free(temp);
	ptr=NULL;
	free(ptr);
	return head;
}
Node* deleteNodeByPosition(Node* head, int position){
	Node* ptr=head;
	Node* temp;
	int i=1;
	while(i<position-2 && ptr->next!=NULL){
		ptr=ptr->next;
		i++;
	}
	if(ptr->next==NULL){
		printf("The position is not in the list.\n");
		return head;
	}
	temp=ptr->next;
	ptr->next = temp->next;
	temp->next = NULL;
	free(temp);
	return head;
}