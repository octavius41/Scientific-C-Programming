#include <stdio.h>
#include <stdlib.h>
#define A(i,j) (*(A + (i)*r + (j)))
#define B(i,j) (*(B + (i)*r + (j)))
#define C(i,j) (*(C + (i)*r + (j)))



void mat_mlt(int r, int c, int p, double *A, double *B, double *C){
	int i,j,k;
	double sum;
	for(i=0;i<r;i++){
		for(j=0;j<p;j++){
			for(k=0;k<c;k++){
				sum+= A(i,k)*B(k,j);
			}
			C(i,j) = sum;
			sum = 0;
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<p;j++){
			printf("c%d%d %lf ",&C(i,j));
		}
		printf("\n");
	}
	
}

void mat_tran(int r, int c, double *A, double *B){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			B(j,i)=A(i,j);
		}
	}
	
}

int main(){
	double *A;
	double *B;
	double *C;
	int r1,c1,r2,c2;
	int opt;
	printf("choose operation 1 for mult., 2 for transpose:\n");
	scanf("%d",&opt);
	while(opt==1){
		printf("enter row and column numbers of 1st matrix in order:\n");
		scanf("%d %d",&r1,&c1);
		printf("enter row and column numbers of 2nd matrix in order:\n");
		scanf("%d %d",&r2,&c2);
			A = (double*) malloc(r1*c1*sizeof(double));
			B = (double*) malloc(r2*c2*sizeof(double));
			C = (double*) malloc(c1*c2*sizeof(double));
			int i,j;
			if(c1 == r2){
				for(i=0;i<r1;i++){
					for(j=0;j<c1;j++){
						printf("a%d%d:",i,j);
						scanf("%lf",&A(i,j));
					}
				}
				for(i=0;i<r2;i++){
					for(j=0;j<c2;j++){
						printf("a%d%d:",i,j);
						scanf("%lf",&B(i,j));
					}
				}
				mat_mlt(r1,c1,c2,A,B,C);
				opt = 0;
			}
			if(c1 != c2){
				printf("column number of first and row number of second must be equal\n");
			}
			printf("\n");
	}
	if(opt==2){
		printf("enter row and column numbers of matrix in order:\n");
		scanf("%d %d",&r1,&c1);
		
		A = (double*) malloc(r1*c1*sizeof(double));
		B = (double*) malloc(c1*r1*sizeof(double));
		mat_tran(r1,c1,A,B);
	}
	printf("\n");
	free(A);
	free(B);
	}

