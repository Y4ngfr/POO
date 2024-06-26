#include <iostream>
#include <string>
#include "Veiculos.h"

using namespace std;

Veiculo::Veiculo()
{
    this->placa = "\0";
    this->ano = 0;
    this->capacidade = 0;
    this->chassi = "\0";
    this->localizacao = "\0";
    this->modelo = "\0";
    this->tipo = "\0";
    this->disponibilidade = true;
}

Veiculo::Veiculo(
    const string placa,
    const string tipo,
    const float capacidade, 
    const int ano, 
    const string chassi, 
    const string modelo, 
    const string localizacao, 
    const bool disponibilidade
    )
{
    this->placa = placa;
    this->ano = ano;
    this->capacidade = capacidade;
    this->chassi = chassi;
    this->localizacao = localizacao;
    this->modelo = modelo;
    this->tipo = tipo;
    this->disponibilidade = disponibilidade;
}

Veiculo::~Veiculo()
{
    cout << "limpando memória.." << endl;
}

string Veiculo::getPlaca()
{
    return this->placa;
}
int Veiculo::setPlaca(const string placa)
{
    if(placa.length() != 7){
        cout << "Placa deve ter 7 caracteres" << endl;
        return 0;
    }

    this->placa = placa;

    return 1;
}

string Veiculo::getTipo()
{
    return this->tipo;
}
int Veiculo::setTipo(const string tipo)
{
    if(tipo.length() > 30){
        cout << "Tipo do veículo deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->tipo = tipo;

    return 1;
}

float Veiculo::getCapacidade()
{
    return this->capacidade;
}
int Veiculo::setCapacidade(float capacidade)
{
    if(capacidade < 0){
        cout << "capacidade negativa não permitida" << endl;
        return 0;
    }

    this->capacidade = capacidade;

    return 1;
}

int Veiculo::getAno()
{
    return this->ano;
}
int Veiculo::setAno(int ano)
{
    if(ano < 0){
        cout << "Ano negativo não permitido" << endl;
        return 0;
    }

    this->ano = ano;

    return 1;
}

string Veiculo::getChassi()
{
    return this->chassi;
}
int Veiculo::setChassi(const string chassi)
{
    if(chassi.length() > 30){
        cout << "Chassi deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->chassi = chassi;

    return 1;
}

string Veiculo::getModelo()
{
    return this->modelo;
}
int Veiculo::setModelo(const string modelo)
{
    if(modelo.length() > 30){
        cout << "Modelo deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->modelo = modelo;

    return 1;
}

string Veiculo::getLocalizacao()
{
    return this->localizacao;
}
int Veiculo::setLocalizacao(const string localizacao)
{
    if(localizacao.length() > 50){
        cout << "Localizacao deve ter no máximo 50 caracteres" << endl;
        return 0;
    }

    this->localizacao = localizacao;

    return 1;
}

bool Veiculo::getDisponibilidade()
{
    return this->disponibilidade;
}
int Veiculo::setDisponibilidade(const bool disponibilidade)
{
    this->disponibilidade = disponibilidade;

    return 1;
}

ostream& operator<<(ostream& ostr, Veiculo& veiculo)
{
    ostr << "Ano: " << veiculo.getAno() << endl;
    ostr << "Tipo: " << veiculo.getTipo() << endl;
    ostr << "Capacidade: " << veiculo.getCapacidade() << endl;
    ostr << "Chassi: " << veiculo.getChassi() << endl;
    ostr << "Localização: " << veiculo.getLocalizacao() << endl;
    ostr << "Modelo: " << veiculo.getModelo() << endl;
    ostr << "Disponibilidade: " << veiculo.getDisponibilidade() << endl;

    return ostr;
}

bool operator==(const Veiculo& este, const Veiculo& outro)
{
    if(
        este.ano == outro.ano &&
        este.capacidade == outro.capacidade &&
        este.chassi == outro.chassi &&
        este.disponibilidade == outro.disponibilidade &&
        este.localizacao == outro.localizacao &&
        este.modelo == outro.modelo &&
        este.placa == outro.placa &&
        este.tipo == outro.tipo
    ){
        return true;
    }

    return false;
}