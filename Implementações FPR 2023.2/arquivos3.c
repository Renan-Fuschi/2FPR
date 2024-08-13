/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 05/10/2023
	
	Arquivos
	
	Exemplo 3: lendo valores de um arquivo
	 
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declara��o de vari�veis
	FILE* arquivo;	//Passo 1: declarar uma vari�vel FILE* representando o arquivo
	char nomeArquivo[20];
	char caracter;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	gets (nomeArquivo);
		
	//Passo 2: abrir o arquivo, associando-o com um caminho
	arquivo = fopen (nomeArquivo, "r");   //w - write    r - read    a - append
	
	if (arquivo == NULL)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{			
		while (fscanf (arquivo, "%c", &caracter) != EOF)  //Passo 3: manipular o arquivo
		{
			printf ("%c", caracter);   //EOF - end of file
		}
		
		fclose (arquivo); //fechando o arquivo
	}
}
