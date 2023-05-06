#include "veiculo.h"

// Veiculo
Veiculo::Veiculo(const char *nome)
{
    this->nome = nome;
    std::cout << "Objeto " << this->nome << " criado." << std::endl;
};

Veiculo::~Veiculo()
{
    std::cout << "Objeto " << this->nome << " destruído." << std::endl;
};

// Terrestre
Terrestre::Terrestre(const char *nome) : Veiculo(nome){};
Terrestre::~Terrestre()
{
    std::cout << "subObjeto " << this->nome << " destruído." << std::endl;
};

void Terrestre::setCapacidadeMax(int newcap_pass)
{
    this->cap_pass = newcap_pass;
}
int Terrestre::getCap_pass()
{
    return cap_pass;
};

// Aquatico
Aquatico::Aquatico(const char *nome) : Veiculo(nome){};
Aquatico::~Aquatico()
{
    std::cout << "subObjeto " << this->nome << " destruído." << std::endl;
};

void Aquatico::setCargaMax(float newcarga_max)
{
    this->carga_max = newcarga_max;
};
int Aquatico::getCarga_max()
{
    return carga_max;
};

// Aereo
Aereo::Aereo(const char *nome) : Veiculo(nome){};
Aereo::~Aereo()
{
    std::cout << "subObjeto" << this->nome << " destruído." << std::endl;
};
void Aereo::setVelocidadeMax(int newvel_max)
{
    this->vel_max = newvel_max;
};
int Aereo::getVel_max()
{
    return vel_max;
};

// Mover
void Terrestre::mover()
{
    std::cout << "Veiculo"
              << " Terrestre"
              << " moveu" << std::endl;
};
void Aquatico::mover()
{
    std::cout << "Veiculo"
              << " Aquatico"
              << " moveu" << std::endl;
};
void Aereo::mover()
{
    std::cout << "Veiculo"
              << " Aereo"
              << " moveu" << std::endl;
};

Anfibio::Anfibio(const char *nome) : Veiculo(nome), Terrestre(), Aquatico(){};
void Anfibio::mover()
{
    Terrestre::mover();
    Aquatico::mover();
};