#ifndef _LISTA_VEICULOS_H
#define _LISTA_VEICULOS_H

#include <list>
#include <string>
#include "../Veiculos/Veiculos.h"

#define INICIO 0
#define FINAL -1

using namespace std;

/**
 * Classe responsável por gerenciar os veículos
*/
class ListaVeiculos
{
    private:
        /** Lista encapsulada. Utilize os métodos para administrá-la */
        list<Veiculo*> *lista;

    public:
        // Construtor
        ListaVeiculos();

        // Destrutor
        ~ListaVeiculos();

        /** Adiciona um veículo na posição indicada
         * \param veiculo Veículo já existente (alocado)
         * \param indice Índice na lista de veículos (utilize as macros para
         * adicionar veículos no inicio ou no final da lista)
         * \returns retorna 0 caso sucesso e -1 caso falha
        */
        int adicionarVeiculo(Veiculo *veiculo, const int indice);

        /** Aloca um veículo vazio e adiciona na posição indicada 
         * \param indice Índice na lista de veículos (utilize as macros para 
         * adicionar veículos no inicio ou no final da lista)
         * \return Retorna 0 caso sucesso e -1 caso falha
        */
        int adicionarVeiculo(const int indice);

        /**
         * Remove um veículo na posição indicada
         * \param indice Índice ao na lista de veículo (utilize as macros para
         * adicionar veículos no inicio ou no final da lista)
         * \returns Retorna 0 caso sucesso e -1 caso falha
        */
        int removerVeiculo(const int indice);

        /**
         * Remove um veículo na posição indicada
         * \param placa Placa do veículo ao qual se quer buscar
         * \returns Retorna 0 caso sucesso e -1 caso falha
        */
        int removerVeiculo(const string placa);

        /**
         * Busca o veículo cuja placa é a indicada no argumento
         * \param placa Placa do veículo ao qual se quer buscar
         * \returns Retornará uma referencia para o veículo ou NULL
         * caso não encontre o veículo
        */
        Veiculo* buscarVeiculo(const string placa);

        /**
         * Busca o veículo de acordo com o índice indicado
         * \param Índice do veículo na lista
         * \returns Retornará uma referencia para o veículo ou NULL
         * caso não encontre o veículo
        */
        Veiculo* buscarVeiculo(const int indice);

        /**
         * Busca todos os veículos cuja localização é a indicada no parâmetro
         * \param localizacao Localizão do veículo
         * \returns Retorna uma nova lista contendo todos os veículos cuja
         * localização seja a requerida. É necessário deletar essa nova
         * lista pois é alocada dinâmicamente. Além disso pode retornar NULL
         * caso não encontre nenhum veículo
        */
        ListaVeiculos* filtrarPorLocalizacao(const string localizacao);

        /**
         * Busca todos os veículos que estiverem disponíveis para uso
         * \returns Retorna uma nova lista contendo todos os veículos
         * que estão disponíveis. É necessário deletar essa nova lista pois
         * é alocada dinamicamente. Álem disso pode retornar NULL caso não
         * encontre nenhum veículo
        */
        ListaVeiculos* obterVeiculosDisponiveis();

        /**
         * \returns Retorna o tamanho atual da lista
        */
        int obterTamanhoLista();

        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& ostr, ListaVeiculos& veiculos);
        friend bool operator==(const ListaVeiculos& este, const ListaVeiculos& outro);
};

#endif