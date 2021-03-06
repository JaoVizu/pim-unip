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

/**
 * 
 * AS FUNCOES DE REMOVER ESTAO REMOVENDO SEMPRE O PRIMEIRO ELEMENTO DA LISTA
 * ACREDITO QUE TEREI QUE ESPERAR PARA VER LISTA DUPLAMENTE ENCADEADA PARA REMOVER
 * DE ACORDO COM O CODIGO OU NOME
 * 
*/

/* DECLARACAO DE  FUNCOES */
void sair();
void defaultMessage();
void editMessage(char cvFunction[]);
void nullList();
void nullDelete();
void listarProdutos();
void removeProduto();
void listarFornecedor();
void alteraFornecedor();
void removeFornecedor();
void listarCliente();
void alteraCliente();
void removeCliente();
void listarFuncionario();
void alteraFuncionario();
void removeFuncionario();
void flush_in();
//void CadastroLogin(char cvCadastroLogin[], char cvCadastroSenha[]);
//void VerificarLogin();
void tela(char tela[]);

/* DECLARACAO DE FUNCOES QUE RETORNAM VALOR */
int menuPrincipal();
int menu();
int menuListar();
char escolhaRegistro();
int menuCadastro();
int cadastrarProduto();
int alteraProduto();
int cadastrarFornecedor();
int cadastrarCliente();
int cadastrarFuncionario();

int main()
{
    int x = 0;
    char login[20], senha[07];
    /*if (!x)
    {
        char *t = "SEJA BEM VINDO ADMINISTRADOR, CADASTRE SEU LOGIN!!";
        tela(t);
        CadastroLogin(login, senha);
        x = 1;
    }
    else
    {
        menu();
    }*/
    menu();
    return 0;
}

void sair()
{
    printf("\nObrigado por utilizar o programa!!!\n");
}

void defaultMessage()
{
    printf("\nPor favor, entre com uma opcao valida!\n");
}

void editMessage(char cvFunction[])
{
    printf("\nEntre com o nome do %s a ser alterado: ", cvFunction);
}

void nullList()
{
    printf("\nNao ha registros para serem listados!!!\n");
}

void nullDelete()
{
    printf("\nNao ha registros para serem removidos!!\n");
}

char escolhaRegistro()
{
    char cEscolha;
    printf("Deseja cadastrar um novo registro?(s/n) \n");
    scanf(" %c", &cEscolha);
    return cEscolha;
}

int menuPrincipal()
{
    int iOp;
    printf("\n\t\t\tMenu\n");
    printf(" 1- Cadastro Funcionario\n");
    printf(" 2- Caixa\n");
    printf(" 3- Estoque\n");
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
        default:
            defaultMessage();
            break;
        }
    } while (iOp != 0);
}

int menuCadastro()
{
    int iOp;
    do
    {
        printf("\n\t\t\tMENU CADASTRO\n");
        printf("\n0- sair");
        printf("\n1- Cadastrar Funcionario");
        printf("\n2- Cadastrar Cliente");
        printf("\n3- Cadastrar Produto");
        printf("\n4- Cadastrar Fornecedor");
        printf("\n5 - Listar");
        printf("\n6 - Alterar");
        printf("\n7 - excluir");
        printf("\n\nEntre com a opcao desejada: ");
        scanf("%d", &iOp);
        switch (iOp)
        {
        case 0:
            break;
        case 1:
            cadastrarFuncionario();
            break;
        case 2:
            cadastrarCliente();
            break;
        case 3:
            cadastrarProduto();
            break;
        case 4:
            cadastrarFornecedor();
            break;
        case 5:
            menuListar();
            break;
        case 6:
            menuAlterar();
            break;
        case 7:
            removeProduto();
            break;
        default:
            defaultMessage();
            break;
        }
    } while (iOp != 0);
}

int menuListar()
{
    system("cls || clear");
    int iOp;
    do
    {
        printf("\n\t\t\tListar\n");
        printf("\n0 - Sair");
        printf("\n1- Listar Funcionario");
        printf("\n2- Listar Clientes");
        printf("\n3- Listar Produto");
        printf("\n4- Listar Fornecedor");
        printf("\nEntre com a opcao desejada: ");
        scanf("%d", &iOp);
        switch (iOp)
        {
            case 0:
                system("cls || clear");
                break;
            case 1:
                listarFuncionario();
                break;
            case 2:
                listarCliente();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                listarFornecedor();
                break;
            default:
                defaultMessage();
                break;
        }
    } while (iOp != 0);
}

int menuAlterar(){
    system("cls || clear");
    int iOp;
    do{
        printf("\n\t\t\Alterar\n");
        printf("\n0 - Sair");
        printf("\n1- Alterar Funcionario");
        printf("\n2- Alterar Clientes");
        printf("\n3- Alterar Produto");
        printf("\n4- Alterar Fornecedor");
        printf("\nEntre com a opcao desejada: ");
        scanf("%d", &iOp);
        switch (iOp)
        {
            case 0:
                menuCadastro();
                break;
            case 1:
                alteraFuncionario();
                break;
            case 2:
                alteraCliente();
                break;
            case 3:
                alteraProduto();
                break;
            case 4:
                alteraFornecedor();
                break;
        
            default:
                defaultMessage();
                break;
        }

    }while(iOp < 0 || iOp > 3);
}

void tela(char tela[])
{
    printf("================================================================================================================================================================================================================================================");
    printf("\t2vjmig\n\n");
    printf("\t\t\t\t\t%s\n", tela);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tiMerc.vs2018\n");
    printf("================================================================================================================================================================================================================================================\n");
}

/*void CadastroLogin(char cvCadastroLogin[], char cvCadastroSenha[])
{
    char cCaracter;
    char cvSenhaIgual[07];
    int iQtdCaracter;
    int iSenhaIgual = 0;
    do
    {
        printf("\nDigite o login: ");
        fflush(stdin); //Limpando o buffer do teclado
        gets(cvCadastroLogin);
        printf("\nDigite a senha: ");
        iQtdCaracter = 0;
        do
        {
            cCaracter = getch();
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
            cCaracter = getch();
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
            system("cls || clear");
            menu();
        }
        else
        {
            system("cls||clear");
            printf("\n\n\t\a\tSENHAS DIFERENTES - DIGITE NOVAMENTE...\n\n");
        }
    } while (iSenhaIgual != 1); //Enquanto b e d forem diferente de zero 0
}

void VerificarLogin(char cvCadastroLogin[], char cvCadastroSenha[])
{
    char cCaracter;
    char cvAcessoLogin[50];
    char cvAcessoSenha[07];
    int iQtdCaracter;
    int iSenhaIgual;
    do
    {
        printf("\nEntre com o login: ");
        fflush(stdin); //Limpando o buffer do teclado
        gets(cvAcessoLogin);
        printf("\nEntre com a senha: ");
        iQtdCaracter = 0;
        do
        {
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 6))
            { //Analisa se o valor de c é imprimível
                cvAcessoSenha[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                printf("*"); //Imprimindo apenas o asterisco *
            }
            else if (cCaracter == 8 && iQtdCaracter)
            {
                cvAcessoSenha[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
            }
        } while (cCaracter != 13); //13 é o valor de ENTER na tabela ASCII
        cvAcessoSenha[iQtdCaracter] = '\0';

        if (!strcmp(cvCadastroLogin, cvAcessoLogin) && !strcmp(cvCadastroSenha, cvAcessoSenha))
        {
            //strcmp retorna 0 se as variáveis forem iguais. !strcmp é o mesmo que strcmp==0
            printf("\n\n\t\t\tLOGADO COM SUCESSO...\n\n");
            iSenhaIgual = 1;
            menu();
        }
        else
        {
            system("cls || clear");
            printf("\n\n\t\a\tSENHA ou LOGIN INVALIDO - TENTE NOVAMENTE...\n\n");
        }
    } while (iSenhaIgual != 1);
}*/

int cadastrarProduto()
{
    system("cls || clear");
    printf("\n\t\t\tCadastro de produtos\n");
    char cEscolha;
    do
    {
        Produto *pNovoProduto = (Produto *)malloc(sizeof(Produto));
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

        if (pProdutoInicial == NULL)
        {
            pProdutoInicial = pNovoProduto;
        }
        else
        {
            Produto *pAux = pProdutoInicial;
            while (pAux->pProximo != NULL)
            {
                pAux = pAux->pProximo;
            }
            pAux->pProximo = pNovoProduto;
        }

        cEscolha = escolhaRegistro();
        system("cls || clear");
    } while (cEscolha != 'n');
}

int alteraProduto()
{
    Produto *pAux = pProdutoInicial;
    int iNaoEncontrado = 0;
    char cvBNome[201];
    flush_in();
    printf("\nEntre com o nome do produto a ser alterado: ");
    fgets(cvBNome, sizeof(cvBNome), stdin);
    cvBNome[strcspn(cvBNome, "\n")] = '\0';
    while (pAux != NULL)
    {
        if(!strcmp(pAux->cvNome, cvBNome)){
            flush_in();
            printf("\nNome do produto: ");
            fgets(pAux->cvNome, sizeof(pAux->cvNome), stdin);
            pAux->cvNome[strcspn(pAux->cvNome, "\n")] = '\0';
            strcpy(pAux->cvNome, pAux->cvNome);
            printf("\nData de Validade: ");
            fgets(pAux->cvValidade, sizeof(pAux->cvValidade), stdin);
            pAux->cvValidade[strcspn(pAux->cvValidade, "\n")] = '\0';
            strcpy(pAux->cvValidade, pAux->cvValidade);
            printf("\nValor do Produto: ");
            scanf("%f", &pAux->fValor);
            pAux->fValor = pAux->fValor;
            printf("\nCodigo do Produto: ");
            scanf("%d", &pAux->iCodigo);
            pAux->iCodigo = pAux->iCodigo;
            printf("\nCodigo do Fornecedor: ");
            scanf("%d", &pAux->iCodigoFornecedor);
            pAux->iCodigoFornecedor = pAux->iCodigoFornecedor;
            iNaoEncontrado++;
            break;
        }
        pAux = pAux->pProximo;
    }
    if(iNaoEncontrado == 0){
        nullList();
    }
    
}

void listarProdutos()
{
    system("cls || clear");
    printf("\n\t\t\tListando Produtos\n");
    printf("\n--------------------------------------------------------------------------------\n");
    if (pProdutoInicial == NULL)
    {
        nullList();
    }
    else
    {
        Produto *pAux = pProdutoInicial;
        while (pAux != NULL)
        {
            printf("\nNome: %s |\tValidade: %s", pAux->cvNome, pAux->cvValidade);
            printf("\nValor: %.2f |\tCodigo: %d |\tCodigo Fornecedor: %d", pAux->fValor, pAux->iCodigo, pAux->iCodigoFornecedor);
            printf("\n------------------------------------------------------------------------------\n");
            pAux = pAux->pProximo;
        }
    }
}

void removeProduto()
{
    printf("\nRemover produto");
    if (pProdutoInicial == NULL)
    {
        printf("\nA lista ja esta vazia!");
    }
    else
    {
        Produto *pAux = pProdutoInicial;
        Produto *pPrev;
        char cvExNome[201];
        flush_in();
        printf("Entre com o nome do produto a ser **REMOVIDO**");
        fgets(cvExNome, sizeof(cvExNome), stdin);
        cvExNome[strcspn(cvExNome, "\n")] = '\0';
    
        while(pAux != NULL){
            pPrev = pAux;
            pAux = pAux->pProximo; 
            if(!strcmp(pAux->cvNome, cvExNome)){
                printf("da pra deletar\n");
                pPrev->pProximo = pAux->pProximo;
                free(pAux);
                return 1;
            }
        }

    }
}

int cadastrarFornecedor()
{
    system("cls || clear");
    char cEscolha;
    printf("\n\t\t\tCadastro de Fornecedor\n");
    do
    {
        Fornecedor *novoFornecedor = (Fornecedor *)malloc(sizeof(Fornecedor));
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

        if (fFornecedorInicial == NULL)
        {
            fFornecedorInicial = novoFornecedor;
        }
        else
        {
            Fornecedor *fAux = fFornecedorInicial;
            while (fAux->fProximo != NULL)
            {
                fAux = fAux->fProximo;
            }
            fAux->fProximo = novoFornecedor;
        }

        cEscolha = escolhaRegistro();
        system("cls || clear");
    } while (cEscolha != 'n');
}

void alteraFornecedor()
{

    Fornecedor *fAux = fFornecedorInicial;
    char cvExNome[201];
    flush_in();
    editMessage("fornecedor");
    fgets(cvExNome, sizeof(cvExNome), stdin);
    cvExNome[strcspn(cvExNome, "\n")] = '\0';
    int iNaoEncontrado = 0;
    while (fAux != NULL)
    {
        if (!strcmp(fAux->cvNome, cvExNome) || !strcmp(fAux->cvNomeFantasia, cvExNome))
        {
            flush_in();
            printf("\nNome do Fornecedor: ");
            fgets(fAux->cvNome, sizeof(fAux->cvNome), stdin);
            fAux->cvNome[strcspn(fAux->cvNome, "\n")] = '\0';
            printf("\nNome Fantasia: ");
            fgets(fAux->cvNomeFantasia, sizeof(fAux->cvNomeFantasia), stdin);
            fAux->cvNomeFantasia[strcspn(fAux->cvNomeFantasia, "\n")] = '\0';
            printf("\nEndereco: ");
            fgets(fAux->cvEndereco, sizeof(fAux->cvEndereco), stdin);
            fAux->cvEndereco[strcspn(fAux->cvEndereco, "\n")] = '\0';
            printf("\CNPJ: ");
            fgets(fAux->cvCnpj, sizeof(fAux->cvCnpj), stdin);
            fAux->cvCnpj[strcspn(fAux->cvCnpj, "\n")] = '\0';
            printf("\nEmail: ");
            fgets(fAux->cvEmail, sizeof(fAux->cvEmail), stdin);
            fAux->cvEmail[strcspn(fAux->cvEmail, "\n")] = '\0';
            printf("\nTelefone: ");
            fgets(fAux->cvTelefone, sizeof(fAux->cvTelefone), stdin);
            fAux->cvTelefone[strcspn(fAux->cvTelefone, "\n")] = '\0';
            printf("\nCelular: ");
            fgets(fAux->cvCelular, sizeof(fAux->cvCelular), stdin);
            fAux->cvCelular[strcspn(fAux->cvCelular, "\n")] = '\0';
            printf("\nCodigo Produto: ");
            scanf("%d", &fAux->iCodigoProduto);
            iNaoEncontrado++;
            break;
        }
        fAux = fAux->fProximo;
    }

    if (iNaoEncontrado == 0)
    {
        nullList();
    }
}

void listarFornecedor()
{
    system("cls || clear");
    printf("\n\t\t\tListando Fornecedores\n");
    printf("\n--------------------------------------------------------------------------------\n");
    if (fFornecedorInicial == NULL)
    {
        nullList();
    }
    else
    {
        Fornecedor *fAux = fFornecedorInicial;
        while (fAux != NULL)
        {
            printf("\nNome: %s |\tNome Fantasia: %s", fAux->cvNome, fAux->cvNomeFantasia);
            printf("\nEndereco: %s |\tCNPJ: %s", fAux->cvEndereco, fAux->cvCnpj);
            printf("\nEmail: %s |\tTelefone: %s ", fAux->cvEmail, fAux->cvTelefone);
            printf("\nCelular: %s |\tCodigo Produto: %d", fAux->cvCelular, fAux->iCodigoProduto);
            printf("\n------------------------------------------------------------------------------\n");
            fAux = fAux->fProximo;
        }
    }
}

void removeFornecedor()
{
    printf("\n\t\t\tRemover Produto\n");
    if (fFornecedorInicial == NULL)
    {
        nullDelete();
    }
    else
    {
        if (fFornecedorInicial->fProximo == NULL)
        {
            fFornecedorInicial = NULL;
        }
        else
        {
            Fornecedor *fAux = fFornecedorInicial;
            fFornecedorInicial = fFornecedorInicial->fProximo;
            free(fAux);
            fAux = NULL;
        }
    }
}

int cadastrarCliente()
{
    system("cls || clear");
    char cEscolha;
    printf("\n\t\t\tCadastro de Cliente\n");
    do
    {
        Cliente *cNovocliente = (Cliente *)malloc(sizeof(Cliente));
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

        if (cClienteInicial == NULL)
        {
            cClienteInicial = cNovocliente;
        }
        else
        {
            Cliente *cAux = cClienteInicial;
            while (cAux->cProximo != NULL)
            {
                cAux = cAux->cProximo;
            }
            cAux->cProximo = cNovocliente;
        }
        cEscolha = escolhaRegistro();
        system("cls || clear");
    } while (cEscolha != 'n');
}

void listarCliente()
{
    system("cls || clear");
    printf("\n\t\t\tListando Clientes:\n\n");
    printf("\n------------------------------------------------------------------------------\n");
    if (cClienteInicial == NULL)
    {
        nullList();
    }
    else
    {
        Cliente *cAux = cClienteInicial;
        while (cAux != NULL)
        {
            printf("\nNome: %s |\tCPF: %s |\tData Nascimento: %s", cAux->cvNomeCli, cAux->cvCpf, cAux->cvData_nascimento);
            printf("\nEmail: %s |\tTelefone: %s", cAux->cvEmail, cAux->cvTelefone);
            printf("\nCelular: %s |\tEndereco: %s", cAux->cvCelular, cAux->cvEndereco);
            printf("\n------------------------------------------------------------------------------\n");
            cAux = cAux->cProximo;
        }
    }
}

void alteraCliente()
{
    Cliente *cAux = cClienteInicial;
    char cvExNome[201];
    flush_in();
    editMessage("cliente");
    fgets(cvExNome, sizeof(cvExNome), stdin);
    cvExNome[strcspn(cvExNome, "\n")] = '\0';
    int iNaoEncontrado = 0;
    while (cAux != NULL)
    {
        if (!strcmp(cAux->cvNomeCli, cvExNome))
        {
            flush_in();
            printf("\nNome: ");
            fgets(cAux->cvNomeCli, sizeof(cAux->cvNomeCli), stdin);
            cAux->cvNomeCli[strcspn(cAux->cvNomeCli, "\n")] = '\0';
            printf("\nCPF: ");
            fgets(cAux->cvCpf, sizeof(cAux->cvCpf), stdin);
            cAux->cvCpf[strcspn(cAux->cvCpf, "\n")] = '\0';
            printf("\nData de Nascimento: ");
            fgets(cAux->cvData_nascimento, sizeof(cAux->cvData_nascimento), stdin);
            cAux->cvData_nascimento[strcspn(cAux->cvData_nascimento, "\n")] = '\0';
            printf("\nEmail: ");
            fgets(cAux->cvEmail, sizeof(cAux->cvEmail), stdin);
            cAux->cvEmail[strcspn(cAux->cvEmail, "\n")] = '\0';
            printf("\nTelefone: ");
            fgets(cAux->cvTelefone, sizeof(cAux->cvTelefone), stdin);
            cAux->cvTelefone[strcspn(cAux->cvTelefone, "\n")] = '\0';
            printf("\nCelular: ");
            fgets(cAux->cvCelular, sizeof(cAux->cvCelular), stdin);
            cAux->cvCelular[strcspn(cAux->cvCelular, "\n")] = '\0';
            printf("\nEndereco: ");
            fgets(cAux->cvEndereco, sizeof(cAux->cvEndereco), stdin);
            cAux->cvEndereco[strcspn(cAux->cvEndereco, "\n")] = '\0';
            iNaoEncontrado++;
            break;
        }
        cAux = cAux->cProximo;
    }

    if (iNaoEncontrado == 0)
    {
        nullList();
    }
}

void removeCliente()
{
    printf("\n\t\t\tRemovendo Cliente\n");
    if (cClienteInicial == NULL)
    {
        nullDelete();
    }
    else
    {
        if (cClienteInicial->cProximo == NULL)
        {
            cClienteInicial = NULL;
        }
        else
        {
            Cliente *cAux = cClienteInicial;
            cClienteInicial = cClienteInicial->cProximo;
            free(cAux);
            cAux = NULL;
        }
    }
}

int cadastrarFuncionario()
{
    system("cls || clear");
    char cEscolha;
    int op;
    printf("\n\t\t\tCadastro de Funcionario\n");
    do
    {
        Funcionario *fNovoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
        fNovoFuncionario->funProximo = NULL;

        flush_in();
        printf("\nNome: ");
        fgets(fNovoFuncionario->cvNomeFunc, sizeof(fNovoFuncionario->cvNomeFunc), stdin);
        fNovoFuncionario->cvNomeFunc[strcspn(fNovoFuncionario->cvNomeFunc, "\n")] = '\0';
        do
        {
            printf("\nCargo: ");
            printf("\n1: GERENTE \n2: CAIXA \n3: FINANCEIRO\n");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                strcpy(fNovoFuncionario->cvCargo, "GERENTE");
                fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
                break;
            case 2:
                strcpy(fNovoFuncionario->cvCargo, "CAIXA");
                fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
                break;
            case 3:
                strcpy(fNovoFuncionario->cvCargo, "FINANCEIRO");
                fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
                break;
            default:
                printf("\nOpcao invalida");
                fflush(stdin);
            }
        } while ((op < 1) || (op > 3));
        flush_in();
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

        if (fFuncionarioInicial == NULL)
        {
            fFuncionarioInicial = fNovoFuncionario;
        }
        else
        {
            Funcionario *fAux = fFuncionarioInicial;
            while (fAux->funProximo != NULL)
            {
                fAux = fAux->funProximo;
            }
            fAux->funProximo = fNovoFuncionario;
        }

        cEscolha = escolhaRegistro();
        system("cls || clear");
    } while (cEscolha != 'n');
}

void listarFuncionario()
{
    system("cls || clear");
    printf("\n\t\t\t Listando Funcionarios\n");
    printf("\n------------------------------------------------------------------------------\n");
    if (fFuncionarioInicial == NULL)
    {
        nullList();
    }
    else
    {
        Funcionario *fAux = fFuncionarioInicial;
        while (fAux != NULL)
        {
            printf("\nNome: %s |\tCargo: %s", fAux->cvNomeFunc, fAux->cvCargo);
            printf("\nCPF: %s |\tData de Nascimento: %s", fAux->cvCpf, fAux->cvData_nascimento);
            printf("\nEmail: %s |\tTelefone: %s", fAux->cvEmail, fAux->cvTelefone);
            printf("\nCelular: %s |\tEndereco: %s", fAux->cvCelular, fAux->cvEndereco);
            printf("\n------------------------------------------------------------------------------\n");
            fAux = fAux->funProximo;
        }
    }
}
void alteraFuncionario()
{
    Funcionario *fAux = fFuncionarioInicial;
    int iOp;
    char cvExNome[201];
    flush_in();
    editMessage("funcionario");
    fgets(cvExNome, sizeof(cvExNome), stdin);
    cvExNome[strcspn(cvExNome, "\n")] = '\0';
    int iNaoEncontrado = 0;
    while (fAux != NULL)
    {
        if(!strcmp(fAux->cvNomeFunc, cvExNome)){
            flush_in();
            printf("\nNome funcionario: ");
            fgets(fAux->cvNomeFunc, sizeof(fAux->cvNomeFunc), stdin);
            fAux->cvNomeFunc[strcspn(fAux->cvNomeFunc, "\n")] = '\0';
            do
            {
                printf("\nCargo: ");
                printf("\n1: GERENTE \n2: CAIXA \n3: FINANCEIRO\n");
                scanf("%d", &iOp);
                switch (iOp)
                {
                case 1:
                    strcpy(fAux->cvCargo, "GERENTE");
                    fAux->cvCargo[strcspn(fAux->cvCargo, "\n")] = '\0';
                    break;
                case 2:
                    strcpy(fAux->cvCargo, "CAIXA");
                    fAux->cvCargo[strcspn(fAux->cvCargo, "\n")] = '\0';
                    break;
                case 3:
                    strcpy(fAux->cvCargo, "FINANCEIRO");
                    fAux->cvCargo[strcspn(fAux->cvCargo, "\n")] = '\0';
                    break;
                default:
                    printf("\nOpcao invalida");
                    fflush(stdin);
                    break;
                }
            } while ((iOp < 1) || (iOp > 3));
            printf("\nCPF: ");
            fgets(fAux->cvCpf, sizeof(fAux->cvCpf), stdin);
            fAux->cvCpf[strcspn(fAux->cvCpf, "\n")] = '\0';
            printf("\nData de Nascimento: ");
            fgets(fAux->cvData_nascimento, sizeof(fAux->cvData_nascimento), stdin);
            fAux->cvData_nascimento[strcspn(fAux->cvData_nascimento, "\n")] = '\0';
            printf("\nEmail: ");
            fgets(fAux->cvEmail, sizeof(fAux->cvEmail), stdin);
            fAux->cvEmail[strcspn(fAux->cvEmail, "\n")] = '\0';
            printf("\nTelefone: ");
            fgets(fAux->cvTelefone, sizeof(fAux->cvTelefone), stdin);
            fAux->cvTelefone[strcspn(fAux->cvTelefone, "\n")] = '\0';
            printf("\nCelular: ");
            fgets(fAux->cvCelular, sizeof(fAux->cvCelular), stdin);
            fAux->cvCelular[strcspn(fAux->cvCelular, "\n")] = '\0';
            printf("\nEndereco: ");
            fgets(fAux->cvEndereco, sizeof(fAux->cvEndereco), stdin);
            fAux->cvEndereco[strcspn(fAux->cvEndereco, "\n")] = '\0';
            iNaoEncontrado++;
            break;
        }
        fAux = fAux->funProximo;
    }
    if (iNaoEncontrado == 0)
    {
        nullList();
    }
}
void removeFuncionario()
{
    printf("\n\t\t\tRemovendo Funcionario\n");
    if (fFuncionarioInicial == NULL)
    {
        nullDelete();
    }
    else
    {
        if (fFuncionarioInicial->funProximo == NULL)
        {
            fFuncionarioInicial = NULL;
        }
        else
        {
            Funcionario *fAux = fFuncionarioInicial;
            fFuncionarioInicial = fFuncionarioInicial->funProximo;
            free(fAux);
            fAux = NULL;
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