#include <iostream>
#include "Motos.h"

using namespace std;

Moto::Moto()
{
    this->tipo = "Moto";
    this->motor = "\0";
    this->combustivel = "\0";
    this->categoria = "\0";
}

Moto::Moto(
    const string placa,
    const float capacidade,
    const int ano,
    const string chassi,
    const string modelo,
    const string localizacao,
    const int disponibilidade,
    const string combustivel, 
    const string motor, 
    const string categoria

) : Veiculo(placa, "Moto", capacidade, ano, chassi, modelo, localizacao, disponibilidade)
{
    this->combustivel = combustivel;
    this->motor = motor;
    this->categoria = categoria;
}

Moto::~Moto()
{
    ;
}

string Moto::getCombustivel()
{
    return this->combustivel;
}
int Moto::setCombustivel(const string combustivel)
{
    if(combustivel.length() > 30){
        cerr << "Combustível deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->combustivel = combustivel;

    return 1;
}

string Moto::getMotor()
{
    return this->motor;
}
int Moto::setMotor(const string motor)
{
    if(motor.length() > 30){
        cerr << "Motor deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->motor = motor;

    return 1;
}

string Moto::getCategoria()
{
    return this->categoria;
}
int Moto::setCategoria(const string categoria)
{
    if(categoria.length() > 30){
        cerr << "Categoria deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->categoria = categoria;

    return 1;
}

ostream& operator<<(ostream& ostr, Moto& moto)
{
    ostr << "Ano: " << moto.getAno() << endl;
    ostr << "Tipo: " << moto.getTipo() << endl;
    ostr << "Capacidade: " << moto.getCapacidade() << endl;
    ostr << "Chassi: " << moto.getChassi() << endl;
    ostr << "Localização: " << moto.getLocalizacao() << endl;
    ostr << "Modelo: " << moto.getModelo() << endl;
    ostr << "Combustivel: " << moto.getCombustivel() << endl;
    ostr << "Motor: " << moto.getMotor() << endl;
    ostr << "Categoria: " << moto.getCategoria() << endl;
    ostr << "Disponibilidade: " << moto.getDisponibilidade() << endl;
    ostr << endl;

    return ostr;
}

bool operator==(const Moto& este, const Moto& outro)
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
        este.combustivel == outro.combustivel &&
        este.categoria == outro.categoria
    ){
        return true;
    }

    return false;
}