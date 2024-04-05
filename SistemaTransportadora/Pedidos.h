#ifndef _PEDIDOS_H
#define _PEDIDOS_H

using namespace std;

class Pedido
{
    private:
        string idCliente;
        string tipoTransporte;
        string localColeta;
        string localEntrega;
        float pesoCarga;
        float volumeCarga;

    public:
        Pedido();
        ~Pedido();

        string getIdCliente();
        int setIdCliente(const string idCliente);

        string getTipoTransporte();
        int setTipoTransporte(const string tipoTransporte);

        string getLocalColeta();
        int setLocalColeta(const string localColeta);

        string getLocalEntrega();
        int setLocalEntrega(const string localEntrega);

        float getPesoCarga();
        int setPesoCarga(float pesoCarga);

        float getVolumeCarga();
        int setVolumeCarga(float volumeCarga);
};

#endif