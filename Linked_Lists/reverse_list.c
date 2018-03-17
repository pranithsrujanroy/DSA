#include "implementation.h"

/*
This method traverses through the list and while traversing each node is placed at the start of the list. This way head pointer is changed at each access.
static void reverse(struct Node** head_ref)
{
	if(*head_ref == NULL)
		return;

	struct Node* current = *head_ref;
	struct Node* next;
	while (current->next != NULL)
	{
	next = current->next; 
	current->next = next->next; 
	next->next=(*head_ref);
	*head_ref=next;
	}

}
*/

//The below three methods reverses the list by reversing the next links with the help of three pointers.
void reverseList1(Node** head_ref){
	if((*head_ref)==NULL || (*head_ref)->next==NULL)
		return;
	Node *prev = NULL;
	Node *curr = *head_ref;
	Node *next = NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head_ref = prev;
}

void reverseList2(Node** head_ref){
	if(!*head_ref)
		return;

	Node *first = *head_ref;
	Node *rest  = first->next;

	if(rest==NULL)
		return;

	reverseList2(&rest);
	first->next->next = first;

	first->next = NULL;

	*head_ref = rest;
}

void reverseListUtil(Node *curr, Node *prev, Node** head_ref){

	if(curr->next==NULL){
		curr->next = prev;
		*head_ref = curr;
		return;
	}
	Node* next = curr->next;
	curr->next = prev;

	reverseListUtil(next, curr, head_ref);
}

void reverseList3(Node** head_ref){
	if(!*head_ref)
		return;
	reverseListUtil(*head_ref, NULL, head_ref);
}

int main()
{
	/* code */
	Node* head = NULL;
	makeList(&head);
	printList(head);
	printf("Hi\n");
	reverseList3(&head);
	printList(head);
	return 0;
}
