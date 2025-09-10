#include "Medicao.hpp"
#include <cmath>
#include <stdexcept>

using std::invalid_argument;

namespace hidrometro
{

Medicao::Medicao() : totalDecilitros_(0), residualLitros_(0.0) 
{}

void Medicao::acrescentarLitros(double litros)
{
    if (litros < 0.0)
    {
        throw invalid_argument("acrescentarLitros: valor negativo nao permitido");
    }

    double soma = residualLitros_ + litros;
    u64 incDL = static_cast<u64>(std::floor(soma * 10.0 + 1e-9));

    if (incDL > 0)
    {
        totalDecilitros_ += incDL;
        soma -= static_cast<double>(incDL) / 10.0;
    }

    residualLitros_ = soma;
}

void Medicao::reset()
{
    totalDecilitros_ = 0;
    residualLitros_  = 0.0;
}

u64 Medicao::getTotalDecilitros() const { return totalDecilitros_; }
u64 Medicao::getTotalLitros() const     { return totalDecilitros_ / 10ULL; }
double Medicao::getTotalM3() const      { return static_cast<double>(totalDecilitros_) / 10000.0; }
u64 Medicao::getM3Inteiros() const      { return totalDecilitros_ / 10000ULL; }

int Medicao::getLitrosRestantes() const
{
    return static_cast<int>((totalDecilitros_ / 10ULL) % 1000ULL); // 0..999
}

int Medicao::getDecilitros() const
{
    return static_cast<int>(totalDecilitros_ % 10ULL); // 0..9
}

Medicao::Digitos Medicao::getDigitos() const
{
    u64 m3 = totalDecilitros_ / 10000ULL;
    int m3Unidade = static_cast<int>( m3 % 10ULL);
    int m3Dezena  = static_cast<int>((m3 / 10ULL)   % 10ULL);
    int m3Centena = static_cast<int>((m3 / 100ULL)  % 10ULL);
    int m3Milhar  = static_cast<int>((m3 / 1000ULL) % 10ULL);

    int litros0a999 = static_cast<int>((totalDecilitros_ / 10ULL) % 1000ULL);
    int litro_unid  = litros0a999 % 10;
    int dL          = static_cast<int>(totalDecilitros_ % 10ULL);

    return {m3Milhar, m3Centena, m3Dezena, m3Unidade, litro_unid, dL};
}

}