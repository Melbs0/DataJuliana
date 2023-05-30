#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dia, mes,ano;
	
	printf("%d",dj(2023, 5,26));
	
	
	
	
	
	
	
	
	return 0;
}



int dj(int Ano, int Mes, int Dia){
	int a, b,c,d,e,dj;
	
	if(Mes<3){
		Ano--;
		Mes +=12;	
	}
	
	if(Ano <=1582 && Dia <= 15 && Mes <=10 ){
		
		a =(int)floor(Ano/100);
		b= (int)floor(a/4);
		c = 2-a+b;
		}
	else{
		c=0;
	}
	
	d =(int) floor(365.25*(Ano+4716));
	e = (int) floor(30.6001*(Mes++));
	
	dj = d+e+Dia+c-1524;
	
	return dj;
	
	
}
