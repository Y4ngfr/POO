#include <iostream>
#include <string>

#include "AlimentadorBancoDados/AlimentadorBancoDados.h"
#include "Caminhao/Caminhao.h"
#include "Carros/Carros.h"
#include "Clientes/Clientes.h"
#include "ListaVeiculos/ListaVeiculos.h"
#include "Logistica/Logistica.h"
#include "Motos/Motos.h"
#include "Pedidos/Pedidos.h"
#include "Sistema/Sistema.h"
#include "Veiculos/Veiculos.h"

using namespace std;

void mostrarSecao(string texto, string enfeite = "=====") {
  string borda;
  char caractereBorda = '=';

  int tamanhoBorda = texto.size() + 2 * enfeite.size() + 2;
  for (int i = 0; i < tamanhoBorda; i++)
    borda += caractereBorda;

  cout << borda << endl;
  cout << enfeite << " " << texto << " " << enfeite << endl;
  cout << borda << endl;
  cout << endl;
}

int main() {
  Sistema *sistema = new Sistema();
  string input;

  while (input != "sair") {
    cout << "Digite seu comando: ";
    input.clear();
    getline(cin, input);
    if (input == "sair")
      exit(0);
    else if (input == "criar cliente")
      sistema->adicionarCliente();
    else if (input == "excluir cliente")
      sistema->excluirCliente();
    else if (input == "buscar cliente")
      sistema->buscarClientePorAtributo();

    else if (input == "criar veiculo")
      sistema->adicionarVeiculo();
    else if (input == "excluir veiculo")
      sistema->desativarVeiculo();
    else if (input == "buscar veiculo")
      sistema->buscarVeiculoPorAtributo();

    else if (input == "criar pedido")
      sistema->adicionarPedido();
    else if (input == "excluir pedido")
      sistema->finalizarPedido();
    else if (input == "buscar pedido")
      sistema->listarPedidosPorAtributo();
    else if (input == "listar pedidos")
      cout << (*sistema->logistica);
    else
      cout << "Comando inválido." << endl << endl;
  }

  cout << sistema->logistica;

  return 0;
}

// int main()
// {
//     // Veiculos
//     Veiculo *veiculo;
//     Caminhao *caminhao;
//     Moto *moto;
//     Moto *moto2;
//     Carro *carro;

//     // Clientes
//     Cliente *cliente;
//     Pedido *pedido;

//     // Listas
//     ListaVeiculos *veiculos;
//     ListaVeiculos *veiculosDisponiveis;

//     Logistica *logistica1;

//     // Inicializando Veículos
//     veiculo = new Veiculo("BRAOS17", "Carro", 999999, 1992, "KSJ381NM4",
//     "Fiat", "24.08, 32.56", 1); caminhao = new Caminhao("376FF12", 999999,
//     2001, "SJNC3823", "VUC", "12.99, 14.15", 1, 2155.90, "6x4"); carro = new
//     Carro("SBL4771", 999999, 2013, "KIROP43L", "Fiat", "12.03, 13.4", 0,
//     "Gasolina", "80 CV"); moto = new Moto("IVX4H97", 999999, 2013,
//     "PCION389C", "Honda", "24.67, 45.78", 1, "Flex", "300 cilindradas",
//     "City"); moto2 = new Moto("IVX4H97", 999999, 2013, "PCION389C", "Honda",
//     "11.11, 11.12", 1, "Flex", "300 cilindradas", "City");

//     // Inicializando Clientes e Pedidos
//     cliente = new Cliente("9312045493", "Marcos", "0123456789",
//     "123.456.789-10", 34); pedido = new Pedido("1234567890", "9313204549",
//     "NULL ID", "13.14, 23.55", "45.32, 67.89", 21, 345, 0);

//     // Inicializando lista de veículos
//     veiculos = new ListaVeiculos();

//     // Inicializando logistica
//     logistica1 = new Logistica();

//     mostrarSecao("ALIMENTANDO BANCO DE DADOS");
//     AlimentadorBancoDados::alimentarComCSV("dados_entregas.csv", logistica1,
//     veiculos, 20);

//     logistica1->adicionarPedido(pedido);

//     veiculos->adicionarVeiculo(carro, INICIO);
//     veiculos->adicionarVeiculo(caminhao, INICIO);
//     veiculos->adicionarVeiculo(veiculo, INICIO);
//     veiculos->adicionarVeiculo(moto, INICIO);
//     veiculos->adicionarVeiculo(moto2, FINAL);

//     mostrarSecao("ATRIBUINDO PEDIDOS");
//     logistica1->atribuirVeiculos(veiculos);

//     mostrarSecao("EXIBINDO PEDIDOS");
//     cout << "Pedidos:" << endl;
//     cout << *logistica1 << endl;

//     // logistica1->atribuirVeiculos(veiculos);

//     // cout << "Cliente: " << endl;
//     // cout << *cliente << endl;
//     // cout << "Pedido:" << endl;
//     // cout << *pedido << endl;

//     // veiculosDisponiveis = veiculos->obterVeiculosDisponiveis();

//     // cout << "Veículos:" << endl;
//     // cout << *veiculos << endl;
//     // cout << "Veículos disponíveis:" << endl;
//     // cout << *veiculosDisponiveis << endl;

//     // if(*(veiculos->buscarVeiculo(INICIO)) ==
//     *(veiculos->buscarVeiculo(FINAL))){
//     //     cout << "são iguais" << endl;
//     // }

//     delete logistica1;
//     // delete veiculosDisponiveis;
//     delete veiculos;
//     delete veiculo;
//     delete carro;
//     delete moto2;
//     delete moto;
//     delete caminhao;

//     return 0;
// }