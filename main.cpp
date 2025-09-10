#include "Entrada.hpp"
#include "Medicao.hpp"
#include "Hidrometro.hpp"
#include "Display.hpp"
#include "Controlador.hpp"
#include "Saida.hpp"
#include <iostream>

using namespace hidrometro;

static void runCaso(const char* titulo,
                    double bitola, double vazao, SentidoFluxo sentido,
                    bool arPresente, double pctAr,
                    double TFS, double DT,
                    bool salvarTxt)
{
    std::cout << "\n=== " << titulo << " ===\n";
    Entrada e;
    e.entradaFluxo(bitola, vazao, sentido);
    e.definirAr(arPresente, pctAr);

    Controlador ctrl;
    ctrl.configurarEntrada(e);
    ctrl.configurarTempo(TFS, DT);

    Display disp;
    disp.imprimirResumoConfig(e, TFS, DT);

    ctrl.executar();
    disp.imprimir(ctrl.getHidrometro());

    if (salvarTxt) {
        Saida out;
        std::cout << "TXT salvo em: " << out.salvarTxt(ctrl.getHidrometro()) << "\n";
    }
}

int main() {
    // 1) Base
    runCaso("BASE (10% ar, Direto)", 20.0, 12.0, SentidoFluxo::Direto, true, 0.10, 30.0, 0.5, true);

    // 2) Sem ar
    runCaso("SEM AR (Direto)",       20.0, 12.0, SentidoFluxo::Direto, false, 0.0, 30.0, 0.5, false);

    // 3) Reverso
    runCaso("REVERSO (nao soma)",    20.0, 12.0, SentidoFluxo::Reverso, true, 0.10, 10.0, 0.5, false);

    // (Opcional) 4) DT diferente
    // runCaso("DT=0.1s vs 1.0s (mesmo total)", 20.0, 12.0, SentidoFluxo::Direto, true, 0.10, 30.0, 0.1, false);
    // runCaso("DT=1.0s (comparacao)",          20.0, 12.0, SentidoFluxo::Direto, true, 0.10, 30.0, 1.0,  false);

    return 0;
}