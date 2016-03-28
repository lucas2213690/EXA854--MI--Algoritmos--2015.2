/****************************************************************************************
Autor: Lucas Alves da Encarnação Oliveira
Componente Curricular : MI - Algoritmos I
Concluido em: XX/04/2016
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

#define CIDADE 10
#define DIA 30
#define HORA 24

struct dados{	// Estrutura de Dados de Entrada
	// a hora nao e armazenada, ja que tem um indice para isso
    float temp;
    float pressao;
    float umidade;
    float prec;
    float km;
    char vento[3];
};
struct saida{		//Estrutura de Dados de Saida
	float temp;
	int cidade;
};

void selection_sort(struct saida []);
void leitura(struct dados [][DIA][HORA], int, char [],char []);
void temp_minima(struct dados [][DIA][HORA], int);
void temp_media(struct dados [][DIA][HORA], int);
void temp_max(struct dados [][DIA][HORA], int);
void medias(struct dados [][DIA][HORA], int);
void consulta(struct dados [][DIA][HORA], char[], int, int );
void desconversor(char [], int);
int conversor(char []);

int main (void)
{
	int escolha = 0;
	char sigla[3];
	char string_dia[3];
	char mes[3];
	int count=0;
	int dia;
	int hora;
	struct dados matriz[CIDADE][DIA][HORA];
	while(true)
	{
		printf("######################	\n");
		printf(" 1 - Importar dados	\n");
		printf(" 2 - Exportar dados	\n");
		printf(" 3 - Consultar		\n");
		printf(" 4 - Medias Diarias	\n");
		printf(" 5 - Sair		\n");
		printf("######################	\n");
		scanf("%d",&escolha);
		switch (escolha)
		{
			case 1:
				printf("Digite de qual dia deseja realizar a leitura, Exemplo: 02,05...\n");
				scanf(" %s",string_dia);
				printf("Digite qual mes  Exemplo:08,09....\n");
				scanf(" %s",mes);

				if (count <= 29)
					leitura(matriz, count, string_dia, mes);
				else
				{
					count = 0;
					leitura(matriz, count, string_dia, mes);
				}
				count++;

				break;
			case 2:
				printf("Digite de qual dia deseja exportar os dados");
				scanf("%d",&dia);
				temp_minima(matriz, dia);
				temp_max(matriz, dia);
				temp_media(matriz, dia);
				printf("Arquivos gerados com sucesso\n");
				break;
			case 3:
				printf("Informe a sigla, o dia e a hora que deseja consultar, separado por um espaco\n");
				printf("Exemplo: SSA 13 22");
				__fpurge(stdin);
				scanf("%s %d %d",sigla ,&dia ,&hora);
				consulta(matriz, sigla, dia, hora);
				break;
			case 4:
				printf("Digite o dia em que deseja gerar as medias");
				scanf("%d",&dia);
				medias(matriz, dia);
			case 5:
				return 0;
			default:
				printf("Comando Invalido \n");
				break;
		}
	}
}
void leitura(struct dados matriz[][DIA][HORA], int count,char dia[],char mes[])  // testado
{
	char nome_arquivo[20];
	int hora = 0;
	FILE *file;
	int i;
	int aux;
	for(i = 0;i < 10; i++){
		desconversor(nome_arquivo,i);
		strcat(nome_arquivo, "2016");
		strcat(nome_arquivo, mes);
		strcat(nome_arquivo, dia);
		strcat(nome_arquivo, ".txt");


		file = fopen(nome_arquivo, "r");
		if (file == NULL){
			printf("Arquivo nao encontrado");
			exit(1);
		}
		while( (fscanf(file,"%d %f %f %f %f %f %s\n", &aux, &matriz[i][count][hora].temp, &matriz[i][count][hora].pressao, &matriz[i][count][hora].umidade,&matriz[i][count][hora].prec, &matriz[i][count][hora].km, matriz[i][count][hora].vento))!=EOF ){
		hora++;
	}
	fclose(file);

	}

}
void consulta(struct dados matriz[][DIA][HORA], char sigla[3], int dia, int hora)
{
	int cidade = conversor(sigla);
	printf("Temperatura: |%f|,  Pressao Atmosferica: |%f|,  Umidade: |%f|,  Precipitacao: |%f|, Km: |%f|,  Vento:  |%s|",matriz[cidade][dia][hora].temp,matriz[cidade][dia][hora].pressao,matriz[cidade][dia][hora].umidade,matriz[cidade][dia][hora].prec,matriz[cidade][dia][hora].km,matriz[cidade][dia][hora].vento);

}
void temp_minima(struct dados matriz[][DIA][HORA], int dia_escolhido)
{
	FILE *file;
	int minima;
	char nome[3];
	char temperatura[10];
	struct saida vet[10];
	int c;
	int aux = 0;
	int h;
	for(c = 0;c < 10; c++)	// zerando o vetor
	{
		vet[c].temp = 0;
		vet[c].cidade = c;
	}
	for(c = 0;c < 10; c++)
	{
		minima = matriz[c][dia_escolhido][0].temp;
		for(h = 0; h < 24; h++)
		{
			if (matriz[c][dia_escolhido][h].temp < minima)
				minima = matriz[c][dia_escolhido][h].temp;
		}
		vet[c].temp = minima;
	}
	selection_sort(vet);


	file = fopen("temp_minima.txt", "w"); // cria um arquivo
	for(c = 0;c < 10; c++)
	{
		desconversor(nome,vet[c].cidade);
		fprintf(file,"%s %.2f \n", nome,vet[c].temp);	//Escreve a sigla da cidade e a temperatura media
	}
	fclose(file);
}
void temp_media(struct dados matriz[][DIA][HORA], int dia_escolhido)
{
	FILE *file;
	char nome[3];
	char temperatura[10];
	struct saida vet[10];
	int c;
	int aux = 0;
	int h;
	for(c = 0;c < 10; c++)	// zerando o vetor
	{
		vet[c].temp = 0;
		vet[c].cidade = c;
	}

	for(c = 0;c < 10; c++)
		for(h = 0;h < 24; h++)
			vet[c].temp += matriz[c][dia_escolhido][h].temp;


	selection_sort(vet);


	file = fopen("temp_media.txt", "w"); // cria um arquivo
	for(c = 0;c < 10; c++)
	{
		desconversor(nome, vet[c].cidade);
		fprintf(file,"%s %.2f \n",nome,vet[c].temp/24);	//Escreve a sigla da cidade e a temperatura media
	}
	fclose(file);
}
void temp_max(struct dados matriz[][DIA][HORA], int dia_escolhido)
{
	FILE *file;
	int maxima;
	char nome[3];
	char temperatura[10];
	struct saida vet[10];
	int c;
	int aux = 0;
	int h;
	for(c = 0;c < 10; c++)	// zerando o vetor
	{
		vet[c].temp = 0;
		vet[c].cidade = c;
	}
	for(c = 0;c < 10; c++)
	{
		maxima = matriz[c][dia_escolhido][0].temp;
		for(h = 0;h < 24; h++)
		{
			if (matriz[c][dia_escolhido][h].temp > maxima)
				maxima = matriz[c][dia_escolhido][h].temp;
		}
		vet[c].temp = maxima;
	}
	selection_sort(vet);


	file = fopen("temp_maxima.txt", "w"); // cria um arquivo
	for(c = 0; c < 10; c++)
	{
		desconversor(nome,vet[c].cidade);
		fprintf(file,"%s %.2f \n",nome,vet[c].temp);	//Escreve a sigla da cidade e a temperatura media
	}
	fclose(file);


}
void medias(struct dados matriz[][DIA][HORA], int dia)
{
	FILE *file;
	char sigla[3];
	int i;
	int h;
	float media_temp = 0;
	float media_pressao = 0;
	float media_umidade = 0;
	float media_prec = 0;
	file = fopen("medias_diarias.txt", "w");
	for(i = 0; i < 10; i++)
	{
	    desconversor(sigla, i);
	    for(h = 0; h < 24; h++)
	    {
	      media_temp += matriz[i][dia][h].temp;
	      media_pressao += matriz[i][dia][h].pressao;
	      media_umidade += matriz[i][dia][h].umidade;
	      media_prec += matriz[i][dia][h].prec;
	    }
	    fprintf(file,"CIDADE: %s  Temperatura: %.2f  Pressao: %.2f  Umidade: %.2f  Precipitacao: %.2f \n", sigla, media_temp/24, media_pressao/24, media_umidade/24, media_prec/24);
	  
	}
	fclose(file);

}
int conversor(char sigla[])
{
		if (!strcmp(sigla,"SSA"))
			return 0;
		else if (!strcmp(sigla, "FSA"))
			return 1;
		else if (!strcmp(sigla, "VDC"))
			return 2;
		else if (!strcmp(sigla, "CAM"))
			return 3;
		else if (!strcmp(sigla, "ITA"))
			return 4;
		else if (!strcmp(sigla, "JUA"))
			return 5;
		else if (!strcmp(sigla, "LDF"))
			return 6;
		else if (!strcmp(sigla, "ILH"))
			return 7;
		else if (!strcmp(sigla, "JEQ"))
			return 8;
		else if (!strcmp(sigla, "TDF"))
			return 9;
}
void desconversor(char nome[],int sigla)
{
	switch (sigla)
	{
		case 0:
			strcpy(nome, "SSA_");
			break;
		case 1:
			strcpy(nome, "FSA_");
			break;
		case 2:
			strcpy(nome, "VDC_");
			break;
		case 3:
			strcpy(nome, "CAM_");
			break;
		case 4:
			strcpy(nome, "ITA_");
			break;
		case 5:
			strcpy(nome, "JUA_");
			break;
		case 6:
			strcpy(nome, "LDF_");
			break;
		case 7:
			strcpy(nome, "ILH_");
			break;
		case 8:
			strcpy(nome, "JEQ_");
			break;
		case 9:
			strcpy(nome, "TDF_");
			break;
	}
}
void selection_sort(struct saida a[])
{

    int i, j, min,aux;

    for (i = 0; i < 10; i++)
    {
        min = i;
        for (j = i + 1; j < 10; j++)
        {
            if (a[j].temp < a[min].temp)
                min = j;
        }
		//troca a temperatura
		aux = a[i].temp;
		a[i].temp = a[min].temp;
		a[min].temp = aux;
		//o campo CIDADE tambem acompanha a troca para nao se perder
		aux = a[i].cidade;
		a[i].cidade = a[min].cidade;
		a[min].cidade = aux;
    }
}


