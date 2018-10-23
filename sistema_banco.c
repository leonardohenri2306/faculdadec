//Faculdade: Pitagoras campus Turu
//Aluno: Leonardo Henrique Martins Ferreira
//Professor: João Antunes
//Sistema do banco para a obtenção da nota parcial 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Variaves de Criar conta
int  conta, saldo_in = 0, senha, operacao ;
long int cpf, cpf1, cpf_des; //O cpf1 é do arquivo extrato
char nome[51];
//variaveis de teste de login e senha
int i, flag = 0, flag2 = 0;
char id[15], pass[15], str[50];
//Variaveis do usuario logado
int opcao, saldo_novo, saque, deposito, conta_des, valor_trans, voltar, voltar1;

//ponteiro do extrato

//Função principal do sistema
int main(void){

  system ("clear");
  printf("        Developer: Leonardo Henrique Martins Ferreira\n");
  printf("\t ______________________________________\n"  );
  printf("\t|     ****************************     |\n" );
  printf("\t|     ***Escolha uma das opções***     |\n" );
  printf("\t|     ****************************     |\n" );
  printf("\t|                                      |\n" );
  printf("\t|           [1] Criar Conta            |\n" );
  printf("\t|           [2] Entrar                 |\n" );
  printf("\t|           [3] Sair                   |\n" );
  printf("\t|______________________________________|\n" );


  scanf("%d", &operacao);
  system ("clear");

  switch (operacao){
    case 1:
   //Criando a conta e recebendo informações
            printf("___________________________________________\n" );
            printf("\nEntre com os dados abaixo\n");
            printf("\n|Digite seu nome(Por favor separe com '-'): ");
            scanf("%s", &nome);
            printf("\n|Digite seu numero de CPF: " );
            scanf("%li", &cpf);
            printf("\n|Digite uma senha(6 Digitos): " );
            scanf("%d", &senha);
            printf("\n____________________________________________\n" );
            system ("clear");
            printf("\n\t|=Conta criada com sucesso=|\n" );
            printf("\n____________________________________________\n" );

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
            printf("\n|Numero da conta: %d", conta);
            printf("\n|Saldo inicial = 0\n");
            printf("________________________________________\n" );

            FILE *pont_arq;
            pont_arq = fopen("dados.txt", "a");
            fprintf(pont_arq, "|----------------------------------------------------|\n" );
            fprintf(pont_arq, "\tProprietario: %s\n", nome);
            fprintf(pont_arq, "\tCPF: %li\n", cpf);
            fprintf(pont_arq, "\tConta: %d\n", conta);
            fprintf(pont_arq, "\tSaldo: %d\n", saldo_in);
            fprintf(pont_arq, "|----------------------------------------------------|\n" );
            fclose(pont_arq);

            FILE *pont_senha;
            pont_senha = fopen("passwords.txt", "a");
            fprintf(pont_senha, "%d\n", senha);
            fclose(pont_senha);


    //Usuario ja cadastrado
    case 2:
    //Todas as contas quando são logadas tem seu saldo alterado para 0 para melhor
    //entendimento no programa, porem nos arquivos permanentes tem todos os dados salvos.
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
              /*Teria varias maneiras de fazer isso, mas eu fiz assim para evitar
              alguns bugs e ficar melhor o entendimento*/

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
                   printf("\t|           [5] Sair                   |\n" );
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
                   if(opcao == 2 && saldo_in > 0){

                   printf("\t\n ______________________________________\n"  );
                   printf("|Digite o valor do saque: ");
                   scanf("%d", &saque);
                   saldo_in = saldo_in - saque;
                   if (saque <= saldo_in){
                      printf("=|Saque efetuado com sucesso|=\n" );
                   }
                   if (saque > saldo_in){
                     printf("Você não tem esse saldo para sacar, consulte seu saldo!\n" );
                   }


                   FILE *pont_extrato;
                   pont_extrato = fopen("extratos.txt", "a");
                   fprintf(pont_extrato, "|----------------------------------------|\n" );
                   fprintf(pont_extrato, "|No dia :%s As:%s|\n", __DATE__,__TIME__);
                   fprintf(pont_extrato, "|O CPF: %s Teve seu saldo alterado\n", id);
                   fprintf(pont_extrato, "|Novo saldo: %d\n", saldo_in);
                   fprintf(pont_extrato, "|----------------------------------------|\n" );
                   fclose(pont_extrato);

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

                     FILE *pont_extrato;
                     pont_extrato = fopen("extratos.txt", "a");
                     fprintf(pont_extrato, "|----------------------------------------|\n" );
                     fprintf(pont_extrato, "|No dia :%s As:%s|\n", __DATE__,__TIME__);
                     fprintf(pont_extrato, "|O CPF: %s Teve seu saldo alterado\n", id);
                     fprintf(pont_extrato, "|Novo saldo: %d\n", saldo_in);
                     fprintf(pont_extrato, "|----------------------------------------|\n" );
                     fclose(pont_extrato);
            //Gravando no arquivo
                     }
              //Tranferencia
                   if (opcao == 4){
                     printf("\t\n ______________________________________\n"  );
                     printf("\n|Digite o CPF destino: ");
                     scanf("%li", &cpf_des);
                     printf("\n|Digite a conta destino: " );
                     scanf("%d", &conta_des);
                     printf("\n|Valor da transferência: ");
                     scanf("%d", &valor_trans);

                     if (valor_trans < saldo_in){

                       printf("\n\t=|Tranferido com sucesso|=\n" );
                       saldo_in = saldo_in - valor_trans;

                       FILE *pont_extrato;
                       pont_extrato = fopen("extratos.txt", "a");
                       fprintf(pont_extrato, "|-------------------------------------------------|\n" );
                       fprintf(pont_extrato, "|No dia :%s As:%s|\n", __DATE__,__TIME__);
                       fprintf(pont_extrato, "|O CPF: %li e a conta: %d Recebeu um deposito!\n", cpf_des, conta_des);
                       fprintf(pont_extrato, "|Valor do deposito: %d\n", valor_trans);
                       fprintf(pont_extrato, "|-------------------------------------------------|\n" );
                       fclose(pont_extrato);

                       printf("\t\n ______________________________________\n"  );
                       printf("||=Extrato da tranferencia=||\n" );
                       printf("\n|CPF Recebido: %li", cpf_des);
                       printf("\n|Conta recebida: %d", conta_des);
                       printf("\n|Valor transferido: %d", valor_trans);
                       printf("\t\n ______________________________________\n"  );

                     }
                    if (valor_trans > saldo_in){
                       printf("\t\n ______________________________________\n"  );
                      printf("=|Saldo insulficiente, consulte seu saldo!!|=\n" );
                       printf("\t\n ______________________________________\n"  );
                    }

                   }
                   if (opcao = 5){
                     system ("clear");
                     break;
                   }

              //Voltando ao menu principal
                   printf("\n=|Deseja fazer outra operação?(Digite qualquer numero) ou '0' para sair|=\n" );
                   scanf("%d", &voltar1);
                   voltar = voltar1;

                   system ("clear");
              //Salvando o novo extrato bancario

            }while (voltar > 0);
          case 3:
            system ("clear");
            break;

    return 0;
}
}
