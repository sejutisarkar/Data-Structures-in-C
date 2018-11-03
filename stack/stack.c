//implement queue using stack
#include<stdio.h>
#include<stdlib.h>
//structure for stack node
typedef struct sNode {
  int data;
  struct sNode *next;
}stack;

//push
void push(stack **top, int data);
//pop
int pop(stack **top);

//structure for queue
typedef struct queue{
  stack *stack1;
  stack *stack2;
} queue;

//enqueue
void enqueue(queue *q, int data){
  push(&q->stack1, data);
}

//dequeue
int dequeue(queue *q){
  int x;
  if(q->stack1 == NULL && q->stack2 == NULL) {
    printf("error");
    exit(0);
  }
  if(q->stack2 == NULL){
    while( q-> stack1 != NULL) {
      int x = pop( &q->stack1);
      push( &q->stack2, x);
    }
  }
  x = pop(&q->stack2);
  return x;
}

//push into the stack
void push( stack **top, int data){
  stack *new_node = (stack *) malloc(sizeof(stack*));
  if(new_node == NULL){
    printf("stack overflow");
    exit(0);
  }
  new_node->data = data;
  new_node->next = (*top);
  (*top) = new_node;
}
//pop from the stack
int pop(stack **top){
  int result;
  stack *temp;

  if(*top == NULL){
    printf("stack underflow");
    exit(0);
  }
  else{
    temp = (*top);
    result = temp->data;
    (*top) = temp->next;
    free(temp);
    return result;
  }
}

int main(){
  queue *q = (queue *)malloc(sizeof(queue * ));
  q->stack1 = NULL;
  q->stack2 = NULL;
  enqueue(q,1);
  enqueue(q,2);
  enqueue(q,3);
  //dequeue
  printf("%d", dequeue(q));
  printf("%d", dequeue(q));
  printf("%d", dequeue(q));
}
