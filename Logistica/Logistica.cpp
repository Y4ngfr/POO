#include <iostream>
#include "Logistica.h"
#include "../Veiculos/Veiculos.h"
#include "../Pedidos/Pedidos.h"
#include "../ListaVeiculos/ListaVeiculos.h"

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

    if(pedido == nullptr){
        cout << "Pedido inválido" << endl;
        return -1;
    }

    it = this->filaPedidos->begin();

    while(it != this->filaPedidos->end())
    {
        if(pedido->getOrdem() < (*it)->getOrdem())
        {
            this->filaPedidos->insert(it, pedido);
            
            return 0;
        }

        it++;
    }

    this->filaPedidos->push_front(pedido);

    return 0;
}

int Logistica::removerPedido(int indice)
{
    list<Pedido*>::iterator it;
    int i;

    if(indice == 0)
    {
        this->filaPedidos->pop_front();

        return 0;
    }

    if(indice == -1)
    {  
        this->filaPedidos->pop_back();

        return 0;
    }

    if(indice > 0)
    {
        it = this->filaPedidos->begin();
        i = 0;

        while(i < indice)
        {
            if(it == this->filaPedidos->end())
            {
                cout << "Índice fora dos limites da lista" << endl;
                return -1;
            }

            it++;
            i++;
        }

        this->filaPedidos->erase(it);

        return 0;
    }

    cout << "Índice inválido" << endl;

    return -1;
}

int Logistica::atribuirVeiculos(ListaVeiculos* veiculos)
{
    list<Pedido*>::iterator iteradorPedidos;
    int iteradorVeiculos, tamanhoLista;

    if(veiculos == nullptr)
    {
        cout << "Lista de veículos inválida" << endl;
        
        return -1;
    }

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
