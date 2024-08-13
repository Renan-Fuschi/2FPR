/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 4: lendo valores de um arquivo (por�m, utilizando fun��o)
	 
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int lerArquivo (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[20];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	gets (nomeArquivo);
	
	//chamando a fun��o
	if (lerArquivo (nomeArquivo) == 0)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{			
		printf ("\n\nLeitura realizada com sucesso!");
	}
}

//implementa��o das fun��es
int lerArquivo (char nomeArq[])
{
	//declara��o de vari�veis
	FILE* arquivo;	//Passo 1: declarar uma vari�vel FILE* representando o arquivo
	char caracter;
		
	//Passo 2: abrir o arquivo, associando-o com um caminho
	arquivo = fopen (nomeArq, "r");   //w - write    r - read    a - append
	
	//verificando se houve erro na abertura do arquivo
	if (arquivo == NULL)
	{
		return 0;
	}
	else
	{			
		while (fscanf (arquivo, "%c", &caracter) != EOF)  //Passo 3: manipular o arquivo
		{
			printf ("%c", caracter);   //EOF - end of file
		}
		
		fclose (arquivo); //fechando o arquivo
		
		return 1;
	}	
}
