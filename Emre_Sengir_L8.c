#include <stdio.h>
#include <stdlib.h>

struct stackNode{
	char data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char info){
	StackNodePtr newPtr; // temporary node pointer
	newPtr = (StackNode*)malloc(sizeof(StackNode));
	if(newPtr){
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else{
		printf("%d not inserted. No memort available.\n",info);
	}
}

char pop(StackNodePtr *topPtr){
	StackNodePtr tempPtr;
	int popValue;
	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	
	return popValue;
}

int isEmpty(StackNodePtr topPtr){
	return topPtr;
}

int main(){
	StackNodePtr stackPtr = NULL;
	char c;
	printf("enter the text\n");
	while((c = getchar()) != '\n'){
		push(&stackPtr,c);
	}
	printf("reverse line\n");
	while(isEmpty(stackPtr)){
		printf("%c",pop(&stackPtr));
		
	}
	return 0;
}
