#include "binario.h"

/* Recebe um valor inteiro e a posição do bit a ser ligado, retornando
o valor inteiro resultante da modificação do bit. */
unsigned short ligar_bit(unsigned short valor, unsigned char posição_para_modificação)
{
	unsigned short mascara = 1 << posição_para_modificação;

	return or_binario(valor, mascara);
}

/* Recebe um valor inteiro e a posição do bit a ser desligado, retornando
o valor inteiro resultante da modificação do bit. */
unsigned short desligar_bit(unsigned short valor, unsigned char posição_para_modificação)
{
	unsigned short mascara = ~(1 << posição_para_modificação);

	return and_binario(valor, mascara);
}

/* Recebe um valor inteiro e a posição do bit a ser testada, retornando
retornando um booleano para indicar se o bit está ou não ligado. */
bool testar_bit(unsigned short valor, unsigned char posição_para_teste)
{
	unsigned short mascara = 1 << posição_para_teste;

	if (valor & mascara)
		return true;
	else
		return false;
}

/* Recebe dois valores inteiros e retorna um inteiro representando o
resultado da operação AND bit a bit entre os números recebidos. */
unsigned short and_binario(unsigned short valor1, unsigned short valor2)
{
	return valor1 & valor2;
}

/* Recebe dois valores inteiros e retorna um inteiro representando o
resultado da operação OR bit a bit entre os números recebidos. */
unsigned short or_binario(unsigned short valor1, unsigned short valor2)
{
	return valor1 | valor2;
}

/* Recebe um valor inteiro e retorna outro contendo apenas os 8 bits
de mais baixa ordem do valor original, com os demais bits colocados para zero. */
unsigned short bits_baixos(unsigned short valor)
{
	unsigned short operação = valor << 8;
	operação = operação >> 8;

	return operação;
}

/* Recebe um valor inteiro e retorna outro contendo apenas os 8 bits
de mais alta ordem do valor original, com os demais bits colocados para zero. */
unsigned short bits_altos(unsigned short valor)
{
	return valor >> 8;
}