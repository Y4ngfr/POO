#ifndef _VEICULOS_H
#define _VEICULOS_H

using namespace std;

class Veiculo
{
    private:
        string tipo;
        float capacidade;
        int ano;
        string chassi;
        string modelo;
        string localização;

    public:
        Veiculo();
        ~Veiculo();

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
};    

#endif