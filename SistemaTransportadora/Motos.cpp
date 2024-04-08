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
Moto::~Moto()
{
    ;
}

string Moto::getCombustivel()
{
    return this->combustivel;
}
int Moto::setCombustivel(string combustivel)
{
    if(combustivel.length() > 30){
        cout << "Combustível deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->combustivel = combustivel;

    return 1;
}

string Moto::getMotor()
{
    return this->motor;
}
int Moto::setMotor(string motor)
{
    if(motor.length() > 30){
        cout << "Motor deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->motor = motor;

    return 1;
}

string Moto::getCategoria()
{
    return this->categoria;
}
int Moto::setCategoria(string categoria)
{
    if(categoria.length() > 30){
        cout << "Categoria deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->categoria = categoria;

    return 1;
}