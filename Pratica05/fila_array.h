template <class T>
class FilaArray : public FilaBase<T> {
private:
    T* itens;
    int capacidade;
    int numItens;
    int inicio;
    int fim;

public:
    FilaArray(int cap) {
        capacidade = cap;
        numItens = 0;
        inicio = 0;
        fim = 0;
        itens = new T[capacidade];
    }

    ~FilaArray() {
        delete[] itens;
    }

    void enfileira(const T& item) override {
        if (cheia()) {
            throw "Fila cheia";
        }
        itens[fim] = item;
        fim = (fim + 1) % capacidade;
        numItens++;
    }

    T desenfileira() override {
        if (vazia()) {
            throw "Fila vazia";
        }
        T item = itens[inicio];
        inicio = (inicio + 1) % capacidade;
        numItens--;
        return item;
    }

    bool cheia() const override {
        return numItens == capacidade;
    }

    bool vazia() const override {
        return numItens == 0;
    }

    int tamanho() const override {
        return numItens;
    }
};