/*
 * lista.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <iostream>
#include "lista_ligada.h" //Importa lista.h para lista_array
#include "lista_array.h"

#define MAX 100

using namespace std;

void testaTamanho(ListaBase<int>& lista, const char* subcaso, int tamanho) {
    cerr << "Testando tamanho() [" << subcaso << "]: ";
    if (lista.tam() != tamanho) {
        cerr << "FALHOU (tam = " << lista.tam() << ")" << endl;
        exit(1);
    }
    cerr << "OK" << endl;
}

int main() {
    ListaBase<int>* lista = new ListaArray<int>(MAX);

    try {
        cerr << "Testando adiciona() [normal]: ";
        for (int i = 1; i <= MAX; i++) {
            lista->adiciona(i);
        }
        cerr << "OK" << endl;
    } catch (...) {
        cerr << "FALHOU!" << endl;
        exit(1);
    }

    testaTamanho(*lista, "cheia", MAX);

    try {
        cerr << "Testando adiciona() [overflow]: ";
        lista->adiciona(MAX + 1);
        cerr << "FALHOU!" << endl;
        exit(1);
    } catch (const char* ex) {
        cerr << "OK (" << ex << ")" << endl;
    }

    cerr << "Testando pega() [todos]: ";
    for (int i = MAX; i >= 1; i--) {
        try {
            if (lista->pega(i) != i) {
                cerr << "FALHOU em " << i << endl;
                lista->exibe();
                exit(1);
            }
        } catch (...) {
            cerr << "FALHOU em " << i << " (exceção)" << endl;
            exit(1);
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando remove() [pares]: ";
    try {
        for (int i = MAX / 2; i >= 1; i--) {
            lista->remove(2 * i);
        }
    } catch (const char* ex) {
        cerr << "FALHOU (" << ex << ")" << endl;
        exit(1);
    }
    cerr << "OK" << endl;

    testaTamanho(*lista, "metade", MAX / 2); /* "uma referência do tipo "ListaArray<int> &" 
	(não qualificada como constante) não pode ser inicializada com um valor do tipo "ListaBase<int>"" 
	Como assim "não qualificada como constante"
	*/

    cerr << "Testando pega() [impares]: ";
    for (int i = 1; i <= MAX / 2; i++) {
        try {
            if (lista->pega(i) != ((i - 1) * 2) + 1) {
                cerr << "FALHOU em " << i << endl;
                lista->exibe();
                exit(1);
            }
        } catch (...) {
            cerr << "FALHOU em " << i << "(exceção)" << endl;
            exit(1);
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando insere() [pares]: ";
    lista->adiciona(MAX);
    for (int i = MAX / 2 - 1; i >= 1; i--) {
        try {
            lista->insere(i + 1, 2 * i);
        } catch (...) {
            cerr << "FALHOU em " << i << " (exceção)" << endl;
            exit(1);
        }
    }
    cerr << "OK" << endl;

    testaTamanho(*lista, "cheia", MAX);

    cerr << "Testando pega() [todos, 2o round]: ";
    for (int i = MAX; i >= 1; i--) {
        try {
            if (lista->pega(i) != i) {
                cerr << "FALHOU em " << i << " (valor = " << lista->pega(i) << ")" << endl;
                lista->exibe();
                exit(1);
            }
        } catch (...) {
            cerr << "FALHOU em " << i << " (exceção)" << endl;
            exit(1);
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando remove() [tudo]: ";
    try {
        for (int i = 1; i <= MAX; i++) {
            lista->remove(1);
        }
    } catch (const char* ex) {
        cerr << "FALHOU (" << ex << ")" << endl;
        exit(1);
    }
    cerr << "OK" << endl;

    testaTamanho(*lista, "vazia", 0);

    try {
        cerr << "Testando remove() [underflow]: ";
        lista->remove(1);
        cerr << "FALHOU!" << endl;
        exit(1);
    } catch (const char* ex) {
        cerr << "OK (" << ex << ")" << endl;
    }

    delete lista;

    return 0;
}