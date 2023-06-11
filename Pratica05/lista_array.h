#include <iostream>
#include <stdexcept>

template <class T>
class Lista {
private:
    T *itens;
    int capacidade;
    int tamanho;

public:
    Lista(int capacidade) {
        this->capacidade = capacidade;
        this->tamanho = 0;
        this->itens = new T[capacidade];
    }

    ~Lista() {
        delete[] itens;
    }

    void adiciona(const T &item) {
        if (tamanho == capacidade) {
            throw std::runtime_error("Lista cheia");
        }
        itens[tamanho++] = item;
    }

    T pega(int idx) {
        if (idx < 1 || idx > tamanho) {
            throw std::runtime_error("Item inválido");
        }
        return itens[idx - 1];
    }

    void insere(int idx, const T &item) {
        if (tamanho == capacidade) {
            throw std::runtime_error("Lista cheia");
        }
        if (idx < 1 || idx > tamanho + 1) {
            throw std::runtime_error("Item inválido");
        }
        for (int i = tamanho; i >= idx; i--) {
            itens[i] = itens[i - 1];
        }
        itens[idx - 1] = item;
        tamanho++;
    }

    void remove(int idx) {
        if (idx < 1 || idx > tamanho) {
            throw std::runtime_error("Item inválido");
        }
        for (int i = idx - 1; i < tamanho - 1; i++) {
            itens[i] = itens[i + 1];
        }
        tamanho--;
    }

    void exibe() {
        for (int i = 0; i < tamanho; i++) {
            std::cout << itens[i] << " ";
        }
        std::cout << std::endl;
    }

    int tam() {
        return tamanho;
    }
};
