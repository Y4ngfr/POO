#ifndef _VEICULOS_H
#define _VEICULOS_H

using namespace std;

class Veiculo
{
    protected:
        string placa;
        string tipo;
        float capacidade;
        int ano;
        string chassi;
        string modelo;
        string localização;
        int disponibilidade;

    public:
        Veiculo();
        ~Veiculo();

        string getPlaca();
        int setPlaca(const string placa);

        string getTipo();
        int setTipo(const string tipo);

        float getCapacidade();
        int setCapacidade(float capacidade);

        int getAno();
        int setAno(int ano);

        string getChassi();
        int setChassi(const string chassi);

        string getModelo();
        int setModelo(const string modelo);

        string getLocalização();
        int setLocalização(const string localização);

        int getDisponibilidade();
        int setDisponibilidade(const int disponibilidade);
};    

#endif