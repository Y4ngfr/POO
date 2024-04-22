#ifndef _CARROS_H
#define _CARROS_H

#include "../Veiculos/Veiculos.h"

using namespace std;

/**
 * Herda de veículos e adiciona atributos específicos
*/
class Carro : public Veiculo
{
    private:
        string motor;       /** Qualquer informação útil sobre o motor */
        string combustivel; /** Tipo de combustível usado no motor */

    public:
        // construtores
        Carro();
        Carro(
            const string placa,
            const float capacidade,
            const int ano,
            const string chassi,
            const string modelo,
            const string localizacao,
            const int disponibilidade,
            const string combustivel, 
            const string motor
            );

        // destrutor
        ~Carro();

        // Métodos Getters e Setters

        string getCombustivel();
        int setCombustivel(string combustivel);

        string getMotor();
        int setMotor(string motor);

        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& ostr, Carro& carro);
        friend bool operator==(const Carro& este, const Carro& outro);
};

#endif