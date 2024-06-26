#ifndef _VEICULOS_H
#define _VEICULOS_H

using namespace std;

/**
 *   Classe Mãe Veículo define os principais atributos
 *   para as classes filhas: Carro, Moto e Caminhão
*/
class Veiculo
{
    protected:
        string placa;           /** Substitui o Id convencional */
        string tipo;            /** Classe do veículo: Carro, Moto, Caminhão, etc */
        float capacidade;       /** Peso máximo suportado, medido em kg */
        bool disponibilidade;   /** Define se o veículo poderá ser vinculado a um pedido */
        int ano;            
        string chassi;
        string modelo;
        string localizacao;

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
            const bool disponibilidade
            );

        // Destrutor
        ~Veiculo();

        // Métodos Getters e Setters

        string getPlaca();
        int setPlaca(const string placa);

        string getTipo();
        int setTipo(const string tipo);

        float getCapacidade();
        int setCapacidade(const float capacidade);

        int getAno();
        int setAno(const int ano);

        string getChassi();
        int setChassi(const string chassi);

        string getModelo();
        int setModelo(const string modelo);

        string getLocalizacao();
        int setLocalizacao(const string localizacao);

        bool getDisponibilidade();
        int setDisponibilidade(const bool disponibilidade);

        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& ostr, Veiculo& veiculo);
        friend bool operator==(const Veiculo& este, const Veiculo& outro);
};    

#endif