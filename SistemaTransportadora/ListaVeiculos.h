#ifndef _LISTA_VEICULOS_H
#define _LISTA_VEICULOS_H

#include <list>
#include <string>
#include "Veiculos.h"

#define INICIO 0
#define FINAL -1

using namespace std;

class ListaVeiculos
{
    private:
        list<Veiculo> *lista;

    public:
        ListaVeiculos();
        ~ListaVeiculos();
        void adicionarVeiculo(Veiculo *veiculo, int indice);
        void adicionarVeiculo(int indice);
        int removerVeiculo(int indice);
        Veiculo* buscarVeiculo(const string placa);
        Veiculo* buscarVeiculo(int indice);
        ListaVeiculos* filtrarPorLocalização(const string localização);
        ListaVeiculos* obterVeiculosDisponiveis();
        void imprimirLista();
};

#endif