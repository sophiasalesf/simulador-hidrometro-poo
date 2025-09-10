#ifndef SAIDA_HPP
#define SAIDA_HPP

#include <string>
#include "Hidrometro.hpp"

namespace hidrometro
{

using std::string;

class Saida
{
public:
    string salvarTxt(const Hidrometro& h, const string& caminho = "");
    const string& getUltimoCaminho() const { return ultimoCaminho_; }

private:
    string ultimoCaminho_;
};

}

#endif
