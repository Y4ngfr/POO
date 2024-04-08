#include <iostream>
#include <string>
#include <list>
#include "ListaVeiculos.h"

using namespace std;

ListaVeiculos::ListaVeiculos()
{
    this->lista = new list<Veiculo>;
}

ListaVeiculos::~ListaVeiculos()
{
    delete lista;
}

void ListaVeiculos::adicionarVeiculo(Veiculo* veiculo, int indice)
{
    if(indice == INICIO)
    {
        this->lista->push_back(*(veiculo));
    }
    else if(indice == FINAL)
    {
        this->lista->push_front(*(veiculo));
    }
    else
    {
        list<Veiculo>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++);
        
        this->lista->insert(position, *(veiculo));
    }
}

void ListaVeiculos::adicionarVeiculo(int indice)
{
    if(indice == INICIO)
    {
        this->lista->emplace_front();
    }
    else if(indice == FINAL)
    {
        this->lista->emplace_back();
    }
    else
    {
        list<Veiculo>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++);

        this->lista->emplace(position);
    }
}

int ListaVeiculos::removerVeiculo(int indice)
{
    if(this->lista->size() == 0){
        return 0;
    }

    if(indice == INICIO)
    {
        this->lista->pop_front();
    }
    else if(indice == FINAL)
    {
        this->lista->pop_back();
    }
    else
    {
        list<Veiculo>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++);

        this->lista->erase(position);
    }

    return 1;
}

Veiculo* ListaVeiculos::buscarVeiculo(const string placa)
{
    list<Veiculo>::iterator it;
    Veiculo* ptr;

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if(it->getPlaca() == placa){
            break;
        }
    }
    
    ptr = &(*it);

    return ptr;
}

Veiculo* ListaVeiculos::buscarVeiculo(int indice)
{
    list<Veiculo>::iterator it;
    Veiculo* ptr;
    int aux;

    if(indice == INICIO){
        ptr = &(*this->lista->begin());
        return ptr;
    }
    else if(indice == FINAL){
        ptr = &(this->lista->back());
        return ptr;
    }

    it = this->lista->begin();

    for(aux = 0; aux < indice; aux++, it++);

    ptr = &(*it);

    return ptr;
    
}

ListaVeiculos* ListaVeiculos::filtrarPorLocalização(const string localização)
{
    ListaVeiculos *listaFiltrada;
    list<Veiculo>::iterator it;
    Veiculo *aux;

    listaFiltrada = new ListaVeiculos;

    if(listaFiltrada == nullptr){
        cout << "Não foi possível alocar lista de retorno" << endl;
        return nullptr;
    }

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if(it->getLocalização() == localização)
        {
            aux = &(*it);
            listaFiltrada->adicionarVeiculo(aux, INICIO);
        }
    }

    return listaFiltrada;
}

ListaVeiculos* ListaVeiculos::obterVeiculosDisponiveis()
{
    ListaVeiculos* veiculosDisponiveis;
    list<Veiculo>::iterator it;
    Veiculo* aux;

    veiculosDisponiveis = new ListaVeiculos;

    if(veiculosDisponiveis == nullptr){
        cout << "Não foi possível alocar a lista de veículos disponíveis" << endl;
        return nullptr;
    }

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if(it->getDisponibilidade() == 1)
        {
            aux = &(*it);
            veiculosDisponiveis->adicionarVeiculo(aux, INICIO);
        }
    }

    return veiculosDisponiveis;
}

void ListaVeiculos::imprimirLista()
{
    list<Veiculo>::iterator it;
    int indice;

    indice = 0;

    if(lista->size() == 0){
        cout << "Lista Vazia" << endl;
        return;
    }

    for(it = this->lista->begin(); it != this->lista->end(); it++, indice++)
    {
        cout << "Veiculo [" << indice << "]" << endl;
        cout << "       Placa: " << it->getPlaca() << endl;
        cout << "       Disponibilidade: " << it->getDisponibilidade() << endl;
        cout << "       Localização: " << it->getLocalização() << endl;
        cout << "       Modelo: " << it->getModelo() << endl;
    }
}