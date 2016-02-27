/****************************************************************************************

Autor: Lucas Alves da Encarnação Oliveira
Componente Curricular : MI - Algoritmos I
Concluido em: 27/02/2016
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet, qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não seráo considerados para fins de avaliação

*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TOTAL 144
struct passageiro {
		int rg;
		int poltrona;
};
void iniciar(struct passageiro [][24]);
void venda(struct passageiro [][24]);
void listar_passageiros(struct passageiro [][24]);
void listar_poltronas(struct passageiro [][24]);
int conversor(char);
char desconversor(int);

int main (void)
	{
	    int total_venda = 0;
		int escolha=0;
		struct passageiro matriz[6][24];
		iniciar(matriz);
		while (true) //loop infinito, a única condição de parada é o RG -1 na função Venda
		{
			printf("####################################  \n");
            		printf("#  Escolha 1 p/ Venda		       #  \n");
            		printf("#  Escolha 2 p/ Listar Passageiros #  \n");
            		printf("#  Escolha 3 p/ Listar Poltronas   #  \n");
            		printf("#  Escolha 4 p/ Reiniciar          #  \n");
            		printf("####################################  \n");

			scanf("%d",&escolha);
			switch (escolha)
			{
				case 1:
				    //O números de vendas não deve exceder 144, já que só existem 144 poltronas para serem vendidas
				    	if (total_venda < TOTAL)
                    			{
                        			venda(matriz);
                        			total_venda++;
                    			}
                    			else
                        			printf("Vendas esgotadas \n");
						break;
				case 2:
				    //exibe todos os passageiros com RG e posição, respectivamente
					listar_passageiros(matriz);
					break;
				case 3:
				    //exibe a quantidade de poltronas disponíveis e ocupadas
					listar_poltronas(matriz);
					break;
				case 4:
				    // Reiniciar a matriz e zera o total de vendas
					iniciar(matriz);
					total_venda = 0;
					break;
			}
		}

	}
void iniciar(struct passageiro matriz [][24])
{
	int l;
	int c;
	for(l=0;l<6;l++)
		for(c=0;c<24;c++)
		{
			matriz[l][c].poltrona = 0;
			matriz[l][c].rg = 0;
		}
}
void venda(struct passageiro matriz [][24])
{
    char letra;
	int aux;
	int l=0;
	int c=0;
	printf(" Digite a fileira (A, B, C, D, E ou F) \n ");
	fflush(stdin);
	scanf("%c",&letra);
	l = conversor(letra); //função que converte a letra para seu respectivo correspondente
	while (l<1 || l>6)// validação da fileira
    	{
        	printf("Letra Invalida, digite novamente \n");
        	fflush(stdin);
        	scanf("%c",&letra);
        	l = conversor(letra);
    	}
    	printf("Digite a poltrona entre 1 e 24 \n");
	scanf("%d",&c);
	while (c<1 || c>24) // validação poltrona
    	{
        	printf("Numero invalido, digite novamente ");
        	scanf("%d",&c);
    	}
	while (matriz[l-1][c-1].poltrona != 0 ) // validação disponibilidade
	{
		printf(" Assento Ocupado \n");
		printf(" Digite a fileira (A, B, C, D, E ou F) n \n ");
		fflush(stdin);
        	scanf(" %c",&letra);
		l = conversor(letra);
		while (l<1 || l>6)
        	{
            		printf("Letra Invalida, digite novamente \n");
        	 	fflush(stdin);
            		scanf("%c",&letra);
            		l = conversor(letra);
        	}
        	printf("Digite a poltrona entre 1 e 24 \n");
		scanf("%d",&c);
		while (c<1 || c>24)
        	{
            		printf("Numero invalido, digite novamente \n");
            		scanf("%d",&c);
        	}
	}
	printf(" Digite o seu RG \n");
	scanf("%d", &aux);
	if (aux == -1) // condição de saida do loop infinito
		exit(0);
	else
		matriz[l-1][c-1].rg = aux;
		matriz[l-1][c-1].poltrona = 1;
}
void listar_poltronas(struct passageiro matriz [][24])
{
	int i = 0;
	int l;
	int c;
	for(l=0;l<6;l++)
		for(c=0;c<24;c++)
			if (matriz[l][c].poltrona != 0)
                i++;
	printf("A Quantidade de poltronas ocupadas e %d \n\n", i );
	printf("A Quantidade de poltronas vazias e %d \n\n", TOTAL - i);
}
void listar_passageiros(struct passageiro matriz [][24])
{
    char letra;
	int l;
	int c;
	for(l=0;l<6;l++)
		for(c=0;c<24;c++)
			if (matriz[l][c].poltrona != 0)
			{
			    letra = desconversor(l+1); //Transforma o numero em letra novamente para exibir
				printf("Passageiro (RG) = %d \n", matriz[l][c].rg);
				printf(" FILEIRA = %c | COLUNA = %d\n", letra,c+1);
				printf(" \n\n");
			}
}
int conversor(char letra)
{
    int l ;
    switch (letra)
        {
            case 'A':
                l = 1;
                break;
            case 'B':
                l = 2;
                break;
            case 'C':
                l = 3;
                break;
            case 'D':
                l = 4;
                break;
            case 'E':
                l = 5;
                break;
            case 'F':
                l = 6;
                break;
            default:
                l = 0;
                break;
        }
    return (l);
}
char desconversor(int l)
{
    char letra;
		switch (l)
                {
                    case 1:
                        letra = 'A';
                        break;
                    case 2:
                        letra = 'B';
                        break;
                    case 3:
                        letra = 'C';
                        break;
                    case 4:
                        letra = 'D';
                        break;
                    case 5:
                        letra = 'E';
                        break;
                    case 6:
                        letra = 'F';
                        break;
                }
    return (letra);
}


