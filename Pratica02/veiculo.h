#include <iostream>
// Parte 1: Preparação / Parte 2: Criando uma hierarquia de classes simples
/*
class Veiculo
{
protected:
    std::string nome;

public:
    Veiculo(const char *nome)
    {
        this->nome = nome;
        std::cout << "Objeto " << this->nome << " criado." << std::endl;
    };

    ~Veiculo()
    {
        std::cout << "Objeto " << this->nome << " destruído." << std::endl;
    };
};

class Terrestre : public Veiculo
{
public:
    Terrestre(const char *nome) : Veiculo(nome)
    {
    }

    ~Terrestre()
    {
        std::cout << "Objeto " << this->nome << " destruído." << std::endl;
    };
};

class Aquatico : public Veiculo
{
public:
    Aquatico(const char *nome) : Veiculo(nome)
    {
    }

    ~Aquatico()
    {
        std::cout << "Objeto " << this->nome << " destruído." << std::endl;
    };
};

class Aereo : public Veiculo
{
public:
    Aereo(const char *nome) : Veiculo(nome)
    {
    }

    ~Aereo()
    {
        std::cout << "Objeto " << this->nome << " destruído." << std::endl;
    };
};
*/
// Parte 3 /Parte 4 /Parte 5
class Veiculo
{
protected:
    std::string nome;

public:
    Veiculo(const char *nome);
    Veiculo();

    virtual ~Veiculo();
    virtual void mover() = 0;
};

class Terrestre : public virtual Veiculo
{
private:
    int cap_pass = 5;

protected:
    Terrestre();

public:
    Terrestre(const char *nome);
    ~Terrestre();
    void setCapacidadeMax(int newcap_pass);
    int getCap_pass();
    void mover();
};

class Aquatico : public virtual Veiculo
{
private:
    float carga_max = 10;

protected:
    Aquatico();
public:
    Aquatico(const char *nome);
    ~Aquatico();
    void setCargaMax(float newarga_max);
    int getCarga_max();
    void mover();
};

class Aereo : public Veiculo
{
private:
    float vel_max = 100;

public:
    Aereo(const char *nome);
    ~Aereo();
    void setVelocidadeMax(int newvel_max);
    int getVel_max();
    void mover();
};

class Anfibio : public Terrestre, Aquatico
{
private:
public:
    Anfibio(const char *nome);
    void mover();
};