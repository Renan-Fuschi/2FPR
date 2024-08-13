/*
	FAETERJ-Rio
	Fundamentos de Programa��o
	Manh� - 2/2023
	Data: 13/09/2023
	
	Lista de Exerc�cios VI:
	
	Quest�o 01:
	Considerando a exist�ncia de uma matriz de inteiros M, de ordem N (ou seja, o n� 
	de linhas e o n� de colunas s�o iguais a N), onde N � uma constante, desenvolver 
	uma fun��o que retorne 1 se a seguinte regra for atendida por M (caso contr�rio, 
	o valor 0 dever� ser retornado):
	
		- A soma dos elementos da diagonal principal deve ser igual � soma dos elementos que 
		  est�o acima desta diagonal, assim como � soma dos elementos abaixo da diagonal.

	Exemplo 1:

	Para a seguinte matriz, a fun��o retornar� 1: 

		6	3	1	2	6	
		1	3	5	4	2	
		3	4	4	2	2	
		5	9	1	9	3	
		4	0	2	1	8	

	Exemplo 2:

	Para a seguinte matriz, a fun��o retornar� 0: 
	
		1	8	5	9	4	
		2	5	4	6	5	
		4	1	2	3	6	
		4	5	5	8	7	
		4	2	5	6	9
*/

//importa��o de bibliotecas
#include <stdio.h>

//declara��o dos prot�tipos
int verificarMatriz (int n, int matriz[n][n]);

//main
void main ()
{
	//declara��o de vari�veis	
	int mat1[5][5] = {{6,3,1,2,6}, 
	                  {1,3,5,4,2},
	                  {3,4,4,2,2},
					  {5,9,1,9,3},
					  {4,0,2,1,8}};	
					  
	int mat2[5][5] = {{1,8,5,9,4}, 
	                  {2,5,4,6,5},
	                  {4,1,2,3,6},
					  {4,5,5,8,7},
					  {4,2,5,6,9}};	
					  
	//chamando a fun��o para a primeira matriz
	if (verificarMatriz (5, mat1) == 1)
	{
		printf ("As somas dos elementos da matriz 1 sao iguais!\n\n");
	}
	else
	{
		printf ("As somas dos elementos da matriz 1 NAO sao iguais!\n\n");
	}
	
	//chamando a fun��o para a segunda matriz
	if (verificarMatriz (5, mat2) == 1)
	{
		printf ("As somas dos elementos da matriz 2 sao iguais!\n\n");
	}
	else
	{
		printf ("As somas dos elementos da matriz 2 NAO sao iguais!\n\n");
	}
}

//implementa��o das fun��es
int verificarMatriz (int n, int matriz[n][n])
{
	//declara��o de vari�veis
	int i, j, aux, somarDiagonal = 0, acimaDiagonal = 0, abaixoDiagonal = 0;
	
	//somando os elementos da diagonal principal
	for (i=0;i<n;i++)
	{
		somarDiagonal += matriz[i][i];	
	}
	
	//somando os elementos acima da diagonal principal
	for(i=0;i<n-1;i++)
	{
    	aux =i+1;
    	for(j=aux;j<n;j++)
		{
    		acimaDiagonal += matriz[i][j];
		}
	}
	
	//somando os elementos abaixo da diagonal principal
	for(i=1;i<n;i++)
	{
    	aux = i-1;
    	for(j=0;j<=aux;j++)
		{
    		abaixoDiagonal += matriz[i][j];
		}
	}
	
	//verificando se as tr�s somas s�o iguais
	if ((somarDiagonal == acimaDiagonal) && (acimaDiagonal == abaixoDiagonal))
	{
		return 1;		
	}
	else
	{
		return 0;
	}
}

