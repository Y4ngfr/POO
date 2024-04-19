#ifndef _PEDIDOS_H
#define _PEDIDOS_H

using namespace std;

class Pedido
{
    private:
        string id;
        string idCliente;
        string idVeiculo;
        string tipoTransporte;
        string localColeta;
        string localEntrega;
        float pesoCarga;
        float volumeCarga;
        int ordem;

    public:
        // Construtor
        Pedido();
        Pedido(
            string id,
            string idCliente,
            string idVeiculo,
            string tipoTransporte,
            string localColeta,
            string localEntrega,
            float pesoCarga,
            float volumeCarga,
            int ordem
        );

        // Destrutor
        ~Pedido();

        string getId();
        int setId(const string id);

        string getIdCliente();
        int setIdCliente(const string idCliente);

        string getIdVeiculo();
        int setIdVeiculo(const string idVeiculo);

        string getTipoTransporte();
        int setTipoTransporte(const string tipoTransporte);

        string getLocalColeta();
        int setLocalColeta(const string localColeta);

        string getLocalEntrega();
        int setLocalEntrega(const string localEntrega);

        float getPesoCarga();
        int setPesoCarga(const float pesoCarga);

        float getVolumeCarga();
        int setVolumeCarga(const float volumeCarga);

        int getOrdem();
        int setOrdem(const int ordem);

        friend ostream& operator<<(ostream& ostr, Pedido& pedido);
        friend bool operator==(const Pedido& este, const Pedido& outro);
};

#endif