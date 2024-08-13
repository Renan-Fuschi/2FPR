/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 04/10/2023
	
	Quest�o 09:
	Desenvolver uma fun��o recursiva que, dado um vetor V com quant n�meros 
	inteiros, determine se seus elementos est�o dispostos de maneira a 
	representar uma progress�o aritm�tica. 
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
int verificarPA (int vetor[], int quant);
int verificarPA_Rec (int vetor[], int quant, int razao, int posicao);

//main
void main ()
{
	//declara��o de vari�veis
	int vet1[5] = {3,7,11,15,19};
	int vet2[5] = {2,6,10,13,18};
	
	//chamando a fun��o
	printf ("\nVet1: %d\n", verificarPA (vet1, 5));
	printf ("\nVet2: %d\n", verificarPA (vet2, 5));
}

//implementa��o das fun��es
int verificarPA (int vetor[], int quant)
{
	//declara��o de vari�veis
	int razao;
	
	//calculando a raz�o da PA sobre os dois primeiros elementos do vetor
	razao = vetor[1]-vetor[0];
	
	//chamando a fun��o recursiva
	return verificarPA_Rec (vetor, quant, razao, 2);
	//iniciando com 2, pois os dois primeiros elementos foram utilizados no c�lculo da raz�o	
}

int verificarPA_Rec (int vetor[], int quant, int razao, int posicao)
{
	if (posicao < quant)
	{
		if (vetor[posicao] - vetor[posicao-1] == razao)  //caso geral
		{
			return verificarPA_Rec (vetor, quant, razao, posicao+1);
		}
		else	//caso base
		{
			return 0;
		}
	}
	else	//caso base
	{
		return 1;
	}
}
