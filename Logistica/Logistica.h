#ifndef _LOGISTICA_H
#define _LOGISTICA_H

using namespace std;

#include <list>
#include "../Pedidos/Pedidos.h"
#include "../ListaVeiculos/ListaVeiculos.h"

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
         * \returns Retorna 0 caso sucesso e -1 caso falha
        */
        int removerPedido(const int indice);

        /** Vincula os pedidos aos veículos
         * \param veiculos Veículos que serão atribuidos aos pedidos (não é necessário
         * passar apenas veículos disponíveis como argumento)
         * \returns Retorna 0 caso sucesso e -1 caso falha
         */
        int atribuirVeiculos(ListaVeiculos* veiculos);

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& ostr, Logistica& logistica);
};

#endif