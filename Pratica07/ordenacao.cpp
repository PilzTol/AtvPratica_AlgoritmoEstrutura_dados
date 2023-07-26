/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

// Troca dois valores
// Pode ser usada nas funções de ordenação
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// Faz uma cópia de um array em outro novo
int * clone(int * array, int size) {
	int * copy = new int[size];
	for (int i = 0; i < size; i++) { copy[i] = array[i]; }
	return copy;
}

// NO-OP Sort: não mexer
void noopsort(int * array, int size) {
	// no-op
}

void BubbleSort(int *ARRAY, int LEN) {
    int ULTIMO_NAO_ORDENADO = LEN - 1;
    bool houveTroca;

    do {
        houveTroca = false;
        int ultimoSwap = 0;

        for (int i = 0; i < ULTIMO_NAO_ORDENADO; i++) {
            if (ARRAY[i] > ARRAY[i + 1]) {
                swap(ARRAY[i], ARRAY[i + 1]);
                houveTroca = true;
                ultimoSwap = i;
            }
        }

        ULTIMO_NAO_ORDENADO = ultimoSwap;

    } while (houveTroca);
}


void selectionsort(int * array, int size) {
	for (int i = 0; i < size - 1; i++) {
        int MIN = i;

        for (int j = i + 1; j < size; j++) {
            if (array[MIN] > array[j]) {
                MIN = j;
            }
        }

        swap(array[MIN], array[i]);
    }
}






void insertionsort(int * array, int size) {
	 for (int i = 1; i < size; i++) {
        int tmp = array[i]; // Salvar array[i] em TMP
        int j = i - 1; // Fazer J = I - 1

        // Deslocar os elementos maiores que TMP para a direita
        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j]; // mover array[J] para array[J+1]
            j--; // decrementar J
        }

        array[j + 1] = tmp; // Salvar TMP em array[J + 1]
    }
}

// Faz o merge dos subarrays em aux para array, isto é, array[...] = aux[...]
void merge(int * array, int * aux, int start, int mid, int finish) {
	int leftIdx = start;
    int rightIdx = mid;
    int auxIdx = start;

    while (leftIdx < mid && rightIdx <= finish) {
        if (array[leftIdx] <= array[rightIdx]) {
            aux[auxIdx++] = array[leftIdx++];
        } else {
            aux[auxIdx++] = array[rightIdx++];
        }
    }

    // Copiar os elementos restantes da primeira metade (se houver)
    while (leftIdx < mid) {
        aux[auxIdx++] = array[leftIdx++];
    }

    // Copiar os elementos restantes da segunda metade (se houver)
    while (rightIdx <= finish) {
        aux[auxIdx++] = array[rightIdx++];
    }

    // Copiar os elementos ordenados de volta para o array original
    for (int i = start; i <= finish; i++) {
        array[i] = aux[i];
    }
}

// Array: array que vai conter o resultado ordenado
// Aux: array auxiliar usado para ordenar as duas metades, esquerda e direita
// Repare que na chamada recursiva de mergesorte, array e aux se alternam
// Isto é, uma hora um é o principal e o outro é o auxiliar, depois invertem
void mergesort(int * array, int * aux, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(aux, array, start, mid);
	mergesort(aux, array, mid + 1, finish);

	merge(array, aux, start, mid + 1, finish);
}

// Função chamada inicialmente;
// Chama a função mergesorte() acima com os limites start e finish, e o clone do array (aux).
void mergesort(int * array, int size) {
	int * aux = clone(array, size);
	mergesort(array, aux, 0, size - 1);
	delete [] aux;
}

// Partição do QuickSort
int partition(int * array, int start, int finish) {
	 int pivot = array[finish]; // Escolha do pivô (último elemento)

    // Índice para o elemento menor (inicialmente é start)
    int smallerIdx = start - 1;

    for (int i = start; i < finish; i++) {
        if (array[i] <= pivot) {
            smallerIdx++;
            swap(array[i], array[smallerIdx]);
        }
    }

    // Colocar o pivô na posição correta
    swap(array[smallerIdx + 1], array[finish]);
    return smallerIdx + 1; // Retornar a posição do pivô
	return -1;
}

void quicksort(int * array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

// Semelhante ao que ocorre com o MergeSort.
void quicksort(int * array, int size) {
	quicksort(array, 0, size - 1);
}


// Funções Utilitárias

// Valida um array (isto é, se está ordenado ou não)
int validate(int * data, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (data[i] > data[i + 1]) return 0;
	}
	return 1;
}

// Exibe um array na tela
void print(int * data, int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

// Testa um algoritmo passado como parâmetro.
void test(int * array, int size, const char * name, void function(int *, int), int printFlag) {
	int * copy = clone(array, size);
	auto start = std::chrono::high_resolution_clock::now();

	function(copy, size);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy, size);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy, size); else cout << endl;

	delete [] copy;
}

int main() {
	int size = 150;
	int print = 1;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % (size * 2);
	}

	test(array, size, "NoOpSort     ", noopsort, print);
	test(array, size, "BubbleSort   ", BubbleSort, print);
	test(array, size, "SelectionSort", selectionsort, print);
	test(array, size, "InsertionSort", insertionsort, print);
	test(array, size, "MergeSort    ", mergesort, print);
	test(array, size, "QuickSort    ", quicksort, print);

	delete [] array;
}






