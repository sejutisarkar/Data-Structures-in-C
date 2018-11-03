#include<stdio.h>
#include<malloc.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
}list;
//front of the list
void push(list ** head, int newData){
  list* new_node = (list*)malloc(sizeof(list*));
  new_node->data = newData;
  new_node->next = (*head);
  new_node->prev = NULL;
  if(*head != NULL){
    (*head)->prev = new_node;
  }
  (*head) = new_node;
}
//insert at the end of the linked list
void append(list** head, int newData){
  list *temp = *head;
  list * new_node = (list*)malloc(sizeof(list*));
  new_node->data = newData;
  new_node->next = NULL;
  if(temp == NULL){
    new_node->prev = NULL;
    *head = new_node;
    return;
  }
  while(temp->next != NULL){
    temp= temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;
  return;
}
//Delete a Node
void Delete(list** head, list*del){
  if(*head == NULL || del == NULL){
    return;
  }
  if(*head == del){
    *head = del->next;
  }
  if(del->next != NULL){
    del->next->prev = del->prev;
  }
  if(del->prev != NULL){
    del->prev->next = del->next;
  }
  free(del);
  return;
}
//reverse the PrintList
void Reverse(list** head){
  list* temp = NULL;
  list* current= *head;
  while(current != NULL){
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if(temp!= NULL)
    *head = temp->prev;
}
//Count number of NODES
int CountNodes(list* head){
  list* curr = head;
  int count = 0;
  while(curr != NULL){
    count++;
    curr = curr->next;
  }
  return count;
}
// swap kth node from first and end
void Swap(list** head, int k){
  int number = CountNodes(*head);
  printf("%d\n", number);
  if(number<k) {printf("not possible\n");}
  if(2*k-1 == number) {printf("not possible\n");}

  //find the kth node from beginning
  list* currentX = *head;
  list* prevX = NULL;
  for(int i = 1;i<k;i++){
    prevX= currentX;
    currentX = currentX->next;
  }
  //find the kth element from the last
  list* currentY = *head;
  list* prevY = NULL;
  for(int i =1;i<number-k+1;i++){
    prevY = currentY;
    currentY = currentY->next;
  }
  if(prevX)
  prevX->next = currentY;
  if(prevY)
  prevY->next = currentX;
  //swapNodes
  list* temp = currentX->next;
  currentX->next = currentY->next;
  currentY->next = temp;

  if (k == 1)
        *head = currentY;
    if (k == number)
        *head = currentX;
}
//Delete at a given position
void DeleteAtAGivenposition(list** head,int n){
  list* current = *head;
  if(*head!=NULL && n<=0) return;
  int i;
  for(i=1;current!=NULL && i<n;i++){
    current=current->next;
  }
  if(current==NULL) return;
  Delete(head,current);
}
void swap(int a,int b){
  int temp = a;
  a = b;
  b =temp;
}
void reverse(list* head){
  list *left = head;
  list *right = head;
  while(right->next != NULL){
    right = right->next;
  }
  while(left!=right && left->prev != right ){
    swap(left->data,right->data);
    left = left->next;
    right = right->prev;
  }
}
void removeDuplicates(list** head){
  list* current = *head;
  list* next;
  if((*head) == NULL) return;
  while(current->next != NULL){
    if(current->data == current->next->data){
      Delete(head,current->next);
    }else{
      current = current->next;
    }
  }
}
//remove duplicates from an unsorted LinkedList
void removeDuplicatesUnSorted(list**head, int x){
  if((*head) == NULL || (*head)->next == NULL) return;

  list *current = *head;
  list* ptr1, *ptr2;
  for(ptr1 = *head; ptr1 != NULL;ptr1=ptr1->next){
    ptr2 = ptr1->next;

    while(ptr2!=NULL){
      if(ptr1->data == ptr2->data){
        list *next = ptr2->next;
        Delete(head,ptr2);
        ptr2= next;
      }else{
        ptr2=ptr2->next;
      }
    }
  }
}
void PrintList(list* node){
  while(node != NULL){
    printf("%d ->",node->data);
    node  = node->next;
  }
}
int main(){
  struct Node *head = NULL;
  // push(&head,10);
  // push(&head,11);
  append(&head,1);
  append(&head,2);
  append(&head,33);
  append(&head,33);
  append(&head,33);
  append(&head,355);
  // Delete(&head,head->next);
//  Reverse(&head);

  PrintList(head);
  printf("\nLength is %d",CountNodes(head));
  printf("\n");
  // Swap(&head,2);
  // DeleteAtAGivenposition(&head,2);
  // reverse(head);
  removeDuplicates(&head);
  PrintList(head);
}
