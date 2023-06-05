#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dia, mes,ano, dj1;
	char semana [7];
	
	do{
		printf("insira a data(DD/MM/AAAA)");
		scanf("%d%d%d", &dia, &mes, &ano);
		printf("a data juliana correspondente a entrada é: %d", dj(ano,mes,dia));
		
		dj1 = dj(ano,mes,dia)%7;
		
		/*switch(dj1){
			
			case 0:
				
				break;
			
			case 1:
				
				break;
			
			case 2:
				
				break;
				
			case 3:
				
				break;
				
			case 4:
				
				break;
				
			case 5:
				
				break;
				
			case 6:
				
				break;
			
		}*/
		
		
		
	}
	while( dia<1 || dia<31 || )
	
	printf("%d",(dj(2023, 6,5)%7));
	
	
	
	
	
	
	
	
	return 0;
}



int dj(int Ano, int Mes, int Dia){
	int a, b,c,d,e,dj, sum, comp;
	 sum= Ano+Mes+Dia;
	 comp=1582+15+10;
	
	
	if(Mes<3){
		Ano--;
		Mes +=12;	
	}
	
	if(Ano >= 1582 ){
		
		a =(int)floor(Ano/100);
		b= (int)floor(a/4);
		c = a+b-2;
		}
		
	else if (Ano ==1582 && Mes >= 10 && Dia>=15){
			a =(int)floor(Ano/100);
			b= (int)floor(a/4);
			c = a+b-2;
		}
		
	else{
		c=0;
	}
	
	d =(int) floor(365.25*(Ano+4716));
	e = (int) floor(30.6001*(Mes+1));
	
	dj = d+e+Dia+c-1524;
	printf("%d \n", c);
	
	return dj;
	
	
}

int bisexto(ano){
	int t4, t100, t400;
	
	t4 = ano%4;
	
	t100 = ano%100;
	
	t400 = ano%400;
	
	if(t100==0 && t400 ==0 && t4==0){
		return 1;
	}
	else if (t100!=0 && t4==0){
		return 1;
	
	}
	
	else {
	return 0
	}
	
	
}





