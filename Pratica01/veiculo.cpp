#include<iostream>
#include "veiculo.h"

void Veiculo::setNumRodas(int rodas_qtd)
{
    num_rodas = rodas_qtd;
    delete[] rodas;
    this->rodas = new Roda[rodas_qtd];
};
int Veiculo::getNumRodas()
{
    return num_rodas;
};