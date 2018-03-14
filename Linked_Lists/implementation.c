#include<stdio.h>
#include<stdlib.h>
#include"implementation.h"
int main(){
	int n;
	printf("How many nodes do you wish to have initially?\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the data:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	Node* head = makeList(a,n);
	printList(head);
	insertNode(head,6,7);
	printList(head);
	deleteNodeByData(head,4);
	printList(head);
	deleteNodeByPosition(head,7);
	printList(head);
	return 0;
}