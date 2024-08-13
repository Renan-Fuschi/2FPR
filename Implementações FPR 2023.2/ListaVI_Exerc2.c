/*
	FAETERJ-Rio
	Fundamentos de Programa��o
	Manh� - 2/2023
	Data: 13/09/2023
	
	Lista de Exerc�cios VI:
	
	Quest�o 02:
	Dada uma matriz MLxC, onde L e C s�o constantes, desenvolver uma fun��o 
	que "troque" os elementos de duas colunas c1 e c2, respeitadas as 
	seguintes regras:

		a.	A troca s� ser� poss�vel se as colunas c1 e c2 existirem na 
		    matriz. Caso existam, a troca ser� realizada e o valor 1 
			retornado pela fun��o; por outro lado, 0 ser� retornado se 
			uma ou as duas colunas forem inv�lidas;
		b.	Ap�s a troca, a coluna c2 conter� exatamente os elementos 
		    originais da coluna c1, na mesma ordem. Por�m, os valores da 
			coluna c1 ser�o os originais da c2, na ordem inversa.

	Exemplo:

	Trocar as colunas 1 e 3 da matriz abaixo:

					1	3	5	7	9	
					4	6	5	8	0	
					3	4	5	7	8	
					5	9	1	2	3	
					7	1	5	3	5	
					4	0	2	1	5	



					1	1	5	3	9	
					4	3	5	6	0	
					3	2	5	4	8	
					5	7	1	9	3	
					7	8	5	1	5	
					4	7	2	0	5	
*/

//importa��o de bibliotecas
#include <stdio.h>

//declara��o dos prot�tipos
int trocarColunasMatriz (int lin, int col, int matriz[lin][col], int c1, int c2);
void exibirMatriz (int lin, int col, int matriz[lin][col]);

//main
void main ()
{
	//declara��o de vari�veis	
	int mat[6][5] = {{1,3,5,7,9},
	                 {4,6,5,8,0},
	                 {3,4,5,7,8},
	                 {5,9,1,2,3},
	                 {7,1,5,3,5},
	                 {4,0,2,1,5}};

	//exibindo a matriz antes da chamada
	printf ("Antes da chamada:\n\n");
	exibirMatriz (6, 5, mat);
	
	//chamando a fun��o
	if (trocarColunasMatriz (6, 5, mat, 1, 3) == 1)
	{
		//exibindo a matriz depois da chamada
		printf ("\n\nDepois da chamada:\n\n");
		exibirMatriz (6, 5, mat);
	}
	else
	{
		printf ("\n\nColuna informada invalida!");
	}
}

//implementa��o das fun��es
int trocarColunasMatriz (int lin, int col, int matriz[lin][col], int c1, int c2)
{
	//declara��o de vari�veis
	int aux[lin];
	int i, i1, i2;
	
	//validando as colunas 'c1' e 'c2'
	if ((c1>=0) && (c1<col) && (c2>=0) && (c2<col) && (c1!=c2))
	{
		//copiar os elementos da coluna 'c1' para o vetor 'aux'
		for (i=0;i<lin;i++)
		{
			aux[i] = matriz[i][c1];
		}
		
		//copiar os elementos de 'c2' para 'c1', por�m na ordem inversa
		for (i1=0,i2=lin-1;i1<lin;i1++,i2--)
		{
			matriz[i1][c1] = matriz[i2][c2];
		}
		
		//copiar os elementos do vetor 'aux' para a coluna 'c2'
		for (i=0;i<lin;i++)
		{
			matriz[i][c2] = aux[i];
		}
		
		return 1;
	}
	else
	{
		//alguma coluna � inv�lida
		return 0;
	}
}

void exibirMatriz (int lin, int col, int matriz[lin][col])
{
	//declara��o de vari�veis
	int i, j;
	
	for (i=0;i<lin;i++)
	{
		for (j=0;j<col;j++)
		{
			printf ("%d ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}
