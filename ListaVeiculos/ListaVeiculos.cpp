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

int ListaVeiculos::adicionarVeiculo(Veiculo* veiculo, const int indice)
{
    if(veiculo == nullptr)
    {
        cerr << "Veículo inválido" << endl;

        return -1;
    }

    if(indice == INICIO)
    {
        this->lista->push_front(veiculo);

        return 0;
    }

    if(indice == FINAL)
    {
        this->lista->push_back(veiculo);

        return 0;
    }
    
    if(indice > 0)
    {
        list<Veiculo*>::iterator position;
        int aux;

        position = this->lista->begin();

        for(aux = 0; aux < indice; aux++, position++){
            if(position == this->lista->end()){
                cerr << "Índice fora dos limites da lista" << endl;
                return -1;
            }
        }
        
        this->lista->insert(position, veiculo);

        return 0;
    }

    cerr << "Índice inválido" << endl;

    return -1;
}

int ListaVeiculos::adicionarVeiculo(const int indice)
{
    Veiculo* novoVeiculo = new Veiculo();

    if(novoVeiculo == nullptr)
    {
        cerr << "Erro ao criar novo veículo" << endl;

        return -1;
    }

    if(indice < 0){
        cerr << "Índice inválido (menor que 0)" << endl;

        return -1;
    }

    if(indice == INICIO)
    {
        this->lista->push_front(novoVeiculo);

        return 0;
    }

    if(indice == FINAL)
    {
        this->lista->push_back(novoVeiculo);

        return 0;
    }

    
    list<Veiculo*>::iterator position;
    int aux;

    position = this->lista->begin();

    for(aux = 0; aux < indice; aux++, position++)
    {
        if(position == this->lista->end()){
            cerr << "Índice fora dos limites da lista" << endl;

            return -1;
        }
    }

    this->lista->insert(position, novoVeiculo);

    return 0;
    
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

int ListaVeiculos::removerVeiculo(const string placa)
{
    list<Veiculo*>::iterator it;
    Veiculo* ptr;

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if((*it)->getPlaca() == placa){
            this->lista->erase(it);
            return 1;
        }
    }

    return 0;
}

Veiculo* ListaVeiculos::buscarVeiculo(const string placa)
{
    list<Veiculo*>::iterator it;
    Veiculo* ptr;

    for(it = this->lista->begin(); it != this->lista->end(); it++)
    {
        if((*it)->getPlaca() == placa){
            return *it;
        }
    }

    return nullptr;
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
        cerr << "Não foi possível alocar lista de retorno" << endl;
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
        cerr << "Não foi possível alocar a lista de veículos disponíveis" << endl;
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

int ListaVeiculos::obterTamanhoLista()
{
    return this->lista->size();
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
        ostr << endl;
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