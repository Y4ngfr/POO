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
        list<Veiculo*> *lista;

    public:
        ListaVeiculos();
        ~ListaVeiculos();
        void adicionarVeiculo(Veiculo *veiculo, const int indice);
        void adicionarVeiculo(const int indice);
        int removerVeiculo(const int indice);
        Veiculo* buscarVeiculo(const string placa);
        Veiculo* buscarVeiculo(const int indice);
        ListaVeiculos* filtrarPorLocalizacao(const string localizacao);
        ListaVeiculos* obterVeiculosDisponiveis();

        friend ostream& operator<<(ostream& ostr, ListaVeiculos& veiculos);
        friend bool operator==(const ListaVeiculos& este, const ListaVeiculos& outro);
};

#endif