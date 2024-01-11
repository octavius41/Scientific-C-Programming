#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fpower(double x){
	double temp;
	temp = 60*exp(-50*x);
	return(temp);	
}

double left_rectangular(double (*f)(double), double a, double b, int n){
	int j,k;
	double temp,sum,h,i,dif;
	dif = b-a;
	h = dif/n;	
	for(i=a;i<=b-h;){
		temp += fpower(i);
		i+=h;
	}
	sum = h*temp;
	return(sum);
}

double right_rectangular(double (*f)(double), double a, double b, int n){
	int j,k;
	double temp,sum,h,i,dif;
	dif = b-a;
	h = dif/n;	
	for(i=a+h;i<=b;){
		temp += fpower(i);
		i+=h;
	}
	sum = h*temp;
	return(sum);
}

double simpson(double (*f)(double), double a, double b, int n){
	double temp,sum,h,i,dif;
	dif = b-a;
	h = dif/n;	
	for(i=a;i<=b;){
		temp += (fpower(i))+(4*fpower(i+(h/2)))+(fpower(i+h));
		i+=h;
	}
	sum = (h/6)*temp;
}

int main(){
	
	int temp;
	int i,panel;
	double v1,v2,v3,trap,a,b;
	printf("enter the beggining point of the integral:\n");
	scanf("%lf",&a);
	printf("enter the end point of the integral:\n");
	scanf("%lf",&b);
	
printf("\t\t\tLeft Rectangular Method \t   Trapezoidal Method \t\t Simpson's Method \n");
	for(i=1;i<11;i++){
		panel = i*10;
		v1 = left_rectangular(fpower,a,b,panel);
		v2 = right_rectangular(fpower,a,b,panel);
		v2 = v2-v1;
		trap=(v1+v2)/2.0;
		v3 = simpson(fpower,a,b,panel);
		printf("Number of panels : %d\t\t ",panel);
		printf("%.10lf \t\t\t ",v1*pow(10,-3));
		printf("%.10lf \t\t\t ",trap*pow(10,-3));
		printf("%.10lf\n",v3*pow(10,-3));
		

}
	printf("val %lf",fpower(0.05));
}

