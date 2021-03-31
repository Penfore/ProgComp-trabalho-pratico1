#include "binario.h"
#include <iostream>

using namespace std;

/* Recebe um valor inteiro, exibeo o valor e o peso total da solu��o e retorna
um booleano indicando se o peso est� dentro do limite da mochila. */ 
bool avalia��o(unsigned short valor_para_avalia��o) // OK
{
	/* Somando as vari�veis peso e valor de acordo com testes realizados usando testar_bit() */
	unsigned short mascara = 0, valor = 0, peso = 0;
	if (testar_bit(valor_para_avalia��o, mascara)) // P
	{
		peso = peso + 1;
		valor = valor + 12;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // O
	{
		peso = peso + 4;
		valor = valor + 4;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // N
	{
		peso = peso + 2;
		valor = valor + 3;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // M
	{
		peso = peso + 5;
		valor = valor + 10;		}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // L
	{
		peso = peso + 4;
		valor = valor + 15;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // K
	{
		peso = peso + 2;
		valor = valor + 20;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // J
	{
		peso = peso + 1;
		valor = valor + 10;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // I
	{
		peso = peso + 4;
		valor = valor + 2;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // H
	{
		peso = peso + 3;
		valor = valor + 1;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // G
	{
		peso = peso + 2;
		valor = valor + 1;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // F
	{
		peso = peso + 1;
		valor = valor + 3;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // E
	{
		peso = peso + 9;
		valor = valor + 15;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // D
	{
		peso = peso + 4;
		valor = valor + 10;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // C
	{
		peso = peso + 5;
		valor = valor + 8;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // B
	{
		peso = peso + 3;
		valor = valor + 4;
	}
	mascara++;
	if (testar_bit(valor_para_avalia��o, mascara)) // A
	{
		peso = peso + 12;
		valor = valor + 4;
	}

	cout.width(5); cout << valor_para_avalia��o << " - "; // Exibindo valor de entrada
	cout << "$"; cout << left; cout.width(3); cout << valor << " - "; // Exibindo o valor monet�rio
	cout << right; cout.width(2); cout << peso << "Kg - "; // Exibindo o peso

	if (peso <= 20)
		return true;
	else
		return false;
}

/* Recebe dois valores inteiros representando as solu��es e retorna
um valor inteiro representando o cruzamento de ponto �nico entre as solu��es. */
unsigned short cruzamento_ponto_unico(unsigned short solu��o1, unsigned short solu��o2) // OK
{
	unsigned short solu��o_bits_altos = bits_altos(solu��o1) << 8; // Zerando os bits baixos para a inser��o da solu��o_bits_baixos na opera��o OR;
	unsigned short solu��o_bits_baixos = bits_baixos(solu��o2);

	return or_binario(solu��o_bits_altos, solu��o_bits_baixos);
}

/* Recebe dois valores inteiros representando  as solu��es e retorna
um valor inteiro representando o cruzamento aritm�tico entre as solu��es. */
unsigned short cruzamento_aritmetico(unsigned short solu��o1, unsigned short solu��o2) // OK
{
	return and_binario(solu��o1, solu��o2);
}

/* Recebe um valor inteiro representando uma solu��o e retorna
um valor inteiro representando a muta��o simples da solu��o. */
unsigned short muta��o_simples(unsigned short solu��o) // OK
{
	if (testar_bit(solu��o, 9))
		return desligar_bit(solu��o, 9);
	else
		return ligar_bit(solu��o, 9);
	// Os valores utilizados na fun��o est�o de acordo com o arquivo dado como proposta para o trabalho
}

/* Recebe um valor inteiro representando uma solu��o e retorna
um valor inteiro representando a muta��o dupla da solu��o. */
unsigned short muta��o_dupla(unsigned short solu��o) // OK
{
	unsigned short realizando_muta��o;

	// Modificando o primeiro bit proposto
	if (testar_bit(solu��o, 3))
		realizando_muta��o = desligar_bit(solu��o, 3);
	else
		realizando_muta��o = ligar_bit(solu��o, 3);

	// Modificando o segundo bit proposto, mas agora a partir da vari�vel utilizada na opera��o anterior
	if (testar_bit(solu��o, 12))
		realizando_muta��o = desligar_bit(realizando_muta��o, 12);
	else
		realizando_muta��o = ligar_bit(realizando_muta��o, 12);
	// Os valores utilizados na fun��o est�o de acordo com o arquivo dado como proposta para o trabalho

	return realizando_muta��o;
}