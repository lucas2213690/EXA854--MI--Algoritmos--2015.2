#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void desconversor(char nome[], int sigla );
void desconversor2(char nome[], int sigla );
int main(void)
{	
	char nome_arquivo[20];
	int dias;
	char mes[3];
	int a = 20;
	int d;
	int c;
	int h;
	char nome_dia[3];
	FILE *file;
	srand( (unsigned)time(NULL) );
	printf("Deseja gerar os quantos dias de arquivos\n");
	scanf("%d",&dias);
	printf("De qual mes   FORMATO - 01 (Janeiro), 02 (Fevereiro) e etc...\n");
	scanf("%s",mes);
	for(d = 0; d < dias; d++)
	{
	    for(c = 0; c < 10; c++)
	    {
		  desconversor(nome_arquivo, c);
		  desconversor2(nome_dia, d);
		  strcat(nome_arquivo, "2016");
		  strcat(nome_arquivo, mes);
		  strcat(nome_arquivo, nome_dia);
		  strcat(nome_arquivo, ".txt");
		  file = fopen(nome_arquivo, "w");
		  for(h = 0; h < 24; h++)
		  {
		      fprintf(file,"%d %.2f %.2f %.2f %d %.2f %s\n", h, (rand() % 55) * 1.2, 1000 + (rand() %50) * 1.1, (rand() % 101) * 0.98, 1 + (rand() % 10), (rand() % 101) * 1.5, "SE");   
		  
		  }
		  fclose(file);
	    }
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
void desconversor2(char nome[],int sigla)
{
		
	switch (sigla)
	{
		case 0:
			strcpy(nome, "01");
			break;
		case 1:
			strcpy(nome, "02");
			break;
		case 2:
			strcpy(nome, "03");
			break;
		case 3:
			strcpy(nome, "04");
			break;
		case 4:
			strcpy(nome, "05");
			break;
		case 5:
			strcpy(nome, "06");
			break;
		case 6:
			strcpy(nome, "07");
			break;
		case 7:
			strcpy(nome, "08");
			break;
		case 8:
			strcpy(nome, "09");
			break;
		case 9:
			strcpy(nome, "10");
			break;
		case 10:
			strcpy(nome, "11");
			break;
		case 11:
			strcpy(nome, "12");
			break;
		case 12:
			strcpy(nome, "13");
			break;
		case 13:
			strcpy(nome, "14");
			break;
		case 14:
			strcpy(nome, "15");
			break;
		case 15:
			strcpy(nome, "16");
			break;
		case 16:
			strcpy(nome, "17");
			break;
		case 17:
			strcpy(nome, "18");
			break;
		case 18:
			strcpy(nome, "19");
			break;
		case 19:
			strcpy(nome, "20");
			break;
		case 20:
			strcpy(nome, "21");
			break;
		case 21:
			strcpy(nome, "22");
			break;
		case 22:
			strcpy(nome, "23");
			break;
		case 23:
			strcpy(nome, "24");
			break;
		case 24:
			strcpy(nome, "25");
			break;
		case 25:
			strcpy(nome, "26");
			break;
		case 26:
			strcpy(nome, "27");
			break;
		case 27:
			strcpy(nome, "28");
			break;
		case 28:
			strcpy(nome, "29");
			break;
		case 29:
			strcpy(nome, "30");
			break;
	}
}
