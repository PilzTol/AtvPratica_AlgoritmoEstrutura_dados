template <typename T>
class Pilha {
private:
    T* items;
    int capacidade;
    int topo;

public:
    Pilha(int capacidade) {
        this->capacidade = capacidade;
        this->topo = -1;
        this->items = new T[capacidade];
    }
    
 
    ~Pilha() {
        delete[] items;
    }

    void empilha(T item) {
        if (topo == capacidade - 1) {
            throw "Estouro da pilha";
        }
        topo++;
        items[topo] = item;
    }

    T desempilha() {
        if (topo == -1) {
            throw "Pilha vazia";
        }
        T item = items[topo];
        topo--;
        return item;
    }

    int tamanho() {
        return topo + 1;
    }
};
