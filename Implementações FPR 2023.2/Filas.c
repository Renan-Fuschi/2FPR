/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 16/11/2023
	
	Filas encadeadas/linked (Filas din�micas)
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
int enfilar (TLista *inicio, TLista *final, int numero);
int desenfilar (TLista *inicio, TLista *final, int *numero);
int primeiro (TLista inicio, int *p);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista inicio = NULL, final = NULL;  //representando a fila inicialmente vazia
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido na fila: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (enfilar (&inicio, &final, num) == 1)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na fila!\n");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na fila!\n");
					}
					break;

			//Desenfilar
			case 2: //chamando a fun��o
			        if (desenfilar (&inicio, &final, &num) == 1)
			        {
			        	printf ("\n\tO elemento %d foi removido da fila!\n", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!\n");
					}
					break;

			//Primeiro
			case 3: //chamando a fun��o
			        if (primeiro (inicio, &num) == 1)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d\n", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!\n");
					}
					break;         
			        
			//Sa�da
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementa��o das fun��es
int enfilar (TLista *inicio, TLista *final, int numero)
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
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para NULL (uma vez que ser� o �ltimo elemento da fila)
		aux->prox = NULL;
		
		if (*final)
		{
			//Passo 4: fazer o "antigo �ltimo n�" apontar para o novo
			(*final)->prox = aux;
		}
		else
		{
			*inicio = aux;
		}
		
		//Passo 5: atualizando 'final', de modo que aponte para o novo n�
		*final = aux;

		return 1;
	}
	else
	{
		return 0;
	}
}

int desenfilar (TLista *inicio, TLista *final, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a fila est� vazia
	if (!(*inicio))
	{
		return 0;
	}
	else
	{
		//armazenando em 'aux' o endere�o do primeiro elemento (que ser� removido)
		aux = *inicio;
		
		//atualizando o valor de 'inicio'
		*inicio = (*inicio)->prox;    //OU:    *inicio = aux->prox;
		
		//verificando se a fila se tornou vazia
		if (!(*inicio))
		{
			//atualizar 'final' para NULL tamb�m
			*final = NULL;
		}
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando a mem�ria do n� apontado por 'aux'
		free (aux);
		
		return 1;
	}
}

//retornar em 'p' o primeiro elemento da fila, caso esta n�o esteja vazia
int primeiro (TLista inicio, int *p)
{
	//verificando se a fila est� vazia
	if (!inicio)
	{
		return 0;
	}
	else
	{
		//armazenando em 'p' o primeiro elemento da fila
		*p = inicio->valor;
		
		return 1;
	}
}

//exibe um menu de op��es ao usu�rio
int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
