//Faculdade: Pitagoras campus Turu
//Aluno: Leonardo Henrique Martins Ferreira
//Professor: João Antunes
//Sistema do banco para a obtenção da nota parcial 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>

//Variaves de Criar conta
int  conta, saldo_in = 0, senha, operacao ;
long int cpf, cpf1; //O cpf1 é do arquivo extrato
char nome[51];
//variaveis de teste de login e senha
int i, flag = 0, flag2 = 0;
char id[15], pass[15], str[50];
//Variaveis do usuario logado
int opcao, saldo_novo, saque, deposito, conta_des, valor_trans, voltar, voltar1;

//ponteiro do extrato

//Função principal do sistema
int main(void){
 __fpurge(stdin);

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
            scanf("%li", &cpf);
            printf("\nDigite uma senha(6 Digitos): " );
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
            printf("\n|CPF: %li", cpf);
            printf("\n|Senha: %d", senha );
            printf("\n|Numero da conta: %d\n", conta);
            printf("________________________________________\n" );

            FILE *pont_arq;
            pont_arq = fopen("dados.txt", "a");
            fprintf(pont_arq, "|--------------------------|\n" );
            fprintf(pont_arq, "Proprietario: %s\n", nome);
            fprintf(pont_arq, "CPF: %li\n", cpf);
            fprintf(pont_arq, "Conta: %d\n", conta);
            fprintf(pont_arq, "Saldo: %d\n", saldo_in);
            fprintf(pont_arq, "|--------------------------|\n" );
            fclose(pont_arq);

            FILE *pont_senha;
            pont_senha = fopen("passwords.txt", "a");
            fprintf(pont_senha, "%d\n", senha);
            fclose(pont_senha);


    //Usuario ja cadastrado
    case 2:
            do{
              printf("________________________________________\n" );
              printf("\n***Entre com sua conta bancaria***\n" );
              printf("\n|CPF ou conta: " );
              scanf("%s", &id);
              pont_arq = fopen("dados.txt", "r");
              //Testando dentro do arquivo para saber se tem o cpf cadastrado
              while((fscanf(pont_arq,"%s\n", &str))!= EOF){
                i++;
                if( (strcmp(id, str))==0){
                  flag = 1;
                  break;
                }
              }
              if(flag == 1)
                printf("|=CPF ou Conta encontrada=|\n");
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

            do{
              //Menu do Usuario
                   printf("\t   ||Logado com o CPF: %s||\n", id);
                   printf("\t   |No dia :%s As:%s|\n",__DATE__,__TIME__);
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
              //Saldo


                   if (opcao == 1){
                     printf("\t\n ______________________________________\n"  );
                     printf("Seu saldo é: %d", saldo_in);
                     printf("\t\n ______________________________________\n"  );
                     }
              //Saque
                   if (opcao == 2 && saldo_in == 0){
                     printf("\t\n ______________________________________\n"  );
                     printf("Você não tem dinheiro em conta para sacar!! "   );
                     printf("\t\n ______________________________________\n"  );
                   }
                   else if(saldo_in > 0){
                   printf("\t\n ______________________________________\n"  );
                   printf("|Digite o valor do saque: ");
                   scanf("%d", &saque);
                   saldo_in = saldo_in - saque;
                   printf("=|Saque efetuado com sucesso|=\n" );
                   printf("\t\n ______________________________________\n"  );
                 }
              //Deposito
                   if (opcao == 3){
                     printf("\t\n ______________________________________\n"  );
                     printf("|Digite o valor do deposito: ");
                     scanf("%d", &deposito);
                     saldo_in = deposito;
                     printf("\t=|Depositado com sucesso|=" );
                     printf("\t\n ______________________________________\n"  );

            //Gravando no arquivo

                     }
              //Tranferencia
                   if (opcao == 4){
                     printf("\t\n ______________________________________\n"  );
                     printf("|Digite a conta destino: ");
                     scanf("%d", &conta_des);
                     printf("|Valor da transferência:: ");
                     scanf("%d", &valor_trans);
                     printf("\n\t=|Tranferido com sucesso|=\n" );
                     printf("\t\n ______________________________________\n"  );
                   }

                   FILE *pont_extrato;
                   pont_extrato = fopen("extratos.txt", "a");
                   fprintf(pont_extrato, "|--------------------------------------|\n" );
                   fprintf(pont_extrato, "|No dia :%s As:%s|\n", __DATE__,__TIME__);
                   fprintf(pont_extrato, "|O CPF: %s Teve seu saldo alterado\n", id);
                   fprintf(pont_extrato, "|Novo saldo: %d\n", saldo_in);
                   fprintf(pont_extrato, "|--------------------------------------|\n" );
                   fclose(pont_extrato);

              //Voltando ao menu principal
                   printf("\n=|Digite qualquer numero para voltar ao menu inicial ou '0' para sair|=\n" );
                   scanf("%d", &voltar1);
                   voltar = voltar1;

                   system ("clear");
              //Salvando o novo extrato bancario

            }while (voltar > 0);

    return 0;
}
}
