#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//__fpurge(stdin); p linux

typedef struct Aluno
{
    char nome[201];
    char ra[11];
    struct Aluno *proximo;
} Aluno;

Aluno *inicio = NULL;

int menu();
void adicionar();
void listar();
void sair();
void pesquisar();
void addP();
void remover();
int removeUltimo();
int removeQualquer();

int main()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 0:
            sair();
            break;
        case 1:
            adicionar();
            break;
        case 2:
            listar();
            break;
        case 3:
            pesquisar();
            break;
        case 4:
            addP();
            break;
        case 5:
            remover();
            break;
        case 6:
            removeUltimo();
            break;
        case 7: 
            removeQualquer();
            break;
        }
    } while (op != 0);
    return 0;
}
int menu()
{
    int op;
    do
    {
        printf("\nMenu\n");
        printf("\n0 - Sair");
        printf("\n1 - Adicionar");
        printf("\n2 - Listar");
        printf("\n3 - Pesquisar");
        printf("\n4 - Adicionar comeco");
        printf("\n5 - Remover");
        printf("\n6 - Remover ultimo item");
        printf("\n7 - Remover qualquer item");
        printf("\nEntre com a opcao desejada: ");
        scanf("%d", &op);
        if (op < 0 || op > 7)
        {
            printf("\n\nOpcao invalida");
        }
    } while (op < 0 || op > 7);
    return op;
}


void addP()
{
    Aluno *no = (Aluno *)malloc(sizeof(Aluno));
    no->proximo = NULL;

    printf("\nAdicionar\n");
    __fpurge(stdin);
    printf("\nEntre com o nome: ");
    fgets(no->nome, sizeof(no->nome), stdin);
    no->nome[strcspn(no->nome, "\n")] = '\0';

    __fpurge(stdin);
    printf("\nEntre com o ra: ");
    fgets(no->ra, sizeof(no->ra), stdin);

    if (inicio == NULL)
    {
        inicio = no;
    }
    else
    {
        //seems like a pilha
        no->proximo = inicio;
        inicio = no;
    }
}

void adicionar()
{
    Aluno *no = (Aluno *)malloc(sizeof(Aluno));
    no->proximo = NULL;

    printf("\nAdicionar\n");
    __fpurge(stdin);
    printf("\nEntre com o nome: ");
    fgets(no->nome, sizeof(no->nome), stdin);
    no->nome[strcspn(no->nome, "\n")] = '\0';

    __fpurge(stdin);
    printf("\nEntre com o ra: ");
    fgets(no->ra, sizeof(no->ra), stdin);

    if (inicio == NULL)
    {
        inicio = no;
    }
    else
    {
        Aluno *aux = inicio;
        //para no ultimo elemento da lista
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
}
void listar()
{
    printf("\nListar\n");

    if (inicio == NULL)
    {
        printf("Nao ha alunos para serem listados!!\n");
    }
    else
    {
        Aluno *aux = inicio;
        while (aux != NULL)
        {
            printf("Nome: %s\t RA: %s\n", aux->nome, aux->ra);
            aux = aux->proximo;
        }
    }
}

void sair()
{
    printf("\nBye");
}

void remover()
{
    Aluno *aux = inicio;
    if(inicio->proximo == NULL){
        free(inicio);
        inicio = NULL;
    }else{
        aux = aux->proximo;
        free(inicio);
        inicio = NULL;
        inicio = aux;
    }
   
    //printf("%s\n", inicio->nome);
}

int removeUltimo(){
    Aluno *aux = inicio;
    Aluno *anterior;
    if(inicio == NULL) return 0; // se inicio for nulo nao faz nada
    if(inicio->proximo == NULL){
        free(inicio);
        inicio = NULL;
    }else{
        while(aux->proximo != NULL){
            anterior = aux;
            aux = aux->proximo;
        }
        free(aux);
        aux = NULL;
        anterior->proximo = NULL;
        //printf("%s\n", anterior->nome);
    }
}

int removeQualquer(){
    Aluno *aux = inicio;
    Aluno *anterior;
    char nomeP[201];
    __fpurge(stdin);
    printf("Digite o nome a ser excluido: ");
    fgets(nomeP, sizeof(nomeP), stdin);
    nomeP[strcspn(nomeP, "\n")] = '\0';
    printf("%s\n", nomeP);

    if(inicio == NULL) return 0; //se inicio for nulo nao faz nada
    if(inicio->proximo == NULL){
        free(inicio);
        inicio = NULL;
    }else{
        while(aux->proximo != NULL){
            anterior = aux;
            aux = aux->proximo;
            if(!strcmp(aux->nome, nomeP)){
                anterior->proximo = aux->proximo;
                free(aux);
            }
            
        }
    }

}

void pesquisar()
{
    Aluno *aux = inicio;
    char nome[201];
    printf("\nPesquisar\n");
    __fpurge(stdin);
    printf("\nEntre com o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    int qtd = 0;
    while (aux != NULL)
    {
        if (!strcmp(aux->nome, nome))
        {
            printf("Aluno encontrado!!\nnome: %s\tra: %s\n", aux->nome, aux->ra);
            qtd++;
           
        }
        aux = aux->proximo;
    }
    if(qtd == 0){
        printf("Aluno nao encontrado!!\n");
    }
    
}
