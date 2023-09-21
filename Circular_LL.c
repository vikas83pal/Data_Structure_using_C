#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;

void insertAtBegin(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    if(temp == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data:");
    scanf("%d", &temp->data);
    
    if (head == NULL) {
        temp->next = temp; // Point the new node to itself to create a circular link
        head = temp; // Update head to the new node
    } else {
        
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head; // Point the new node to the current head
        temp->next = temp; // Update the last node to point to the new node
        head = temp; // Update head to the new node
    }
    
    printf("Node is inserted\n");
}


void delete(){

}

void search(){

}

void disp(){
    struct node* temp;
    temp = head;
    
    if (temp == NULL){
        printf("List is empty\n");
        return;
    }
    
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n"); // Add a newline character at the end for better formatting
}


int main(){
    int ch;
    while(1){
        printf("Circular Linked List..\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. searching\n");
        printf("4. Traversal\n");
        printf("5. Quit\n");

        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:insertAtBegin();
            break;
            case 2:delete();
            break;
            case 3:search();
            break;
            case 4:disp();
            break;
            case 5:exit(1);
            break;            
            default:
            printf("Invalid Choice");
        }

    }

    return 0;
}