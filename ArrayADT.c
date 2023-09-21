#include<stdio.h>
#include<stdlib.h>
/*Used to customize the the array (Creating Our Own Array)*/
 
struct myArray{ //craetion of ADT
    int total_size;
    int used_size;
    int *p;
};

void createArray(struct myArray *a, int tsize,int usize){
    // (*a).total_size=tsize;
    // (*a).used_size=usize; 
    // (*a).p =(int *)malloc(tsize * sizeof(int));

    a->total_size=tsize;
    a->used_size=usize; 
    a->p =(int *)malloc(tsize * sizeof(int));


    
}


void show(struct myArray *a){
    int i;
    for(i=0;i<a->used_size;i++){
        printf("%d\n" , (a->p)[i]);
    }
}

void set(struct myArray *a){
    int i,n;
    for(i=0;i<a->used_size;i++){
        printf("Enter Element %d:",i);
        scanf("%d" , &n);
        (a->p)[i]=n;
    }
}
int main(){
    struct myArray marks;
    createArray(&marks,100,2);
    printf("We are running Set Now\n");
    set(&marks);
    printf("We Are running Show Now\n");
    show(&marks);
   
    return 0;
}