Aqui está o código em C++ para os métodos enqueue e dequeue de uma fila usando ponteiros:

template <typename T>
void Queue<T>::enqueue(T dados) {
    Node<T> *novoNo = new Node<T>(dados);
    if (novoNo == nullptr) {
        throw std::runtime_error("Queue overflow");
    }
    novoNo->setProx(nullptr);
    if (inicio == nullptr) {
        inicio = novoNo;
    } else {
        final->setProx(novoNo);
    }
    final = novoNo;
}

template <typename T>
T Queue<T>::dequeue() {
    if (inicio == nullptr) {
        throw std::runtime_error("Queue underflow");
    }
    Node<T> *tmp = inicio;
    inicio = inicio->getProx();
    if (inicio == nullptr) {
        final = nullptr;
    }
    T dados = tmp->getDados();
    delete tmp;
    return dados;
}