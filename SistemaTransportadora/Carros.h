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
        Carro();
        ~Carro();

        string getCombustivel();
        int setCombustivel(string combustivel);

        string getMotor();
        int setMotor(string motor);
};

#endif