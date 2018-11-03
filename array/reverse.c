#include<stdio.h>
void reverseArray(int arr[], int start, int end){
  if(start>=end) return;
  int temp;
  temp = arr[start];
  arr[start] = arr[end];
  arr[end] =temp;
  start++;
  end--;
}
//move all the 0 to the end of the array
void pushAllZeros(int arr[],int n){
  int i,count=0;
  for(i=0;i<n;i++){
    if(arr[i]!=0){
      arr[count++]=arr[i];
    }
    while(count<n){
      arr[count++]=0;
    }
  }
}
//rearrange alternately positive and negative number
void swap(int *a, int *b);
void ArrangeNegativeandPositive(int arr[],int n){
  int i=-1;
  for(int j=0;j<n;j++){
    if(arr[j]<0){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  //indexing the start point of negative and positive number
  int pos=i+1;
  int neg=0;
  while(neg<pos && pos<n && arr[neg]<0){
    swap(&arr[neg], &arr[pos]);
    pos++;
    neg+=2;
  }
}
void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void printArray(int arr[], int size){
  int i;
  for(i=0;i<size;i++)
    printf("%d",arr[i]);
    printf("\n");
}

int main(){
  int arr[] = {1 ,0 ,-2 ,0 ,-4 ,-5 ,0, 6};
  printArray(arr,6);
  // reverseArray(arr,0,5);
  // pushAllZeros(arr,6);
  ArrangeNegativeandPositive(arr,6);
  printArray(arr,6);
  return 0;
}
