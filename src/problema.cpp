#include <iostream>
#include <Windows.h>
#include "binario.h"
#include "genetico.h"

// Definindo as cores para usar nas sa�das
#define verde "\033[32m"
#define vermelho "\033[31m"
#define default "\033[m"

using namespace std;

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	/* PRIMEIRA JANELA DO PROGRAMA
	Instru��es para o usu�rio e leitura da entrada */
	cout << "Entre com 6 solu��o iniciais (n�meros entre 0 e 65535):\n";
	unsigned short solu��o1, solu��o2, solu��o3, solu��o4, solu��o5, solu��o6;
	cin >> solu��o1 >> solu��o2 >> solu��o3 >> solu��o4 >> solu��o5 >> solu��o6;
	system("cls");
	// FIM DA PRIMEIRA JANELA

	/* SEGUNDA JANELA DO PROGRAMA
	Exibindo os resultados das avalia��es e chamando as fun��es de opera��es gen�ticas */
	cout << "Resultado da avalia��o\n";
	cout << "------------------------\n";

	// Exibindo o resultado das avalia��es dependendo da sa�da da fun��o avalia��o()
	if (avalia��o(solu��o1)) // SOLU��O1
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avalia��o(solu��o2)) // SOLU��O2
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avalia��o(solu��o3)) // SOLU��O3
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avalia��o(solu��o4)) // SOLU��O4
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avalia��o(solu��o5)) // SOLU��O5
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	if (avalia��o(solu��o6)) // SOLU��O6
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Divindo as solu��es entre as digitadas e as que sofreram por opera��es
	cout << "------------------------\n";

	// Realizando a primeira opera��o para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solu��o_cruzamento_ponto_unico = cruzamento_ponto_unico(solu��o1, solu��o2);

	if (avalia��o(solu��o_cruzamento_ponto_unico)) // CRUZAMENTO PONTO UNICO
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Realizando a segunda opera��o para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solu��o_cruzamento_aritmetico = cruzamento_aritmetico(solu��o3, solu��o4);

	if (avalia��o(solu��o_cruzamento_aritmetico)) // CRUZAMENTO ARITMETICO
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Relizando a terceira opera��o para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solu��o_muta��o_simples = muta��o_simples(solu��o5);

	if (avalia��o(solu��o_muta��o_simples)) // MUTA��O SIMPLES
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;

	// Realizando a quarta opera��o para gerar uma nova entrada para ser avaliada pelo programa
	unsigned short solu��o_muta��o_dupla = muta��o_dupla(solu��o6);

	if (avalia��o(solu��o_muta��o_dupla)) // MUTA��O DUPLA
		cout << verde << "Ok\n" << default;
	else
		cout << vermelho << "X\n" << default;
	// FIM DA SEGUNDA JANELA

	return 0;
}