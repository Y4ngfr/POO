#ifndef _VEICULOS_H
#define _VEICULOS_H

class Veiculo
{
    private:
        char tipo[21];
        int capacidade;
        char ano[5];
        char chassi[21];
        char modelo[21];
        char localização[41];

    public:
        Veiculo();

        char* getTipo();
        void setTipo(const char* tipo);

        int getCapacidade();
        void setCapacidade(int capacidade);

        char* getAno();
        void setAno(const char* ano);

        char* getChassi();
        void setChassi(const char* chassi);

        char* getModelo();
        void setModelo(const char* modelo);

        char* getLocalização();
        void setLocalização(const char* localização);
};    

#endif