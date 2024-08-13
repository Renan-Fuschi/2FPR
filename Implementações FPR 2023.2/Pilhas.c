/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 16/11/2023
	
	Pilhas encadeadas/linked (Pilhas din�micas)
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
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista P = NULL;  //representando a pilha inicialmente vazia
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido na pilha: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (empilhar (&P, num) == 1)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na pilha!\n");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na pilha!\n");
					}
					break;

			//Desempilhar
			case 2: //chamando a fun��o
			        if (desempilhar (&P, &num) == 1)
			        {
			        	printf ("\n\tO elemeto %d foi removido da pilha!\n", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!\n");
					}
					break;

			//Topo
			case 3: //chamando a fun��o
			        if (topo (P, &num) == 1)
			        {
			        	printf ("\n\tTopo da pilha: %d\n", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!\n");
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
int empilhar (TLista *P, int numero)
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
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para o "antigo topo da pilha"
		aux->prox = *P;
		
		//Passo 4: fazer P apontar para o novo n�
		*P = aux;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a pilha 'P' est� vazia
	if (!(*P))
	{
		return 0;
	}
	else
	{
		//armazenando em 'aux' o endere�o do topo (que ser� removido)
		aux = *P;
		
		//atualizando o valor de 'P'
		*P = (*P)->prox;    //OU:    *P = aux->prox;
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando a mem�ria do n� apontado por 'aux'
		free (aux);
		
		return 1;
	}
}

//retornar em 't' o elemento que est� no topo da pilha 'P', caso esta n�o
//esteja vazia
int topo (TLista P, int *t)
{
	//verificando se a pilha 'P' est� vazia
	if (!P)
	{
		return 0;
	}
	else
	{
		//armazenando em 't' o n�mero que est� no topo da pilha
		*t = P->valor;
		
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
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
