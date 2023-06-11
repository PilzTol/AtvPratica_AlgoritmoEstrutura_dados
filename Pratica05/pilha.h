template <typename T>
class PilhaBase {
public:
    virtual void empilha(T item) = 0;
    virtual T desempilha() = 0;
    virtual int tamanho() = 0;
    virtual ~PilhaBase() {}
};