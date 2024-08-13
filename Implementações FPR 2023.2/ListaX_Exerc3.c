/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 29/11/2023
	
	Lista de Exerc�cios X (Arquivos)
	
	Quest�o 03:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero 
	de letras existentes no mesmo (entendendo que no arquivo podem existir 
	letras, algarismos e s�mbolos).
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//prot�tipos das fun��es
int numLetras (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[20];
	int quant;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a fun��o
	quant = numLetras (nomeArquivo);
	
	//exibindo o resultado
	if (quant != -1)
	{
		printf ("\n\nForam encontradas %d letras no arquivo %s.", quant, nomeArquivo);
	}
	else
	{
		printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);
	}
}

//implementa��o das fun��es
int numLetras (char nomeArq[])
{
	//declara��o de vari�veis
	FILE* arquivo;
	int cont = 0;
	char caracter;
	
	//tentando abriro arquivo
	arquivo = fopen (nomeArq, "r");
	
	//verificando se houve erro
	if (!arquivo)    //if (arq == NULL)
	{
		return -1;
	}
	else
	{
		while (fscanf (arquivo, "%c", &caracter) != EOF)  //EOF = End Of File
		{
			//colocando o caracter lido para mai�scula
			caracter = toupper (caracter);
			
			//verificando se o caracter lido � uma letra
			if ((caracter >= 'A') && (caracter <= 'Z'))
			{
				cont++;
			}
		}
		
		//fechar o arquivo
		fclose (arquivo);
		
		return cont;
	}
}
