template <typename T>
class PilhaArray : public PilhaBase<T> {
private:
    T* items;
    int capacidade;
    int topo;

public:
    PilhaArray(int capacidade) {
        this->capacidade = capacidade;
        this->topo = -1;
        this->items = new T[capacidade];
    }
    
    ~PilhaArray() {
        delete[] items;
    }

    void empilha(T item) override {
        if (topo == capacidade - 1) {
            throw "Estouro da pilha";
        }
        topo++;
        items[topo] = item;
    }

    T desempilha() override {
        if (topo == -1) {
            throw "Pilha vazia";
        }
        T item = items[topo];
        topo--;
        return item;
    }

    int tamanho() override {
        return topo + 1;
    }
};

