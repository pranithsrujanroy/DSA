#include<stdio.h>
/*
 * for malloc()
 */
#include<stdlib.h>

struct node_list{
  int data;
  struct node_tree* node;
  struct node_list* next;
}*front=NULL,*rear=NULL;

#define INORDER 1
struct node_tree{
  int data;
  struct node_tree* left;
  struct node_tree* right;
}*root = NULL;

node_list* create_queue(node_list **front_ref, node_list **rear_ref, node_tree *data){
  node_list *temp = (node_list*)malloc(sizeof(node_list));
  temp->node = data;
  temp->next = NULL;

  *front_ref = temp;
  *rear_ref = temp;
  return temp;
}
node_list* enqueue(node_tree *node){
  node_list *temp_node = (node_list*)malloc(sizeof(node_list));
  temp_node->node = node;
  temp_node->next = NULL;

  if((front == NULL)&&(rear == NULL)){
    front = temp_node;
    rear = temp_node;
  }
  else{
    rear->next = temp_node;
    rear = temp_node;
  }
  return rear;
}
node_tree* dequeue(){
  if(!front){
    return NULL;
  }
  else if(front == rear){
  }
  else{
    node_list *temp = front;
    front = front->next;
    node_tree* data = temp->node;
    free(temp);
    return data;
  }
}
void display_queue(){
  node_list *ptr = front;
  printf("\nQueue: ");
  while(ptr){
    printf("%d ",ptr->node->data);
    ptr = ptr->next;
  }
}

node_tree* insert_tree(int n){
  node_tree* newnode = (node_tree*)malloc(sizeof(node_tree));
  newnode->data = n;
  newnode->left = NULL;
  newnode->right = NULL;
  if(!root){
    root = newnode;
    return root;
  }
  //perform level order to insert
  //node_list *front, *rear;
  //create_queue(&front,&rear,root);
  enqueue(root);
  //node_list *ptr = front;
  //node_list *last_seen = ptr;
  while(front){
    //last_seen = ptr;
    node_tree* temp = dequeue();
    //ptr = front;
    if(temp->left != NULL)
      enqueue(temp->left);
    else{
      temp->left = newnode;
      break;
    }


    if(temp->right != NULL)
      enqueue(temp->right);
    else{
      temp->right = newnode;
      break;
    }
  }


  // enqueue(&rear,root);
  // display_queue(front);
  //
  // node_tree* tmp = dequeue(&front);
  // printf("\ndeleted node %d", tmp->data);

  //insert_queue()
  //while(root->left != NULL)

  return newnode;
}
void display_tree_inorder(node_tree* node){
  if(!node)
    return;

  display_tree_inorder(node->left);
  printf("%d ",node->data);
  display_tree_inorder(node->right);

}
void display_tree(int order){
  node_tree *start_node = root;

  if(order == INORDER)
    display_tree_inorder(start_node);
}

int main(){
  // node_list *front=NULL,*rear=NULL;
  // create_queue(&front, &rear, 10);
  // //printf("%d",front->data);
  // insert_queue(&rear, 2);
  // //printf("%d",rear->data);
  // display_queue(front);   //since front is not modified by display function

  //printf("\nRemoving from queue: %d",dequeue(&front));

  //node_tree* root = create_tree(2);
  insert_tree(1);
  insert_tree(2);
  insert_tree(3);
  display_tree(INORDER);
  printf("\nRoot: %d %d %d",root->data, root->left->data, root->right->data);
}
