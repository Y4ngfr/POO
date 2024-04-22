#ifndef _PEDIDOS_H
#define _PEDIDOS_H

using namespace std;

/**
 * Define as principais informações dos pedidos dos clientes
*/
class Pedido
{
    private:
        string id;
        string idCliente;       /** Vincula o cliente ao pedido */
        string idVeiculo;       /** Vincula o veículo ao pedido */
        int ordem;              /** Define a prioridade do pedido */
        float volumeCarga;      /** Volume dado em metros cúbicos */
        float pesoCarga;        /** Peso dado em kg */
        string localColeta;
        string localEntrega;

    public:
        // Construtores
        Pedido();
        Pedido(
            string id,
            string idCliente,
            string idVeiculo,
            string localColeta,
            string localEntrega,
            float pesoCarga,
            float volumeCarga,
            int ordem
        );

        // Destrutor
        ~Pedido();

        // Métodos Getters e Setters

        string getId();
        int setId(const string id);

        string getIdCliente();
        int setIdCliente(const string idCliente);

        string getIdVeiculo();
        int setIdVeiculo(const string idVeiculo);

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

        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& ostr, Pedido& pedido);
        friend bool operator==(const Pedido& este, const Pedido& outro);
};

#endif