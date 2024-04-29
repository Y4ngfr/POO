#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include "Logistica/Logistica.h"
#include "Clientes/Clientes.h"

using namespace std;

class Editor_de_CSV{
public:
static vector<string> lerLinha(string linha, bool& string_aberta){
        vector<string> linha_cortada;
        string cedula;

        for (char caractere : linha) {
            if (caractere == '"') {
                string_aberta = !string_aberta;
            } else if (caractere == ',' && !string_aberta) {
                linha_cortada.push_back(cedula);
                cedula.clear();
            } else {
                cedula += caractere;
            }
        }

        if (!cedula.empty() && !string_aberta) {
            linha_cortada.push_back(cedula);
        }

        return linha_cortada;
}

    static void alimentarComCSV(string path, Logistica* logistica, uint64_t maximo_de_linhas = UINT64_MAX)
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
        vector<string> cabecalhos = Editor_de_CSV::lerLinha(linha, string_aberta);

        // Pegando células de todas as linhas
        vector<string> cedulas_da_linha;
        while (getline(arquivo, linha)) {

            // Lendo linha e armazenando em um vetor
            cedulas_da_linha = Editor_de_CSV::lerLinha(linha, string_aberta);

            // Inserindo células na lista de dados
            for (string cedula : cedulas_da_linha){
                dados.push_back(cedula);
            }
        }

        // Fechando arquivo
        arquivo.close();
 
        double numero_de_cabecalhos = cabecalhos.size();
        double numero_de_linhas = dados.size() / numero_de_cabecalhos;

        maximo_de_linhas = numero_de_linhas < maximo_de_linhas ? numero_de_linhas : maximo_de_linhas;

        Cliente* cliente;
        Pedido* pedido;
        for (int linha=0; linha<maximo_de_linhas; linha++){
            int j = linha*numero_de_cabecalhos;
            cliente = new Cliente(to_string(linha), dados[j+0], "", dados[j+1], 0);
            pedido = new Pedido(to_string(10000+linha), cliente->getId(), "-1", dados[j+5], dados[j+6], stod(dados[j+7]), stod(dados[j+8]), dados[j+9] == "sim" ? true : false);

            logistica->adicionarPedido(pedido);

            // delete cliente;
            // delete pedido;

            // for (int i=0; i<numero_de_cabecalhos; i++){
            //     cout << cabecalhos[i] << ": " << dados[linha*numero_de_cabecalhos + i] << endl;
            // }
        }
    } 
};

// int main(){
//     Logistica* log = new Logistica();
//     Editor_de_CSV::alimentarComCSV("dados_entregas.csv", log);
//     return 0;
// }
