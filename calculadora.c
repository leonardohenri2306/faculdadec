#include <stdio.h>
#include <stdlib.h>


int main(){
  //variaves do sistema
int num1, num2, result, saida, operacao;

  //Teste de repetição
do {
  //Inicio
  system("clear");
  printf("\n\t|=Bem vindo a Agecalc=|\n");
  printf("Porfavor escolha umas das operações abaixo!\n");
  printf("\n|'1' Soma+|, |'2' Subtração-|, |'3' Divisão/|, |'4' Multipicação*|\n");
  scanf("%d", &operacao);

  //Escolha das operação
  switch (operacao){
    case 1:
      printf("\nVoce está somando!\n");
      printf("\nDigite o primeiro numero para somar: ");
      scanf("%d", &num1);
      printf("\nDigite o segundo numero para somar: ");
      scanf("%d", &num2);
      result = num1 + num2;
      printf("\nO resultado da soma é: %d\n", result);
      break;
    case 2:
      printf("\nVoce está subitraindo!\n");
      printf("\nDigite o primeiro numero para subtrair: ");
      scanf("%d", &num1);
      printf("\nDigite o segundo numero para subtrair: ");
      scanf("%d", &num2);
      result = num1 - num2;
      printf("\nO resultado da subtração é: %d\n", result);
      break;
    case 3:
      printf("\nVoce está dividindo!\n");
      printf("\nDigite o primeiro numero para dividir: ");
      scanf("%d", &num1);
      printf("\nDigite o segundo numero para dividir: ");
      scanf("%d", &num2);
      result = num1 / num2;
      printf("\nO resultado da divisão é: %d\n", result);
      break;
    case 4:
      printf("\nVoce está multiplicando!\n");
      printf("\nDigite o primeiro numero para multiplicar: ");
      scanf("%d", &num1);
      printf("\nDigite o segundo numero para multiplicar: ");
      scanf("%d", &num2);
      result = num1 * num2;
      printf("\nO resultado da multiplicação é: %d\n", result);
      break;
    }
  printf("\nDigite '0' para sair, ou '1' para continuar calculando: " );
  scanf("%d", &saida);
}while(saida == 1);

  return 0;
}
