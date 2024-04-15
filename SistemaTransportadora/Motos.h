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
        // construtor
        Moto();
        Moto(
            const string placa,
            const float capacidade,
            const int ano,
            const string chassi,
            const string modelo,
            const string localizacao,
            const int disponibilidade,
            const string combustivel, 
            const string motor, 
            const string categoria
            );

        // destrutor
        ~Moto();

        string getCombustivel();
        int setCombustivel(const string combustivel);

        string getMotor();
        int setMotor(const string motor);

        string getCategoria();
        int setCategoria(const string categoria);

        friend ostream& operator<<(ostream& ostr, Moto& moto);
        friend bool operator==(const Moto& este, const Moto& outro);
};

#endif