#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define POLITICOS 4
#define EMPRESAS 4

// Estrutura de Dados para armazenar dados dos Politicos
struct politico{
	int indice;
	float valor[EMPRESAS];
	float com_juros[EMPRESAS];
	float juros_recebidos[EMPRESAS];
	int parcela[EMPRESAS];
};

void leitura(struct politico [], float *,  char []);
void calculo_propina(struct politico [], float, char []);
void total_propina_empresas(struct politico [], char []);
void politico_maior_propina(struct politico [], float, char []);
void politico_menor_propina(struct politico [], float, char []);
void empresa_maior_propina(struct politico [], float, char []);
void empresa_menor_propina(struct politico [], float, char []);
void media_propina_politico(struct politico [], char []);
void media_propina_empresa(struct politico [], char []);
float juros_compostos(float, int, float);

int main (void)
{
	char arquivo_entrada[25];
	char arquivo_saida[25];
	int escolha = 0;
	float juros = 0;
	struct politico politicos[POLITICOS];

	while(true)
	{
		printf("######################	\n");
		printf(" 1 - Importar dados	\n");
		printf(" 2 - Exportar dados	\n");
		printf("######################	\n");
		scanf("%d",&escolha);
		switch (escolha)
		{
			case 1:
				printf("Digite o nome do arquivo de entrada\n");
				fflush(stdin);
				scanf(" %s",arquivo_entrada);
				leitura(politicos, &juros, arquivo_entrada);
				break;
			case 2:
				printf("Digite o nome do arquivo de saida\n");
				fflush(stdin);
				scanf(" %s",arquivo_saida);
				calculo_propina(politicos, juros, arquivo_saida);
				total_propina_empresas(politicos, arquivo_saida);
				politico_maior_propina(politicos, juros, arquivo_saida);
				politico_menor_propina(politicos, juros, arquivo_saida);
				empresa_maior_propina(politicos, juros, arquivo_saida);
				empresa_menor_propina(politicos, juros, arquivo_saida);
				media_propina_politico(politicos, arquivo_saida);
				media_propina_empresa(politicos, arquivo_saida);
				printf("Arquivos gerados com sucesso\n");
				break;
				
			default:
				printf("Comando Invalido \n");
				break;
		}
	}
}
void leitura(struct politico politicos[], float *juros,  char nome[])
{
	int linhas = 0;
	FILE *file;
	file = fopen(nome, "r");
	if (file == NULL){
		printf("Arquivo nao encontrado \n");
		exit(1);
	}
	while (linhas < 9){
		// Primeira linha
		if (linhas == 0){
			fscanf(file, "%f \n", juros);
		}
		else if (linhas > 0 && linhas <= 4){
			fscanf(file, "%d %f %f %f %f\n", &politicos[linhas - 1].indice, &politicos[linhas - 1].valor[0], &politicos[linhas - 1].valor[1], &politicos[linhas - 1].valor[2], &politicos[linhas - 1].valor[3]);
		}
		else if (linhas > 4 && linhas < 9){
			fscanf(file, "%d %d %d %d\n", &politicos[linhas - 5].parcela[0], &politicos[linhas - 5].parcela[1], &politicos[linhas - 5].parcela[2], &politicos[linhas - 5].parcela[3]);
		}

		linhas++;
	}
	
	fclose(file);
	
	printf("%f \n", *juros);
	
	for(int i = 0; i < 4; i++){
		printf("%d %f %f %f %f \n",politicos[i].indice, politicos[i].valor[0], politicos[i].valor[1], politicos[i].valor[2], politicos[i].valor[3]);   
	}
	
	for(int i = 0; i < 4; i++){
		printf("%d %d %d %d \n", politicos[i].parcela[0], politicos[i].parcela[1], politicos[i].parcela[2], politicos[i].parcela[3]);   
	}
	
		
}


float juros_compostos(float valor, int tempo, float taxa)
{
      float montante = valor * pow((1 + (taxa / 100)), tempo);
      return montante;
}

void calculo_propina(struct politico politicos[],float juros, char arquivo_saida []){
	
	FILE *file = fopen(arquivo_saida, "a");
	
	for(int i = 0; i < 4; i++){
		for(int j = 0;j < 4; j++){
			politicos[i].com_juros[j] = juros_compostos(politicos[i].valor[j], politicos[i].parcela[j], juros);	
		}
		fprintf(file, "%d %.2f %.2f %.2f %.2f %.2f \n", i +1, politicos[i].com_juros[0] , politicos[i].com_juros[1], politicos[i].com_juros[2], politicos[i].com_juros[3], politicos[i].com_juros[0] + politicos[i].com_juros[1] + politicos[i].com_juros[2] + politicos[i].com_juros[3]);
	}
	
	fclose(file);
	
}

void total_propina_empresas(struct politico politicos[], char arquivo_saida []){
	float propina_com_juros[3];
	FILE *file = fopen(arquivo_saida, "a");
	
	for(int i = 0; i < 4; i++){
		propina_com_juros[i] = politicos[0].com_juros[i] + politicos[1].com_juros[i] + politicos[2].com_juros[i] + politicos[3].com_juros[i];
	}
	
	fprintf(file, "\n%.2f %.2f %.2f %.2f \n", propina_com_juros[0], propina_com_juros[1], propina_com_juros[2], propina_com_juros[3]);
	
	fclose(file);
}


void politico_maior_propina(struct politico politicos [], float juros, char arquivo_saida []){
	float propina_com_juros[3];
	float propina_sem_juros;
	float max;
	int indice = 1;
	FILE *file = fopen(arquivo_saida, "a");
	
	for(int i = 0; i < 4; i++){
		propina_com_juros[i] = politicos[i].com_juros[0] + politicos[i].com_juros[1] + politicos[i].com_juros[2] + politicos[i].com_juros[3];
	}
	
	
	max = propina_com_juros[0];
	
	for(int i = 0; i < 4; i++){
		if (propina_com_juros[i] > max){
			max = propina_com_juros[i];
			indice = i + 1;
		}
	}
	
	propina_sem_juros = politicos[indice -1].valor[0] + politicos[indice - 1].valor[1] + politicos[indice - 1].valor[2] + politicos[indice - 1].valor[3];
	
	fprintf(file, "\n%d %.2f %.2f %.2f \n", indice, propina_sem_juros, max, max - propina_sem_juros);
	
	fclose(file);
	
}

void politico_menor_propina(struct politico politicos [], float juros, char arquivo_saida []){
	float propina_com_juros[3];
	float propina_sem_juros;
	float min;
	int indice = 1;
	FILE *file = fopen(arquivo_saida, "a");
	
	for(int i = 0; i < 4; i++){
		propina_com_juros[i] = politicos[i].com_juros[0] + politicos[i].com_juros[1] + politicos[i].com_juros[2] + politicos[i].com_juros[3];
	}
	
	
	min = propina_com_juros[0];
	
	for(int i = 0; i < 4; i++){
		if (propina_com_juros[i] < min){
			min = propina_com_juros[i];
			indice = i + 1;
		}
	}
	
	propina_sem_juros = politicos[indice - 1].valor[0] + politicos[indice - 1].valor[1] + politicos[indice - 1].valor[2] + politicos[indice - 1].valor[3];
	
	fprintf(file, "\n%d %.2f %.2f %.2f \n", indice, propina_sem_juros, min, min - propina_sem_juros);
	
	fclose(file);
	
}

void empresa_maior_propina(struct politico politicos [], float juros, char arquivo_saida []){
	float propina_com_juros[3];
	float propina_sem_juros;
	float max;
	int indice = 1;
	FILE *file = fopen(arquivo_saida, "a");
	
	for(int i = 0; i < 4; i++){
		propina_com_juros[i] = politicos[0].com_juros[i] + politicos[1].com_juros[i] + politicos[2].com_juros[i] + politicos[3].com_juros[i];
	}
	
	
	max = propina_com_juros[0];
	
	for(int i = 0; i < 4; i++){
		if (propina_com_juros[i] > max){
			max = propina_com_juros[i];
			indice = i + 1;
		}
	}
	
	propina_sem_juros = politicos[0].valor[indice -1] + politicos[1].valor[indice - 1] + politicos[2].valor[indice - 1] + politicos[3].valor[indice - 1];
	
	fprintf(file, "\n%d %.2f %.2f %.2f \n", indice, propina_sem_juros, max, max - propina_sem_juros);
	
	fclose(file);
	
}

void empresa_menor_propina(struct politico politicos [], float juros, char arquivo_saida []){
	float propina_com_juros[3];
	float propina_sem_juros;
	float min;
	int indice = 1;
	FILE *file = fopen(arquivo_saida, "a");
	
	for(int i = 0; i < 4; i++){
		propina_com_juros[i] = politicos[0].com_juros[i] + politicos[1].com_juros[i] + politicos[2].com_juros[i] + politicos[3].com_juros[i];
	}
	
	
	min = propina_com_juros[0];
	
	for(int i = 0; i < 4; i++){
		if (propina_com_juros[i] < min){
			min = propina_com_juros[i];
			indice = i + 1;
		}
	}
	
	propina_sem_juros = politicos[0].valor[indice -1] + politicos[1].valor[indice - 1] + politicos[2].valor[indice - 1] + politicos[3].valor[indice - 1];
	
	fprintf(file, "\n%d %.2f %.2f %.2f \n", indice, propina_sem_juros, min, min - propina_sem_juros);
	
	fclose(file);
	
}

void media_propina_politico(struct politico politicos[], char arquivo_saida []){
	float sum = 0;
	
	FILE *file = fopen(arquivo_saida, "a");
	
	
	for (int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
					sum = sum + politicos[i].com_juros[j];
			}
			fprintf(file, "%d %.2f \n", politicos[i].indice, sum/4);
			sum = 0;
	}
	
	fclose(file);
}

void media_propina_empresa(struct politico politicos[], char arquivo_saida []){
	float sum = 0;
	
	FILE *file = fopen(arquivo_saida, "a");
	
	fprintf(file, "\n");
	
	for (int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
					sum = sum + politicos[j].com_juros[i];
			}
			fprintf(file, "%d %.2f \n", i+1, sum/4);
			sum = 0;
	}
	fclose(file);
}





