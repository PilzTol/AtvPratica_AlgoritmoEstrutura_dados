#include<iostream>
#include<string>
#include "veiculo.cpp"
//Parte 1: Preparação inicial
/*
int main(void)
{
    std::cout << "Primeira aplicação C++";
}
*/

//Parte 2: Criando e instanciando uma classe
/*
class Veiculo
{
    private:
        std::string nome;
        int num_rodas;
    public:      
        Veiculo(const char *nome) 
        {
            this->nome = std::string(nome); 
            std::cout << "Novo objeto construído " << this->nome << std::endl; 
        };
        ~Veiculo() 
        {
            std::cout << "Objeto destruído " << this->nome << std::endl;
        };
        void setNumRodas(int rodas_qtd);
        int getNumRodas();
};

void Veiculo::setNumRodas(int rodas_qtd)
{
    num_rodas = rodas_qtd;
};
int Veiculo::getNumRodas()
{
    return num_rodas;
};

/*
int main(void)
{ 
    Veiculo carro1("CeltaAzul"); 
    {
        Veiculo carro2("CeltaCinza");
        {
            Veiculo carro3("Celtapreto");
        }
    } 
} 
*/

//Parte 3: Instanciando objetos no heap
/*
int main(void)
{
    Veiculo * objet1 = new Veiculo("CeltaAzul");
    {
        Veiculo *objet2 = new Veiculo("CeltaCinza");
        {
            Veiculo *objet3 = new Veiculo("CeltaPreto");
            delete objet3;   
        }
        delete objet2;
    }
    delete objet1;     
}
*/

//Parte 4: Trabalhando com visibilidade de membros
/*
int main(void)
{
    Veiculo * carro1 = new Veiculo("CeltaAzul");
    carro1->setNumRodas(4);
    std::cout << "Numero de rodas: " << carro1->getNumRodas(); 
}
*/

//Parte 5: Trabalhando com sub-objetos

int main(void)
{
    Veiculo * carro1 = new Veiculo("CeltaAzul");
    carro1->setNumRodas(4);
    std::cout << "Numero de rodas: " << carro1->getNumRodas();
    delete carro1; 
}
