#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10

double polysum(int order, float array[MAXSIZE], double x){
	int i,j,k;
	double sum=0;
	for(i=order;i>=0;i--){
		sum += pow(x,i)*array[i];
	}
	return sum;
}

double derivative_polysum(int order, float array[MAXSIZE], double x){
	int i,j,k;
	double sum=0;
	j = order;
	for(i=order-1;i>=0;i--){
		sum += j*pow(x,i)*array[j];
		j = j-1;
	}
	return sum;
}

double newton_method(int order, float array[MAXSIZE], double x0, double epsilon, int N){
	double f0,g0,xn;
	f0 = polysum(order,array,x0);
	g0 = derivative_polysum(order,array,x0);
	int ct = 1;
	printf("Iteration\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\t\n");
	while(epsilon < fabs(f0) && N>ct){
		printf("\t%d\t\t%lf\t%lf\t",ct,x0,f0);
		x0 = x0 - (f0/g0);
		f0 = polysum(order,array,x0);
		g0 = derivative_polysum(order,array,x0);
		printf("%lf\t%lf\n",x0,f0);
		ct = ct+1;
	}
	printf("\n");
	if(ct == N){
		printf("not convergent\n");
	}
	if(ct < N){
		return x0;
	}
}

int main(){
	int deg,N;
	printf("enter the degree of polynomial\n");
	scanf("%d",&deg);
	int i,j,k;
	double temp,epsilon,x0,x1;
	float a[MAXSIZE];
	double suma;
	printf("enter the coefficients of the polynomial\n");
	for(i=deg;i>=0;i--){
		printf("x^%d: ",i);
		scanf("%lf",&temp);
		a[i] = temp;
	}
	for(i=deg;i>=0;i--){
		printf("%lf.x^%d ",a[i],i);
	}
	printf("\n");
	
	printf("enter the tolerable error, epsilon\n");
	scanf("%lf",&epsilon);
	printf("enter the maximum number of iterations, N\n");
	scanf("%d",&N);
	printf("enter the initial point, x0\n");
	scanf("%lf",&x0);
	printf("root = %lf\n",newton_method(deg,a,x0,epsilon,N));
	
}
	
	
	
	
