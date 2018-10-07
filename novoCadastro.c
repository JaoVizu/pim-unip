#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto
{
    char cvNome[500];
    char cvValidade[100];
    float fValor;
    int iCodigo;
    int iCodigoFornecedor;
    struct Produto *pProximo;
} Produto;

typedef struct fornecedor
{
    char cvNome[101];
    char cvNomeFantasia[101];
    char cvEndereco[101];
    char cvCnpj[20];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    int iCodigoProduto;
    struct Fornecedor *fProximo;
} Fornecedor;

typedef struct cliente
{
    char cvNomeCli[200];
    char cvCpf[15];
    char cvData_nascimento[101];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    char cvEndereco[101];
    struct Cliente *cProximo;
} Cliente;

typedef struct funcionario
{
    char cvNomeFunc[101];
    char cvCargo[101];
    char cvCpf[15];
    char cvData_nascimento[101];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    char cvEndereco[101];
    struct Funcionario *funProximo;
} Funcionario;

/* DECLARACAO DE STRUCTS */
Produto *pProdutoInicial = NULL;
Fornecedor *fFornecedorInicial = NULL;
Cliente *cClienteInicial = NULL;
Funcionario *fFuncionarioInicial = NULL;

/* DECLARACAO DE  FUNCOES */
void sair();
void defaultMessage();
void nullList();
void listarProdutos();
void removeProduto(int iCodigoProduto);
void listarFornecedor();
void listarCliente();
void listarFuncionario();
void flush_in();

/* DECLARACAO DE FUNCOES QUE RETORNAM VALOR */
int menuPrincipal();
int menu();
char escolhaRegistro();
int menuCadastro();
int cadastrarProduto();
int cadastrarFornecedor();
int cadastrarCliente();
int cadastrarFuncionario();


int main(){
    menu();
    return 0;
}

void sair(){
    printf("\nObrigado por utilizar o programa!!!\n");
}

void defaultMessage(){
    printf("\nPor favor, entre com uma opcao valida!\n");
}

void nullList(){
    printf("\nNao ha registros para serem listados!!!\n");
}

char escolhaRegistro(){
    char cEscolha;
    printf("Deseja cadastrar um novo registro?(s/n) \n");
    scanf(" %c", &cEscolha);
    return cEscolha;
}

int menuPrincipal()
{
    int iOp;
    printf("**Menu**\n\n");
    printf(" 1-> Cadastro\n");
    printf(" 2-> Caixa\n");
    printf(" 3-> Estoque\n");
    printf("\n Escolha a opcao desejada: ");
    scanf("%d", &iOp);
    return iOp;
}

int menu()
{
    int iOp;
    do
    {
        iOp = menuPrincipal();
        switch (iOp)
        {
        case 0:
            printf("Obrigado por utilizar o software!!\n");
            break;
        case 1:
            system("cls || clear");
            menuCadastro();
            break;
        case 2:
            printf("\n Iniciando Caixa...\n");
            break;
        case 3:
            printf("\n Iniciando Estoque...\n");
            break;
        default: defaultMessage(); break;
        }
    } while (iOp != 0);
}

int menuCadastro(){
    int iOp;

    do{
        printf("\n *** MENU CADASTRO ***");
        printf("\n0- sair");
        printf("\n1- Cadastrar Funcionario");
        printf("\n2- Cadastrar Cliente");
        printf("\n3- Cadastrar Produto");
        printf("\n4- Cadastrar Fornecedor");
        printf("\n5- Listar Funcionario");
        printf("\n6- Listar Clientes");        
        printf("\n7- Listar Produto");        
        printf("\n8- Listar Fornecedor");        
        printf("\n\nEntre com a opcao desejada: ");
        scanf("%d", &iOp);
        switch(iOp){
            case 0: break;
            case 1: cadastrarFuncionario(); break;
            case 2: cadastrarCliente(); break;
            case 3: cadastrarProduto(); break;
            case 4: cadastrarFornecedor(); break;
            case 5: listarFuncionario(); break;
            case 6: listarCliente(); break;
            case 7: listarProdutos(); break;
            case 8: listarFornecedor(); break;

            default: defaultMessage(); break;
        }
    }while(iOp != 0);
}

int cadastrarProduto(){
    printf("\n** Cadastro de produtos **\n");
    char cEscolha;
    do{
        Produto *pNovoProduto = (Produto*) malloc(sizeof(Produto));
        pNovoProduto->pProximo = NULL;

        printf("\nNome do produto: ");
        flush_in();
        fgets(pNovoProduto->cvNome, sizeof(pNovoProduto->cvNome), stdin);
        pNovoProduto->cvNome[strcspn(pNovoProduto->cvNome, "\n")] = '\0';
        printf("\nData de Validade: ");
        fgets(pNovoProduto->cvValidade, sizeof(pNovoProduto->cvValidade), stdin);
        pNovoProduto->cvValidade[strcspn(pNovoProduto->cvValidade, "\n")] = '\0';
        printf("\nValor do Produto: ");
        scanf("%f", &pNovoProduto->fValor);
        printf("\nCodigo do Produto: ");
        scanf("%d", &pNovoProduto->iCodigo);
        printf("\nCodigo do Fornecedor: ");
        scanf("%d", &pNovoProduto->iCodigoFornecedor);
        flush_in();

        if(pProdutoInicial == NULL){
            pProdutoInicial = pNovoProduto;
        }else{
            Produto *pAux = pProdutoInicial;
            while(pAux->pProximo != NULL){
                pAux = pAux->pProximo;
            }
            pAux->pProximo = pNovoProduto;
        }

        cEscolha = escolhaRegistro();
        system("cls || clear");
    }while(cEscolha != 'n');
}

void listarProdutos(){
    printf("\n*** Listando Produtos ***\n");
    printf("\n--------------------------------------------------------------------------------\n");
    if(pProdutoInicial == NULL){
         nullList();
    }else{
        Produto *pAux = pProdutoInicial;
        while(pAux != NULL){
            printf("\nNome: %s |\tValidade: %s", pAux->cvNome, pAux->cvValidade);
            printf("\nValor: %.2f |\tCodigo: %d |\tCodigo Fornecedor: %d", pAux->fValor, pAux->iCodigo, pAux->iCodigoFornecedor);
            printf("\n------------------------------------------------------------------------------\n");
            pAux = pAux->pProximo;
        }
    }
}

void removeProduto(int iCodigoProduto)
{
    printf("\nRemover produto");
    if (pProdutoInicial == NULL)
    {
        printf("\nA lista ja esta vazia!");
    }
    else
    {
        if (pProdutoInicial->pProximo == NULL)
        {
            pProdutoInicial = NULL;
        }
        else
        {
            Produto *pAux = pProdutoInicial;
            pProdutoInicial = pProdutoInicial->pProximo;
            free(pAux);
            pAux = NULL;
        }
    }
}

int cadastrarFornecedor(){
    char cEscolha;
    printf("\nCadastro de Fornecedor");
    do{
        Fornecedor *novoFornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
        novoFornecedor->fProximo = NULL;

        printf("\nNome Fornecedor: ");
        flush_in();
        fgets(novoFornecedor->cvNome, sizeof(novoFornecedor->cvNome), stdin);
        novoFornecedor->cvNome[strcspn(novoFornecedor->cvNome, "\n")] = '\0';
        printf("\nNome Fantasia: ");
        fgets(novoFornecedor->cvNomeFantasia, sizeof(novoFornecedor->cvNomeFantasia), stdin);
        novoFornecedor->cvNomeFantasia[strcspn(novoFornecedor->cvNomeFantasia, "\n")] = '\0';
        printf("\nEndereco: ");
        fgets(novoFornecedor->cvEndereco, sizeof(novoFornecedor->cvEndereco), stdin);
        novoFornecedor->cvEndereco[strcspn(novoFornecedor->cvEndereco, "\n")] = '\0';
        printf("\nCNPJ: ");
        fgets(novoFornecedor->cvCnpj, sizeof(novoFornecedor->cvCnpj), stdin);
        novoFornecedor->cvCnpj[strcspn(novoFornecedor->cvCnpj, "\n")] = '\0';
        printf("\nEmail: ");
        fgets(novoFornecedor->cvEmail, sizeof(novoFornecedor->cvNome), stdin);
        novoFornecedor->cvEmail[strcspn(novoFornecedor->cvEmail, "\n")] = '\0';
        printf("\nTelefone: ");
        fgets(novoFornecedor->cvTelefone, sizeof(novoFornecedor->cvTelefone), stdin);
        novoFornecedor->cvTelefone[strcspn(novoFornecedor->cvTelefone, "\n")] = '\0';
        printf("\nCelular: ");
        fgets(novoFornecedor->cvCelular, sizeof(novoFornecedor->cvCelular), stdin);
        novoFornecedor->cvCelular[strcspn(novoFornecedor->cvCelular, "\n")] = '\0';
        printf("\nCodigo Produto: ");
        scanf("%d", &novoFornecedor->iCodigoProduto);

        if(fFornecedorInicial == NULL) {
            fFornecedorInicial = novoFornecedor;
        }else{
            Fornecedor *fAux = fFornecedorInicial;
            while(fAux->fProximo != NULL){
                fAux = fAux->fProximo;
            }
            fAux->fProximo = novoFornecedor;
        }

        cEscolha = escolhaRegistro();
        system("cls || clear");
    }while(cEscolha != 'n');
}

void listarFornecedor(){
    printf("\nListando Fornecedores");
    printf("\n--------------------------------------------------------------------------------\n");
    if(fFornecedorInicial == NULL){
        nullList();
    }else{
        Fornecedor *fAux = fFornecedorInicial;
        while(fAux != NULL){
            printf("\nNome: %s |\tNome Fantasia: %s", fAux->cvNome, fAux->cvNomeFantasia);
            printf("\nEndereco: %s |\tCNPJ: %s", fAux->cvEndereco, fAux->cvCnpj);
            printf("\nEmail: %s |\tTelefone: %s ",  fAux->cvEmail, fAux->cvTelefone);
            printf("\nCelular: %s |\tCodigo Produto: %d", fAux->cvCelular, fAux->iCodigoProduto);
            printf("\n------------------------------------------------------------------------------\n");
            fAux = fAux->fProximo;
        }
    }
}

int cadastrarCliente(){
    char cEscolha;
    printf("\nCadastro de Cliente\n");
    do{
        Cliente *cNovocliente = (Cliente*) malloc(sizeof(Cliente));
        cNovocliente->cProximo = NULL;

        flush_in();
        printf("\nNome: ");
        fgets(cNovocliente->cvNomeCli, sizeof(cNovocliente->cvNomeCli), stdin);
        cNovocliente->cvNomeCli[strcspn(cNovocliente->cvNomeCli, "\n")] = '\0';
        printf("\nCPF: ");
        fgets(cNovocliente->cvCpf, sizeof(cNovocliente->cvCpf), stdin);
        cNovocliente->cvCpf[strcspn(cNovocliente->cvCpf, "\n")] = '\0';
        printf("\nData de Nascimento: ");
        fgets(cNovocliente->cvData_nascimento, sizeof(cNovocliente->cvData_nascimento), stdin);
        cNovocliente->cvData_nascimento[strcspn(cNovocliente->cvData_nascimento, "\n")] = '\0';
        printf("\nEmail: ");
        fgets(cNovocliente->cvEmail, sizeof(cNovocliente->cvEmail), stdin);
        cNovocliente->cvEmail[strcspn(cNovocliente->cvEmail, "\n")] = '\0';
        printf("\nTelefone: ");
        fgets(cNovocliente->cvTelefone, sizeof(cNovocliente->cvTelefone), stdin);
        cNovocliente->cvTelefone[strcspn(cNovocliente->cvTelefone, "\n")] = '\0';
        printf("\nCelular: ");
        fgets(cNovocliente->cvCelular, sizeof(cNovocliente->cvCelular), stdin);
        cNovocliente->cvCelular[strcspn(cNovocliente->cvCelular, "\n")] = '\0';
        printf("\nEndereco: ");
        fgets(cNovocliente->cvEndereco, sizeof(cNovocliente->cvEndereco), stdin);
        cNovocliente->cvEndereco[strcspn(cNovocliente->cvEndereco, "\n")] = '\0';

        if(cClienteInicial == NULL){
            cClienteInicial = cNovocliente;
        }else{
            Cliente *cAux = cClienteInicial;
            while(cAux->cProximo != NULL){
                cAux = cAux->cProximo;
            }
            cAux->cProximo = cNovocliente;
        }
        cEscolha = escolhaRegistro();
        system("cls || clear");
    }while(cEscolha != 'n');
}

void listarCliente(){
    printf("\n\t\t\tListando Clientes:\n\n");
    printf("\n------------------------------------------------------------------------------\n");
    if(cClienteInicial == NULL){
        nullList();
    }else{
        Cliente *cAux = cClienteInicial;
        while(cAux != NULL){
            printf("\nNome: %s |\tCPF: %s |\tData Nascimento: %s", cAux->cvNomeCli, cAux->cvCpf, cAux->cvData_nascimento);
            printf("\nEmail: %s |\tTelefone: %s", cAux->cvEmail, cAux->cvTelefone);
            printf("\nCelular: %s |\tEndereco: %s", cAux->cvCelular, cAux->cvEndereco);
            printf("\n------------------------------------------------------------------------------\n");
            cAux = cAux->cProximo;
        }

    }
}

int cadastrarFuncionario(){
    char cEscolha;
    printf("\n\t\t\tCadastro de Funcionario\n");
    do{
        Funcionario *fNovoFuncionario = (Funcionario *) malloc(sizeof(Funcionario));
        fNovoFuncionario->funProximo = NULL;
        
        flush_in();
        printf("\nNome: ");
        fgets(fNovoFuncionario->cvNomeFunc, sizeof(fNovoFuncionario->cvNomeFunc), stdin);
        fNovoFuncionario->cvNomeFunc[strcspn(fNovoFuncionario->cvNomeFunc, "\n")] = '\0';
        printf("\nCargo: ");
        fgets(fNovoFuncionario->cvCargo, sizeof(fNovoFuncionario->cvCargo), stdin);
        fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
        printf("\nCPF: ");
        fgets(fNovoFuncionario->cvCpf, sizeof(fNovoFuncionario->cvCpf), stdin);
        fNovoFuncionario->cvCpf[strcspn(fNovoFuncionario->cvCpf, "\n")] = '\0';
        printf("\nData de Nascimento: ");
        fgets(fNovoFuncionario->cvData_nascimento, sizeof(fNovoFuncionario->cvData_nascimento), stdin);
        fNovoFuncionario->cvData_nascimento[strcspn(fNovoFuncionario->cvData_nascimento, "\n")] = '\0';
        printf("\nEmail: ");
        fgets(fNovoFuncionario->cvEmail, sizeof(fNovoFuncionario->cvEmail), stdin);
        fNovoFuncionario->cvEmail[strcspn(fNovoFuncionario->cvEmail, "\n")] = '\0';
        printf("\nTelefone: ");
        fgets(fNovoFuncionario->cvTelefone, sizeof(fNovoFuncionario->cvTelefone), stdin);
        fNovoFuncionario->cvTelefone[strcspn(fNovoFuncionario->cvTelefone, "\n")] = '\0';
        printf("\nCelular: ");
        fgets(fNovoFuncionario->cvCelular, sizeof(fNovoFuncionario->cvCelular), stdin);
        fNovoFuncionario->cvCelular[strcspn(fNovoFuncionario->cvCelular, "\n")] = '\0';
        printf("\nEndereco: ");
        fgets(fNovoFuncionario->cvEndereco, sizeof(fNovoFuncionario->cvEndereco), stdin);
        fNovoFuncionario->cvEndereco[strcspn(fNovoFuncionario->cvEndereco, "\n")] = '\0';

        if(fFuncionarioInicial == NULL) {
            fFuncionarioInicial = fNovoFuncionario;
        }else{
            Funcionario *fAux = fFuncionarioInicial;
            while(fAux->funProximo != NULL){
                fAux = fAux->funProximo;
            }
            fAux->funProximo = fNovoFuncionario;
        }

        cEscolha = escolhaRegistro();
        system("cls || clear");
    }while(cEscolha != 'n');
}

void listarFuncionario(){
    printf("\n\t\t\t Listando Funcionarios\n");
    printf("\n------------------------------------------------------------------------------\n");
    if(fFuncionarioInicial == NULL){
        nullList();
    }else{
        Funcionario *fAux = fFuncionarioInicial;
        while(fAux != NULL){
            printf("\nNome: %s |\tCargo: %s", fAux->cvNomeFunc, fAux->cvCargo);
            printf("\nCPF: %s |\tData de Nascimento: %s", fAux->cvCpf, fAux->cvData_nascimento);
            printf("\nEmail: %s |\tTelefone: %s", fAux->cvEmail, fAux->cvTelefone);
            printf("\nCelular: %s |\tEndereco: %s", fAux->cvCelular, fAux->cvEndereco);
            printf("\n------------------------------------------------------------------------------\n");
            fAux = fAux->funProximo;
        }
    }
}

//Limpa buffer do teclado
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}
