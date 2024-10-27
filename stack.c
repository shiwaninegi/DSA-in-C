#include <stdio.h>
#include <stdlib.h>
#define max 10
void push (int stk[],int *top,int item){
	if(*top==max-1)
	printf("stack is full");
	else{
		(*top)++;
		stk[*top]=item;
	}
}
void pop(int stk[],int *top){
	if(*top==-1)
	printf("stack is empty");
	else{
		printf("the popped value is %d",
		stk[*top]);
		*top=*top-1;
	}
}
void traverse(int stk[],int *top){
	int temp,i;
	temp=*top;
	if(temp==-1){
		printf("stack is empty.");
	}
	else{
		for(i=temp;i>=0;i--){
			printf("%d\t",stk[i]);
		}
	}
}
int main(){
	int stack[max],top=-1,choice,item;
	do{
		printf("enter the choice of operation");
		printf("for push=1,for pop=2,for traverse=3");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter the no to be pushed:");
				scanf("%d",&item);
				push(stack,&top,item);
				break;
			case 2:
				pop(stack,&top);
				break;
			case 3:
				traverse(stack,&top);
				break;
			default:
				exit(0);
				
		}
	}while(1);
 return 0;
}

*/

/*
//stack implementation using structure
#include <stdio.h>
#include <stdlib.h>
struct stack{
	int size;
	int *s;
	int top;
	
};
void create(struct stack *st){
	printf("enter the size of stack:\n");
	scanf("%d",&st->size);
	st->top=-1;
	st->s=(int*)malloc(st->size*sizeof(int));
}
void push(struct stack *st,int x){
	if(st->top==st->size-1){
	printf("stack overflow\n");
}
	else{
		st->top++;
		st->s[st->top]=x;
		printf("%d is pushed in the stack.",x);
	}
}
int pop(struct stack *st){
	int x=-1;
	if(st->top==-1){
		printf("stack underflow\n");
	}
	else{
		x=st->s[st->top];
		st->top--;
		printf("%d is popped from the stack",x);
	}
	return x;
}
int size(struct stack *st){
	return st->top+1;
}
int main(){
	struct stack st;
	create(&st);
	int choice,value;
	printf("enter your choice\n1=push\n2=pop\n3=exit\4=calculate the size:\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf ("enter the number to be push:\n");
			scanf("%d",&value);
			push(&st,value);
			break;
		case 2:
			pop(&st);
			break;
		
		case 3:
			printf("exiting...\n");
			break;
		case 4:
			printf("size:%d \n",size(&st));
			break;
		default:
		       exit(0);
		    
	}while(choice!=4);
	return 0;
}





















