#include "binario.h"

/* Recebe um valor inteiro e a posi��o do bit a ser ligado, retornando
o valor inteiro resultante da modifica��o do bit. */
unsigned short ligar_bit(unsigned short valor, unsigned char posi��o_para_modifica��o)
{
	unsigned short mascara = 1 << posi��o_para_modifica��o;

	return or_binario(valor, mascara);
}

/* Recebe um valor inteiro e a posi��o do bit a ser desligado, retornando
o valor inteiro resultante da modifica��o do bit. */
unsigned short desligar_bit(unsigned short valor, unsigned char posi��o_para_modifica��o)
{
	unsigned short mascara = ~(1 << posi��o_para_modifica��o);

	return and_binario(valor, mascara);
}

/* Recebe um valor inteiro e a posi��o do bit a ser testada, retornando
retornando um booleano para indicar se o bit est� ou n�o ligado. */
bool testar_bit(unsigned short valor, unsigned char posi��o_para_teste)
{
	unsigned short mascara = 1 << posi��o_para_teste;

	if (valor & mascara)
		return true;
	else
		return false;
}

/* Recebe dois valores inteiros e retorna um inteiro representando o
resultado da opera��o AND bit a bit entre os n�meros recebidos. */
unsigned short and_binario(unsigned short valor1, unsigned short valor2)
{
	return valor1 & valor2;
}

/* Recebe dois valores inteiros e retorna um inteiro representando o
resultado da opera��o OR bit a bit entre os n�meros recebidos. */
unsigned short or_binario(unsigned short valor1, unsigned short valor2)
{
	return valor1 | valor2;
}

/* Recebe um valor inteiro e retorna outro contendo apenas os 8 bits
de mais baixa ordem do valor original, com os demais bits colocados para zero. */
unsigned short bits_baixos(unsigned short valor)
{
	unsigned short opera��o = valor << 8;
	opera��o = opera��o >> 8;

	return opera��o;
}

/* Recebe um valor inteiro e retorna outro contendo apenas os 8 bits
de mais alta ordem do valor original, com os demais bits colocados para zero. */
unsigned short bits_altos(unsigned short valor)
{
	return valor >> 8;
}