#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 250
double polysum(int num, double array[MAXSIZE], double x){
	int i,j,k;
	double sum=0;
	for(i=num;i>=0;i--){
		sum += pow(x,i)*array[i];
	}
	return sum;
}


int main(){
	int deg,xl,xu,ct;
	printf("enter the degree of polynomial\n");
	scanf("%d",&deg);
	int i,j,k;
	double temp,val1,val2,ss,n,il;
	double a[MAXSIZE],v1[MAXSIZE],v2[MAXSIZE],ara[MAXSIZE];
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
	printf("input interval values (x_{L},x_{U}) and step size:\n");
	scanf("%d",&xl);
	scanf("%d",&xu);
	scanf("%lf",&ss);
	j=0;
	for(n=xl;n<xu;){
		val1 = polysum(deg,a,n);
		v1[j] = val1;
		n = n+ss;
		j=j+1;
	}	
	
	j=0;
	
	for(n=xu;n>xl;){
		val2 = polysum(deg,a,n);
		v2[j] = val2;
		n = n-ss;
		j=j+1;
	}	
	val1 = polysum(deg,a,xl);
	val2 = polysum(deg,a,xu);
	il = (xu-xl) / ss;
	
	for(i=0;i<il;i++){
		if(v1[i]*v2[i] <= 0){
			ara[i] = i;
		}
		if(v1[i]*v2[i] > 0){
			continue;
		}
	}
	for(i=0;i<MAXSIZE;i++){
		suma+=a[i];
    }
    printf("root %lf \n",suma);
		return 0;
}
