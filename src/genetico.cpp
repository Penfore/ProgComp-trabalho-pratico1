#include "binario.h"
#include <iostream>

using namespace std;

/* Recebe um valor inteiro, exibeo o valor e o peso total da solução e retorna
um booleano indicando se o peso está dentro do limite da mochila. */ 
bool avaliação(unsigned short valor_para_avaliação) // OK
{
	/* Somando as variáveis peso e valor de acordo com testes realizados usando testar_bit() */
	unsigned short mascara = 0, valor = 0, peso = 0;
	if (testar_bit(valor_para_avaliação, mascara)) // P
	{
		peso = peso + 1;
		valor = valor + 12;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // O
	{
		peso = peso + 4;
		valor = valor + 4;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // N
	{
		peso = peso + 2;
		valor = valor + 3;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // M
	{
		peso = peso + 5;
		valor = valor + 10;		}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // L
	{
		peso = peso + 4;
		valor = valor + 15;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // K
	{
		peso = peso + 2;
		valor = valor + 20;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // J
	{
		peso = peso + 1;
		valor = valor + 10;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // I
	{
		peso = peso + 4;
		valor = valor + 2;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // H
	{
		peso = peso + 3;
		valor = valor + 1;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // G
	{
		peso = peso + 2;
		valor = valor + 1;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // F
	{
		peso = peso + 1;
		valor = valor + 3;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // E
	{
		peso = peso + 9;
		valor = valor + 15;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // D
	{
		peso = peso + 4;
		valor = valor + 10;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // C
	{
		peso = peso + 5;
		valor = valor + 8;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // B
	{
		peso = peso + 3;
		valor = valor + 4;
	}
	mascara++;
	if (testar_bit(valor_para_avaliação, mascara)) // A
	{
		peso = peso + 12;
		valor = valor + 4;
	}

	cout.width(5); cout << valor_para_avaliação << " - "; // Exibindo valor de entrada
	cout << "$"; cout << left; cout.width(3); cout << valor << " - "; // Exibindo o valor monetário
	cout << right; cout.width(2); cout << peso << "Kg - "; // Exibindo o peso

	if (peso <= 20)
		return true;
	else
		return false;
}

/* Recebe dois valores inteiros representando as soluções e retorna
um valor inteiro representando o cruzamento de ponto único entre as soluções. */
unsigned short cruzamento_ponto_unico(unsigned short solução1, unsigned short solução2) // OK
{
	unsigned short solução_bits_altos = bits_altos(solução1) << 8; // Zerando os bits baixos para a inserção da solução_bits_baixos na operação OR;
	unsigned short solução_bits_baixos = bits_baixos(solução2);

	return or_binario(solução_bits_altos, solução_bits_baixos);
}

/* Recebe dois valores inteiros representando  as soluções e retorna
um valor inteiro representando o cruzamento aritmético entre as soluções. */
unsigned short cruzamento_aritmetico(unsigned short solução1, unsigned short solução2) // OK
{
	return and_binario(solução1, solução2);
}

/* Recebe um valor inteiro representando uma solução e retorna
um valor inteiro representando a mutação simples da solução. */
unsigned short mutação_simples(unsigned short solução) // OK
{
	if (testar_bit(solução, 9))
		return desligar_bit(solução, 9);
	else
		return ligar_bit(solução, 9);
	// Os valores utilizados na função estão de acordo com o arquivo dado como proposta para o trabalho
}

/* Recebe um valor inteiro representando uma solução e retorna
um valor inteiro representando a mutação dupla da solução. */
unsigned short mutação_dupla(unsigned short solução) // OK
{
	unsigned short realizando_mutação;

	// Modificando o primeiro bit proposto
	if (testar_bit(solução, 3))
		realizando_mutação = desligar_bit(solução, 3);
	else
		realizando_mutação = ligar_bit(solução, 3);

	// Modificando o segundo bit proposto, mas agora a partir da variável utilizada na operação anterior
	if (testar_bit(solução, 12))
		realizando_mutação = desligar_bit(realizando_mutação, 12);
	else
		realizando_mutação = ligar_bit(realizando_mutação, 12);
	// Os valores utilizados na função estão de acordo com o arquivo dado como proposta para o trabalho

	return realizando_mutação;
}