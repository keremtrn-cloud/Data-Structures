#include <stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1; 
void enqueue(int x);
void display();
void dequeue();

int main(){
    
    int queue[N];
    int front = -1;
    int rear = -1;
    
    enqueue(2);
    enqueue(2);
    
    display();
   
   
    
 }   
void enqueue(int x){
	
	
     
    if((front+1)%N == front){
        printf("queue is full");
         }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear]=x;
         }
    else{
         queue[rear] = x;
         }
 }
void dequeue(){
    
    if(front == -1 && rear ==-1){
        printf("queue  is empty");
        }
    else if(front == rear)
     {
       front = 1;
     }
    else{
        printf("%d \n",queue[front]);
        front = front+1%N;
     }
}
void display(){
    
    int i = front;
     
    if(front == -1 && rear==-1){
       printf("queue  is empty");
        }
    else{
       printf("Queue is");
       while(queue[i] != rear){
              
            printf("%d",queue[i]);
            i = (i+1)% N;
            }
        printf("%d",queue[rear]);
     }
}
