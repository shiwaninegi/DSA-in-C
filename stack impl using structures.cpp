#include <stdio.h>
#include <stdlib.h>
struct stack{
int size;
int *s;
int top;
};
void create(struct stack *st){
    printf("enter the size of the stack: ");
    scanf("%d",&(st->size));
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}
void push(struct stack *st,int x){
    if (st->top==st->size-1){
        printf("stack overflow\n");}
    else{
            st->top++;
            st->s[st->top]=x;
            printf("%d pushed in the stack",x);
    }
}
void pop(struct stack *st){
    if(st->top==-1){
        printf("stack underflow");
    }
    else{
        printf("%d popped from the stack\n",st->s[st->top]);
        st->top--;
    }

}
void display(struct stack *st){
    if (st->top==-1){
        printf("empty stack");
    }
    else{
    printf("stack element:\n");
    for(int i=st->top;i>=0;i--){
        printf("%d\t",st->s[i]);

    }
    }
}
int size(struct stack *st){
    return st->top+1;
}
void isempty(struct stack *st){
    if (st->top==-1){
printf("stack empty\n");
    }
else{
    printf("stack is not empty\n");
}
}
int main(){
    struct stack st;
    create(&st);
    int choice,item,siz;
    do{
        printf("\nenter the choice:\n1 for push \n2 for display\n3 for pop\n4 to calculate size\n5 for is empty or not\n");
        scanf("%d",&choice);
        switch(choice){
    case 1:
        printf("enter item:\n");
        scanf("%d",&item);
        push(&st,item);
        break;
    case 2:
        display
        (&st);
        break;
    case 3:
        pop(&st);
        break;
    case 4:
        siz=size(&st);
        printf("size:%d",siz);
        break;
    case 5:
        isempty(&st);
        break;

    default:
        exit(0);

        }
    }while(1);
    return 0;
}
