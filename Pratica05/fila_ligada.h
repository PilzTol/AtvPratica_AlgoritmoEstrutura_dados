#include "fila.h"

template <class T>
class FilaLigada : public FilaBase<T> {
private:
    struct Item {
        T dado;
        Item* proximo;
    };

    Item* inicio;
    Item* fim;
    int numItens;
    int capacidade;

public:
    FilaLigada(int cap = 0) {
        inicio = nullptr;
        fim = nullptr;
        numItens = 0;
        capacidade = cap;
    }

    ~FilaLigada() {
        while (!vazia()) {
            desenfileira();
        }
    }

    void enfileira(const T& item) override {
        if (cheia()) {
            throw "Fila cheia";
        }
        Item* novoItem = new Item;
        novoItem->dado = item;
        novoItem->proximo = nullptr;

        if (vazia()) {
            inicio = novoItem;
            fim = novoItem;
        } else {
            fim->proximo = novoItem;
            fim = novoItem;
        }

        numItens++;
    }

    T desenfileira() override {
        if (vazia()) {
            throw "Fila vazia";
        }

        T item = inicio->dado;
        Item* temp = inicio;

        if (inicio == fim) {
            inicio = nullptr;
            fim = nullptr;
        } else {
            inicio = inicio->proximo;
        }

        delete temp;
        numItens--;

        return item;
    }

    bool cheia() const override {
        return ((numItens == capacidade) && (capacidade != 0));
    }

    bool vazia() const override {
        return numItens == 0;
    }

    int tamanho() const override {
        return numItens;
    }
};