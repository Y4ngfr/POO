#ifndef _CLIENTES_H
#define _CLIENTES_H

class Cliente
{
    private:
        char id[10];
        char nome[30];
        char rg[11];
        char cpf[15];
        int idade;

    public:
        Cliente();

        char* getId();
        void setId(const char* id);

        char* getNome();
        void setNome(const char* nome);

        char* getRg();
        void setRg(const char* rg);

        char* getCpf();
        void setCpf(const char* cpf);

        int getIdade();
        void setIdade(int idade);
};

#endif