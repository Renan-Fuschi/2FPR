/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turmas: Manh� e Noite
	Professor Leonardo Vianna
	
	Data: 02/12/2023
	
	Lista de Exerc�cios XI (Listas Encadeadas)
	
	QUEST�O 08:
	Implementar uma fun��o que crie uma lista encadeada (din�mica) com 
	os N primeiros termos de uma PA (progress�o aritm�tica) de raz�o R 
	e primeiro termo igual a A1.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//prot�tipos das fun��es
void criarPA (int a1, int n, int r, TLista *PA);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declara��o de vari�veis
	TLista PA;
	
	//chamando a fun��o
	criarPA (2, 10, 3, &PA);
	
	exibir (PA);
}

//implementa��o das fun��es
void criarPA (int a1, int n, int r, TLista *PA)
{
	//declara��o de vari�veis
	int termo = a1, i;
	TLista aux, novoNo;
	
	//inicializando 'PA'
	*PA = (TLista) malloc (sizeof(TNo));
	(*PA)->valor = a1;
	(*PA)->prox = NULL;
	
	//incializando 'aux'
	aux = *PA;
	
	//inserindo os demais elementos da PA
	for (i=1;i<n;i++)
	{
		//atualizando 'termo'
		termo += r;
		
		//inserindo 'termo' no final da PA
		novoNo = (TLista) malloc (sizeof(TNo));
		
		//inserindo 'termo' no novo n�
		novoNo->valor = termo;
		
		//fazendo o campo 'prox' do novo n� apontar para NULL
		novoNo->prox = NULL;
		
		//fazendo o "antigo �ltimo n�" apontar para o novo n�
		aux->prox = novoNo;
		
		//atualizando 'aux'
		aux = novoNo;
	}		
}

int inserir (TLista *L, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//Passo 1: alocando mem�ria para o novo n�
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se a mem�ria foi alocada
	if (aux)
	{
		//Passo 2: inserir 'numero' no novo n�
		aux->valor = numero;
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para o "antigo primeiro n�"
		aux->prox = *L;
		
		//Passo 4: fazer L apontar para o novo n�
		*L = aux;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//verificando se a lista est� vazia
	if (!L)
	{
		printf ("Lista vazia!\n\n");
	}
	else
	{
		printf ("Lista: ");
		
		//while (aux != NULL)
		while (aux)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux', de modo que aponte para o pr�ximo n� da lista
			aux = aux->prox;
		}
		
		printf ("\n\n");
	}
}

