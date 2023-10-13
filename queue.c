#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define CAPACITY 5
int queue[CAPACITY], front = 0, rear = 0;

void delete()
{
     int temp,i;
     if (front==rear){
          printf("Queue is empty\n");

     }
     else{
          temp=queue[front];
          printf("%d is deleted\n",temp);
          /*traversee the data or shif the ele*/
          for(i=0;i<rear;i++){
               queue[i]=queue[i+1];
          }
          rear--;
     }
}
/*rear is used to insert the element*/
int insert(int data)
{
     if (rear == CAPACITY)
     {
          printf("Queue is full\n");
     }
     else
     {
          queue[rear] = data;
          rear++;
          printf("Data is Inserted\n");
     }
}

void disp(){
     int i;
     if (front==rear){
          printf("Queue is empty\n");

     }else{
          printf("Queue elements are:");
          for(i=front;i<=rear;i++){
               printf(" %d|",queue[i]);
          }
          printf("\n");
     }

}

int main()
{
     int ch, data;
     while (1)
     {
          printf("QUEUE OPERATIONS..\n");
     
          printf("1. insertion\n");
          printf("2. Deletion\n");
          printf("3. Display\n");
          printf("4. Quit\n");

          printf("Enter The choice:");
          scanf("%d", &ch);

          switch (ch)
          {
     
          case 1:
               printf("Enter The Data:");
               scanf("%d", &data);
               insert(data);
               break;
          case 2:

               delete();
               break;
          case 3:
               disp();
               break;
          case 4:
               exit(1);
               break;

          default:
               printf("Invalid choice\n");
               break;
          }
     }
     return 0;
}