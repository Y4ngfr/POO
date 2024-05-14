#include "Pedidos.h"
#include "../GeoShell/GeoShell.hpp"

using namespace std;

Pedido::Pedido()
{
    this->id = "\0";
    this->idCliente = "\0";
    this->idVeiculo = "\0";
    this->localColeta = "\0";
    this->localEntrega = "\0";
    this->pesoCarga = 0;
    this->volumeCarga = 0;
    this->ordem = 0;
}

Pedido::Pedido(
    string id,
    string idCliente,
    string idVeiculo,
    string localColeta,
    string localEntrega,
    float pesoCarga,
    float volumeCarga,
    int ordem
){
    this->id = id;
    this->idCliente = idCliente;
    this->idVeiculo = idVeiculo;
    this->localColeta = localColeta;
    this->setCoordenadasColeta(localColeta);
    this->localEntrega = localEntrega;
    this->pesoCarga = pesoCarga;
    this->volumeCarga = volumeCarga;
    this->ordem = ordem;
}

Pedido::~Pedido()
{
    cout << "limpando memória.." << endl;
}

string Pedido::getId()
{
    return this->id;
}
int Pedido::setId(const string id)
{
    if(id.length() != 10){
        cout << "Id deve ter 10 caracteres" << endl;
        return 0;
    }

    this->id = id;

    return 1;
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

string Pedido::getIdVeiculo()
{
    return this->idVeiculo;
}
int Pedido::setIdVeiculo(const string idVeiculo)
{
    if(idVeiculo.length() != 7){
        cout << "Id veículo deve ter 7 caracteres" << endl;
        return 0;
    }

    this->idVeiculo = idVeiculo;
    
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

array<double, 2> Pedido::getCoordenadasColeta(){
    return this->coordenadasColeta;
}
int Pedido::setCoordenadasColeta(const array<double, 2> coordenadasColeta){
    this->coordenadasColeta = coordenadasColeta;

    return 1;
}
int Pedido::setCoordenadasColeta(const string localColeta){
    array<double, 2> COORDENADAS_NULAS = {0, 0};
    try{
        this->coordenadasColeta = GeoShell::get_coordinates(localColeta);
        if (this->coordenadasColeta == COORDENADAS_NULAS){
            throw exception();
        }
    }
    catch(invalid_argument e){
        cerr << "[" << this->getId() << "] Endereço não encontrado." << endl;
        this->coordenadasColeta = {0, 0};
    }
    catch(exception e){
        cerr << "[" << this->getId() << "] Erro ao encontrar coordenadas." << endl;
        this->coordenadasColeta = {0, 0};
    }

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

int Pedido::getOrdem()
{
    return this->ordem;
}
int Pedido::setOrdem(const int ordem)
{
    if(ordem < 0){
        cout << "Valor negativo não permitido" << endl;
        return 0;
    }

    this->ordem = ordem;

    return 1;
}

ostream& operator<<(ostream& ostr, Pedido& pedido)
{
    ostr << "Id :" << pedido.getId() << endl;
    ostr << "Id do cliente: " << pedido.getIdCliente() << endl;
    ostr << "Id do veículo: " << pedido.getIdVeiculo() << endl;
    ostr << "Local de coleta: " << pedido.getLocalColeta() << endl;
    ostr << "Local de entrega: " << pedido.getLocalEntrega() << endl;
    ostr << "Peso da carga: " << pedido.getPesoCarga() << endl;
    ostr << "Volume da carga: " << pedido.getVolumeCarga() << endl;
    ostr << "Ordem: " << pedido.getOrdem() << endl;

    return ostr;
}

bool operator==(const Pedido& este, const Pedido& outro)
{
    if(
        este.id == outro.id &&
        este.idCliente == outro.idCliente &&
        este.idVeiculo == outro.idVeiculo &&
        este.localColeta == outro.localColeta &&
        este.localEntrega == outro.localEntrega &&
        este.pesoCarga == outro.pesoCarga &&
        este.volumeCarga == outro.volumeCarga &&
        este.ordem == outro.ordem
    ){
        return true;
    }

    return false;
}