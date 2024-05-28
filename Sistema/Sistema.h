#ifndef SISTEMA_H
#define SISTEMA_H

#include "../Clientes/Clientes.h"
#include "../ListaVeiculos/ListaVeiculos.h"
#include "../Logistica/Logistica.h"
#include "../Pedidos/Pedidos.h"
#include "../Veiculos/Veiculos.h"

using namespace std;

/**
 * \brief Classe que representa um sistema de logística
 */
class Sistema {
   public:
    static int idPedido;         ///< ID único para pedidos
    static int idCliente;        ///< ID único para clientes
    ListaVeiculos* veiculos;     ///< Ponteiro para a lista de veículos
    Logistica* logistica;        ///< Ponteiro para o objeto de logística
    vector<Cliente*>* clientes;  ///< Ponteiro para o vetor de clientes

   public:
    /**
     * \brief Construtor da classe Sistema
     * \param veiculos Ponteiro para a lista de veículos
     * \param logistica Ponteiro para o objeto de logística
     * \param clientes Ponteiro para o vetor de clientes
     */
    Sistema(ListaVeiculos* veiculos = nullptr, Logistica* logistica = nullptr,
            vector<Cliente*>* clientes = nullptr);

    // Métodos relacionados a Veículos
    /**
     * \brief Adiciona um veículo à lista de veículos do sistema
     * \returns Retorna o ID do veículo adicionado
     */
    int adicionarVeiculo();

    /**
     * \brief Adiciona um veículo à lista de veículos do sistema
     * \param veiculo Ponteiro para o veículo a ser adicionado
     * \returns Retorna o ID do veículo adicionado
     */
    int adicionarVeiculo(Veiculo* veiculo);

    /**
     * \brief Adiciona um veículo à lista de veículos do sistema
     * \param placa Placa do veículo
     * \param tipo Tipo do veículo
     * \param capacidade Capacidade do veículo
     * \param ano Ano do veículo
     * \param chassi Chassi do veículo
     * \param modelo Modelo do veículo
     * \param localizacao Localização do veículo
     * \param disponibilidade Disponibilidade do veículo
     * \returns Retorna o ID do veículo adicionado
     */
    int adicionarVeiculo(const string placa, const string tipo,
                         const float capacidade, const int ano,
                         const string chassi, const string modelo,
                         const string localizacao, const bool disponibilidade);

    /**
     * \brief Busca um veículo por um atributo específico
     * \returns Retorna o ID do veículo encontrado
     */
    int buscarVeiculoPorAtributo();

    /**
     * \brief Busca um veículo por um atributo específico
     * \param atributo Atributo a ser buscado
     * \param valor Valor do atributo
     * \returns Retorna o ID do veículo encontrado
     */
    string buscarVeiculoPorAtributo(string atributo, string valor);

    /**
     * \brief Desativa um veículo
     * \returns Retorna 1 se desativou com sucesso ou 0 caso contrário
     */
    int desativarVeiculo();

    /**
     * \brief Desativa um veículo
     * \param veiculo Ponteiro para o veículo a ser desativado
     * \param forcarDesligamento Indica se deve forçar o desligamento
     * \returns Retorna 1 se desativou com sucesso ou 0 caso contrário
     */
    int desativarVeiculo(Veiculo* veiculo, bool forcarDesligamento = false);

    /**
     * \brief Desativa um veículo
     * \param id ID do veículo a ser desativado
     * \param forcarDesligamento Indica se deve forçar o desligamento
     * \returns Retorna 1 se desativou com sucesso ou 0 caso contrário
     */
    int desativarVeiculo(string id, bool forcarDesligamento = false);

    // Cliente
    /**
     * \brief Adiciona um cliente ao sistema
     * \returns Retorna o ID do cliente adicionado
     */
    int adicionarCliente();

    /**
     * \brief Adiciona um cliente ao sistema
     * \param cliente Ponteiro para o cliente a ser adicionado
     * \returns Retorna o ID do cliente adicionado
     */
    int adicionarCliente(Cliente* cliente);

    /**
     * \brief Adiciona um cliente ao sistema
     * \param nome Nome do cliente
     * \param rg RG do cliente
     * \param cpf CPF do cliente
     * \param idade Idade do cliente
     * \returns Retorna o ID do cliente adicionado
     */
    int adicionarCliente(string nome, string rg, string cpf, int idade);

    /**
     * \brief Busca um cliente por um atributo específico
     * \returns Retorna o ID do cliente encontrado
     */
    int buscarClientePorAtributo();

    /**
     * \brief Busca um cliente por um atributo específico
     * \param atributo Atributo a ser buscado
     * \param valor Valor do atributo
     * \returns Retorna o ID do cliente encontrado
     */
    string buscarClientePorAtributo(string atributo, string valor);

    /**
     * \brief Exclui um cliente do sistema
     * \returns Retorna 1 se excluiu com sucesso ou 0 caso contrário
     */
    int excluirCliente();

    /**
     * \brief Exclui um cliente do sistema
     * \param cliente Ponteiro para o cliente a ser excluído
     * \returns Retorna 1 se excluiu com sucesso ou 0 caso contrário
     */
    int excluirCliente(Cliente* cliente);

    /**
     * \brief Exclui um cliente do sistema
     * \param id ID do cliente a ser excluído
     * \returns Retorna 1 se excluiu com sucesso ou 0 caso contrário
     */
    int excluirCliente(string id);

    // Pedido
    /**
     * \brief Adiciona um pedido ao sistema
     * \returns Retorna o ID do pedido adicionado
     */
    int adicionarPedido();

    /**
     * \brief Adiciona um pedido ao sistema
     * \param pedido Ponteiro para o pedido a ser adicionado
     * \returns Retorna o ID do pedido adicionado
     */
    int adicionarPedido(Pedido* pedido);

    /**
     * \brief Adiciona um pedido ao sistema
     * \param idCliente ID do cliente associado ao pedido
     * \param idVeiculo ID do veículo associado ao pedido
     * \param localColeta Local de coleta do pedido
     * \param localEntrega Local de entrega do pedido
     * \param pesoCarga Peso da carga do pedido
     * \param volumeCarga Volume da carga do pedido
     * \param ordem Ordem do pedido
     * \returns Retorna o ID do pedido adicionado
     */
    int adicionarPedido(string idCliente, string idVeiculo, string localColeta,
                        string localEntrega, float pesoCarga, float volumeCarga,
                        int ordem);

    /**
     * \brief Atribui carga a um pedido
     * \returns Retorna 1 se atribuiu com sucesso ou 0 caso contrário
     */
    int atribuirCarga();

    /**
     * \brief Lista os pedidos por um atributo específico
     * \returns Retorna um vetor com os IDs dos pedidos encontrados
     */
    int listarPedidosPorAtributo();

    /**
     * \brief Lista os pedidos por um atributo específico
     * \param atributo Atributo a ser buscado
     * \param valor Valor do atributo
     * \returns Retorna um vetor com os IDs dos pedidos encontrados
     */
    vector<string> listarPedidosPorAtributo(string atributo, string valor);

    /**
     * \brief Finaliza um pedido
     * \returns Retorna 1 se finalizou com sucesso ou 0 caso contrário
     */
    int finalizarPedido();

    /**
     * \brief Finaliza um pedido
     * \param pedido Ponteiro para o pedido a ser finalizado
     * \param cancelar Indica se deve cancelar o pedido
     * \returns Retorna 1 se finalizou com sucesso ou 0 caso contrário
     */
    int finalizarPedido(Pedido* pedido, bool cancelar = false);

    /**
     * \brief Finaliza um pedido
     * \param id ID do pedido a ser finalizado
     * \param cancelar Indica se deve cancelar o pedido
     * \returns Retorna 1 se finalizou com sucesso ou 0 caso contrário
     */
    int finalizarPedido(string id, bool cancelar = false);

    /**
     * \brief Destrutor da classe Sistema
     */
    ~Sistema();
};

#endif