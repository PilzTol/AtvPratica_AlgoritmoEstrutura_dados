#include "lista.h"


template <class T>
class ListaLigada : public ListaBase<T> {
private:
    struct Item {
        T dado;
        Item *proximo;
    };

    Item *inicio;
    int tamanho;
    int capacidade;

public:
    ListaLigada(int cap = 0) {
        inicio = nullptr;
        tamanho = 0;
        capacidade = cap;
    }

    ~ListaLigada() {
        while (inicio != nullptr) {
            Item *temp = inicio;
            inicio = inicio->proximo;
            delete temp;
        }
    }

    //Ponteiro adicional
    void adiciona(const T &item) override {
        if ((tamanho == capacidade) && (capacidade != 0)) {
            throw ("Lista cheia");
        }
        Item *novoItem = new Item;
        novoItem->dado = item;
        novoItem->proximo = nullptr;

        if (inicio == nullptr) {
            inicio = novoItem;
        } else {
            Item *atual = inicio;
            while (atual->proximo != nullptr) {
                atual = atual->proximo;
            }
            atual->proximo = novoItem;
        }

        tamanho++;
    }

    T pega(int idx) override {
        if (idx < 1 || idx > tamanho) {
            throw ("Item inválido");
        }

        Item *atual = inicio;
        int pos = 1;
        while (pos < idx) {
            atual = atual->proximo;
            pos++;
        }

        return atual->dado;
    }

    void insere(int idx, const T &item) override {
        if ((tamanho == capacidade) && (capacidade != 0)) {
            throw ("Lista cheia");
        }
        if (idx < 1 || idx > tamanho + 1) {
            throw ("Item inválido");
        }

        Item *novoItem = new Item;
        novoItem->dado = item;

        if (idx == 1) {
            novoItem->proximo = inicio;
            inicio = novoItem;
        } else {
            Item *anterior = inicio;
            int pos = 1;
            while (pos < idx - 1) {
                anterior = anterior->proximo;
                pos++;
            }
            novoItem->proximo = anterior->proximo;
            anterior->proximo = novoItem;
        }

        tamanho++;
    }

    void remove(int idx) override {
        if (idx < 1 || idx > tamanho) {
            throw ("Item inválido");
        }

        Item *itemRemovido;
        if (idx == 1) {
            itemRemovido = inicio;
            inicio = inicio->proximo;
        } else {
            Item *anterior = inicio;
            int pos = 1;
            while (pos < idx - 1) {
                anterior = anterior->proximo;
                pos++;
            }
            itemRemovido = anterior->proximo;
            anterior->proximo = itemRemovido->proximo;
        }

        delete itemRemovido;
        tamanho--;
    }

    void exibe() override {
        Item *atual = inicio;
        while (atual != nullptr) {
            std::cout << atual->dado << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

    int tam() override {
        return tamanho;
    }
};