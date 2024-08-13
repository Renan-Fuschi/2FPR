/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 09/11/2023
	
	Listas encadeadas (Listas din�micas)
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
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int anterior, int novo);
TLista buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, num2, op, quant;
	TLista resp;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (inserir (&L, num1) == 1)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remo��o
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Altera��o
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a fun��o
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        resp = buscar (L, num1);
			        
					if (resp != NULL)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Sa�da
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}

//implementa��o das fun��es
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

int remover (TLista *L, int numero)
{
	//declara��o de vari�veis
	TLista aux1, aux2;
	int cont = 0;
	
	//verificando se o primeiro elemento da lista � igual a 'numero'
	while ((*L) && (*L)->valor == numero)
	{
		//salvando o endere�o do n� que ser� removido
		aux1 = *L;
		
		//atualizando o valor de 'L'
		*L = (*L)->prox;	
		
		//liberando a mem�ria ocupada pelo primeiro n�
		free (aux1);
		
		//atualizando a quantidade de remo��es realizadas
		cont++;
	}
	
	//verificando se ainda existem n�s na lista
	if (*L)
	{
		aux2 = *L;
		aux1 = (*L)->prox;   //ou   aux1 = aux2->prox;
		
		//percorrendo a lista
		while (aux1)
		{
			//verificando se 'numero' foi encontrado
			if (aux1->valor == numero)
			{
				//fazer o n� anterior apontar para o pr�ximo n�
				aux2->prox = aux1->prox;
				
				//liberando a mem�ria
				free (aux1);
				
				//atualizando a quantidade de remo��es realizadas
				cont++;	
				
				//atualizando o ponteiro 'aux1'
				aux1 = aux2->prox;
			}
			else
			{
				//andar com os dois ponteiros
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando a quantidade de remo��es realizadas
	return cont;
}

int alterar (TLista L, int anterior, int novo)
{
	//declara��o de vari�veis
	TLista aux;
	int cont = 0;
	
	//verificando se os valores s�o distintos
	if (anterior != novo)
	{
		//buscando a primeira ocorr�ncia de 'anterior'
		aux = buscar (L, anterior);
		
		//enquanto o elemento existir na lista
		while (aux)
		{
			//atualizando o valor apontado pelo 'aux'
			aux->valor = novo;	
			
			//atualizando a quantidade de altera��es realizadas
			cont++;
			
			//buscando novamente o 'anterior'
			aux = buscar (aux->prox, anterior);
		}	
	}
	
	return cont; //retornando a quantidade de altera��es realizadas
}

TLista buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//percorrendo a lista
	while (aux)
	{
		//verificando se o elemento foi encontrado
		if (aux->valor == numero)
		{
			return aux;
		}
		
		//atualizando o 'aux'
		aux = aux->prox;	
	}	
	
	return NULL;	//elemento n�o se encontra na lista
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

//exibe um menu de op��es ao usu�rio
int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
