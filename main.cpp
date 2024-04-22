#include <iostream>
#include <string>
#include "Veiculos/Veiculos.h"
#include "Clientes/Clientes.h"
#include "Pedidos/Pedidos.h"
#include "Caminhao/Caminhao.h"
#include "Carros/Carros.h"
#include "Motos/Motos.h"
#include "ListaVeiculos/ListaVeiculos.h"
#include "Logistica/Logistica.h"

using namespace std;

int main()
{
    // Veiculos
    Veiculo *veiculo;
    Caminhao *caminhao;
    Moto *moto;
    Moto *moto2;
    Carro *carro;

    // Clientes
    Cliente *cliente;
    Pedido *pedido;

    // Listas
    ListaVeiculos *veiculos;
    ListaVeiculos *veiculosDisponiveis;

    Logistica *logistica1;

    // Inicializando Veículos
    veiculo = new Veiculo("BRAOS17", "Carro", 100, 1992, "KSJ381NM4", "Fiat", "24.08, 32.56", 1);
    caminhao = new Caminhao("376FF12", 139.54, 2001, "SJNC3823", "VUC", "12.99, 14.15", 1, 2155.90, "6x4");
    carro = new Carro("SBL4771", 43.2, 2013, "KIROP43L", "Fiat", "12.03, 13.4", 0, "Gasolina", "80 CV");
    moto = new Moto("IVX4H97", 10, 2013, "PCION389C", "Honda", "24.67, 45.78", 1, "Flex", "300 cilindradas", "City");
    moto2 = new Moto("IVX4H97", 10, 2013, "PCION389C", "Honda", "11.11, 11.12", 1, "Flex", "300 cilindradas", "City");

    // Inicializando Clientes e Pedidos
    cliente = new Cliente("9312045493", "Marcos", "0123456789", "123.456.789-10", 34);
    pedido = new Pedido("1234567890", "9313204549", "1234567", "13.14, 23.55", "45.32, 67.89", 21, 345, 0);

    // Inicializando lista de veículos
    veiculos = new ListaVeiculos();

    // Inicializando logistica
    logistica1 = new Logistica();

    logistica1->adicionarPedido(pedido);

    cout << "Pedidos:" << endl;
    cout << *logistica1 << endl;

    cout << "Cliente: " << endl;
    cout << *cliente << endl;
    cout << "Pedido:" << endl;
    cout << *pedido << endl;

    veiculos->adicionarVeiculo(carro, INICIO);
    veiculos->adicionarVeiculo(caminhao, INICIO);
    veiculos->adicionarVeiculo(veiculo, INICIO);
    veiculos->adicionarVeiculo(moto, INICIO);
    veiculos->adicionarVeiculo(moto2, FINAL);

    veiculosDisponiveis = veiculos->obterVeiculosDisponiveis();
    
    cout << "Veículos:" << endl;
    cout << *veiculos << endl;
    cout << "Veículos disponíveis:" << endl;
    cout << *veiculosDisponiveis << endl;

    if(*(veiculos->buscarVeiculo(INICIO)) == *(veiculos->buscarVeiculo(FINAL))){
        cout << "são iguais" << endl;
    }

    delete logistica1;
    delete veiculosDisponiveis;
    delete veiculos;
    delete veiculo;
    delete carro;
    delete moto2;
    delete moto;
    delete caminhao;

    return 0;
}