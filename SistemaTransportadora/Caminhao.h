#ifndef _CAMINHAO_H
#define _CAMINHAO_H

#include "Veiculos.h"

using namespace std;

class Caminhao : public Veiculo
{
    private:
        float peso;
        string tracao;

    public:
        // construtores
        Caminhao();
        Caminhao(
            const string placa,
            const float capacidade,
            const int ano,
            const string chassi,
            const string modelo,
            const string localizacao,
            const int disponibilidade,
            const float peso, 
            const string tracao
        );

        // destrutor
        ~Caminhao();

        float getPeso();
        int setPeso(float peso);

        string getTracao();
        int setTracao(string tracao);

        friend ostream& operator<<(ostream& ostr, Caminhao& caminhao);
        friend bool operator==(const Caminhao& este, const Caminhao& outro);
};

#endif