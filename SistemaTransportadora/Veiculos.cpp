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
    this->localização = "\0";
    this->modelo = "\0";
    this->tipo = "\0";
    this->disponibilidade = 1;
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

string Veiculo::getLocalização()
{
    return this->localização;
}
int Veiculo::setLocalização(const string localização)
{
    if(localização.length() > 50){
        cout << "Localização deve ter no máximo 50 caracteres" << endl;
        return 0;
    }

    this->localização = localização;

    return 1;
}

int Veiculo::getDisponibilidade()
{
    return this->disponibilidade;
}
int Veiculo::setDisponibilidade(const int disponibilidade)
{
    if(disponibilidade > 0){
        this->disponibilidade = 1;
    }
    else if(disponibilidade == 0){
        this->disponibilidade = 0;
    }
    else{
        cout << "Valor para disponibilidade inválido" << endl;
        return 0;
    }

    return 1;
}