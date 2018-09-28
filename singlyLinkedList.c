#include<stdio.h>
#include<malloc.h>

typedef struct Node {
  int data;
  struct Node * next;
}list;

void push (struct Node **head, int new_data){
  list* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head);
  (*head) = new_node;
}
void append(struct Node** head, int new_data){
  list* new_node = (struct Node*) malloc(sizeof(struct Node));
  list* temp = *head;
  new_node-> data = new_data;
  new_node->next = NULL;

  if(*head == NULL){
    (*head) = new_node;
    return;
  }

  while(temp->next != NULL){
    temp = temp->next;
    }
    temp->next = new_node;


}
void insertAfter(struct Node* prev, int new_data){
  list* new_node = (struct Node*) malloc(sizeof(struct Node));
    if(prev == NULL){
      return;
    }
  new_node-> data = new_data;
  new_node->next = prev->next;
  prev->next = new_node;

}
//length of the LinkedList

int length(struct Node* head){
  int count = 0;
  list* current = head;
  while(current != NULL){
    count ++;
    current = current->next;
  }
  return count;
}

//nth node from the end pf a LinkedList
void End(struct Node* head, int n){
  list* temp = head;
  int len=0,i;
  while(temp != NULL){
    temp = temp->next;
    len++;
  }
  if(len<n){
    printf("\n Not possible");
    return;
  }
  temp=head;
  for(i=1;i<len-n+1;i++){
    temp=temp->next;
  }
  printf("%d",temp->data);
  return;

}
//print the middle element of a linked PrintList
void MiddleElement(struct Node* head){
  list* slow= head;
  list* fast=head;
  if(head != NULL){
    while(fast != NULL && fast->next != NULL){
      fast = fast->next->next;
      slow= slow->next;
    }
    printf("\nmiddle element of the linked list is : %d",slow->data );
  }
}
void DetectLoop(struct Node* head){
  list* slow = head;
  list* fast = head;
  if(head != NULL){
    while(slow && fast && fast->next){
      slow= slow->next;
      fast = fast->next->next;
      if(slow == fast){
        printf("\n Found Loop" );
      }else{
        printf("No Loop\n");
      }
    }
  }
}
void PrintList(struct Node* node){
  while(node != NULL){
    printf("%d ->",node->data );
    node = node->next ;
  }
}
//remove Duplicates
void removeDuplicates(struct Node* head){
  list* current = head;
  list* temp;
  if(current == NULL){
    return;
  }
  while(current->next != NULL){
    if(current->data == current->next->data){
      temp = current->next->next;
      free(current->next);
      current->next = temp;
    }else{
      current = current->next;
    }
  }
}
//remove duplicates from an unsorted linked list
void removeDuplicatesUnSorted(struct Node* head){
  list* ptr1, *ptr2, *dup;
  ptr1 = head;

  while(ptr1 != NULL && ptr1->next != NULL){
    ptr2 = ptr1;
    while(ptr2->next != NULL){
      if(ptr1->data  == ptr2->next->data){
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        free(dup);
      }else{
        ptr2 = ptr2->next;
      }
    }
    ptr1 = ptr1->next;
  }
}
//SWAP NODES
void swapNodes(struct Node** head,int x, int y){
  if(x == y) return;
  list *currentX, *prevX = NULL;
  list *currentY, *prevY = NULL;
  currentX = *head;
  currentY = *head;
  while(currentX && currentX->data != x){
    prevX = currentX;
    currentX = currentX->next;
  }
  while(currentY && currentY->data != y){
    prevY = currentY;
    currentY = currentY->next;
  }
  //if x and y are not present
  if(currentX == NULL && currentY == NULL){
    return;
  }
  //if x is not the head
  if(prevX != NULL){
    prevX->next = currentY;
  }else{
    *head = currentY;
  }
  //if y is not the head
  if(prevY != NULL){
    prevY->next = currentX;
  }else{
    *head = currentX;
  }
  list* temp;
  temp = currentX->next;
  currentX->next = currentY->next;
  currentY->next = temp;
}
//pairwise swap data
//swapfunction
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void pairWiseSwap(struct Node* head){
  list* temp = head;
  while(temp && temp->next != NULL){
    swap(&temp->data, &temp->next->data);
    temp = temp->next->next;
  }
}
//move last element to the first
void MoveLastElement(struct Node** head){
  list*secLast, *temp = *head;
  if((*head) == NULL || (*head)->next == NULL){
    return;
  }
  while(temp->next != NULL){
    secLast = temp;
    temp = temp->next;
  }
  secLast->next = NULL;
  temp->next = *head;
  *head = temp;
}
//Intersection of two LinkedList
// list* Intersection(struct Node* a, struct Node* b){
//   if(a ==  NULL && b == NULL) return;
//   if(a->data < b->data){
//     return Intersection(a->next,b);
//   }
//   if(a->data > b->data){
//     return Intersection(a, b->next);
//   }
//   list* temp = (struct Node *) malloc(sizeof(struct Node *));
//   temp->data = a->data;
//   temp->next = Intersection(a->next,b->next);
//   return temp;
// }
//segregate the even and odd datas
void segregateEvenOdd(struct Node** head){
  list* evenStart=NULL, *evenEnd=NULL, *oddStart=NULL, *oddEnd=NULL;
  list* curr = *head;

  if(curr != NULL){
    int val = curr->data;
    if(val%2==0){
      if(evenStart == NULL){
        evenStart = curr;
        evenEnd = evenStart;
      }else{
        evenEnd = curr;
        evenEnd = evenEnd->next;
      }
    }else{
      if(oddStart == NULL){
        oddStart = curr;
        oddEnd = oddStart;
      }else{
        oddEnd = curr;
        oddEnd = oddEnd->next;
      }
    }
    curr = curr->next;
  }
  if(oddStart==NULL || evenStart==NULL) return;
  //Add Oddlist after evenlist
  evenEnd->next = oddStart;
  oddEnd->next = NULL;

  *head = evenStart;
}
//reverse
void Reverse(struct Node** head){
  list* prev = NULL;
  list* next = NULL;
  list* curr = *head;
  while(curr != NULL){
    //store the next
    next = curr->next;
    //Reverse
    curr->next = prev;
    //move the pointer one step ahead
    prev = curr;
    curr = next;
  }
  *head = prev;
}
int main(){
  struct Node* head = NULL;
  push(&head,11);
  append(&head, 12);
  append(&head, 56);
  append(&head,443);
  append(&head, 7);
  append(&head,4440);
  insertAfter(head->next , 20);
  printf("\n The LinkedList is: ");
  PrintList(head);
  printf("\nThe length of the linked list is %d\n ",length(head));
  End(head,3);
  MiddleElement(head);
  //DetectLoop(head);// length(head);
  //removeDuplicates(head);
  //removeDuplicatesUnSorted(head);
  printf("\n");
  //swapNodes(&head, 11,4440);
  //pairWiseSwap(head);
  //MoveLastElement(&head);
  //segregateEvenOdd(&head);
  Reverse(&head);
  PrintList(head);

}
