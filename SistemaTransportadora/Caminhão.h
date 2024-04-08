#ifndef _CAMINHAO_H
#define _CAMINHAO_H

#include "Veiculos.h"

using namespace std;

class Caminhão : public Veiculo
{
    private:
        float peso;
        string tração;

    public:
        Caminhão();
        ~Caminhão();

        float getPeso();
        int setPeso(float peso);

        string getTração();
        int setTração(string tração);
};

#endif