#include <iostream>
#include "Carros.h"

using namespace std;

Carro::Carro()
{
    this->tipo = "Carro";
    this->motor = "\0";
    this->combustivel = "\0";
}

Carro::Carro(
    const string placa,
    const float capacidade,
    const int ano,
    const string chassi,
    const string modelo,
    const string localizacao,
    const int disponibilidade,
    const string combustivel, 
    const string motor

) : Veiculo(placa, "Carro", capacidade, ano, chassi, modelo, localizacao, disponibilidade)
{
    this->combustivel = combustivel;
    this->motor = motor;
}

Carro::~Carro()
{
    ;
}

string Carro::getCombustivel()
{
    return this->combustivel;
}
int Carro::setCombustivel(string combustivel)
{
    if(combustivel.length() > 30){
        cout << "Combustível deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->combustivel = combustivel;

    return 1;
}

string Carro::getMotor()
{
    return this->motor;
}
int Carro::setMotor(string motor)
{
    if(motor.length() > 30){
        cout << "Motor deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->motor = motor;

    return 1;
}

ostream& operator<<(ostream& ostr, Carro& carro)
{
    ostr << "Ano: " << carro.getAno() << endl;
    ostr << "Tipo: " << carro.getTipo() << endl;
    ostr << "Capacidade: " << carro.getCapacidade() << endl;
    ostr << "Chassi: " << carro.getChassi() << endl;
    ostr << "Localização: " << carro.getLocalizacao() << endl;
    ostr << "Modelo: " << carro.getModelo() << endl;
    ostr << "Combustível: " << carro.getCombustivel() << endl;
    ostr << "Motor: " << carro.getMotor() << endl;
    ostr << "Disponibilidade: " << carro.getDisponibilidade() << endl;

    return ostr;
}

bool operator==(const Carro& este, const Carro& outro)
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
        este.motor == outro.motor &&
        este.combustivel == outro.combustivel
    ){
        return true;
    }

    return false;
}