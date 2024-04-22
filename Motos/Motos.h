#ifndef _MOTOS_H
#define _MOTOS_H

#include "../Veiculos/Veiculos.h"

using namespace std;

/**
 * Herda de Veiculo e adiciona atributos específicos
*/
class Moto : public Veiculo
{
    private:
        string motor;       /** Qualquer informação útil sobre o motor */
        string combustivel; /** Tipo do combústivel usado no motor */
        string categoria;   /** Estilo de design (city, custom ou sport) */

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