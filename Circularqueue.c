// Circular Queue implementation in C

#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;
int count=0;
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    count++;
  }
  
}
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    count--;
    return (element);
  }
  
}
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
 int ch,no;
    printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n5.size\n");
    while(1){
        printf("enter choice:-");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                printf("enter the data to be inserted :-");
                scanf("%d",&no);
                enQueue(no);
                break;
        case 2:
                deQueue ();
                break;
        case 3:
                display ();
                break;
        case 4:
             //   exit(1);
        case 5:
               printf("size is %d\n",count);
        }
    }
  return 0;
}