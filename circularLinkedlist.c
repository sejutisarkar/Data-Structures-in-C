#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
}list;

void push(struct Node **head){
  list* curr;
  list* new_node;
  curr = new_node = NULL;
  char choice = 'Y';
  do{
    printf("Add new Node(Y/N)");
    scanf(" %c",&choice );

    if(choice == 'Y')
    {
      new_node = (list*)malloc(sizeof(list*));
      printf("Enter data");
      scanf("%d",&new_node->data );

      if(*head == NULL)
      {
         curr = new_node;
        (*head) = new_node;
        (*head)->next = *head;
      }
      else
      {
        curr->next = new_node;
        new_node->next = *head;
        curr = new_node;
      }
  }
  else
  break;
}while(1);
}
void sortInsert(list** head,list* new_node){
  list* current = *head;
  if(current == NULL){
    new_node->next = new_node;
    *head = new_node;
  }
  else if(current->data >= new_node->data){
    while(current->next != *head){
      current = current->next;
    }
    current->next = new_node;
    new_node->next = *head;
    (*head) = new_node;
  }
  else{
    while(current->next != *head && current->next->data < new_node->data){
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}
//check if the linked list is circular
void checkCircular(list* head){
  list* curr = head->next;
  if(head == NULL) return;
  while(curr->next != head && curr != NULL){
    curr = curr->next;
  }
  if(curr->next == head)
  printf("it is circular");
  else
  printf("it is not circular");
}
void PrintList(struct Node* head){
  list* curr = head;
  if(head != NULL){
    do{
      printf("%d->",curr->data );
      curr = curr->next;
    }while(curr!=head);
  }
}
void Split(list *head, list **head1, list** head2){
  list* slow, *fast;
  slow=fast=head;
  if(head != NULL){
    while(fast->next != head && fast->next->next != head){
      fast = fast->next->next;
      slow = slow->next;
    }
    //for even nodes
    if(fast->next->next == head)
    fast=fast->next;
    //set the head pointer of the first half
    (*head1) = head;
    //set the head pointer of the second half
    if(head->next != head){
      (*head2) = slow->next;
    }
    //make the 2nd list circular
    fast->next = slow->next;
    //make the 1st list as circuar
    slow->next = head;
  }
}
int countNodes(struct Node* head){
  list* temp = head;
  int count = 0;
  if(head != null){
    do{
      temp = temp->next;
      count++;
    }while(temp!= head)
  }
  return  count;
}
int main(){
  list* head = NULL;
  list* list1 = NULL;
  list* list2 = NULL;
  list* new = (list*) malloc(sizeof(list*));
  new->data = 7;
  push(&head);
  PrintList(head);
  // printf("the LinkedList is\n");
  //Split(head, &list1, &list2);

  // printf("\n");
  // PrintList(list1);
  printf("\n");
  // PrintList(list2);
 // sortInsert(&head,new);
checkCircular(head);
countNodes(head);
 // PrintList(head);
}
