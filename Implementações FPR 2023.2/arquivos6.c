/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 6: copiar o conte�do de um arquivo para outro.	 
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeOrigem[20], nomeDestino[20];
		
	//obtendo o nome do arquivo de origem
	printf ("Entre com o nome do arquivo a ser copiado: ");
	gets (nomeOrigem);
	
	//obtendo o nome do arquivo de destino
	printf ("Entre com o nome do novo arquivo: ");
	gets (nomeDestino);
	
	//chamando a fun��o
	if (copiarArquivo (nomeOrigem, nomeDestino) == 1)
	{
		printf ("\n\nCopia realizada com sucesso!");
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos! Copia nao realizada.");
	}
}

//implementa��o das fun��es
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
