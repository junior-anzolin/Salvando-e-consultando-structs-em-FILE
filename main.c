#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    typedef struct ficha_vendedores{
        int viCodigo;
        char vcNome[30];
        char vcEndereco[50];
        char vcFone[20];
        int ativo;
    }T_ficha_vendedores;
    typedef struct ficha_produtos{
        int viCodigo;
        int viUniEstoque;
        char vcDescricao[50];
        char vcFornecedor[30];
        char vcDataComp[20];
        float vfPreco;
        int ativo;
    }T_ficha_produtos;
    typedef struct ficha_cliente{
        int viCodigo;
        char vcNome[30];
        char vcEndereco[50];
        char vcFone[20];
        int vbCredito;
        int ativo;
    }T_ficha_cliente;
  void limpaBuffer(){
        char c = '\n';
        while(1){ c = getchar(); if(c == '\n') break; }
}
void lerString(char *str, int maxlen){
        //limpa qualquer \n
        fflush(stdin);

        int len;
        char buff[200];
        //leitura/verificar tamanho
        scanf(" %[^\n]s", buff);
        len = (strlen(buff) > maxlen) ? (maxlen-1):strlen(buff);
        //copia
        strncpy(str,buff,len);
        //...
        limpaBuffer();
}

int lerVendedor(T_ficha_vendedores arr[]){
        FILE * arq = fopen("vendedores.bin", "rb");
    if(arq != NULL){
        int indice = 0;
        while(1){
            T_ficha_vendedores p;
            size_t r = fread(&p, sizeof(T_ficha_vendedores), 1, arq);

            // se retorno for menor que o count, então sai do loop
            if(r < 1)
                break;
            else
                arr[indice++] = p;
        }
        fclose(arq); // fecha o arquivo
        return indice;
    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        printf("\nCriando arquivo!\n");
        arq = fopen("vendedores.bin", "w");
        if(arq){
            printf("Arquivo criado com sucesso! (vendedores.bin)\n");
        }else{
            printf("Erro ao criar arquivo (vendedores.bin)\n");
        }
        fclose(arq); // fecha o arquivo
        system("pause"); 
        return 0;
    }
}
int lerProdutos(T_ficha_produtos arr[]){
        FILE * arq = fopen("produtos.bin", "rb");
    if(arq != NULL){
        int indice = 0;
        T_ficha_produtos p;
        while(1){
            size_t r = fread(&p, sizeof(T_ficha_produtos), 1, arq);
            // se retorno for menor que o count, então sai do loop
            if(r < 1)
                break;
            else
                arr[indice++] = p;
        }
        fclose(arq); // fecha o arquivo
        return indice;
    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        printf("\nCriando arquivo!\n");
        arq = fopen("produtos.bin", "w");
        if(arq){
            printf("Arquivo criado com sucesso! (produtos.bin)\n");
        }else{
            printf("Erro ao criar arquivo (produtos.bin)\n");
        }
        fclose(arq); // fecha o arquivo
        system("pause"); 
        return 0;
    }
}
int lerClientes(T_ficha_cliente arr[]){
    FILE * arq;
    arq = fopen("clientes.bin", "rb");
    if(arq){
        int indice = 0;
        T_ficha_cliente p;
        while(1){
            size_t r = fread(&p, sizeof(T_ficha_cliente), 1, arq);
            // se retorno for menor que o count, então sai do loop
            if(r < 1)
                break;
            else
                arr[indice++] = p;
        }
        fclose(arq);
        return indice;
    }else{
        printf("\nErro ao abrir o arquivo para leitura!\n");
        printf("\nCriando arquivo!\n");
        arq = fopen("clientes.bin", "w");
        if(arq){
            printf("Arquivo criado com sucesso! (clientes.bin)\n");
        }else{
            printf("Erro ao criar arquivo (clientes.bin)\n");
        }
        fclose(arq); // fecha o arquivo
        system("pause"); 
        return 0;
    }
}
void CadastraVendedores(T_ficha_vendedores vendedor[], int viCodigo){
    fflush(stdin);
    system("cls");

    printf("\n\n<---------- Novo vendedor ---------->\n\n");
    vendedor[viCodigo].ativo = 1;
    vendedor[viCodigo].viCodigo = viCodigo;

    printf("Codigo: %d\n\n", vendedor[viCodigo].viCodigo);
    printf("Nome: ");
    lerString(vendedor[viCodigo].vcNome, 30);

    printf("Endereco: ");
    lerString(vendedor[viCodigo].vcEndereco, 50);

    printf("Telefone: ");
    lerString(vendedor[viCodigo].vcFone, 20);

    printf("\n<---------- Novo vendedor ---------->\n\n");
}
void CadastraProdutos(T_ficha_produtos produto[], int viCodigo){
    system("cls");
    printf("\n\n<---------- Novo produto ---------->\n\n");
    produto[viCodigo].ativo = 1;
    produto[viCodigo].viCodigo = viCodigo;

    printf("Codigo: %d\n\n", produto[viCodigo].viCodigo);

    printf("Unidade no estoque: ");
    scanf("%d", &produto[viCodigo].viUniEstoque);

    printf("Descricao do produto: ");
    lerString(produto[viCodigo].vcDescricao, 50);

    printf("Fornecedor: ");
    lerString(produto[viCodigo].vcFornecedor, 30);

    printf("Preco final: ");
    scanf("%f", &produto[viCodigo].vfPreco);

    printf("Data da compra 00/00/0000: ");
    lerString(produto[viCodigo].vcDataComp, 20);

    printf("\n<---------- Novo produto ---------->\n\n");
}
void CadastraClientes(T_ficha_cliente cliente[], int viCodigo){
    system("cls");
    printf("\n\n<---------- Novo cliente ---------->\n\n");
    cliente[viCodigo].vbCredito = 1;
    cliente[viCodigo].ativo = 1;
    cliente[viCodigo].viCodigo = viCodigo;

    printf("Codigo: %d\n\n", cliente[viCodigo].viCodigo);

    printf("Nome: ");
    lerString(cliente[viCodigo].vcNome, 30);

    printf("Endereco: ");
    lerString(cliente[viCodigo].vcEndereco, 50);

    printf("Telefone: ");
    lerString(cliente[viCodigo].vcFone, 20);

    printf("\n<---------- Novo cliente ---------->\n\n");
}
void VerifyContinue(char text[50], int *result){
    char out[5];
    *result = 10;
    printf("%s[s/n]\n", text);
    fflush(stdin);
    fgets(out, 5, stdin);
    if((strncmp(out, "s", 1))){
        *result = 0;
    }
}
void PrintMenu(int *option){
    system("cls");
    printf("<============================>\n");
    printf("<----------- Menu ----------->\n");
    printf("<============================>\n");
    printf("<=      1. Cadastrar        =>\n");
    printf("<=      2. Listar           =>\n");
    printf("<=      3. Emitir venda     =>\n");
    printf("<=      4. Procurar         =>\n");
    printf("<=      0. Sair             =>\n");
    printf("<============================>\n");
    scanf("%d", &*option);
}
void MenuCadastros(int *option){
    system("cls");
    printf("<============================>\n");
    printf("<------ Menu Cadastro ------->\n");
    printf("<============================>\n");
    printf("<=      1. Novo cliente     =>\n");
    printf("<=      2. Novo produto     =>\n");
    printf("<=      3. Novo vendedor    =>\n");
    printf("<=      0. Voltar ao inicio =>\n");
    printf("<============================>\n");
    scanf("%d", &*option);
}
void MenuProcurar(int *option){
    system("cls");
    printf("<============================>\n");
    printf("<--------- Procurar --------->\n");
    printf("<============================>\n");
    printf("<=      1. Clientes         =>\n");
    printf("<=      2. Produtos         =>\n");
    printf("<=      3. Vendedores       =>\n");
    printf("<=      0. Voltar ao inicio =>\n");
    printf("<============================>\n");
    scanf("%d", &*option);
}
void MenuListar(int *option){
    system("cls");
    printf("<============================>\n");
    printf("<---------- Listar ---------->\n");
    printf("<============================>\n");
    printf("<=      1. Clientes         =>\n");
    printf("<=      2. Produtos         =>\n");
    printf("<=      3. Vendedores       =>\n");
    printf("<=      0. Voltar ao inicio =>\n");
    printf("<============================>\n");
    scanf("%d", &*option);
}
void MenuDetalhes(int *option){
    printf("<============================>\n");
    printf("<--------- Detalhes --------->\n");
    printf("<============================>\n");
    printf("<=      1. Alterar          =>\n");
    printf("<=      2. Excluir          =>\n");
    printf("<=      0. Voltar           =>\n");
    printf("<============================>\n");
    scanf("%d", &*option);
}
void SalvarArqClientes(T_ficha_cliente clientes[], int sizeVet){
    int i;
    FILE * arq;
    arq = fopen("clientes.bin", "w");
    if(arq != NULL){
        for (i = 0; i < sizeVet; i++){
            fwrite(&clientes[i], sizeof(T_ficha_cliente), 1, arq);
        }
        fclose(arq);
    }else{
        printf("Erro ao salvar o arquivo\n");
        system("pause");
        exit(1);
    }
}
void SalvarArqProdutos(T_ficha_produtos produtos[], int sizeVet){
    int i;
    FILE * arq;
    arq = fopen("produtos.bin", "w");
    if(arq != NULL){
        for (i = 0; i < sizeVet; i++)        {
            fwrite(&produtos[i], sizeof(T_ficha_produtos), 1, arq);
        }
        fclose(arq);
    }else{
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
}
void SalvarArqVendedores(T_ficha_vendedores vendedores[], int sizeVet){
    int i;
    FILE * arq;
    arq = fopen("vendedores.bin", "w");
    if(arq != NULL){
        for (i = 0; i < sizeVet; i++)        {
            fwrite(&vendedores[i], sizeof(T_ficha_vendedores), 1, arq);
        }
        fclose(arq);
    }else{
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
}
void ListarClientes(T_ficha_cliente arr[], int size){
    int i, sizeA = 0;
    for(i = 0; i < size; i++){
        if(arr[i].ativo == 1){
            sizeA += 1;
        }
    }
    if(sizeA > 0){
        for(i = 0; i < size; i++){
            if(arr[i].ativo==1){
                printf("\n<===============================>\n\n");
                printf("ID: %d\n", i+1);
                printf("CODIGO: %d\n", arr[i].viCodigo);
                printf("NOME: %s", arr[i].vcNome);
                printf("\n<===============================>\n");
            }
        }
    }else{
        printf("Nenhum regstro encontrado.\n");
    }
}
void DetalhesCliente(T_ficha_cliente arr[], int option){
    printf("CLIENTE %d\n", option);
    printf("CODIGO: %d\n", arr[option-1].viCodigo);
    printf("NOME: %s\n", arr[option-1].vcNome);
    printf("ENDERECO: %s\n", arr[option-1].vcEndereco);
    printf("TELEFONE: %s\n", arr[option-1].vcFone);
    printf("STATUS CREDITO: ");
    if(arr[option-1].vbCredito == 1){
        printf("OK!\n");
    }else{
        printf("EM DEBITO\n");
    }
}
void AlteraCliente(T_ficha_cliente cliente[], int option){
    int verify;
    system("cls");
    printf("\n\n<---------- Editar cliente ---------->\n\n");
    printf("Codigo: %d\n\n", cliente[option-1].viCodigo);
    if(cliente[option-1].vbCredito == 0){
        printf("Este cliente tem debitos pendentes.\n");
        VerifyContinue("Foram pagos?", &verify);
        if(verify != 0){
            cliente[option-1].vbCredito = 1;
            printf("Atualizado com sucesso!\n");
        }else{
            printf("OK!\n");
        }
    }
    system("cls");
    printf("\n\n<---------- Editar cliente ---------->\n\n");
    printf("Codigo: %d\n\n", cliente[option-1].viCodigo);
    printf("NOME: %s\n", cliente[option-1].vcNome);
    VerifyContinue("Alterar NOME?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        printf("Nome: ");
        lerString(cliente[option-1].vcNome, 30);
    }
    system("cls");
    printf("\n\n<---------- Editar cliente ---------->\n\n");
    printf("Codigo: %d\n\n", cliente[option-1].viCodigo);
    printf("ENDERECO: %s\n", cliente[option-1].vcEndereco);
    VerifyContinue("Alterar ENDERECO?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        printf("Endereco: ");
        lerString(cliente[option-1].vcEndereco, 50);
    }
    system("cls");
    printf("\n\n<---------- Editar cliente ---------->\n\n");
    printf("Codigo: %d\n\n", cliente[option-1].viCodigo);
    printf("TELEFONE: %s\n", cliente[option-1].vcFone);
    VerifyContinue("Alterar TELEFONE?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        printf("Telefone: ");
        lerString(cliente[option-1].vcFone, 20);
    }
    printf("\n<---------- Editar cliente ---------->\n\n");
}
void ExcluiCliente(T_ficha_cliente cliente[], int option){
    cliente[option-1].ativo = 0;
    if(cliente[option-1].ativo == 0){
        printf("Produto excluido com sucesso\n");
    }else{
        printf("Ops! Algo deu errado\n");
    }
}
void ListarProdutos(T_ficha_produtos arr[], int size){
    int i, sizeA = 0;
    for(i = 0; i < size; i++){
        if(arr[i].ativo == 1){
            sizeA += 1;
        }
    }
    if(sizeA > 0){
        for(i = 0; i < size; i++){
            if(arr[i].ativo==1){
                printf("\n<===============================>\n\n");
                printf("ID: %d\n", i+1);
                printf("CODIGO: %d\n", arr[i].viCodigo);
                printf("DESCRICAO: %s\n", arr[i].vcDescricao);
                printf("QTD. EM ESTOQUE: %d\n", arr[i].viUniEstoque);
                printf("PRECO UNI.: %.2f\n", arr[i].vfPreco);
                printf("\n<===============================>\n");
            }
        }
    }else{
        printf("Nenhum regstro encontrado.\n");
    }
}
void DetalhesProduto(T_ficha_produtos arr[], int option){
    printf("PRODUTO %d\n", option);
    printf("CODIGO: %d\n", arr[option-1].viCodigo);
    printf("UNIDADES EM ESTOQUE: %d\n", arr[option-1].viUniEstoque);
    printf("DESCRICAO DO PRODUTO: %s\n", arr[option-1].vcDescricao);
    printf("FORNECEDOR:  %s\n", arr[option-1].vcFornecedor);
    printf("DATA DA COMPRA: %s\n", arr[option-1].vcDataComp);
    printf("PRECO: %.2f\n", arr[option-1].vfPreco);
}
void AlteraProduto(T_ficha_produtos produto[], int option){
    int verify;
    system("cls");
    printf("\n\n<---------- Editar produto ---------->\n\n");
    printf("Codigo: %d\n\n", produto[option-1].viCodigo);
    printf("UNIDADES EM ESTOQUE: %d\n", produto[option-1].viUniEstoque);
    VerifyContinue("Alterar UNIDADES EM ESTOQUE?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Unidade no estoque: ");
        scanf("%d", &produto[option-1].viUniEstoque);
    }
    system("cls");
    printf("\n\n<---------- Editar produto ---------->\n\n");
    printf("Codigo: %d\n\n", produto[option-1].viCodigo);
    printf("DESCRICAO DO PRODUTO: %s\n", produto[option-1].vcDescricao);
    VerifyContinue("Alterar DESCRICAO DO PRODUTO?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Descricao do produto: ");
        lerString(produto[option-1].vcDescricao, 50);
    }
    system("cls");
    printf("\n\n<---------- Editar produto ---------->\n\n");
    printf("Codigo: %d\n\n", produto[option-1].viCodigo);
    printf("FORNECEDOR: %s\n", produto[option-1].vcFornecedor);
    VerifyContinue("Alterar FORNECEDOR?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Fornecedor: ");
        lerString(produto[option-1].vcFornecedor, 30);
    }
    system("cls");
    printf("\n\n<---------- Editar produto ---------->\n\n");
    printf("Codigo: %d\n\n", produto[option-1].viCodigo);
    printf("PRECO: %.2f\n", produto[option-1].vfPreco);
    VerifyContinue("Alterar PRECO?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Preco final: ");
        scanf("%f", &produto[option-1].vfPreco);
    }
    system("cls");
    printf("\n\n<---------- Editar produto ---------->\n\n");
    printf("Codigo: %d\n\n", produto[option-1].viCodigo);
    printf("DATA DA COMPRA: %s\n", produto[option-1].vcDataComp);
    VerifyContinue("Alterar DATA DA COMPRA?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Data da compra 00/00/0000: ");
        lerString(produto[option-1].vcDataComp, 20);
    }
    printf("\n<---------- Editar produto ---------->\n\n");
}
                            void ExcluiProduto(T_ficha_produtos produto[], int option){
    produto[option-1].ativo = 0;
    if(produto[option-1].ativo == 0){
        printf("Produto excluido com sucesso\n");
    }else{
        printf("Ops! Algo deu errado\n");
    }
}
void ListarVendedores(T_ficha_vendedores arr[], int size){
    int i, sizeA = 0;
    for(i = 0; i < size; i++){
        if(arr[i].ativo == 1){
            sizeA += 1;
        }
    }
    if(sizeA > 0){
        for (i = 0; i < size; i++){
            if(arr[i].ativo==1){
                printf("\n<===============================>\n\n");
                printf("ID: %d\n", i+1);
                printf("CODIGO: %d\n", arr[i].viCodigo);
                printf("NOME: %s", arr[i].vcNome);
                printf("\n<===============================>\n");
            }
        }
    }else{
        printf("Nenhum regstro encontrado.\n");
    }
}
void DetalhesVendedor(T_ficha_vendedores arr[], int option){
    printf("VENDEDOR %d\n", option);
    printf("CODIGO: %d\n", arr[option-1].viCodigo);
    printf("NOME: %s\n", arr[option-1].vcNome);
    printf("ENDERECO: %s\n", arr[option-1].vcEndereco);
    printf("TELEFONE:  %s\n", arr[option-1].vcFone);
}
void AlteraVendedor(T_ficha_vendedores vendedor[], int option){
    int verify;
    system("cls");
    printf("\n\n<---------- Editar vendedor ---------->\n\n");
    printf("Codigo: %d\n\n", vendedor[option-1].viCodigo);
    printf("NOME: %s\n", vendedor[option-1].vcNome);
    VerifyContinue("Alterar NOME?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Nome: ");
        lerString(vendedor[option-1].vcNome, 30);
    }
    system("cls");
    printf("\n\n<---------- Editar vendedor ---------->\n\n");
    printf("Codigo: %d\n\n", vendedor[option-1].viCodigo);
    printf("ENDERECO: %s\n", vendedor[option-1].vcNome);
    VerifyContinue("Alterar ENDERECO?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Endereco: ");
        lerString(vendedor[option-1].vcEndereco, 50);
    }
    system("cls");
    printf("\n\n<---------- Editar vendedor ---------->\n\n");
    printf("Codigo: %d\n\n", vendedor[option-1].viCodigo);
    printf("TELEFONE: %s\n", vendedor[option-1].vcNome);
    VerifyContinue("Alterar TELEFONE?", &verify);
    if(verify == 0){
        printf("OK!\n");
    }else{
        fflush(stdin);
        printf("Telefone: ");
        lerString(vendedor[option-1].vcFone, 20);
    }
    printf("\n<---------- Editar vendedor ---------->\n\n");
}
void ExcluiVendedor(T_ficha_vendedores vendedor[], int option){
    vendedor[option-1].ativo = 0;
    if(vendedor[option-1].ativo == 0){
        printf("Vendedor excluido com sucesso\n");
    }else{
        printf("Ops! Algo deu errado\n");
    }
}
int getVendedor(T_ficha_vendedores arr[], int size){
    int id;
    do{
        system("cls");
        ListarVendedores(arr, size);
        printf("Digite o ID do vendedor que esta vendendo.\nOu digite 0 para sair.\n");
        scanf("%d", &id);
        if(!(id == 0)){
            if(arr[id - 1].ativo==1){
                return id--;
            }else{
                printf("Desculpe mas este vendedor está desativado.\n");
                system("pause");
                return -1;
            }
        }else{
            return -1;
        }
    }while(id != 0);
}
int getCliente(T_ficha_cliente arr[], int size){
    int id;
    do{
        system("cls");
        ListarClientes(arr, size);
        printf("Digite o ID do cliente que esta comprando.\nOu digite 0 para sair.\n");
        scanf("%d", &id);
        if(!(id == 0)){
            if(arr[id - 1].ativo==1){
                if(arr[id - 1].vbCredito==1){
                    arr[id - 1].vbCredito=0;
                    return id--;
                }else{
                    printf("Desculpe mas este cliente está com debitos pendentes.\n");
                    system("pause");
                    return -1;
                }
            }else{
                    printf("Desculpe mas este cliente está desativado.\n");
                    return -1;
            }
        }else{
            return -1;
        }
    }while(id != 0);
}
void ListarCarrinho(int itens[], int quant[], T_ficha_produtos produtos[]){
    int i;
    float totalC=0;
    system("cls");
    for (i = 0; i < 100; ++i){
        if(itens[i] != 0){
            printf("\n<===============================>\n\n");
            printf("CODIGO: %d\n", produtos[itens[i]-1].viCodigo);
            printf("QUANTIDADE: %d\n", quant[itens[i]-1]);
            printf("DESCRICAO: %s", produtos[itens[i]-1].vcDescricao);
            printf("PRECO UNI.: %.2f\n", produtos[itens[i]-1].vfPreco);
            float preco = produtos[itens[i]-1].vfPreco;
            int quantidade = quant[i];
            totalC += preco * quantidade;
            printf("TOTAL: %2.f\n", preco * quantidade);
            printf("\n<===============================>\n");
        }
    }
    printf("\nTotal da compra = %.2f\n\n", totalC);
}
void NotaFiscal(int itens[], int quant[], T_ficha_produtos produtos[], T_ficha_vendedores vendedor[], T_ficha_cliente cliente[], int codVend, int codClie){
    int i;
    float totalC=0;
    system("cls");
    printf("\n\tNOTA FISCAL\t\n\n");
    printf("\tVendedor\t\n\n");
    printf("CODIGO: %d\n", vendedor[codVend-1].viCodigo);
    printf("NOME: %s\n\n", vendedor[codVend-1].vcNome);
    printf("\tCliente\t\n\n");
    printf("CODIGO: %d\n", cliente[codClie-1].viCodigo);
    printf("NOME: %s\n\n", cliente[codClie-1].vcNome);
    printf("\tProdutos:\t\n\n");
    printf("CODIGO\t|\tQUANT.\t|\tDESC.\t|\tPRECO UNI.\t|\tTOTAL\n");
    for (i = 0; i < 100; ++i){
        if(itens[i] != 0){
            float preco = produtos[itens[i]-1].vfPreco;
            int quantidade = quant[i];
            printf("%d\t|\t%d\t|\t%s\t|\t%.2f\t|\t%2.f\n", produtos[itens[i]-1].viCodigo, quant[i], produtos[itens[i]-1].vcDescricao, produtos[itens[i]-1].vfPreco, preco * quantidade);

            totalC += preco * quantidade;
        }
    }
    printf("\nTotal da compra = %.2f\n", totalC);
}
void NovaVenda(T_ficha_cliente clientes[], T_ficha_produtos produtos[], T_ficha_vendedores vendedores[], int sizeC, int sizeP, int sizeV){
    system("cls");
    int codVend, codProdutos[100], codClie, test, count=0, prod, quantTemp, quant[100], i, unidades;
    char str[20];

    for(i=0;i<100;i++){
        codProdutos[i] = 0;
        quant[i] = 0;
    }

    codVend = getVendedor(vendedores, sizeV);

    if(!(codVend < 0)){
        codClie = getCliente(clientes, sizeC);
    }

    if((!(codVend < 0)) && (!(codClie < 0))){
        do{
            system("cls");
            ListarProdutos(produtos, sizeP);
            printf("Digite o ID do produto para adicionar no carrinho.\nOu digite 0 para sair.\n");
            scanf("%d", &prod);
            unidades = produtos[prod-1].viUniEstoque;
            if(!(prod == 0)){
                printf("Quantos?\n");
                scanf("%d", &quantTemp);
                if(unidades >= quantTemp){
                    quant[count] = quantTemp;
                    codProdutos[count] = prod;
                    unidades -= quantTemp;
                    produtos[prod-1].viUniEstoque = unidades;
                    count++;
                }else{
                    printf("Ops! Nao temos tanto no estoque.\nProduto nao adicionado ao carrinho!\n");
                }
                VerifyContinue("Cadastrar mais?", &test);
            }else{
                test = 0;
            }
        }while(test != 0);

        if(!(prod == 0)){
            ListarCarrinho(codProdutos, quant, produtos);
            
            VerifyContinue("Emitir nota fiscal?", &test);
            if(test != 0){
                NotaFiscal(codProdutos, quant, produtos, vendedores, clientes, codVend, codClie);
                system("pause");
            }else{
                printf("\n\nVenda realizada com sucesso!\n\n\n");
                system("pause");
            }
        }else{
            printf("Venda cancelada!\n");
            system("pause");
        }
    }else{
        printf("Venda cancelada!\n");
        system("pause");
    }
}

void ProcurarClientes(T_ficha_cliente arr[]){
    char pesquisa[50];
    int i, count = 0;
    printf("Informe o Nome que procura:");
    fflush(stdin);
    lerString(pesquisa, 50);
    system("cls");
    printf("\n\nResultados de pesquisa: %s\b\b\n\n", pesquisa);
    for(i=0; i< 100; i++){
        if(strcmp(pesquisa, arr[i].vcNome) == 0){
        	if(arr[i].ativo==1){
                count++;
	            printf("<---------------------------------------->\n");
	            DetalhesCliente(arr, i+1);
	            printf("<---------------------------------------->\n");
	        }
        }
    }
    if(count>0){
        printf("%d resultado(s) encontrado(s)\n\n", count);
    }else{
        printf("Nenhum registro encontrado.\n\n");
    }
    system("pause");
}
void ProcurarProdutos(T_ficha_produtos arr[]){
    char pesquisa[50];
    int i, count = 0;
    printf("Informe a descricao que procura:");
    fflush(stdin);
    lerString(pesquisa, 50);
    system("cls");
    printf("\n\nResultados de pesquisa: %s\b\b\n\n", pesquisa);
    for(i=0; i < 50; i++){
        if(strcmp(pesquisa, arr[i].vcDescricao) == 0){
        	if(arr[i].ativo==1){
                count++;
	            printf("<---------------------------------------->\n");
	            DetalhesProduto(arr, i+1);
	            printf("<---------------------------------------->\n");
	        }
        }
    }
    if(count>0){
        printf("%d resultado(s) encontrado(s)\n\n", count);
    }else{
        printf("Nenhum registro encontrado.\n\n");
    }
    system("pause");
}
void ProcurarVendedores(T_ficha_vendedores arr[]){
    char pesquisa[50];
    int i, count = 0;
    printf("Informe o Nome que procura:");
    fflush(stdin);
    lerString(pesquisa, 50);
    system("cls");
    printf("\n\nResultados de pesquisa: %s\b\b\n\n", pesquisa);
    for(i=0; i< 10; i++){
        if(strcmp(pesquisa, arr[i].vcNome) == 0){
        	if(arr[i].ativo==1){
                count++;
	            printf("<---------------------------------------->\n");
	            DetalhesVendedor(arr, i+1);
	            printf("<---------------------------------------->\n");
	        }
        }
    }
    if(count>0){
        printf("%d resultado(s) encontrado(s)\n\n", count);
    }else{
        printf("Nenhum registro encontrado.\n\n");
    }
    system("pause");
}

int main(void){
    int viMenu, idC=0, idP=0, idV=0, i, sair, option, optiondt, verify;
    T_ficha_cliente clientes[100];
    T_ficha_produtos produtos[50];
    T_ficha_vendedores vendedores[10];
    int sizeC = lerClientes(clientes);
    int sizeV = lerVendedor(vendedores);
    int sizeP = lerProdutos(produtos);
    int sizeAC, sizeAP, sizeAV;
    do{
        PrintMenu(&viMenu);

        system("cls");
        switch(viMenu){
            case 1:
                do{
                    MenuCadastros(&sair);
                    switch(sair){
                        case 1:
                            if(sizeC < 100){
                                CadastraClientes(clientes, sizeC);
                                sizeC += 1;
                                break;
                            }else{
                                printf("Ops! Nao tenho mais espaco!\n");
                                system("pause");
                                sair = 0;
                            }
                        case 2:
                            if(sizeV < 50){
                                CadastraProdutos(produtos, sizeP);
                                sizeP += 1;
                                break;
                            }else{
                                printf("Ops! Nao tenho mais espaco!\n");
                                system("pause");
                                sair = 0;
                            }
                        case 3:
                            if(sizeP < 10){
                                CadastraVendedores(vendedores, sizeV);
                                sizeV += 1;
                                break;
                            }else{
                                printf("Ops! Nao tenho mais espaco!\n");
                                system("pause");
                                sair = 0;
                            }
                    }
                }while(sair != 0);
                break;
            case 2:
                do{
                    MenuListar(&sair);
                    system("cls");
                    switch(sair){
                        case 1:
                            do{
                                system("cls");
                                ListarClientes(clientes, sizeC);
                                sizeAC = 0;
                                for(i = 0; i < sizeC; i++){
                                    if(clientes[i].ativo == 1){
                                        sizeAC += 1;
                                    }
                                }
                                if(sizeAC > 0){
                                    printf("Digite o ID do cliente para ver detalhes, alterar ou excluir\nOu 0 para voltar ao menu anterior\n");
                                }else{
                                    printf("Digite 0 para voltar ao menu anterior\n");
                                }
                                scanf("%d", &option);
                                if(option == 0){
                                    break;
                                }
                                system("cls");
                                DetalhesCliente(clientes, option);
                                MenuDetalhes(&optiondt);
                                system("cls");
                                switch(optiondt){
                                    case 1:
                                        do{
                                            AlteraCliente(clientes, option);
                                            system("cls");
                                            DetalhesCliente(clientes, option);
                                            VerifyContinue("Tudo certo?", &verify);
                                        }while(verify == 0);
                                        break;
                                    case 2:
                                        ExcluiCliente(clientes, option);
                                        system("pause");
                                        break;
                                }
                            }while((option != 0) || (clientes[option-1].ativo != 0));
                            break;
                        case 2:
                            do{
                                system("cls");
                                ListarProdutos(produtos, sizeP);
                                sizeAP = 0;
                                for(i = 0; i < sizeP; i++){
                                    if(produtos[i].ativo == 1){
                                        sizeAP += 1;
                                    }
                                }
                                if(sizeAP > 0){
                                    printf("Digite o ID do produto para ver detalhes, alterar ou excluir\nOu 0 para voltar ao menu anterior\n");
                                }else{
                                    printf("Digite 0 para voltar ao menu anterior\n");
                                }
                                scanf("%d", &option);
                                if(option == 0){
                                    break;
                                }
                                system("cls");
                                DetalhesProduto(produtos, option);
                                MenuDetalhes(&optiondt);
                                system("cls");
                                switch(optiondt){
                                    case 1:
                                        do{
                                            AlteraProduto(produtos, option);
                                            system("cls");
                                            DetalhesProduto(produtos, option);
                                            VerifyContinue("Tudo certo?", &verify);
                                        }while(verify == 0);
                                        break;
                                    case 2:
                                        ExcluiProduto(produtos, option);
                                        system("pause");
                                        break;
                                }
                            }while((option != 0) || (produtos[option-1].ativo != 0));
                            break;
                        case 3:
                            do{
                                system("cls");
                                ListarVendedores(vendedores, sizeV);
                                sizeAV = 0;
                                for(i = 0; i < sizeV; i++){
                                    if(vendedores[i].ativo == 1){
                                        sizeAV += 1;
                                    }
                                }
                                if(sizeAV > 0){
                                    printf("Digite o ID do produto para ver detalhes, alterar ou excluir\nOu 0 para voltar ao menu anterior\n");
                                }else{
                                    printf("Digite 0 para voltar ao menu anterior\n");
                                }
                                scanf("%d", &option);
                                if(option == 0){
                                    break;
                                }
                                system("cls");
                                DetalhesVendedor(vendedores, option);
                                MenuDetalhes(&optiondt);
                                system("cls");
                                switch(optiondt){
                                    case 1:
                                        do{
                                            AlteraVendedor(vendedores, option);
                                            system("cls");
                                            DetalhesVendedor(vendedores, option);
                                            VerifyContinue("Tudo certo?", &verify);
                                        }while(verify == 0);
                                        break;
                                    case 2:
                                        ExcluiVendedor(vendedores, option);
                                        system("pause");
                                        break;
                                }
                            }while((option != 0) || (vendedores[option-1].ativo != 0));
                            break;
                    }
                }while(sair != 0);
                break;
            case 3:
                do{
                    sair = 10;
                    if((sizeC > 0) && (sizeV > 0) && (sizeP > 0)){
                        NovaVenda(clientes, produtos, vendedores, sizeC, sizeP, sizeV);
                        VerifyContinue("Fazer uma nova venda?", &sair);
                    }else{
                        sair = 0;
                        if(sizeC <= 0){
                            printf("Ops! Nao ha clientes, por favor cadastra pelo menos um.\n");
                        }
                        if(sizeP <= 0){
                            printf("Ops! Nao ha produtos, por favor cadastra pelo menos um.\n");
                        }
                        if(sizeV <= 0){
                            printf("Ops! Nao ha vendedores, por favor cadastra pelo menos um.\n");
                        }
                        system("pause");
                    }
                }while(sair != 0);
                break;
            case 4:
                do{
                    sair = 10;
                    MenuProcurar(&sair);
                    switch(sair){
                        case 1:
                            ProcurarClientes(clientes);
                            break;
                        case 2:
                            ProcurarProdutos(produtos);
                            break;
                        case 3:
                            ProcurarVendedores(vendedores);
                            break;
                    }
                }while(sair != 0);
                break;
        }
        
        SalvarArqClientes(clientes, sizeC);
        SalvarArqProdutos(produtos, sizeP);
        SalvarArqVendedores(vendedores, sizeV);

    }while(viMenu != 0);

    system("cls");
    SalvarArqClientes(clientes, sizeC);
    SalvarArqProdutos(produtos, sizeP);
    SalvarArqVendedores(vendedores, sizeV);
    printf("\n\n\n\t\tEncerrando...\n\n\n");
    system("pause");
    return 0;
}
