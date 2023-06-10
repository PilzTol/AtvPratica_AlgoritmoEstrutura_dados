struct Prato
{
    int dado;
    Prato *next;
};

template <typename T>
class Pilha
{
private:
    Prato *topo;
    int valor_maximo;
    int total_pratos;

public:
    Pilha(int valor_maximo_par = 0)
    {
        topo = nullptr;
        valor_maximo = valor_maximo_par;
    }

    ~Pilha()
    {
        Prato *temp;
        while (topo != nullptr)
        {
            temp = topo;
            topo = topo->next;
            delete temp;
        }
    }

    void empilha(T item)
    {
        int count = 0;
        Prato *temp = topo;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        };
        if((this->total_pratos == this->valor_maximo))
        {
          throw "Estouro da pilha";
        };
        Prato *newPrato = new Prato;
        newPrato->dado = item;
        newPrato->next = topo;
        topo = newPrato;
        delete temp;
    }

    T desempilha()
    {
        if (topo == nullptr)
        {
            throw "Pilha vazia";
        }
        Prato *temp = topo;
        T dado_desempilhado = topo->dado;
        topo = topo->next;
        delete temp;
        return dado_desempilhado;
    }

    int tamanho()
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
