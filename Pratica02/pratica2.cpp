#include <iostream>
#include "veiculo.cpp"

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

int main(void)
{
    std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
    Veiculo *terr, *aqua, *aereo;
    terr = new Terrestre("VT1");
    aqua = new Aquatico("VQ1");
    aereo = new Aereo("VA1");
    ((Aereo *)aereo)->setVelocidadeMax(1040.5);


    std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
    
    // Parte 5: Herança Múltipla
    dynamic_cast<Terrestre *>(terr)->setCapacidadeMax(45);
    dynamic_cast<Aquatico *>(aqua)->setCargaMax(12.5);

    Veiculo *anfi = new Anfibio("Nemo");
    anfi->mover();

    std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;

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