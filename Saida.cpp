#include "Saida.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <stdexcept>

namespace hidrometro
{

using std::string;
using std::fixed;
using std::setprecision;

static string timestampedTxtName()
{
    std::time_t t = std::time(nullptr);
    std::tm tm{};
    if (auto* p = std::localtime(&t)) { tm = *p; }
    char buf[64];
    std::strftime(buf, sizeof(buf), "hidrometro_%Y%m%d_%H%M%S.txt", &tm);
    return string(buf);
}

static const char* sentidoToStr(SentidoFluxo s) 
{
    return (s == SentidoFluxo::Direto) ? "Direto" : "Reverso";
}

string Saida::salvarTxt(const Hidrometro& h, const string& caminho)
{
    const Entrada& e = h.getEntrada();
    const Medicao& m = h.getMedicao();
    auto d = m.getDigitos();

    std::ostringstream os;
    os << "-Simulador de Hidrômetro-\n";
    os << "Bitola (mm): " << fixed << setprecision(1) << e.getBitola() << "\n";
    os << "Vazao (L/min): " << fixed << setprecision(2) << e.getVazao()  << "\n";
    os << "Sentido: " << sentidoToStr(e.getSentido()) << "\n";
    os << "Ar presente: " << (e.getArPresente() ? "sim" : "nao") << "\n";
    os << "Ar percentual (%): " << fixed << setprecision(2) << (e.getArPercentual()*100.0) << "\n\n";

    os << "Odometro m3: [" << d[0] << d[1] << d[2] << d[3] << "] L=" << d[4] << " dL=" << d[5] << "\n";
    os << "Total (m3): " << fixed << setprecision(4) << m.getTotalM3() << "\n";
    os << "Total (L): " << m.getTotalLitros() << " | dL: " << m.getDecilitros() << "\n";

    string file = caminho.empty() ? timestampedTxtName() : caminho;

    std::ofstream fout(file.c_str(), std::ios::out | std::ios::trunc);
    if (!fout) throw std::runtime_error("Nao foi possivel escrever em: " + file);
    fout << os.str();
    fout.close();

    ultimoCaminho_ = file;
    return ultimoCaminho_;
}

}