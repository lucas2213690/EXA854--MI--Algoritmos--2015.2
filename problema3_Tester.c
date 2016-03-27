#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void desconversor(char nome[], int sigla );
int main(void)
{	
	char nome_arquivo[20];
	int dias;
	int a = 20;
	int i;
	int h;
	FILE *file;
	srand( (unsigned)time(NULL) );
	printf("Deseja gerar os arquivos até que dia \n");
	scanf("%d",&dias);
	for(i = 0; i < 4; i++)
	{
		desconversor(nome_arquivo, i);
		strcat(nome_arquivo, "2016");
		strcat(nome_arquivo, "04");
		strcat(nome_arquivo, "01");
		strcat(nome_arquivo, ".txt");
		file = fopen(nome_arquivo, "w");
		for(h = 0; h < 24; h++)
		{
		    fprintf(file,"%d %.2f %.2f %.2f %d %.2f %s\n", h, (rand() % 55) * 1.2, 1000 + (rand() %50) * 1.1, (rand() % 101) * 0.98, 1 + (rand() % 10), (rand() % 101) * 1.5, "SE");   
		  
		}
		fclose(file);
	}
return 0;




return 0;
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
	}
}
