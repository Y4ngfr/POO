#include <iostream>
#include <math.h>
#include "Logistica.h"
#include "../Veiculos/Veiculos.h"
#include "../Pedidos/Pedidos.h"
#include "../ListaVeiculos/ListaVeiculos.h"
#include "../GeoShell/GeoShell.hpp"

using namespace std;

Logistica::Logistica()
{
    this->filaPedidos = new list<Pedido*>;

    if(filaPedidos == nullptr){
        cerr << "Erro ao alocar Logisitca" << endl;
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
        cerr << "Pedido inválido" << endl;
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
                cerr << "Índice fora dos limites da lista" << endl;
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

double Logistica::calcular_distancia(array<double, 2> coordenadas1, array<double, 2> coordenadas2)
{
    double distanciaX = pow(coordenadas1[0] - coordenadas2[0], 2);
    double distanciaY = pow(coordenadas1[1] - coordenadas2[1], 2);

    // Calculando distância através do teorema de Pitagoras
    double distancia = sqrt(distanciaX + distanciaY);

    return distancia;
}

Veiculo *Logistica::encontrarVeiculoIdeal(Pedido *pedido, ListaVeiculos* lista_de_veiculos, string tipo_de_veiculo)
{
    double distancia_mais_proxima = INT32_MAX;
    Veiculo *veiculo_mais_proximo = NULL;

    for (int i = 0; i < lista_de_veiculos->obterTamanhoLista(); i++)
    {
        Veiculo* veiculo = lista_de_veiculos->buscarVeiculo(i);
        array<double, 2> c1 = GeoShell::get_coordinates(veiculo->getLocalizacao());
        array<double, 2> c2;
        try{
            c2 = GeoShell::get_coordinates(pedido->getLocalColeta());
        }
        catch (exception e){
            return NULL;
        }
        double distancia = this->calcular_distancia(c1, c2);

        // Verificando de o veículo está mais longe que o mais perto
        if (distancia > distancia_mais_proxima)
            continue;

        // Verificando se o veículo é de um tipo diferente
        if (veiculo->getTipo() != tipo_de_veiculo)
            continue;

        // Verificando se o veículo tem capacidade
        if ((veiculo->getCapacidade() < pedido->getPesoCarga())/* || (veiculo->get_max_load_weight() < pedido->get_load_weight())*/)
            continue;

        distancia_mais_proxima = distancia;
        veiculo_mais_proximo = veiculo;
    }

    return veiculo_mais_proximo;
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
            this->encontrarVeiculoIdeal((*iteradorPedidos), veiculos, "Moto") ;
        }
        else if((*iteradorPedidos)->getVolumeCarga() > 10)
        {   // Se o volume maior que 10m³ então um caminhão é escolhido
            this->encontrarVeiculoIdeal((*iteradorPedidos), veiculos, "Caminhao");
        }
        else 
        {  // Se volume > 2 e < 10 então um carro é escolhido 
            this->encontrarVeiculoIdeal((*iteradorPedidos), veiculos, "Carro");  
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
        ostr << endl;
    }

    return ostr;
}
