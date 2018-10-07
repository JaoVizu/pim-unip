#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//função limpar tela
void sistema()
{
    system("cls||clear");
}
int main()
{
    char cCaracter;
    char cvCadastroLogin[50];
    char cvCadastroSenha[07];
    char cvSenhaIgual[07];
    int iQtdCaracter;
    int iSenhaIgual = 0;
    //int iQtdErros=3;
    do
    {
        printf("\n\t\t\tCADASTRO GERENTE\n\nDigite o login: ");
        fflush(stdin); //Limpando o buffer do teclado
        scanf("%s", &cvCadastroLogin);
        printf("\nDigite a senha: ");
        iQtdCaracter = 0;
        do
        {
            //cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 6))
            {                                              //Analisa se o valor da variável c é imprimivel
                cvCadastroSenha[iQtdCaracter] = cCaracter; //Se for, armazena o caractere
                iQtdCaracter++;
                printf("*"); //imprime o * Anterisco
            }
            else if (cCaracter == 8 && iQtdCaracter)
            { //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
                cvCadastroSenha[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando o caractere digitado
            }
        } while (cCaracter != 13); //13 é o valor de ENTER na tabela ASCII
        cvCadastroSenha[iQtdCaracter] = '\0';

        printf("\nconfirmação da senha: ");
        iQtdCaracter = 0;
        do
        {
            //cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 6))
            { //Analisa se o valor de c é imprimível
                cvSenhaIgual[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                printf("*"); //Imprimindo apenas o asterisco *
            }
            else if (cCaracter == 8 && iQtdCaracter)
            {
                cvSenhaIgual[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
            }
        } while (cCaracter != 13); //13 é o valor de ENTER na tabela ASCII
        cvSenhaIgual[iQtdCaracter] = '\0';

        if (!strcmp(cvCadastroSenha, cvSenhaIgual))
        {
            //strcmp retorna 0 se as variáveis forem iguais. !strcmp é o mesmo que strcmp==0
            printf("\n\n\t\t\tCADASTRO EFETUADO COM SUCESSO...\n\n");
            iSenhaIgual = 1;
        }
        else
        {
            sistema();
            printf("\n\n\t\a\tSENHAS DIFERENTES - DIGITE NOVAMENTE...\n\n");
        }
    } while (iSenhaIgual != 1); //Enquanto b e d forem diferente de zero 0
    return 0;
}