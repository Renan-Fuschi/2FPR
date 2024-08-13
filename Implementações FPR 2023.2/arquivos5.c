/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 5: dados um arquivo texto (contendo n�meros, um por linha) e 
	um valor inteiro 'n', determinar se 'n' existe ou n�o no arquivo.	 
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int buscar (char nomeArq[], int numero);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[20];
	int numero, retorno;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	gets (nomeArquivo);
	
	//obtendo o n�mero a ser buscado no arquivo
	printf ("Entre com o numero a ser buscado: ");
	scanf ("%d", &numero);
	
	//chamando a fun��o
	retorno = buscar (nomeArquivo, numero);
	
	//testando o retorno da fun��o
	switch (retorno)
	{
		case -1: printf ("\n\nErro na abertura do arquivo %s!", nomeArquivo);
		         break;
		case  0: printf ("\n\nO valor %d NAO foi encontrado no arquivo %s.", numero, nomeArquivo);
		         break;
		case  1: printf ("\n\nO valor %d foi encontrado no arquivo %s.", numero, nomeArquivo);
	}	
}

//implementa��o das fun��es

/*
   Verifica se 'numero' existe no arquivo de nome 'nomeArq'.
   Retornar�:
   		0	Se o n�mero n�o existir no arquivo
   		1	Se o n�mero existir no arquivo
   		-1	Se ocorrer erro na abertura do arquivo
*/
int buscar (char nomeArq[], int numero)
{
	//declara��o de vari�veis
	FILE* arquivo;
	int valor;
	
	//abrindo o arquivo
	arquivo = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	//if (arquivo == NULL)   OU
	if (!arquivo)
	{
		return -1;
	}
	else
	{
		//lendo todos os valores que est�o no arquivo
		while (fscanf (arquivo, "%d", &valor) != EOF)  //EOF - end of file
		{
			//verificando se o valor lido � o n�mero sendo buscado
			if (valor == numero)
			{
				//fechando o arquivo
				fclose (arquivo);
				
				return 1;
			}			
		}
		
		//fechando o arquivo
		fclose (arquivo);
		
		//se chegou at� aqui, conclui-se que o n�mero n�o existe no arquivo
		return 0;
	}
}
