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

/*Creation Of a list*/
void create(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&temp->data);
        //temp->link=NULL;
        temp->link=head;
        head=temp;
}

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

/*Function to insert a node at middle*/
void insertAtMiddle(){
    struct node* temp,*p;
    int loc,i,len;
    printf("Enter loction To be inserted:");
    scanf("%d",&loc);
    len=length(head);
    if(loc>len){
        printf("Invalid loction.\n");
        printf("Currently The List is Having %d Nodes",len);
    }
    else{
        p=head;
        while (i<loc)
        {
            p=p->link;
            i++;
        }        
        temp=(struct node*)malloc(sizeof(struct node*));
            printf("Enter data:");
            scanf("%d",&temp->data);
            temp->link=NULL;
            temp->link=p->link;
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
void revdisp() {
    struct node* temp;
    temp = head;
    
    if (temp == NULL) {
        printf("LIST IS EMPTY\n");
    } else {
        struct node* prev = NULL;
        
        // Traverse the list while reversing the links
        while (temp != NULL) {
            struct node* next = temp->link;
            temp->link = prev;
            prev = temp;
            temp = next;
        }
        
        // Now 'prev' points to the new head of the reversed list
        temp = prev;
        
        printf("Reversed List: ");
        
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        
        printf("NULL\n");
    }
}

/*function to del a node*/
void del(){
    struct node* temp;
    int loc;
    printf("Enter the Loction Of The Node To Be Deleted:");
    scanf("%d",&loc);
    if(loc>length(head)){
        printf("Invalid Loction\n");
    }
    else if(loc==1){
        temp=head;
        head=temp->link;
        temp->link=NULL;
        free(temp);
        printf("Node Is Deleted\n");
    }
    else{
        int i=1;
        struct node* p=head,*q;
        while(i<loc-1){
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
        printf("Node Is Deleted\n");
    }
}

int main(){
    int ch;
    while(1){
        printf("SINGLE LINKED LIST OPERATIONS\n");
        printf("1. Creation\n");
        printf("2. InsertAtBegin\n");
        printf("3. InsertAtEnd\n");
        printf("4. InsertAtMiddle\n");
        printf("5. Display\n");
        printf("6. length\n");
        printf("7. Reverse Display\n");
        printf("8. Deletion\n");
        printf("9. Exit\n");

        printf("Enter The Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: create();
                    break;
            case 2: insertAtBegin();
                    break;
            case 3: insertAtEnd();
                    break;
            case 4: insertAtMiddle();
                    break;
            case 5: disp();
                    break;
            case 6: len = length(head); 
                    printf("Length: %d\n", len); 
                    break;
            case 7: revdisp();
                    break;
            case 8: del();
                    break;
            case 9: exit(1);
                    break;
            default : printf("Invalid choice");
        }
    }
    getch();
    return 0;
}
