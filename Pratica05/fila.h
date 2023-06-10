template <class T>
class Fila {
private:
    T *itens;
    int capacidade;
    int numItens;
    int inicio;
    int fim;

public:
    Fila(int cap) {
        capacidade = cap;
        numItens = 0;
        inicio = 0;
        fim = 0;
        itens = new T[capacidade];
    }

    ~Fila() {
        delete[] itens;
    }

    void enfileira(const T &item) {
        if (cheia()) {
            throw "Fila cheia";
        }
        itens[fim] = item;
        fim = (fim + 1) % capacidade;
        numItens++;
    }

    T desenfileira() {
        if (vazia()) {
            throw "Fila vazia";
        }
        T item = itens[inicio];
        inicio = (inicio + 1) % capacidade;
        numItens--;
        return item;
    }

    int cheia() {
        return numItens == capacidade;
    }

    int vazia() {
        return numItens == 0;
    }

    int tamanho() {
        return numItens;
    }
};
