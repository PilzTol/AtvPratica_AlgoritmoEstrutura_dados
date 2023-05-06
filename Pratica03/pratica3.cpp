#include <iostream>
#include "funcoes.h"
#include "aluno.h"

// Parte 1/Parte 2 : Peparação/Criando uma biblioteca de funções
/*
int main(void)
{
    int x = 5, y = 10, z = 30;
    std::cout << "Antes: x = " << x << " y = " << y << std::endl;
    trocar(x, y);
    std::cout << "Depois : x = " << x << " y = " << y << std::endl;
    std::cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << std::endl;
    std::cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << std::endl;
}
*/
// Parte 3 : Trabalhando com templates de funcoes

int main(void)
{
    std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;

    float x = 5, y = 10, z = 30;
    std::cout << "Antes: x = " << x << " y = " << y << std::endl;
    funcoes::trocar(x, y);
    std::cout << "Depois : x = " << x << " y = " << y << std::endl;
    std::cout << "Minimo entre " << x << " e " << y << ": " << funcoes::minimo(x, y) << std::endl;
    std::cout << "Maximo entre " << y << " e " << z << ": " << funcoes::maximo(y, z) << std::endl;
    std::cout << "Minimo de \"strA\" e \"strB\": " << funcoes::minimo("strA", "strB") << std::endl;
    std::cout << "Maximo de \"strA\" e \"strB\": " << funcoes::maximo("strA", "strB") << std::endl;

    // Parte 3 : Trabalhando com templates da classes
    std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
    
    Arranjo<int> arr(10);
    arr.set(4, 5);
    arr.set(7, 15);
    arr.set(8, 22);
    arr.exibir();

    std::cout<<std::endl;

    Arranjo<float> arrFloat(5);
    arrFloat.set(0, 3.14);
    arrFloat.set(2, 1.23);
    arrFloat.set(4, 0.99);
    arrFloat.exibir();
    try
    {
        // tenta acessar uma posição inválida do array //Isso está meio que desativado no momento //Pode dar erro em tempo de execução.
        arr.set(11, 5);
        // arr.get(11);
    }
    catch (erro::IndiceInvalido &e)
    {
        std::cout << "Erro:" << e.getMensagem() << std::endl;
    }

    // Parte 4: Especializando templates de classes
    std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
    Arranjo<Aluno> turma(3);
    turma.set(0, Aluno("Joao", "1234"));
    turma.set(1, Aluno("Maria", "5235"));
    turma.set(2, Aluno("Jose", "2412"));
    turma.exibir();
}

/*
Nesse ponto a aplicação deve funcionar como esperado. Sem a especialização feita no
passo 2 o compilador não vai saber como realizar a exibição na saída (cout <<
aluno), usada no método exibir(). Se quisermos usar os métodos não
especializados, podemos sobrecarregar os operadores = e <<.
*/