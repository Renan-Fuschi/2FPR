/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 04/10/2023
	
	Quest�o 06:
	Dada uma string s, desenvolver uma fun��o recursiva que determine se s � ou 
	n�o um pal�ndromo. 
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
int palindromo (char s[]);
int palindromoRec (char s[], int inicio, int fim);

//main
void main ()
{
	//declara��o de vari�veis
	char s1[10], s2[10];
	int resp1, resp2;
	
	//inicializando as strings
	strcpy (s1, "TESTE");
	strcpy (s2, "OSSO");
	
	//chamando a fun��o
	resp1 = palindromo (s1);
	resp2 = palindromo (s2);
	
	//verificando os resultados
	if (resp1 == 1)
	{
		printf ("\nA string %s e' um palindromo!\n", s1);
	}
	else
	{
		printf ("\nA string %s NAO e' um palindromo!\n", s1);
	}
	
	if (resp2 == 1)
	{
		printf ("\nA string %s e' um palindromo!\n", s2);
	}
	else
	{
		printf ("\nA string %s NAO e' um palindromo!\n", s2);
	}
}

//implementa��o das fun��es
int palindromo (char s[])
{
	return palindromoRec (s, 0, strlen(s)-1);
}

int palindromoRec (char s[], int inicio, int fim)
{
	if (inicio >= fim)	//caso base
	{
		return 1;
	}
	else
	{
		if (s[inicio] != s[fim])	//caso base
		{
			return 0;
		}
		else
		{
			return palindromoRec (s, inicio+1, fim-1);	//caso geral
		}
	}
}
