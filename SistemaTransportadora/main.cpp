#include <iostream>
#include <string>
#include "Veiculos.h"
#include "Clientes.h"
#include "Pedidos.h"
#include "Caminhao.h"
#include "Carros.h"
#include "Motos.h"
#include "ListaVeiculos.h"

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
    ListaVeiculos *veiculosLocalizacao;

    // Inicializando Veículos
    veiculo = new Veiculo("BRAOS17", "Carro", 100, 1992, "KSJ381NM4", "Fiat", "Brasil", 1);
    caminhao = new Caminhao("376FF12", 139.54, 2001, "SJNC3823", "VUC", "França", 1, 2155.90, "6x4");
    carro = new Carro("SBL4771", 43.2, 2013, "KIROP43L", "Fiat", "Uruguai", 0, "Gasolina", "80 CV");
    moto = new Moto("IVX4H97", 10, 2013, "PCION389C", "Honda", "China", 1, "Flex", "300 cilindradas", "City");
    moto2 = new Moto("IVX4H97", 10, 2013, "PCION389C", "Honda", "China", 1, "Flex", "300 cilindradas", "City");

    // Inicializando Clientes e Pedidos
    cliente = new Cliente("9312045493", "Marcos", "0123456789", "123.456.789-10", 34);
    pedido = new Pedido("9313204549", "Terreno", "Rua 12", "Rua 13", 21, 345);

    // Inicializando lista de veículos
    veiculos = new ListaVeiculos();

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
    veiculosLocalizacao = veiculos->filtrarPorLocalizacao("Brasil");
    
    cout << "Veículos:" << endl;
    cout << *veiculos << endl;
    cout << "Veículos disponíveis:" << endl;
    cout << *veiculosDisponiveis << endl;
    cout << "Veículos filtrados por localização:" << endl;
    cout << *veiculosLocalizacao << endl;

    if(*(veiculos->buscarVeiculo(INICIO)) == *(veiculos->buscarVeiculo(FINAL))){
        cout << "são iguais" << endl;
    }

    delete veiculosDisponiveis;
    delete veiculosLocalizacao;
    delete veiculos;
    delete veiculo;
    delete carro;
    delete moto2;
    delete moto;
    delete caminhao;

    return 0;
}