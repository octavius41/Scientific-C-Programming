#include <stdio.h>
#include <stdlib.h>
#define A(i,j) (*(A + (i)*r + (j)))
#define Mat(i,j) (*(Mat +(i)*r + (j)))
#define TempM(i,j) (*(TempM+i*(r-1)+(j)))


void getmat(int r,double *Mat){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			printf("a%d%d:",i,j);
			scanf("%lf",&Mat(i,j));
		}
	}
	printf("content of the matrix:\n");
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			printf("%lf ",Mat(i,j));
		}
		printf("\n");
	}
	printf("\n");
}

double printmat(double *Mat, int r){
	int i,j,k;
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			printf("%lf ",Mat(i,j));
		}
		printf("\n");
	}
	printf("\n");
}

/*double detMat(double *M, int c){
	double det =0;
	double temp;
	int i,j,k,x=0;
	if(c==1){
		det = M(0,0);
	}
	else{
		double *mat;
		mat = malloc(sizeof(double)*(c-1)*(c-1));
		for(k=0;k<c;k++){
			x=0;
			for(i=0;i<c;i++){
				for(j=0;j<c;j++){
					if(i!=0 && j != k){
						mat((x/(c-1)),(x%(c-1))) = M(i,j);
						c++;
					}
				}
			}
			temp = detMat(mat,c-1);
			if(0==(k%2))
			det += temp*M(0,k);
			else
			det-= temp*M(0,k);
		}
		free(mat);
	}
	return det;
}
*/
double determinant(double *Mat,int r){
	
	double det=0;
	double temp;
	
	int i,j,k,c=0;
	
	if(r==1){
		det=Mat(0,0);
		
	}
	else{
		double *TempM;
		TempM=malloc(sizeof(double)*(r-1)*(r-1));
		for(k=0;k<r;k++){
			c=0;
			for(i=0;i<r;i++){
				for(j=0;j<r;j++){
					if(i!=0 && j!=k){
						TempM((c/(r-1)),(c%(r-1))) = Mat(i,j);
						c++;
					}
				}
			}
			
			temp=determinant(TempM,r-1);
			if(0==(k%2)){
			det+=temp*Mat(0,k);
		
			}
			else{
				det-= temp*Mat(0,k);
				
			}
		}
			
		free(TempM);
		
			
	}

	return det;
}

void posdef(double *Mat, int r){
	int c,n,p,i,j,k;
	c = r-1;
	int arr[r-1];
	for(i=0;i<r;i++){
		printf("---------------\n");
		printmat(Mat,r-c);
		printf("---------------\n");
		printf("determinant = %lf \n",determinant(Mat,r-c));
		printf("---------------\n");
		arr[i] = determinant(Mat,c);

		--c;
	}
	p=0;
	n=0;
	
	for(j=0;j<r;j++){
		if(arr[j] > 0){
			p = p+1;
		}
		if(arr[j] < 0){
			n = n+1;
		}
	}
	if(p == r){
		printf("pozitive definite\n");
	}
	if(n == r){
		printf("negative definite\n");
	}
	if(p != r && n != r){
		printf("neither of them\n");
	}
	
}

int main(){
	int s,i,j,r,d1,d2,d3,ind,p,n,n_n;
	double *A;
	printf("enter the size of the square matrix\n");
	scanf("%d",&r);
	A = (double*) malloc(r*r*sizeof(double));
	getmat(r,A);
	posdef(A,r);
	
	return 0;
	
	
	
}
