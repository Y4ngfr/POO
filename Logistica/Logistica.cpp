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

int Logistica::removerPedido(const int indice, ListaVeiculos* veiculos)
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

        Veiculo* veiculoComPedido;
        veiculoComPedido = veiculos->buscarVeiculo((*it)->getIdVeiculo());
        veiculoComPedido->setCapacidade(veiculoComPedido->getCapacidade() + (*it)->getPesoCarga());

        this->filaPedidos->erase(it);

        return 0;
    }

    cerr << "Índice inválido" << endl;

    return -1;
}

int Logistica::removerPedido(const string id, ListaVeiculos* veiculos){
    list<Pedido*>::iterator it;
    Veiculo* ptr;

    for(it = this->filaPedidos->begin(); it != this->filaPedidos->end(); it++)
    {
        if((*it)->getId() == id){
            Veiculo* veiculoComPedido;
            veiculoComPedido = veiculos->buscarVeiculo((*it)->getIdVeiculo());
            veiculoComPedido->setCapacidade(veiculoComPedido->getCapacidade() + (*it)->getPesoCarga());

            this->filaPedidos->erase(it);
            return 1;
        }
    }

    cerr << "ID inválido." << endl;
    return 0;
}

double Logistica::calcular_distancia(array<double, 2> coordenadas1, array<double, 2> coordenadas2)
{
    double distanciaX = pow(coordenadas1[0] - coordenadas2[0], 2);
    double distanciaY = pow(coordenadas1[1] - coordenadas2[1], 2);

    // Calculando distância através do teorema de Pitagoras
    double distancia = sqrt(distanciaX + distanciaY);

    return distancia;
}

Veiculo *Logistica::encontrarVeiculoIdeal(Pedido *pedido, ListaVeiculos* listaVeiculos, string tipoVeiculo)
{
    clog << "[" << pedido->getId() << "] Encontrando o veículo ideal." << endl;
    listaVeiculos = listaVeiculos->obterVeiculosDisponiveis();

    if (listaVeiculos->obterTamanhoLista() == 0){
        cerr << "Nenhum veiculo disponível na lista de veículos." << endl;
        return NULL;
    }

    const array<double, 2> COORDENADA_NULA = {0, 0};

    double distanciaMaisProxima = INT32_MAX;
    Veiculo *veiculoMaisProximo = NULL;
    
    array<double, 2> coordenadasEntrega;
    array<double, 2> coordenadasVeiculo;

    if (pedido->getCoordenadasColeta() == COORDENADA_NULA)
        // Tentando pegar coordenadas do pedido, se não foi possível, retorna NULL
        try{
            coordenadasEntrega = GeoShell::get_coordinates(pedido->getLocalColeta());
            if (coordenadasEntrega == COORDENADA_NULA)
                throw exception();
        }
        catch (exception e){
            cerr << "[" << pedido->getId() << "] Pedido não pôde ser alocado pois não foi possível encontrar suas coordenadas." << endl;
            return NULL;
        }
    
    // Buscando o veículo ideal
    for (int i = 0; i < listaVeiculos->obterTamanhoLista(); i++)
    {
        Veiculo* veiculo = listaVeiculos->buscarVeiculo(i);

        if (veiculo->getCoordenadas() == COORDENADA_NULA){
            veiculo->setCoordenadas(veiculo->getLocalizacao());
        }
        coordenadasVeiculo = veiculo->getCoordenadas();

        double distancia = this->calcular_distancia(coordenadasVeiculo, coordenadasEntrega);

        // Verificando de o veículo está mais longe que o mais perto
        if (distancia > distanciaMaisProxima)
            continue;
        // Verificando se o veículo é de um tipo diferente
        if (veiculo->getTipo() != tipoVeiculo)
            continue;

        // Verificando se o veículo tem capacidade
        if ((veiculo->getCapacidade() < pedido->getPesoCarga())/* || (veiculo->get_max_load_weight() < pedido->get_load_weight())*/)
            continue;

        distanciaMaisProxima = distancia;
        veiculoMaisProximo = veiculo;
    }

    return veiculoMaisProximo;
}

int Logistica::atribuirVeiculo(Pedido* pedido, ListaVeiculos* veiculos){

    Veiculo* veiculoIdeal;

    const array<double, 2> COORDENADA_NULA = {0, 0};

    if (pedido->getCoordenadasColeta() == COORDENADA_NULA)
        // Tentando pegar coordenadas do pedido, se não foi possível, retorna NULL
        try{
            pedido->setCoordenadasColeta(pedido->getLocalColeta());
            if (pedido->getCoordenadasColeta() == COORDENADA_NULA)
                throw exception();
        }
        catch (exception e){
            cerr << "[" << pedido->getId() << "] Pedido não pôde ser alocado pois não foi possível encontrar suas coordenadas." << endl;
            return 0;
        }

    if(pedido->getVolumeCarga() < 2){  
        // Se volume menor que 2m³ então uma moto é escolhida
        veiculoIdeal = this->encontrarVeiculoIdeal(pedido, veiculos, "Moto");
        if (veiculoIdeal == NULL){
            pedido->setIdVeiculo("NULL ID");
            cerr << "[" << pedido->getId() << "] Nenhum veículo encontrado." << endl;
        }
        else{
            pedido->setIdVeiculo(veiculoIdeal->getPlaca());
            veiculoIdeal->setCapacidade(veiculoIdeal->getCapacidade() - pedido->getPesoCarga());
        }
    }
    else if(pedido->getVolumeCarga() > 10)
    {   // Se o volume maior que 10m³ então um caminhão é escolhido
        veiculoIdeal = this->encontrarVeiculoIdeal(pedido, veiculos, "Caminhão");
        if (veiculoIdeal == NULL){
            pedido->setIdVeiculo("NULL ID");
            cerr << "[" << pedido->getId() << "] Nenhum veículo encontrado." << endl;
        }
        else{
            pedido->setIdVeiculo(veiculoIdeal->getPlaca());
            veiculoIdeal->setCapacidade(veiculoIdeal->getCapacidade() - pedido->getPesoCarga());
        }
    }
    else 
    {  // Se volume > 2 e < 10 então um carro é escolhido 
        veiculoIdeal = this->encontrarVeiculoIdeal(pedido, veiculos, "Carro");  
        if (veiculoIdeal == NULL){
            pedido->setIdVeiculo("NULL ID");
            cerr << "[" << pedido->getId() << "] Nenhum veículo encontrado." << endl;
        }
        else{
            pedido->setIdVeiculo(veiculoIdeal->getPlaca());
            veiculoIdeal->setCapacidade(veiculoIdeal->getCapacidade() - pedido->getPesoCarga());
        }
    }

    return 0;
}

int Logistica::atribuirVeiculos(ListaVeiculos* veiculos)
{
    list<Pedido*>::iterator iteradorPedidos;
    int iteradorVeiculos, tamanhoLista;

    if(veiculos == nullptr)
    {
        cerr << "Lista de veículos inválida" << endl;
        
        return -1;
    }

    tamanhoLista = this->filaPedidos->size();
    iteradorPedidos = this->filaPedidos->begin();
    int numeroPedidosAtribuidos = 0;

    while(iteradorPedidos != this->filaPedidos->end())
    {
        this->atribuirVeiculo((*iteradorPedidos), veiculos);
        iteradorPedidos++;

        numeroPedidosAtribuidos++;
        cout << "CARREGANDO... (" << numeroPedidosAtribuidos*100/tamanhoLista << "%)" << endl;
    }
    return 0;
}

vector<string> Logistica::listarPedidos(string idCliente, int apenasAbertos){
    list<Pedido*>::iterator it;
    vector<string> pedidos;

    for(it = this->filaPedidos->begin(); it != this->filaPedidos->end(); it++)
    {
        if((*it)->getIdCliente() == idCliente){
            pedidos.push_back((*it)->getId());
        }
    }

    return pedidos;
}

vector<Pedido*> Logistica::listarPedidosVeiculo(string placa, int apenasAbertos){
    list<Pedido*>::iterator it;
    vector<Pedido*> pedidos;

    for(it = this->filaPedidos->begin(); it != this->filaPedidos->end(); it++)
    {
        if((*it)->getIdVeiculo() == placa){
            pedidos.push_back(*it);
        }
    }

    return pedidos;
}

Pedido* Logistica::buscarPedido(string id){
    list<Pedido*>::iterator it;

    for(it = this->filaPedidos->begin(); it != this->filaPedidos->end(); it++)
    {
        if((*it)->getId() == id){
            return (*it);
        }
    }

    return nullptr;
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
