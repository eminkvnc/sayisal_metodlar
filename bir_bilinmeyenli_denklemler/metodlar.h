#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TOL 1e-3
#define NO 10
#define STR "\n\n \
Secim yapiniz:\n\n \
1-Yarilama Metodu\n \
2-Sabit Nokta Metodu\n \
3-Newton-Raphson Metodu\n \
4-Secant Metodu\n \
5-Regula-Falsi Metodu\n \
6-Exit\n\n"


double f(double x){
			
			double s;
			s = (x*x*x) - x - 1;
			return s;	
		}
	
	double f_turev(double x){
			double s;
			s = 3*(x*x)-1;
			return s;	
		}
	
		double g(double x){
			
			double s;
			s = (x*x*x)-1;
			return s;
		}
	
	double yarilama(double a , double b){
		
		int i = 1;
		double p = 0;
		double FP , FA;
		FA = f(a);
		if(f(a)*f(b)<0){
			printf("\nn	a		b		p		f(p)\n-----------------------------------------------------------------\n");
		while(i <= NO){
			p = (a+b)/2;
			FP = f(p);
			printf("%d	%f	%f	%f	%f\n", i , a , b , p , f(p));
			if(FP == 0 || (b - a)/2 < TOL){
				return p;
				}
			i = i + 1;
			if(FA*FP>0){
				a = p;
				FA = FP;	
				}
			else 
				b = p;
			}
			printf("Metod %d adimdan sonra basarisiz oldu.\n", NO);
			return p;
		}
		else {
			printf("Fonksiyonun girilen aralikta koku yok!\n");
			return 0;
		}
	}
	
	double sabit_nokta(double p0){
		int i = 1;
		double p = p0;
		printf("\nn	g(p)\n----------------\n");
		while(i <= NO){
			printf("%d	%f\n", i-1 , p);
			p = g(p0);
		if(p - p0 < TOL && p - p0 > -(TOL))
			return p;
		i = i + 1;
		p0 = p;
			}
		printf("Metod %d adimdan sonra basarisiz oldu.\n", NO);
			return p;
		}
	
	double newton_raphson(double p0){
		int i = 1;
		double p = p0;
		printf("\nn	pn\n----------------\n");
		while(i <= NO){
			printf("%d	%f\n", i-1 , p);
			p = p0-(f(p0)/f_turev(p0));
		if(p - p0 < TOL && p - p0 > -(TOL))
			return p;
		i = i + 1;
		p0 = p;
			}
		printf("Metod %d adimdan sonra basarisiz oldu.\n", NO);
			return p;
		}
	
	double secant(double p0 , double p1){
		int i = 2;
		double q0 = f(p0);
		double q1 = f(p1);
		double p = p0;
		printf("\nn	pn\n----------------\n");
		while(i <= NO){
			printf("%d	%f\n", i-2 , p0);
			p = p1-q1*(p1-p0)/(q1-q0);
		if(p - p0 < TOL && p - p0 > -(TOL))
			return p;
		i = i + 1;
		p0 = p1;
		q0 = q1;
		p1 = p;
		q1 = f(p);	
			}
		printf("Metod %d adimdan sonra basarisiz oldu.\n", NO);
			return p;
		}
	
	double regula_falsi(double p0 , double p1){
		int i = 2;
		double q0 = f(p0);
		double q1 = f(p1);
		double p = p0;
		double q;
		printf("\nn	pn\n----------------\n");
		while(i <= NO){
			printf("%d	%f\n", i-2 , p0);
			p = p1-q1*(p1-p0)/(q1-q0);
		if(p - p0 < TOL && p - p0 > -(TOL))
			return p;
		i = i + 1;
		q = f(p);
		if(q*q1 > 0){
			p0 = p;
			q0 = q;
			}
		else{
		p1 = p;
		q1 = q;
		}
		}
		printf("Metod %d adimdan sonra basarisiz oldu.\n", NO);
			return p;
		}
