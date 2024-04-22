#ifndef _CAMINHAO_H
#define _CAMINHAO_H

#include "../Veiculos/Veiculos.h"

using namespace std;

/**
 * Herda de veículos e adiciona atributos específicos
*/
class Caminhao : public Veiculo
{
    private:
        float peso;     /** Peso do caminhão (sem contar com a carga) em kg */
        string tracao;  /** Relação entre o total de rodas e quais delas possui tração exemplo: 6x4, 8x4, etc */

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

        // Getters e Setters

        float getPeso();
        int setPeso(float peso);

        string getTracao();
        int setTracao(string tracao);

        // Sobrecarga de Operadores
        friend ostream& operator<<(ostream& ostr, Caminhao& caminhao);
        friend bool operator==(const Caminhao& este, const Caminhao& outro);
};

#endif