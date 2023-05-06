#include<iostream>
#include<string>

class Roda
{
    private:
        
    public:
    Roda()
    {
        std::cout << "Novo objeto construído \n";
    };
    ~Roda()
    {
        std::cout << "Objeto destruído \n";
    };
};

class Veiculo
{
    private:
        std::string nome;
        int num_rodas;
        Roda* rodas;
    public:      
        Veiculo(const char *nome) 
        {
            this->nome = std::string(nome); 
            std::cout << "\nNovo objeto construído: " << this->nome << std::endl; 
            this->rodas = NULL;
        };
        ~Veiculo() 
        {
            std::cout << "Objeto destruído: " << this->nome << std::endl;
            delete[] this->rodas;
        };
        void setNumRodas(int rodas_qtd);
        int getNumRodas();
};

 