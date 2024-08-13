/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turmas: Manh� e Noite
	Professor Leonardo Vianna
	
	Data: 02/12/2023
	
	Considere a exist�ncia de uma lista encadeada L, do tipo TLista, e um n�mero 
	inteiro n. Fazer uma fun��o que crie duas novas listas, conforme descrito abaixo:
	
		L1: conter� todos os elementos de L que sejam inferiores a n;
		L2: conter� todos os elementos de L que sejam maiores ou iguais a n.
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
void criarListas (TLista L, int numero, TLista *L1, TLista *L2);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declara��o de vari�veis
	TLista original = NULL, nova1 = NULL, nova2 = NULL;
	
	//inserindo valores na lista 'original'
	inserir (&original, 10);
	inserir (&original, 7);
	inserir (&original, 6);
	inserir (&original, 1);
	inserir (&original, 3);
	inserir (&original, 0);
	inserir (&original, 8);
	inserir (&original, 6);
	
	//chamando a fun��o
	criarListas (original, 6, &nova1, &nova2);
	
	//exibindo as listas
	printf ("Lista original:\n");
	exibir (original);
	
	printf ("\n\nLista 1:\n");
	exibir (nova1);
	
	printf ("\n\nLista 2:\n");
	exibir (nova2);
}

//implementa��o das fun��es
void criarListas (TLista L, int numero, TLista *L1, TLista *L2)
{
	//declara��o de vari�veis
	TLista aux;
	
	//'aux' percorrer� a lista. Come�ando pelo primeiro n�.
	aux = L;
	
	//enquanto 'aux' n�o chegar ao final da lista
	while (aux)	
	{
		//verificando se o valor apontado por 'aux' � menor ou n�o do que 'numero'
		if (aux->valor < numero)
		{
			//inserir 'numero' em 'L1'
			inserir (/*&*L1*/L1, aux->valor);
		}
		else
		{
			//inserir 'numero' em 'L2'
			inserir (/*&*L2*/L2, aux->valor);
		}
		
		//atualizando 'aux' de forma que aponte para o pr�ximo n�
		aux = aux->prox;
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

