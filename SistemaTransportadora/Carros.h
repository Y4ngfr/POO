#ifndef _CARROS_H
#define _CARROS_H

#include "Veiculos.h"

using namespace std;

class Carro : public Veiculo
{
    private:
        string combustivel;
        string motor;

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

        string getCombustivel();
        int setCombustivel(string combustivel);

        string getMotor();
        int setMotor(string motor);

        friend ostream& operator<<(ostream& ostr, Carro& carro);
        friend bool operator==(const Carro& este, const Carro& outro);
};

#endif