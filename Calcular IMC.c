//Cadastrar algumas pessoas e pesquisar por cpf o seu IMC
//Grupo: Leonardo Henrique Martins Ferreira, Nara Marinho, Gabriel Farias
//Professor Ewerton 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Macros
#if !defined(true)
#define true 1
#endif

#if !defined(false)
#define false 1
#endif

#if !defined(MAX_PESSOAS)
#define MAX_PESSOAS 2 //Alterar numero de pessoas a ser cadastrado
#endif

typedef struct _pessoa_ //struct de informação
{
    char nome[100];
    float altura;
    float peso;
    char cpf[11] ;
    int sexo;
}Pessoa;
Pessoa pessoas[MAX_PESSOAS];

//funções globais
void resultado(float imc, int sexo);
float CalcularIMC(int index);
void CadastrarPessoa();
int PesquisarPessoa(char cpf[]);

int main(int argc, char const *argv[])
{
    char cpf[11];
    float imc;
    int menu;
    system("clear");
    printf("\n|=========MENU============|\n");
    printf("|[1] - Cadastrar pessoas  |\n");
    printf("|[0] - Sair               |\n");
    printf("|=========================|");
    scanf("%d", &menu);
    switch (menu)
    {
        case 1:
            //cadastrar pessoa menu
            system("clear");
            CadastrarPessoa();
            break;
        case 0:
            break;
            system("exit");
    }
    int opc = 1;
    
    while(opc){
        printf("\n|=========MENU============|\n");
        printf("|[1] - Pesquisar por CPF  |\n");
        printf("|[0] - sair               |\n");
        printf("|=========================|");
        scanf("%d", &opc);
        switch (opc)
        {
            case 1:
                //Pesquisar por CPF
                printf("\n|Digite seu CPF: ");
                scanf("%s", cpf);
                int index = PesquisarPessoa(cpf);
                if (index > -1) {
                    float imc = CalcularIMC(index);
                    resultado(imc, pessoas[index].sexo);
                }else
                {
                    printf("CPF não encontrado!!\n");
                }
                break;
            case 0:
                system("exit");
        }
        
    }
    return 0;
}
//Resultados IMC
void resultado(float imc, int sexo){
    if ((sexo == 0 && imc > 43.0) || (sexo == 1 && imc > 39.0)){
        printf("IMC: %.2f -> Obesidade Mórbida\n", imc);
    }else if ((sexo == 0 && (imc >= 30.0 && imc <= 39.9)) || (sexo == 1 && (imc >=29.0 && imc <= 38.9))) {
        printf("IMC: %.2f -> Obesidade Moderado\n", imc);
    }else if ((sexo == 0 && (imc >= 25.0 && imc <= 29.9)) || (sexo == 1 && (imc >=24.0 && imc <= 28.9))) {
        printf("IMC: %.2f -> Obesidade Leve\n", imc);
    }else if ((sexo == 0 && (imc >= 20.0 && imc <= 24.9)) || (sexo == 1 && (imc >=19.0 && imc <= 23.9))) {
        printf("IMC: %.2f -> Normal\n", imc);
    }else if ((sexo == 0 && imc < 20.0) || (sexo == 1 && imc < 19.0 )) {
        printf("IMC: %.2f -> Abaixo do Normal\n", imc);
    }
}
float CalcularIMC(int index){
    float imc = ((pessoas[index].peso) / (pessoas[index].altura * pessoas[index].altura));
}
void CadastrarPessoa(){
    for(size_t i = 0; i < MAX_PESSOAS; i++)
    {   
        printf("\n|Digite seu nome: ");
        scanf("%s", pessoas[i].nome);
        printf("\n|Digite sua altura: ");
        scanf("%f", &pessoas[i].altura);
        printf("\n|Digite seu peso: ");
        scanf("%f", &pessoas[i].peso);
        printf("\n|Digite seu CPF: ");
        scanf("%s", pessoas[i].cpf);
        printf("\n|Digite seu sexo(0 = M | 1 = F): ");
        scanf("%d", &pessoas[i].sexo);
        system("clear");
        printf("\n|=Pessoa cadastrada com sucesso!=|\n");
    }
}
int PesquisarPessoa(char cpf[]){
    for(size_t i = 0; i < MAX_PESSOAS; i++)
    {
        if (!strcmp(pessoas[i].cpf, cpf))
            return i;
    }
    return -1;
}