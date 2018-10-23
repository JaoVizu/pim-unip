#include <stdio.h>
#include <stdlib.h>
typedef struct lista1 {
    int numero;
    float valor;
    struct Lista1 *proximo;
} Lista1;

typedef struct Venda{
    int numeroVenda;
    float valorTotal;
    struct Venda *nextVenda;
}Venda;

typedef struct itemVenda{
    int numeroItem;
    float valorItem;
    struct itemVenda *nextItem;
}itemVenda;

Lista1 *inicioL1 = NULL;
Venda *vendaIni = NULL;
itemVenda *itemVendaIni = NULL;


void addL1();
void listar();
void realizaVenda();
void listaItemVenda();
void listarVenda();

int main(){

    int escolha;
    do{
        printf("MENU \n\n");
        printf(" 0 - exit\n");
        printf(" 1 - add L1\n");
        printf(" 2 - realizar venda\n");
        printf(" 3 - listar item\n");
        printf(" 4 - listar venda\n");
        printf("\nEntre com uma opcao: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 0: break;
            case 1:
                addL1();
                break;
            case 2:
                realizaVenda();
                break;
            case 3:
                listaItemVenda();
                break;
            case 4:
                listarVenda();
                break;
        }
        
    }while(escolha != 0);
    listar();

    return 0;
}

void addL1(){

    Lista1 *novoEl = (Lista1*) malloc(sizeof(Lista1));
    novoEl->proximo = NULL;

    printf("Entre com o numero da lista: ");
    scanf("%d", &novoEl->numero);
    printf("Entre com o valor do numero: ");
    scanf("%f", &novoEl->valor);

    if(inicioL1 == NULL){
        inicioL1 = novoEl;
    }else{
        Lista1 *aux = inicioL1;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novoEl;
    }

}


void realizaVenda(){

    int numero;
    float valor;
    char escolha;
   
    do{

        
        do{
            itemVenda *newItem = (itemVenda *)malloc(sizeof(itemVenda));
            newItem->nextItem = NULL;
            printf("Entre com o numero que deseja vender: ");
            scanf("%d", &numero);
            //declarando struct
            Lista1 *auxl1 = inicioL1;

            while(auxl1 != NULL){
                if(auxl1->numero == numero){
                    newItem->numeroItem = auxl1->numero;
                    newItem->valorItem = auxl1->valor;
                    if (itemVendaIni == NULL)
                    {
                        itemVendaIni = newItem;
                    }
                    else
                    {
                        itemVenda *auxItem = itemVendaIni;
                        while(auxItem->nextItem != NULL){
                            auxItem = auxItem->nextItem;
                        }
                        auxItem->nextItem = newItem;
                    }
                    break;
                }
                auxl1 = auxl1->proximo;
               
            }
            printf("Adicionar mais um numero? ");
            scanf(" %c", &escolha);
        }while(escolha != 'n');
        
        printf("caiu aqui");
        Venda *newVenda = (Venda *)malloc(sizeof(Venda));
        newVenda->nextVenda = NULL;
        //parte da venda
        itemVenda *auxItem2 = itemVendaIni;
        while(auxItem2 != NULL){
            newVenda->numeroVenda = auxItem2->numeroItem ;
            newVenda->valorTotal += auxItem2->valorItem;
            auxItem2 = auxItem2->nextItem;
        }
        
        if(vendaIni == NULL){
            printf("Venda ini NULA\n");
            vendaIni = newVenda;
            //liberar e receber nulo no itemVenda, para ele nao somar valores anteriores
            free(auxItem2);
            itemVendaIni = NULL;
        }else{
            printf("Venda ini NAAAO NULA\n");

            Venda *auxVenda = vendaIni;
            while(auxVenda->nextVenda != NULL){
                auxVenda = auxVenda->nextVenda;
            }
            auxVenda->nextVenda = newVenda;
            //liberar e receber nulo no itemVenda, para ele nao somar valores anteriores
            free(auxItem2);
            itemVendaIni = NULL;
        }
        printf("Valor new venda: %.2f\n", newVenda->valorTotal);
        printf("Deseja realizar mais uma venda?");
        scanf(" %c", &escolha);
    }while(escolha != 'n');

}


void listar(){

    Lista1 *aux = inicioL1;

    while(aux != NULL){
        printf("Numero : %d\n", aux->numero);
        printf("Valor : %.2f\n", aux->valor);
        aux = aux->proximo;
    }

}

void listaItemVenda(){

    itemVenda *aux = itemVendaIni;
    while(aux != NULL){
        printf("Numero: %d\tValor: %.2f\n", aux->numeroItem, aux->valorItem);
        aux = aux->nextItem;
    }
}

void listarVenda(){
    Venda *auxVenda = vendaIni;
   
    while (auxVenda != NULL)
    {
        printf("Numero Venda: %d\tValor da venda: %.2f\n", auxVenda->numeroVenda, auxVenda->valorTotal);
        auxVenda = auxVenda->nextVenda;
    }
}
