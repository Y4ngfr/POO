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
    list<Pedido*>::iterator iteradorPedidos;
    int iteradorVeiculos, tamanhoLista;

    tamanhoLista = veiculos->obterTamanhoLista();
    iteradorPedidos = this->filaPedidos->begin();

    while(iteradorPedidos != this->filaPedidos->end())
    {
        Veiculo* aux;

        if((*iteradorPedidos)->getVolumeCarga() < 2)
        {   // Se volume menor que 2m³ então uma moto é escolhida
            for( iteradorVeiculos = 0;
                 iteradorVeiculos < tamanhoLista;
                 iteradorVeiculos++
            ){
                aux = veiculos->buscarVeiculo(iteradorVeiculos);

                if( aux->getDisponibilidade() == 1 &&
                    aux->getTipo() == "Moto" &&
                    aux->getCapacidade() >= (*iteradorPedidos)->getPesoCarga()
                ){
                    (*iteradorPedidos)->setIdVeiculo(aux->getPlaca());
                    aux->setDisponibilidade(0);
                }
            }    
        }
        else if((*iteradorPedidos)->getVolumeCarga() > 10)
        {   // Se o volume maior que 10m³ então um caminhão é escolhido
            for( iteradorVeiculos = 0;
                 iteradorVeiculos < tamanhoLista;
                 iteradorVeiculos++
            ){
                aux = veiculos->buscarVeiculo(iteradorVeiculos);

                if( aux->getDisponibilidade() == 1 &&
                    aux->getTipo() == "Caminhão" &&
                    aux->getCapacidade() >= (*iteradorPedidos)->getPesoCarga()
                ){
                    (*iteradorPedidos)->setIdVeiculo(aux->getPlaca());
                    aux->setDisponibilidade(0);
                }
            }    
        }
        else 
        {  // Se volume > 2 e < 10 então um carro é escolhido 
            for( iteradorVeiculos = 0;
                 iteradorVeiculos < tamanhoLista;
                 iteradorVeiculos++
            ){
                aux = veiculos->buscarVeiculo(iteradorVeiculos);

                if( aux->getDisponibilidade() == 1 &&
                    aux->getTipo() == "Carro" &&
                    aux->getCapacidade() >= (*iteradorPedidos)->getPesoCarga()
                ){
                    (*iteradorPedidos)->setIdVeiculo(aux->getPlaca());
                    aux->setDisponibilidade(0);
                }
            }    
        }



        for(iteradorVeiculos = 0; iteradorVeiculos < tamanhoLista; iteradorVeiculos++)
        {
            aux = veiculos->buscarVeiculo(iteradorVeiculos);

            if(aux->getDisponibilidade() == 1)
            {
                if(aux->getCapacidade() >= (*iteradorPedidos)->getPesoCarga())
                {
                    (*iteradorPedidos)->setIdVeiculo(aux->getPlaca());
                }
            }
        }

        iteradorPedidos++;
    }

    return 0;
}

ostream& operator<<(ostream& ostr, Logistica& logistica)
{
    list<Pedido*>::iterator it;
    int indice;

    indice = 0;

    if(logistica.filaPedidos->size() == 0){
        ostr << "Fila Vazia" << endl;
        return ostr;
    }

    for(it = logistica.filaPedidos->begin(); it != logistica.filaPedidos->end(); it++, indice++)
    {
        ostr << "Pedido [" << indice << "]" << endl;
        ostr << "       Id: " << (*it)->getId() << endl;
        ostr << "       Id Cliente: " << (*it)->getIdCliente() << endl;
        ostr << "       Id Veiculo: " << (*it)->getIdVeiculo() << endl;
        ostr << "       Local Coleta: " << (*it)->getLocalColeta() << endl;
        ostr << "       Ordem: " << (*it)->getOrdem() << endl;
    }

    return ostr;
}