#ifndef _CLIENTES_H
#define _CLIENTES_H

#include <iostream>

using namespace std;

/**
 * Classe que contém as principais informações sobre o cliente
*/
class Cliente
{
    private:
        string id;
        string nome;
        string rg;
        string cpf;
        int idade;

    public:
        // Construtores
        Cliente();
        Cliente(
            string id,
            string nome,
            string rg,
            string cpf,
            int idade
        );

        // destrutor
        ~Cliente();

        // Métodos Getters e Setters

        string getId();
        int setId(const string id);

        string getNome();
        int setNome(const string nome);

        string getRg();
        int setRg(const string rg);

        string getCpf();
        int setCpf(const string cpf);

        int getIdade();
        int setIdade(const int idade);

        // Sobrecarga de operadores
        friend ostream& operator<<(ostream& ostr, const Cliente& cliente);
        friend bool operator==(const Cliente& este, const Cliente& outro);
};

#endif