#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Hidrometro.hpp"

namespace hidrometro
{

class Controlador
{
public:
    Controlador();

    void configurarTempo(double tempoTotalSeg, double dtSeg);
    void configurarEntrada(const Entrada& e);
    void executar();

    const Hidrometro& getHidrometro() const;

private:
    Hidrometro hidrometro_;
    double tempoTotalSeg_;
    double dtSeg_;
};

}

#endif