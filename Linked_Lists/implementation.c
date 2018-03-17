#include<stdio.h>
#include<stdlib.h>
#include"implementation.h"
int main(){
	int n;
	Node* head=NULL;
	makeList(&head);
	printList(head);
	insertNode(&head,6,5);
	printList(head);
	deleteNodeByData(&head,6);
	printList(head);
	deleteNodeByPosition(&head,4);
	printList(head);
	countNodesInList(head);
	return 0;
}