#ifndef _MOTOS_H
#define _MOTOS_H

#include "Veiculos.h"

using namespace std;

class Moto : public Veiculo
{
    private:
        string combustivel;
        string motor;
        string categoria;

    public:
        Moto();
        ~Moto();

        string getCombustivel();
        int setCombustivel(string combustivel);

        string getMotor();
        int setMotor(string motor);

        string getCategoria();
        int setCategoria(string categoria);
};

#endif