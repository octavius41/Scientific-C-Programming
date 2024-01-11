#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define START 0.0
#define END 20.0

double f1(double x){
	double temp;
	temp = ((0.5)*exp(0.2*x)) + 20; 
	return(temp);
}

double f2(double x){
	double temp;
	temp = 0.01*pow(x,3) + 50;
	return (temp);
}

double rectangular(double (*f)(double), int n){
	int j,k;
	double temp,sum,h,i;
	h = 20.0/n;	
	for(i=START;i<END-h;){
		temp += f(i);
		i+=h;
	}
	sum = h*temp;
	return(sum);
}

double trapezoidal(double (*f)(double), int n){
	int j,k;
	double temp,sum,h,i;
	h = 20.0/n;	
	for(i=START+h;i<END;){
		temp += f(i-h)+f(i);
		i+=h;
	}
	sum = (h/2.0)*temp;
	return(sum);
}

int *number_of_panels_generator(){
	
}

double absolute(double va, double ve){
	double temp,abs;
	temp = ve-va;
	abs = fabs(temp);
	return(abs);
}

double relative(double va, double ve){
	double temp,abs;
	temp = (ve-va)/ve;
	abs = fabs(temp);
	return(abs);
}

double percentage(double va, double ve){
	double temp,abs;
	temp = (ve-va)/ve;
	abs = fabs(temp)*100;
	return(abs);
}

int main(){
	int temp;
	int i,panel;
	double v1,v2,a,e;
	e=866.04929;
	printf("\t\t\tRect. f1     Rect. f2         Rect. Area\t Abs.Error  Rela.Error\tPer.Error(%)\n");
	for(i=1;i<11;i++){
		panel = i*100;
		v1 = rectangular(f1,panel);
		v2 = rectangular(f2,panel);
		v2=v2-v1;
		a = v2-v1;
		printf("Number of panels:%d   |   ",panel);
		printf("%lf  ",v1);
		printf("%lf\t",v2);
		printf("%lf    |   ",a);
		printf("%lf   ",absolute(a,e));
		printf("%lf\t",relative(a,e));
		printf("%lf\n",percentage(a,e));
	}
	printf("\n\n");
	printf("\t\t\tTrap. f1     Trap. f2         Trap. Area\t Abs.Error  Rela.Error\tPer.Error(%)\n");
	for(i=1;i<11;i++){
		panel = i*100;
		v1 = trapezoidal(f1,panel);
		v2 = trapezoidal(f2,panel);
		v2=v2-v1;
		a = v2-v1;
		printf("Number of panels:%d   |   ",panel);
		printf("%lf  ",v1);
		printf("%lf\t",v2);
		printf("%lf    |   ",a);
		printf("%lf   ",absolute(a,e));
		printf("%lf\t",relative(a,e));
		printf("%lf\n",percentage(a,e));
	}	
}
