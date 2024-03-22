#include <iostream>
#include <string.h>
#include "Pedidos.h"

using namespace std;

Pedido::Pedido()
{
    memset(this->idCliente, '\0', 10);
    memset(this->tipoTransporte, '\0', 40);
    memset(this->localColeta, '\0', 40);
    memset(this->localEntrega, '\0', 40);
    this->pesoCarga = 0;
    this->volumeCarga = 0;
}

char* Pedido::getIdCliente()
{
    return this->idCliente;
}
void Pedido::setIdCliente(const char* idCliente)
{
    if(strlen(idCliente) > 10){
        cout << "Erro: o máximo de caracteres é 9" << endl;
        return;
    }

    strcpy(this->idCliente, idCliente);
}

char* Pedido::getTipoTransporte()
{
    return this->tipoTransporte;
}
void Pedido::setTipoTransporte(const char* tipoTransporte)
{
    if(strlen(tipoTransporte) > 40){
        cout << "Erro: o máximo de caracteres é 39" << endl;
        return;
    }

    strcpy(this->tipoTransporte, tipoTransporte);
}

char* Pedido::getLocalColeta()
{
    return this->localColeta;
}
void Pedido::setLocalColeta(const char* localColeta)
{
    if(strlen(localColeta) > 40){
        cout << "Erro: o máximo de caracteres é 39" << endl;
        return;
    }

    strcpy(this->localColeta, localColeta);
}

char* Pedido::getLocalEntrega()
{
    return this->localEntrega;
}
void Pedido::setLocalEntrega(const char* localEntrega)
{
    if(strlen(localEntrega) > 40){
        cout << "Erro: o máximo de caracteres é 39" << endl;
        return;
    }

    strcpy(this->localEntrega, localEntrega);
}

int Pedido::getPesoCarga()
{
    return this->pesoCarga;
}
void Pedido::setPesoCarga(int pesoCarga)
{
    this->pesoCarga = pesoCarga;
}

int Pedido::getVolumeCarga()
{
    return this->pesoCarga;
}
void Pedido::setVolumeCarga(int volumeCarga)
{
    this->volumeCarga = volumeCarga;
}