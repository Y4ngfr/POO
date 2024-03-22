#ifndef _PEDIDOS_H
#define _PEDIDOS_H

class Pedido
{
    private:
        char idCliente[10];
        char tipoTransporte[40];
        char localColeta[40];
        char localEntrega[40];
        int pesoCarga;
        int volumeCarga;

    public:
        Pedido();

        char* getIdCliente();
        void setIdCliente(const char* idCliente);

        char* getTipoTransporte();
        void setTipoTransporte(const char* tipoTransporte);

        char* getLocalColeta();
        void setLocalColeta(const char* localColeta);

        char* getLocalEntrega();
        void setLocalEntrega(const char* localEntrega);

        int getPesoCarga();
        void setPesoCarga(int pesoCarga);

        int getVolumeCarga();
        void setVolumeCarga(int volumeCarga);
};

#endif