#include <stdexcept>

template <class T>
class ListaBase {
public:
    virtual ~ListaBase() {}
    virtual void adiciona(const T &item) = 0;
    virtual T pega(int idx) = 0;
    virtual void insere(int idx, const T &item) = 0;
    virtual void remove(int idx) = 0;
    virtual void exibe() = 0;
    virtual int tam() = 0;
};