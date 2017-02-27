
#include <//home/emin//Belgeler//metodlar.h>

	int main(){
		
		int secim;
		
		double a = 1.0;
		double b = 2.0;
		double p;
		printf(STR);
		scanf("%d" , &secim);
		while(1){
		switch(secim){
		case 1:
		p = yarilama(a , b);
		break;
		case 2:
		p = sabit_nokta(1.5);
		break;
		case 3:
		p = newton_raphson(1.5);
		break;
		case 4:
		secant(1.0 , 1.5);
		break;
		case 5:
		regula_falsi(1.5 , 2.0);
		break;
		case 6:
		exit(0);
		break;
	}
		printf(STR);
		scanf("%d" , &secim);
	}
		return p;
		}
	

