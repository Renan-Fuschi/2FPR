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
	//verificando se 'data' est� entre os meses compreendidos pelo intervalo 
	//passado, por�m n�o no m�s da 'dataInferior' e nem da 'dataSuperior'
	if ((data.mes > dataInferior.mes) && (data.mes < dataSuperior.mes))
	{
		return 1;
	}

	//verificando se est� no m�s de 'dataInferior'. Al�m disso, o dia deve 
	//ser maior ou igual ao dia de 'dataInferior'
	if ((data.mes == dataInferior.mes) && (data.dia >= dataInferior.dia))
	{
		return 1;
	}
	
	//verificando se est� no m�s de 'dataSuperior'. Al�m disso, o dia deve 
	//ser menor ou igual ao dia de 'dataSuperior'
	if ((data.mes == dataSuperior.mes) && (data.dia <= dataSuperior.dia))
	{
		return 1;
	}

	return 0;
}
