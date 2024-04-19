#ifndef _LOGISTICA_H
#define _LOGISTICA_H

using namespace std;

class Logistica
{
    private:
        // Fila define a ordem dos pedidos
        list<Pedido*>* filaPedidos;

    public:
        Logistica();
        ~Logistica();

        int adicionarPedido(Pedido* pedido);
        int removerPedido(const int indice);
        int atribuirVeiculos(ListaVeiculos* veiculos);
};

#endif