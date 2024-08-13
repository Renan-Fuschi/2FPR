/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 05/10/2023
	
	Arquivos
	
	Exemplo 2: adicionando valores a um arquivo texto existente
	 
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declara��o de vari�veis
	int i, inf, sup;
	FILE* arquivo;	//Passo 1: declarar uma vari�vel FILE* representando o arquivo
	char nomeArquivo[20];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser criado: ");
	gets (nomeArquivo);
	
	//obtendo os limites dos valores que ser�o escritos no arquivo
	printf ("Entre com os valores minimo e maximo a serem escritos no arquivo %s: ", nomeArquivo);
	scanf ("%d %d", &inf, &sup);
			
	//Passo 2: abrir o arquivo, associando-o com um caminho
	arquivo = fopen (nomeArquivo, "a");   //w - write    r - read    a - append
	
	if (arquivo == NULL)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{			
		for (i=inf;i<=sup;i++)
		{
			fprintf (arquivo, "%d\n", i);   //Passo 3: manipular o arquivo
		}
		
		fclose (arquivo); //fechando o arquivo
	}
}
