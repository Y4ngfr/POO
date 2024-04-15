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
        string localizacao;
        int disponibilidade;

    public:
        // Construtores
        Veiculo();
        Veiculo(    
            const string placa,
            const string tipo,
            const float capacidade,
            const int ano,
            const string chassi,
            const string modelo,
            const string localizacao,
            const int disponibilidade
            );

        // Destrutor
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

        string getLocalizacao();
        int setLocalizacao(const string localizacao);

        int getDisponibilidade();
        int setDisponibilidade(const int disponibilidade);

        friend ostream& operator<<(ostream& ostr, Veiculo& veiculo);
        friend bool operator==(const Veiculo& este, const Veiculo& outro);
};    

#endif