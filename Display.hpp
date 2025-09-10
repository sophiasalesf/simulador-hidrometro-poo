#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Hidrometro.hpp"
#include <string>

namespace hidrometro
{
class Display 
{
public:
    void imprimirResumoConfig(const Entrada& e, double tempoTotalSeg, double dtSeg) const;

    void imprimir(const class Hidrometro& h) const;
};


}

#endif