/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 7: dados um arquivo texto (contendo n�meros) e um valor inteiro
	'n', remover do arquivo todas as ocorr�ncia de 'n' e retornar a quantidade
	de remo��es.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int remover (char nomeArquivo[], int numero);
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArq[20];
	int n, quant;
	
	//lendo os dados de entrada
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nomeArq);
	
	printf ("Valor a ser removido: ");
	scanf ("%d", &n);
	
	//chamando a fun��o
	quant = remover (nomeArq, n);
	
	//verificando o retorno da fun��o
	if (quant < 0)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n\nForam realizadas %d remocoes do numero %d no arquivo %s.", quant, n, nomeArq);
	}
}

//implementa��o das fun��es
int remover (char nomeArquivo[], int numero)
{
	//declara��o de vari�veis
	FILE *arq, *tmp;
	int valor, cont = 0;
	
	//abrindo os arquivos
	arq = fopen (nomeArquivo, "r");
	tmp = fopen ("temp.txt", "w");
	
	//verificando se houve erro na abertura dos arquivos
	if ((!arq) || (!tmp))
	{
		fclose (arq);
		fclose (tmp);
		
		return -1;
	}
	else
	{
		//lendo todos os valores do arquivo de origem
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se o valor lido deve ser copiado para o arquivo tempor�rio
			if (valor != numero)
			{
				fprintf (tmp, "%d\n", valor);
			}
			else
			{
				cont++;
			}
		}
		
		//fechando os arquivos
		fclose (arq);
		fclose (tmp);
		
		//copiando os dados do arquivo tempor�rio para o arquivo original
		copiarArquivo ("temp.txt", nomeArquivo);
		
		//retornando a quantidade de remo��es realizadas
		return cont;
	}
}

int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[])
{
	//declara��o de vari�veis
	FILE *arqO, *arqD;
	char caracter;
	
	//abrindo os arquivos
	arqO = fopen (nomeArqOrigem, "r");
	arqD = fopen (nomeArqDestino, "w");
	
	//verificando se houve erro na abertura
	if ((!arqO) || (!arqD))
	{
		fclose (arqO);
		fclose (arqD);
		
		return 0;
	}
	else
	{
		//lendo cada caracter do arquivo de origem ...
		while (fscanf (arqO, "%c", &caracter) != EOF)
		{
			fprintf (arqD, "%c", caracter);
		}
		
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}
