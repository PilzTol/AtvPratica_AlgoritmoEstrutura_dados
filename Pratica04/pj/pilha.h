#include <stdexcept>

template <class T>
class Pilha {
private:
    T *items; // ponteiro para array de items
    int capacidade; // capacidade da pilha
    int topo; // posição do topo da pilha
    
public:
    Pilha(int capacidade) {
        this->capacidade = capacidade;
        this->items = new T[capacidade];
        this->topo = -1; // pilha vazia
    }
    
    ~Pilha() {
        delete[] this->items;
    }
    
    void empilha(T item) {
        if (this->topo == this->capacidade - 1) {
            throw std::overflow_error("Estouro da pilha");
        }
        this->topo++;
        this->items[this->topo] = item;
    }
    
    T desempilha() {
        if (this->topo == -1) {
            throw std::underflow_error("Pilha vazia");
        }
        T item = this->items[this->topo];
        this->topo--;
        return item;
    }
    
    int tamanho() {
        return this->topo + 1;
    }
};
