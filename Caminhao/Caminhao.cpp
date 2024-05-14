#include <iostream>
#include "Caminhao.h"

using namespace std;

Caminhao::Caminhao() 
{
    this->tipo = "caminhão";
    this->peso = 0;
    this->tracao = "\0";
}

Caminhao::Caminhao(
    const string placa,
    const float capacidade,
    const int ano,
    const string chassi,
    const string modelo,
    const string localizacao,
    const int disponibilidade,
    const float peso, 
    const string tracao

) : Veiculo(placa, "Caminhão", capacidade, ano, chassi, modelo, localizacao, disponibilidade)
{
    this->peso = peso;
    this->tracao = tracao;
}

Caminhao::~Caminhao()
{
    ;
}

float Caminhao::getPeso()
{ 
    return this->peso; 
}
int Caminhao::setPeso(float peso)
{ 
    if(peso < 0){
        cerr << "Peso negativo não permitido" << endl;
        return 0;
    }

    this->peso = peso; 

    return 1;
}

string Caminhao::getTracao()
{
     return this->tracao; 
}
int Caminhao::setTracao(string tracao)
{ 
    if(tracao != "6x2" && tracao != "6x4" && tracao != "8x2" && tracao != "8x4")
    {
        cerr << "Valor para tracao inválido" << endl;

        return 0;
    }

    this->tracao = tracao; 

    return 1;
}

ostream& operator<<(ostream& ostr, Caminhao& caminhao)
{
    ostr << "Ano: " << caminhao.getAno() << endl;
    ostr << "Tipo: " << caminhao.getTipo() << endl;
    ostr << "Capacidade: " << caminhao.getCapacidade() << endl;
    ostr << "Chassi: " << caminhao.getChassi() << endl;
    ostr << "Localização: " << caminhao.getLocalizacao() << endl;
    ostr << "Modelo: " << caminhao.getModelo() << endl;
    ostr << "Peso: " << caminhao.getPeso() << endl;
    ostr << "Tração: " << caminhao.getTracao() << endl;
    ostr << "Disponibilidade: " << caminhao.getDisponibilidade() << endl;
    ostr << endl;

    return ostr;
}

bool operator==(const Caminhao& este, const Caminhao& outro)
{
    if(
        este.ano == outro.ano &&
        este.capacidade == outro.capacidade &&
        este.chassi == outro.chassi &&
        este.disponibilidade == outro.disponibilidade &&
        este.localizacao == outro.localizacao &&
        este.modelo == outro.modelo &&
        este.placa == outro.placa &&
        este.tipo == outro.tipo &&
        este.tracao == outro.tracao &&
        este.peso == outro.peso
    ){
        return true;
    }

    return false;
}