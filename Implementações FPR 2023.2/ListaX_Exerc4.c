/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 29/11/2023
	
	Lista de Exerc�cios X (Arquivos)
	
	Quest�o 04:
	Desenvolver uma fun��o que, dado um arquivo texto contendo n�meros, 
	determine se estes encontram-se ordenados crescentemente.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <limits.h>

//prot�tipos das fun��es
int verificarOrdenacao (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[20];
	int resposta;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a fun��o
	resposta = verificarOrdenacao (nomeArquivo);
	
	//exibindo o resultado
	switch (resposta)
	{
		case 0: printf ("\n\nOs elementos do arquivo %s nao estao ordenados.", nomeArquivo);
		        break;
		        
		case 1: printf ("\n\nOs elementos do arquivo %s estao ordenados.", nomeArquivo);
		        break;
	
		case -1:printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);       
	}
}

//implementa��o das fun��es
int verificarOrdenacao (char nomeArq[])
{
	//declara��o de vari�veis
	FILE* arquivo;
	int atual, anterior = INT_MIN;
	
	//tentando abriro arquivo
	arquivo = fopen (nomeArq, "r");
	
	//verificando se houve erro
	if (!arquivo)    //if (arq == NULL)
	{
		return -1;
	}
	else
	{
		while (fscanf (arquivo, "%d", &atual) != EOF)  //EOF = End Of File
		{
			//verificando se o n�mero atual � menor do que o anterior
			if (atual < anterior)
			{
				return 0;
			}
			
			//atualizando 'anterior'
			anterior = atual;
		}
		
		//fechar o arquivo
		fclose (arquivo);	
		
		return 1;	
	}
}
