#include "Sistema.h"

#include <iostream>
#include <string>

#include "../AlimentadorBancoDados/AlimentadorBancoDados.h"
#include "../Caminhao/Caminhao.h"
#include "../Carros/Carros.h"
#include "../Clientes/Clientes.h"
#include "../Motos/Motos.h"
#include "../Pedidos/Pedidos.h"
#include "../Veiculos/Veiculos.h"

using namespace std;

int Sistema::idPedido = 0;
int Sistema::idCliente = 0;

int lerDados(vector<string>& atributos, vector<string>& valores, string texto) {
    string input;

    cout << texto << ", entre com os dados:" << endl;
    for (int i = 0; i < atributos.size(); i++) {
        input.clear();
        cout << atributos[i] << ": ";
        getline(cin, input);
        valores.push_back(input);
    }

    return 1;
}

Sistema::Sistema(ListaVeiculos* veiculos, Logistica* logistica,
                 vector<Cliente*>* clientes) {
    this->veiculos = veiculos == nullptr ? new ListaVeiculos() : veiculos;
    this->logistica = logistica == nullptr ? new Logistica() : logistica;
    this->clientes = clientes == nullptr ? new vector<Cliente*> : clientes;
}

// Veiculo
int Sistema::adicionarVeiculo() {
    vector<string> atributos = {"Placa",       "Tipo",           "Capacidade",
                                "Ano",         "Chassi",         "Modelo",
                                "Localização", "Disponibilidade"};
    vector<string> valores;

    string input;

    lerDados(atributos, valores, "Adicionando veículo");

    try {
        stof(valores[2]);
        stoi(valores[3]);
        stoi(valores[7]);
    } catch (...) {
        cerr << "Valores inválidos. Excluindo dados." << endl;
        return 0;
    }

    return adicionarVeiculo(valores[0], valores[1], stof(valores[2]),
                            stoi(valores[3]), valores[4], valores[5],
                            valores[6], stoi(valores[7]));
}
int Sistema::adicionarVeiculo(Veiculo* veiculo) {
    try {
        this->veiculos->adicionarVeiculo(veiculo, FINAL);
    } catch (exception e) {
        cerr << "Não foi possível adicionar veículo à lista, por conta do "
                "seguinte erro: "
             << e.what() << endl;
        return 0;
    }

    clog << "Veículo adicionado à lista com sucesso!" << endl;
    return 1;
}
int Sistema::adicionarVeiculo(const string placa, const string tipo,
                              const float capacidade, const int ano,
                              const string chassi, const string modelo,
                              const string localizacao,
                              const bool disponibilidade) {
    Veiculo* veiculo;

    try {
        veiculo = new Veiculo(placa, tipo, capacidade, ano, chassi, modelo,
                              localizacao, disponibilidade);
    } catch (exception e) {
        cerr << "Não foi possível criar veículo, por conta do seguinte erro: "
             << e.what() << endl;
        return 0;
    }
    clog << "Veículo criado com sucesso!" << endl;

    if (adicionarVeiculo(veiculo)) return 1;

    delete veiculo;
    return 0;
}

int Sistema::buscarVeiculoPorAtributo() {
    vector<string> atributos = {"Atributo", "Valor"};
    vector<string> valores;
    string idVeiculo;

    string input;

    lerDados(atributos, valores, "Buscando veiculo");

    idVeiculo = buscarVeiculoPorAtributo(valores[0], valores[1]);

    if (idVeiculo == "") {
        cout << "Nenhum veículo encontrado." << endl;
        return 0;
    }

    cout << "Veiculo encontrado: " << idVeiculo << endl;
    return 1;
}
string Sistema::buscarVeiculoPorAtributo(string atributo, string valor) {
    int i = 0;
    Veiculo* veiculo;

    if (atributo == "chassi") {
        for (int i = 0; i < this->veiculos->obterTamanhoLista(); i++) {
            veiculo = this->veiculos->buscarVeiculo(i);

            if ((veiculo->getChassi() == valor) && (atributo == "chassi"))
                return veiculo->getPlaca();
        }
    } else {
        cerr << "Atributo de busca não aceito." << endl;
    }

    return "";
}

int Sistema::desativarVeiculo() {
    string placa, tmp;
    bool forcarDesligamento;

    cout << "Insira a placa do veículo: ";
    cin >> placa;

    cout << "Forçar desligamento (sim ou nao)? ";
    cin >> tmp;

    forcarDesligamento = tmp == "sim" ? 1 : 0;

    return desativarVeiculo(placa, forcarDesligamento);
}
int Sistema::desativarVeiculo(Veiculo* veiculo, bool forcarDesligamento) {
    if (veiculo == nullptr) {
        cerr << "Veiculo inválido." << endl;
        return 0;
    }
    return desativarVeiculo(veiculo->getPlaca(), forcarDesligamento);
}
int Sistema::desativarVeiculo(string placa, bool forcarDesligamento) {
    Veiculo* veiculo = this->veiculos->buscarVeiculo(placa);

    if (veiculo == nullptr) {
        cerr << "Nenhum veículo encontrado com a placa fornecida." << endl;
        return 0;
    }

    if (forcarDesligamento) {
        for (Pedido* pedido : this->logistica->listarPedidosVeiculo(placa)) {
            if (!adicionarPedido(
                    pedido->getIdCliente(), pedido->getIdVeiculo(),
                    veiculo->getLocalizacao(), pedido->getLocalEntrega(),
                    pedido->getPesoCarga(), pedido->getVolumeCarga(), 1)) {
                cerr << "Erro ao transferir pedido." << endl;
                return 0;
            }
            this->logistica->removerPedido(pedido->getId());
        }
    }

    if (this->veiculos->removerVeiculo(placa)) {
        clog << "Veículo removido com sucesso!" << endl;
        return 1;
    }

    cerr << "Não foi possível desativar veículo." << endl;
    return 0;
}

// Cliente
int Sistema::adicionarCliente() {
    vector<string> atributos = {"Nome", "RG", "CPF", "Idade"};
    vector<string> valores;

    string input;

    lerDados(atributos, valores, "Adicionando clientes");

    try {
        stoi(valores[3]);
    } catch (...) {
        cerr << "Valor inválido para idade. Excluindo dados." << endl;
        return 0;
    }

    return adicionarCliente(valores[0], valores[1], valores[2],
                            stoi(valores[3]));
}
int Sistema::adicionarCliente(Cliente* cliente) {
    try {
        this->clientes->push_back(cliente);
    } catch (exception e) {
        cerr << "Não foi possível adicionar cliente à lista, por conta do "
                "seguinte erro: "
             << e.what() << endl;
        return 0;
    }

    clog << "Cliente adicionado à lista com sucesso!" << endl;
    return 1;
}
int Sistema::adicionarCliente(const string nome, const string rg,
                              const string cpf, const int idade) {
    Cliente* cliente;

    try {
        cliente = new Cliente(to_string(idCliente++), nome, rg, cpf, idade);
    } catch (exception e) {
        cerr << "Não foi possível criar cliente, por conta do seguinte erro: "
             << e.what() << endl;
        return 0;
    }
    clog << "Cliente criado com sucesso!" << endl;

    if (adicionarCliente(cliente)) return 1;

    delete cliente;
    return 0;
}

int Sistema::buscarClientePorAtributo() {
    vector<string> atributos = {"Atributo", "Valor"};
    vector<string> valores;
    string idCliente;

    string input;

    lerDados(atributos, valores, "Buscando cliente");

    idCliente = buscarClientePorAtributo(valores[0], valores[1]);

    if (idCliente == "") {
        cout << "Nenhum cliente encontrado." << endl;
        return 0;
    }

    cout << "Cliente encontrado: " << idCliente << endl;
    return 1;
}
string Sistema::buscarClientePorAtributo(string atributo, string valor) {
    Cliente* cliente;

    if (atributo == "rg") {
        for (int i = 0; i < this->clientes->size(); i++) {
            cliente = this->clientes->at(i);

            if (cliente->getRg() == valor) {
                return cliente->getNome();
            }
        }
    } else if (atributo == "cpf") {
        for (int i = 0; i < this->clientes->size(); i++) {
            cliente = this->clientes->at(i);

            if (cliente->getCpf() == valor) {
                return cliente->getId();
            }
        }
    } else {
        cerr << "Atributo de busca não aceito." << endl;
    }

    return "";
}

int Sistema::excluirCliente() {
    string id;

    cout << "Insira o ID do cliente: ";
    cin >> id;

    return excluirCliente(id);
}
int Sistema::excluirCliente(Cliente* cliente) {
    if (cliente == nullptr) {
        cerr << "Cliente inválido." << endl;
        return 0;
    }

    return excluirCliente(cliente->getId());
}
int Sistema::excluirCliente(string id) {
    vector<Cliente*>::iterator it;
    Cliente* cliente;

    for (it = this->clientes->begin(); it != this->clientes->end(); ++it) {
        if (*it == cliente) {
            this->clientes->erase(it);
            clog << "Cliente excluído com sucesso!" << endl;
            return 1;
        }
    }

    cerr << "Nenhum cliente encontrado com o ID fornecido." << endl;
    return 0;
}

// Pedido
int Sistema::adicionarPedido() {
    vector<string> atributos = {"ID Cliente",
                                "Placa Veiculo",
                                "Local de Coleta",
                                "Local  de Entrega",
                                "Peso da Carga",
                                "Volume da Carga",
                                "Ordem"};
    vector<string> valores;

    string input;

    lerDados(atributos, valores, "Adicionando pedido");

    try {
        stof(valores[4]);
        stof(valores[5]);
        stoi(valores[6]);
    } catch (...) {
        cerr << "Valores inválidos. Excluindo dados." << endl;
        return 0;
    }

    return adicionarPedido(valores[0], valores[1], valores[2], valores[3],
                           stof(valores[4]), stof(valores[5]),
                           stoi(valores[6]));
}
int Sistema::adicionarPedido(Pedido* pedido) {
    try {
        this->logistica->adicionarPedido(pedido);
    } catch (exception e) {
        cerr << "Não foi possível adicionar pedido à logistica, por conta do "
                "seguinte erro: "
             << e.what() << endl;
        return 0;
    }

    clog << "Pedido adicionado à logistica com sucesso!" << endl;
    return 1;
}
int Sistema::adicionarPedido(const string idCliente, const string idVeiculo,
                             const string localColeta,
                             const string localEntrega, const float pesoCarga,
                             const float volumeCarga, const int ordem) {
    Pedido* pedido;

    try {
        pedido = new Pedido(to_string(this->idPedido++), idCliente, idVeiculo,
                            localColeta, localEntrega, pesoCarga, volumeCarga,
                            ordem);
    } catch (exception e) {
        cerr << "Não foi possível criar pedido, por conta do seguinte erro: "
             << e.what() << endl;
        return 0;
    }
    clog << "Pedido criado com sucesso!" << endl;

    if (adicionarPedido(pedido)) return 1;

    delete pedido;
    return 0;
}

int Sistema::atribuirCarga() {
    return this->logistica->atribuirVeiculos(this->veiculos);
}

int Sistema::listarPedidosPorAtributo() {
    vector<string> atributos = {"Atributo", "Valor"};
    vector<string> valores;
    vector<string> idPedidos;

    string input;

    lerDados(atributos, valores, "Buscando veiculo");

    idPedidos = listarPedidosPorAtributo(valores[0], valores[1]);

    if (idPedidos.size() == 0) {
        cout << "Nenhum pedido encontrado." << endl;
        return 0;
    }

    for (string idPedido : idPedidos) {
        cout << "Pedido encontrado: " << idPedido << endl;
    }
    return 1;
}
vector<string> Sistema::listarPedidosPorAtributo(string atributo,
                                                 string valor) {
    int i = 0;
    Pedido* pedido;
    vector<string> pedidos;

    if (atributo == "idCliente") {
        return this->logistica->listarPedidos(valor);
    } else if (atributo == "idVeiculo") {
        for (Pedido* pedido : this->logistica->listarPedidosVeiculo(valor)) {
            pedidos.push_back(pedido->getId());
        }
        return pedidos;
    } else {
        cerr << "Atributo de busca não aceito." << endl;
    }

    return pedidos;
}

int Sistema::finalizarPedido() {
    string id, tmp;
    bool cancelar;

    cout << "Insira o ID do pedido: ";
    cin >> id;

    cout << "Cancelar pedido (sim ou nao)? ";
    cin >> tmp;

    cancelar = tmp == "sim" ? 1 : 0;

    return finalizarPedido(id, cancelar);
}
int Sistema::finalizarPedido(Pedido* pedido, bool cancelar) {
    if (pedido == nullptr) {
        cerr << "Pedido inválido." << endl;
        return 0;
    }
    return finalizarPedido(pedido->getId(), cancelar);
}
int Sistema::finalizarPedido(string id, bool cancelar) {
    Pedido* pedido = this->logistica->buscarPedido(id);

    if (pedido == nullptr) {
        cerr << "Nenhum pedido encontrado com o ID fornecido." << endl;
        return 0;
    }

    if (cancelar) {
        if (adicionarPedido(pedido->getIdCliente(), pedido->getIdVeiculo(),
                            pedido->getIdVeiculo(), pedido->getLocalColeta(),
                            pedido->getPesoCarga(), pedido->getVolumeCarga(),
                            1)) {
            cerr << "Não foi possível cancelar o pedido";
            return 0;
        }
    }

    if (this->logistica->removerPedido(id, this->veiculos)) {
        clog << "Pedido finalizado com sucesso!" << endl;
        return 1;
    }

    cerr << "Não foi possível finalizar pedido." << endl;
    return 0;
}

Sistema::~Sistema() {
    delete veiculos;
    delete logistica;
}