/*Implementar uma função que converta
determinada temperatura em graus Celsius
para graus Fahrenheit.*/
#include<stdio.h>

float conversor(float cel);

int main()
{
	float celsius,resultado;
	
	printf("Entre com uma temperatura em Celsius: ");
	scanf("%f",&celsius);
	
	resultado = conversor(celsius);
	
	printf("%.1f para Fahrenheit resulta em: %.1f",celsius,resultado);
}

float conversor(float cel)
{
	int fah;
	
	fah = (cel * 1.8) + 32;
	
	return fah;
}
