#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>

int main(){
 __fpurge(stdin);
  //VAriaves de Criar conta
  int cpf[15], conta, saldo_in = 0, senha, operacao ;
  char nome[51];
  //variaveis de teste de login e senha
  int i, flag = 0, flag2 = 0;
  char id[15], pass[15], str[50];
  //Variaveis do usuario logado
  int opcao;

  system ("clear");
  printf("\t ______________________________________\n"  );
  printf("\t|     ****************************     |\n" );
  printf("\t|     ***Escolha uma das opções***     |\n" );
  printf("\t|     ****************************     |\n" );
  printf("\t|                                      |\n" );
  printf("\t|           [1] Criar Conta            |\n" );
  printf("\t|           [2] Entrar                 |\n" );
  printf("\t|                                      |\n" );
  printf("\t|______________________________________|\n" );

  scanf("%d", &operacao);
  system ("clear");

  switch (operacao){
    case 1:
   //Criando a conta e recebendo informações
            printf("________________________________________\n" );
            printf("\nEntre com os dados abaixo\n");
            printf("\nDigite seu nome: ");
            scanf("%s", &nome);
            printf("\nDigite seu numero de CPF: " );
            scanf("%d", &cpf);
            printf("\nDigite uma senha: " );
            scanf("%d", &senha);
            printf("\n________________________________________\n" );
            system ("clear");
            printf("\n\t|=Conta criada com sucesso=|\n" );
            printf("\n________________________________________\n" );

    // inicializar o gerador de números aleatórios
            srand(100);
    // para gerar números aleatórios de 0 a 50
            srand( (unsigned)time(NULL) );
                conta = rand() % 1000000;

    //Mostrando os dados da conta
            printf("\t|=DADOS DA CONTA=|\n" );
            printf("\n|Proprietario: %s", nome );
            printf("\n|CPF: %d", cpf );
            printf("\n|Senha: %d", senha );
            printf("\n|Numero da conta: %d\n", conta);
            printf("________________________________________\n" );
            getc;

            FILE *pont_arq;
            pont_arq = fopen("dados.txt", "a");
            fprintf(pont_arq, "|--------------------------|\n" );
            fprintf(pont_arq, "Proprietario: %s\n", nome);
            fprintf(pont_arq, "CPF: %i\n", cpf);
            fprintf(pont_arq, "Conta: %d\n", conta);
            fprintf(pont_arq, "Saldo: %d\n", saldo_in);
            fprintf(pont_arq, "|--------------------------|\n" );
            fclose(pont_arq);

            FILE *pont_senha;
            pont_senha = fopen("passwords.txt", "a");
            fprintf(pont_senha, "%d\n", senha);
            fclose(pont_senha);
            break;
    //Usuario ja cadastrado
    case 2:
            do{
              printf("________________________________________\n" );
              printf("\n***Entre com sua conta bancaria***\n" );
              printf("\n|CPF ou conta: " );
              scanf("%s", &id);
              pont_arq = fopen("dados.txt", "r");
              while((fscanf(pont_arq,"%s\n", &str))!= EOF){
                i++;
                if( (strcmp(id, str))==0){
                  flag = 1;
                  break;
                }
              }
              if(flag == 1)
                printf("|=CPF ou Conta correto, agora senha...=|\n");
              else
                printf("\n|=CPF ou Conta inexistente... Tente novamente|\n");

              fclose(pont_arq);
              }while(flag == 0);
          //Teste de senha
            do{
              printf("________________________________________\n" );
              printf("***Entre com sua senha***\n" );
              printf("\n|Senha: ");
              scanf("%s", &pass);

              pont_senha = fopen("passwords.txt", "r");
              while((fscanf(pont_senha,"%s\n", &str))!= EOF){
                i++;
                if( (strcmp(pass, str))==0){
                  flag2 = 1;
                  break;
                }
              }
              if(flag2 == 1)
                printf("|=Login correto acessando conta bancaria...=|\n");
              else
                printf("|=Senha incorreta... Tente novamente=|\n");
              printf("________________________________________\n" );
              fclose(pont_senha);
            }while(flag2 == 0);
            system("clear");

        //Menu do usuario
            printf("\t ______________________________________\n"  );
            printf("\t|     ****************************     |\n" );
            printf("\t|     ***Escolha uma das opções***     |\n" );
            printf("\t|     ****************************     |\n" );
            printf("\t|                                      |\n" );
            printf("\t|           [1] Saldo                  |\n" );
            printf("\t|           [2] Saque                  |\n" );
            printf("\t|           [3] Deposito               |\n" );
            printf("\t|           [4] Transferencia          |\n" );
            printf("\t|                                      |\n" );
            printf("\t|______________________________________|\n" );
            scanf("%d", &opcao);

            if (opcao == 1){
              printf("\t\n ______________________________________\n"  );
              printf("Seu saldo é: ");
              printf("\t\n ______________________________________\n"  );
            }

            break;

    return 0;
}
}
