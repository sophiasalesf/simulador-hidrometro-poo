#include "Display.hpp"
#include <iostream>
#include <iomanip>

namespace hidrometro
{

using std::cout;

void Display::imprimirResumoConfig(const Entrada& e, double tempoTotalSeg, double dtSeg) const 
{
    using std::cout; using std::fixed; using std::setprecision;

    int pctAr = static_cast<int>(e.getArPercentual() * 100.0 + 0.5);

    cout << "TFS=" << std::setprecision(0) << std::fixed << tempoTotalSeg
         << " | VAZAO=" << setprecision(2) << e.getVazao()
         << " | PCT_AR=" << pctAr
         << " | BITOLA=" << setprecision(1) << e.getBitola()
         << " | SENTIDO=" << (e.getSentido() == SentidoFluxo::Direto ? "Direto" : "Reverso")
         << " | DT=" << setprecision(2) << dtSeg
         << "\n";
}

void Display::imprimir(const Hidrometro& h) const {
    const auto& m = h.getMedicao();
    auto d = m.getDigitos();

    std::ostringstream od;
    od << "[" << d[0] << d[1] << d[2] << d[3] << "]";

    std::cout << "HIDROMETRO\n";
    std::cout << "  Odometro (m3): " << od.str() << "\n";
    std::cout << "  Litros (L)   : " << d[4] << "\n";
    std::cout << "  Decilitros   : " << d[5] << "\n";
    std::cout << "  Total (m3)   : " << std::fixed << std::setprecision(4)
              << m.getTotalM3() << "\n";
}

}