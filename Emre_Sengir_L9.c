#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

struct measurement{
	char parameter[N];
	char unit[N];
	struct measurement *nextPtr;
};

typedef struct measurement Measurement;
typedef Measurement *measurementPtr;

void insert_node(measurementPtr *x, char q[N], char u[N]){
	measurementPtr temp;
	temp = (measurementPtr*) malloc(sizeof(measurementPtr));
	strcpy(temp->parameter,q);
	strcpy(temp->unit,u);
	*x = temp;
}

void print_node(measurementPtr y){
	printf("\t%s\t\t\t\t%s\n",y->parameter,y->unit);
		
}



int main(){
	int opt,i;
	char q[N],u[N];
	measurementPtr exp1 = (measurementPtr*) malloc(sizeof(measurementPtr));
	printf("Choose an Operation\n1. Add a Measurement\n2.Delete a Measurement\n");
	scanf("%d",&opt);
	while(opt != 0){
		if(opt == 1){
			printf("Enter the Electrical Measurement Parameter\n");
			scanf("%s",q);
			printf("Enter the Parameter Unit\n");
			scanf("%s",u);
			insert_node(&exp1,q,u);
			printf("No\tParameters\t\t\tUnits\n");
			printf("--\t-----------\t\t\t----\n");
				while(exp1){
					print_node(&exp1);
					exp1 = exp1->nextPtr;
				}			
		}
		if(opt == 2){
			
		}
		printf("Choose an Operation\n1. Add a Measurement\n2.Delete a Measurement\n");
		scanf("%d",&opt);
	}
	
	
	return 0;
}
