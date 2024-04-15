#include <iostream>
#include <string>
#include "Pedidos.h"

using namespace std;

Pedido::Pedido()
{
    this->idCliente = "\0";
    this->tipoTransporte = "\0";
    this->localColeta = "\0";
    this->localEntrega = "\0";
    this->pesoCarga = 0;
    this->volumeCarga = 0;
}

Pedido::Pedido(
    string idCliente,
    string tipoTransporte,
    string localColeta,
    string localEntrega,
    float pesoCarga,
    float volumeCarga
)
{
    this->idCliente = idCliente;
    this->tipoTransporte = tipoTransporte;
    this->localColeta = localColeta;
    this->localEntrega = localEntrega;
    this->pesoCarga = pesoCarga;
    this->volumeCarga = volumeCarga;
}

Pedido::~Pedido()
{
    cout << "limpando memória.." << endl;
}

string Pedido::getIdCliente()
{
    return this->idCliente;
}
int Pedido::setIdCliente(const string idCliente)
{
    if(idCliente.length() != 10){
        cout << "Id do cliente deve ter 10 caracteres" << endl;
        return 0;
    }

    this->idCliente = idCliente;

    return 1;
}

string Pedido::getTipoTransporte()
{
    return this->tipoTransporte;
}
int Pedido::setTipoTransporte(const string tipoTransporte)
{
    if(tipoTransporte.length() > 30){
        cout << "Tipo do transporte deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->tipoTransporte = tipoTransporte;

    return 1;
}

string Pedido::getLocalColeta()
{
    return this->localColeta;
}
int Pedido::setLocalColeta(const string localColeta)
{
    if(localColeta.length() > 30){
        cout << "Local de coleta deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->localColeta = localColeta;

    return 1;
}

string Pedido::getLocalEntrega()
{
    return this->localEntrega;
}
int Pedido::setLocalEntrega(const string localEntrega)
{
    if(localEntrega.length() > 30){
        cout << "Local de entrega deve ter no máximo 30 caracteres" << endl;
        return 0;
    }

    this->localEntrega = localEntrega;

    return 1;
}

float Pedido::getPesoCarga()
{
    return this->pesoCarga;
}
int Pedido::setPesoCarga(float pesoCarga)
{
    if(pesoCarga < 0){
        cout << "Peso negativo não permitido" << endl;
        return 0;
    }

    this->pesoCarga = pesoCarga;

    return 1;
}

float Pedido::getVolumeCarga()
{
    return this->pesoCarga;
}
int Pedido::setVolumeCarga(float volumeCarga)
{
    if(volumeCarga < 0){
        cout << "Volume negatico não permitido" << endl;
        return 0;
    }

    this->volumeCarga = volumeCarga;

    return 1;
}

ostream& operator<<(ostream& ostr, Pedido& pedido)
{
    ostr << "Id do cliente: " << pedido.getIdCliente() << endl;
    ostr << "Local de coleta: " << pedido.getLocalColeta() << endl;
    ostr << "Local de entrega: " << pedido.getLocalEntrega() << endl;
    ostr << "Peso da carga: " << pedido.getPesoCarga() << endl;
    ostr << "Tipo do transporte: " << pedido.getTipoTransporte() << endl;
    ostr << "Volume da carga: " << pedido.getVolumeCarga() << endl;

    return ostr;
}

bool operator==(const Pedido& este, const Pedido& outro)
{
    if(
        este.idCliente == outro.idCliente &&
        este.localColeta == outro.localColeta &&
        este.localEntrega == outro.localEntrega &&
        este.pesoCarga == este.pesoCarga &&
        este.tipoTransporte == este.tipoTransporte &&
        este.volumeCarga == este.volumeCarga
    ){
        return true;
    }

    return false;
}