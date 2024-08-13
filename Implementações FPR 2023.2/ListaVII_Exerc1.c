/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2
	Professor Leonardo Vianna
	Data: 23/09/2023
	
	Lista de Exerc�cios VII (Structs)
	
	Quest�o 01:
	Uma loja de autom�veis mant�m os carros � venda sob a forma de um 
	vetor de structs contendo as seguintes informa��es, para cada 
	ve�culo: placa, modelo, marca, cor, quilometragem, 
	ano modelo/fabrica��o (deve ser um struct), valor e 
	tipo (usado ou 0 km, conforme o valor do campo quilometragem). 

	Pede-se a declara��o de uma vari�vel que represente o estoque 
	de ve�culos da loja, incluindo todas as declara��es de tipos 
	que possam ser necess�rias.

	Al�m disso, implementar as seguintes fun��es: 
	i.	Exibir todos os carros do modelo m, ano de fabrica��o entre 
	    a1 e a2 (inclusive), com valor n�o superior a x reais;
	ii.	Reajustar os valores de todos os carros 0 km, considerando um 
	    aumento de p %;
	iii. Retirar do estoque um determinado ve�culo, dada a sua placa.	
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de tipos
typedef struct {
	int fabricacao;
	int modelo;
} TAno;

typedef struct {
	char placa[8];
	char modelo[20];
	char marca[20];
	char cor[20];
	float quilometragem;
	TAno ano;
	float valor;
	char tipo[6];	
} TCarro;

//prot�tipos das fun��es
void exibirFiltros (TCarro ag[], int quantidade, char m[], int a1, int a2, float x);
void exibirDadosCarro (TCarro carro);
void reajustarCarros0km (TCarro ag[], int quantidade, float p);
int  removerCarro (TCarro ag[], int *quantidade, char placa[]);

//main
void main ()
{
	//declara��o de vari�veis
	TCarro agencia[5];	
}

//implementa��o das fun��es

/* Exibir todos os carros do modelo m, ano de fabrica��o entre a1 e a2 
(inclusive), com valor n�o superior a x reais. */
void exibirFiltros (TCarro ag[], int quantidade, char m[], int a1, int a2, float x)
{
	//declara��o de vari�veis
	int i;
	
	//percorrendo todo o vetor de carros
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro da posi��o 'i' do vetor atende aos filtros
		if ((strcmp(ag[i].modelo,m)==0) &&
		    ((ag[i].ano.fabricacao >= a1) && (ag[i].ano.fabricacao <= a2)) &&
		    (ag[i].valor <= x))
		{
			exibirDadosCarro (ag[i]);
		}
	}
}

//Exibe os dados de determinado carro
void exibirDadosCarro (TCarro carro)
{
	printf ("Placa: %s\n", carro.placa);
	printf ("Marca/Modelo: %s/%s\n", carro.marca, carro.modelo);
	printf ("Cor: %s\n", carro.cor);
	printf ("Km: %.1f\n", carro.quilometragem);
	printf ("Ano (fabricacao/modelo): %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: %s\n\n", carro.tipo);
}

/* Reajustar os valores de todos os carros 0 km, considerando um 
   aumento de p %.*/
void reajustarCarros0km (TCarro ag[], int quantidade, float p)
{
	//declara��o de vari�veis
	int i;
	
	//percorrendo todo o vetor de carros
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro da posi��o 'i' � 0 km
		if (strcmp (ag[i].tipo, "0KM") == 0)
		{
			//reajustar o seu valor
			ag[i].valor = ag[i].valor + (ag[i].valor*(p/100));
			//ou: ag[i].valor += (ag[i].valor*(p/100));
			
			//ou: ag[i].valor = ag[i].valor * (1 + (p/100));
			//ou: ag[i].valor = ag[i].valor * ((p+100)/100);
			//ou: ag[i].valor *= ((p+100)/100);
		}
	}
}

//Retirar do estoque um determinado ve�culo, dada a sua placa.
//A fun��o retornar� 1 se a remo��o for feita, ou 0, caso contr�rio.
int  removerCarro (TCarro ag[], int *quantidade, char placa[])
{
	//declara��o de vari�veis
	int i, j;
	
	//percorrendo todo o vetor de carros
	for (i=0;i<*quantidade;i++)
	{
		//verificando se o carro da posi��o 'i' � aquele a ser removido
		if (strcmp (ag[i].placa, placa) == 0)
		{
			//deslocando uma posi��o � esquerda todos os carros ap�s a posi��o 'i'	
			for (j=i+1;j<*quantidade;j++)
			{
				ag[j-1] = ag[j];
			}
			
			//atualizando a quantidade de carros na ag�ncia
			(*quantidade)--;
			
			return 1;
		}
	}
	
	return 0;
}
