/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2
	Professor Leonardo Vianna
	Data: 23/09/2023
	
	Lista de Exerc�cios VII (Structs)
	
	Quest�o 02: 
	Suponha a exist�ncia de um vetor de tamanho TAM, cada posi��o 
	armazenando o nome da pessoa e a sua data de anivers�rio 
	(representada por um struct do tipo TData, contendo os campos dia 
	e mes). Pede-se o desenvolvimento das seguintes fun��es:
 	
	 	- Determinar a quantidade de pessoas que fazem anivers�rio no 
		  m�s M;
 		- Exibir os nomes de todas pessoas que fazem anivers�rio entre 
		  as datas d1 e d2, ambas do tipo TData.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TAM 5

//defini��o de tipos
typedef struct {
	int dia;
	int mes;
} TData;

typedef struct {
	char nome[30];
	TData dataAniversario;
} TPessoa;

//prot�tipos das fun��es
int quantidadeAniversariantes (TPessoa pessoas[], int quantidade, int m);
void exibirAniversariantes (TPessoa pessoas[], int quantidade, TData d1, TData d2);
int verificarAniversariante (TData data, TData dataInferior, TData dataSuperior);
//main
void main ()
{
	//declara��o de vari�veis
	TPessoa pessoas[TAM];
}

//implementa��o das fun��es
int quantidadeAniversariantes (TPessoa pessoas[], int quantidade, int m)
{
	//declara��o de vari�veis
	int i, cont = 0;
	
	//percorrendo todas as posi��es do vetor
	for (i=0;i<quantidade;i++)
	{
		//verificando se a pessoa da posi��o 'i' faz anivers�rio no m�s 'm'
		if (pessoas[i].dataAniversario.mes == m)
		{
			cont++;
		}
	}
	
	//retornando a quantidade
	return cont;
}

/*Exibir os nomes de todas pessoas que fazem anivers�rio entre 
  as datas d1 e d2, ambas do tipo TData.*/		  
void exibirAniversariantes (TPessoa pessoas[], int quantidade, TData d1, TData d2)
{
	//declara��o de vari�veis
	int i;
	
	//percorrendo todas as posi��es do vetor
	for (i=0;i<quantidade;i++)
	{
		//verificando se a pessoa da posi��o 'i' faz anivers�rio
		//entre as datas 'd1' e 'd2'
		if (verificarAniversariante (pessoas[i].dataAniversario, d1, d2) == 1)
		{
			printf ("%s\n", pessoas[i].nome);
		}
	}
}

int verificarAniversariante (TData data, TData dataInferior, TData dataSuperior)
{
	//declara��o de vari�veis
	int total, totalInferior, totalSuperior;
	
	//convertendo cada data para o total de dias equivalente
	total = data.mes*30 + data.dia;
	totalInferior = dataInferior.mes*30 + dataInferior.dia;
	totalSuperior = dataSuperior.mes*30 + dataSuperior.dia;
	
	//verificando se a data passada est� entre as duas lim�trofes
	if ((total >= totalInferior) && (total <= totalSuperior))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
