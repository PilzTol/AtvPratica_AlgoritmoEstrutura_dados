#include "pilha.h"

struct Prato
{
    int dado;
    Prato *next;
};

template <typename T>
class PilhaLigada : public PilhaBase<T>
{
private:
    Prato *topo;
    int capacidade;
    int total_pratos;

public:
    PilhaLigada(int valor_maximo_par = 0)
    {
        topo = nullptr;
        capacidade = valor_maximo_par;
        total_pratos = 0;
    }

    ~PilhaLigada()
    {
        Prato *temp;
        while (topo != nullptr)
        {
            temp = topo;
            topo = topo->next;
            delete temp;
        }
    }

    void empilha(T item) override
    {
        if ((this->total_pratos == this->capacidade) && (this->capacidade != 0))
        {
            throw "Estouro da pilha";
        }
        Prato *newPrato = new Prato;
        newPrato->dado = item;
        newPrato->next = topo;
        topo = newPrato;
        ++total_pratos;
    }

    T desempilha() override
    {
        if (topo == nullptr)
        {
            throw "Pilha vazia";
        }
        Prato *temp = topo;
        T dado_desempilhado = topo->dado;
        topo = topo->next;
        delete temp;
        --total_pratos;
        return dado_desempilhado;
    }

    int tamanho() override
    {
        int count = 0;
        Prato *temp = topo;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        delete temp;
        return count;
    }
};
