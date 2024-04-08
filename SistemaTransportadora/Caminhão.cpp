#include <iostream>
#include "Caminhão.h"

using namespace std;

Caminhão::Caminhão()
{
    this->tipo = "caminhão";
    this->peso = 0;
    this->tração = "\0";
}
Caminhão::~Caminhão()
{
    ;
}

float Caminhão::getPeso()
{ 
    return this->peso; 
}
int Caminhão::setPeso(float peso)
{ 
    if(peso < 0){
        cout << "Peso negativo não permitido\n" << endl;
        return 0;
    }

    this->peso = peso; 

    return 1;
}

string Caminhão::getTração()
{
     return this->tração; 
}
int Caminhão::setTração(string tração)
{ 
    if(tração != "6x2" && tração != "6x4" && tração != "8x2" && tração != "8x4")
    {
        cout << "valor para tração inválido" << endl;

        return 0;
    }

    this->tração = tração; 

    return 1;
}