#include <iostream>
//#include "veiculo.cpp"

// Parte 1: Preparação / Parte 2: Criando uma hierarquia de classes simples
/*
int main(void)
{
    Aereo v1("Boing477");
    Terrestre v2("Uno");
    Aquatico v3("Submarino22");
}
*/

// Parte 3: Especializando as subclasses
// Veiculo
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
// Parte 3: Especializando as subclasses
class Veiculo
{
protected:
    std::string nome;

public:
    Veiculo(const char *nome);
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

class Anfibio : public virtual Terrestre, Aquatico
{   
    private:

    public:
        Anfibio (const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {}
        void mover();
   
    

};

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

//Mover
void Terrestre::mover()
{
    std::cout << "Veiculo" << " Terrestre" << " moveu" << std::endl;
};
void Aquatico::mover()
{
    std::cout << "Veiculo" << " Aquatico" << " moveu" << std::endl;
};
void Aereo::mover()
{
    std::cout << "Veiculo" << " Aereo" << " moveu" << std::endl;
};

void Anfibio::mover(){
    Terrestre::mover();
    Aquatico::mover();
};

int main(void)
{
    Veiculo *terr, *aqua, *aereo;
    terr = new Terrestre("VT1");
    aqua = new Aquatico("VQ1");
    aereo = new Aereo("VA1");
    ((Aereo *)aereo)->setVelocidadeMax(1040.5);

    // Parte 5: Herança Múltipla
    dynamic_cast<Terrestre *>(terr)->setCapacidadeMax(45);
    dynamic_cast<Aquatico *>(aqua)->setCargaMax(12.5);

    Veiculo *anfi = new Anfibio("Nemo");
    anfi->mover();

    // Parte 4: Trabalhando com métodos virtuais
    terr->mover();
    aqua->mover();
    aereo->mover();
    delete terr;
    delete aqua;
    delete aereo;
}

// Superclasse * ponteiro = new Subclasse();
//((Subclasse *)ponteiro)->metodoSubclasse();
// dynamic_cast<NovoTipo>(var)->metodo();