#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <sstream>
#include "AlimentadorBancoDados.h"
#include "../Clientes/Clientes.h"

#include <omp.h>
#define NUMERO_DE_THREADS 8

using namespace std;

vector<string> AlimentadorBancoDados::lerLinha(string linha, bool& string_aberta){
    vector<string> linha_cortada;
    string celula;

    for (char caractere : linha) {
        if (caractere == '"') {
            string_aberta = !string_aberta;
        } else if (caractere == ',' && !string_aberta) {
            linha_cortada.push_back(celula);
            celula.clear();
        } else {
            celula += caractere;
        }
    }

    if (!celula.empty() && !string_aberta) {
        linha_cortada.push_back(celula);
    }

    return linha_cortada;
}

void AlimentadorBancoDados::alimentarComCSV(string path, Logistica* logistica, ListaVeiculos* veiculos, uint64_t maximo_de_linhas)
{ 
    // Criando arquivo
    fstream arquivo; 

    // Abrindo arquivo
    arquivo.open(path, ios::in); 

    // Verificando se houve erro na abertura do arquivo
    if (!arquivo.is_open())
        throw runtime_error("Arquivo não pôde ser aberto");

    // Declarando variáveis necessárias
    vector<string> dados;
    string linha; 
    bool string_aberta = false;

    // Pegando cabeçalhos da tabela
    getline(arquivo, linha);
    vector<string> cabecalhos = AlimentadorBancoDados::lerLinha(linha, string_aberta);

    // Pegando células de todas as linhas
    vector<string> celulas_da_linha;
    while (getline(arquivo, linha)) {

        // Lendo linha e armazenando em um vetor
        celulas_da_linha = AlimentadorBancoDados::lerLinha(linha, string_aberta);

        // Inserindo células na lista de dados
        for (string celula : celulas_da_linha){
            dados.push_back(celula);
        }
    }

    // Fechando arquivo
    arquivo.close();
 
    double numero_de_cabecalhos = cabecalhos.size();
    double numero_de_linhas = dados.size() / numero_de_cabecalhos;

    maximo_de_linhas = numero_de_linhas < maximo_de_linhas ? numero_de_linhas : maximo_de_linhas;

    Cliente* cliente;
    Pedido* pedido;
    
    int numeroPedidosAdicionados = 0;

    omp_set_num_threads(NUMERO_DE_THREADS);
    #pragma omp parallel for
    for (int linha=0; linha<maximo_de_linhas; linha++){
        int j = linha*numero_de_cabecalhos;
        
        // Verificando se há erro no valor de peso ou volume
        #pragma omp critical
        try{
            stod(dados[j+7]);
            stod(dados[j+8]);
        }
        catch(invalid_argument e){
            cerr << "Os valores de peso ou volume são inválidos.";
            throw e;
        }

        // Criando um novo cliente e um novo pedido
        cliente = new Cliente(to_string(linha), dados[j+0], "", dados[j+1], 0);
        pedido = new Pedido(to_string(10000+linha), cliente->getId(), "NULL ID", dados[j+5], dados[j+6], stod(dados[j+7]), stod(dados[j+8]), dados[j+9] == "sim" ? true : false);

        // Adicionando pedido na lista de pedidos
        logistica->adicionarPedido(pedido);
        numeroPedidosAdicionados++;
        cout << "CARREGANDO... (" << numeroPedidosAdicionados*100/maximo_de_linhas << "%)" << endl;

        // delete cliente;
        // delete pedido;

        // for (int i=0; i<numero_de_cabecalhos; i++){
        //     cout << cabecalhos[i] << ": " << dados[linha*numero_de_cabecalhos + i] << endl;
        // }
    }
}