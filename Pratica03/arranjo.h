#include <iostream>

namespace erro
{
    class IndiceInvalido
    {
    private:
        std::string mensagem;

    public:
        IndiceInvalido(const std::string &mensagem) : mensagem(mensagem) {}
        std::string getMensagem() const
        {
            return mensagem;
        }
    };
}

// Classe Arranjo...
template <class T>
class Arranjo
{
private:
    int tamanho; // tamanho do arranjo
    T *items;    // items do arranjo
public:
    Arranjo(int tam)
    { // instanciar o array de items com new (pratica 1) e setar tamanho;
        tamanho = tam;
        items = new T[tamanho];
    }
    virtual ~Arranjo()
    { // destruir o array de items (prática 1);
        delete[] items;
    }
    virtual T get(int idx)
    { // retornar um item do array a partir do indice;
        /*
        if (idx < 0 || idx >= tamanho)
        {
            throw IndiceInvalido("Indice fora do limite do array");
        }*/
        return items[idx];
    }
    virtual void set(int idx, const T &item)
    { // set o item do array apontado pelo indice usando
        /*
        if (idx < 0 || idx >= tamanho)
        {
            throw IndiceInvalido("Indice fora do limite do array");
        }*/
        items[idx] = item;
    }
    virtual void exibir();
};

template <class T>
void Arranjo<T>::exibir()
{ // exibir cada item numa linha da forma "<idx>: <item>"
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << i << ": " << items[i] << std::endl;
    }
}
