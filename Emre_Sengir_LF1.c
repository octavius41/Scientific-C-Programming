#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100

struct Node{
	char diff_method[N];
	float n_diff;
	float a_diff;
	float error;
	struct Node *nextPtr;
};

typedef struct Node Num_Diff;

float f(float x){
	double temp;
	temp = pow((x-3),2) + 1;
	return(temp);
}

float derivative(float x){
	double r;
	r=2*(x-3);
	return(r);
}

float forward_diff(float x,float h,float (*f)(float)){
	double r;
	r = (f(x+h)-f(x))/h;
	return(r);
}

float backward_diff(float x,float h,float (*f)(float)){
	double r;
	r = (f(x)-f(x-h))/h;
	return(r);
}

float centered_diff(float x,float h,float (*f)(float)){
	double r;
	r = (f(x+h)-f(x-h))/(2*h);
	return(r);
}

void printf_node(Num_Diff *y){
	printf("%s\t\t",y->diff_method);
	printf("%lf\t\t",y->n_diff);
	printf("%lf\t\t",y->a_diff);
	printf("%lf\n",y->error);
}

int main(){
	double x,h;
	printf("enter variable x\n");
	scanf("%lf",&x);
	printf("enter value of h in order to see it's effect\n");
	scanf("%lf",&h);
	printf("Numerical Derivative Method\tNumerical Solution\tAnalytic Solution\tError(%)\n");
	printf("------------------------\t----------------\t-----------------\t-------\n");
	Num_Diff *head;
	head = (Num_Diff*) malloc(sizeof(Num_Diff));
	Num_Diff *act = head;

	strcpy(act->diff_method,"Forward Difference");
	act->a_diff = derivative(x);
	act->n_diff = forward_diff(x,h,&f);
	act->error = (fabs(derivative(x)-forward_diff(x,h,&f))/derivative(x))*100;
	
	act->nextPtr = (Num_Diff*) malloc(sizeof(Num_Diff));
	act = act->nextPtr;
	strcpy(act->diff_method,"Backward Difference");
	act->a_diff = derivative(x);
	act->n_diff = backward_diff(x,h,&f);
	act->error = (fabs(derivative(x)-backward_diff(x,h,&f))/derivative(x))*100;
	
	act->nextPtr = (Num_Diff*) malloc(sizeof(Num_Diff));
	act = act->nextPtr;
	act->nextPtr = NULL;
	strcpy(act->diff_method,"Centered Difference");
	act->a_diff = derivative(x);
	act->n_diff = centered_diff(x,h,&f);
	act->error = (fabs(derivative(x)-centered_diff(x,h,&f))/derivative(x))*100;

	act = head;
	
	while(act){
		printf_node(act);
		act = act->nextPtr;
	}
}

