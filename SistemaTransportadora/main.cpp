#include <iostream>
#include <string>
#include "Veiculos.h"
#include "Clientes.h"
#include "Pedidos.h"
#include "Caminhão.h"
#include "Carros.h"
#include "Motos.h"
#include "ListaVeiculos.h"

using namespace std;

int main()
{
    Veiculo veiculo;
    Cliente cliente;
    Pedido pedido;
    Caminhão caminhão;
    Moto moto;
    Carro carro;
    ListaVeiculos veiculos;
    ListaVeiculos *veiculosDisponiveis;
    ListaVeiculos *veiculosLocalização;

    veiculo.setPlaca("BRAOS17");
    veiculo.setAno(1992);
    veiculo.setTipo("Carro");
    veiculo.setCapacidade(100);
    veiculo.setChassi("KSJ381NM4");
    veiculo.setLocalização("Brasil");
    veiculo.setModelo("MAN");
    veiculo.setDisponibilidade(1);

    cliente.setCpf("123.456.789-10");
    cliente.setId("9312045493");
    cliente.setIdade(34);
    cliente.setNome("Marcos");
    cliente.setRg("0123456789");

    pedido.setIdCliente("9313204549");
    pedido.setLocalColeta("Rua 12");
    pedido.setLocalEntrega("Rua 13");
    pedido.setPesoCarga(21);
    pedido.setTipoTransporte("Terreno");
    pedido.setVolumeCarga(345);

    caminhão.setPlaca("376FF12");
    caminhão.setAno(2004);
    caminhão.setCapacidade(139.54);
    caminhão.setChassi("SJNC3823");
    caminhão.setLocalização("França");
    caminhão.setModelo("VUC");
    caminhão.setPeso(2155.90);
    caminhão.setTração("6x4");
    caminhão.setDisponibilidade(1);

    carro.setPlaca("SBL4771");
    carro.setAno(2013);
    carro.setCapacidade(43.2);
    carro.setChassi("KIROP43L");
    carro.setCombustivel("Gasolina");
    carro.setLocalização("Uruguai");
    carro.setModelo("Fiat");
    carro.setMotor("Motor 80 CV");
    carro.setDisponibilidade(0);

    moto.setPlaca("IVX4H97");
    moto.setAno(2013);
    moto.setCapacidade(10);
    moto.setCategoria("Custom");
    moto.setChassi("PCION389C");
    moto.setCombustivel("Flex");
    moto.setLocalização("China");
    moto.setModelo("Honda");
    moto.setMotor("Motor 300 cilindradas");
    moto.setDisponibilidade(1);

    veiculos.adicionarVeiculo(&carro, INICIO);
    veiculos.adicionarVeiculo(&moto, INICIO);
    veiculos.adicionarVeiculo(&caminhão, INICIO);
    veiculos.adicionarVeiculo(&veiculo, INICIO);
    veiculos.adicionarVeiculo(FINAL);

    veiculosDisponiveis = veiculos.obterVeiculosDisponiveis();
    veiculosLocalização = veiculos.filtrarPorLocalização("Brasil");

    cout << veiculos.buscarVeiculo(FINAL)->getPlaca() << endl << endl;

    veiculos.imprimirLista();
    cout << endl;

    veiculosDisponiveis->imprimirLista();
    cout << endl;
    veiculosLocalização->imprimirLista();
    cout << endl;

    cout << "Veículo:" << endl;
    cout << "Ano: " << veiculo.getAno() << endl;
    cout << "Tipo: " << veiculo.getTipo() << endl;
    cout << "Capacidade: " << veiculo.getCapacidade() << endl;
    cout << "Chassi: " << veiculo.getChassi() << endl;
    cout << "Localização: " << veiculo.getLocalização() << endl;
    cout << "Modelo: " << veiculo.getModelo() << endl;
    cout << "Disponibilidade: " << veiculo.getDisponibilidade() << endl << endl;

    cout << "Cliente:" << endl;
    cout << "Cpf: " << cliente.getCpf() << endl;
    cout << "Id: " << cliente.getId() << endl;
    cout << "Idade: " << cliente.getIdade() << endl;
    cout << "Nome: " << cliente.getNome() << endl;
    cout << "Rg: " << cliente.getRg() << endl << endl;

    cout << "Pedido:" << endl;
    cout << "Id do cliente: " << pedido.getIdCliente() << endl;
    cout << "Local de coleta: " << pedido.getLocalColeta() << endl;
    cout << "Local de entrega: " << pedido.getLocalEntrega() << endl;
    cout << "Peso da carga: " << pedido.getPesoCarga() << endl;
    cout << "Tipo do transporte: " << pedido.getTipoTransporte() << endl;
    cout << "Volume da carga: " << pedido.getVolumeCarga() << endl << endl;

    cout << "Caminhão:" << endl;
    cout << "Ano: " << caminhão.getAno() << endl;
    cout << "Tipo: " << caminhão.getTipo() << endl;
    cout << "Capacidade: " << caminhão.getCapacidade() << endl;
    cout << "Chassi: " << caminhão.getChassi() << endl;
    cout << "Localização: " << caminhão.getLocalização() << endl;
    cout << "Modelo: " << caminhão.getModelo() << endl;
    cout << "Peso: " << caminhão.getPeso() << endl;
    cout << "Tração: " << caminhão.getTração() << endl;
    cout << "Disponibilidade: " << caminhão.getDisponibilidade() << endl << endl;

    cout << "Carro:" << endl;
    cout << "Ano: " << carro.getAno() << endl;
    cout << "Tipo: " << carro.getTipo() << endl;
    cout << "Capacidade: " << carro.getCapacidade() << endl;
    cout << "Chassi: " << carro.getChassi() << endl;
    cout << "Localização: " << carro.getLocalização() << endl;
    cout << "Modelo: " << carro.getModelo() << endl;
    cout << "Combustível: " << carro.getCombustivel() << endl;
    cout << "Motor: " << carro.getMotor() << endl;
    cout << "Disponibilidade: " << carro.getDisponibilidade() << endl << endl;

    cout << "Moto:" << endl;
    cout << "Ano: " << moto.getAno() << endl;
    cout << "Tipo: " << moto.getTipo() << endl;
    cout << "Capacidade: " << moto.getCapacidade() << endl;
    cout << "Chassi: " << moto.getChassi() << endl;
    cout << "Localização: " << moto.getLocalização() << endl;
    cout << "Modelo: " << moto.getModelo() << endl;
    cout << "Combustivel: " << moto.getCombustivel() << endl;
    cout << "Motor: " << moto.getMotor() << endl;
    cout << "Categoria: " << moto.getCategoria() << endl;
    cout << "Disponibilidade: " << moto.getDisponibilidade() << endl << endl;

    delete veiculosDisponiveis;
    delete veiculosLocalização;

    return 0;
}