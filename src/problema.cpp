#include <iostream>
#include <Windows.h>
#include "binario.h"
#include "genetico.h"

// Definindo as cores para usar nas saídas
#define verde "\033[32m"
#define vermelho "\033[31m"
#define default "\033[m"

using namespace std;

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	/* PRIMEIRA JANELA DO PROGRAMA
	Instruções para o usuário e leitura da entrada */
	cout << "Entre com 6 solução iniciais (números entre 0 e 65535):\n";
	unsigned short solução1, solução2, solução3, solução4, solução5, solução6;
	cin >> solução1 >> solução2 >> solução3 >> solução4 >> solução5 >> solução6;
	system("cls");
	// FIM DA PRIMEIRA JANELA

	/* SEGUNDA JANELA DO PROGRAMA
	Exibindo os resultados das avaliações e chamando as funções de operações genéticas */
	cout << "Resultado da avaliação\n";
	cout << "------------------------\n";

	// Exibindo o resultado das avaliações dependendo da saída da função avaliação()
	if (avaliação(solução1)) // SOLUÇÃO1
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avaliação(solução2)) // SOLUÇÃO2
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avaliação(solução3)) // SOLUÇÃO3
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avaliação(solução4)) // SOLUÇÃO4
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avaliação(solução5)) // SOLUÇÃO5
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avaliação(solução6)) // SOLUÇÃO6
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Divindo as soluções entre as digitadas e as que sofreram por operações
	cout << "------------------------\n";

	// Realizando a primeira operação para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solução_cruzamento_ponto_unico = cruzamento_ponto_unico(solução1, solução2);

	if (avaliação(solução_cruzamento_ponto_unico)) // CRUZAMENTO PONTO UNICO
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Realizando a segunda operação para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solução_cruzamento_aritmetico = cruzamento_aritmetico(solução3, solução4);

	if (avaliação(solução_cruzamento_aritmetico)) // CRUZAMENTO ARITMETICO
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Relizando a terceira operação para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solução_mutação_simples = mutação_simples(solução5);

	if (avaliação(solução_mutação_simples)) // MUTAÇÃO SIMPLES
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Realizando a quarta operação para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solução_mutação_dupla = mutação_dupla(solução6);

	if (avaliação(solução_mutação_dupla)) // MUTAÇÃO DUPLA
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;
	// FIM DA SEGUNDA JANELA

	return 0;
}