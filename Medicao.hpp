#ifndef MEDICAO_HPP
#define MEDICAO_HPP

#include <array>
#include <cstdint>

namespace hidrometro
{

using u64 = std::uint64_t;

class Medicao
{
public:
    using Digitos = std::array<int, 6>;

    Medicao();

    void acrescentarLitros(double litros);
    void reset();

    u64    getTotalDecilitros() const;
    u64    getTotalLitros() const;
    double getTotalM3() const;

    u64 getM3Inteiros() const;
    int getLitrosRestantes() const;
    int getDecilitros() const;

    Digitos getDigitos() const;

private:
    u64    totalDecilitros_;
    double residualLitros_;
};

}

#endif