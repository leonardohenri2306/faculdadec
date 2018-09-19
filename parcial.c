//Importação das bibliotecas padrões de comando e de syntax
#include<stdio.h>
#include<stdlib.h>

//Variavel principal do programa
int main (){

//Definição de variaveis
int cpf[11], depen;
char nome[41];
float sala, vlr, desc;

//Obtendo informações do usuario
	 printf("\n\t\t_____Imposto de renda_____\n");
	 printf("\n Informe seu CPF: ");
	 scanf("%d",&cpf);

	 printf("\n Informe nome do funcionario: ");
	 scanf("%s",&nome);

	 printf("\n Numero de dependentes: ");
	 scanf("%d",&depen);

	 printf("\n Informe seu salario:  ");
   scanf("%f",&sala);

//Testes condicionais do programa
	 if(sala<=1499.15){
	    printf("\n Total LIQUIDO a receber: %2.f . \n obs: Isento de Imposto de renda \n",sala);
			}
//Se não
   else if(sala>=1499.16  && sala<2246.75){
	     printf("\n Imposto de renda e de: 117");
	     desc=depen*0.05*540;
	     printf(" \n Desconto de dependentes %f",desc);
	     vlr=sala-(117-desc);
	     printf("\n Total LIQUIDO  a receber: %f",vlr	);
	 }
//Se não
   else if(sala>=2246.76 && sala<=2995.70){
	     printf("\n Imposto de renda: 280,94\n");
	     desc=depen*0.05*540;
       printf("\n Desconto Dependentes: %f",desc);
       vlr=sala-(280.94-desc);
       printf("\n Total Liquido a receber: %f",vlr);
	 }
//Se não
   else if(sala>=2995.71 && sala <=3743.19){
	     printf("\n Imposto de renda: 505,62");
       desc=depen*0.05*540;
       printf("\n Desconto Dependentes: %f",desc);
       vlr=sala-(505.62-desc);
       printf("\n Total Liquido a receber: %f",vlr);
	 }
//Se não
   else if(sala>=3743.20){
	     printf("\n Imposto de renda: 692,78");
	     desc=depen*0.05*540;
       printf("\n Desconto Dependentes: %f ",desc);
       vlr=sala-(692.78-desc);
       printf("\n Total Liquido a receber: %f",vlr);
	 }
//fim do programa
   printf("\t\t\n|=Fim do programa=|\n");

	 return(0);
   }
