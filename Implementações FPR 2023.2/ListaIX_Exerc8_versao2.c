/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 04/10/2023
	
	Quest�o 08:
	Desenvolver uma fun��o recursiva que, dada uma string, exiba-a invertida. 
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
void exibirInvertida (char s[]);
void exibirInvertidaRec (char s[], int inicio);

//main
void main ()
{
	//declara��o de vari�veis
	char str[10];
	
	//inicializando a string
	strcpy (str, "ALGORITMO");
	
	//chamando a fun��o
	exibirInvertida (str);
}

//implementa��o das fun��es
void exibirInvertida (char s[])
{
	exibirInvertidaRec (s, 0);	
}

void exibirInvertidaRec (char s[], int inicio)
{
	if (inicio < strlen(s))	//caso geral
	{
		exibirInvertidaRec (s, inicio+1);
		printf ("%c", s[inicio]);
	}
}
