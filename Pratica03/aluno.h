#include "arranjo.h"
#include <string>

class Aluno
{
private:
    std::string nome;
    std::string mat;

public:
    Aluno() {}
    Aluno(const char *nome, const char *mat) : nome(nome), mat(mat) {}
    friend class Arranjo<Aluno>;
};

template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {
    items[idx].nome = aluno.nome;
    items[idx].mat = aluno.mat;
}

template<>
void Arranjo<Aluno>::exibir() {
    for (int i = 0; i < tamanho; i++) {
        std::cout << i << " : " << items[i].mat << " = " << items[i].nome << std::endl;
    }
}
