#ifndef _LOGISTICA_H
#define _LOGISTICA_H

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include "../Pedidos/Pedidos.h"
#include "../ListaVeiculos/ListaVeiculos.h"

using namespace std;

/**
 * Classe responsável por gerenciar os pedidos dos clientes, utilize
 * a fila dos pedidos para deixá-los em ordem e o método atribuirVeiculos()
 * para vincular os pedidos aos veículos disponíveis 
*/
class Logistica
{
    private:
        /** Fila define a ordem dos pedidos */
        list<Pedido*>* filaPedidos;

    public:
        // Construtor
        Logistica();

        // Destrutor
        ~Logistica();

        /** Adiciona um pedido à fila considerando o valor do atributo ordem do pedido
         * \param pedido Pedido já existente (alocado) que será adicionado à fila
         * \returns Retorna 0 caso sucesso e -1 caso falha
         */
        int adicionarPedido(Pedido* pedido);

        /** Remove um pedido da fila (pode utilizar -1 para remover no fim da fila) 
         * \param indice Índice na fila de pedidos (utilize -1 para adicionar no final)
         * \param veiculos Veículos que serão atribuidos aos pedidos (não é necessário
         * passar apenas veículos disponíveis como argumento)
         * \returns Retorna 0 caso sucesso e -1 caso falha
        */
        int removerPedido(const int indice, ListaVeiculos* veiculos = NULL);

        /** Remove um pedido da fila (pode utilizar -1 para remover no fim da fila) 
         * \param id ID do pedido a ser excluido
         * \param veiculos Veículos que serão atribuidos aos pedidos (não é necessário
         * passar apenas veículos disponíveis como argumento)
         * \returns Retorna 0 caso sucesso e -1 caso falha
        */
        int removerPedido(const string id, ListaVeiculos* veiculos = NULL);

        /** Vincula os pedidos aos veículos
         * \param pedido Pedido que será atribuído a um veículo
         * \param veiculos Veículos que serão atribuidos aos pedidos (não é necessário
         * passar apenas veículos disponíveis como argumento)
         * \returns Retorna 0 caso sucesso e -1 caso falha
         */
        int atribuirVeiculo(Pedido* pedido, ListaVeiculos* veiculos = NULL);

        /** Vincula os pedidos aos veículos
         * \param veiculos Veículos que serão atribuidos aos pedidos (não é necessário
         * passar apenas veículos disponíveis como argumento)
         * \returns Retorna 0 caso sucesso e -1 caso falha
         */
        int atribuirVeiculos(ListaVeiculos* veiculos);

        /** Vincula os pedidos aos veículos
         * \param idCliente ID do cliente que desejamos buscar os pedidos
         * \param apenasAbertos Retornar apenas pedidos em aberto (1 para sim e 0 para 
         * não)
         * \returns Retorna um vetor com os pedidos
         */
        vector<string> listarPedidos(string idCliente, int apenasAbertos = false);

        /** Vincula os pedidos aos veículos
         * \param placa Placa do veiculo que desejamos buscar os pedidos
         * \param apenasAbertos Retornar apenas pedidos em aberto (1 para sim e 0 para 
         * não)
         * \returns Retorna um vetor com os pedidos
         */
        vector<Pedido*> listarPedidosVeiculo(string placa, int apenasAbertos = false);

        Pedido* buscarPedido(string id);

        double calcular_distancia(array<double, 2> coordenadas1, array<double, 2> coordenadas2);
        Veiculo *encontrarVeiculoIdeal(Pedido *pedido, ListaVeiculos* lista_de_veiculos, string tipo_de_veiculo);

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& ostr, Logistica& logistica);
};

#endif