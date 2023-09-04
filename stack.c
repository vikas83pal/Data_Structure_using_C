#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define CAPACITY 5

/*Creation Of a stack*/
int top = -1;
int stack[CAPACITY];

int isFull()
{
    if (top == CAPACITY - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data)
{
    
    if (isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = data;
        printf("Data is pushed\n");
    }
}

int pop()
{
    int temp;
    if (isEmpty())
    {
        printf("Stack Is empty\n");
    }
    else
    {
        temp = stack[top];
        top--;
        printf("%d is poped from the stack\n", temp);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack Is empty\n");
        
    } else {
        printf("%d\n", stack[top]);
    }
}


void disp()
{
    int i;
    if(isEmpty()){
        printf("Stack IS Empty\n");
    }
    else{
        for(i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int ch, val;

    while (1)
    {
        printf("Stack Operations\n");
        // printf("1. creation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");

        printf("Enter The Choice:");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter The data:");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            disp();
            break;
        case 5:
            exit(1);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}