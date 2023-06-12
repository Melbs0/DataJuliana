#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dia, mes,ano, dj1;
	int monthCheck, b6, Ce, allCheck;

	
	do{
		
		printf("insira a data(DD/MM/AAAA)\n");
		scanf("%d%d%d", &dia, &mes, &ano);
		
		
		b6 = bisexto(ano);
		monthCheck = checaMes(mes, dia, b6);
		Ce = casosEspecificos(dia, mes, ano);
		allCheck = monthCheck * Ce;
		
		if(allCheck == 0){
			
			printf("a data inserida e invalida! \n");
			
		}
		
		else {
			
			
			printf("a data juliana correspondente a entrada e: %d \n", dj(ano,mes,dia));
			
			printf("esse dia caiu em ");
		
			dj1 = dj(ano,mes,dia)%7;
			
			switch(dj1){
				
				case 0 :
					printf("um domingo\n");
					break;
				
				case 1 :
					printf("uma segunda\n");
					break;
				
				case 2 :
					printf("uma ter�a\n");
					break;
				
				case 3 :
					printf("uma quarta\n");
					break;
				
				case 4 :
					printf("uma quinta\n");
					break;
			
				case 5 :
					printf("uma sexta\n");
					break;
				
				case 6 :
					printf("um sabado\n");
					break;
			}
			
		}
		
	}while(allCheck == 1 );
	
	
	printf("o programa foi finalizado pois uma data invalida foi inserida");
	
	return 0;
}



int dj(int Ano, int Mes, int Dia){
	int a, b,c,d,e,dj;
	
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
		return 0;
		}
	
	
}
int checaMes (int mes, int dia, int b6){ 
	if (mes>12|| mes < 1 || dia >31 ||dia < 1  ){ /*checa se o ano tem entre 1 e 12 meses e se os meses tem entre 1 e 31 dias*/
		return 0;
		}
	

	else if(mes == 2 && dia >27){ // checa se o mes e fevereiro, e se o dia e maior que 27
		
		if (b6 ==0 && dia == 28){ //checa se o ano nao e bissexto E se tem a quantidade certa de dias
				
			return 1;
			}

		else if (b6 == 1 && dia == 29){ //checa se o ano e bissexto E se tem a quantidade certa de dias
			return 1;
			}

		else { //retorna 0 (false) caso o dia de fevereiro seja invalido >28 em ano não bissexto ou > 29 em ano bissexto 
			return 0;
			}
		}


	else if (mes != 2 && dia >=30){ // checa se o mês é diferente de fevereiro e se o dia é igual ou maior que 30
		if (mes == 1 || mes == 3|| mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 && dia == 31) { // checa se o mes deve ter 31 dias
			return 1;
			}

		else if (mes == 4 ||mes == 6 ||mes == 9 ||mes == 11 && dia == 30){ // checa se o mes deve ter 30 dias
			return 1;
			}

		else { // retorna 0 (false) caso, o dia seja 31 dias em um mes onde devria ter apenas 30 e vice versa
			return 0;
			}
	}

	else { // retorna 1 (true) para 1 <= mes <=12, e para qualquer dia <=27	
		return 1;
		}

	}
	
	int casosEspecificos (int dia, int mes, int ano){

		/*
		checa datas especificas: 
		
		-como anteriores a 24/11/4714 AEC
		- "   posteriores a 23/11/3766 DEC
		- entre 5/10 e 14/10 de 1524
		*/

		/*if (ano < -4714){ // checa se o ano � anterior a 4714 AEC
			return 0;
		}
		else */if ( ano == -4714 && mes<11 && dia < 24){
			return 0;
		}
		else if (ano == 0){
			return 0;
		}
		else if (ano > 3766){
			return 0;
		}
		else if (ano == 3766 && mes > 11 && dia >23){
			return 0;
		}
		else if (ano == 1524 && mes == 10 && dia >=5){
			return 0;
		}
		else if (ano == 1524 && mes == 10 && dia <=14){
			return 0;
		}
		else {
			return 1;
		}

	}




