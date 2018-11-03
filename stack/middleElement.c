//design a stack with operations on middle element
 //structure of the DLL
 struct DLLnode {
   struct DLLnode *prev;
   struct DLLnode *next;
   int data;
 }

 //structure of the stack
 struct stack {
   struct DLLnode *head;
   struct DLLnode *mid;
   int count;
 }
 //create stack
 struct stack *createStack(){
   struct stack *ms = (struct stack*)malloc(sizeof(struct stack*));
   ms->count = 0;
   return ms;
 }
 //push operations
void push(struct stack *ms, int data){
  struct DLLnode *newDll_node = (struct DLLnode *)malloc(sizeof(struct DLLnode*));
  newDll_node->data = data;
  newDll_node->prev = NULL;
  newDll_node->next = ms->head;

  ms->count +=1;

  //update the middle element if the elements are odd and the list is empty
  if(ms->count == 1){
    ms->mid = newDll_node;
  }
  else{
    ms->head->prev = new_DLLNode;

      if (ms->count & 1) // Update mid if ms->count is odd
         ms->mid = ms->mid->prev;
  }
  }
  /* Function to pop an element from stack */
  int pop(struct myStack *ms)
  {
      /* Stack underflow */
      if (ms->count  ==  0)
      {
          printf("Stack is empty\n");
          return -1;
      }

      struct DLLNode *head = ms->head;
      int item = head->data;
      ms->head = head->next;

      // If linked list doesn't become empty, update prev
      // of new head as NULL
      if (ms->head != NULL)
          ms->head->prev = NULL;

      ms->count -= 1;

      // update the mid pointer when we have even number of
      // elements in the stack, i,e move down the mid pointer.
      if (!((ms->count) & 1 ))
          ms->mid = ms->mid->next;

      free(head);

      return item;
  }

  // Function for finding middle of the stack
  int findMiddle(struct myStack *ms)
  {
      if (ms->count  ==  0)
      {
          printf("Stack is empty now\n");
          return -1;
      }

      return ms->mid->data;
  }

  // Driver program to test functions of myStack
  int main()
  {
      /* Let us create a stack using push() operation*/
      struct myStack *ms = createMyStack();
      push(ms, 11);
      push(ms, 22);
      push(ms, 33);
      push(ms, 44);
      push(ms, 55);
      push(ms, 66);
      push(ms, 77);

      printf("Item popped is %d\n", pop(ms));
      printf("Item popped is %d\n", pop(ms));
      printf("Middle Element is %d\n", findMiddle(ms));
      return 0;
  } 
