#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double g_function(double Vc0, double R, double C, double Vs){
	double temp,div,pow;
	temp = (1.0/(R*C))*(Vs-Vc0);
	return temp;
}

double y_exact(double t, double R, double C, double Vs){
	double temp,div,pow;
	div = -t/(R*C);
	temp = Vs*(1-exp(div));
	return temp;
}

double euler(double t0, double Vc0, double (*g)(double,double,double,double), double h, double tlast, double R, double C, double Vs){
	double i,j,Vc;
	Vc=Vc0;
	for(i=0.0;i<tlast;){
		Vc = Vc + (h*g_function(Vc,R,C,Vs));
		i = i+h;
	}
	return Vc;
}

double error(double ea, double va){
	double temp;
	temp = ((ea-va)/ea) * 100;
	temp = fabs(temp);
	return temp;
}

int main(){
	double t0,Vc0,R,C,Vs,h1,h2,h3,tlast,eval;
	int i,j;
	double yval;
	printf("input respectively\n");
	printf(" t0 Vc0\n");
	scanf("%lf",&t0);
	scanf("%lf",&Vc0);
	printf(" R C V\n");
	scanf("%lf",&R);
	scanf("%lf",&C);
	scanf("%lf",&Vs);
	printf("input stepsize\nh1=");
	scanf("%lf",&h1);
	printf("input stepsize\nh2=");
	scanf("%lf",&h2);
	printf("input stepsize\nh3=");
	scanf("%lf",&h3);
	printf("input t_last\ntlast:");
	scanf("%lf",&tlast);
	yval = y_exact(tlast,R,C,Vs);
	printf("exact voltage : %lf\n",yval);
	eval = euler(t0,Vc0,g_function,h1,tlast,R,C,Vs);
	printf("euler for 0.1 %lf\n",eval);
	printf("Percentage error for h = %lf: %lf\n",h1,error(yval,eval));
	eval = euler(t0,Vc0,g_function,h2,tlast,R,C,Vs);
	printf("euler for 0.01 %lf\n",eval);
	printf("Percentage error for h = %lf: %lf\n",h2,error(yval,eval));
	eval = euler(t0,Vc0,g_function,h3,tlast,R,C,Vs);
	printf("euler for 0.001 %lf\n",eval);
	printf("Percentage error for h = %lf: %lf\n",h3,error(yval,eval));
	
}
