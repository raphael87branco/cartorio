#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
    char CPF[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite seu CPF: ");
    scanf("%s", CPF);

    strcpy(arquivo, CPF);
    strcat(arquivo, ".txt");

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "%s", CPF);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, ",%s", nome);
    fclose(file);

    printf("Digite o Sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, ",%s", sobrenome);
    fclose(file);

    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, ",%s", cargo);
    fclose(file);

    getchar();
}

int consultar()
{
    setlocale(LC_ALL, "PORTUGUESE");

    char CPF[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", CPF);

    strcat(CPF, ".txt");

    FILE *file;
    file = fopen(CPF, "r");

    if (file == NULL)
    {
        printf("Arquivo nao localizado.\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);

    system("clear");
}

int deletar()
{
    char CPF[40];

    printf("Digite o CPF a ser deletado");
    scanf("%s", CPF);

    remove(CPF);

    FILE *file;
    file = fopen(CPF, "r");

    if(file == NULL)
    {
        PRINTF("Usuario nao encontrad!o");
        system(clear);
}

int main()
{
    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco == 1;)
    {
        system("clear");

        setlocale(LC_ALL, "PORTUGUESE");

        printf("### Casa dos Brancos ###\n\n");
        printf("Escolha a opcao desejada do menu:\n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        system("clear");

        switch (opcao)
        {
        case 1:
            registro();
            break;

        case 2:
            consultar();
            break;

        case 3:
            deletar();
            break;

        case 4:
        printf("Ate Breve");
        return 0;
        break;

        default:
            printf("Opcao nao disponivel.\n");
            system("clear");
            break;
        }
    }
}
