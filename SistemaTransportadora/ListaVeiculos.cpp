#include <iostream>
#include <string>
#include <list>
#include "ListaVeiculos.h"

using namespace std;

ListaVeiculos::ListaVeiculos()
{
    this->lista = new list<Veiculo*>;
}

ListaVeiculos::~ListaVeiculos()
{
    delete lista;
}

void ListaVeiculos::adicionarVeiculo(Veiculo* veiculo, const int indice)
{
    if(indice == INICIO)
    {
        this->lista->push_front(veiculo);
    }
    else if(indice == FINAL)
    {
        this->lista->push_back(veiculo);
    }
    else
    {
        list<Veiculo*>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++);
        
        this->lista->insert(position, veiculo);
    }
}

void ListaVeiculos::adicionarVeiculo(const int indice)
{
    Veiculo* novoVeiculo = new Veiculo();

    if(indice == INICIO)
    {
        this->lista->push_front(novoVeiculo);
    }
    else if(indice == FINAL)
    {
        this->lista->push_back(novoVeiculo);
    }
    else
    {
        list<Veiculo*>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++);

        this->lista->insert(position, novoVeiculo);
    }
}

int ListaVeiculos::removerVeiculo(const int indice)
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
        list<Veiculo*>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++);

        this->lista->erase(position);
    }

    return 1;
}

Veiculo* ListaVeiculos::buscarVeiculo(const string placa)
{
    list<Veiculo*>::iterator it;
    Veiculo* ptr;

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if((*it)->getPlaca() == placa){
            break;
        }
    }
    
    ptr = *it;

    return ptr;
}

Veiculo* ListaVeiculos::buscarVeiculo(const int indice)
{
    list<Veiculo*>::iterator it;
    Veiculo* ptr;
    int aux;

    if(indice == INICIO){
        ptr = *(this->lista->begin());
        return ptr;
    }
    else if(indice == FINAL){
        ptr = this->lista->back();
        return ptr;
    }

    it = this->lista->begin();

    for(aux = 0; aux < indice; aux++, it++);

    ptr = *it;

    return ptr;
    
}

ListaVeiculos* ListaVeiculos::filtrarPorLocalizacao(const string localizacao)
{
    ListaVeiculos *listaFiltrada;
    list<Veiculo*>::iterator it;
    Veiculo *aux;

    listaFiltrada = new ListaVeiculos;

    if(listaFiltrada == nullptr){
        cout << "Não foi possível alocar lista de retorno" << endl;
        return nullptr;
    }

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if((*it)->getLocalizacao() == localizacao)
        {
            aux = *it;
            listaFiltrada->adicionarVeiculo(aux, INICIO);
        }
    }

    return listaFiltrada;
}

ListaVeiculos* ListaVeiculos::obterVeiculosDisponiveis()
{
    ListaVeiculos* veiculosDisponiveis;
    list<Veiculo*>::iterator it;
    Veiculo* aux;

    veiculosDisponiveis = new ListaVeiculos;

    if(veiculosDisponiveis == nullptr){
        cout << "Não foi possível alocar a lista de veículos disponíveis" << endl;
        return nullptr;
    }

    it = this->lista->begin();

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if((*it)->getDisponibilidade() == 1)
        {
            aux = *it;
            veiculosDisponiveis->adicionarVeiculo(aux, INICIO);
        }
    }

    return veiculosDisponiveis;
}

ostream& operator<<(ostream& ostr, ListaVeiculos& veiculos)
{
    list<Veiculo*>::iterator it;
    int indice;

    indice = 0;

    if(veiculos.lista->size() == 0){
        ostr << "Lista Vazia" << endl;
        return ostr;
    }

    for(it = veiculos.lista->begin(); it != veiculos.lista->end(); it++, indice++)
    {
        ostr << "Veiculo [" << indice << "]" << endl;
        ostr << "       Placa: " << (*it)->getPlaca() << endl;
        ostr << "       Disponibilidade: " << (*it)->getDisponibilidade() << endl;
        ostr << "       Localizacao: " << (*it)->getLocalizacao() << endl;
        ostr << "       Tipo: " << (*it)->getTipo() << endl;
        ostr << "       Modelo: " << (*it)->getModelo() << endl;
    }

    return ostr;
}

bool operator==(const ListaVeiculos& este, const ListaVeiculos& outro)
{
    list<Veiculo*>::iterator iteradorEste;
    list<Veiculo*>::iterator iteradorOutro;
    int tamanhoLista, iteradorNumerico;

    if(este.lista->size() != outro.lista->size()){
        return false;
    }

    tamanhoLista = este.lista->size();

    iteradorEste = este.lista->begin();
    iteradorOutro = outro.lista->begin();
    iteradorNumerico = 0;

    while(iteradorNumerico < tamanhoLista)
    {
        if(!(*iteradorEste == *iteradorOutro)){
            return false;
        }

        iteradorEste++;
        iteradorOutro++;
        iteradorNumerico++;
    }

    return true;
}