#include <stdio.h>
#include <stdlib.h>
struct snode {
int data;
struct snode *next;
};
struct snode *create(int x){

    struct snode *temp=(struct snode *)malloc(sizeof(struct snode));
    if(temp==NULL){
        printf("no space\n");
    }
    else{
        temp->data=x;
        temp->next=NULL;
        return temp;

    }
}


struct snode *push(struct snode *top,int x){
struct snode *newNode=create(x);

newNode->next=top;
top=newNode;
printf("%d pushed",x);
return top;

}
struct snode *pop(struct snode *top){
    if(top==NULL){
        printf("underflow");
    }
    else{
    struct snode *p1=top;
    int poppedData=p1->data;
    top=top->next;
    free(p1);
    printf("%d popped",poppedData);
    }
  return top;
}


struct snode *disp(struct snode *top){
    if(top==NULL)
    printf("stack underflow\n");
    else{
        struct snode *p1=top;
        printf("stack elements:  ");
        while(p1!=NULL){
            printf("%d\t",p1->data);
            p1=p1->next;
        }

    printf("\n");
    }
}

int size(struct snode *top){
    int count=0;
    struct snode *p1=top;
    while(p1!=NULL){
        count++;
        p1=p1->next;
    }
    return count;
}
int main(){
struct snode *top=NULL;
int choice,item,a;
do{
    printf("\nenter your choice:\n");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for display\n");
    printf("4 for size\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("enter item:");
    scanf("%d",&item);
    top=push(top,item);
    break;
case 2:
    top=pop(top);
    break;
case 3:
    disp(top);
    break;
case 4:
    a=size(top);
    printf("size: %d",a);
    break;
default:
    exit(0);

}
}while(1);

return 0;
}







