#include"implementation.h"
#include<iostream>
//This requires two loops.
void swapNodes(Node** head_ref){

	if(*head_ref == NULL)
		return;

	int key1,key2;
	printf("Enter the keys to be swapped\n");
	scanf("%d%d",&key1,&key2);
 
	if(key1==key2)
		return;

	Node *prev1, *curr1;
	Node *prev2, *curr2;
	Node *temp;

	curr1 = *head_ref;
	while(curr1!=NULL && curr1->data!=key1){
		prev1 = curr1;
		curr1 = curr1->next;
	}
	if(curr1==NULL)
		return;

	curr2 = *head_ref;
	while(curr2!=NULL && curr2->data!=key2){
		prev2 = curr2;
		curr2 = curr2->next;
	}
	if(curr2==NULL)
		return;

	//If the program reaches this point it ensures that we have two distinct nodes in the list to be swapped.

	if(prev1!=NULL)
		prev1->next = curr2;
	else
		*head_ref = curr2;
	if(prev2!=NULL)
		prev2->next = curr1;
	else
		*head_ref = curr1;

	temp = curr1->next;
	curr1->next = curr2->next;
	curr2->next = temp;
}

void swap(Node* &a, Node* &b){
	Node* temp = a;
	a = b;
	b = temp;
}

//This implementation is done using double pointers
void swapNodes2(Node **head_ref){
	if(*head_ref == NULL)
		return;
	int key1, key2;
	printf("Enter the keys to be swapped in the list\n");
	scanf("%d%d",&key1,&key2);

	if(key1==key2)
		return;

	Node **a, **b;
	while(*head_ref){
		if((*head_ref)->data==key1)
			a = head_ref;
		if((*head_ref)->data==key2)
			b = head_ref;

		head_ref = &((*head_ref)->next);
	}

	if(a&&b){
		//swapping the current pointers
		swap(*a,*b);
		//swapping the next pointers
		swap((*a)->next,(*b)->next);
	}
}

int main(){
	Node* head = NULL;
	makeList(&head);
	printList(head);
	swapNodes2(&head);
	printList(head);
}