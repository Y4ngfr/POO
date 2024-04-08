#include <iostream>
#include "Carros.h"

using namespace std;

Carro::Carro()
{
    this->tipo = "Carro";
    this->motor = "\0";
    this->combustivel = "\0";
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