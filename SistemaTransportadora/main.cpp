#include <iostream>
#include "Veiculos.h"
#include "Clientes.h"
#include "Pedidos.h"

using namespace std;

int main()
{
    Veiculo v1;
    Cliente c1;
    Pedido p1;

    v1.setAno("1992");
    v1.setTipo("Carro");
    v1.setCapacidade(100);
    v1.setChassi("KSJ381NM4");
    v1.setLocalização("Brasil");
    v1.setModelo("Fusca");

    c1.setCpf("123.456.789-10");
    c1.setId("931204549");
    c1.setIdade(34);
    c1.setNome("Marcos");
    c1.setRg("0123456789");

    p1.setIdCliente("931204549");
    p1.setLocalColeta("Rua 12");
    p1.setLocalEntrega("Rua 13");
    p1.setPesoCarga(21);
    p1.setTipoTransporte("Terreno");
    p1.setVolumeCarga(345);

    cout << "Veículo:" << endl;
    cout << "Ano: " << v1.getAno() << endl;
    cout << "Tipo: " << v1.getTipo() << endl;
    cout << "Capacidade: " << v1.getCapacidade() << endl;
    cout << "Chassi: " << v1.getChassi() << endl;
    cout << "Localização: " << v1.getLocalização() << endl;
    cout << "Modelo: " << v1.getModelo() << endl << endl;

    cout << "Cliente:" << endl;
    cout << "Cpf: " << c1.getCpf() << endl;
    cout << "Id: " << c1.getId() << endl;
    cout << "Idade: " << c1.getIdade() << endl;
    cout << "Nome: " << c1.getNome() << endl;
    cout << "Rg: " << c1.getRg() << endl << endl;

    cout << "Pedido:" << endl;
    cout << "Id do cliente: " << p1.getIdCliente() << endl;
    cout << "Local de coleta: " << p1.getLocalColeta() << endl;
    cout << "Local de entrega: " << p1.getLocalEntrega() << endl;
    cout << "Peso da carga: " << p1.getPesoCarga() << endl;
    cout << "Tipo do transporte: " << p1.getTipoTransporte() << endl;
    cout << "Volume da carga: " << p1.getVolumeCarga() << endl;

    return 0;
}