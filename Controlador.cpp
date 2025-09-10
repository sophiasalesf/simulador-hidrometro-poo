#include "Controlador.hpp"
#include <stdexcept>

using std::invalid_argument;

namespace hidrometro
{

Controlador::Controlador()
    : hidrometro_(), tempoTotalSeg_(0.0), dtSeg_(0.0) {}

void Controlador::configurarTempo(double tempoTotalSeg, double dtSeg)
{
    if (tempoTotalSeg < 0.0) 
        throw invalid_argument("tempoTotalSeg deve ser >= 0");
    if (dtSeg <= 0.0)        
        throw invalid_argument("dtSeg deve ser > 0");
    tempoTotalSeg_ = tempoTotalSeg;
    dtSeg_ = dtSeg;
}

void Controlador::configurarEntrada(const Entrada& e)
{
    hidrometro_.setEntrada(e);
}

void Controlador::executar()
{
    if (dtSeg_ <= 0.0)     
        throw invalid_argument("chame configurarTempo antes (dtSeg <= 0)");
    if (tempoTotalSeg_ < 0.0) 
        throw invalid_argument("tempoTotalSeg invalido");

    double acumulado = 0.0;
    while (acumulado + dtSeg_ <= tempoTotalSeg_)
    {
        hidrometro_.medir(dtSeg_);
        acumulado += dtSeg_;
    }

    double resto = tempoTotalSeg_ - acumulado;
    if (resto > 0.0)
    {
        hidrometro_.medir(resto);
    }
}

const Hidrometro& Controlador::getHidrometro() const
{
    return hidrometro_;
}

}
