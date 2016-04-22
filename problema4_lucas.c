 /****************************************************************************************
Autor: Lucas Alves da Encarnação Oliveira
Componente Curricular : MI - Algoritmos I
Concluido em: 10/05/2016
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet, qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não seráo considerados para fins de avaliação

*****************************************************************************************/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Lista{
	int num_cadastro;
	char posto[10];
	char data[10];
	char nome[30];
	int rg;
	int idade;
	char endereco[30];
	struct Lista *proximo;
};
typedef struct Lista lista;

void insercao_inicio(lista *, int);
int menu_principal(void);
int menu_consulta(void);
void consulta_cadastro(lista *, int);
void consulta_nome(lista *, char []);
void consulta_rg(lista *, int);
void atualizar(lista *, int);
void remover(lista *, int);

int main(void)
{

	lista *LISTA = (lista *) malloc(sizeof(lista));
	LISTA->proximo = NULL;
	lista *P = LISTA;

	int escolha;
	int cadastro = 1;
	int aux;
	while(true)
		{
			escolha = menu_principal();
			switch (escolha)
			{
				case 1:
						insercao_inicio( P, cadastro);
						cadastro++;
						break;
				case 2:
				    {
                        int escolha_2;
                        int cadastro;
                        char nome[30];
                        int rg;
                        escolha_2 = menu_consulta();
                        switch (escolha_2)
                        {
                            case 1:
                                printf("Digite o numero de cadastro \n");
                                scanf("%d", &cadastro);
                                consulta_cadastro(P, cadastro);
                                break;
                            case 2:
                                printf("Digite o nome do paciente \n");
                                scanf("%s", nome);
                                consulta_nome(P, nome);
                                break;
                            case 3:
                                printf("Digite o numero do RG \n");
                                scanf("%d", &rg);
                                consulta_rg(P, rg);
                                break;

                            }
                    break;
				    }
            case 3:
                    printf("Digite o numero de cadastro que deseja atualizar\n");
                    scanf("%d", &aux);
                    atualizar(P, aux);
                    break;
            case 4:
                    printf("Digite o numero de cadastro que deseja Remover\n");
                    scanf("%d", &aux);
                    remover(P, aux);
                    break;
            /*case 5:


                */
            case 6:
                    return (0);










			}
		}
	return 0;
}
int menu_principal()
{
    int escolha;
	printf("######################	\n");
	printf(" 1 - Novos Cadastro	\n");
	printf(" 2 - Consulta de Dados	\n");
	printf(" 3 - Atualizacao de Dados		\n");
	printf(" 4 - Remocao de Dados	\n");
	printf(" 5 - Exibica o Especial de Dados		\n");
	printf(" 6 - Sair \n");
	printf("######################\n\n");
	scanf("%d",&escolha);
	return (escolha);
}


int menu_consulta()
{
	int escolha;
	printf("############################################\n");
	printf("1 - Consulta atraves do numero de cadastro 	\n");
	printf("2 - Consulta atraves do nome do paciente 	\n");
	printf("3 - Consulta atraves do RG 					\n");
	printf("############################################\n\n");
	scanf("%d", &escolha);
	return (escolha);
}
void insercao_inicio(lista *LISTA, int cadastro)
{

		lista *old = LISTA->proximo;
		lista *novo = (lista*) malloc(sizeof (lista));
		novo->num_cadastro = cadastro;
		printf("Nome paciente \n");
		scanf("%s",novo->nome);
		printf("Numero RG \n");
		scanf("%d",&novo->rg);
		printf("Idade \n");
		scanf("%d",&novo->idade);
		printf("Endereço \n");
		scanf("%s",novo->endereco);
		printf("Nome do Posto de Saude\n");
		scanf("%s", novo->posto);
		printf("Data de vacinação (formato: DDMMAAAA\n");
		scanf("%s", novo->data);

		LISTA->proximo = novo;
		novo->proximo =  old;
}


void consulta_cadastro(lista *LISTA, int cadastro)
{
	bool achou = false;
	lista *aux = LISTA->proximo;
	while (aux != NULL)
	{
		if (aux->num_cadastro == cadastro)
		{
			printf("Nome paciente %s \n", aux->nome);
			printf("Numero RG %d\n", aux->rg);
			printf("Idade %d\n", aux->idade);
			printf("Endereço %s\n", aux->endereco);
			printf("Nome do Posto de Saude %s\n", aux->posto);
			printf("Data de vacinação %s\n\n", aux->data);
			achou = true;
		}
		aux = aux->proximo;
	}
	if (achou != true)
	{
		printf("Paciente nao encontrado \n\n");
	}
}
void consulta_nome(lista *LISTA, char nome[30])
{
	bool achou = false;
	lista *aux = LISTA->proximo;
	while (aux != NULL)
	{
		if (!strcmp(aux->nome, nome))
		{
			printf("Nome paciente %s \n", aux->nome);
			printf("Numero RG %d\n", aux->rg);
			printf("Idade %d\n", aux->idade);
			printf("Endereço %s\n", aux->endereco);
			printf("Nome do Posto de Saude %s\n", aux->posto);
			printf("Data de vacinação %s\n", aux->data);
			achou = true;
		}
		aux = aux->proximo;
	}
	if (achou != true)
	{
		printf("Paciente nao encontrado \n\n");
	}
}
void consulta_rg(lista *LISTA, int cadastro)
{
	bool achou = false;
	lista *aux = LISTA->proximo;
	while (aux != NULL)
	{
		if (aux->rg == cadastro)
		{
			printf("Nome paciente %s \n", aux->nome);
			printf("Numero RG %d\n", aux->rg);
			printf("Idade %d\n", aux->idade);
			printf("Endereço %s\n", aux->endereco);
			printf("Nome do Posto de Saude %s\n", aux->posto);
			printf("Data de vacinação %s\n", aux->data);
			achou = true;
		}
		aux = aux->proximo;
	}
	if (achou != true)
	{
		printf("Paciente nao encontrado \n\n");
	}
}
void atualizar(lista *LISTA, int cadastro)
{
    bool achou = false;
    lista *aux = LISTA->proximo;
    while ((aux != NULL) && (achou != true))
	{
		if (aux->num_cadastro == cadastro)
		{
		    printf("Atualize o nome \n");
			scanf("%s", aux->nome);
			printf("Atualize o RG \n");
			scanf("%d", &aux->rg);
			printf("Atualize a idade \n");
			scanf("%d", &aux->idade);
			printf("Atualize o Endereco \n");
			scanf("%s", aux->endereco);
			printf("Atualize o Posto de Saude\n");
			scanf("%s", aux->posto);
			printf("Atualize a data de vacinacao\n");
			scanf("%s", aux->data);
			achou = true;
		}
		aux = aux->proximo;
	}
	if (achou != true)
        printf("Cadastro não encontrado \n Nao foi possivel atualizar \n");
}

void remover(lista *LISTA, int cadastro)
{
    lista *anterior = LISTA;
    lista *aux = LISTA->proximo;


    while(aux != NULL && aux->num_cadastro != cadastro)
    {
        anterior = aux;
        aux = aux->proximo;


    }
    if (aux != NULL)
    {
        anterior->proximo = aux->proximo;
        free(aux);
    }
    else
        printf("Item nao encontrado \n\n");

}
void relatorio_1(lista *LISTA, char posto[20])
{
    int crescente = 0;
    lista *aux = LISTA->proximo;
    lista *aux2;
    int menor = aux->num_cadastro;

    while (aux != NULL)
    {
        while (aux2 != NULL)
        {
            if (aux2->num_cadastro < menor)
                menor = aux2->num_cadastro;
            aux2 = aux2->proximo;
        }
        if (!strcmp(aux->posto, posto) && (aux->num_cadastro ))
    }
}



