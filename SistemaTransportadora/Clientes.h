#ifndef _CLIENTES_H
#define _CLIENTES_H

using namespace std;

class Cliente
{
    private:
        string id;
        string nome;
        string rg;
        string cpf;
        int idade;

    public:
        Cliente();
        ~Cliente();

        string getId();
        int setId(const string id);

        string getNome();
        int setNome(const string nome);

        string getRg();
        int setRg(const string rg);

        string getCpf();
        int setCpf(const string cpf);

        int getIdade();
        int setIdade(int idade);
};

#endif