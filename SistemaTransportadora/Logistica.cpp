#include <iostream>
#include "Logistica.h"
#include "Veiculos.h"
#include "Pedidos.h"
#include "ListaVeiculos.h"

using namespace std;

Logistica::Logistica()
{
    this->filaPedidos = new list<Pedido*>;

    if(filaPedidos == nullptr){
        cout << "Erro ao alocar Logisitca" << endl;
    }
}

Logistica::~Logistica()
{
    int iterador, tamanho;

    tamanho = this->filaPedidos->size();

    for(iterador = 0; iterador < tamanho; iterador++)
    {
        this->filaPedidos->pop_front();
    }

    delete this->filaPedidos;
}

int Logistica::adicionarPedido(Pedido* pedido)
{
    list<Pedido*>::iterator it;

    it = this->filaPedidos->begin();

    while(it != this->filaPedidos->end())
    {
        if(pedido->getOrdem() < (*it)->getOrdem()){
            this->filaPedidos->insert(it, pedido);
            break;
        }

        it++;
    }

    if(this->filaPedidos->size() == 0){
        this->filaPedidos->push_front(pedido);
    }

    return 0;
}

int Logistica::removerPedido(int indice)
{
    list<Pedido*>::iterator it;
    int i;

    it = this->filaPedidos->begin();
    i = 0;

    while(i < indice){
        it++;
        i++;
    }

    this->filaPedidos->erase(it);

    return 0;
}

int Logistica::atribuirVeiculos(ListaVeiculos* veiculos)
{
    return 0;
}