#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*creating a node*/
struct node{
    int data;
    struct node* link;
};
struct node* head=NULL;
int len;

/*Function to insert a node at begin*/
void insertAtBegin(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->link=head;
        head=temp;
    }
    
}

/*Function to insert a node at end*/
void insertAtEnd(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node* p;
        p=head;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
    }
}

/*Function to find length of the linked list*/
int length(struct node* head) {
    struct node* temp = head;
    int cnt = 0;
    
    while (temp != NULL) {
        cnt++;
        temp = temp->link;
    }

    return cnt;
}


/*function to display a linked list*/
void disp(){
    struct node* temp;
       temp=head;
       if(temp==NULL){
        printf("LIST IS EMPTY\n");
       }else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
       }
}

/*function to display a node in reverse order*/
void revdisp(){

}

/*function to del a node*/
void del(){
    
}

int main(){
    int ch;
    while(1){
        printf("\nSINGLE LINKED LIST OPERATIONS\n");
        printf("1. AddAtBegin\n");
        printf("2. AddAtEnd\n");
        printf("3. Display\n");
        printf("4. length\n");
        printf("5. Reverse Display\n");
        printf("6. Exit\n");

        printf("Enter The Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertAtBegin();
                    break;
            case 2: insertAtEnd();
                    break;
            case 3: disp();
                    break;
            case 4:
                    len = length(head); // Call the length function with the head of your linked list
                    printf("Length: %d\n", len); // Print the length
                    break;
            case 5: revdisp();
                    break;
            case 6: exit(1);
                    break;
            default : printf("Invalid choice");
        }
    }






    getch();
    return 0;
}