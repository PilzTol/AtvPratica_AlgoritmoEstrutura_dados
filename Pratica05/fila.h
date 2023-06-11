template <class T>
class FilaBase {
public:
    virtual ~FilaBase() {}
    virtual void enfileira(const T& item) = 0;
    virtual T desenfileira() = 0;
    virtual bool cheia() const = 0;
    virtual bool vazia() const = 0;
    virtual int tamanho() const = 0;
};